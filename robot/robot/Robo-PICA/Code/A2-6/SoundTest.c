void main()
{
     Sound_Init(&PORTC, 0);           // Init Sound
     while(1)
     {
          if (!PORTA.F4)              // Test RA4 keypress
          sound_play(2000,100);       // 2 kHz sound ON RC0 at 100 ms
     }
}
