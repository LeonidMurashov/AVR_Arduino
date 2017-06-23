/*
 * test.c
 *
 * Created: 04.11.2015 13:16:12
 * Author : LeoMur
 */ 
#define F_CPU 20000000

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <math.h>
//#include <stdbool.h>


float log2(float a)
{
	return log(a)/log(2);
}
void truebit()
{
	for(int i = 0; i<100; i++)
	{
		PORTA=1023;
		_delay_ms(1);
		PORTA=0;
		_delay_ms(1);
	}
}
void falsebit()
{
		for(int i = 0; i<100; i++)
		{
			PORTA=1023;
			_delay_ms(3);
			PORTA=0;
			_delay_ms(3);
		}
}

int main(void)
{
    
	//DDRA = 0b00011111; // 1 - выход 0 - вход
    DDRA = 0b11111111;
	DDRB = 0b11100000;
	//DDRB = 0b11111111;
	DDRC = 0b00000000;
	DDRD = 0b11111111;
	long long i = 0;
	long long TIME = 300;
	PORTA=0;


	while (1) 
    {
		
		/*PORTA=1;
		_delay_ms(500);
		PORTA=0;
		_delay_ms(500);*/

		/*	for(i=0; i<500; i++)
			{
				PORTA=1023;
				for(int j = 0; j< i; j++)_delay_us(1);
				PORTA=0;
				for(int j = 0; j< 500-i; j++)_delay_us(1);
			}
			for(i=500; i>0; i--)
			{
				PORTA=1023;
				for(int j = 0; j< i; j++)_delay_us(1);
				PORTA=0;
				for(int j = 0; j< 500-i; j++)_delay_us(1);
			}*/
		
		
		
		/*PORTA=1023;
		for(int j = 0; j<PINC; j++)_delay_ms(1);
		PORTA=0;
		for(int j = 0; j<PINC; j++)_delay_ms(1);*/
		
			//_delay_ms(3000);
	//	PORTA = 0;
		int port = PINC;
	
		
		/*
		
		for(int i = floor(log2(port)); i>=0; i--)
		{
			if(port-pow(2,i)>=0)
			{
				port-=pow(2,i);
				truebit();
			}
			else falsebit();
			_delay_ms(500);
		}
		*/
		/*_delay_ms(1000);
		PORTA=1023;
		_delay_ms(1000);*/
			
		
		
		PORTA=1023;
		for(int j = 0; j<port ; j++)_delay_us(1);
		PORTA = 0; //// здесь 0
		for(int j = 0; j<255-port ; j++)_delay_us(1);
		
		
		
		
		//_delay_ms(500);
		
		
		///PORTA = PINC;
		/*PORTC = 255;
		for(int j = 0; j<TIME ; j++)_delay_us(1);
		PORTC = 0;
		for(int j = 0; j<TIME ; j++)_delay_us(1);
		if(PINB == 1){TIME-=1;_delay_ms(100);}
		if(PINB == 2){TIME-=10;_delay_ms(100);}
		if(PINB == 4){TIME+=10;_delay_ms(100);}
		if(PINB == 8){TIME+=1;_delay_ms(100);}
			PORTA = PINB;
		/*if(PINB!=0){TIME-=100;PORTD = 1;}
		else PORTD = 0;
		
		/**/
		/*i++;
		PORTA = i;
		PORTB = i /256;
		PORTC = i /65536;
		PORTD = i /16777216;*/
		//_delay_ms(1);
    }
}

