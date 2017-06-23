/*
 * Project name:
     LED_Curtain (Simple 'Hello World' project)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This is a simple 'Hello World' project. It turns on/off LEDs connected to
     PORTA, PORTB, PORTC, PORTD and PORTE.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:LEDs
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn ON the PORT LEDs at SW3.
*/

char counter;

void wait() {
  Delay_ms(100);
}

void main() {

  TRISA = 0x00;                                 // set direction to be output
  TRISB = 0x00;                                 // set direction to be output
  TRISC = 0x00;                                 // set direction to be output
  TRISD = 0x00;                                 // set direction to be output
  TRISE = 0x00;                                 // set direction to be output

  LATA = 0x00;                                  // turn OFF the LATD leds
  LATB = 0x00;                                  // turn OFF the LATD leds
  LATC = 0x00;                                  // turn OFF the LATC leds
  LATD = 0x00;                                  // turn OFF the LATD leds
  LATE = 0x00;                                  // turn OFF the LATD leds
  
  while (1) {
    for (counter=0; counter<8; counter++) {
      LATA |= 1 << counter;
      LATB |= 1 << counter;
      LATC |= 1 << counter;
      LATD |= 1 << counter;
      LATE |= 1 << counter;
      wait();
    }
       
    counter = 0;
    while (counter<8) {
      LATA &= ~(1 << counter);
      LATB &= ~(1 << counter);
      LATC &= ~(1 << counter);
      LATD &= ~(1 << counter);
      LATE &= ~(1 << counter);
      wait();
      counter++;
    }
  }
}