#line 1 "E:/Work2007/MikroC/Code/A2-4/LCDChar_Test.c"
char *text1 = "Innovative";
char *text2 = "Experiment";

void main()
{
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 while(1)
 {
 Lcd_Out(1,4,text1);
 Lcd_Out(2,4,text2);
 Delay_ms(5000);
 Lcd_Cmd(LCD_CLEAR);
 Delay_ms(500);
 }
}
