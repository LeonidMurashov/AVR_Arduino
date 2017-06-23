#line 1 "E:/Work2007/MikroC/Code/A4-1/PWMTest01.c"
void main()
{

 ANSELH.F0=0;
 ANSELH.F2=0;
 TRISB.F1=0;
 TRISB.F2=0;
 TRISD.F0=0;
 TRISD.F1=0;


 Pwm1_Init(5000);
 Pwm2_Init(5000);


 Pwm1_Start();
 Pwm2_Start();
 Pwm1_Change_Duty(190);
 Pwm2_Change_Duty(190);


 while(1)
 {
 PORTD.F0 =0;PORTD.F1 =1;
 PORTB.F1 =0;PORTB.F2 =1;
 Delay_ms(2000);
 PORTB.F1 =1;PORTB.F2 =0;
 Delay_ms(800);
 }
}
