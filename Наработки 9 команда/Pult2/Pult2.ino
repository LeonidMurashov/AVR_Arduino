
//#define SENSOR_LEFT 3
//#define SENSOR_RIGHT 2

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

  pinMode(13, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(4 , INPUT_PULLUP);

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  pinMode(A4, OUTPUT);  digitalWrite(A4, HIGH);

  

  //pinMode(SENSOR_RIGHT, INPUT);
  //pinMode(SENSOR_LEFT, INPUT);
  
  while(true)
  {
    bool L_FWD = !digitalRead(11);
    bool L_BWD = !digitalRead(4);
    bool R_FWD = !digitalRead(12);
    bool R_BWD = !digitalRead(13);

    bool ACT_UP = !digitalRead(2);
    bool ACT_DOWN = !digitalRead(3);

    if(L_FWD) 
      LeftForward();
    else if(L_BWD)
      LeftBackward();      
    else
      LeftStop();
      
    if(R_FWD)
      RightForward();
    else if(R_BWD)
      RightBackward();   
    else
      RightStop();

    if(ACT_UP)
      digitalWrite(A4, LOW);
    if(ACT_DOWN)
      digitalWrite(A4, HIGH);
  } 

}

void loop() {  
}
