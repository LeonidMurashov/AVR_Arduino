void setup()
{
  pinMode(A8, INPUT);
  pinMode(15, INPUT_PULLUP);
  Serial.begin(9600);

  /*for(int i = 0; i < 40; i++)
  {
    while (digitalRead(15));
    int d = 0;
    for(int j = 0; j < 10; j++)
    {
      d += analogRead(A8);
      delay(10);
    }
    Serial.println(d/10);
    delay(500);
  }
  Serial.println("Stop");*/
}

const byte dists[] = {50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 50, 46, 32, 31, 26, 25, 25, 22, 20, 19, 18, 17, 15, 15, 14, 14, 13, 13, 12, 12, 11, 11, 10, 10, 10, 10, 9, 9, 9, 8, 8, 8, 7, 7, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6};

int get_distance()
{
  int r = 0; 
  for(byte i = 0; i < 10; i++)
  {
    r += analogRead(A8);
    delay(1);
  }
  r/=10;
  return dists[r/16];
}

void loop()
{
  Serial.println(get_distance());
}
