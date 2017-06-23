char motor_duty_= 127;            // Defalt PWM 50%
char motor_init_=0;               // Status initial

//  *** Motor A *****
//   PD0 ====>  1A
//   PD1 ====>  1B
//   PC2 ====>  1E (PWM1)

//  *** Motor B *****
//   PB1 ====>  2A
//   PB2 ====>  2B
//   PC1 ====>  2E (PWM2)

//****************************************************
//********** Initial Motor Function ******************
//****************************************************
void Motor_Init()
{
  if (motor_init_==0)            // First time ?
  {
    motor_init_=1;               // Status
    ANSELH.F0=0;                 // RB1 ==> Digital IO
    ANSELH.F2=0;                 // RB2 ==> Digital IO
    TRISB.F1=0;                  // Motor B 2A
    TRISB.F2=0;                  // Motor B 2B
    TRISD.F0=0;                  // Motor A 1A
    TRISD.F1=0;                  // MOtor A 1B
    Pwm1_Init(5000);             // Initail PWM 1E
    Pwm2_Init(5000);             // Initail PWM 2E
  }
}
//****************************************************

//****************************************************
//********** Control Duty Cycle  *********************
//****************************************************
void Change_Duty(char speed)
 {
  if (speed != motor_duty_)      // Check Same old speed
  {
   motor_duty_=speed;            // Save for old speed
   Pwm1_Change_Duty(speed);      // Motor A
   Pwm2_Change_Duty(speed);      // Motor B
   }
 }
//****************************************************

/********** Motor A Forward  ********/
void Motor_A_FWD()
{
  Pwm1_Start();
  PORTD.F0 =0;
  PORTD.F1 =1;
}
/************************************/

/********** Motor B Forward  ********/
void Motor_B_FWD()
{
  Pwm2_Start();
  PORTB.F1 =0;
  PORTB.F2 =1;
}
/************************************/

/********** Motor A Backward  *******/
void Motor_A_BWD()
{
  Pwm1_Start();
  PORTD.F0 =1;
  PORTD.F1 =0;
}
/************************************/

/********** Motor B Backward  *******/
void Motor_B_BWD()
{
  Pwm2_Start();
  PORTB.F1 =1;
  PORTB.F2 =0;
}
/************************************/

/********** Go Forward   ************/
void Forward(char speed)
{
    Motor_Init();
    Change_Duty(speed);
    Motor_A_FWD();
    Motor_B_FWD();
}
/************************************/

/********** Go Backward  ************/
void Backward(char speed)
{
    Motor_Init();
    Change_Duty(speed);
    Motor_A_BWD();
    Motor_B_BWD();
}
/************************************/

/********** Spin Left   *************/
void S_Right(char speed)
{
    Motor_Init();
    Change_Duty(speed);
    Motor_A_FWD();
    Motor_B_BWD();
}
/************************************/

/********** Spin Right   ************/
void S_Left(char speed)
{
    Motor_Init();
    Change_Duty(speed);
    Motor_A_BWD();
    Motor_B_FWD();
}
/************************************/
/********** Motor A Off  ************/
void Motor_A_Off()
{
  Pwm1_Stop();
  PORTD.F0 =0;
  PORTD.F1 =0;
}
/************************************/

/********** Motor B Off  ************/
void Motor_B_Off()
{
  Pwm2_Stop();
  PORTB.F1 =0;
  PORTB.F2 =0;
}
/************************************/

/********** Stop Motor   ************/
void Motor_Stop()
{
   Change_Duty(0);
//   Pwm1_Change_Duty(0);      // Motor A
//   Pwm2_Change_Duty(0);      // Motor B
    Motor_A_Off();
    Motor_B_Off();
    motor_init_=0;
    
}
/************************************/

