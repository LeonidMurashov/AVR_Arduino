#include <adc.h>
int GP2=0;
float Distance;
char txt1[6];
char txt[13];                   // Save String
char *text1 ="RAW Value=";
char *text2 ="Far= CM";
char *text3 = "Out of Range";
void main()
{
     Lcd_Init(&PORTD);          // Init LCD Port
     Lcd_Cmd(LCD_CURSOR_OFF);   // LCD cursor off
     Lcd_Cmd(LCD_CLEAR);
  while(1)
  {
        GP2=Adc_Rd(2);          // Read ADC CH 2
        WordToStr(GP2,txt1);    // Convert Raw Data to String
        Lcd_Cmd(LCD_CLEAR);     // Clear Screen
        Lcd_Out(1,1,text1);     // Show Line 1 Text
        Lcd_Out(1,12,txt1);     // Show Raw Data
        if (GP2>90)             // Check Gp2 Out of Range ?
        {
           Distance=(2914.0/(GP2+5))-1;  // Convert to Centimeter
           FloatToStr(Distance,txt);     // Convert to String
           Lcd_Out(2,1,text2);           // Show on LCD
           Lcd_Out(2,5,txt);
        }
        else
            Lcd_Out(2,1,text3);          // Show Out of Range
        Delay_ms(400);
  }
}