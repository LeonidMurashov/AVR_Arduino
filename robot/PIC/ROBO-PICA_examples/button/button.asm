
_main:

;button.c,1 :: 		void main() {
;button.c,3 :: 		TRISB.F3 = 0;
	BCF        TRISB+0, 3
;button.c,4 :: 		TRISC.F7 = 1;
	BSF        TRISC+0, 7
;button.c,6 :: 		Sound_Init(&PORTC,0);
	MOVLW      PORTC+0
	MOVWF      FARG_Sound_Init_snd_port+0
	CLRF       FARG_Sound_Init_snd_pin+0
	CALL       _Sound_Init+0
;button.c,10 :: 		PORTB.F3 = 1;
	BSF        PORTB+0, 3
;button.c,11 :: 		while(1)
L_main0:
;button.c,13 :: 		if(PORTC.F7)PORTB.F3 = 1;
	BTFSS      PORTC+0, 7
	GOTO       L_main2
	BSF        PORTB+0, 3
	GOTO       L_main3
L_main2:
;button.c,14 :: 		else  PORTB.F3 = 0;
	BCF        PORTB+0, 3
L_main3:
;button.c,15 :: 		}
	GOTO       L_main0
;button.c,18 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
