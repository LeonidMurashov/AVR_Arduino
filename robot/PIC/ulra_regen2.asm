
_Display_Input:

;ulra_regen2.c,19 :: 		void Display_Input(int x,  int y, int z) {
;ulra_regen2.c,27 :: 		text[0] = (z/100)%10    + 48;         // Extract tens digit
	MOVLW      100
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_Display_Input_z+0, 0
	MOVWF      R0+0
	MOVF       FARG_Display_Input_z+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVLW      48
	ADDWF      R0+0, 1
	MOVF       _text+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;ulra_regen2.c,28 :: 		text[1] = (z/10)%10     + 48;         // Extract ones digit
	INCF       _text+0, 0
	MOVWF      FLOC__Display_Input+0
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_Display_Input_z+0, 0
	MOVWF      R0+0
	MOVF       FARG_Display_Input_z+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVLW      48
	ADDWF      R0+0, 1
	MOVF       FLOC__Display_Input+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;ulra_regen2.c,29 :: 		text[2] =  z%10         + 48;         // Extract ones digit
	MOVLW      2
	ADDWF      _text+0, 0
	MOVWF      FLOC__Display_Input+0
	MOVLW      10
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       FARG_Display_Input_z+0, 0
	MOVWF      R0+0
	MOVF       FARG_Display_Input_z+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVF       R8+0, 0
	MOVWF      R0+0
	MOVF       R8+1, 0
	MOVWF      R0+1
	MOVLW      48
	ADDWF      R0+0, 1
	MOVF       FLOC__Display_Input+0, 0
	MOVWF      FSR
	MOVF       R0+0, 0
	MOVWF      INDF+0
;ulra_regen2.c,31 :: 		Lcd_Out(x,y,text);
	MOVF       FARG_Display_Input_x+0, 0
	MOVWF      FARG_Lcd_Out_row+0
	MOVF       FARG_Display_Input_y+0, 0
	MOVWF      FARG_Lcd_Out_column+0
	MOVF       _text+0, 0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;ulra_regen2.c,32 :: 		}
L_end_Display_Input:
	RETURN
; end of _Display_Input

_serv:

;ulra_regen2.c,36 :: 		void serv(int a, int port, int look) /// а - грады(проценты)
;ulra_regen2.c,39 :: 		if(look==1)k=1;
	MOVLW      0
	XORWF      FARG_serv_look+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv50
	MOVLW      1
	XORWF      FARG_serv_look+0, 0
L__serv50:
	BTFSS      STATUS+0, 2
	GOTO       L_serv0
	MOVLW      1
	MOVWF      R7+0
	MOVLW      0
	MOVWF      R7+1
	GOTO       L_serv1
L_serv0:
;ulra_regen2.c,40 :: 		else k=15;
	MOVLW      15
	MOVWF      R7+0
	MOVLW      0
	MOVWF      R7+1
L_serv1:
;ulra_regen2.c,41 :: 		for(i = 0; i<k; i++)
	CLRF       R3+0
	CLRF       R3+1
L_serv2:
	MOVLW      128
	XORWF      R3+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      R7+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv51
	MOVF       R7+0, 0
	SUBWF      R3+0, 0
L__serv51:
	BTFSC      STATUS+0, 0
	GOTO       L_serv3
;ulra_regen2.c,43 :: 		if(port == 0) PORTC.F6 = 1;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv52
	MOVLW      0
	XORWF      FARG_serv_port+0, 0
L__serv52:
	BTFSS      STATUS+0, 2
	GOTO       L_serv5
	BSF        PORTC+0, 6
	GOTO       L_serv6
L_serv5:
;ulra_regen2.c,44 :: 		else if(port == 1) PORTC.F5 = 1;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv53
	MOVLW      1
	XORWF      FARG_serv_port+0, 0
L__serv53:
	BTFSS      STATUS+0, 2
	GOTO       L_serv7
	BSF        PORTC+0, 5
	GOTO       L_serv8
L_serv7:
;ulra_regen2.c,45 :: 		else if(port == 2) PORTB.F4 = 1;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv54
	MOVLW      2
	XORWF      FARG_serv_port+0, 0
L__serv54:
	BTFSS      STATUS+0, 2
	GOTO       L_serv9
	BSF        PORTB+0, 4
	GOTO       L_serv10
L_serv9:
;ulra_regen2.c,46 :: 		else if(port == 3) PORTB.F5 = 1;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv55
	MOVLW      3
	XORWF      FARG_serv_port+0, 0
