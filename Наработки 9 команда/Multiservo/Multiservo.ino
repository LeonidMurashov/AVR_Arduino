#include <Multiservo.h>

Multiservo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(0);

  while(true)
  {
    servo.write(0);
    delay(500);
    servo.write(180);
    delay(500);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  
}
