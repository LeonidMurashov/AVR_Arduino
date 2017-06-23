#include <openGLCD.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char byt;
  /*byt = Serial.read();
  if(byt == 'H')
    {
      digitalWrite(12, HIGH);
      delay(500);
      digitalWrite(12, LOW);
      Serial.println('Y');
    }*/
    Serial.println("Hello!");
    delay(1000);
}
