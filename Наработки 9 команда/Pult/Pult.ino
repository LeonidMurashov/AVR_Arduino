#define LEFT_DIR 6
#define RIGHT_DIR 8
#define LEFT_SPEED 9
#define RIGHT_SPEED 10

#define LEFT_FWD 5
#define RIGHT_FWD 7

#define SPEED 200

// Start btn
#define START_BTN 3


void RightForward()
{
  //Right forward
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  analogWrite(10, 255);
}

void LeftForward()
{
  //Left forward
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(9, 255);
}

void LeftBackward()
{
  //Left backward
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(9, 255);  
}

void setup() {

pinMode(7, OUTPUT);
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);  
  
//  pinMode(3, INPUT_PULLUP);
  // Start on btn on
 // while(digitalRead(START_BTN));
} 

void loop() {
  // put your main code here, to run repeatedly:
 // Forward();
 // Backward();
 //LeftBackward();
}
