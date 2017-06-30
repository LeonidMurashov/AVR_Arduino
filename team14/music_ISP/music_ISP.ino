//#include <iom8.h>
#include "notes.h" 
#include <avr/io.h>
#include <avr/interrupt.h>
//#define F_CPU 2048000

#define BUZZ_PIN 18

int SW_TONE[] = {LA3 ,LA3 ,LA3 ,F3  ,C4  ,LA3 ,F3  ,C4  ,LA3 ,E4  ,E4  ,E4  ,F4  ,C4  ,Ab3 ,F3  ,C4  ,LA3 ,LA4 ,LA3 ,LA3 ,LA4 ,Ab4 ,G4  ,Gb4 ,E4  ,F4  ,Bb3 ,Eb4 ,D4  ,Db4 ,C4  ,B3  ,C4  ,F3  ,Ab3 ,F3  ,LA3 ,C4  ,LA3 ,C4  ,E4  ,LA4 ,LA3 ,LA3 ,LA4 ,Ab4 ,G4  ,Gb4 ,E4  ,F4  ,Bb3 ,Eb4 ,D4  ,Db4 ,C4  ,B3  ,C4  ,F3  ,Ab3 ,F3  ,C4  ,LA3 ,F3  ,C4  ,LA3 ,};
int SW_DUR[] = {Q,Q,Q,E+S,S,Q,E+S,S,H,Q,Q,Q,E+S,S,Q,E+S,S,H,Q,E+S,S,Q,E+S,S,S,S,E,E,Q,E+S,S,S,S,E,E,Q,E+S,S,Q,E+S,S,H,Q,E+S,S,Q,E+S,S,S,S,E,E,Q,E+S,S,S,S,E,E,Q,E+S,S,Q,E+S,S,H,};
int len = 65;

int iter = 0;

ISR(TIMER1_COMPA_vect)//обработчик прерывания по совпадению А
{
  TCNT1H=0;//обнуляем регистр TCNT1
  TCNT1L=0;
  iter += 1;
  if(iter >= len)
  iter = 0;
  tone(BUZZ_PIN, SW_TONE[iter], SW_DUR[iter]);
  
}

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);


  
  DDRB=0x02;//настраиваем OC1A как выход
  PORTB=0x00;
  TCCR1A=0x40;//при совпадении уровень OC1A меняется на противоположный
  TCCR1B=0x05;//CLK/1024
  OCR1AH=0x3D;//записываем в регистр OCR1A 15625 (раз в секунду)
  OCR1AL=0x09;
  TIMSK1 = 0x10;//разрешаем прерывание по совпадению
  sei();//разрешаем прерывания глобально
  while(1);
}

void loop() {
  // put your main code here, to run repeatedly:

}
