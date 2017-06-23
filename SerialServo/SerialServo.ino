#include <Servo.h>

String inputString = "";         // a string to hold incoming data
bool stringComplete = false;  // whether the string is complete
unsigned long long ms;

Servo myServo;  
#define SERVO_PIN 9
#define LED_PIN 12
void setup() 
{
  pinMode(A0, INPUT);
  pinMode(LED_PIN, OUTPUT);
  srand(analogRead(A0));
  myServo.attach(SERVO_PIN);
  Serial.begin(9600);
  myServo.write(60);
  ms = millis(); 

  digitalWrite(LED_PIN, HIGH);
  delay(10);
  digitalWrite(LED_PIN, LOW);
}

int currAngle = 60;

void loop() 
{
 
  if(stringComplete)
  {
    digitalWrite(LED_PIN, HIGH); 
    if(!myServo.attached())
      myServo.attach(SERVO_PIN);
    int value = inputString.toInt();
   // if(abs(value - currAngle) > 50)
     // value = currAngle + 50*((value - currAngle)/abs((value - currAngle)));
    
    myServo.write(constrain(value, 0, 120));

    currAngle = value;

    ms = millis();
    inputString = "";
    stringComplete = false;
  }
 
  if(myServo.attached() && millis() - ms >= 400)    
    {
      myServo.detach();
      digitalWrite(LED_PIN, LOW); 
    }
}

 
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
