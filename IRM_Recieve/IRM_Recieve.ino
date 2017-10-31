#include <IRremote.h>

int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  for(int i = 0; i < 4;i++)
    pinMode(i+4, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);

    switch(results.value){
      case 3255005345:
        digitalWrite(4, HIGH);
        Serial.println("Forward");
        break;
      case 2553984193:
        digitalWrite(5, HIGH);
        Serial.println("Left");
        break;
      case 2173897225:
        digitalWrite(6, HIGH);
        Serial.println("Backward");
        break;
      case 553866289:
        digitalWrite(7, HIGH);
        Serial.println("Right");
        break;
    }

   //dujjhygoolkqqqqaqq translateIR();
    irrecv.resume(); // Receive the next value
    delay(100);
    for(int i = 0; i < 4;i++)
      digitalWrite(i+4, LOW);
  }
}
