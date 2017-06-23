//-------------- Returns mask for common cathode 7-seg. display
unsigned short mask(unsigned short num) {
  switch (num) {
    case 0 : return 0x3F;                                
    case 1 : return 0x06;
    case 2 : return 0x5B;
    case 3 : return 0x4F;
    case 4 : return 0x66;
    case 5 : return 0x6D;
    case 6 : return 0x7D;
    case 7 : return 0x07;
    case 8 : return 0x7F;
    case 9 : return 0x6F;
  } //case end
}
