//#include "GLCD_Library_Arduino.h"
#include <Servo.h>
#include <string.h>
#define LED_PIN 3

Servo myServo;

void setup()
{
   pinMode(LED_PIN, OUTPUT);
   pinMode(5, OUTPUT);
   Serial.begin(9600);
   //Lcd_Init();
   myServo.attach(LED_PIN);
   digitalWrite(5, LOW);
}

String readMessage()
{    
  if(Serial.available())
  {
    String message = "";
    // 256 characters max
    for(int i = 0; i<256; i++)
    {
      char inc = Serial.read();
      if(inc != '\n')
        message += inc;
      else
        break;
      delay(1);
    }
    Serial.println(message);
    return message;
  }
  else 
    return "";
}

void MoveServo(Servo servo, int angle)
{
  if(angle <= 180 && angle >=0)
    myServo.write(angle);
}

// Check and return if char is numeric
bool IsNumber(char ch)
{
  return ch >= '0' && ch<='9';
}

// Finding number in string in specified position and return it
int ParseNumber(String mes)
{
  byte it = -1;
  char ch;
  do
  {
    it++;
    ch = mes[it];
    if(ch == '\n')
      return -1;
  }
  while(IsNumber(ch));
  String newStr = "";
  for(int i = it; i<mes.length(); i++)
    newStr += mes[i];
  return newStr.toInt();
}

// Find command and arguments, return false if failed 
bool ParseCommand(String mes, String &command, int &argc, char **argv)
{
  byte it = -1, lastit = 0, wordit = 0;
  argc = 0;

  // Counting spaces
  for(int i = 0; i<mes.length(); i++)
    if(mes[i] == ' ')
      argc++;  
  argv = new char*[argc];
  
  while(true)
  {
    char ch;
    do
    {
      it++;
      ch = mes[it];
      
    }while(ch != ' ' && ch != '\n');
    if(lastit - it < 0) return false;
    
    if(wordit == 0)
    {
      command = "";
      for(int i = lastit; i<it; i++)
        command += mes[i];          
    }
    else 
    {
      char* arg;
      for(int i = lastit; i<it; i++)
        arg += mes[i];
      if(wordit > argc)
        return false;
      argv[wordit-1] = arg;
    }

    
    wordit++;
    lastit = it + 1;
    it++;
    
    if(ch == '\n')
      return true;
  }
}

void loop()
{  
  String command;
  int argc;
  char** argv;
  String message = readMessage();
 /* if(message != "")Serial.println(message);/*
  if(ParseCommand(message, command, argc, argv))
  {    
    digitalWrite(5, HIGH);
    if(command == "S")
      MoveServo(myServo, String(argv[0]).toInt());
  }*/
  delay(2000); 
}


/*
String message;
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(3, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
// the loop function runs over and over again forever
void loop() {
  if(Serial.available())
  {
    char incoming = Serial.read();
    if(incoming >= '0' && incoming <= '9')
    {
      message += incoming;
    }
    else if (incoming == '\n')
    {
      analogWrite(3, message.toInt());
      lcd.clear();
      lcd.print(message.toInt());
      delay(10);
      message = "";
    }
  } 

  
}*/

/*
template <class T> int EEPROM_writeAnything(int ee, const T& value)
{
    const byte* p = (const byte*)(const void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          EEPROM.write(ee++, *p++);
    return i;
}

template <class T> int EEPROM_readAnything(int ee, T& value)
{
    byte* p = (byte*)(void*)&value;
    unsigned int i;
    for (i = 0; i < sizeof(value); i++)
          *p++ = EEPROM.read(ee++);
    return i;
}*/

/*void setup()
{
   pinMode(LED_PIN, OUTPUT);
   Serial.begin(9600);
   Lcd_Init();
   EEPROM_readAnything(0, myi);
}

void loop()
{
  myi++;
  for(int j = 0; j<20; j++)
    Circle(rand()%128, rand()%64, rand()%30+2, false);
  Lcd_Fill();

  
  Serial.print("Num ");
  Serial.println(myi);

  if(Serial.available())
  {
    while(true)
    {
      char inc = Serial.read();
      if(inc != -1)
        message += inc;
      else
        break;
    }
    Serial.println(message);
    message = "";
  }

  
  EEPROM_writeAnything(0,myi);
  delay(500);
  digitalWrite(LED_PIN, HIGH);
  delay(2000);
  digitalWrite(LED_PIN, LOW);
}*/
