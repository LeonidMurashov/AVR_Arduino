/*
 * Painter_GLCD.cpp
 *
 * Created: 27.03.2016 13:25:26
 * Author : Леонид
 */ 

#define F_CPU 20000000

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <math.h>
#include "Lcd.hpp"

class Ground
{
	bool mas[128][64];
	public:
	void setground(int x, int y, bool state)
	{
		if(x<128 && x>=0 && y >=0 && y<64)
		mas[x][y] = state;
	}

	bool getground(int x, int y)
	{
		if(x<128 && x>=0 && y >=0 && y<64)
		return mas[x][y];
		else
		return true;
	}
	
	void clear()
	{
		for(int i = 0; i<128; i++)
		for(int j = 0; j<64; j++)
		mas[i][j] = false;
	}
	Ground()
	{
		clear();
	}
};
Ground ground;

class Player
{
	int x, y;
	unsigned char enableDraw;
	
	void draw()
	{
		if(enableDraw != 2)
		{
			if(enableDraw == 1)setPixel(x,y); else setPixel(x,y,0);
			setPixel(x+1,y);
			setPixel(x-1,y);
			setPixel(x,y+1);
			setPixel(x,y-1);
			
			if(enableDraw)ground.setground(x,y,true);
		}
		else
		{
			setPixel(x-2, y-2,1); setPixel(x-1, y-2,1); setPixel(x,y-2,1); setPixel(x+1, y-2,1); setPixel(x+2, y-2,1);
			setPixel(x-2, y-1,1); setPixel(x-1, y-1,0); setPixel(x,y-1,0); setPixel(x+1, y-1,0); setPixel(x+2, y-1,1);
			setPixel(x-2, y  ,1); setPixel(x-1, y  ,0); setPixel(x,y  ,0); setPixel(x+1, y  ,0); setPixel(x+2, y  ,1);
			setPixel(x-2, y+1,1); setPixel(x-1, y+1,0); setPixel(x,y+1,0); setPixel(x+1, y+1,0); setPixel(x+2, y+1,1);
			setPixel(x-2, y+2,1); setPixel(x-1, y+2,1); setPixel(x,y+2,1); setPixel(x+1, y+2,1); setPixel(x+2, y+2,1);
			
			for(int i = x-1; i<=x+1; i++)
			for(int j = y-1; j<=y+1; j++)
			ground.setground(i,j,0);
		}
		
		if(enableDraw == 0)PORTB = 2;
		else if(enableDraw == 1)PORTB = 1;
		else if(enableDraw == 2)PORTB = 4;
	}
	
	public:
	
	void remove()
	{
		if(enableDraw != 2)
		{
			if(!ground.getground(x,y))setPixel(x,y,0); else setPixel(x,y);
			if(!ground.getground(x+1,y))setPixel(x+1,y,0);
			if(!ground.getground(x-1,y))setPixel(x-1,y,0);
			if(!ground.getground(x,y+1))setPixel(x,y+1,0);
			if(!ground.getground(x,y-1))setPixel(x,y-1,0);
		}
		else
		{
			if(!ground.getground(x-2, y-2))setPixel(x-2, y-2,0); if(!ground.getground(x-1, y-2))setPixel(x-1, y-2,0); if(!ground.getground(x,y-2))setPixel(x,y-2,0); if(!ground.getground(x+1, y-2))setPixel(x+1, y-2,0); if(!ground.getground(x+2, y-2))setPixel(x+2, y-2,0);
			if(!ground.getground(x-2, y-1))setPixel(x-2, y-1,0);																																				  if(!ground.getground(x+2, y-1))setPixel(x+2, y-1,0);
			if(!ground.getground(x-2, y  ))setPixel(x-2, y  ,0);																			 																      if(!ground.getground(x+2, y  ))setPixel(x+2, y  ,0);
			if(!ground.getground(x-2, y+1))setPixel(x-2, y+1,0);																			 																	  if(!ground.getground(x+2, y+1))setPixel(x+2, y+1,0);
			if(!ground.getground(x-2, y+2))setPixel(x-2, y+2,0); if(!ground.getground(x-1, y+2))setPixel(x-1, y+2,0); if(!ground.getground(x,y+2))setPixel(x,y+2,0); if(!ground.getground(x+1, y+2))setPixel(x+1, y+2,0); if(!ground.getground(x+2, y+2))setPixel(x+2, y+2,0);
		}
	}
	
	void move(int xm,int ym)
	{
		remove();
		x += xm;
		y += ym;
		draw();
	}
	
	void respawn(int xm, int ym)
	{
		remove();
		x = xm;
		y = ym;
		draw();
	}
	
	void changeState()
	{
		remove();
		if(enableDraw)enableDraw = 0;
		else enableDraw = 1;
		
		draw();
	}
	
	void rubberOn()
	{
		if(enableDraw!=2)
		{
			remove();
			enableDraw = 2;
			draw();
		}
		else
		{
			changeState();
		}
	}
	
	Player(int _x, int _y)
	{
		x = _x;
		y = _y;
		enableDraw = 1;
		draw();
	}
};

int main(void)
{
	//DDRA = 0b00011111; // 1 - выход 0 - вход
	DDRA = 0b00000000;
	DDRB = 0b11111111;	
	Lcd_Init();
	
	Ground ground;
	ground.setground(1,1,1);
	Player player(64,32);
	
	while(1)
	{
		Lcd_Fill();
		for(int i = 0; i<10; i++)circle(rand()%128,rand()%64,rand()%32,false);
		
		_delay_ms(1500);
		for(int i = 0; i < 128; i++)
			for(int j = 0; j < 64; j++)
				{setPixel(i,j,0);_delay_us(50);}
	}
	
	while(1)
	{		
		if(PINA&1)player.move(0,-1);
		if(PINA&2)player.move(-1,0);
		if(PINA&4)player.move(1,0);
		if(PINA&8)player.move(0,1);
		if(PINA&16){while(PINA&16);player.changeState();}
		if(PINA&32){while(PINA&32);player.rubberOn();}
					
		_delay_ms(50);		
	}	
}