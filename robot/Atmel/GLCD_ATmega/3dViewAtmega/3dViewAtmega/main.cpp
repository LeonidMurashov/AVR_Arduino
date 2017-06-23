/*
 * 3dViewAtmega.cpp
 *
 * Created: 20.03.2016 10:45:08
 * Author : Леонид
 */ 

#define F_CPU 20000000

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
#include <math.h>
#include "Lcd.hpp"


struct Point
{
	int x, y, z;
	Point(int _x, int _y, int _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}
};

struct Line
{
	Point *p1;
	Point *p2;
	Line(int _x,int _y, int _z,int _x1,int _y1, int _z1)
	{
		p1 = new Point(_x, _y, _z);
		p2 = new Point(_x1, _y1, _z1);
	}	
	Line(Point _p1, Point _p2)
	{
		p1 = &_p1;
		p2 = &_p2;
	}
};
/*
class Cube
{
	Point vertex[8];
	Line edges[12];
	int x, y, z, size;
	public:
	void draw(int dist)
	{
		for(int i = 0; i<12; i++)
		{
			int x1 = 128/2+edges[i].p1.x*dist/(edges[i].p1.z+dist);	
			int y1 = 64/2-edges[i].p1.y*dist/(edges[i].p1.z+dist);
			int x2 = 128/2+edges[i].p2.x*dist/(edges[i].p2.z+dist);
			int y2 = 64/2-edges[i].p2.y*dist/(edges[i].p2.z+dist);
			drawLine(x1,y1,x2,y2);	
		}
	}
	void shift(int xm, int ym, int zm)
	{
		x += xm;
		y += ym;
		z += zm;
	}
	Cube(int _x, int _y, int _z, int _size)
	{
		size = _size;		
		x = _x;
		y = _y;
		z = _z;		
		
		vertex[0] = Point(0,0,0);	
	}	
};
/*		

vertex =
{
	Point(0,0,0),
	Point(0,0,size),
	Point(0,size,0),
	Point(size,0,0),
	Point(size,size,0),
	Point(size,0,size),
	Point(0,size,size),
	Point(size,size,size)
};
Line _edges[] =
{
Line(vertex[0], vertex[1]),
Line(vertex[0], vertex[2]),
Line(vertex[0], vertex[3]),
Line(vertex[1], vertex[5]),
Line(vertex[1], vertex[6]),
Line(vertex[2], vertex[4]),
Line(vertex[2], vertex[6]),
Line(vertex[3], vertex[4]),
Line(vertex[3], vertex[5]),
Line(vertex[4], vertex[7]),
Line(vertex[5], vertex[7]),
Line(vertex[6], vertex[7])
};*/
		/*		vertex[0] = Point(0,0,0);
		vertex[1] = Point(0,0,size);
		vertex[2] = Point(0,size,0);
		vertex[3] = Point(size,0,0);
		vertex[4] = Point(size,size,0);
		vertex[5] = Point(size,0,size);
		vertex[6] = Point(0,size,size);
		vertex[7] = Point(size,size,size) ;
		
		
		edges[0] = Line(vertex[0], vertex[1]);
		edges[1] = Line(vertex[0], vertex[2]);
		edges[2] = Line(vertex[0], vertex[3]);
		edges[3] = Line(vertex[1], vertex[5]);
		edges[4] = Line(vertex[1], vertex[6]);
		edges[5] = Line(vertex[2], vertex[4]);
		edges[6] = Line(vertex[2], vertex[6]);
		edges[7] = Line(vertex[3], vertex[4]);
		edges[8] = Line(vertex[3], vertex[5]);
		edges[9] = Line(vertex[4], vertex[7]);
		edges[10] = Line(vertex[5], vertex[7]);
		edges[11] = Line(vertex[6], vertex[7]);*/

int main(void)
{ 
	//DDRA = 0b00011111; // 1 - выход 0 - вход
	DDRA = 0b00000000;
	DDRB = 0b11111111;	
	Lcd_Init();
	
	Point *a;
	a = new Point(1,1,1);
	
	int dist = 15;	
	/*Cube cube(0,0,0,20);
	while(1) 
	{
		cube.draw(dist);
	
	
		if(PINA&1){cube.shift(0,1,0); _delay_ms(50); Lcd_Clear();}
		if(PINA&2){cube.shift(-1,0,0); _delay_ms(50); Lcd_Clear();}
		if(PINA&4){cube.shift(1,0,0); _delay_ms(50); Lcd_Clear();}
		if(PINA&8){cube.shift(0,-1,0); _delay_ms(50); Lcd_Clear();}
		if(PINA&64){dist++; _delay_ms(50); Lcd_Clear();}
		if(PINA&128){dist--; _delay_ms(50); Lcd_Clear();}	
					
	}*/
	//sx = xSize/2+x*dist/(z+dist),
	//sy = ySize/2-y*dist/(z+dist).				
					
	return 0;	
}


