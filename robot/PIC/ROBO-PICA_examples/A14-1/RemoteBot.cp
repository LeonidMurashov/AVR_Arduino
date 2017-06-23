#line 1 "E:/Work2007/MikroC/Code/A14-1/RemoteBot.c"
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
#line 2 "E:/Work2007/MikroC/Code/A14-1/RemoteBot.c"
char *text = "ER-4 Remote";
unsigned char ir_cmd=0;



void interrupt()
{
 unsigned char i;
 if(INTCON.INTF)
 {
 Delay_us(416);
 for(i=0;i<8;i++)
 {
 Delay_us(833);
 ir_cmd = ir_cmd>>1;
 if((PORTB & 0x01)==1)
 ir_cmd = ir_cmd|0x80;
 }
 Delay_us(833);
 INTCON.INTF =0;
 }
}



unsigned char get_remote()
{
 unsigned char _key=ir_cmd;
 ir_cmd=0;
 return(_key);
}





void main()
{
 ANSELH.F4=0;
 OPTION_REG.INTEDG = 0;
 INTCON.INTE =1;
 INTCON.GIE =1;

 Lcd_Init(&PORTD);
 Lcd_Cmd(Lcd_CLEAR);
 Lcd_Cmd(Lcd_CURSOR_OFF);
 Lcd_Out(1, 1, text);
 Sound_Init(&PORTC,0);
 Sound_Play(2500,400);
 while(1)
 {
 char key=get_remote();
 if((key=='a')||(key=='A'))
 { Backward(255);Delay_ms(50); }
 else if((key=='b')||(key=='B'))
 { S_Right(255);Delay_ms(50); }
 else if((key=='c')||(key=='C'))
 { S_Left(255);Delay_ms(50); }
 else if((key=='d')||(key=='D'))
 { Forward(255);Delay_ms(50);}
 else Motor_Stop();
 }

 }
