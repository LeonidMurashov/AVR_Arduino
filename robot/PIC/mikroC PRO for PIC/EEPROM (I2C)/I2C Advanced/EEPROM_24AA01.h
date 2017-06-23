//EEPROM_24AA01 library header file

void EEPROM_24AA01_Init();
void EEPROM_24AA01_WrSingle(unsigned short wAddr, unsigned short wData);
unsigned short EEPROM_24AA01_RdSingle(unsigned short rAddr);
void EEPROM_24AA01_RdSeq(unsigned short rAddr,
                        unsigned char *rdData,
                        unsigned short rLen);
