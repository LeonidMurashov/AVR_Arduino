#include <motor.h>
char *text = "ER-4 Remote";   // Define message
unsigned char ir_cmd=0;       // Keep Command button from ER-4 Remote
//==================================================================//
//================== Interrupt service routine INT =================//
//==================================================================//
void interrupt()
{
  unsigned char i;                 // Keep counter
  if(INTCON.INTF)                  // Check interrupt flag RB0  (Falling edge)
  {
     Delay_us(416);                // Delay 1/2 of 1 bit timing(baudrate 1200 bps)
     for(i=0;i<8;i++)              // Loop for 8 time for keep data from ER-4 Remote
     {
       Delay_us(833);              // Delay of 1 bit timing(baudrate 1200 bps)
       ir_cmd = ir_cmd>>1;         // Shitt bit 1 time
       if((PORTB & 0x01)==1)       // Get logic @ RB0 = '1'?
          ir_cmd = ir_cmd|0x80;    // Inset bit data is '1'
      }
     Delay_us(833);                // Delay of 1 bit timing(baudrate 1200 bps)
     INTCON.INTF =0;               // Clear interrupt flag
  }
}
//==================================================================//
//================== Function for get character from Remote ========//
//==================================================================//
unsigned char get_remote()
{
   unsigned char _key=ir_cmd;      // Get character to buffer
   ir_cmd=0;                       // Clear old data
   return(_key);                   // Return character from Remote
}

//==================================================================//
//================== Main Program ==================================//
//==================================================================//

void main()
{
  ANSELH.F4=0;                // RB0 ==> Digital IO
  OPTION_REG.INTEDG = 0;      // INT falling edge
  INTCON.INTE =1;             // Enable INT/PB0
  INTCON.GIE =1;              // Enable Global interrupt

  Lcd_Init(&PORTD);           // Initialize LCD connected to PORTD
  Lcd_Cmd(Lcd_CLEAR);         // Clear display
  Lcd_Cmd(Lcd_CURSOR_OFF);    // Turn cursor off
  Lcd_Out(1, 1, text);        // Print text to LCD, 2nd row, 1st column
  Sound_Init(&PORTC,0);
  Sound_Play(2500,400);
  while(1)                                   // Infinite loop
  {
          char key=get_remote();                   // Get Remote
          if((key=='a')||(key=='A'))               // Button A press?
          { Backward(255);Delay_ms(50); }
          else if((key=='b')||(key=='B'))          // Button B press?
          { S_Right(255);Delay_ms(50);  }
          else if((key=='c')||(key=='C'))          // Button C press?
          { S_Left(255);Delay_ms(50);   }
          else if((key=='d')||(key=='D'))          // Button D press?
          { Forward(255);Delay_ms(50);}
          else Motor_Stop();
  }

 }