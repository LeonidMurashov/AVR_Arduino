byte trig = 4, echo = 6;
int get_distance()
{
  long duration, cm;
  digitalWrite(trig, LOW);
  delayMicroseconds(5);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  cm = (duration/2) / 29.1;
  if(cm > 255)
    cm = 255;
  delay(5);
  return cm;
}

void setup() 
{
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(9, OUTPUT);
}

void loop() 
{
  if(get_distance() < 15)
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
  delay(20);
}
