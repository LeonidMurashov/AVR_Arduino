void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);  
}

void loop() 
{
  digitalWrite(9, HIGH);
  delay(200);
  digitalWrite(9, LOW);
  delay(400);
  digitalWrite(9, HIGH);
  delay(600);
  digitalWrite(9, LOW);
  delay(800);
  digitalWrite(9, HIGH);
  delay(600);
  digitalWrite(9, LOW);
  delay(400);
  
}
