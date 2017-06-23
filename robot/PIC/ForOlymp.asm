
_getFromSensor:

;ForOlymp.c,33 :: 		int getFromSensor(int sensor)  // 0- left
;ForOlymp.c,35 :: 		if(sensor==0)
	MOVLW      0
	XORWF      FARG_getFromSensor_sensor+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__getFromSensor43
	MOVLW      0
	XORWF      FARG_getFromSensor_sensor+0, 0
L__getFromSensor43:
	BTFSS      STATUS+0, 2
	GOTO       L_getFromSensor0
;ForOlymp.c,36 :: 		return (int)(ADC_READ(3)/3.95);
	MOVLW      3
	MOVWF      FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVLW      205
	MOVWF      R4+0
	MOVLW      204
	MOVWF      R4+1
	MOVLW      124
	MOVWF      R4+2
	MOVLW      128
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _double2int+0
	GOTO       L_end_getFromSensor
L_getFromSensor0:
;ForOlymp.c,37 :: 		else if(sensor==1)
	MOVLW      0
	XORWF      FARG_getFromSensor_sensor+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__getFromSensor44
	MOVLW      1
	XORWF      FARG_getFromSensor_sensor+0, 0
L__getFromSensor44:
	BTFSS      STATUS+0, 2
	GOTO       L_getFromSensor2
;ForOlymp.c,38 :: 		return (int)(ADC_READ(0)/6.72);       /// даёт 100% при белом, на нормальной высоте, при чёрном - меньше
	CLRF       FARG_ADC_Read_channel+0
	CALL       _ADC_Read+0
	CALL       _word2double+0
	MOVLW      61
	MOVWF      R4+0
	MOVLW      10
	MOVWF      R4+1
	MOVLW      87
	MOVWF      R4+2
	MOVLW      129
	MOVWF      R4+3
	CALL       _Div_32x32_FP+0
	CALL       _double2int+0
	GOTO       L_end_getFromSensor
L_getFromSensor2:
;ForOlymp.c,39 :: 		}
L_end_getFromSensor:
	RETURN
; end of _getFromSensor

_skan:

;ForOlymp.c,43 :: 		int skan()
;ForOlymp.c,45 :: 		int us = 0;
	CLRF       skan_us_L0+0
	CLRF       skan_us_L0+1
;ForOlymp.c,46 :: 		PORTA.F5 = 1;
	BSF        PORTA+0, 5
;ForOlymp.c,47 :: 		delay_us(10);
	MOVLW      16
	MOVWF      R13+0
L_skan3:
	DECFSZ     R13+0, 1
	GOTO       L_skan3
	NOP
;ForOlymp.c,48 :: 		PORTA.F5 = 0;
	BCF        PORTA+0, 5
;ForOlymp.c,49 :: 		while(!PORTC.F7);//{PORTB.F3 = 1;delay_ms(100);PORTB.F3 = 0; delay_ms(10);  }
L_skan4:
	BTFSC      PORTC+0, 7
	GOTO       L_skan5
	GOTO       L_skan4
L_skan5:
;ForOlymp.c,50 :: 		while(PORTC.F7 != 0){delay_us(5);us = us + 5;}
L_skan6:
	BTFSS      PORTC+0, 7
	GOTO       L_skan7
	MOVLW      8
	MOVWF      R13+0
L_skan8:
	DECFSZ     R13+0, 1
	GOTO       L_skan8
	MOVLW      5
	ADDWF      skan_us_L0+0, 1
	BTFSC      STATUS+0, 0
	INCF       skan_us_L0+1, 1
	GOTO       L_skan6
L_skan7:
;ForOlymp.c,53 :: 		if(us/58>0 && us/58<255){ return us/58;}
	MOVLW      58
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       skan_us_L0+0, 0
	MOVWF      R0+0
	MOVF       skan_us_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVLW      128
	MOVWF      R2+0
	MOVLW      128
	XORWF      R0+1, 0
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__skan46
	MOVF       R0+0, 0
	SUBLW      0
