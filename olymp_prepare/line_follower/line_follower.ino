#include <AFMotor.h> // Подключаем библиотеку для работы с Motor Shield L293D

// Придумываем имена моторам и объявляем клеммники к которым они подсоединены
AF_DCMotor motor_left(1);
AF_DCMotor motor_right(2);

byte line[] = {A15, A14, A13},
              button = 15,
              led = 53,
              encoder_left = 19,
              encoder_right = 20;

void setup()
{
  Serial.begin(9600);
  for (int i = 0; i < 3; i++)
    pinMode(line[i], INPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);

  motor_left.run(FORWARD);
  motor_right.run(FORWARD);


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
  digitalWrite(led, HIGH);
  delay(500);

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

int speed = 110, rotate_speed = 100;
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
