/*
 * helpFile.cpp
 *
 * Created: 21.03.2016 17:44:45
 *  Author: Леонид
 */ 
#include <avr/io.h>
#include<util/delay.h>

#define TIME_TO_WAIT_BEFORE 0 // 310 //T_WH-T_ASU
#define TIME_TO_WRITE 0 //140 //T_ASU
#define TIME_TO_WAIT_AFTER 0 //450 //T_WH
#define TIME_TO_WAIT_AFTER_WAITING 0 //10 //T_DHW

#define WAITING_TIME_FOR_E 3

unsigned char lcd[8][64][2]; //Страница>строка>CS>data(unsigned char - 8 бит)
//unsigned char updateStage = 0;
void E_PULL(); void Lcd_Clear();

void Lcd_Init()
{
	DDRC = 0b11111111;
	DDRD = 0b11111111;

	PORTD = 0;
	E_PULL();
	PORTD = 0b10000000;   //рестарт и инициализация
	PORTC = 0b00111111;
	E_PULL();
	
	Lcd_Clear();
}

void E_PULL()
{
	PORTD|=(1<<PB6);    _delay_us(WAITING_TIME_FOR_E); //дрыг начало
	PORTD&=~(1<<PB6);   _delay_us(WAITING_TIME_FOR_E); //дрыг конец
}


void WRITE(unsigned char data)
{
	PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
	PORTC = data;	    _delay_us(TIME_TO_WRITE);
	E_PULL();
}
void WRITE_D(unsigned char data, int CS)//CS1 or CS2
{
	if(CS==1)
	{
		PORTD = 0b10011000; _delay_us(TIME_TO_WAIT_BEFORE);
		PORTC = data;       _delay_us(TIME_TO_WRITE);
		E_PULL();
	}
	else if (CS==2)
	{
		PORTD = 0b10010100; _delay_us(TIME_TO_WAIT_BEFORE);
		PORTC = data;       _delay_us(TIME_TO_WRITE);
		E_PULL();
	}
}
void Lcd_Clear()
{
	for(int i = 0; i<8; i++)
	{
		PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
		PORTC = 0b10111000 + i; _delay_us(TIME_TO_WRITE);
		E_PULL();
		for(int j = 0; j<64; j++)
		{
			PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b01000000+j; _delay_us(TIME_TO_WRITE); //выбор ячейки по X
			E_PULL();
			
			PORTD = 0b10010100; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b00000000; _delay_us(TIME_TO_WRITE);	//стирание с CS1
			E_PULL();
			
			PORTD = 0b10011000; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b00000000; _delay_us(TIME_TO_WRITE);	//стирание с CS2
			E_PULL();
		}
	}
	
	for(int i = 0; i<8; i++)
		for(int j = 0; j<64; j++)
			{
				lcd[i][j][0] = 0b00000000;
				lcd[i][j][1] = 0b00000000;
			}			
}

void setPixel(unsigned char x, unsigned char y, bool state = true)// 0 - off // 1 - on
{
	if(x<128 && x>=0 && y >=0 && y<64 && (state == false || state == true))
	{
		unsigned char page = y/8, adress, databit = y%8, CS, data;
		if(x<64){CS = 0; adress = x;}
		else {CS = 1; adress = x-64;}
		
		WRITE(0b01000000 + adress);
		WRITE(0b10111000 + page);
		/*
		if(state)
			for(int i = 0; i<8; i++) if(lcd[page][adress][CS][i] || i == databit) data |= (1<<i);
		else
			for(int i = 0; i<8; i++) if(lcd[page][adress][CS][i] && i!=databit) data |= (1<<i);
		*/
		if(state) data = lcd[page][adress][CS] | (1<<databit);
		else 
		{
			data = lcd[page][adress][CS];
			if((lcd[page][adress][CS]) & (1<<databit)) data -= (1<<databit); 
		}
		
		WRITE_D(data, CS ? 2 : 1); //выбор половины
		
		if(state)lcd[page][adress][CS] |= (1<<databit);
		else 
		{
			if(lcd[page][adress][CS] & (1<<databit)) lcd[page][adress][CS] -= (1<<databit);
		}
	}
}

