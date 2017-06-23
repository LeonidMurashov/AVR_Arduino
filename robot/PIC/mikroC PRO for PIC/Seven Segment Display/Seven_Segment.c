/*
 * Project name:
     Seven Segment Display (The 'Hello World' example for the Seven Segment Display)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This code demonstrates how to display number on one 7-segment display
     (common cathode). Display is connected to PORTD (RD0..RD7, segment A to
     RD0, segment B to RD1, etc); common cathode is connected to the pin RA0 on
     PORTA. Number is incremented every 1s.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:7SEG
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn on Seven Segment Display switches SW4.1, SW4.2, SW4.3 and SW4.4. (board specific)
 */

#include "Display_Utils.h"

unsigned short shifter, portd_index;
unsigned int   digit, number;
unsigned short portd_array[4];

void interrupt() {
  LATA = 0;                             // Turn off all 7seg displays
  LATD = portd_array[portd_index];      // bring appropriate value to PORTD
  LATA = shifter;                       // turn on appropriate 7seg. display

  // move shifter to next digit
  shifter <<= 1;
  if (shifter > 8u)
    shifter = 1;

  // increment portd_index
  portd_index++ ;
  if (portd_index > 3u)
    portd_index = 0;             // turn on 1st, turn off 2nd 7seg.
  TMR0L  =   0;                  // reset TIMER0 value
  TMR0IF_bit = 0;                // Clear TMR0IF
}

void main() {
  ANSELA = 0;                    // Configure PORTA pins as digital
  ANSELD = 0;                    // Configure PORTD pins as digital

  TRISA = 0;                     // Configure PORTA as output
  LATA  = 0;                     // Clear PORTA
  TRISD = 0;                     // Configure PORTD as output
  LATD  = 0;                     // Clear PORTD

  T0CON = 0xC4;                  // Set TMR0 in 8bit mode, assign prescaler to TMR0
  TMR0L = 0;                     // clear TMROL
  digit = 0;
  portd_index = 0;
  shifter = 1;

  number = 1234;                 // Initial number value
  GIE_bit = 1;
  TMR0IE_bit = 1;

  do {
    digit = number / 1000u ;             // extract thousands digit
    portd_array[3] = mask(digit);        // and store it to PORTD array
    digit = (number / 100u) % 10u;       // extract hundreds digit
    portd_array[2] = mask(digit);        // and store it to PORTD array
    digit = (number / 10u) % 10u;        // extract tens digit
    portd_array[1] = mask(digit);        // and store it to PORTD array
    digit = number % 10u;                // extract ones digit
    portd_array[0] = mask(digit);        // and store it to PORTD array

    Delay_ms(1000);                      // one second delay

    number++ ;                           // increment number
    if (number > 9999u)
      number = 0;

  } while(1);                            // endless loop
}