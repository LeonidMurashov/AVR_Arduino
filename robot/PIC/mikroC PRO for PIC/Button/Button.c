/*
 * Project name:
     Button (Demonstration of using Button Library)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This program demonstrates usage on-board button as PORTB input.
     On every RB0 one-to-zero transition PORTC is inverted.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:Buttons
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn ON the PORTC LEDs at SW3.3.
     - Put button jumper (J17) into VCC position and pull-down PORTB.
*/

bit oldstate;                                    // Old state flag

void main() {

  ANSELB = 0;                                    // Configure PORTB pins as digital
  ANSELC = 0;                                    // Configure PORTC pins as digital

  TRISB0_bit = 1;                                // set RB0 pin as input
  
  TRISC = 0x00;                                  // Configure PORTC as output
  LATC = 0xAA;                                   // Initial PORTC value
  
  oldstate = 0;
  
  do {
    if (Button(&PORTB, 0, 1, 1)) {               // Detect logical one
      oldstate = 1;                              // Update flag
    }
    if (oldstate && Button(&PORTB, 0, 1, 0)) {   // Detect one-to-zero transition
      LATC = ~LATC;                              // Invert PORTC
      oldstate = 0;                              // Update flag
    }
  } while(1);                                    // Endless loop
}