#include <Multiservo.h>

Multiservo servo;
void setup() {
  // put your setup code here, to run once:
  servo.attach(17);

  while(true)
  {
    servo.write(5);
    delay(500);
    servo.write(90);
    delay(1000);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  
}
