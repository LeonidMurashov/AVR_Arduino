#include <adc.h>
#include <motor.h>

int GP2=0,CNT=0;                    // Variable
char txt[6],i,Round=0;
//char *text1="Object Detector";
//char *text2="Distance =";
void main()
{
 Sound_Init(&PORTC,0);               // Init Sound ==> RC0
 Lcd_Init(&PORTD);                   // Init LCD PORT D
 Lcd_Cmd(LCD_CURSOR_OFF);            // LCD cursor off
 Lcd_Cmd(LCD_CLEAR);
// Lcd_Out(1,1, "<< RA4 >> Start");  // Use For registered MikroC
// Lcd_Out(2,1,"GP2 Reading");       // Use For registered MikroC
 while(PORTA.F4==1);                 // Start Program when Press RA4
/********************************************/
 Lcd_Cmd(LCD_CLEAR);                 // Show Text
 //Lcd_Out(1,1,text1);               // Use For registered MikroC
 //Lcd_Out(2,1,text2);               // Use For registered MikroC
 while(1)
 {
  for (i=0;i<10;i++)GP2+=Adc_Rd(2);  // Read Gp2 10 Time
  GP2=GP2/10;                        // and Average
  CNT++;                             // Counter For Show LCD
  if (CNT>600)
  {
   CNT=0;
   WordToStr(GP2,Txt);               // Show LCD
   Lcd_Out(2,11,Txt);
  }
  if (GP2>500)                       // Check Gp2 Out of Range ?
  {
   Round++;                          // Counter For Rotate Robot
   Backward(255);
   WordToStr(GP2,Txt);
   Lcd_Out(2,11,Txt);
   Sound_Play(250,100);
   Delay_ms(500);
   if (Round>5)                      // Right 5 Time ?
   {
    Round=0;
    S_Right(255);
    Delay_ms(1000);
   }
   else                              // More Then 5 Time ==> Left
   {
    S_Left(255);
    Delay_ms(1000);
   }
  }
  Forward(255);                      // Not Found Object => Forward
  }
}