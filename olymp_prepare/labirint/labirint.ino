#include "queue.h"
#include "vector.h"
#include "motors.h"
#include <Ultrasonic.h>

byte line[] = {A15, A14, A13, A12},
     trigs[]={22,26,28,24},
     echos[]={23,27,29,25};

/// Forwarding
bool forwarding = 0;
byte forwarding_speed;
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

  forward(80);
  while(true)
  {
    control_falling();
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
    forward(70);
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
  if(analogRead(line[0]) > 100 || analogRead(line[3]) > 100)
  {
    forwarding = 0;
    do_steps(-10-20*(analogRead(line[0]) > 100), -10-20*(analogRead(line[3]) > 100));
    rots_left = 0;
    rots_right = 0;
    //forwarding = 1;
    //motor_right.run(FORWARD);
    //motor_left.run(FORWARD);
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

ISR(TIMER1_COMPA_vect)
{
  if (digitalRead(encoder_left) != encoder_left_state)
  {
    rots_left += 1;
    encoder_left_state ^= 1;
  }
  if (digitalRead(encoder_right) != encoder_right_state)
  {
    rots_right += 1;
    encoder_right_state ^= 1;
  }

  // forwarding module  
  if(forwarding)
  {
    motor_left.setSpeed(forwarding_speed - 5*(rots_left-rots_right));
    motor_right.setSpeed(forwarding_speed + 5*(rots_left-rots_right));
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
  delay(30);
  int d = ultrasonic[n].distanceRead();
  return d ? d : 255;
}

void turn_right()
{
  do_steps(right_angle_steps, -right_angle_steps);
}

void turn_left()
{  
  do_steps(-right_angle_steps, right_angle_steps);
}

void forward(int speed)
{
  forwarding_speed = speed;
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
  motor_right.run(RELEASE);
  motor_left.run(RELEASE);
}
void loop()
{
}