L__skan46:
	BTFSC      STATUS+0, 0
	GOTO       L_skan11
	MOVLW      58
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       skan_us_L0+0, 0
	MOVWF      R0+0
	MOVF       skan_us_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	MOVLW      128
	XORWF      R0+1, 0
	MOVWF      R2+0
	MOVLW      128
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__skan47
	MOVLW      255
	SUBWF      R0+0, 0
L__skan47:
	BTFSC      STATUS+0, 0
	GOTO       L_skan11
L__skan38:
	MOVLW      58
	MOVWF      R4+0
	MOVLW      0
	MOVWF      R4+1
	MOVF       skan_us_L0+0, 0
	MOVWF      R0+0
	MOVF       skan_us_L0+1, 0
	MOVWF      R0+1
	CALL       _Div_16x16_S+0
	GOTO       L_end_skan
L_skan11:
;ForOlymp.c,54 :: 		else { return 255;}
	MOVLW      255
	MOVWF      R0+0
	CLRF       R0+1
;ForOlymp.c,55 :: 		}
L_end_skan:
	RETURN
; end of _skan

_RotateR:

;ForOlymp.c,56 :: 		void RotateR(int gr)
;ForOlymp.c,59 :: 		Right();
	CALL       _Right+0
;ForOlymp.c,60 :: 		for(i = 0; i<gr; i++) delay_us(7590);
	CLRF       RotateR_i_L0+0
	CLRF       RotateR_i_L0+1
L_RotateR13:
	MOVLW      128
	XORWF      RotateR_i_L0+1, 0
	MOVWF      R0+0
	MOVLW      128
	XORWF      FARG_RotateR_gr+1, 0
	SUBWF      R0+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__RotateR49
	MOVF       FARG_RotateR_gr+0, 0
	SUBWF      RotateR_i_L0+0, 0
L__RotateR49:
	BTFSC      STATUS+0, 0
	GOTO       L_RotateR14
	MOVLW      50
	MOVWF      R12+0
	MOVLW      71
	MOVWF      R13+0
L_RotateR16:
	DECFSZ     R13+0, 1
	GOTO       L_RotateR16
	DECFSZ     R12+0, 1
	GOTO       L_RotateR16
	NOP
	NOP
	INCF       RotateR_i_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       RotateR_i_L0+1, 1
	GOTO       L_RotateR13
L_RotateR14:
;ForOlymp.c,61 :: 		Stop();
	CALL       _Stop+0
;ForOlymp.c,62 :: 		}
L_end_RotateR:
	RETURN
; end of _RotateR

_main:

