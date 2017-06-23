sbit LCD_RS at RD2_bit;
sbit LCD_EN at RD3_bit;
sbit LCD_D4 at RD4_bit;
sbit LCD_D5 at RD5_bit;
sbit LCD_D6 at RD6_bit;
sbit LCD_D7 at RD7_bit;

sbit LCD_RS_Direction at TRISD2_bit;
sbit LCD_EN_Direction at TRISD3_bit;
sbit LCD_D4_Direction at TRISD4_bit;
sbit LCD_D5_Direction at TRISD5_bit;
sbit LCD_D6_Direction at TRISD6_bit;
sbit LCD_D7_Direction at TRISD7_bit;

char *text = "000";
/*void Display_Input(int x,  int y, int z) {
  /*if (z<0) {
  text[0] =45;
  z=-z;
  }
  else   text[0] =32;

    
  if(z>999)z=999;
  
  text[0] = (z/100)%10    + 48;         // Extract tens digit
  text[1] = (z/10)%10     + 48;         // Extract ones digit
  text[2] =  z%10         + 48;         // Extract ones digit

 Lcd_Out(x,y,text);
}*/

int getFromSensor(int sensor)  // 0- left
{
  if(sensor==0)
    return (int)(ADC_READ(3)/3.95);
  else if(sensor==1)
    return (int)(ADC_READ(0)/6.72);       /// даёт 100% при белом, на нормальной высоте, при чёрном - меньше
}

 void Right(); void Left(); void Forward(); void Backward(); void Stop();

 int skan()
 {
       int us = 0;
       PORTA.F5 = 1;
       delay_us(10);
       PORTA.F5 = 0;
       while(!PORTC.F7);//{PORTB.F3 = 1;delay_ms(100);PORTB.F3 = 0; delay_ms(10);  }
       while(PORTC.F7 != 0){delay_us(5);us = us + 5;}


       if(us/58>0 && us/58<255){ return us/58;}
       else { return 255;}
 }
 void RotateR(int gr)
 {
 int i;
  Right();
  for(i = 0; i<gr; i++) delay_us(7590);
  Stop();
 }
/*  void RotateL(int gr)
 {
 int i;
  Left();
  for(i = 0; i<gr; i++) delay_us(7550);
  Stop();
 }  */
void main() {

    int i, adc, minw, maxw, tagw, s, dist=300;
    int last0 = 0, last1 = 0;
    int lastvec = 0;
    
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off

  
  TRISA  = 0xFF;                   // PORTA ==> input
  ANSEL = 0xFF;                    // PORTA ==> Analog
  ANSELH = 0x00 ;                       // Set PORTB => Digital
  TRISC.F7 = 1;
  TRISA.F5 = 0; //вход
 
     /* Initial port for control motor */

    TRISB.F1=0;TRISB.F2=0;              // Motor B 2A,Motor B 2B
    TRISD.F0=0;TRISD.F1=0;              // Motor A 1A,MOtor A 1B
    TRISC.F1=0;TRISC.F2=0;              // Motor B 2E,Motor A 1E


  Sound_Init(&PORTC,0);
  Stop();
  
  
  
   while(PORTA.f4);
   delay_ms(500);
   sound_play(500,500);
   /*
  while(1)   // >80 - белый  <60 -чёрный
  {

      if(!PORTA.F4){Stop();break;}
  }*/



  Forward();
  while(skan()>4)
  {
   if(getFromSensor(0)>=80 && getFromSensor(1)>=80)      // при обоих белых
   {
    Forward();
   }
      else if(getFromSensor(0)>=80 && getFromSensor(1)<=60) // линия на правом
   {
     Right();
   }
   else if(getFromSensor(0)<=60 && getFromSensor(1)>=80) // линия на левом
   {
     Left();
   }
   else                                                // оба на линии
   {
     Forward();
   }
     delay_ms(50);
     Forward();
     delay_ms(100);

  }
  Stop();
  RotateR(540);
  Forward();
  while(skan()>3);


  Stop();

  //Forward();

/* Triangle running robot */

          //PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
          //PORTD.F0 =1;PORTD.F1 =0;      // left backward
          //PORTD.F0 =0;PORTD.F1 =1;      // left forward
          //PORTB.F1 =1;PORTB.F2 =0;      // right backward
          //PORTB.F1 =0;PORTB.F2 =1;      // right forward
          //PORTC.F1 =0;PORTC.F2 =0;      //deinit

         
          

         //  PORTD.F0 =1;PORTD.F1 =1//acts right f
         //PORTD.F0 =0;PORTD.F1 =0; // acts right f

  /*  while(1)
  {

     Lcd_Out(1,1,"Sensor1 says:");            // Show on LCD
     Display_Input(1, 14, getFromSensor(0)); // left
     
     Lcd_Out(2,1,"Sensor2 says:");            // Show on LCD
     Display_Input(2, 14, getFromSensor(1));  //right
  }  */
}

void Right()
{
     PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
     PORTD.F0 =0;PORTD.F1 =1;      // left forward
     PORTB.F1 =1;PORTB.F2 =0;      // right backward
}
void Left()
{
     PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
     PORTB.F1 =0;PORTB.F2 =1;      // right forward
     PORTD.F0 =1;PORTD.F1 =0;      // left backward
}
void Forward()
{
     PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
     PORTB.F1 =0;PORTB.F2 =1;      // right forward
     PORTD.F0 =0;PORTD.F1 =1;      // left forward
}
void Backward()
{
     PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
     PORTD.F0 =1;PORTD.F1 =0;      // left backward
     PORTB.F1 =1;PORTB.F2 =0;      // right backward
}
void Stop()
{
     PORTC.F1 =0;PORTC.F2 =0;      //deinit
}