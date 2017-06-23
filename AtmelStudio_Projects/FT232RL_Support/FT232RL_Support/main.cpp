/*
 * FT232RL_Support.cpp
 *
 * Created: 30.06.2016 20:41:44
 * Author : Leonid
 *
 * Статья про таймеры: http://chipenable.ru/index.php/programming-avr/item/171-avr-timer-t0-ch1.html
 *
 * И по-конкретней: http://www.doneathome.ru/archives/364 
 */ 

 #define F_CPU 20000000
 #define INT_MAX 65535

#include <avr/io.h >
#include <avr/interrupt.h>
#include <avr/delay.h>

unsigned char servoAngle = 60;

void TurnServo(unsigned char angle)
{
	if(angle < 0)
		angle = 0;
	if(angle > 120)
		angle = 120;

	PORTD = 255;
	_delay_us(544);
	for(unsigned short i = 0; i<angle; i++)
		_delay_us(9);
	PORTD = 0;

	servoAngle = angle;
}
/*
ISR( TIMER2_COMPA_vect )
{
	cli(); // Глобальный запрет прерываний
	
	if(PINA)
		PORTA = 0;
	else
		PORTA = 255;

	sei();  // выставить бит общего разрешения прерываний
}*/

int main(void)
{   
 //DDRA = 0b00011111; // 1 - выход 0 - вход
   DDRC = 0b00000000;
   DDRD = 0b10000000;
   DDRA = 0b11111111;

   /*// Setting up timers
   TCCR2B = (1<<CS12)|(0<<CS11)|(1<<CS10); //xtall/1024
   TCCR2A |= (1<<WGM01)|(0<<WGM00); //Установка сброса TCNT1, после прерывания
   OCR2A = 19500; // Значение для 20ms, для сравнения

   //TCNT1 = 0;

   TIMSK2 |= (1<<OCIE2A);  // разрешить прерывание по совпадению таймера счетчика с OCR01
   sei();                // выставить бит общего разрешения прерываний
   //cli(); // Глобальный запрет прерываний
   */

  PORTA = 255;

   while(true)
   {
	if(PINC != 255)TurnServo(PINC);
	_delay_ms(20);
   }
   return 0;

}

  