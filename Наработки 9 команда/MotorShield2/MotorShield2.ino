
void LeftBackward()
{ 
  //Left backward
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  analogWrite(10, 255);  
}

void LeftForward()
{  
  //Left forward
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  analogWrite(10, 255);
}

void RightForward()
{  
  //Right backward
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  analogWrite(9, 255);
}

void RightBackward()
{  
  //Right backward
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  analogWrite(9, 255);
}

void LeftStop()
{
  //Left stop
  analogWrite(10, 0);
}

void RightStop()
{
  //Right stop
  analogWrite(9, 0);
}

void setup() 
{
  // put your setup code here, to run once:

  //
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  RightBackward();
  LeftForward();
  delay(1000); 
  LeftStop();
}

void loop() {
  // put your main code here, to run repeatedly:

}
