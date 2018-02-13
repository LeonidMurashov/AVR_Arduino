int rots_left = 0,
          rots_right = 0;
byte encoder_left = 19,
     encoder_right = 20;
bool encoder_left_state = 0,
     encoder_right_state = 0;

void setup()
{
  Serial.begin(9600);
  
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

  pinMode(encoder_left, INPUT);  
  pinMode(encoder_right, INPUT);

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
}

void loop()
{
  Serial.print(rots_left);
  Serial.print(" ");
  Serial.println(rots_right);
}

