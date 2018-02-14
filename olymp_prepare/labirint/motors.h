#include <AFMotor.h>

AF_DCMotor motor_left(4);
AF_DCMotor motor_claw(3);
AF_DCMotor motor_right(2);

byte button = 15,
     led = 53,
     encoder_left = 19,
     encoder_right = 20,
     right_angle_steps = 20,
     speed = 100;
bool encoder_left_state = 0,
     encoder_right_state = 0;
volatile int rots_left = 0,
             rots_right = 0;
int err_left=0, err_right=0;

void do_steps(int steps_left, int steps_right, bool blocking=true)
{
  int rots_left_prev = rots_left,
      rots_right_prev = rots_right;

  bool left_fwd = 1,
       right_fwd = 1;

  if (steps_left > 0)
    motor_left.run(FORWARD);
  else
  {
    steps_left *= -1;
    motor_left.run(BACKWARD);
    left_fwd = 0;
  }
  if (steps_right > 0)
    motor_right.run(FORWARD);
  else
  {
    steps_right *= -1;
    motor_right.run(BACKWARD);
    right_fwd = 0;
  }

  bool left_not_done, right_not_done;
  int i = 0;
  do
  {
    int left_remain = rots_left_prev + steps_left - err_left - rots_left,
        right_remain = rots_right_prev + steps_right - err_right - rots_right;
    left_not_done = left_remain > 2;
    right_not_done = right_remain > 2;
    if (left_not_done)
      motor_left.setSpeed(speed);
    else
    {
      if(blocking)
      {
        motor_left.setSpeed(255);
        motor_left.run(i%2 ? BACKWARD : FORWARD);
      }
      else
        motor_left.setSpeed(0);
    }
    if (right_not_done)
      motor_right.setSpeed(speed);
    else
    {
      if(blocking)
      {
        motor_right.setSpeed(255);
        motor_right.run(i%2 ? BACKWARD : FORWARD);
      }
      else
        motor_right.setSpeed(0);
    }
    i+=1;
    delay(9);
  }
  while (left_not_done || right_not_done);
  //delay(500);
  err_left = (rots_right_prev + steps_right - err_left - rots_right)/2;
  err_right = (rots_left_prev + steps_left - err_right - rots_left)/2;
  motor_right.run(RELEASE);
  motor_left.run(RELEASE);
}