L__serv55:
	BTFSS      STATUS+0, 2
	GOTO       L_serv11
	BSF        PORTB+0, 5
L_serv11:
L_serv10:
L_serv8:
L_serv6:
;ulra_regen2.c,48 :: 		delay_us(450);
	MOVLW      3
	MOVWF      R12+0
	MOVLW      235
	MOVWF      R13+0
L_serv12:
	DECFSZ     R13+0, 1
	GOTO       L_serv12
	DECFSZ     R12+0, 1
	GOTO       L_serv12
;ulra_regen2.c,49 :: 		if(a<=50)for(j = 0; j<a; j++)delay_us(14); //976/50
	MOVLW      128
	MOVWF      R0+0
	MOVLW      128
	XORWF      FARG_serv_a+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv56
	MOVF       FARG_serv_a+0, 0
	SUBLW      50
L__serv56:
	BTFSS      STATUS+0, 0
	GOTO       L_serv13
	CLRF       R5+0
	CLRF       R5+1
L_serv14:
	MOVLW      128
	XORWF      R5+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      FARG_serv_a+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv57
	MOVF       FARG_serv_a+0, 0
	SUBWF      R5+0, 0
L__serv57:
	BTFSC      STATUS+0, 0
	GOTO       L_serv15
	MOVLW      23
	MOVWF      R13+0
L_serv17:
	DECFSZ     R13+0, 1
	GOTO       L_serv17
	INCF       R5+0, 1
	BTFSC      STATUS+0, 2
	INCF       R5+1, 1
	GOTO       L_serv14
L_serv15:
	GOTO       L_serv18
L_serv13:
;ulra_regen2.c,52 :: 		delay_us(14*50+140);
	MOVLW      6
	MOVWF      R12+0
	MOVLW      115
	MOVWF      R13+0
L_serv19:
	DECFSZ     R13+0, 1
	GOTO       L_serv19
	DECFSZ     R12+0, 1
	GOTO       L_serv19
;ulra_regen2.c,53 :: 		for(j = 0; j<(a-50); j++)delay_us(15);
	CLRF       R5+0
	CLRF       R5+1
L_serv20:
	MOVLW      50
	SUBWF      FARG_serv_a+0, 0
	MOVWF      R1+0
	MOVLW      0
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      FARG_serv_a+1, 0
	MOVWF      R1+1
	MOVLW      128
	XORWF      R5+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      R1+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv58
	MOVF       R1+0, 0
	SUBWF      R5+0, 0
L__serv58:
	BTFSC      STATUS+0, 0
	GOTO       L_serv21
	MOVLW      24
	MOVWF      R13+0
L_serv23:
	DECFSZ     R13+0, 1
	GOTO       L_serv23
	NOP
	NOP
	INCF       R5+0, 1
	BTFSC      STATUS+0, 2
	INCF       R5+1, 1
	GOTO       L_serv20
L_serv21:
;ulra_regen2.c,54 :: 		}
L_serv18:
;ulra_regen2.c,55 :: 		if(port == 0) PORTC.F6 = 0;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv59
	MOVLW      0
	XORWF      FARG_serv_port+0, 0
L__serv59:
	BTFSS      STATUS+0, 2
	GOTO       L_serv24
	BCF        PORTC+0, 6
	GOTO       L_serv25
L_serv24:
;ulra_regen2.c,56 :: 		else if(port == 1) PORTC.F5 = 0;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv60
	MOVLW      1
	XORWF      FARG_serv_port+0, 0
L__serv60:
	BTFSS      STATUS+0, 2
	GOTO       L_serv26
	BCF        PORTC+0, 5
	GOTO       L_serv27
L_serv26:
;ulra_regen2.c,57 :: 		else if(port == 2) PORTB.F4 = 0;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv61
	MOVLW      2
	XORWF      FARG_serv_port+0, 0
L__serv61:
	BTFSS      STATUS+0, 2
	GOTO       L_serv28
	BCF        PORTB+0, 4
	GOTO       L_serv29
L_serv28:
;ulra_regen2.c,58 :: 		else if(port == 3) PORTB.F5 = 0;
	MOVLW      0
	XORWF      FARG_serv_port+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__serv62
	MOVLW      3
	XORWF      FARG_serv_port+0, 0
L__serv62:
	BTFSS      STATUS+0, 2
	GOTO       L_serv30
	BCF        PORTB+0, 5