;ForOlymp.c,70 :: 		void main() {
;ForOlymp.c,72 :: 		int i, adc, minw, maxw, tagw, s, dist=300;
;ForOlymp.c,73 :: 		int last0 = 0, last1 = 0;
;ForOlymp.c,74 :: 		int lastvec = 0;
;ForOlymp.c,76 :: 		Lcd_Init();                        // Initialize LCD
	CALL       _Lcd_Init+0
;ForOlymp.c,77 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;ForOlymp.c,78 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;ForOlymp.c,81 :: 		TRISA  = 0xFF;                   // PORTA ==> input
	MOVLW      255
	MOVWF      TRISA+0
;ForOlymp.c,82 :: 		ANSEL = 0xFF;                    // PORTA ==> Analog
	MOVLW      255
	MOVWF      ANSEL+0
;ForOlymp.c,83 :: 		ANSELH = 0x00 ;                       // Set PORTB => Digital
	CLRF       ANSELH+0
;ForOlymp.c,84 :: 		TRISC.F7 = 1;
	BSF        TRISC+0, 7
;ForOlymp.c,85 :: 		TRISA.F5 = 0; //вход
	BCF        TRISA+0, 5
;ForOlymp.c,89 :: 		TRISB.F1=0;TRISB.F2=0;              // Motor B 2A,Motor B 2B
	BCF        TRISB+0, 1
	BCF        TRISB+0, 2
;ForOlymp.c,90 :: 		TRISD.F0=0;TRISD.F1=0;              // Motor A 1A,MOtor A 1B
	BCF        TRISD+0, 0
	BCF        TRISD+0, 1
;ForOlymp.c,91 :: 		TRISC.F1=0;TRISC.F2=0;              // Motor B 2E,Motor A 1E
	BCF        TRISC+0, 1
	BCF        TRISC+0, 2
;ForOlymp.c,94 :: 		Sound_Init(&PORTC,0);
	MOVLW      PORTC+0
	MOVWF      FARG_Sound_Init_snd_port+0
	CLRF       FARG_Sound_Init_snd_pin+0
	CALL       _Sound_Init+0
;ForOlymp.c,95 :: 		Stop();
	CALL       _Stop+0
;ForOlymp.c,99 :: 		while(PORTA.f4);
L_main17:
	BTFSS      PORTA+0, 4
	GOTO       L_main18
	GOTO       L_main17
L_main18:
;ForOlymp.c,100 :: 		delay_ms(500);
	MOVLW      13
	MOVWF      R11+0
	MOVLW      175
	MOVWF      R12+0
	MOVLW      182
	MOVWF      R13+0
L_main19:
	DECFSZ     R13+0, 1
	GOTO       L_main19
	DECFSZ     R12+0, 1
	GOTO       L_main19
	DECFSZ     R11+0, 1
	GOTO       L_main19
	NOP
;ForOlymp.c,101 :: 		sound_play(500,500);
	MOVLW      244
	MOVWF      FARG_Sound_Play_freq_in_hz+0
	MOVLW      1
	MOVWF      FARG_Sound_Play_freq_in_hz+1
	MOVLW      244
	MOVWF      FARG_Sound_Play_duration_ms+0
	MOVLW      1
	MOVWF      FARG_Sound_Play_duration_ms+1
	CALL       _Sound_Play+0
;ForOlymp.c,111 :: 		Forward();
	CALL       _Forward+0
;ForOlymp.c,112 :: 		while(skan()>4)
L_main20:
	CALL       _skan+0
	MOVLW      128
	MOVWF      R2+0
	MOVLW      128
	XORWF      R0+1, 0
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main51
	MOVF       R0+0, 0
	SUBLW      4
L__main51:
	BTFSC      STATUS+0, 0
	GOTO       L_main21
;ForOlymp.c,114 :: 		if(getFromSensor(0)>=80 && getFromSensor(1)>=80)      // при обоих белых
	CLRF       FARG_getFromSensor_sensor+0
	CLRF       FARG_getFromSensor_sensor+1
	CALL       _getFromSensor+0
	MOVLW      128
	XORWF      R0+1, 0
	MOVWF      R2+0
	MOVLW      128
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main52
	MOVLW      80
	SUBWF      R0+0, 0
L__main52:
	BTFSS      STATUS+0, 0
	GOTO       L_main24
	MOVLW      1
	MOVWF      FARG_getFromSensor_sensor+0
	MOVLW      0
	MOVWF      FARG_getFromSensor_sensor+1
	CALL       _getFromSensor+0
	MOVLW      128
	XORWF      R0+1, 0
	MOVWF      R2+0
	MOVLW      128
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main53
	MOVLW      80
	SUBWF      R0+0, 0
L__main53:
	BTFSS      STATUS+0, 0
	GOTO       L_main24
L__main41:
;ForOlymp.c,116 :: 		Forward();
	CALL       _Forward+0
;ForOlymp.c,117 :: 		}
	GOTO       L_main25
