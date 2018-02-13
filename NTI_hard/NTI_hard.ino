// https://habrahabr.ru/post/337430/
#include"timer-api.h"

const byte stepPin = 10;
const byte dirPin = 16;
const byte actPin = 14;
const float motorAngle = 1.8;
const float stepSize = 0.5;//full=1, half=0.5, quarter=0.25, etc...

const byte btn_left = 2, btn_right = 3;
const byte led_blue = 8, led_yellow = 9;

void setup() 
{  
  Serial.begin(9600);
  Serial1.begin(1200);

  // Stepper init
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(actPin, OUTPUT);

  pinMode(btn_left, INPUT);
  pinMode(btn_right, INPUT);

  pinMode(led_blue, OUTPUT);
  pinMode(led_yellow, OUTPUT);

  // init timers  
  timer_init_ISR_1KHz(TIMER_DEFAULT);  
  interrupts();
}

// 60 degrees
const float angle = 0.08333f;
void loop() 
{
  stepperRotate(angle,600);
  delay(1000);
  stepperRotate(-2 * angle,600);
  stepperRotate(angle,600);
}

int str_num = 0, err_num = 0;
// docs https://www.arduino.cc/en/Reference/SerialEvent
void serialEvent1()
{
  while(Serial1.available())
  {
    String str = Serial1.readStringUntil('\n');
    if(str == "The quick brown fox jumps over the lazy dog" || 
        str == "Beyond font testing, these tools can also be useful")
    {
      str_num += 1;
      Serial.print(str_num);
      Serial.print(" ");
      Serial.println(str); 
    }
    else
    {
      err_num += 1;
      Serial.print(err_num);
      Serial.print(" Error /");
      Serial.println(str); 
    }
  }      
}

void timer_handle_interrupts(int timer)
{
  if(digitalRead(btn_left))
  {
    digitalWrite(led_yellow, HIGH);
    digitalWrite(led_blue, LOW);
  }
  if(digitalRead(btn_right))
  {
    digitalWrite(led_yellow, LOW);
    digitalWrite(led_blue, HIGH);
  }
}

//Stepper Board Test Code
//Kevin Darrah 2017
void stepperRotate(float rotation, float rpm) 
{
  if (rotation > 0) {
    digitalWrite(dirPin, HIGH);
  }
  else {
    digitalWrite(dirPin, LOW);
    rotation = rotation * -1;
  }

  // first figure out how many steps in one rotation, so a motor with 1.8deg per step, equals 360/1.8 = 200 steps/rotation
  // then if you're doing half step, that will double, so divide by 0.5, gives 400steps per rotation
  float stepsPerRotation = (360.00 / motorAngle) / stepSize;

  //now we have the steps per rotation, multiply by the rotations for this command to get total steps
  float totalSteps = rotation * stepsPerRotation;
  //Serial.println(totalSteps); // debug

  //tricky part here - what is the ON/OFF time of the step pin to get the desired RPM?
  // First, what is the seconds per revolution? then we can figure out seconds per step
  // RPM (rotation per minute) needs to be converted to MPR, so 1/RPM, then seconds per rotation is 60seconds/RPM
  // that gives us Seconds per Rotation, but how many seconds per step? well, we just divide that by the number of steps per rotation
  // so now we're at 60/RPM/stepsPerRotation
  // this is seconds, but we're going to use microSeconds, so let's multiply by 1 Million (1E6)
  // then, we want a 50% duty cycle, half time ON, half time OFF, so divide this value by 2, then we end up with:
  unsigned long stepPeriodmicroSec = ((60.0000 / (rpm * stepsPerRotation)) * 1E6 / 2.0000) - 5;

  //what's up with the -5 at the end?  well, in the for loop, we have to compensate for the i++ and i<x check, so 5us is subracted to speed it up a little

  //Serial.println(stepPeriodmicroSec);
  noInterrupts();
  for (unsigned long i = 0; i < totalSteps; i++) {
    digitalWrite(stepPin, HIGH);//PORTD |= (1 << 2);
    _delay_us(stepPeriodmicroSec);
    digitalWrite(stepPin, LOW);//PORTD &= ~(1 << 2);
    _delay_us(stepPeriodmicroSec);
  }
  interrupts();

}

