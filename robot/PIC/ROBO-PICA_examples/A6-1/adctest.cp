#line 1 "E:/Work2007/MikroC/Code/A6-1/adctest.c"



char txt[6];
int adc;
void main()
{
 Delay_ms(1000);

 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 Lcd_Out(1,1,"SENSOR0 = ");

 TRISA = 0xFF;
 ANSEL = 0xFF;
 ADCON0=0b11000001;
 while(1)
 {
 ADCON0.GO=1;
 while(ADCON0.GO);
 adc= (ADRESH*4)+(ADRESL/64);
 WordToStr(adc,txt);
 Lcd_Out(1,10,txt);
 Delay_ms(100);
 }
}
