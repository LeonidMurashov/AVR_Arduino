/***********************************/
/*****  Show ADC from RA0 to LCD ***/
/***********************************/
char txt[6];                       // Save test
int  adc;
void main()
{
  Delay_ms(1000);

  Lcd_Init(&PORTD);                // Init LCD Port
  Lcd_Cmd(LCD_CURSOR_OFF);         // LCD cursor off
  Lcd_Out(1,1,"SENSOR0 = ");       // Show Text

  TRISA  = 0xFF;                   // PORTA ==> input
  ANSEL = 0xFF;                    // PORTA ==> Analog
  ADCON0=0b11000001;               // Select Analog1 RC_Mode and ADON
  while(1)
  {
     ADCON0.GO=1;                  // Start conversion
     while(ADCON0.GO);             // conversion done?
     adc= (ADRESH*4)+(ADRESL/64);  // Sum highbyte and lowbyte
     WordToStr(adc,txt);           // Convert to ASCII
     Lcd_Out(1,10,txt);            // Show on LCD
     Delay_ms(100);
  }
}
