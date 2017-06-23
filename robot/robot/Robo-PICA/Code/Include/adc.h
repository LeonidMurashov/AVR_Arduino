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
