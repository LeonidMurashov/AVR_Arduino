#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;
#define SPEED 100

int prev_contr;

void setup() {
  md.init();  
  //pinMode(7, INPUT);
  pinMode(5, INPUT);
  pinMode(3, INPUT);
  pinMode(13, INPUT_PULLUP);
  pinMode(52, INPUT_PULLUP);
  
  Serial.begin(9600);
  while(digitalRead(13))
  {
    bool prev = digitalRead(52);
    delay(10);
    if(!prev && digitalRead(52))
      break;    
  
  prev_contr = analogRead(A15);
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
void rot(float a)
{  
    md.setM1Speed(SPEED*a);
    md.setM2Speed(-SPEED*a);  
}

void loop() {
  //md.setM2Speed(55);
  bool r = !digitalRead(3); // M2
  bool l = !digitalRead(5); // M1
  //int _l = analogRead(A15); // 42 - 20
  //md.setM1Speed(SPEED*l);
  //md.setM2Speed(SPEED*r);
  //Serial.println(analogRead(A15));
    
  //if(r)
  //  rot(-0.5);
  /*
  fwd();
  delay(500);
  bwd();
  delay(500);*/
  
  if(r && l)
  {stp();}
  else
  {
    if(r && !l)
      rot(-1);
    else if(l && !r)
      rot(1);
    else
      fwd();
  }
  /**/

/*
  float ratio = (_l - prev_contr)/(float)512;
  Serial.println(ratio);

  if(_l > 512 && r)
  {}
  else if(r && _l < 512)
  {
    rot(-0.5);
  }
  else
  {
    if(abs(ratio) > 0.2)
    {
      rot(ratio);
    }
    else
    {
      fwd();
    }
  }

  prev_contr = _l;
  */
  delay(20);
  
}
