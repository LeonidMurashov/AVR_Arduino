// Моторы подключаются к клеммам M1+,M1-,M2+,M2-  
// Motor shield использует четыре контакта 6,5,7,4 для управления моторами 
#define SPEED_LEFT       9
#define SPEED_RIGHT      10
#define MOT_EN 5 

#define DIR_LEFT         5

#define DIR_RIGHT        7

#define LEFT_SENSOR_PIN  2
#define RIGHT_SENSOR_PIN 6

 #define mot_dir(port, dir) \
     digitalWrite(port, dir); \
     digitalWrite(port+1, !dir);
      
// Скоростииииииь, с которой мы движемся вперёд (0-255)
#define SPEED           200
 
// Коэффициент, задающий во сколько раз нужно затормозить
// одно из колёс для поворота
#define BRAKE_K          2
 
#define STATE_FORWARD    0
#define STATE_RIGHT      1
#define STATE_LEFT       2
#define STATE_STOP       3 
int state = STATE_FORWARD;

void fullStop(){
  state = STATE_STOP;
  analogWrite(SPEED_LEFT, 0);
  analogWrite(SPEED_RIGHT, 0);
 
    // Если в DIR_LEFT или DIR_RIGHT пишем HIGH, мотор будет двигать соответствующее колесо
    // вперёд, если LOW - назад.
    mot_dir(DIR_LEFT, LOW);
    mot_dir(DIR_RIGHT, LOW );
}

void runForward() 
{
    state = STATE_FORWARD;
 
    // Для регулировки скорости `SPEED` может принимать значения от 0 до 255,
    // чем болше, тем быстрее. 
    analogWrite(SPEED_LEFT, SPEED);
    analogWrite(SPEED_RIGHT, SPEED);

 
    // Если в DIR_LEFT или DIR_RIGHT пишем HIGH, мотор будет двигать соответствующее колесо
    // вперёд, если LOW - назад.
    mot_dir(DIR_LEFT, LOW);
    mot_dir(DIR_RIGHT, LOW );
   
   
}
 
void steerRight() 
{
    state = STATE_RIGHT;
 
    // Замедляем правое колесо относительно левого,
    // чтобы начать поворот
    analogWrite(SPEED_RIGHT, SPEED / BRAKE_K);
    analogWrite(SPEED_LEFT, SPEED);
 
    mot_dir(DIR_LEFT, LOW);
    mot_dir(DIR_RIGHT, LOW);
    
}
 
void steerLeft() 
{
    state = STATE_LEFT;
 
    analogWrite(SPEED_LEFT, SPEED / BRAKE_K);
    analogWrite(SPEED_RIGHT, SPEED);
 
    mot_dir(DIR_LEFT, LOW);
    mot_dir(DIR_RIGHT, LOW);
}
 
 
void setup() 
{
    // Настраивает выводы платы 4,5,6,7 на вывод сигналов 
 Serial.begin(9600);
 pinMode(2, INPUT);
 pinMode(3, INPUT);
    for(int i = 5; i <= 10; i++)
        pinMode(i, OUTPUT);
  digitalWrite(MOT_EN, HIGH);
 
    // Сразу едем вперёд
    runForward(); 
   delay(50);

} 
 
void loop() 
{ 
    // Наш робот ездит по белому полю с чёрным треком. В обратном случае не нужно
    // инвертировать значения с датчиков 
    boolean left = !digitalRead(LEFT_SENSOR_PIN);
    boolean right = !digitalRead(RIGHT_SENSOR_PIN);
 
    // В какое состояние нужно перейти?
    int targetState;
 
    if (left == right && left == 1) {
        // под сенсорами всё белое или всё чёрное
        // едем вперёд
        targetState = STATE_FORWARD;
    } else if  (left == right){
       targetState = STATE_STOP;
    }else if (left) {
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
 
    switch (targetState) 
    {
        case STATE_FORWARD:
            runForward();
            break;
 
        case STATE_RIGHT:
            steerRight();
            break;
 
        case STATE_LEFT:
            steerLeft();
            break;
        case STATE_STOP:
            fullStop();
            break;
    }
 
    // не позволяем сильно вилять на прямой
    delay(5);
}
