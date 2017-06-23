/*
 * Project name:
     TouchPanelCalibrationAndWrite (Demo for working with TouchPanel Controller)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This code works with TouchPanel and GLCD. Two digital output and
     two analog input signals are used for communication with TouchPanel. 
     This example shows how to calibrate touch panel and how to write on the screen.
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

bit          write_erase;
char         pen_size;
char write_msg[] = "WRITE";   // GLCD menu messages
char clear_msg[] = "CLEAR";
char erase_msg[] = "ERASE";
unsigned int x_coord, y_coord;

void Initialize() {
  ANSELA = 3;              // Configure AN0 and AN1 pins as analog
  ANSELB = 0;              // Configure PORTB pins as digital
  ANSELC = 0;              // Configure PORTC pins as digital
  ANSELD = 0;              // Configure PORTD pins as digital
  TRISA  = 3;              // Configure AN0 and AN1 pins as input
 
  Glcd_Init();                                     // Initialize GLCD
  Glcd_Fill(0);                                    // Clear GLCD

  ADC_Init();                                      // Initialize ADC
  TP_Init(128, 64, 0, 1);                          // Initialize touch panel
  TP_Set_ADC_Threshold(900);                       // Set touch panel ADC threshold
}

void Calibrate() {

  Glcd_Dot(0,63,1);                                // Draw bottom left dot
  Glcd_Write_Text("TOUCH BOTTOM LEFT",12,3,1);
  TP_Calibrate_Bottom_Left();                      // Calibration of bottom left corner
  Delay_ms(1000);

  Glcd_Dot(0,63,0);                                // Clear bottom left dot
  Glcd_Dot(127,0,1);                               // Draw upper right dot
  Glcd_Write_Text("                 ",12,3,1);  
  Glcd_Write_Text("TOUCH UPPER RIGHT",12,4,1);
  TP_Calibrate_Upper_Right();                      // Calibration of upper right corner

  Delay_ms(1000);
}

void delay2S(){                                    // 2 seconds delay function
  Delay_ms(2000);
}

void main() {

  Initialize();

  Glcd_Write_Text("CALIBRATION",32,3,1);
  Delay_ms(1000);
  Glcd_Fill(0);                                    // Clear GLCD
  Calibrate();

  Glcd_Fill(0);
  Glcd_Write_Text("WRITE ON SCREEN", 20, 5, 1) ;
  Delay_ms(1000);

  Glcd_Fill(0);                                    // Clear GLCD
  Glcd_V_Line(0,7,0,1);
  Glcd_Write_Text(clear_msg,1,0,0);
  Glcd_V_Line(0,7,97,1);
  Glcd_Write_Text(erase_msg,98,0,0);

  // Pen Menu:
  Glcd_Rectangle(41,0,52,9,1);
  Glcd_Box(45,3,48,6,1);
  Glcd_Rectangle(63,0,70,7,1);
  Glcd_Box(66,3,67,4,1);
  Glcd_Rectangle(80,0,86,6,1);
  Glcd_Dot(83,3,1);

  write_erase = 1;
  pen_size = 1;
  while (1) {

    if (TP_Press_Detect()) {
      // After a PRESS is detected read X-Y and convert it to 128x64 space
      if (TP_Get_Coordinates(&x_coord, &y_coord) == 0) {

        if ((x_coord < 31) && (y_coord < 8)) {

          Glcd_Fill(0);

          // Pen Menu:
          Glcd_Rectangle(41,0,52,9,1);
          Glcd_Box(45,3,48,6,1);
          Glcd_Rectangle(63,0,70,7,1);
          Glcd_Box(66,3,67,4,1);
          Glcd_Rectangle(80,0,86,6,1);
          Glcd_Dot(83,3,1);

          Glcd_V_Line(0,7,0,1);
          Glcd_Write_Text(clear_msg,1,0,0);
          Glcd_V_Line(0,7,97,1);
          if (write_erase)
            Glcd_Write_Text(erase_msg,98,0,0);
          else
            Glcd_Write_Text(write_msg,98,0,0);
          }

        // If write/erase is pressed
        if ((x_coord > 96) && (y_coord < 8)) {
          if (write_erase) {
            write_erase = 0;
            Glcd_Write_Text(write_msg,98,0,0);
            Delay_ms(500);
            }
          else {
            write_erase = 1;
            Glcd_Write_Text(erase_msg,98,0,0);
            Delay_ms(500);
            }
          }

        // If pen size is selected
        if ((x_coord >= 41) && (x_coord <= 52) && (y_coord <= 9))
          pen_size = 3;

        if ((x_coord >= 63) && (x_coord <= 70) && (y_coord <= 7))
          pen_size = 2;

        if ((x_coord >= 80) && (x_coord <= 86) && (y_coord <= 6))
          pen_size = 1;

        if (y_coord < 11)
          continue;

        switch (pen_size) {
          case 1 : {
                     if ( (x_coord >= 0) && (y_coord >= 0) && (x_coord <= 127) && (y_coord <= 63) )
                       Glcd_Dot(x_coord, y_coord, write_erase);
                     break;
                   }
          case 2 : {
                     if ( (x_coord >= 0) && (y_coord >= 0) && (x_coord <= 127-1) && (y_coord <= 63-1) )
                       Glcd_Box(x_coord, y_coord, x_coord + 1, y_coord + 1, write_erase);
                     break;
                   }
          case 3 : {
                     if ( (x_coord >= 1) && (y_coord >= 1) && (x_coord <= 127-2) && (y_coord <= 63-2) )
                       Glcd_Box(x_coord-1, y_coord-1, x_coord + 2, y_coord + 2, write_erase);
                     break;
                   }
        }
      }
    }
  }
}

