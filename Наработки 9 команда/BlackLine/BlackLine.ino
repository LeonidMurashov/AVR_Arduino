// Моторы подключаются к клеммам M1+,M1-,M2+,M2-  
// Motor shield использует четыре контакта 6,5,7,4 для управления моторами 
#define LEFT_FWD 5
#define LEFT_BWD 6
#define RIGHT_FWD 7
#define RIGHT_BWD 8
#define LEFT_SPEED 9
#define RIGHT_SPEED 10

#define LEFT_SENSOR_PIN  2
#define RIGHT_SENSOR_PIN 3

// Start btn
#define START_BTN 3
 
// Скорость, с которой мы движемся вперёд (0-255)
#define SPEED            200
 
// Коэффициент, задающий во сколько раз нужно затормозить
// одно из колёс для поворота
#define BRAKE_K          4
 
#define STATE_FORWARD    0
#define STATE_RIGHT      1
#define STATE_LEFT       2
 
#define RELE1 0
#define RELE2 1

int state = STATE_FORWARD;

void Stop()
{  
    digitalWrite(LEFT_BWD, LOW);
    digitalWrite(RIGHT_BWD, LOW);
    digitalWrite(LEFT_FWD, LOW);
    digitalWrite(RIGHT_FWD, LOW);

    analogWrite(RIGHT_SPEED, 0);
    analogWrite(LEFT_SPEED, 0);
}
 
void runForward() 
{
    state = STATE_FORWARD;
 
    // Для регулировки скорости `SPEED` может принимать значения от 0 до 255,
    // чем болше, тем быстрее. 
    analogWrite(LEFT_SPEED, SPEED);
    analogWrite(RIGHT_SPEED, SPEED);
 
    // Если в DIR_LEFT или DIR_RIGHT пишем HIGH, мотор будет двигать соответствующее колесо
    // вперёд, если LOW - назад.
    digitalWrite(LEFT_FWD, HIGH);
    digitalWrite(RIGHT_FWD, HIGH);
    digitalWrite(LEFT_BWD, LOW);
    digitalWrite(RIGHT_BWD, LOW);
    
}
 
void steerRight() 
{
    state = STATE_RIGHT;
 
    // Замедляем правое колесо относительно левого,
    // чтобы начать поворот
    analogWrite(RIGHT_SPEED, SPEED / BRAKE_K);
    analogWrite(LEFT_SPEED, SPEED);
     
    digitalWrite(LEFT_FWD, HIGH);
    digitalWrite(RIGHT_FWD, HIGH);
    digitalWrite(LEFT_BWD, LOW);
    digitalWrite(RIGHT_BWD, LOW);
}
 
void steerLeft() 
{
    state = STATE_LEFT;
 
    analogWrite(LEFT_SPEED, SPEED / BRAKE_K);
    analogWrite(RIGHT_SPEED, SPEED);
 
    digitalWrite(LEFT_FWD, HIGH);
    digitalWrite(RIGHT_FWD, HIGH);
    digitalWrite(LEFT_BWD, LOW);
    digitalWrite(RIGHT_BWD, LOW);
}

 void TurnOff();
 
void setup() 
{
  // Init motor pins
    for(int i = 0; i<5; i++)
      pinMode(i + 5, OUTPUT);       
 
  delay(250);

  pinMode(RIGHT_SENSOR_PIN, INPUT);
  pinMode(LEFT_SENSOR_PIN, INPUT);

  pinMode(3, INPUT_PULLUP);
  // Start on btn on
  while(digitalRead(START_BTN));

delay(250);


  digitalWrite(RELE1, HIGH);
  digitalWrite(RELE2, HIGH);
  
  runForward();
  
} 

 void TurnOff() 
 {
  
  setup();
 }
 
void loop() 
{ 
  
  
    // Наш робот ездит по белому полю с чёрным треком. В обратном случае не нужно
    // инвертировать значения с датчиков
    boolean left = !digitalRead(LEFT_SENSOR_PIN);
    boolean right = !digitalRead(RIGHT_SENSOR_PIN);
 
    // В какое состояние нужно перейти?
    int targetState;
 
    if (left == right) {
        // под сенсорами всё белое или всё чёрное
        // едем вперёд
        targetState = STATE_FORWARD;
    } else if (left) {
        // левый сенсор упёрся в трек
        // поворачиваем налево
        targetState = STATE_LEFT;
    } else {
        targetState = STATE_RIGHT;
    }
 
    if (state == targetState) {
        // мы уже делаём всё что нужно,
        // делаем измерения заново
        return;
    }
 
    switch (targetState) {
        case STATE_FORWARD:
            runForward();
            break;
 
        case STATE_RIGHT:
            steerRight();
            break;
 
        case STATE_LEFT:
            steerLeft();
            break;
    }
 
    // не позволяем сильно вилять на прямой
    delay(20);
}



/*
void setup()
{
    for(int i = 0; i<4; i++)
    pinMode(i+4, OUTPUT);  
}

void loop()
{
  for(int i = 0; i<4; i++)
  {
    digitalWrite(i+4, HIGH);
    delay(500);
  }

    for(int i = 0; i<4; i++)
  {
    analogWrite(i+4, 128);
    delay(500);
  }

  
}*/

/*#include <MotorDriver.h>

#define LINE_1 A8
#define LINE_2 52
#define SENSITIVITY 0.5

void setup()
{
  pinMode(LINE_1, OUTPUT);
  pinMode(LINE_2, OUTPUT);

    
}

void loop()
{
  int d1 = analogRead(LINE_1);
  int d2 = analogRead(LINE_2);

  int motorRight = 100 + (d1 - d2)* SENSITIVITY;
  int motorLeft = 100 - (d1 - d2)*SENSITIVITY;
  
  
}*/

/*
#define LED 9
void setup()
{
  pinMode(LED, OUTPUT);
  
}

void loop()
{

  while(true)
  {
    digitalWrite(LED, HIGH);
    delay(1000);

    digitalWrite(LED, LOW);
    delay(1000);
  }
}*/






