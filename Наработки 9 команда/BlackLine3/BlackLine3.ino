
#define SENSOR_LEFT 3
#define SENSOR_RIGHT 2

//Пины 5-10 заняты
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

  pinMode(SENSOR_RIGHT, INPUT);
  pinMode(SENSOR_LEFT, INPUT);

  LeftForward();
  RightForward();
  delay(700);
  LeftStop();
  RightStop();
  while(true)
  {
      bool L_W = !digitalRead(SENSOR_LEFT);
      bool R_W = !digitalRead(SENSOR_RIGHT);
    
     if(L_W || R_W)
     { 
      if(L_W)
        LeftForward();
      else
        LeftStop();
      if(R_W)
        RightForward();
      else
        RightStop();
     }
     else
     {
      LeftStop();
      RightStop();
      break;
     }  
  }

}

void loop() {  
}
