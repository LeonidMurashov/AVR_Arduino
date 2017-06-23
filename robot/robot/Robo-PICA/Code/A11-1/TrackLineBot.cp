#line 1 "E:/Work2007/MikroC/Code/A11-1/TrackLineBot.c"
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
#line 1 "c:/program files/mikroelektronika/mikroc/include/adc.h"
int Adc_Rd(char ch)
{
 int dat=0;
 if ((ch>=0) && (ch<=3))
 TRISA |= (1<<ch);
 else if (ch==4)
 TRISA |= 0x20;
 else if ((ch>=5) && (ch<=7))
 TRISE |= (1<<(ch-5));
 ANSEL |=(1<<ch);
 ADCON0 = (0xC1 + (ch*4));
 Delay_us(10);
 ADCON0.GO=1;
 while(ADCON0.GO);
 dat = (ADRESH*4)+(ADRESL/64);
 return dat;
}
#line 13 "E:/Work2007/MikroC/Code/A11-1/TrackLineBot.c"
char Cnt=0;
char txt[4];
char First_Time=5;
int ADC1=0,ADC2=0;
void main()
{





 Sound_Init(&PORTC,0);



 while(PORTA.F4==1);

 while(1)
 {
 ADC1 =Adc_Rd(0);
 ADC2 =Adc_Rd(1);
 if ((ADC1<300)&&(ADC2<300))
 {
 if (First_Time!=0)
 {
 First_Time=0;
 Cnt++;





 Sound_Play(250,100);
 Forward(255);
 Delay_ms(400);
 }
 }
 if ((ADC1>300)&&(ADC2>300))
 {
 if (First_Time!=1)
 {
 First_Time=1;



 Forward(255);
 }
 }
 if (ADC1<300)
 {
 S_Left(255);
 if (First_Time!=2)
 {
 First_Time=2;



 }
 }
 if (ADC2<300)
 {
 S_Right(255);
 if (First_Time!=3)
 {
 First_Time=3;



 }
 }
 }
}
