#line 1 "E:/Work2007/MikroC/Code/A10-1/SurveyBot.c"
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
#line 6 "E:/Work2007/MikroC/Code/A10-1/SurveyBot.c"
char *text1 = "Edge of a table" ;
char *text2 = "From Left";
char *text3 = "From Right";
char *text4 = "Let'Go" ;
char *text5 = "Route Clear";

char flag=0;
int ADC=0;
void main()
{
 Lcd_Init(&PORTD);
 Lcd_Cmd(LCD_CURSOR_OFF);
 Lcd_Cmd(LCD_CLEAR);

 Lcd_Out(1,1, "<< RA4 >> Start");
 while(PORTA.F4==1);

 while(1)
 {
 ADC =Adc_Rd(0);
 if (ADC<100)
 {
 flag=0;
 Backward(255);
 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1,text1);
 Lcd_Out(2,1,text2);
 Delay_ms(400);
 S_Right(255);
 Delay_ms(600);
 }
 ADC =Adc_Rd(1);
 if (ADC<100)
 {
 flag=0;
 Backward(255);
 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1,text1);
 Lcd_Out(2,1,text3);
 Delay_ms(400);
 S_Left(255);
 Delay_ms(900);
 }
 forward(255);
 if (flag==0)
 {
 flag=1;
 Lcd_Cmd(LCD_CLEAR);
 Lcd_Out(1,1,text4);
 Lcd_Out(2,1,text5);
 }
 }

}
