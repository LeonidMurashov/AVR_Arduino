#line 1 "E:/Work2007/MikroC/Code/A7-1/GP2D120Test.c"
#line 1 "c:/program files/mikroelektronika/mikroc/include/adc.h"
int Adc_Rd(char ch)
{
 int dat=0;
 if ((ch>=0) && (ch<=3))
 TRISA |= (1<<ch);
 else if (ch==4)
 TRISA |= 0x20;
 else if ((ch>=5) && (ch<=7))
 TRISE |= (1<<(ch-5));
 ANSEL |=(1<<ch);
 ADCON0 = (0xC1 + (ch*4));
 Delay_us(10);
 ADCON0.GO=1;
 while(ADCON0.GO);
 dat = (ADRESH*4)+(ADRESL/64);
 return dat;
}
#line 2 "E:/Work2007/MikroC/Code/A7-1/GP2D120Test.c"
int GP2=0;
float Distance;
char txt1[6];
char txt[13];
char *text1 ="RAW Value=";
char *text2 ="Far= CM";
char *text3 = "Out of Range";
void main()
{
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 Lcd_Cmd(LCD_CLEAR);
 while(1)
 {
 GP2=Adc_Rd(2);
 WordToStr(GP2,txt1);
 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1,text1);
 Lcd_Out(1,12,txt1);
 if (GP2>90)
 {
 Distance=(2914.0/(GP2+5))-1;
 FloatToStr(Distance,txt);
 Lcd_Out(2,1,text2);
 Lcd_Out(2,5,txt);
 }
 else
 Lcd_Out(2,1,text3);
 Delay_ms(400);
 }
}
