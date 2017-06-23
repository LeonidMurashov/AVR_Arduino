#line 1 "E:/Work2007/MikroC/Code/A12-1/IntTest.c"
void interrupt()
{
 Sound_Play(2000,200);
 INTCON.INTF=0;
}
void main()
{

 ANSELH.F4=0;
 OPTION_REG.INTEDG = 0;
 INTCON.INTE =1;
 INTCON.GIE =1;

 TRISB.F3=0;
 Sound_Init(&PORTC,0);
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1, "<< RA4 >> Start");
 Lcd_Out(2,1,"Test Interrupt");
 while(PORTA.F4==1);

 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1, "Start Program");
 while(1)
 {
 PORTB.F3=1;
 Delay_ms(500);
 PORTB.F3=0;
 Delay_ms(500);
 }
}
