#line 1 "E:/Work2007/MikroC/Code/A13-1/IRTest.c"
char *text1 = "ER-4 Remote";
unsigned char ir_cmd=0;



void interrupt()
{
 unsigned char i;
 if(INTCON.INTF)
 {
 Delay_us(416);
 for(i=0;i<8;i++)
 {
 Delay_us(833);
 ir_cmd = ir_cmd>>1;
 if((PORTB & 0x01)==1)
 ir_cmd = ir_cmd | 0x80;
 }
 Delay_us(833);
 INTCON.INTF =0;
 }
}



unsigned char get_remote()
{
 unsigned char _key=ir_cmd;
 ir_cmd=0;
 return(_key);
}



void main()
{
 unsigned char key;
 ANSELH.F4=0;
 OPTION_REG.INTEDG = 0;
 INTCON.INTE =1;
 INTCON.GIE =1;

 Lcd_Init(&PORTD);
 Lcd_Cmd(Lcd_CLEAR);
 Lcd_Cmd(Lcd_CURSOR_OFF);
 Lcd_Out(1, 1, text1);
 Sound_Init(&PORTC,0);
 while(1)
 {
 key = get_remote();
 if(key=='a' || key=='A')
 {
 Lcd_Out(2, 1, "Button A Press  ");
 Sound_Play(2000,200);
 }
 else if(key=='b' || key=='B')
 {
 Lcd_Out(2, 1, "Button B Press  ");
 Sound_Play(2500,200);
 }
 else if(key=='c' || key=='C')
 {
 Lcd_Out(2, 1, "Button C Press  ");
 Sound_Play(2900,200);
 }
 else if(key=='d' || key=='D')
 {
 Lcd_Out(2, 1, "Button D Press  ");
 Sound_Play(3200,200);
 }
 }








 }
