int laser_din=16;

void setup()
{
  pinMode(laser_din,INPUT);
  Serial.begin(9600);
}

bool prev = 0;
void loop()
{
  bool a = digitalRead(laser_din);
  if(a != prev)
    {
      prev = a;
      Serial.println("Change");
    }
  
}
