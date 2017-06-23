void interrupt()                             // Interrupt Service routine
{
     Sound_Play(2000,200);                    // Show Sound
     INTCON.INTF=0;                          // Clear Flag Interrupt
}
void main()
{
/********************************************/
     ANSELH.F4=0;                            // RB0 ==> Digital IO
     OPTION_REG.INTEDG = 0;                  // INT falling edge
     INTCON.INTE =1;                         // Enable INT/PB0
     INTCON.GIE =1;                          // Enable Global interrupt
/********************************************/
     TRISB.F3=0;
     Sound_Init(&PORTC,0);                   // Init Sound ==> RC0
     Lcd_Init(&PORTD);                       // Init LCD PORT D
     Lcd_Cmd(LCD_CURSOR_OFF);                // LCD cursor off
     Lcd_Cmd(LCD_CLEAR);
     Lcd_Out(1,1, "<< RA4 >> Start");
     Lcd_Out(2,1,"Test Interrupt");
     while(PORTA.F4==1);                     // Start Program when Press RA4
/********************************************/
     Lcd_Cmd(LCD_CLEAR);
     Lcd_Out(1,1, "Start Program");          // Main Program
     while(1)
     {
          PORTB.F3=1;                        // Blinking LED
          Delay_ms(500);
          PORTB.F3=0;
          Delay_ms(500);
     }
}