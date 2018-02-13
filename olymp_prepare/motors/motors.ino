#include <AFMotor.h>

AF_DCMotor motor_left(4);
AF_DCMotor motor_claw(3);
AF_DCMotor motor_right(2);

byte line[] = {A15, A14, A13},
              button = 15,
              led = 53,
              encoder_left = 19,
              encoder_right = 20,
              right_angle_steps = 18;
bool encoder_left_state = 0,
     encoder_right_state = 0;
volatile int rots_left = 0,
    rots_right = 0;


ISR(TIMER1_COMPA_vect)
{
  if (digitalRead(encoder_left) != encoder_left_state)
  {
    rots_left += 1;
    encoder_left_state ^= 1;
  }
  if (digitalRead(encoder_right) != encoder_right_state)
  {
    rots_right += 1;
    encoder_right_state ^= 1;
  }
}

void setup()
{
  /////////////////////////////////////////////
  // initialize timer1
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 30; // ~ 1KHz            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts
  ////////////////////////////////////////////////////////////


  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
    pinMode(line[i], INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(encoder_left, INPUT);
  pinMode(encoder_right, INPUT);

  while (digitalRead(button));
  motor_claw.setSpeed(255);
  while(true)
  {
    motor_claw.run(BACKWARD);
    delay(200);
    motor_claw.run(RELEASE);
    delay(1000);
    motor_claw.run(FORWARD);
    delay(200);
    motor_claw.run(RELEASE);
    delay(1000);
  }

  while (!true) {
    int left = analogRead(line[0]), right = analogRead(line[2]);
    Serial.print(left);
    Serial.print(" ");
    Serial.println(right);
  }

  digitalWrite(led, HIGH);
  delay(10);
  digitalWrite(led, LOW);

  while (digitalRead(button));
  do_steps(right_angle_steps,-right_angle_steps);
  delay(1000);
  do_steps(right_angle_steps,-right_angle_steps);
  delay(1000);
  do_steps(right_angle_steps,-right_angle_steps);
  delay(1000);
  do_steps(right_angle_steps,-right_angle_steps);

  digitalWrite(led, HIGH);
  delay(500);
  while (digitalRead(button));
  digitalWrite(led, HIGH);
  delay(500);


}

void do_steps(int steps_left, int steps_right)
{
  int rots_left_prev = rots_left,
      rots_right_prev = rots_right,
      speed = 90;

  if (steps_left > 0)
    motor_left.run(FORWARD);
  else
  {
    steps_left *= -1;
    motor_left.run(BACKWARD);
  }
  if (steps_right > 0)
    motor_right.run(FORWARD);
  else
  {
    steps_right *= -1;
    motor_right.run(BACKWARD);
  }

  bool left_not_done, right_not_done;
  do
  {
    left_not_done = rots_left_prev + steps_left > rots_left;
    right_not_done = rots_right_prev + steps_right > rots_right;
    if (left_not_done)
      motor_left.setSpeed(((rots_left_prev + steps_left - rots_left)>8)*10 + 80);
    else
      motor_left.run(RELEASE);
    if (right_not_done)
      motor_right.setSpeed(((rots_right_prev + steps_right - rots_right)>8)*10 + 80);
    else
      motor_right.run(RELEASE);
  }
  while (left_not_done || right_not_done);
}

void gas_left(int sp)
{
  if (sp > 0)
  {
    motor_left.run(FORWARD);
    motor_left.setSpeed(sp);
  }
  else
  {
    motor_left.run(BACKWARD);
    motor_left.setSpeed(-sp);
  }
}

void gas_right(int sp)
{
  if (sp > 0)
  {
    motor_right.run(FORWARD);
    motor_right.setSpeed(sp);
  }
  else
  {
    motor_right.run(BACKWARD);
    motor_right.setSpeed(-sp);
  }
}

int speed = 100, rotate_speed = 100;
bool last_max = 0;
void loop()
{
  int left = analogRead(line[0]), right = analogRead(line[2]);
  digitalWrite(led, LOW);
  if (left < 100 && right < 100)
  {
    digitalWrite(led, HIGH);
    if (last_max)
    {
      gas_left(rotate_speed);
      gas_right(-rotate_speed);
    }
    else
    {
      gas_left(-rotate_speed);
      gas_right(rotate_speed);
    }
  }
  else
  {
    if (left > right)
    {
      gas_left(speed / 1.5);
      gas_right(speed);
    }
    else
    {
      gas_left(speed);
      gas_right(speed / 1.5);
    }
    last_max = right > left;
  }
  delay(1);
}
