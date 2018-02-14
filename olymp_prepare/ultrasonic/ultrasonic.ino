#include <Ultrasonic.h>

byte trig = 30, echo = 28;

Ultrasonic ultrasonic(trig, echo);

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.println(ultrasonic.distanceRead());
  delay(20);
}
