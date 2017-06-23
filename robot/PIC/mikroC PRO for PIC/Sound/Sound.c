/*
 * Project name:
     Sound_Var (Usage of Sound library)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This project is a simple demonstration of how to
     use sound library for playing tones on a piezo speaker.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:Sound
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Put Piezo Buzzer jumper J21 into upper position (RE1). (board specific)
     - Put button jumper (J17) into VCC position and
       pull-down pins RB7...RB3 on PORTB. (board specific)
 */

void Tone1() {
  Sound_Play(659, 250);   // Frequency = 659Hz, duration = 250ms
}

void Tone2() {
  Sound_Play(698, 250);   // Frequency = 698Hz, duration = 250ms
}

void Tone3() {
  Sound_Play(784, 250);   // Frequency = 784Hz, duration = 250ms
}

void Melody() {           // Plays the melody "Yellow house"
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone1(); Tone2(); Tone3(); Tone3();
  Tone1(); Tone2(); Tone3();
  Tone3(); Tone3(); Tone2(); Tone2(); Tone1();
}

void ToneA() {
  Sound_Play( 880, 50);
}
void ToneC() {
  Sound_Play(1046, 50);
}
void ToneE() {
  Sound_Play(1318, 50);
}

void Melody2() {
  unsigned short i;
  for (i = 9; i > 0; i--) {
    ToneA(); ToneC(); ToneE();
  }
}

void main() {
  ANSELB = 0;                        // Configure PORTB pins as digital
  ANSELE = 0;                        // Configure PORTE pins as digital

  TRISB  = 0xF8;                     // Configure RB7..RB3 as input

  Sound_Init(&PORTE, 1);
  Sound_Play(880, 1000);             // Play sound at 880Hz for 1 second

  while (1) {
    if (Button(&PORTB,7,1,1))        // RB7 plays Tone1
      Tone1();
    while (RB7_bit) ;                // Wait for button to be released

    if (Button(&PORTB,6,1,1))        // RB6 plays Tone2
      Tone2();
    while (RB6_bit) ;                // Wait for button to be released

    if (Button(&PORTB,5,1,1))        // RB5 plays Tone3
      Tone3();
    while (RB5_bit) ;                // Wait for button to be released

    if (Button(&PORTB,4,1,1))        // RB4 plays Melody2
      Melody2();
    while (RB4_bit) ;                // Wait for button to be released

    if (Button(&PORTB,3,1,1))        // RB3 plays Melody
      Melody();
    while (RB3_bit) ;                // Wait for button to be released
  }
}