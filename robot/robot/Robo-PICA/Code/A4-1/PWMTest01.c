void main()
{
/* Initial port for control motor */
    ANSELH.F0=0;                        // RB1 ==> Digital IO
    ANSELH.F2=0;                        // RB2 ==> Digital IO
    TRISB.F1=0;                         // Motor M-2 2A
    TRISB.F2=0;                         // Motor M-2 2B
    TRISD.F0=0;                         // Motor M-1 1A
    TRISD.F1=0;                         // MOtor M-1 1B

/* Initial PWM module freq = 5 kHz */
    Pwm1_Init(5000);                    // Initail PWM 1E
    Pwm2_Init(5000);                    // Initail PWM 2E

/* Start PWM and set duty cycle 100% */
    Pwm1_Start();
    Pwm2_Start();
    Pwm1_Change_Duty(190);              // Motor M-1 75% Speed
    Pwm2_Change_Duty(190);              // Motor M-2 75% Speed

/* Triangle running robot */
    while(1)
     {
          PORTD.F0 =0;PORTD.F1 =1;      // Motor M-1 Forward
          PORTB.F1 =0;PORTB.F2 =1;      // Motor M-2 Forward
          Delay_ms(2000);
          PORTB.F1 =1;PORTB.F2 =0;      // Motor M-2 Backward
          Delay_ms(800);
     }
}
