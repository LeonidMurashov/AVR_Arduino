#include <ve_avr.h>        // Используется библиотека VEduino

volatile bool doWhile = true;
volatile byte tIteration = 0;

ISR(TIMER2_OVF_vect)
{
  if (tIteration == 64)
  {
    // Произойдёт через 1,04 секунды после запуска
    doWhile = false;
    DEV_TICTRL2.overflowIntDisable();    // Запретить прерывание TIMER2_OVF_vect
  }
  else
    tIteration++;
}

// Convert unsigned long long to String
String ULL2STR(unsigned long long ull)
{
  String digits[20], finalString = "";
  unsigned long long a = ull;
  for (int i = 19; i >= 0; i--)
  {
    digits[i] = String((unsigned int)( a % 10));
    a /= 10;
  }

  bool wasNonZero = false;
  for (int i = 0; i < 20; i++)
  {
    if (digits[i] != "0" || wasNonZero)
    {
      wasNonZero = true;
      finalString += digits[i];
    }
  }

  return finalString == "" ? "Nan" : finalString;
}

void setup() {

  DEV_TIMER2.setClockSelect(Prescaler2::Prescaler_1024);  // Предделитель /1024. 16 МГц / 1024 / 256 = 62.5 Гц
  DEV_TIMER2.setWaveGenMode(Timer2::Normal);

  // put your setup code here, to run once:         
  double a = 0, b = 1;
  Serial.begin(9600);
  Serial.println("Calculating FLOPS...");

  DEV_TICTRL2.overflowIntEnable();     // Разрешаем прерывание по переполнению т/с 2.
  interrupts();                        // Разрешаем прерывания
  ///unsigned long long it = 0;
  unsigned long long t = micros();

  // Main cycle
  while (doWhile)
    {a+=b;}

  unsigned long long c = (micros() - t);
  Serial.println("Time elapsed: " + ULL2STR(c) + "us");
  Serial.println("Operations done: " + ULL2STR(a));
  double FLOPS = (double)a / ((unsigned long long)c / (double)1000000);
  Serial.println("FLOPS: " + String(FLOPS) + " (FLoating-point Operations Per Second)");
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
      for (unsigned long long k = 0; k < (unsigned long long)10000000000000000000; k++)
        for (unsigned long long j = 0; j < (unsigned long long)10000000000000000000; j++)
          for (unsigned long long i = 0; i < (unsigned long long)10000000000000000000; i++)*/
}

/* Mean one*/
/*
  void setup() {
  // put your setup code here, to run once:
  double a = rand() / rand(), b = rand() / rand();
  Serial.begin(9600);
  Serial.println("Calculating FLOPS...");
  unsigned long long t = micros();

  for (unsigned long long p = 0; p < (unsigned long long)1000000; p++)
   if(a == b)_delay_us(1);

  unsigned long long c = (micros() - t);
  Serial.println("Time elapsed: " + ULL2STR(c) + "us");
  double FLOPS = (double)1000000 / ((unsigned long long)c / (double)1000000);
  Serial.println("FLOPS: " + String(FLOPS) + " (Floating-point operations per second)");
  }
*/

