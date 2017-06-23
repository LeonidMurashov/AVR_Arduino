#define LEFT_FWD 5
#define LEFT_BWD 6
#define RIGHT_FWD 7
#define RIGHT_BWD 8  
#define LEFT_SPEED 10
#define RIGHT_SPEED 9

#define LEFT_SENSOR_PIN  2
#define RIGHT_SENSOR_PIN 3

#define SPEED 255

// Start btn
#define START_BTN 3

void Forward()
{
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_BWD, LOW);

  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED);
}

void Backward()
{
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_BWD, HIGH);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_BWD, HIGH);

  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED);
}

void Right()
{
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  digitalWrite(RIGHT_BWD, HIGH);

  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED);
}

void Left()
{
  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(LEFT_BWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_BWD, LOW);

  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED);
}

void Stop()
{
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_BWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_BWD, HIGH);

  analogWrite(LEFT_SPEED, 0);
  analogWrite(RIGHT_SPEED, 0);
}

void SteerLeft()
{
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_BWD, LOW);

  analogWrite(LEFT_SPEED, SPEED/4);
  analogWrite(RIGHT_SPEED, SPEED);
}

void SteerRight()
{
  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(LEFT_BWD, LOW);
  digitalWrite(RIGHT_FWD, HIGH);
  digitalWrite(RIGHT_BWD, LOW);

  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED/4);
}


void setup() 
{
start:
  
   // Init motor pins
   for(int i = 0; i<5; i++)
      pinMode(i + 5, OUTPUT); 

  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);

  pinMode(3, INPUT_PULLUP);
  pinMode(A5, INPUT);
  // Start on btn on
  while(digitalRead(START_BTN));

 // Forward();
  delay(200);

  Serial.begin(9600);

 // Loop
  
  while(true)
  {
    bool LeftWhite = !digitalRead(LEFT_SENSOR_PIN);
    bool RightWhite = !digitalRead(RIGHT_SENSOR_PIN);
  
    if(LeftWhite || RightWhite)
      Forward();
    if(!LeftWhite || RightWhite)
      Right();//SteerRight();
    if(LeftWhite || !RightWhite)
      Left();//SteerLeft();  
    if(!LeftWhite || !RightWhite)
    { 
      Stop();
      break;
    }  

    //Serial.println(digitalRead());
 
      delay(20);
  }

  
}


void loop() 
{  

 
}

  /*Forward();
  delay(1000);

  Left();
  delay(1000);

  Right();
  delay(1000);

  Backward();  
  delay(1000);*/
