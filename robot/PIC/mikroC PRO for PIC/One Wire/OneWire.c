/*
 * Project name:
     OneWire (Interfacing the DS1820 temperature sensor - all versions)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This code demonstrates one-wire communication with temperature sensor
     DS18x20 connected to RA4 or RE2 pin.
     MCU reads temperature from the sensor and prints it on the LCD.
     The display format of the temperature is 'xxx.xxxx°C'. To obtain correct
     results, the 18x20's temperature resolution has to be adjusted (constant
     TEMP_RESOLUTION).
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:One_Wire
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    DS18x20 Sensor, Character Lcd 2x16
                      http://www.mikroe.com/eng/products/view/277/various-components/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Place LM35 in proper position and place jumper J11 in the right position (RE2). (board specific)
     - Turn on Lcd backlight switch SW4.6. (board specific)
     - Be sure to put the power supply jumper J5 in the 5V position.
 */

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

//  Set TEMP_RESOLUTION to the corresponding resolution of used DS18x20 sensor:
//  18S20: 9  (default setting; can be 9,10,11,or 12)
//  18B20: 12
const unsigned short TEMP_RESOLUTION = 9;

char *text = "000.0000";
unsigned temp;

void Display_Temperature(unsigned int temp2write) {
  const unsigned short RES_SHIFT = TEMP_RESOLUTION - 8;
  char temp_whole;
  unsigned int temp_fraction;

  // Check if temperature is negative
  if (temp2write & 0x8000) {
    text[0] = '-';
    temp2write = ~temp2write + 1;
  }

  // Extract temp_whole
  temp_whole = temp2write >> RES_SHIFT ;

  // Convert temp_whole to characters
  if (temp_whole/100)
    text[0] = temp_whole/100  + 48;
  else
    text[0] = '0';

  text[1] = (temp_whole/10)%10 + 48;             // Extract tens digit
  text[2] =  temp_whole%10     + 48;             // Extract ones digit

  // Extract temp_fraction and convert it to unsigned int
  temp_fraction  = temp2write << (4-RES_SHIFT);
  temp_fraction &= 0x000F;
  temp_fraction *= 625;

  // Convert temp_fraction to characters
  text[4] =  temp_fraction/1000    + 48;         // Extract thousands digit
  text[5] = (temp_fraction/100)%10 + 48;         // Extract hundreds digit
  text[6] = (temp_fraction/10)%10  + 48;         // Extract tens digit
  text[7] =  temp_fraction%10      + 48;         // Extract ones digit

  // Print temperature on LCD
  Lcd_Out(2, 5, text);
}

void main() {
  ANSELE = 0;                                    // Configure PORTE pins as digital
  TRISE.B2 = 1;                                  // Configure RE2 pin as input

  Lcd_Init();                                    // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);                           // Clear LCD
  Lcd_Cmd(_LCD_CURSOR_OFF);                      // Turn cursor off
  Lcd_Out(1, 1, " Temperature:   ");
  // Print degree character, 'C' for Centigrades
  Lcd_Chr(2,13,223);                             // Different LCD displays have different char code for degree
                                                 // If you see greek alpha letter try typing 178 instead of 223
  Lcd_Chr(2,14,'C');

  // Main loop
  do {
    // Perform temperature reading
    Ow_Reset(&PORTE, 2);                         // Onewire reset signal
    Ow_Write(&PORTE, 2, 0xCC);                   // Issue command SKIP_ROM
    Ow_Write(&PORTE, 2, 0x44);                   // Issue command CONVERT_T
    Delay_us(120);

    Ow_Reset(&PORTE, 2);
    Ow_Write(&PORTE, 2, 0xCC);                   // Issue command SKIP_ROM
    Ow_Write(&PORTE, 2, 0xBE);                   // Issue command READ_SCRATCHPAD

    temp =  Ow_Read(&PORTE, 2);
    temp = (Ow_Read(&PORTE, 2) << 8) + temp;

    // Format and display result on Lcd
    Display_Temperature(temp);

    Delay_ms(500);
  } while (1);
}