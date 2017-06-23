#include <motor.h>                      // Motor Control Library
#include <adc.h>                        // Use Analog to Digital Library
/**********************************/
/*   Text For Show On LCD         */
/**********************************/

//char *text0 = "Forward Only";
//char *text1 = "Found Line" ;
//char *text2 = "On Left";
//char *text3 = "On Right";
//char *text4 = "Not Found Line";
//char *text5 = "Cross Number";
char Cnt=0;                             // Counter
char txt[4];                            // Save String
char First_Time=5;                      // Save Status
int ADC1=0,ADC2=0;
void main()
{
/* LCD Initial */
//  Lcd_Init(&PORTD);                     // Init LCD Port
//  Lcd_Cmd(LCD_CURSOR_OFF);              // LCD cursor off
//  Lcd_Cmd(LCD_CLEAR);
/* Sound Initial */
  Sound_Init(&PORTC,0);
/* Check Key Press*/
//  Lcd_Out(1,1, "<< RA4 >> Start");
//  Lcd_Out(2,1,"Line Tracking");
  while(PORTA.F4==1);                   // Start Program when Press RA4

  while(1)
  {
     ADC1 =Adc_Rd(0);                   // Reading Sensor from Left
     ADC2 =Adc_Rd(1);                   // Reading Sensor from Right
     if ((ADC1<300)&&(ADC2<300))        // Check Both Sensor Found White
     {
          if (First_Time!=0)            // Check First Time ?
          {
               First_Time=0;            // Change Status => Second_Time
               Cnt++;
//               Lcd_Cmd(LCD_CLEAR);      // Shcw ==> LCD
//               Lcd_Out(1,1,text5);
//               Lcd_Out(2,1,text0);
//               ByteToStr(Cnt,txt);      // Convert Counter to String
//               Lcd_Out(1,13,txt);       // Show Counter ==> LCD
               Sound_Play(250,100);     // Play Sound When Found Cross
               Forward(255);            // Running Robot
               Delay_ms(400);
          }
     }
     if ((ADC1>300)&&(ADC2>300))        // Check Both Sensor Found White
     {
          if (First_Time!=1)            // Check First Time ?
          {
               First_Time=1;            // Change Status => Second_Time
//               Lcd_Cmd(LCD_CLEAR);      // Shcw ==> LCD
//               Lcd_Out(1,1,text4);
//               Lcd_Out(2,1,text0);
               Forward(255);            // Running Robot
          }
     }
     if (ADC1<300)                      // Left Sensor Found Black
     {
          S_Left(255);                  // Turn Left
          if (First_Time!=2)
          {
               First_Time=2;             // Clear First Time Stutus
//               Lcd_Cmd(LCD_CLEAR);      // Show ==> LCD
//               Lcd_Out(1,1,text1);
//               Lcd_Out(2,1,text2);
          }
     }
     if (ADC2<300)                      // Right Sensor Found Black
     {
          S_Right(255);                 // Turn Right
          if (First_Time!=3)
          {
               First_Time=3;             // Clear First Time Status
//               Lcd_Cmd(LCD_CLEAR);       // Show ==> LCD
//              Lcd_Out(1,1,text1);
//              Lcd_Out(2,1,text3);
          }
     }
  }
}