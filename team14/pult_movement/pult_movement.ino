#define UP 51
#define DOWN 53
#define FAST 49
#define SLOW 45
#define V_D 47 // veseloe deistviye
#define MAIN 43
#define SQUEESE 39
#define UNSQUEESE 41
#define JOY_X A14
#define JOY_Z 37
#define JOY_Y A15

#define SERVO_KRAN 16
#define SERVO_CLAW 17
#define KRAN_MIN 5 
#define KRAN_MAX 50 // pomenyaj menya 
#define CLAW_MIN 5
#define CLAW_MAX 35 // pomenyaj menya
#define SLOW_SPEED 50 // pomenyaj menya
#define CLAW_SPEED 2 // pomenyaj menya
#define KRAN_SPEED 3 // pomenyaj menya

#include "DualVNH5019MotorShield.h"
#include <Multiservo.h>

DualVNH5019MotorShield md;
Multiservo servo_claw, servo_kran;
int claw_pos = CLAW_MAX, kran_pos = KRAN_MIN;
bool fast;

void setup() {
  md.init();
  servo_claw.attach(SERVO_CLAW);
  servo_kran.attach(SERVO_KRAN);
  int pullup[] = {UP, DOWN, FAST, SLOW, V_D, MAIN, SQUEESE, UNSQUEESE};
  for(int i = 0; i < 8; i++)
    pinMode(pullup[i], INPUT_PULLUP);
  pinMode(JOY_X, INPUT); 
  pinMode(JOY_Y, INPUT);
  pinMode(JOY_Z, INPUT);
  Serial.begin(9600);  

  fast = !digitalRead(FAST);
  servo_claw.write(CLAW_MAX);
  servo_kran.write(KRAN_MIN);
}

void setMotorSpeed(int x, int y)
{ 
    if(abs(x) < 25) x = 0;
    if(abs(y) < 25) y = 0;

    int limit = fast ? 255 : SLOW_SPEED;    
    int m1 = constrain(y + x, -limit, limit),
        m2 = constrain(y - x, -limit, limit);
    
    md.setM1Speed(m1);
    md.setM2Speed(m2);   
}

void loop() {
  int x = (analogRead(JOY_X)-512)/2,
      y = (analogRead(JOY_Y)-512)/2,
      up = !digitalRead(UP),
      down = !digitalRead(DOWN),
      squeese = !digitalRead(SQUEESE),
      unsqueese = !digitalRead(UNSQUEESE);

  fast = !digitalRead(FAST);
  setMotorSpeed(x, y);

  // CLAW CODE
  if(squeese)
  {
    if(claw_pos - CLAW_SPEED < CLAW_MIN)
      claw_pos = CLAW_MIN;
    else
      claw_pos -= CLAW_SPEED;
    servo_claw.write(claw_pos);
  }
  if(unsqueese)
  {
    if(claw_pos + CLAW_SPEED > CLAW_MAX)
      claw_pos = CLAW_MAX;
    else
      claw_pos += CLAW_SPEED;
    servo_claw.write(claw_pos);    
  }

  // KRAN CODE
  if(up)
  {
    if(kran_pos - KRAN_SPEED < KRAN_MIN)
      kran_pos = KRAN_MIN;
    else
      kran_pos -= KRAN_SPEED;
    servo_kran.write(kran_pos);
  }
  if(down)
  {
    if(kran_pos + KRAN_SPEED > KRAN_MAX)
      kran_pos = KRAN_MAX;
    else
      kran_pos += KRAN_SPEED;
    servo_kran.write(kran_pos);    
  }
  
   
  
  delay(10);
}



  /*int mas[] = {UP, DOWN, FAST, SLOW, V_D, MAIN, SQUEESE, UNSQUEESE, JOY_Z};
  for(int i = 0; i < 9; i++)
  {
    Serial.print(digitalRead(mas[i]));
    Serial.print(" ");
  }
  Serial.println();
  */
