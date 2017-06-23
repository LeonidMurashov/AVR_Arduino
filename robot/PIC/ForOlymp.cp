#line 1 "D:/robot/PIC/ForOlymp.c"
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

char *text = "000";
#line 33 "D:/robot/PIC/ForOlymp.c"
int getFromSensor(int sensor)
{
 if(sensor==0)
 return (int)(ADC_READ(3)/3.95);
 else if(sensor==1)
 return (int)(ADC_READ(0)/6.72);
}

 void Right(); void Left(); void Forward(); void Backward(); void Stop();

 int skan()
 {
 int us = 0;
 PORTA.F5 = 1;
 delay_us(10);
 PORTA.F5 = 0;
 while(!PORTC.F7);
 while(PORTC.F7 != 0){delay_us(5);us = us + 5;}


 if(us/58>0 && us/58<255){ return us/58;}
 else { return 255;}
 }
 void RotateR(int gr)
 {
 int i;
 Right();
 for(i = 0; i<gr; i++) delay_us(7590);
 Stop();
 }
#line 70 "D:/robot/PIC/ForOlymp.c"
void main() {

 int i, adc, minw, maxw, tagw, s, dist=300;
 int last0 = 0, last1 = 0;
 int lastvec = 0;

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);


 TRISA = 0xFF;
 ANSEL = 0xFF;
 ANSELH = 0x00 ;
 TRISC.F7 = 1;
 TRISA.F5 = 0;



 TRISB.F1=0;TRISB.F2=0;
 TRISD.F0=0;TRISD.F1=0;
 TRISC.F1=0;TRISC.F2=0;


 Sound_Init(&PORTC,0);
 Stop();



 while(PORTA.f4);
 delay_ms(500);
 sound_play(500,500);
#line 111 "D:/robot/PIC/ForOlymp.c"
 Forward();
 while(skan()>4)
 {
 if(getFromSensor(0)>=80 && getFromSensor(1)>=80)
 {
 Forward();
 }
 else if(getFromSensor(0)>=80 && getFromSensor(1)<=60)
 {
 Right();
 }
 else if(getFromSensor(0)<=60 && getFromSensor(1)>=80)
 {
 Left();
 }
 else
 {
 Forward();
 }
 delay_ms(50);
 Forward();
 delay_ms(100);

 }
 Stop();
 RotateR(540);
 Forward();
 while(skan()>3);


 Stop();
#line 169 "D:/robot/PIC/ForOlymp.c"
}

void Right()
{
 PORTC.F1=1;PORTC.F2=1;
 PORTD.F0 =0;PORTD.F1 =1;
 PORTB.F1 =1;PORTB.F2 =0;
}
void Left()
{
 PORTC.F1=1;PORTC.F2=1;
 PORTB.F1 =0;PORTB.F2 =1;
 PORTD.F0 =1;PORTD.F1 =0;
}
void Forward()
{
 PORTC.F1=1;PORTC.F2=1;
 PORTB.F1 =0;PORTB.F2 =1;
 PORTD.F0 =0;PORTD.F1 =1;
}
void Backward()
{
 PORTC.F1=1;PORTC.F2=1;
 PORTD.F0 =1;PORTD.F1 =0;
 PORTB.F1 =1;PORTB.F2 =0;
}
void Stop()
{
 PORTC.F1 =0;PORTC.F2 =0;
}
