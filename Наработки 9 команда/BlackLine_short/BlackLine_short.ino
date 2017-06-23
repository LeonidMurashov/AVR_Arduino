#define LEFT_DIR 6
#define RIGHT_DIR 8

#define LEFT_SPEED 9
#define RIGHT_SPEED 10

#define SPEED 200

// Start btn
#define START_BTN 3
#define LEFT_FWD 5
#define RIGHT_FWD 7

#define RELE1 0
#define RELE2 1

void setup() {
  // put your setup code here, to run once:
  pinMode(LEFT_DIR, OUTPUT);
  pinMode(RIGHT_DIR, OUTPUT);
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
  pinMode(LEFT_FWD, OUTPUT);
  pinMode(RIGHT_FWD, OUTPUT);

  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  
  pinMode(3, INPUT_PULLUP);
  // Start on btn on
 // while(digitalRead(START_BTN));



  digitalWrite(RELE1, LOW);
  digitalWrite(RELE2, LOW);

  digitalWrite(LEFT_FWD, HIGH);
  digitalWrite(RIGHT_FWD, HIGH);

  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED);

  

  delay(100);


  // включение реле
  digitalWrite(RELE1, HIGH);
  digitalWrite(RELE2, HIGH);



  digitalWrite(LEFT_FWD, LOW);
  digitalWrite(RIGHT_FWD, LOW);
  pinMode(LEFT_FWD, INPUT_PULLUP);
  pinMode(RIGHT_FWD, INPUT_PULLUP);
  

  
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  analogWrite(LEFT_SPEED, SPEED);
  analogWrite(RIGHT_SPEED, SPEED);
}

void loop() {
  // put your main code here, to run repeatedly:
}