L_serv30:
L_serv29:
L_serv27:
L_serv25:
;ulra_regen2.c,60 :: 		delay_ms(20);
	MOVLW      130
	MOVWF      R12+0
	MOVLW      221
	MOVWF      R13+0
L_serv31:
	DECFSZ     R13+0, 1
	GOTO       L_serv31
	DECFSZ     R12+0, 1
	GOTO       L_serv31
	NOP
	NOP
;ulra_regen2.c,41 :: 		for(i = 0; i<k; i++)
	INCF       R3+0, 1
	BTFSC      STATUS+0, 2
	INCF       R3+1, 1
;ulra_regen2.c,61 :: 		}
	GOTO       L_serv2
L_serv3:
;ulra_regen2.c,62 :: 		}
L_end_serv:
	RETURN
; end of _serv

_skan:

;ulra_regen2.c,64 :: 		int skan()
;ulra_regen2.c,66 :: 		int us = 0;
	CLRF       skan_us_L0+0
	CLRF       skan_us_L0+1
;ulra_regen2.c,67 :: 		PORTA.F5 = 1;
	BSF        PORTA+0, 5
;ulra_regen2.c,68 :: 		delay_us(10);
	MOVLW      16
	MOVWF      R13+0
L_skan32:
	DECFSZ     R13+0, 1
	GOTO       L_skan32
	NOP
;ulra_regen2.c,69 :: 		PORTA.F5 = 0;
	BCF        PORTA+0, 5
;ulra_regen2.c,70 :: 		while(!PORTC.F7);//{PORTB.F3 = 1;delay_ms(100);PORTB.F3 = 0; delay_ms(10);  }
L_skan33:
	BTFSC      PORTC+0, 7
	GOTO       L_skan34
	GOTO       L_skan33
L_skan34:
;ulra_regen2.c,71 :: 		while(PORTC.F7 != 0){delay_us(5);us = us + 5;}
L_skan35:
	BTFSS      PORTC+0, 7
	GOTO       L_skan36
	MOVLW      8
	MOVWF      R13+0
L_skan37:
	DECFSZ     R13+0, 1
	GOTO       L_skan37
	MOVLW      5
	ADDWF      skan_us_L0+0, 1
	BTFSC      STATUS+0, 0
	INCF       skan_us_L0+1, 1
	GOTO       L_skan35
L_skan36:
;ulra_regen2.c,73 :: 		return us/58;
	MOVLW      58
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       skan_us_L0+0, 0
	MOVWF      R0+0
	MOVF       skan_us_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
;ulra_regen2.c,74 :: 		}
L_end_skan:
	RETURN
; end of _skan

_init:

;ulra_regen2.c,79 :: 		void init()
;ulra_regen2.c,81 :: 		serv(50 + corr1, 1, 0);
	MOVLW      50
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      1
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,82 :: 		serv(10 + corr0, 0, 0);
	MOVLW      10
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	CLRF       FARG_serv_port+0
	CLRF       FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,83 :: 		serv(50 + corr3, 3, 0);
	MOVLW      54
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      3
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,85 :: 		serv(50 + corr2, 2, 0);
	MOVLW      52
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      2
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,86 :: 		}
L_end_init:
	RETURN
; end of _init

_aim:

;ulra_regen2.c,87 :: 		void aim(int tagw, int dist)
;ulra_regen2.c,89 :: 		serv(tagw, 3, 0);
	MOVF       FARG_aim_tagw+0, 0
	MOVWF      FARG_serv_a+0
	MOVF       FARG_aim_tagw+1, 0
	MOVWF      FARG_serv_a+1
	MOVLW      3
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,90 :: 		serv(50 + corr0, 0, 0);
	MOVLW      50
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	CLRF       FARG_serv_port+0
	CLRF       FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,91 :: 		serv(10 + corr1, 1, 0);
	MOVLW      10
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      1
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,92 :: 		serv(90 + corr1, 1, 0);
	MOVLW      90
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      1
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,93 :: 		serv(50 + corr1, 1, 0);
	MOVLW      50
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      1
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,94 :: 		serv(10 + corr0, 0, 0);
	MOVLW      10
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	CLRF       FARG_serv_port+0
	CLRF       FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,95 :: 		serv(50 + corr3, 3, 0);
	MOVLW      54
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      3
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,97 :: 		}
L_end_aim:
	RETURN
; end of _aim

_main:

