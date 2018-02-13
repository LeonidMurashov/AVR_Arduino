#define DIR_PIN1 2
#define STEP_PIN1 3
#define DIR_PIN2 4
#define STEP_PIN2 5

void setup() { 
  pinMode(DIR_PIN1, OUTPUT); 
  pinMode(STEP_PIN1, OUTPUT); 
  pinMode(DIR_PIN2, OUTPUT); 
  pinMode(STEP_PIN2, OUTPUT); 
}

void loop(){

  //rotate a specific number of degrees 
  /*rotateDeg(360, 1); 
  delay(1000);

  rotateDeg(-360, .1);  //reverse
  delay(1000);
*/
  rotate(3200*10, 0.5,0);
  rotate(3200*1, 1,1);
  //delay(1000);

  //rotate a specific number of microsteps (8 microsteps per step)
  //a 200 step stepper would take 1600 micro steps for one full revolution
  /*rotate(1600, .5); 
  delay(1000);

  rotate(-1600, .25); //reverse
  delay(1000); */
}

void rotate(int steps, float speed, byte motor){ 
  if(motor == 0)
  {
    //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
    //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
    int dir = (steps > 0)? HIGH:LOW;
    steps = abs(steps);
  
    digitalWrite(DIR_PIN1,dir);
  
    float usDelay = (1/speed) * 70;
  
    for(int i=0; i < steps; i++){ 
      digitalWrite(STEP_PIN1, HIGH); 
      delayMicroseconds(usDelay);
  
      digitalWrite(STEP_PIN1, LOW); 
      delayMicroseconds(usDelay); 
    } 
  }
  else if(motor == 1)
  {
    //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
    //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
    int dir = (steps > 0)? HIGH:LOW;
    steps = abs(steps);
  
    digitalWrite(DIR_PIN2,dir);
  
    float usDelay = (1/speed) * 70;
  
    for(int i=0; i < steps; i++){ 
      digitalWrite(STEP_PIN2, HIGH); 
      delayMicroseconds(usDelay);
  
      digitalWrite(STEP_PIN2, LOW); 
      delayMicroseconds(usDelay); 
    }
  }
}

