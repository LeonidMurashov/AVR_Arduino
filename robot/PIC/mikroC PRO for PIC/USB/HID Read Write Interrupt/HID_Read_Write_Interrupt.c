/*
 * Project name:
     HID_Read_Write_Interrupt (Testing the USB HID connection)
 * Copyright:
     (c) Mikroelektronika, 2011.
 * Revision History:
     20110929:
       - initial release (FJ);
 * Description:
     This example establishes connection with the HID terminal that is active
     on the PC. Upon connection establishment, the HID Device Name will appear
     in the respective window. After that software will wait for data and
     it will return received data back.
 * Test configuration:
     MCU:             PIC18F4550
                      http://ww1.microchip.com/downloads/en/DeviceDoc/39632D.pdf
     Dev.Board:       EasyPIC7 - ac:USB
                      http://www.mikroe.com/eng/products/view/757/easypic-v7-development-system/
     Oscillator:      HS, 8.000 MHz  (USB osc. is raised with PLL to 48.000MHz)
     Ext. Modules:    None.
     SW:              mikroC PRO for PIC
                      http://www.mikroe.com/eng/products/view/7/mikroc-pro-for-pic/
 * NOTES:
     (*) Be VERY careful about the configuration flags for the 18F4550 - there's
     so much place for mistake!
    - Place jumpers J12 in the right (USB) position.
 */

unsigned char readbuff[64] absolute 0x500;   // Buffers should be in USB RAM, please consult datasheet
unsigned char writebuff[64] absolute 0x540;

char cnt;
char kk;

void interrupt(){
   USB_Interrupt_Proc();                   // USB servicing is done inside the interrupt
}

void main(void){
  ADCON1 |= 0x0F;                         // Configure all ports with analog function as digital
  CMCON  |= 7;                            // Disable comparators

  HID_Enable(&readbuff,&writebuff);       // Enable HID communication

  while(1){
    while(!HID_Read())
      ;

    for(cnt=0;cnt<64;cnt++)
      writebuff[cnt]=readbuff[cnt];

    while(!HID_Write(&writebuff,64))
      ;
  }
}