;ulra_regen2.c,98 :: 		void main() {
;ulra_regen2.c,100 :: 		int i, minw, maxw, tagw, s, dist=300;
	MOVLW      44
	MOVWF      main_dist_L0+0
	MOVLW      1
	MOVWF      main_dist_L0+1
;ulra_regen2.c,101 :: 		Lcd_Init();                        // Initialize LCD
	CALL       _Lcd_Init+0
;ulra_regen2.c,102 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;ulra_regen2.c,103 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;ulra_regen2.c,106 :: 		ANSELH.F4 = 0;
	BCF        ANSELH+0, 4
;ulra_regen2.c,107 :: 		TRISB = 0;
	CLRF       TRISB+0
;ulra_regen2.c,108 :: 		TRISA.F4 = 1;
	BSF        TRISA+0, 4
;ulra_regen2.c,109 :: 		TRISA.F5 = 0;
	BCF        TRISA+0, 5
;ulra_regen2.c,110 :: 		TRISE.F1 = 1;
	BSF        TRISE+0, 1
;ulra_regen2.c,111 :: 		TRISC = 0;
	CLRF       TRISC+0
;ulra_regen2.c,112 :: 		TRISC.F7 = 1;
	BSF        TRISC+0, 7
;ulra_regen2.c,114 :: 		Sound_Init(&PORTC,0);
	MOVLW      PORTC+0
	MOVWF      FARG_Sound_Init_snd_port+0
	CLRF       FARG_Sound_Init_snd_pin+0
	CALL       _Sound_Init+0
;ulra_regen2.c,118 :: 		init();
	CALL       _init+0
;ulra_regen2.c,128 :: 		while(1)
L_main38:
;ulra_regen2.c,130 :: 		while(PORTA.F4);
L_main40:
	BTFSS      PORTA+0, 4
	GOTO       L_main41
	GOTO       L_main40
L_main41:
;ulra_regen2.c,131 :: 		dist = 900;
	MOVLW      132
	MOVWF      main_dist_L0+0
	MOVLW      3
	MOVWF      main_dist_L0+1
;ulra_regen2.c,135 :: 		lcd_out(1,1,"Cur:");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr2_ulra_regen2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;ulra_regen2.c,136 :: 		lcd_out(1,9,"Min:");
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      9
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr3_ulra_regen2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;ulra_regen2.c,137 :: 		lcd_out(2,9,"Tag:");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      9
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr4_ulra_regen2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;ulra_regen2.c,139 :: 		serv(10+corr2, 2, 0);
	MOVLW      12
	MOVWF      FARG_serv_a+0
	MOVLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      2
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,140 :: 		for(i = 10; i<90; i++)
	MOVLW      10
	MOVWF      main_i_L0+0
	MOVLW      0
	MOVWF      main_i_L0+1
L_main42:
	MOVLW      128
	XORWF      main_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main67
	MOVLW      90
	SUBWF      main_i_L0+0, 0
L__main67:
	BTFSC      STATUS+0, 0
	GOTO       L_main43
;ulra_regen2.c,142 :: 		serv(i+corr2, 2, 1);
	MOVLW      2
	ADDWF      main_i_L0+0, 0
	MOVWF      FARG_serv_a+0
	MOVF       main_i_L0+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      2
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	MOVLW      1
	MOVWF      FARG_serv_look+0
	MOVLW      0
	MOVWF      FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,144 :: 		s = skan();
	CALL       _skan+0
	MOVF       R0+0, 0
	MOVWF      main_s_L0+0
	MOVF       R0+1, 0
	MOVWF      main_s_L0+1
;ulra_regen2.c,145 :: 		if(s<0) s = 255;
	MOVLW      128
	XORWF      R0+1, 0
	MOVWF      R2+0
	MOVLW      128
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main68
	MOVLW      0
	SUBWF      R0+0, 0
L__main68:
	BTFSC      STATUS+0, 0
	GOTO       L_main45
	MOVLW      255
	MOVWF      main_s_L0+0
	CLRF       main_s_L0+1
L_main45:
;ulra_regen2.c,146 :: 		if(s<dist-7){dist = s; tagw = i; Display_Input(1,13,s);}
	MOVLW      7
	SUBWF      main_dist_L0+0, 0
	MOVWF      R1+0
	MOVLW      0
	BTFSS      STATUS+0, 0
	ADDLW      1
	SUBWF      main_dist_L0+1, 0
	MOVWF      R1+1
	MOVLW      128
	XORWF      main_s_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      R1+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main69
	MOVF       R1+0, 0
	SUBWF      main_s_L0+0, 0
L__main69:
	BTFSC      STATUS+0, 0
	GOTO       L_main46
	MOVF       main_s_L0+0, 0
	MOVWF      main_dist_L0+0
	MOVF       main_s_L0+1, 0
	MOVWF      main_dist_L0+1
	MOVF       main_i_L0+0, 0
	MOVWF      main_tagw_L0+0
	MOVF       main_i_L0+1, 0
	MOVWF      main_tagw_L0+1
	MOVLW      1
	MOVWF      FARG_Display_Input_x+0
	MOVLW      0
	MOVWF      FARG_Display_Input_x+1
	MOVLW      13
	MOVWF      FARG_Display_Input_y+0
	MOVLW      0
	MOVWF      FARG_Display_Input_y+1
	MOVF       main_s_L0+0, 0
	MOVWF      FARG_Display_Input_z+0
	MOVF       main_s_L0+1, 0
	MOVWF      FARG_Display_Input_z+1
	CALL       _Display_Input+0
L_main46:
;ulra_regen2.c,148 :: 		Display_Input(1,5,s);
	MOVLW      1
	MOVWF      FARG_Display_Input_x+0
	MOVLW      0
	MOVWF      FARG_Display_Input_x+1
	MOVLW      5
	MOVWF      FARG_Display_Input_y+0
	MOVLW      0
	MOVWF      FARG_Display_Input_y+1
	MOVF       main_s_L0+0, 0
	MOVWF      FARG_Display_Input_z+0
	MOVF       main_s_L0+1, 0
	MOVWF      FARG_Display_Input_z+1
	CALL       _Display_Input+0
;ulra_regen2.c,150 :: 		delay_ms(25);
	MOVLW      163
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main47:
	DECFSZ     R13+0, 1
	GOTO       L_main47
	DECFSZ     R12+0, 1
	GOTO       L_main47
;ulra_regen2.c,140 :: 		for(i = 10; i<90; i++)
	INCF       main_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       main_i_L0+1, 1
;ulra_regen2.c,151 :: 		}
	GOTO       L_main42
