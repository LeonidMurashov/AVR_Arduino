char *text1 = "ER-4 Remote";       // Define message
unsigned char ir_cmd=0;            // Keep Command button from ER-4 Remote
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
          ir_cmd = ir_cmd | 0x80;  // Inset bit data is '1'
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
  unsigned char key;               // Save Remote Key Press
  ANSELH.F4=0;                     // RB0 ==> Digital IO
  OPTION_REG.INTEDG = 0;           // INT falling edge
  INTCON.INTE =1;                  // Enable INT/PB0
  INTCON.GIE =1;                   // Enable Global interrupt

  Lcd_Init(&PORTD);                // Initialize LCD connected to PORTD
  Lcd_Cmd(Lcd_CLEAR);              // Clear display
  Lcd_Cmd(Lcd_CURSOR_OFF);         // Turn cursor off
  Lcd_Out(1, 1, text1);            // Print text to LCD, 2nd row, 1st column
  Sound_Init(&PORTC,0);
  while(1)                                   // Infinite loop
  {
      key = get_remote();                    // Get Remote
      if(key=='a' || key=='A')               // Button A press?
      {
         Lcd_Out(2, 1, "Button A Press  ");  // Display message Button B press
         Sound_Play(2000,200);
      }
      else if(key=='b' || key=='B')          // Button B press?
      {
         Lcd_Out(2, 1, "Button B Press  ");  // Display message Button B press
         Sound_Play(2500,200);
      }
      else if(key=='c' || key=='C')          // Button C press?
      {
         Lcd_Out(2, 1, "Button C Press  ");  // Display message Button C press
         Sound_Play(2900,200);
      }
      else if(key=='d' || key=='D')          // Button D press?
      {
         Lcd_Out(2, 1, "Button D Press  ");  // Display message Button D press
         Sound_Play(3200,200);
      }
  }








 }