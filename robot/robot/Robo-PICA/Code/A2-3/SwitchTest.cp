#line 1 "E:/Work2007/MikroC/Code/A2-3/SwitchTest.c"
void main()
{
 ANSELH.F4=0;
 TRISB.F3=0;
 while(1)
 {
 if(PORTB.F0==0)
 {
 PORTB.F3=1;
 }
 if(PORTA.F4==0)
 {
 PORTB.F3=0;
 }
 }
}
