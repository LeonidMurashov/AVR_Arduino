/*
 * StreetLights.cpp
 *
 * Created: 06.01.2018 23:25:51
 * Author : Леонид
 */ 
 #define F_CPU 1600000UL

#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	DDRB = 0xFF;
    /* Replace with your application code */
    while (1) 
    {
	    PORTB = 0b00000001;
		_delay_ms(10000);
		PORTB = 0b00000011;
		_delay_ms(2000);
		PORTB = 0b00000100;
		_delay_ms(6000);
		for(int i = 0; i < 3; i++)
		{
			PORTB = 0b00000000;
			_delay_ms(500);
			PORTB = 0b00000100;
			_delay_ms(500);
		}
		PORTB = 0b00000010;
		_delay_ms(4000);
    }
}

