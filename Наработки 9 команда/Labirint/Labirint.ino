  
#define TURN_LEFT_TIME 820
#define TURN_RIGHT_TIME 945
#define SPEED 150

#include "Ultrasonic.h"
Ultrasonic ultrasonic(A0, A1);

void LeftBackward()
{ 
  //Left backward
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(10, SPEED);  
}

void LeftForward()
{  
  //Left forward
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, SPEED);
}

void RightForward()
{  
  //Right forward
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  analogWrite(9, SPEED);
}

void RightBackward()
{  
  //Right backward
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  analogWrite(9, SPEED);
}

void LeftStop()
{
  //Left stop
  analogWrite(10, 0);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}

void RightStop()
{
  //Right stop
  analogWrite(9, 0);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
}

void TurnRight()
{
 // Turn Right
  LeftForward();
  RightBackward(); 
  delay(TURN_RIGHT_TIME);
  LeftStop();
  RightStop();   
  delay(500);
}

void TurnLeft()
{  
 //Turn Left
  LeftBackward();
  RightForward(); 
  delay(TURN_LEFT_TIME);
  LeftStop();
  RightStop();
  delay(500);  
}

void Stop()
{  
  LeftStop();
  RightStop();
}

void Forward()
{
  LeftForward();
  RightForward();
}

void SteerLeft()
{
  //Left forward
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, SPEED*0.6);
  
  //Right forward
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  analogWrite(9, SPEED);
}

void SteerRight()
{
  //Left forward
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, SPEED);
  
  //Right forward
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  analogWrite(9, SPEED*0.6);
}

#define DELAY_TIME 20 

void setup() 
{
  // put your setup code here, to run once:

  //
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  pinMode(0, INPUT_PULLUP);

 //TurnRight();
 //while(digitalRead(0));


  delay(3000);

  Forward();
  while(ultrasonic.Ranging(CM) > 2)
  {
    delay(DELAY_TIME);
  }
  
  TurnRight();
  Forward();
  delay(600);
  
  while(ultrasonic.Ranging(CM) > 2)
  {
    if(analogRead(A5) > 500)
      SteerLeft();
    else 
      SteerRight();
      
    delay(DELAY_TIME);
  }
  TurnLeft();
  Forward();
  
  while(ultrasonic.Ranging(CM) > 23)
  {
    if(analogRead(A5) > 500)
      SteerLeft();
    else 
      SteerRight();
      
    delay(DELAY_TIME);
  }
  TurnLeft();
  Forward();

  while(ultrasonic.Ranging(CM) > 22)
  {
    delay(DELAY_TIME);
  }
  
  
  Stop();


  
}

void loop() {
}
