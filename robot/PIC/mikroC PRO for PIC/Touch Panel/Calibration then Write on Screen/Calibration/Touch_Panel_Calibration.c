/*
 * Project name:
     TouchPanelCalibration (Demo for working with TouchPanel Controller)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This code works with TouchPanel and GLCD. Two digital output and
     two analog input signals are used for communication with TouchPanel.
     The example shows how to calibrate touch panel and prints aquired 
     calibration constants on GLCD.
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:Touch_Panel
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    GLCD 128x64, Touch Panel
                      http://www.mikroe.com/eng/products/view/277/various-components/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * Notes:
     - Turn on GLCD backlight switch SW4.6. (board specific)
     - Turn on TouchPanel Controller switches SW3.5, SW3.6, SW3.7 and SW3.8. (board specific)
     - Turn off PORTA LEDs SW3.1. (board specific)
     - Put the power supply jumper J5 in the 3.3V position. (board specific)
 */

// Glcd module connections
char GLCD_DataPort at PORTD;

sbit GLCD_CS1 at LATB0_bit;
sbit GLCD_CS2 at LATB1_bit;
sbit GLCD_RS  at LATB2_bit;
sbit GLCD_RW  at LATB3_bit;
sbit GLCD_EN  at LATB4_bit;
sbit GLCD_RST at LATB5_bit;

sbit GLCD_CS1_Direction at TRISB0_bit;
sbit GLCD_CS2_Direction at TRISB1_bit;
sbit GLCD_RS_Direction  at TRISB2_bit;
sbit GLCD_RW_Direction  at TRISB3_bit;
sbit GLCD_EN_Direction  at TRISB4_bit;
sbit GLCD_RST_Direction at TRISB5_bit;
// End Glcd module connections

// Touch Panel module connections
sbit DriveA at LATC0_bit;
sbit DriveB at LATC1_bit;
sbit DriveA_Direction at TRISC0_bit;
sbit DriveB_Direction at TRISC1_bit;
// End Touch Panel module connections

const char msg1[] = "TOUCH BOTTOM LEFT";
const char msg2[] = "                 ";
const char msg3[] = "TOUCH UPPER RIGHT";
const char msg4[] = "CALIBRATION";
const char msg5[] = "Calibration constants";
char msg[22];

unsigned int x_min, y_min, x_max, y_max;           // Calibration constants

char x_min_msg[] = "X min:";                       // GLCD text messages
char y_min_msg[] = "Y min:";
char x_max_msg[] = "X max:";
char y_max_msg[] = "Y max:";

char x_min_val[6];                                 // Calibration constants string values
char y_min_val[6];
char x_max_val[6];
char y_max_val[6];

// copy const to ram string
char * CopyConst2Ram(char * dest, const char * src){
  char * d ;
  d = dest;
  for(;*dest++ = *src++;)
    ;
  return d;
}

void Initialize() {
  ANSELA = 3;                  // Configure AN0 and AN1 pins as analog
  ANSELB = 0;                  // Configure PORTB pins as digital
  ANSELC = 0;                  // Configure PORTC pins as digital
  ANSELD = 0;                  // Configure PORTD pins as digital
  TRISA  = 3;                  // Configure AN0 and AN1 pins as input

  Glcd_Init();                 // Initialize GLCD
  Glcd_Fill(0);                // Clear GLCD
  ADC_Init();                  // Initialize ADC
  TP_Init(128, 64, 0, 1);      // Initialize touch panel
  TP_Set_ADC_Threshold(900);   // Set touch panel ADC threshold
}

void Calibrate() {

  Glcd_Dot(0,63,1);                                // Draw bottom left dot
  Glcd_Write_Text(CopyConst2Ram(msg,msg1),12,3,1);
  TP_Calibrate_Bottom_Left();                      // Calibration of bottom left corner
  Delay_ms(1000);

  Glcd_Dot(0,63,0);                                // Clear bottom left dot
  Glcd_Dot(127,0,1);                               // Draw upper right dot
  Glcd_Write_Text(CopyConst2Ram(msg,msg2),12,3,1);
  Glcd_Write_Text(CopyConst2Ram(msg,msg3),12,4,1);
  TP_Calibrate_Upper_Right();                      // Calibration of upper right corner

  Delay_ms(1000);
}

void main() {

  Initialize();

  Glcd_Write_Text(CopyConst2Ram(msg,msg4),32,3,1);
  Delay_ms(1000);
  Glcd_Fill(0);                                    // Clear GLCD
  Calibrate();

  TP_Get_Calibration_Consts(&x_min, &x_max, &y_min, &y_max); // Get calibration constants

  WordToStr(x_min, x_min_val);                             // Convert calibration constants into string values
  WordToStr(x_max, x_max_val);
  WordToStr(y_min, y_min_val);
  WordToStr(y_max, y_max_val);

  // Display Calibration constants on GLCD
  
  Glcd_Fill(0);                                            // Clear GLCD
  Glcd_Write_Text(CopyConst2Ram(msg,msg5),1,1,1);
  Glcd_Write_Text(x_min_msg,1,3,1);                        // Write messages on GLCD
  Glcd_Write_Text(x_max_msg,1,4,1);
  Glcd_Write_Text(y_min_msg,1,5,1);
  Glcd_Write_Text(y_max_msg,1,6,1);

  Glcd_Write_Text(x_min_val,50,3,1);                       // Write calibration constants values on GLCD
  Glcd_Write_Text(x_max_val,50,4,1);
  Glcd_Write_Text(y_min_val,50,5,1);
  Glcd_Write_Text(y_max_val,50,6,1);

}