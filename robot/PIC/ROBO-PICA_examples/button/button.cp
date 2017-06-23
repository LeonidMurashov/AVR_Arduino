#line 1 "D:/робот/button/button.c"
void main() {

 TRISB.F3 = 0;
 TRISC.F7 = 1;

 Sound_Init(&PORTC,0);



 PORTB.F3 = 1;
 while(1)
 {
 if(PORTC.F7)PORTB.F3 = 1;
 else PORTB.F3 = 0;
 }

 PORTB.F3 = 0;
}
