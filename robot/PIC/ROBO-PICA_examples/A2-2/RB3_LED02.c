void main()
{
     TRISB.F3=0;              // RB3==> Output
     while(1)                 // Infinite Loop
     {
          PORTB.F3=1;         // "1" ==> RB3
          Delay_ms(500);      // Delay
          PORTB.F3=0;         // "0" ==> RB3
          Delay_ms(500);      // Delay
     }
}