#line 1 "E:/Work2007/MikroC/Code/A9-1/ReflectTest.c"



char txt[6];
char i;
int adc;
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

void main()
{
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 Lcd_Cmd(LCD_CLEAR);

 Lcd_Out(1,1, "<< RA4 >> Start");
 while(PORTA.F4==1);





 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1,"SENSOR0 = ");
 Lcd_Out(2,1,"SENSOR1 = ");

 while(1)
 {
 adc= Adc_Rd(0);
 WordToStr(adc,txt);
 Lcd_Out(1,10,txt);
 adc= Adc_Rd(1);
 WordToStr(adc,txt);
 Lcd_Out(2,10,txt);
 Delay_ms(100);
 }
}
