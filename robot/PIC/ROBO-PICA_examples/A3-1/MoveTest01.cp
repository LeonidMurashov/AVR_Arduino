#line 1 "E:/Work2007/MikroC/Code/A3-1/MoveTest01.c"
void main()
{

 ANSELH=0x00 ;
 TRISB.F1=0;TRISB.F2=0;
 TRISD.F0=0;TRISD.F1=0;
 TRISC.F1=0;TRISC.F2=0;
 PORTC.F1=1;PORTC.F2=1;


 while(1)
 {
 PORTD.F0 =0;PORTD.F1 =1;
 PORTB.F1 =0;PORTB.F2 =1;
 Delay_ms(2000);
 PORTB.F1 =1;PORTB.F2 =0;
 Delay_ms(800);
 }
}
