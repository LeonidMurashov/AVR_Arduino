#line 1 "D:/робот/ulra_regen2.c"
sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

const int corr3 = 4,corr2 = 2, corr0 = 0, corr1 = 0;


char *text = "000";
void Display_Input(int x, int y, int z) {
#line 27 "D:/робот/ulra_regen2.c"
 text[0] = (z/100)%10 + 48;
 text[1] = (z/10)%10 + 48;
 text[2] = z%10 + 48;

 Lcd_Out(x,y,text);
}



void serv(int a, int port, int look)
{
int i,j,k;
if(look==1)k=1;
else k=15;
for(i = 0; i<k; i++)
{
 if(port == 0) PORTC.F6 = 1;
 else if(port == 1) PORTC.F5 = 1;
 else if(port == 2) PORTB.F4 = 1;
 else if(port == 3) PORTB.F5 = 1;

 delay_us(450);
 if(a<=50)for(j = 0; j<a; j++)delay_us(14);
 else
 {
 delay_us(14*50+140);
 for(j = 0; j<(a-50); j++)delay_us(15);
 }
 if(port == 0) PORTC.F6 = 0;
 else if(port == 1) PORTC.F5 = 0;
 else if(port == 2) PORTB.F4 = 0;
 else if(port == 3) PORTB.F5 = 0;

 delay_ms(20);
 }
}

 int skan()
 {
 int us = 0;
 PORTA.F5 = 1;
 delay_us(10);
 PORTA.F5 = 0;
 while(!PORTC.F7);
 while(PORTC.F7 != 0){delay_us(5);us = us + 5;}

 return us/58;
 }




void init()
{
 serv(50 + corr1, 1, 0);
 serv(10 + corr0, 0, 0);
 serv(50 + corr3, 3, 0);

 serv(50 + corr2, 2, 0);
}
void aim(int tagw, int dist)
{
 serv(tagw, 3, 0);
 serv(50 + corr0, 0, 0);
 serv(10 + corr1, 1, 0);
 serv(90 + corr1, 1, 0);
 serv(50 + corr1, 1, 0);
 serv(10 + corr0, 0, 0);
 serv(50 + corr3, 3, 0);

}
void main() {

 int i, minw, maxw, tagw, s, dist=300;
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);


 ANSELH.F4 = 0;
 TRISB = 0;
 TRISA.F4 = 1;
 TRISA.F5 = 0;
 TRISE.F1 = 1;
 TRISC = 0;
 TRISC.F7 = 1;

 Sound_Init(&PORTC,0);



 init();
#line 128 "D:/робот/ulra_regen2.c"
 while(1)
 {
 while(PORTA.F4);
 dist = 900;



 lcd_out(1,1,"Cur:");
 lcd_out(1,9,"Min:");
 lcd_out(2,9,"Tag:");

 serv(10+corr2, 2, 0);
 for(i = 10; i<90; i++)
 {
 serv(i+corr2, 2, 1);

 s = skan();
 if(s<0) s = 255;
 if(s<dist-7){dist = s; tagw = i; Display_Input(1,13,s);}

 Display_Input(1,5,s);

 delay_ms(25);
 }

 tagw = 50;
 Display_Input(2,13,tagw);
 lcd_out(2, 16, "'");
 serv(tagw+corr2, 2, 0);

 s = skan();
#line 166 "D:/робот/ulra_regen2.c"
 aim(tagw+4,dist);
 init();

}
#line 180 "D:/робот/ulra_regen2.c"
}
