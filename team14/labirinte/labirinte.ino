#include "Ultrasonic.h"
#include "DualVNH5019MotorShield.h"
#define SPEED 100
#define SENSE 30
DualVNH5019MotorShield md;

// sensor connected to:
// Trig - 12, Echo - 13
Ultrasonic ult_l(16, 17), ult_r(14, 15);
void setup()
{
  md.init();
  Serial.begin(9600); 

  pinMode(13, INPUT_PULLUP);
  pinMode(52, INPUT_PULLUP);
  
  Serial.begin(9600);
  while(digitalRead(13))
  {
    bool prev = digitalRead(52);
    delay(10);
    if(!prev && digitalRead(52))
      break;    
  }
}

void fwd()
{
    md.setM1Speed(SPEED);
    md.setM2Speed(SPEED);  
}
void stp()
{
    md.setM1Speed(0);
    md.setM2Speed(0);  
}
void bwd()
{
    md.setM1Speed(-SPEED);
    md.setM2Speed(-SPEED);    
}

void right()
{
    md.setM1Speed(SPEED);
    md.setM2Speed(0);   
}

void left()
{
    md.setM1Speed(0);
    md.setM2Speed(SPEED);     
}

void rot(float a)
{  
    md.setM1Speed(SPEED*a);
    md.setM2Speed(-SPEED*a);  
}

int kosyak = 0;

void loop()
{

  
  float dist_l = ult_l.Ranging(CM),
        dist_r = ult_r.Ranging(CM);       // get distance


  Serial.print(dist_l);
  Serial.print(" ");
  Serial.println(dist_r);

  //return;

  if ((dist_l == 51 || dist_r == 51) && !((dist_l == 51 && dist_r == 51)))
  {
    fwd();
    delay(100);
    stp();
    delay(50);
    return;
  }

  if(dist_l > SENSE && dist_r > SENSE)
  {
    if(kosyak < 4)
    {
      delay(20);
      kosyak++;
      return;
    }
    
    fwd();
    delay(1500);
    stp();
    while(true);
  }
  kosyak = 0;
  if(dist_l > dist_r)  
    left();
  else
    right();
  
  
  delay(10);                                   // arbitary wait time.


}
