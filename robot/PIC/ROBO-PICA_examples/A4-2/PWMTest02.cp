#line 1 "E:/Work2007/MikroC/Code/A4-2/PWMTest02.c"
void main()
{

 ANSELH=0x00;
 TRISB.F1=0;
 TRISB.F2=0;
 TRISD.F0=0;
 TRISD.F1=0;


 Pwm1_Init(5000);
 Pwm2_Init(5000);


 Pwm1_Start();
 Pwm2_Start();
 Pwm1_Change_Duty(255);
 Pwm2_Change_Duty(220);
 while(PORTB.F0==1);

 PORTD.F0 =0;PORTD.F1 =1;
 PORTB.F1 =0;PORTB.F2 =1;
}
