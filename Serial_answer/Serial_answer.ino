void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = Serial.read();
  if(a != -1)
    Serial.println("hello");
}