L_main24:
;ForOlymp.c,118 :: 		else if(getFromSensor(0)>=80 && getFromSensor(1)<=60) // линия на правом
	CLRF       FARG_getFromSensor_sensor+0
	CLRF       FARG_getFromSensor_sensor+1
	CALL       _getFromSensor+0
	MOVLW      128
	XORWF      R0+1, 0
	MOVWF      R2+0
	MOVLW      128
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main54
	MOVLW      80
	SUBWF      R0+0, 0
L__main54:
	BTFSS      STATUS+0, 0
	GOTO       L_main28
	MOVLW      1
	MOVWF      FARG_getFromSensor_sensor+0
	MOVLW      0
	MOVWF      FARG_getFromSensor_sensor+1
	CALL       _getFromSensor+0
	MOVLW      128
	MOVWF      R2+0
	MOVLW      128
	XORWF      R0+1, 0
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main55
	MOVF       R0+0, 0
	SUBLW      60
L__main55:
	BTFSS      STATUS+0, 0
	GOTO       L_main28
L__main40:
;ForOlymp.c,120 :: 		Right();
	CALL       _Right+0
;ForOlymp.c,121 :: 		}
	GOTO       L_main29
L_main28:
;ForOlymp.c,122 :: 		else if(getFromSensor(0)<=60 && getFromSensor(1)>=80) // линия на левом
	CLRF       FARG_getFromSensor_sensor+0
	CLRF       FARG_getFromSensor_sensor+1
	CALL       _getFromSensor+0
	MOVLW      128
	MOVWF      R2+0
	MOVLW      128
	XORWF      R0+1, 0
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main56
	MOVF       R0+0, 0
	SUBLW      60
L__main56:
	BTFSS      STATUS+0, 0
	GOTO       L_main32
	MOVLW      1
	MOVWF      FARG_getFromSensor_sensor+0
	MOVLW      0
	MOVWF      FARG_getFromSensor_sensor+1
	CALL       _getFromSensor+0
	MOVLW      128
	XORWF      R0+1, 0
	MOVWF      R2+0
	MOVLW      128
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main57
	MOVLW      80
	SUBWF      R0+0, 0
L__main57:
	BTFSS      STATUS+0, 0
	GOTO       L_main32
L__main39:
;ForOlymp.c,124 :: 		Left();
	CALL       _Left+0
;ForOlymp.c,125 :: 		}
	GOTO       L_main33
L_main32:
;ForOlymp.c,128 :: 		Forward();
	CALL       _Forward+0
;ForOlymp.c,129 :: 		}
L_main33:
L_main29:
L_main25:
;ForOlymp.c,130 :: 		delay_ms(50);
	MOVLW      2
	MOVWF      R11+0
	MOVLW      69
	MOVWF      R12+0
	MOVLW      169
	MOVWF      R13+0
L_main34:
	DECFSZ     R13+0, 1
	GOTO       L_main34
	DECFSZ     R12+0, 1
	GOTO       L_main34
	DECFSZ     R11+0, 1
	GOTO       L_main34
	NOP
	NOP
;ForOlymp.c,131 :: 		Forward();
	CALL       _Forward+0
;ForOlymp.c,132 :: 		delay_ms(100);
	MOVLW      3
	MOVWF      R11+0
	MOVLW      138
	MOVWF      R12+0
	MOVLW      85
	MOVWF      R13+0
L_main35:
	DECFSZ     R13+0, 1
	GOTO       L_main35
	DECFSZ     R12+0, 1
	GOTO       L_main35
	DECFSZ     R11+0, 1
	GOTO       L_main35
	NOP
	NOP
;ForOlymp.c,134 :: 		}
	GOTO       L_main20
L_main21:
;ForOlymp.c,135 :: 		Stop();
	CALL       _Stop+0
;ForOlymp.c,136 :: 		RotateR(540);
	MOVLW      28
	MOVWF      FARG_RotateR_gr+0
	MOVLW      2
	MOVWF      FARG_RotateR_gr+1
	CALL       _RotateR+0
