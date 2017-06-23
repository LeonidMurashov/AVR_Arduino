/*
 * Project name:
     GLCD_Test (Demonstration of the GLCD library routines)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This is a simple demonstration of the GLCD library routines:
     - Init and Clear (pattern fill)
     - Image display
     - Basic geometry - lines, circles, boxes and rectangles
     - Text display and handling
 * Test configuration:
     MCU:             PIC18F45K22
                      http://ww1.microchip.com/downloads/en/DeviceDoc/41412D.pdf
     Dev.Board:       EasyPIC7 - ac:GLCD
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS-PLL 32.0000 MHz, 8.0000 MHz Crystal
     Ext. Modules:    GLCD 128x64, KS108/107 controller
                      http://www.mikroe.com/eng/products/view/277/various-components/
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * Notes:
     - Turn on GLCD backlight switch SW4.6.
 */

//Declarations------------------------------------------------------------------
const code char truck_bmp[1024];
//--------------------------------------------------------------end-declarations

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

void delay2S(){                                    // 2 seconds delay function
  Delay_ms(2000);
}

void main() {

  unsigned short counter;
  char *someText;

  ANSELB = 0;                        // Configure PORTB pins as digital I/O
  ANSELD = 0;                        // Configure PORTD pins as digital I/O

  Glcd_Init();                                   // Initialize GLCD
  Glcd_Fill(0x00);                               // Clear GLCD

  while(1) {
    Glcd_Image(truck_bmp);                            // Draw image
    Delay2s(); Delay2s();
    Glcd_fill(0x00);                                  // Clear GLCD
    Glcd_PartialImage(0,0,68,30,128,64,truck_bmp);    // Partial image
    Delay_ms(500);
    Glcd_PartialImage(24,16,68,30,128,64,truck_bmp);
    Delay_ms(500);
    Glcd_PartialImage(56,34,68,30,128,64,truck_bmp);
    Delay2s(); Delay2s();
    Glcd_Fill(0x00);                             // Clear GLCD

    Glcd_Box(62,40,124,56,1);                    // Draw box
    Glcd_Rectangle(5,5,84,35,1);                 // Draw rectangle
    Delay_ms(1000);
    Glcd_Rectangle_Round_Edges(2,2,87,38,7,1);
    Delay_ms(1000);
    Glcd_Rectangle_Round_Edges_Fill(8,8,81,32,12,1);
    Delay_ms(1000);
    Glcd_Line(0, 0, 127, 63, 1);                 // Draw line
    Delay2s();

    for(counter = 5; counter < 60; counter+=5 ){ // Draw horizontal and vertical lines
      Delay_ms(250);
      Glcd_V_Line(2, 54, counter, 1);
      Glcd_H_Line(2, 120, counter, 1);
    }
    Delay2s();

    Glcd_Fill(0x00);                             // Clear Glcd

    for (counter = 1; counter <= 10; counter++)  // Draw circles
      Glcd_Circle(63,32, 3*counter, 1);
    Delay2s();

    for (counter = 1; counter <= 10; counter++)  // Draw circles
      Glcd_Circle_Fill(63,32, 3*counter, 1);
    Delay2s();

    Glcd_Box(12,20, 70,57, 2);                   // Draw box
    Delay2s();

    Glcd_Fill(0xFF);                             // Fill Glcd

    Glcd_Set_Font(Character8x7, 8, 7, 32);       // Choose font, see __Lib_GLCDFonts.c in Uses folder
    Glcd_Write_Text("TEXT DEMO", 24, 3, 2);      // Write string
    Delay2s();
    Glcd_Fill(0x00);                             // Clear Glcd

    Glcd_Set_Font(Character8x7, 8, 7, 32);       // Change font
    someText = "8x7 Font";
    Glcd_Write_Text(someText, 5, 0, 2);          // Write string
    Delay2s();

    Glcd_Set_Font(System3x5, 3, 5, 32);          // Change font
    someText = "3X5 CAPITALS ONLY";
    Glcd_Write_Text(someText, 60, 2, 2);         // Write string
    Delay2s();

    Glcd_Set_Font(font5x7, 5, 7, 32);            // Change font
    someText = "5x7 Font";
    Glcd_Write_Text(someText, 5, 4, 2);          // Write string
    Delay2s();

    Glcd_Set_Font(FontSystem5x7_v2, 5, 7, 32);   // Change font
    someText = "5x7 Font (v2)";
    Glcd_Write_Text(someText, 50, 6, 2);         // Write string
    Delay2s();
  }

}