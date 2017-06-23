void setup()
{
   pinMode(3, OUTPUT);
   Serial.begin(9600);
}

    String message = "";
void loop()
{

  if(Serial.available())
  {
    while(true)
    {
      char inc = Serial.read();
      if(inc != '\n')
        message += inc;
      else
        break;
    delay(1);
    }
    Serial.println(message);
  }
}
