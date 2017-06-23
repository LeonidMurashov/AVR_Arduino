char *text1 = "Innovative";        // Save Text
char *text2 = "Experiment";

void main()
{
  Lcd_Init(&PORTD);                // Config PORTD connect LCD
  Lcd_Cmd(LCD_CURSOR_OFF);         // Setting cursor of LCD off
  while(1)
  {
    Lcd_Out(1,4,text1);            // Show "Innovative" in Line 1
    Lcd_Out(2,4,text2);            // Show "Experiment" int Line 2
    Delay_ms(5000);
    Lcd_Cmd(LCD_CLEAR);            // Blink LCD
    Delay_ms(500);
  }
}