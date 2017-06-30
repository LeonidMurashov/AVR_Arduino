#define UP 51
#define DOWN 53
#define FAST 49
#define SLOW 45
#define V_D 47
#define MAIN 43
#define SQUEESE 39
#define UNSQUEESE 41
#define JOY_X A14
#define JOY_Z 37
#define JOY_Y A15

#include "DualVNH5019MotorShield.h"
DualVNH5019MotorShield md;

void setup() {
  // put your setup code here, to run once:
  md.init();
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(FAST, INPUT_PULLUP);
  pinMode(SLOW, INPUT_PULLUP);
  pinMode(V_D, INPUT_PULLUP);
  pinMode(MAIN, INPUT_PULLUP);
  pinMode(SQUEESE, INPUT_PULLUP);
  pinMode(UNSQUEESE, INPUT_PULLUP);
  pinMode(JOY_X, INPUT); 
  pinMode(JOY_Y, INPUT);
  pinMode(JOY_Z, INPUT);
  Serial.begin(9600);  
}

void setMotorSpeed(int x, int y)
{ 
    md.setM1Speed(y + x);
    md.setM2Speed(y - x);   
}


void loop() {
  // put your main code here, to run repeatedly:
  /*int mas[] = {UP, DOWN, FAST, SLOW, V_D, MAIN, SQUEESE, UNSQUEESE, JOY_Z};
  for(int i = 0; i < 9; i++)
  {
    Serial.print(digitalRead(mas[i]));
    Serial.print(" ");
  }
  Serial.println();
  */

  int x = analogRead(JOY_X)-512,
      y = analogRead(JOY_Y)-512;

  setMotorSpeed(x, y);

  

}
