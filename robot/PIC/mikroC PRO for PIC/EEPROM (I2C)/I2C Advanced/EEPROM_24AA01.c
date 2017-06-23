// EEPROM 24AA01 read/write library


//--------------- Performs 24AA01 Init
void EEPROM_24AA01_Init() {
  I2C1_Init(100000);
}

//--------------- Writes data to 24AA01 EEPROM - single location
void EEPROM_24AA01_WrSingle(unsigned short wAddr, unsigned short wData) {
    I2C1_Start();             // issue I2C1 start signal
    I2C1_Wr(0xA2);            // send byte via I2C1  (command to 24cO2)
    I2C1_Wr(wAddr);           // send byte (address of EEPROM location)
    I2C1_Wr(wData);           // send data (data to be written)
    I2C1_Stop();
}

//--------------- Reads data from 24AA01 EEPROM - single location (random)
unsigned short EEPROM_24AA01_RdSingle(unsigned short rAddr) {
    unsigned short reslt;

    I2C1_Start();             // issue I2C1 start signal
    I2C1_Wr(0xA2);            // send byte via I2C1  (device address + W)
    I2C1_Wr(rAddr);           // send byte (data address)
    I2C1_Repeated_Start();    // issue I2C1 signal repeated start
    I2C1_Wr(0xA3);            // send byte (device address + R)
    reslt = I2C1_Rd(0u);      // Read the data (NO acknowledge)
    while (!I2C1_Is_Idle())
      asm nop;                // Wait for the read cycle to finish
    I2C1_Stop();
    return reslt;
}

//--------------- Reads data from 24AA01 EEPROM - sequential read
void EEPROM_24AA01_RdSeq(unsigned short rAddr,
                        unsigned char *rdData,
                        unsigned short rLen) {
  unsigned short i;
  I2C1_Start();               // issue I2C1 start signal
  I2C1_Wr(0xA2);              // send byte via I2C1  (device address + W)
  I2C1_Wr(rAddr);             // send byte (address of EEPROM location)
  I2C1_Repeated_Start();      // issue I2C1 signal repeated start
  I2C1_Wr(0xA3);              // send byte (device address + R)
  i = 0;
  while (i < rLen) {
    rdData[i] = I2C1_Rd(1u);  // read data (acknowledge)
    Delay_ms(20);
    i++ ;
  }
  rdData[i] = I2C1_Rd(0u);    // last data is read (no acknowledge)
  I2C1_Stop();
}