void Lcd_Fill()
{
	for(int i = 0; i<8; i++)
	{
		PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
		PORTC = 0b10111000 + i; _delay_us(TIME_TO_WRITE);
		E_PULL();
		for(int j = 0; j<64; j++)
		{
			PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b01000000+j; _delay_us(TIME_TO_WRITE); //выбор ячейки по X
			E_PULL();
			
			PORTD = 0b10010100; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b11111111; _delay_us(TIME_TO_WRITE);	//стирание с CS1
			E_PULL();
			
			PORTD = 0b10011000; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b11111111; _delay_us(TIME_TO_WRITE);	//стирание с CS2
			E_PULL();
		}
	}
	for(int i = 0; i<8; i++)
		for(int j = 0; j<64; j++)
		{
			lcd[i][j][0] = 0b11111111;
			lcd[i][j][1] = 0b11111111;
		}
	
}

void swap(int &a, int &b)
{
	int c = a - b;
	b = a;
	a = b + c;
}

int max(int a, int b)
{
	return a>b ? a : b;
}
void drawLine(int x1, int y1, int x2, int y2)
{
	int dx = (x2 - x1 >= 0 ? 1 : -1);
	int dy = (y2 - y1 >= 0 ? 1 : -1);
	
	int lengthX = abs(x2 - x1);
	int lengthY = abs(y2 - y1);
	
	int length = max(lengthX, lengthY);
	
	if (length == 0)
	{
		setPixel(x1, y1);
	}
	
	if (lengthY <= lengthX)
	{
		// Начальные значения
		int x = x1;
		int y = y1;
		int d = -lengthX;
		
		// Основной цикл
		length++;
		while(length--)
		{
			setPixel(x, y);
			x += dx;
			d += 2 * lengthY;
			if (d > 0) {
				d -= 2 * lengthX;
				y += dy;
			}
		}
	}
	else
	{
		// Начальные значения
		int x = x1;
		int y = y1;
		int d = - lengthY;
		
		// Основной цикл
		length++;
		while(length--)
		{
			setPixel(x, y);
			y += dy;
			d += 2 * lengthX;
			if (d > 0) {
				d -= 2 * lengthY;
				x += dx;
			}
		}
	}
}

void drawCircle(int x0, int y0, int radius)
{
	int x = radius;
	int y = 0;
	int radiusError = 1 - x;
	while (x >= y)
	{
		setPixel(x + x0, y + y0);
		setPixel(y + x0, x + y0);
		setPixel(-x + x0, y + y0);
		setPixel(-y + x0, x + y0);
		setPixel(-x + x0, -y + y0);
		setPixel(-y + x0, -x + y0);
		setPixel(x + x0, -y + y0);
		setPixel(y + x0, -x + y0);
		y++;
		if (radiusError < 0)
		{
			radiusError += 2 * y + 1;
		}
		else
		{
			x--;
			radiusError += 2 * (y - x + 1);
		}
	}
}



/*
void setPixel(unsigned char x, unsigned char y, unsigned char state = 1)// 0 - off // 1 - on //2 - blinking
{
	if(x<128 && x>=0 && y >=0 && y<64)
	{
		int page = y/8, adress, dataint = y%8, CS;
		if(x<64){CS = 0; adress = x;}
		else {CS = 1; adress = x-64;}		
				
		lcd[page][adress][CS][dataint] = state;
	}
}
void Lcd_Update()
{
	unsigned char data;
	for(int i = 0; i<8; i++)
	{
		PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
		PORTC = 0b10111000 + i; _delay_us(TIME_TO_WRITE);
		E_PULL();
		for(int j = 0; j<64; j++)
		{
			PORTD = 0b10000000; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = 0b01000000+j; _delay_us(TIME_TO_WRITE); //выбор ячейки по X
			E_PULL();
			
			data = 0b00000000;
			for(int o = 0; o<8; o++)
			{
				if(lcd[i][j][0][o] == 1) data |= (1<<o);
				if(lcd[i][j][0][o] > 1 && updateStage < lcd[i][j][0][o]) data |= (1<<o);
			}
						
			PORTD = 0b10011000; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = data; _delay_us(TIME_TO_WRITE);	//заполнение CS1
			E_PULL();
			
			data = 0b00000000;
			for(int o = 0; o<8; o++)
			{
				 if(lcd[i][j][1][o] == 1) data |= (1<<o);
				 if(lcd[i][j][1][o] > 1 && updateStage < lcd[i][j][1][o]) {data |= (1<<o);} 
			}
			PORTD = 0b10010100; _delay_us(TIME_TO_WAIT_BEFORE);
			PORTC = data; _delay_us(TIME_TO_WRITE);	//заполнение CS2
			E_PULL();
		}
	}
	updateStage++;
	if(updateStage == 10)updateStage = 0;
}
*/