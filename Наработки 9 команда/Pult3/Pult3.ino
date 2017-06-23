#include <Multiservo.h>

#define CLAW1_MIN 10
#define CLAW1_MAX 180

#define CLAW2_MIN 10
#define CLAW2_MAX 55

#define SPEED1 40
#define SPEED2 100
#define SPEED3 255

int SPEED = 255;
Multiservo funny, claw1, claw2;

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

void Backward()
{
  LeftBackward();
  RightBackward();
}

void SteerLeft()
{
  //Left forward
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, SPEED*0.4);
  
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
  analogWrite(9, SPEED*0.4);
}


void SteerBackLeft()
{
  //Left backward
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(10, SPEED*0.4);
  
  //Right backward
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  analogWrite(9, SPEED);
}

void SteerBackRight()
{
  //Left backward
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(10, SPEED);
  
  //Right backward
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  analogWrite(9, SPEED*0.4);
}


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

  pinMode(52, INPUT_PULLUP);
  pinMode(50, INPUT_PULLUP);
  pinMode(48, INPUT_PULLUP);
  pinMode(46, INPUT_PULLUP);
  pinMode(44, INPUT_PULLUP);
  pinMode(42, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(38, INPUT_PULLUP);
  pinMode(36, INPUT_PULLUP);

  funny.attach(0);
  funny.write(20);

  claw1.attach(1);
  claw2.attach(2);
/*
  claw2.write(constrain(0, 10, 34));
  //claw1.write(constrain(90,  CLAW1_MIN, CLAW1_MAX));
  delay(50);*/

/*
#define CLAW1_MIN 20
#define CLAW1_MAX 90

#define CLAW2_MIN 10
#define CLAW2_MAX 34
*/

int clawState = 0;
int clawState2 = 0;

claw2.write(constrain(10,  CLAW2_MIN, CLAW2_MAX)); 
claw1.write(constrain(85,  CLAW1_MIN, CLAW1_MAX));

  while(true)
  {
    bool FWD = !digitalRead(36);
    bool BWD = !digitalRead(38);

    bool RIGHT = !digitalRead(42);
    bool LEFT = !digitalRead(40);

    bool SpeedTrig1 = !digitalRead(48);
    bool SpeedTrig2 = !digitalRead(50);

    bool SERVO_UP = !digitalRead(46);
    bool SERVO_DOWN = !digitalRead(44);
    
    bool ADD_BTN = !digitalRead(52);

    

    if(SpeedTrig1)
      SPEED = SPEED1;
    else if(SpeedTrig2)
      SPEED = SPEED3;
    else
      SPEED = SPEED2;

    if(!ADD_BTN)
    {
      if(FWD || BWD)
      {
        if(FWD)
        {      
          if(LEFT)
            SteerLeft();
          else if(RIGHT)
            SteerRight();
          else  
            Forward();
        }          
    
        if(BWD)
        {
          if(LEFT)
            SteerBackLeft();
          else if(RIGHT)
            SteerBackRight();
          else  
          Backward();  
        }    
      }   
      else if(LEFT)
      {
         LeftBackward();
         RightForward();
      }
      else if(RIGHT)
      {
        LeftForward();
        RightBackward();
      }
      else
        Stop();

        //claw2.write(constrain(0, CLAW2_MIN, CLAW2_MAX));  
    }
    else
    {
      if(FWD)      
        funny.write(100);      
      if(BWD)
        funny.write(20);      


      if(SERVO_UP)      
      {
        if(clawState2 == 0)
        {
          claw2.write(constrain(40,  CLAW2_MIN, CLAW2_MAX));      
        
          delay(100);
          while(!digitalRead(46));
          delay(100);

          clawState2 = 2;
        }
        else
        { 
         claw2.write(constrain(10,  CLAW2_MIN, CLAW2_MAX));      
        
          delay(100);
          while(!digitalRead(46));
          delay(100);

          clawState2 = 2;
        }
      }
      if(SERVO_DOWN)
      {
        claw2.write(constrain(65,  CLAW2_MIN, 100));
        clawState2 = 0;
      }

      if(RIGHT)
      {
        claw1.write(constrain(85,  CLAW1_MIN, CLAW1_MAX));
        clawState = 0;
      }
      if(LEFT)
      {
        if(clawState == 0)
        {
          claw1.write(constrain(70,  CLAW1_MIN, CLAW1_MAX));
          clawState = 1;
          delay(100);
          while(!digitalRead(40));
          delay(100);
        }
        else if(clawState == 1)
        {
          if(SPEED != SPEED1) 
          {
            claw1.write(constrain(50,  CLAW1_MIN, CLAW1_MAX));
            clawState = 2;
          }
        }
      }
    }
      
  } 
  
  

}

void loop() {  
}
