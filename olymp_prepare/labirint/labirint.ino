#include "queue.h"
#include "vector.h"
#include "motors.h"
#include <Ultrasonic.h>

byte line[] = {A15, A14, A13, A12},
     trigs[]={22,26,28,24},
     echos[]={23,27,29,25};

volatile int speed_left, speed_right;

/// Forwarding
bool forwarding = 0;
byte forwarding_speed;
///

/// ADS module
volatile long long last_time_left = 0, last_time_right = 0, iterator=0;
volatile int delta_left = 0, delta_right = 0;
///

Ultrasonic ultrasonic[] = {
                           Ultrasonic(trigs[0], echos[0]),
                           Ultrasonic(trigs[1], echos[1]),
                           Ultrasonic(trigs[2], echos[2]),
                           Ultrasonic(trigs[3], echos[3])    
};

class Vec4
{
  byte v[4];
  public:

  Vec4(){};
  
  Vec4(byte a,byte b,byte c,byte d)
  {
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
  }
  byte &operator[](byte i)
  {
    return v[i];
  }  

  bool operator!=(Vec4 a)
  {
    for(int i = 0; i < 4; i++)
      if(a[i] != v[i])
        return true;
    return false;
  }

  void print()
  {
    for(int i = 0; i < 4; i++)
    {
      Serial.print(v[i]);
      Serial.print(" ");
    }
    Serial.println();
  }
};

class Vertex
{
  public:
  byte number;

  Vec4 roads, features;

  Vertex(byte _number, Vec4 _roads, Vec4 _features)
  {
      number = _number;
      roads = _roads;
      features = _features;
  }

  byte get_direction(byte t)
  {
    for(int i = 0; i < 4; i++)
      if(roads[i]==t)
        return i;
    return 4;
  }
};

Vertex verts[]={
    Vertex(0, Vec4(0,0,0,0), Vec4(0,0,0,0)),
    Vertex(1, Vec4(16,0,2,0), Vec4(0,0,0,1)),
    Vertex(2, Vec4(1,0,0,3), Vec4(0,0,1,0)),
    Vertex(3, Vec4(0,0,1,8), Vec4(0,0,0,0)),
    Vertex(4, Vec4(5,3,10,15), Vec4(0,0,0,0)),
    Vertex(5, Vec4(6,0,4,0), Vec4(0,1,0,0)),
    Vertex(6, Vec4(7,0,5,0), Vec4(0,1,0,1)),
    Vertex(7, Vec4(0,8,6,0), Vec4(0,0,0,1)),
    Vertex(8, Vec4(0,16,0,7), Vec4(0,0,1,0)),
    Vertex(9, Vec4(3,0,0,10), Vec4(0,1,0,0)),
    Vertex(10, Vec4(4,9,0,0), Vec4(0,0,0,1)),
    Vertex(11, Vec4(12,15,0,0), Vec4(0,0,1,0)),
    Vertex(12, Vec4(13,0,11,0), Vec4(0,0,0,0)),
    Vertex(13, Vec4(0,0,12,0), Vec4(1,1,0,0)),
    Vertex(14, Vec4(0,0,0,0), Vec4(0,0,0,0)),
    Vertex(15, Vec4(0,4,0,11), Vec4(1,0,1,0)),
    Vertex(16, Vec4(0,0,1,8), Vec4(0,0,0,0)),
  };

byte position = 16,
     target = 12,
     direction = 3;

void setup() 
{
    /////////////////////////////////////////////
  // initialize timer1
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  OCR1A = 30; // ~ 1KHz            // compare match register 16MHz/256/2Hz
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12);    // 256 prescaler
  TIMSK1 |= (1 << OCIE1A);  // enable timer compare interrupt
  interrupts();             // enable all interrupts
  ////////////////////////////////////////////////////////////
  
  Serial.begin(9600);
  for (int i = 0; i < 4; i++)
    pinMode(line[i], INPUT);
  for(int i = 0; i < 4; i++)
  {
    pinMode(trigs[i], OUTPUT);
    pinMode(echos[i], INPUT);
  }
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(encoder_left, INPUT);
  pinMode(encoder_right, INPUT);
  Serial.println("begin");
  digitalWrite(led, HIGH);
  delay(20);
  digitalWrite(led, LOW);


  while (digitalRead(button) && !Serial.available());
  Serial.read();

  while(true)
  {
    forward();
    while(get_distance(3) > 30)
    {
      control_falling();
      delay(20);
    }
    while(get_distance(3) < 30)
    {
      Serial.println(get_distance(3));
      control_falling();   
      delay(20);   
    }
    stop();
    do_steps(25,25);
    Serial.println("Time to turn");
    turn_left();
    Serial.println("Turn complete");
    stop();
  }
  
  while(!true)
  {
    Serial.print(delta_left);
    Serial.print(" ");
    Serial.println(delta_right);
    delay(100);
  }
  while(!true)
  {
    int left = analogRead(line[0]), right = analogRead(line[2]);  
    Serial.print(left);
    Serial.print(" ");
    Serial.println(right);
  }

  while (digitalRead(button) && !Serial.available());
  Serial.read();
  
  Vector v = get_path(position, target);
  for(int i = 0; i < v.get_size(); i++)
  {
    Serial.print("State ");
    Serial.println(position);
    byte d = verts[position].get_direction(v[i]);
    if(d != direction)
    {
      if(d - direction == 1)
        turn_right();
      else if(direction - d == 1)
        turn_left();
      else
      {
        turn_right();
        turn_right();
      }
      direction = d;
    }
    Vec4 states;
    bool no_emergency;
    forward();
    do
    {
      no_emergency = get_distance(0) > 5;
      states = Vec4(get_distance(0) < 20, get_distance(1) < 20,
                    get_distance(2) < 20, get_distance(3) < 20);
      states = rotate_states(states, direction);
      //Serial.print("Need ");
      //verts[v[i]].features.print();
      //Serial.print("Is ");
      //states.print();
    }
    while(states!=verts[v[i]].features && no_emergency);
    while(no_emergency)
    {
      no_emergency = get_distance(0) > 5;
    }
    stop();
    position = v[i];
  }
  Serial.println("finish");
}

