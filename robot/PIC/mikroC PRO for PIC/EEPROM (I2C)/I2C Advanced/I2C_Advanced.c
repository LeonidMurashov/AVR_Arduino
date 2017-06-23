/*
 * Project name:
     I2C_Advanced (Advanced I2C Example)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);   
 * Description:
     This example features the advanced communication with the 24AA01 EEPROM chip
     by introducing its own library of functions for this task: init, single
     write, single and sequential read. It performs write of a sequence of bytes
     (characters) into the EEPROM and writes this out at the first row on Lcd.
     Then, data read from EEPROM is performed and the result is displayed at the
     second row on Lcd.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 -  ac:Serial_EEPROM
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    Character Lcd 2x16
                      http://www.mikroe.com/eng/products/view/277/various-components/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Turn on I2C switches SW4.7 and SW4.8. (board specific)
     - Turn off PORTC LEDs (SW3.3). (board specific)
     - Turn on LCD backlight switch SW4.6. (board specific)
*/

#include "EEPROM_24AA01.h"

// LCD module connections
sbit LCD_RS at LATB4_bit;
sbit LCD_EN at LATB5_bit;
sbit LCD_D4 at LATB0_bit;
sbit LCD_D5 at LATB1_bit;
sbit LCD_D6 at LATB2_bit;
sbit LCD_D7 at LATB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;
// End LCD module connections

char someData[] = "I2C mikroE";
char i ,tmpdata;

//  Main
void main() {

  EEPROM_24AA01_Init();                     // performs I2C initialization
  ANSELB = 0;                               // Configure PORTB pins as digital
  ANSELC = 0;                               // Configure PORTC pins as digital
  Lcd_Init();                               // performs Lcd initialization
  Lcd_Cmd(_LCD_CLEAR);                      // clear Lcd
  Lcd_Cmd(_LCD_CURSOR_OFF);                 // set cursor off

  // Example for single-byte write
  i = 0;
  tmpdata = 1;
  while ((tmpdata = someData[i]) != 0) {
    i++;
    EEPROM_24AA01_WrSingle(i, tmpdata);     // writes data, char by char, in the EEPROM
    Delay_ms(20);
    Lcd_Chr(1,i, tmpdata);                  // diplays data on the first row of the Lcd
  }
  EEPROM_24AA01_WrSingle(i+1, 0);           // writes string termination
  Delay_ms(20);

  // Example for single-byte read
  i = 1;
  tmpdata = 1;
  while ((tmpdata = EEPROM_24AA01_RdSingle(i)) != 0) {
    Lcd_Chr(2,i, tmpdata);                  // displays data from EEPROM on the second row of the Lcd
    Delay_ms(20);
    i++ ;
  }
  
  //  Example for sequential data read
  Delay_ms(1000);
  Lcd_Cmd(_LCD_CLEAR);
  EEPROM_24AA01_RdSeq(1, someData, 13);
  Lcd_Out(2,1,someData);
}