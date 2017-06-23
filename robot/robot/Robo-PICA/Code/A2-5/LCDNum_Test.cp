#line 1 "E:/Work2007/MikroC/Code/A2-5/LCDNum_Test.c"
int i=0;
char txt[6];
void main()
{
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1,"Counter= ");

 while(1)
 {
 i++;
 WordToStr(i,txt);
 Lcd_Out(1,10,txt);
 Delay_ms(100);
 }
}
