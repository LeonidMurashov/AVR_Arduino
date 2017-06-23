#define LEFT_FWD 5
#define LEFT_BWD 6
#define RIGHT_FWD 7
#define RIGHT_BWD 8
#define LEFT_SPEED 9
#define RIGHT_SPEED 10

void setup()
{
  // Init motor pins
    for(int i = 0; i<5; i++)
      pinMode(i + 5, OUTPUT); 
         
  analogWrite(LEFT_SPEED, 200);
  analogWrite(RIGHT_SPEED, 200);
  
}


void loop()
{
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);
  delay(2000);
  
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  delay(2000);
  
  digitalWrite(LEFT_BWD, HIGH);
  digitalWrite(RIGHT_BWD, HIGH);
  delay(2000);
  
  digitalWrite(LEFT_BWD, LOW);  
  digitalWrite(RIGHT_BWD, LOW);
  delay(2000);
}

