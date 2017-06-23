/*
 * Project name:
     ADC_on LEDs (Display the result of ADC on LEDs)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
      A simple example of using the ADC library.
      ADC results are displayed on PORTC and PORTD.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:ADC
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn on PORTC and PORTD LEDs on SW3.3 and SW3.4.
     - To simulate analog input on ADC channel 1, use on-board potentiometer P1
       and place jumper J15 to MCU pin corresponding to ADC channel 1 input.
 */

#include <built_in.h>

unsigned int adc_rd;

void main() {
  ANSELA = 0x02;             // Configure RA1 pin as analog
  ANSELC = 0;                // Configure PORTC pins as digital
  ANSELD = 0;                // Configure PORTD pins as digital
  
  TRISA = 0x02;              // Set RA1 pin as input
  TRISC = 0x00;              // Set PORTC as output
  TRISD = 0x00;              // Set PORTD as output

  while (1) {
    adc_rd = ADC_Read(1);    // get ADC value from 1st channel
    LATC = adc_rd;           // display adc_rd[7..0]
    LATD = Hi(adc_rd);       // display adc_rd[9..8]
  }
}