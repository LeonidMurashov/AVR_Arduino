#define START_BTN 4


void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(6, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(analogRead(2));
  Serial.print("\t\t");
  Serial.println(analogRead(6));
}
