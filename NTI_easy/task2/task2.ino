void setup() 
{
  pinMode(9, OUTPUT);  
}   

void loop() 
{
  analogWrite(9, int((1+sin(millis()/200.0))/2.0*255));
}
