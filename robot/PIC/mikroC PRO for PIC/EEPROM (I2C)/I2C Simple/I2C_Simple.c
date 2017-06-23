/*
 * Project name:
     I2C_Simple (Simple test of I2C library routines)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This program demonstrates usage of the I2C library routines. It
     establishes I2C bus communication with 24C02 EEPROM chip, writes one byte
     of data on some location, then reads it and displays it on PORTB.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:Serial_EEPROM
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn on I2C switches SW4.7 and SW4.8. (board specific)
     - Turn off PORTC LEDs (SW3.3). (board specific)
     - Turn on PORTB LEDs (SW3.2). (board specific)
 */

void main(){
  ANSELB = 0;                // Configure PORTB pins as digital
  ANSELC = 0;                // Configure PORTC pins as digital
  
  TRISB = 0;                 // Configure PORTB as output
  LATB = 0;                  // Clear PORTB

  I2C1_Init(100000);         // initialize I2C communication
  I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0xA2);             // send byte via I2C  (device address + W)
  I2C1_Wr(2);                // send byte (address of EEPROM location)
  I2C1_Wr(0xAA);             // send data (data to be written)
  I2C1_Stop();               // issue I2C stop signal

  Delay_100ms();

  I2C1_Start();              // issue I2C start signal
  I2C1_Wr(0xA2);             // send byte via I2C  (device address + W)
  I2C1_Wr(2);                // send byte (data address)
  I2C1_Repeated_Start();     // issue I2C signal repeated start
  I2C1_Wr(0xA3);             // send byte (device address + R)
  LATB = I2C1_Rd(0u);        // Read the data (NO acknowledge)
  I2C1_Stop();               // issue I2C stop signal
}