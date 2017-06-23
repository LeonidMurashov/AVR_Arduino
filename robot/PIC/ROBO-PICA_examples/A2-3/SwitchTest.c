void main()
{
     ANSELH.F4=0;                 // RA4 ==> Digital IO
     TRISB.F3=0;                  // RB3 ==> Digital Output
     while(1)                     // Infinite Loop
     {
          if(PORTB.F0==0)         // Check RB0 Press ?
          {
               PORTB.F3=1;        // ON ==> RB3
          }
          if(PORTA.F4==0)         // Check RA4 Press ?
          {
               PORTB.F3=0;        // OFF ==> RB3
          }
     }
}