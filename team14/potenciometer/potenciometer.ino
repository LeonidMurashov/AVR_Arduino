#define X A0
#define Y A1
#define Z A2

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int x,y,z;
  x = analogRead(X);
  y = analogRead(Y);
  z = analogRead(Z);

  Serial.print(x);
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println(z);
}

