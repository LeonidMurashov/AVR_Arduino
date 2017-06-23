#line 1 "E:/Work2007/MikroC/Code/A2-6/SoundTest.c"
void main()
{
 Sound_Init(&PORTC, 0);
 while(1)
 {
 if (!PORTA.F4)
 sound_play(2000,100);
 }
}
