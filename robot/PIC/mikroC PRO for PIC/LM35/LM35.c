/*
 * Project name:
     LM35 Sensor (Temperature measurement)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
      A simple example of using the LM35 sensor.
      Temperature is displayed on LCD.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:LM35
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    LM35 Sensor, Character Lcd 2x16
                      http://www.mikroe.com/eng/products/view/277/various-components/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     - Place LM35 in proper position and place jumper J25 in the left position (RE1). (board specific)
     - Turn on Lcd backlight switch SW4.6. (board specific)
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

//  Set VREF according to the voltage reference :
//  5.00 - power supply jumper set to 5V position (reference = 5V)
//  3.30 - power supply jumper set to 3.3V position (reference = 3.3V)
const unsigned short VREF = 3.30;

unsigned int temp_res = 0;
float temp;
char txt[15];

void main() {
  ANSELB = 0;                        // Configure PORTB pins as digital
  ANSELE = 0x02;                     // Configure RE1 pin as analog
  TRISE1_bit = 1;                    // Configure RE1 pin as input
  
  ADC_Init();                        // Initialize ADC
  
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off

  Lcd_Out(1, 1, "Temperature :");
  Lcd_Chr(2,8,223);                  // Different LCD displays have different
                                     //   char code for degree
  Lcd_Chr(2,9,'C');                  // Display "C" for Celsius

  temp_res = 0;
  do {
    temp_res = ADC_Get_Sample(6);     // Get 10-bit results of AD conversion
    temp = (temp_res * VREF)/10.240;  // Calculate temperature in Celsuis
                                      //  change Vref constant according
                                      //  to the power supply voltage
    FloatToStr(temp, txt);            // Convert temperature to string
    txt[4] = 0;
    Lcd_Out(2,3,txt);                 // Write string in second row
    Delay_ms(300);
  } while(1);
}