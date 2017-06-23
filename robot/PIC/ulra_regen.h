
void main() {
   TRISB.f3=0;

   while(1)
   {
              PORTB.F3=1;
           Delay_ms(500);
              PORTB.F3=0;
           Delay_ms(500);
    }
    
}