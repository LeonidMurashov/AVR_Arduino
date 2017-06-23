void main()
{
/* Initial port for control motor */
    ANSELH=0x00 ;                       // Set PORTB => Digital
    TRISB.F1=0;TRISB.F2=0;              // Motor B 2A,Motor B 2B
    TRISD.F0=0;TRISD.F1=0;              // Motor A 1A,MOtor A 1B
    TRISC.F1=0;TRISC.F2=0;              // Motor B 2E,Motor A 1E
    PORTC.F1=1;PORTC.F2=1;              // Enable Motor B,Enable Motor A

/* Triangle running robot */
    while(1)
     {
          PORTD.F0 =0;PORTD.F1 =1;      // Motor A Forward
          PORTB.F1 =0;PORTB.F2 =1;      // Motor B Forward
          Delay_ms(2000);
          PORTB.F1 =1;PORTB.F2 =0;      // Motor B Backward
          Delay_ms(800);
     }
}