;ForOlymp.c,137 :: 		Forward();
	CALL       _Forward+0
;ForOlymp.c,138 :: 		while(skan()>3);
L_main36:
	CALL       _skan+0
	MOVLW      128
	MOVWF      R2+0
	MOVLW      128
	XORWF      R0+1, 0
	SUBWF      R2+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L__main58
	MOVF       R0+0, 0
	SUBLW      3
L__main58:
	BTFSC      STATUS+0, 0
	GOTO       L_main37
	GOTO       L_main36
L_main37:
;ForOlymp.c,141 :: 		Stop();
	CALL       _Stop+0
;ForOlymp.c,169 :: 		}
L_end_main:
	GOTO       $+0
; end of _main

_Right:

;ForOlymp.c,171 :: 		void Right()
;ForOlymp.c,173 :: 		PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
	BSF        PORTC+0, 1
	BSF        PORTC+0, 2
;ForOlymp.c,174 :: 		PORTD.F0 =0;PORTD.F1 =1;      // left forward
	BCF        PORTD+0, 0
	BSF        PORTD+0, 1
;ForOlymp.c,175 :: 		PORTB.F1 =1;PORTB.F2 =0;      // right backward
	BSF        PORTB+0, 1
	BCF        PORTB+0, 2
;ForOlymp.c,176 :: 		}
L_end_Right:
	RETURN
; end of _Right

_Left:

;ForOlymp.c,177 :: 		void Left()
;ForOlymp.c,179 :: 		PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
	BSF        PORTC+0, 1
	BSF        PORTC+0, 2
;ForOlymp.c,180 :: 		PORTB.F1 =0;PORTB.F2 =1;      // right forward
	BCF        PORTB+0, 1
	BSF        PORTB+0, 2
;ForOlymp.c,181 :: 		PORTD.F0 =1;PORTD.F1 =0;      // left backward
	BSF        PORTD+0, 0
	BCF        PORTD+0, 1
;ForOlymp.c,182 :: 		}
L_end_Left:
	RETURN
; end of _Left

_Forward:

;ForOlymp.c,183 :: 		void Forward()
;ForOlymp.c,185 :: 		PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
	BSF        PORTC+0, 1
	BSF        PORTC+0, 2
;ForOlymp.c,186 :: 		PORTB.F1 =0;PORTB.F2 =1;      // right forward
	BCF        PORTB+0, 1
	BSF        PORTB+0, 2
;ForOlymp.c,187 :: 		PORTD.F0 =0;PORTD.F1 =1;      // left forward
	BCF        PORTD+0, 0
	BSF        PORTD+0, 1
;ForOlymp.c,188 :: 		}
L_end_Forward:
	RETURN
; end of _Forward

_Backward:

;ForOlymp.c,189 :: 		void Backward()
;ForOlymp.c,191 :: 		PORTC.F1=1;PORTC.F2=1;              // Enable Motor left,Enable Motor right
	BSF        PORTC+0, 1
	BSF        PORTC+0, 2
;ForOlymp.c,192 :: 		PORTD.F0 =1;PORTD.F1 =0;      // left backward
	BSF        PORTD+0, 0
	BCF        PORTD+0, 1
;ForOlymp.c,193 :: 		PORTB.F1 =1;PORTB.F2 =0;      // right backward
	BSF        PORTB+0, 1
	BCF        PORTB+0, 2
;ForOlymp.c,194 :: 		}
L_end_Backward:
	RETURN
; end of _Backward

_Stop:

;ForOlymp.c,195 :: 		void Stop()
;ForOlymp.c,197 :: 		PORTC.F1 =0;PORTC.F2 =0;      //deinit
	BCF        PORTC+0, 1
	BCF        PORTC+0, 2
;ForOlymp.c,198 :: 		}
L_end_Stop:
	RETURN
; end of _Stop
