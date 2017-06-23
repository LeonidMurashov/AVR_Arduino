#line 1 "E:/Work2007/MikroC/Code/A5-1/Movement.c"
#line 1 "c:/program files/mikroelektronika/mikroc/include/motor.h"
char motor_duty_= 127;
char motor_init_=0;
#line 17 "c:/program files/mikroelektronika/mikroc/include/motor.h"
void Motor_Init()
{
 if (motor_init_==0)
 {
 motor_init_=1;
 ANSELH.F0=0;
 ANSELH.F2=0;
 TRISB.F1=0;
 TRISB.F2=0;
 TRISD.F0=0;
 TRISD.F1=0;
 Pwm1_Init(5000);
 Pwm2_Init(5000);
 }
}





void Change_Duty(char speed)
 {
 if (speed != motor_duty_)
 {
 motor_duty_=speed;
 Pwm1_Change_Duty(speed);
 Pwm2_Change_Duty(speed);
 }
 }



void Motor_A_FWD()
{
 Pwm1_Start();
 PORTD.F0 =0;
 PORTD.F1 =1;
}



void Motor_B_FWD()
{
 Pwm2_Start();
 PORTB.F1 =0;
 PORTB.F2 =1;
}



void Motor_A_BWD()
{
 Pwm1_Start();
 PORTD.F0 =1;
 PORTD.F1 =0;
}



void Motor_B_BWD()
{
 Pwm2_Start();
 PORTB.F1 =1;
 PORTB.F2 =0;
}



void Forward(char speed)
{
 Motor_Init();
 Change_Duty(speed);
 Motor_A_FWD();
 Motor_B_FWD();
}



void Backward(char speed)
{
 Motor_Init();
 Change_Duty(speed);
 Motor_A_BWD();
 Motor_B_BWD();
}



void S_Right(char speed)
{
 Motor_Init();
 Change_Duty(speed);
 Motor_A_FWD();
 Motor_B_BWD();
}



void S_Left(char speed)
{
 Motor_Init();
 Change_Duty(speed);
 Motor_A_BWD();
 Motor_B_FWD();
}


void Motor_A_Off()
{
 Pwm1_Stop();
 PORTD.F0 =0;
 PORTD.F1 =0;
}



void Motor_B_Off()
{
 Pwm2_Stop();
 PORTB.F1 =0;
 PORTB.F2 =0;
}



void Motor_Stop()
{
 Change_Duty(0);


 Motor_A_Off();
 Motor_B_Off();
 motor_init_=0;

}
#line 2 "E:/Work2007/MikroC/Code/A5-1/Movement.c"
void main()
{
 Sound_Init(&PORTC, 0);
 while(PORTA.F4==1);
 Sound_Play(2000,50);
 Forward(255);
 Delay_ms(2000);

 Sound_Play(2000,50);
 S_Left(255);
 Delay_ms(800);

 Sound_Play(2000,50);
 Forward(255);
 Delay_ms(2000);

 Sound_Play(2000,50);
 S_Right(255);
 Delay_ms(800);

 Sound_Play(2000,50);
 Forward(255);
 Delay_ms(2000);

 Sound_Play(2000,50);
 S_Left(255);
 Delay_ms(800);

 Sound_Play(2000,50);
 Backward(255);
 Delay_ms(1000);

 Sound_Play(2000,50);
 Motor_Stop();

}
