
class PORT
{
 public:
  PORT(byte _bitAdress[])
  {
    
  }
};
void setup() {
  // put your setup code here, to run once:
  byte b[8];
  PORT _PORTC(b);
  String PORTC;
  PORTC = "Helo worl";
}

void loop() {
  // put your main code here, to run repeatedly:

}
