#include <motor.h>                 // Motor Control Library
#include <adc.h>                   // Use Analog to Digital Library
/**********************************/
/*   Text For Show On LCD         */
/**********************************/
char *text1 = "Edge of a table" ;
char *text2 = "From Left";
char *text3 = "From Right";
char *text4 = "Let'Go" ;
char *text5 = "Route Clear";

char flag=0;
int ADC=0;
void main()
{
  Lcd_Init(&PORTD);                // Init LCD Port
  Lcd_Cmd(LCD_CURSOR_OFF);         // LCD cursor off
  Lcd_Cmd(LCD_CLEAR);
                                   // Check Key Press
  Lcd_Out(1,1, "<< RA4 >> Start");
  while(PORTA.F4==1);

  while(1)
  {
     ADC =Adc_Rd(0);               // Reading Sensor from Left
     if (ADC<100)                  // Left Sensor Found Edge of Table ?
     {
          flag=0;                  // clear flag
          Backward(255);
          Lcd_Cmd(LCD_CLEAR);      // Show Text ON LCD
          Lcd_Out(1,1,text1);
          Lcd_Out(2,1,text2);
          Delay_ms(400);
          S_Right(255);            // Change route
          Delay_ms(600);
     }
     ADC =Adc_Rd(1);               // Reading Sensor from Right
     if (ADC<100)                  // Right Sensor Found Edge of Table ?
     {
          flag=0;                  // Clear Flag
          Backward(255);
          Lcd_Cmd(LCD_CLEAR);      // Show LCD text
          Lcd_Out(1,1,text1);
          Lcd_Out(2,1,text3);
          Delay_ms(400);
          S_Left(255);             // Change route
          Delay_ms(900);
     }
     forward(255);                 // normal ==> Forward
     if (flag==0)                  // check fisrt time Show LCD ?
     {
     flag=1;
     Lcd_Cmd(LCD_CLEAR);           // Show LCD
     Lcd_Out(1,1,text4);
     Lcd_Out(2,1,text5);
     }
  }

}