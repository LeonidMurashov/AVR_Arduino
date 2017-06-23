#include <IRremote.h>

int RECV_PIN = 3;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);

   //dujjhygoolkqqqqaqq translateIR();

    irrecv.resume(); // Receive the next value
  }
}

/*-----( Declare User-written Functions )-----*/
void translateIR() // takes action based on IR code received
{

  switch (results.value)
  {
    case 632192737:
    case 1286666973:
      Serial.println("Forward");
      break;
    case 4272685797:
    case 4255908178:
      Serial.println("Left");
      break;
    case 4239130559:
//    case 4255908178:
      Serial.println("Backward");
      break;
//    case 4239130559:
    //case 4255908178:
      Serial.println("Right");
      break;
    default:
      Serial.println("Other button");
  }

  delay(100);


} //END translateIR
