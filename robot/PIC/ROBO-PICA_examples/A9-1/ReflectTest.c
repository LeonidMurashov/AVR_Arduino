/***********************************/
/*****  Show ADC from RA0 to LCD ***/
/***********************************/
char txt[6];                       // Save test
char i;
int  adc;
int Adc_Rd(char ch)                // Low 8 Channel ADC Read
{
     int dat=0;                    // Save Adc
     if ((ch>=0) && (ch<=3))       // CH0-CH3
           TRISA |= (1<<ch);
     else if (ch==4)               // CH4
           TRISA |= 0x20;
     else if ((ch>=5) && (ch<=7))  // CH5-CH7
           TRISE |= (1<<(ch-5));
     ANSEL |=(1<<ch);              // set Channel to Analog
     ADCON0 = (0xC1 + (ch*4));     // Select ADC Channel
     Delay_us(10);                 // Acquisiton delay
     ADCON0.GO=1;                  // Start conversion
     while(ADCON0.GO);             // conversion done?
     dat = (ADRESH*4)+(ADRESL/64); // Sum highbyte and lowbyte
     return dat;                   // Return Value
}

void main()
{
  Lcd_Init(&PORTD);                // Init LCD Port
  Lcd_Cmd(LCD_CURSOR_OFF);         // LCD cursor off
  Lcd_Cmd(LCD_CLEAR);
                                   // keypress
  Lcd_Out(1,1, "<< RA4 >> Start");
  while(PORTA.F4==1);

/********************************/
//  Start Program
/********************************/

  Lcd_Cmd(LCD_CLEAR);
  Lcd_Out(1,1,"SENSOR0 = ");       // Show Text Line1
  Lcd_Out(2,1,"SENSOR1 = ");       // Line2

  while(1)
  {
     adc= Adc_Rd(0);
     WordToStr(adc,txt);           // Convert to ASCII
     Lcd_Out(1,10,txt);            // Show on LCD Line1
     adc= Adc_Rd(1);
     WordToStr(adc,txt);           // Convert to ASCII
     Lcd_Out(2,10,txt);            // Show on LCD Line2
     Delay_ms(100);
  }
}
