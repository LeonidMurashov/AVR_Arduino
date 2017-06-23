
/* Oscillograph - Leonid Murashov
    Drawing Graph of voltage on MEASURE_PIN
    For 128x64 displays
*/

#include <openGLCD.h>

#define MEASURE_PIN A5

// Graph demention is 121x55
#define GRAPH_X 121
#define GRAPH_Y 55
#define DATACURSOR_BEGIN 7
#define TIME_DILATION 1

void setup()
{
  // put your setup code here, to run once:
  GLCD.Init();
  pinMode(MEASURE_PIN, INPUT);
  GLCD.SelectFont(System5x7);
  InitGraph();
  Serial.begin(9600);
}

int dataCursor = DATACURSOR_BEGIN, previousData = -1;

void loop()
{
  DrawData();
  _delay_us(TIME_DILATION);
}

void InitGraph()
{
  GLCD.DrawLine(6, 1, 6, 55);
  GLCD.DrawLine(6, 55, 126, 55);
  //GLCD.SetDot(7, 2, BLACK);GLCD.SetDot(8, 3, BLACK);
  GLCD.SetDot(4, 3, BLACK); GLCD.SetDot(5, 2, BLACK);

  GLCD.SetDot(125, 56, BLACK); GLCD.SetDot(124, 57, BLACK);
  // GLCD.SetDot(125, 54, BLACK); GLCD.SetDot(124, 53, BLACK);

  GLCD.CursorToXY(95, 57);
  GLCD.print("Time");

  printVertical("Voltage", 0, 5);

}

int prevMicro;
bool ifRaising, ifRaisingPrev;
int prevTime = 0;
const int MIDDLE = 512;
int previousVoltage = 0;

void DrawData()
{
  int voltage = analogRead(MEASURE_PIN);
  int data = map(voltage, 0, 1024, GRAPH_Y - 1, 0);

  GLCD.DrawVLine(dataCursor, 0, GRAPH_Y, WHITE);
  if (previousData == -1)GLCD.SetDot(dataCursor, data, BLACK);
  else GLCD.DrawLine(dataCursor - 1, previousData, dataCursor, data, BLACK);

  /* Experimental area */
/*
  // Detect middle-crossing on raising
  if(voltage > MIDDLE && previousVoltage < MIDDLE)
  {    
    // If state trigged
    int delta = micros() - prevTime;

    DisplayFrequency(delta);

    prevTime = micros();
  }

  if(voltage > 900)
  {
    tone(3, 400, 10);
    Serial.println("НАРУШИТЕЛИ!!!!!");
  }
*/
  /*// Detect if raising state changed
  ifRaisingPrev = ifRaising;
  if (data > previousData) ifRaising = true;
  else ifRaising = false;
  if (ifRaisingPrev != ifRaising)
  {
    // If state trigged
    int Time = micros(), delta = Time - prevTime;

   // DisplayFrequency(delta);

    prevTime = Time;
  }*/
  // Finishing the function
  if (dataCursor < 127)
  {
    dataCursor++;
    previousData = data;
  }
  else
  {
    dataCursor = DATACURSOR_BEGIN;
    previousData = -1;
  }

}

// Display readable numbers
int prevMills = 0;
void DisplayFrequency(int delta)
{
  if (millis() - prevMills > 2000)
  {
    int frequency = 1000000 / delta;
    GLCD.FillRect(60, 57, 30, 7, WHITE);
    GLCD.CursorToXY(60, 57);
    GLCD.print(frequency);
    prevMills = millis();
  }
}


void printVertical(String str, int x, int y)
{
  for (int i = 0; i < str.length(); i++, y += 8)
  {
    GLCD.CursorToXY(x, y);
    GLCD.print(str[i]);
  }
}


