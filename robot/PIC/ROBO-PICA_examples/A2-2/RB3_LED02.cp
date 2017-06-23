#line 1 "E:/Work2007/MikroC/Code/A2-2/RB3_LED02.c"
void main()
{
 TRISB.F3=0;
 while(1)
 {
 PORTB.F3=1;
 Delay_ms(500);
 PORTB.F3=0;
 Delay_ms(500);
 }
}
