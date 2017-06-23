int i=0;
char txt[6];                       // Save 16 bit 0-65535
void main()
{
  Lcd_Init(&PORTD);                // Config PORTD connect LCD
  Lcd_Cmd(LCD_CURSOR_OFF);         // Setting cursor of LCD off
  Lcd_Cmd(LCD_CLEAR);              // Clear Screen First
  Lcd_Out(1,1,"Counter= ");        // Show Text

  while(1)
  {
     i++;                          // Count
     WordToStr(i,txt);             // Convert to String
     Lcd_Out(1,10,txt);            // Show Counter ==> LCD
     Delay_ms(100);
  }
}