void control_falling()
{
  if(analogRead(line[0]) > 150 || analogRead(line[3]) > 150)
  {
    Serial.println("We are falling!");
    forwarding = 0;
    do_steps(-5-10*(analogRead(line[0]) > 100), -5-10*(analogRead(line[3]) > 100));
    forward();  
  }
}

Vec4 rotate_states(Vec4 states, byte direction)
{
  Vec4 v(0,0,0,0);
  for(int i = 0; i < 4; i++)
  {
    v[i] = states[(4+int(i)-int(direction))%4];
  }
  return v;
}

#define SPEED 10

ISR(TIMER1_COMPA_vect)
{
  iterator++;
  if (digitalRead(encoder_left) != encoder_left_state)
  {
    rots_left += 1;
    encoder_left_state ^= 1;
    if(encoder_left_state)
    {
      speed_left = int(1/((double(millis()-last_time_left))/(double)1000));
      last_time_left = millis();
    }
  }
  if (digitalRead(encoder_right) != encoder_right_state)
  {
    rots_right += 1;
    encoder_right_state ^= 1;
    if(encoder_right_state)
    {
      speed_right = int(1/((double(millis()-last_time_right))/(double)1000));
      last_time_right = millis();
    }
  }

  // Speed measurement
  if(iterator%250==0)
  {
    if(millis() - last_time_left > 200)
      speed_left = 0;
    if(millis() - last_time_right > 200)
      speed_right = 0;
  }

  // ADS module
  if(iterator%50==0)
  {
    const byte increment = 1, gist = 2;
    if(speed_left < SPEED-gist)
      delta_left+=increment;
    else if(speed_left > SPEED+gist)
      delta_left-=increment;
    if(speed_right < SPEED-gist)
      delta_right+=increment;
    else if(speed_right > SPEED+gist)
      delta_right-=increment;
  }

  // forwarding module  
  if(forwarding)
  {
    motor_left.setSpeed(max(0,forwarding_speed - 5*(rots_left-rots_right) + delta_left));
    motor_right.setSpeed(max(0,forwarding_speed + 5*(rots_left-rots_right) + delta_right));
  }
}

Vector get_path(byte p, byte t)
{
  bool was[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  byte prev[17];
  Queue q;
  q.add(p);
  int pos;
  do
  {
    pos = q.get();
    was[pos] = 1;
    for(int i = 0; i < 4; i++)
    {
      if(verts[pos].roads[i] != 0 && was[verts[pos].roads[i]]==0)
      {
        q.add(verts[pos].roads[i]);
        prev[verts[pos].roads[i]] = pos;     
      }
    }
  }
  while(pos != t && pos!=0);

  /*for(int i = 0; i < 17; i++)
  {
    Serial.print(" ");
    Serial.print(prev[i]);
  }*/

  Vector path;
  byte curr = t;
  do
  {
   // Serial.println(curr);
    path.push_front(curr);
    curr = prev[curr];
  }
  while(curr != p);

  return path;
}

int get_distance(byte n)
{
  int sum = 0;
  for(int i = 0; i < 3; i++)
  {
    int a = ultrasonic[n].distanceRead(); 
    sum += a ? a : 255;
    delay(30);
  }

  return sum;
}

void turn_right()
{
  do_steps(right_angle_steps, -right_angle_steps);
}

void turn_left()
{  
  do_steps(-right_angle_steps, right_angle_steps);
}

void forward()
{
  stop();
  forwarding_speed = 20;
  motor_right.run(FORWARD);
  motor_left.run(FORWARD);
  motor_right.setSpeed(forwarding_speed);
  motor_left.setSpeed(forwarding_speed);
  rots_left = 0;
  rots_right = 0;
  forwarding = true;
}

void stop()
{
  forwarding = false;
  delta_left = 0;
  delta_right = 0;
  rots_left = 0;
  rots_right = 0;
  motor_right.run(RELEASE);
  motor_left.run(RELEASE);
}
void loop()
{
}