L_main43:
;ulra_regen2.c,153 :: 		tagw = 50;
	MOVLW      50
	MOVWF      main_tagw_L0+0
	MOVLW      0
	MOVWF      main_tagw_L0+1
;ulra_regen2.c,154 :: 		Display_Input(2,13,tagw);
	MOVLW      2
	MOVWF      FARG_Display_Input_x+0
	MOVLW      0
	MOVWF      FARG_Display_Input_x+1
	MOVLW      13
	MOVWF      FARG_Display_Input_y+0
	MOVLW      0
	MOVWF      FARG_Display_Input_y+1
	MOVLW      50
	MOVWF      FARG_Display_Input_z+0
	MOVLW      0
	MOVWF      FARG_Display_Input_z+1
	CALL       _Display_Input+0
;ulra_regen2.c,155 :: 		lcd_out(2, 16, "'");
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      16
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      ?lstr5_ulra_regen2+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;ulra_regen2.c,156 :: 		serv(tagw+corr2, 2, 0);
	MOVLW      2
	ADDWF      main_tagw_L0+0, 0
	MOVWF      FARG_serv_a+0
	MOVF       main_tagw_L0+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	ADDLW      0
	MOVWF      FARG_serv_a+1
	MOVLW      2
	MOVWF      FARG_serv_port+0
	MOVLW      0
	MOVWF      FARG_serv_port+1
	CLRF       FARG_serv_look+0
	CLRF       FARG_serv_look+1
	CALL       _serv+0
;ulra_regen2.c,158 :: 		s = skan();
	CALL       _skan+0
	MOVF       R0+0, 0
	MOVWF      main_s_L0+0
	MOVF       R0+1, 0
	MOVWF      main_s_L0+1
;ulra_regen2.c,166 :: 		aim(tagw+4,dist);
	MOVLW      4
	ADDWF      main_tagw_L0+0, 0
	MOVWF      FARG_aim_tagw+0
	MOVF       main_tagw_L0+1, 0
	BTFSC      STATUS+0, 0
	ADDLW      1
	MOVWF      FARG_aim_tagw+1
	MOVF       main_dist_L0+0, 0
	MOVWF      FARG_aim_dist+0
	MOVF       main_dist_L0+1, 0
	MOVWF      FARG_aim_dist+1
	CALL       _aim+0
;ulra_regen2.c,167 :: 		init();
	CALL       _init+0
;ulra_regen2.c,169 :: 		}
	GOTO       L_main38
;ulra_regen2.c,180 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
