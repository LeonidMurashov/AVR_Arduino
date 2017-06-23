#include <motor.h>
void main()
{
     Sound_Init(&PORTC, 0);        // Init Sound
     while(PORTA.F4==1);
     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     Forward(255);                 // Call Forward
     Delay_ms(2000);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     S_Left(255);                  // Call Spin Left
     Delay_ms(800);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     Forward(255);                 // Call Forward
     Delay_ms(2000);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     S_Right(255);                 // Call Spin Right
     Delay_ms(800);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     Forward(255);                 // Call Forward
     Delay_ms(2000);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     S_Left(255);                  // Call Spin Left
     Delay_ms(800);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     Backward(255);                // Call Backward
     Delay_ms(1000);

     Sound_Play(2000,50);           // 2 kHz sound ON RC0
     Motor_Stop();                 // Stop all

}