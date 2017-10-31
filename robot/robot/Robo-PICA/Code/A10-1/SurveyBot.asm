;  ASM code generated by mikroVirtualMachine for PIC - V. 8.2.0.0
;  Date/Time: 4/6/2008 15:02:33
;  Info: http://www.mikroe.com


; ADDRESS	OPCODE	ASM
; ----------------------------------------------
$0000	$2804			GOTO	_main
$0427	$	_Delay_1us:
;delays.c,7 :: 		void Delay_1us() {
;delays.c,8 :: 		Delay_us(1);
$0427	$3001			MOVLW	1
$0428	$1303			BCF	STATUS, RP1
$0429	$1283			BCF	STATUS, RP0
$042A	$00FA			MOVWF	STACK_10
$042B	$0BFA			DECFSZ	STACK_10, F
$042C	$2C2B			GOTO	$-1
$042D	$0000			NOP
;delays.c,9 :: 		}
$042E	$0008			RETURN
$040D	$	_Delay_5500us:
;delays.c,31 :: 		void Delay_5500us() {
;delays.c,32 :: 		Delay_us(5500);
$040D	$3024			MOVLW	36
$040E	$1303			BCF	STATUS, RP1
$040F	$1283			BCF	STATUS, RP0
$0410	$00FB			MOVWF	STACK_11
$0411	$30FF			MOVLW	255
$0412	$00FA			MOVWF	STACK_10
$0413	$0BFB			DECFSZ	STACK_11, F
$0414	$2C16			GOTO	$+2
$0415	$2C19			GOTO	$+4
$0416	$0BFA			DECFSZ	STACK_10, F
$0417	$2C16			GOTO	$-1
$0418	$2C13			GOTO	$-5
$0419	$309E			MOVLW	158
$041A	$00FA			MOVWF	STACK_10
$041B	$0BFA			DECFSZ	STACK_10, F
$041C	$2C1B			GOTO	$-1
;delays.c,33 :: 		}
$041D	$0008			RETURN
$044F	$	_Delay_50us:
;delays.c,19 :: 		void Delay_50us() {
;delays.c,20 :: 		Delay_us(50);
$044F	$3053			MOVLW	83
$0450	$1303			BCF	STATUS, RP1
$0451	$1283			BCF	STATUS, RP0
$0452	$00FA			MOVWF	STACK_10
$0453	$0BFA			DECFSZ	STACK_10, F
$0454	$2C53			GOTO	$-1
;delays.c,21 :: 		}
$0455	$0008			RETURN
$0305	$	_Mul_16x16_S:
$0305	$1303			BCF	STATUS, RP1
$0306	$1283			BCF	STATUS, RP0
$0307	$01FB			CLRF	STACK_11
$0308	$01FA			CLRF	STACK_10
$0309	$01F9			CLRF	STACK_9
$030A	$3080			MOVLW	128
$030B	$00F8			MOVWF	STACK_8
$030C	$01FD			CLRF	STACK_13
$030D	$1FF1			BTFSS	STACK_1, 7
$030E	$2B15			GOTO	$+7
$030F	$09F1			COMF	STACK_1, F
$0310	$09F0			COMF	STACK_0, F
$0311	$0AF0			INCF	STACK_0, F
$0312	$1903			BTFSC	STATUS, Z
$0313	$0AF1			INCF	STACK_1, F
$0314	$0AFD			INCF	STACK_13, F
$0315	$1FF5			BTFSS	STACK_5, 7
$0316	$2B1D			GOTO	$+7
$0317	$09F5			COMF	STACK_5, F
$0318	$09F4			COMF	STACK_4, F
$0319	$0AF4			INCF	STACK_4, F
$031A	$1903			BTFSC	STATUS, Z
$031B	$0AF5			INCF	STACK_5, F
$031C	$0AFD			INCF	STACK_13, F
$031D	$0CF1			RRF	STACK_1, F
$031E	$0CF0			RRF	STACK_0, F
$031F	$1C03			BTFSS	STATUS, C
$0320	$2B2A			GOTO	$+10
$0321	$0874			MOVF	STACK_4, W
$0322	$07F9			ADDWF	STACK_9, F
$0323	$0875			MOVF	STACK_5, W
$0324	$1803			BTFSC	STATUS, C
$0325	$0F75			INCFSZ	STACK_5, W
$0326	$07FA			ADDWF	STACK_10, F
$0327	$1803			BTFSC	STATUS, C
$0328	$0AFB			INCF	STACK_11, F
$0329	$1003			BCF	STATUS, C
$032A	$1FF0			BTFSS	STACK_0, 7
$032B	$2B32			GOTO	$+7
$032C	$0874			MOVF	STACK_4, W
$032D	$07FA			ADDWF	STACK_10, F
$032E	$1803			BTFSC	STATUS, C
$032F	$0AFB			INCF	STACK_11, F
$0330	$0875			MOVF	STACK_5, W
$0331	$07FB			ADDWF	STACK_11, F
$0332	$0CFB			RRF	STACK_11, F
$0333	$0CFA			RRF	STACK_10, F
$0334	$0CF9			RRF	STACK_9, F
$0335	$0CF8			RRF	STACK_8, F
$0336	$1C03			BTFSS	STATUS, C
$0337	$2B1D			GOTO	$-26
$0338	$1C7D			BTFSS	STACK_13, 0
$0339	$2B45			GOTO	$+12
$033A	$09FB			COMF	STACK_11, F
$033B	$09FA			COMF	STACK_10, F
$033C	$09F9			COMF	STACK_9, F
$033D	$09F8			COMF	STACK_8, F
$033E	$0AF8			INCF	STACK_8, F
$033F	$1903			BTFSC	STATUS, Z
$0340	$0AF9			INCF	STACK_9, F
$0341	$1903			BTFSC	STATUS, Z
$0342	$0AFA			INCF	STACK_10, F
$0343	$1903			BTFSC	STATUS, Z
$0344	$0AFB			INCF	STACK_11, F
$0345	$087B			MOVF	STACK_11, W
$0346	$00F3			MOVWF	STACK_3
$0347	$087A			MOVF	STACK_10, W
$0348	$00F2			MOVWF	STACK_2
$0349	$0879			MOVF	STACK_9, W
$034A	$00F1			MOVWF	STACK_1
$034B	$0878			MOVF	STACK_8, W
$034C	$00F0			MOVWF	STACK_0
$034D	$0000			NOP
$034E	$0008			RETURN
$0284	$	_Lcd_Cmd:
$0284	$1303			BCF	STATUS, RP1
$0285	$1283			BCF	STATUS, RP0
$0286	$0820			MOVF	LCD_port_address, 0
$0287	$0084			MOVWF	FSR
$0288	$0869			MOVF	FARG_Lcd_Cmd+0, 0
$0289	$1903			BTFSC	STATUS, Z
$028A	$2A8B			GOTO	L_Lcd_Cmd_0
$028B	$	L_Lcd_Cmd_0:
$028B	$1180			BCF	INDF, ___ENABLE
$028C	$1100			BCF	INDF, ___RS
$028D	$1380			BCF	INDF, ___DB7
$028E	$1300			BCF	INDF, ___DB6
$028F	$1280			BCF	INDF, ___DB5
$0290	$1200			BCF	INDF, ___DB4
$0291	$1BE9			BTFSC	FARG_Lcd_Cmd+0, 7
$0292	$1780			BSF	INDF, ___DB7
$0293	$1B69			BTFSC	FARG_Lcd_Cmd+0, 6
$0294	$1700			BSF	INDF, ___DB6
$0295	$1AE9			BTFSC	FARG_Lcd_Cmd+0, 5
$0296	$1680			BSF	INDF, ___DB5
$0297	$1A69			BTFSC	FARG_Lcd_Cmd+0, 4
$0298	$1600			BSF	INDF, ___DB4
$0299	$0821			MOVF	LCD_cmd_status, 0
$029A	$1903			BTFSC	STATUS, Z
$029B	$2A9E			GOTO	L_Lcd_Cmd_1
$029C	$1100			BCF	INDF, ___RS
$029D	$2A9F			GOTO	L_Lcd_Cmd_2
$029E	$	L_Lcd_Cmd_1:
$029E	$1500			BSF	INDF, ___RS
$029F	$	L_Lcd_Cmd_2:
$029F	$1580			BSF	INDF, ___ENABLE
$02A0	$2427			CALL	_Delay_1us
$02A1	$0869			MOVF	FARG_Lcd_Cmd+0, 0
$02A2	$1903			BTFSC	STATUS, Z
$02A3	$2AA4			GOTO	L_Lcd_Cmd_3
$02A4	$	L_Lcd_Cmd_3:
$02A4	$1180			BCF	INDF, ___ENABLE
$02A5	$1100			BCF	INDF, ___RS
$02A6	$1380			BCF	INDF, ___DB7
$02A7	$1300			BCF	INDF, ___DB6
$02A8	$1280			BCF	INDF, ___DB5
$02A9	$1200			BCF	INDF, ___DB4
$02AA	$19E9			BTFSC	FARG_Lcd_Cmd+0, 3
$02AB	$1780			BSF	INDF, ___DB7
$02AC	$1969			BTFSC	FARG_Lcd_Cmd+0, 2
$02AD	$1700			BSF	INDF, ___DB6
$02AE	$18E9			BTFSC	FARG_Lcd_Cmd+0, 1
$02AF	$1680			BSF	INDF, ___DB5
$02B0	$1869			BTFSC	FARG_Lcd_Cmd+0, 0
$02B1	$1600			BSF	INDF, ___DB4
$02B2	$0821			MOVF	LCD_cmd_status, 0
$02B3	$1903			BTFSC	STATUS, Z
$02B4	$2AB7			GOTO	L_Lcd_Cmd_4
$02B5	$1100			BCF	INDF, ___RS
$02B6	$2AB8			GOTO	L_Lcd_Cmd_5
$02B7	$	L_Lcd_Cmd_4:
$02B7	$1500			BSF	INDF, ___RS
$02B8	$	L_Lcd_Cmd_5:
$02B8	$1580			BSF	INDF, ___ENABLE
$02B9	$2427			CALL	_Delay_1us
$02BA	$1180			BCF	INDF, ___ENABLE
$02BB	$0821			MOVF	LCD_cmd_status, 0
$02BC	$1903			BTFSC	STATUS, Z
$02BD	$2AC0			GOTO	L_Lcd_Cmd_6
$02BE	$240D			CALL	_Delay_5500us
$02BF	$2AC1			GOTO	L_Lcd_Cmd_7
$02C0	$	L_Lcd_Cmd_6:
$02C0	$244F			CALL	_Delay_50us
$02C1	$	L_Lcd_Cmd_7:
$02C1	$0008			RETURN
$045C	$	_PWM1_Init:
$045C	$1303			BCF	STATUS, RP1
$045D	$1283			BCF	STATUS, RP0
$045E	$0195			CLRF	CCPR1L, 1
$045F	$1217			BCF	CCP1CON, 4
$0460	$1297			BCF	CCP1CON, 5
$0461	$0008			RETURN
$0456	$	_PWM2_Init:
$0456	$1303			BCF	STATUS, RP1
$0457	$1283			BCF	STATUS, RP0
$0458	$019B			CLRF	CCPR2L, 1
$0459	$121D			BCF	CCP2CON, 4
$045A	$129D			BCF	CCP2CON, 5
$045B	$0008			RETURN
$034F	$	_PWM1_Change_Duty:
$034F	$1303			BCF	STATUS, RP1
$0350	$1683			BSF	STATUS, RP0
$0351	$0812			MOVF	PR2, 0
$0352	$3F01			ADDLW	1
$0353	$00F0			MOVWF	STACK_0
$0354	$01F1			CLRF	STACK_0+1
$0355	$1803			BTFSC	STATUS, C
$0356	$0AF1			INCF	STACK_0+1, 1
$0357	$1283			BCF	STATUS, RP0
$0358	$0869			MOVF	FARG_PWM1_Change_Duty+0, 0
$0359	$00F4			MOVWF	STACK_4
$035A	$01F5			CLRF	STACK_4+1
$035B	$2305			CALL	_mul_16x16_s
$035C	$3006			MOVLW	6
$035D	$00F2			MOVWF	STACK_2
$035E	$0870			MOVF	STACK_0, 0
$035F	$00F4			MOVWF	STACK_4
$0360	$0871			MOVF	STACK_0+1, 0
$0361	$00F5			MOVWF	STACK_4+1
$0362	$0872			MOVF	STACK_2, 0
$0363	$	L_PWM1_Change_Duty_2:
$0363	$1903			BTFSC	STATUS, Z
$0364	$2B6A			GOTO	L_PWM1_Change_Duty_3
$0365	$0CF5			RRF	STACK_4+1, 1
$0366	$0CF4			RRF	STACK_4, 1
$0367	$13F5			BCF	STACK_4+1, 7
$0368	$3FFF			ADDLW	255
$0369	$2B63			GOTO	L_PWM1_Change_Duty_2
$036A	$	L_PWM1_Change_Duty_3:
$036A	$0874			MOVF	STACK_4, 0
$036B	$00F0			MOVWF	STACK_0
$036C	$0DF0			RLF	STACK_0, 1
$036D	$1070			BCF	STACK_0, 0
$036E	$0DF0			RLF	STACK_0, 1
$036F	$1070			BCF	STACK_0, 0
$0370	$0DF0			RLF	STACK_0, 1
$0371	$1070			BCF	STACK_0, 0
$0372	$0DF0			RLF	STACK_0, 1
$0373	$1070			BCF	STACK_0, 0
$0374	$3030			MOVLW	48
$0375	$0570			ANDWF	STACK_0, 0
$0376	$00F3			MOVWF	STACK_3
$0377	$0874			MOVF	STACK_4, 0
$0378	$00F0			MOVWF	STACK_0
$0379	$0875			MOVF	STACK_4+1, 0
$037A	$00F1			MOVWF	STACK_0+1
$037B	$0CF1			RRF	STACK_0+1, 1
$037C	$0CF0			RRF	STACK_0, 1
$037D	$13F1			BCF	STACK_0+1, 7
$037E	$0CF1			RRF	STACK_0+1, 1
$037F	$0CF0			RRF	STACK_0, 1
$0380	$13F1			BCF	STACK_0+1, 7
$0381	$0870			MOVF	STACK_0, 0
$0382	$0095			MOVWF	CCPR1L
$0383	$300F			MOVLW	15
$0384	$0597			ANDWF	CCP1CON, 1
$0385	$0873			MOVF	STACK_3, 0
$0386	$0497			IORWF	CCP1CON, 1
$0387	$0008			RETURN
$0388	$	_PWM2_Change_Duty:
$0388	$1303			BCF	STATUS, RP1
$0389	$1683			BSF	STATUS, RP0
$038A	$0812			MOVF	PR2, 0
$038B	$3F01			ADDLW	1
$038C	$00F0			MOVWF	STACK_0
$038D	$01F1			CLRF	STACK_0+1
$038E	$1803			BTFSC	STATUS, C
$038F	$0AF1			INCF	STACK_0+1, 1
$0390	$1283			BCF	STATUS, RP0
$0391	$0869			MOVF	FARG_PWM2_Change_Duty+0, 0
$0392	$00F4			MOVWF	STACK_4
$0393	$01F5			CLRF	STACK_4+1
$0394	$2305			CALL	_mul_16x16_s
$0395	$3006			MOVLW	6
$0396	$00F2			MOVWF	STACK_2
$0397	$0870			MOVF	STACK_0, 0
$0398	$00F4			MOVWF	STACK_4
$0399	$0871			MOVF	STACK_0+1, 0
$039A	$00F5			MOVWF	STACK_4+1
$039B	$0872			MOVF	STACK_2, 0
$039C	$	L_PWM2_Change_Duty_0:
$039C	$1903			BTFSC	STATUS, Z
$039D	$2BA3			GOTO	L_PWM2_Change_Duty_1
$039E	$0CF5			RRF	STACK_4+1, 1
$039F	$0CF4			RRF	STACK_4, 1
$03A0	$13F5			BCF	STACK_4+1, 7
$03A1	$3FFF			ADDLW	255
$03A2	$2B9C			GOTO	L_PWM2_Change_Duty_0
$03A3	$	L_PWM2_Change_Duty_1:
$03A3	$0874			MOVF	STACK_4, 0
$03A4	$00F0			MOVWF	STACK_0
$03A5	$0DF0			RLF	STACK_0, 1
$03A6	$1070			BCF	STACK_0, 0
$03A7	$0DF0			RLF	STACK_0, 1
$03A8	$1070			BCF	STACK_0, 0
$03A9	$0DF0			RLF	STACK_0, 1
$03AA	$1070			BCF	STACK_0, 0
$03AB	$0DF0			RLF	STACK_0, 1
$03AC	$1070			BCF	STACK_0, 0
$03AD	$3030			MOVLW	48
$03AE	$0570			ANDWF	STACK_0, 0
$03AF	$00F3			MOVWF	STACK_3
$03B0	$0874			MOVF	STACK_4, 0
$03B1	$00F0			MOVWF	STACK_0
$03B2	$0875			MOVF	STACK_4+1, 0
$03B3	$00F1			MOVWF	STACK_0+1
$03B4	$0CF1			RRF	STACK_0+1, 1
$03B5	$0CF0			RRF	STACK_0, 1
$03B6	$13F1			BCF	STACK_0+1, 7
$03B7	$0CF1			RRF	STACK_0+1, 1
$03B8	$0CF0			RRF	STACK_0, 1
$03B9	$13F1			BCF	STACK_0+1, 7
$03BA	$0870			MOVF	STACK_0, 0
$03BB	$009B			MOVWF	CCPR2L
$03BC	$300F			MOVLW	15
$03BD	$059D			ANDWF	CCP2CON, 1
$03BE	$0873			MOVF	STACK_3, 0
$03BF	$049D			IORWF	CCP2CON, 1
$03C0	$0008			RETURN
$0437	$	_PWM1_Start:
$0437	$1303			BCF	STATUS, RP1
$0438	$1683			BSF	STATUS, RP0
$0439	$1107			BCF	TRISC, 2
$043A	$1283			BCF	STATUS, RP0
$043B	$1512			BSF	T2CON, 2
$043C	$300C			MOVLW	12
$043D	$0497			IORWF	CCP1CON, 1
$043E	$0008			RETURN
$043F	$	_PWM2_Start:
$043F	$1303			BCF	STATUS, RP1
$0440	$1683			BSF	STATUS, RP0
$0441	$1087			BCF	TRISC, 1
$0442	$1283			BCF	STATUS, RP0
$0443	$1512			BSF	T2CON, 2
$0444	$300C			MOVLW	12
$0445	$049D			IORWF	CCP2CON, 1
$0446	$0008			RETURN
$041E	$	_Lcd_Chr_CP:
$041E	$1303			BCF	STATUS, RP1
$041F	$1283			BCF	STATUS, RP0
$0420	$01A1			CLRF	LCD_cmd_status, 1
$0421	$0868			MOVF	FARG_Lcd_Chr_CP+0, 0
$0422	$00E9			MOVWF	FARG_Lcd_Cmd+0
$0423	$2284			CALL	_Lcd_Cmd
$0424	$3001			MOVLW	1
$0425	$00A1			MOVWF	LCD_cmd_status
$0426	$0008			RETURN
$03C1	$	_Motor_Init:
;motor.h,17 :: 		
;motor.h,19 :: 		
$03C1	$1303			BCF	STATUS, RP1
$03C2	$1283			BCF	STATUS, RP0
$03C3	$0822			MOVF	_motor_init_, 0
$03C4	$3A00			XORLW	0
$03C5	$1D03			BTFSS	STATUS, Z
$03C6	$2BE1			GOTO	L_Motor_Init_0
;motor.h,21 :: 		
$03C7	$3001			MOVLW	1
$03C8	$00A2			MOVWF	_motor_init_
;motor.h,22 :: 		
$03C9	$1703			BSF	STATUS, RP1
$03CA	$1683			BSF	STATUS, RP0
$03CB	$1009			BCF	ANSELH, 0
;motor.h,23 :: 		
$03CC	$1109			BCF	ANSELH, 2
;motor.h,24 :: 		
$03CD	$1303			BCF	STATUS, RP1
$03CE	$1086			BCF	TRISB, 1
;motor.h,25 :: 		
$03CF	$1106			BCF	TRISB, 2
;motor.h,26 :: 		
$03D0	$1008			BCF	TRISD, 0
;motor.h,27 :: 		
$03D1	$1088			BCF	TRISD, 1
;motor.h,28 :: 		
$03D2	$1283			BCF	STATUS, RP0
$03D3	$1012			BCF	T2CON, T2CKPS0
$03D4	$1092			BCF	T2CON, T2CKPS1
$03D5	$1412			BSF	T2CON, T2CKPS0
$03D6	$30F9			MOVLW	249
$03D7	$1683			BSF	STATUS, RP0
$03D8	$0092			MOVWF	PR2
$03D9	$245C			CALL	_PWM1_Init
;motor.h,29 :: 		
$03DA	$1012			BCF	T2CON, T2CKPS0
$03DB	$1092			BCF	T2CON, T2CKPS1
$03DC	$1412			BSF	T2CON, T2CKPS0
$03DD	$30F9			MOVLW	249
$03DE	$1683			BSF	STATUS, RP0
$03DF	$0092			MOVWF	PR2
$03E0	$2456			CALL	_PWM2_Init
;motor.h,30 :: 		
$03E1	$	L_Motor_Init_0:
;motor.h,31 :: 		
$03E1	$0008			RETURN
$03E2	$	_Change_Duty:
;motor.h,37 :: 		
;motor.h,39 :: 		
$03E2	$1303			BCF	STATUS, RP1
$03E3	$1283			BCF	STATUS, RP0
$03E4	$0868			MOVF	FARG_Change_Duty+0, 0
$03E5	$0623			XORWF	_motor_duty_, 0
$03E6	$1903			BTFSC	STATUS, Z
$03E7	$2BF0			GOTO	L_Change_Duty_1
;motor.h,41 :: 		
$03E8	$0868			MOVF	FARG_Change_Duty+0, 0
$03E9	$00A3			MOVWF	_motor_duty_
;motor.h,42 :: 		
$03EA	$0868			MOVF	FARG_Change_Duty+0, 0
$03EB	$00E9			MOVWF	FARG_PWM1_Change_Duty+0
$03EC	$234F			CALL	_PWM1_Change_Duty
;motor.h,43 :: 		
$03ED	$0868			MOVF	FARG_Change_Duty+0, 0
$03EE	$00E9			MOVWF	FARG_PWM2_Change_Duty+0
$03EF	$2388			CALL	_PWM2_Change_Duty
;motor.h,44 :: 		
$03F0	$	L_Change_Duty_1:
;motor.h,45 :: 		
$03F0	$0008			RETURN
$0433	$	_Motor_A_BWD:
;motor.h,67 :: 		
;motor.h,69 :: 		
$0433	$2437			CALL	_PWM1_Start
;motor.h,70 :: 		
$0434	$1408			BSF	PORTD, 0
;motor.h,71 :: 		
$0435	$1088			BCF	PORTD, 1
;motor.h,72 :: 		
$0436	$0008			RETURN
$042F	$	_Motor_B_BWD:
;motor.h,76 :: 		
;motor.h,78 :: 		
$042F	$243F			CALL	_PWM2_Start
;motor.h,79 :: 		
$0430	$1486			BSF	PORTB, 1
;motor.h,80 :: 		
$0431	$1106			BCF	PORTB, 2
;motor.h,81 :: 		
$0432	$0008			RETURN
$0447	$	_Motor_A_FWD:
;motor.h,49 :: 		
;motor.h,51 :: 		
$0447	$2437			CALL	_PWM1_Start
;motor.h,52 :: 		
$0448	$1008			BCF	PORTD, 0
;motor.h,53 :: 		
$0449	$1488			BSF	PORTD, 1
;motor.h,54 :: 		
$044A	$0008			RETURN
$044B	$	_Motor_B_FWD:
;motor.h,58 :: 		
;motor.h,60 :: 		
$044B	$243F			CALL	_PWM2_Start
;motor.h,61 :: 		
$044C	$1086			BCF	PORTB, 1
;motor.h,62 :: 		
$044D	$1506			BSF	PORTB, 2
;motor.h,63 :: 		
$044E	$0008			RETURN
$0238	$	_Lcd_Init:
$0238	$240D			CALL	_Delay_5500us
$0239	$240D			CALL	_Delay_5500us
$023A	$240D			CALL	_Delay_5500us
$023B	$0864			MOVF	FARG_Lcd_Init+0, 0
$023C	$00A0			MOVWF	LCD_port_address
$023D	$0864			MOVF	FARG_Lcd_Init+0, 0
$023E	$0084			MOVWF	FSR
$023F	$1784			BSF	FSR, 7
$0240	$1180			BCF	INDF, ___ENABLE
$0241	$1100			BCF	INDF, ___RS
$0242	$1000			BCF	INDF, ___RW
$0243	$1380			BCF	INDF, ___DB7
$0244	$1300			BCF	INDF, ___DB6
$0245	$1280			BCF	INDF, ___DB5
$0246	$1200			BCF	INDF, ___DB4
$0247	$1384			BCF	FSR, 7
$0248	$1180			BCF	INDF, ___ENABLE
$0249	$1100			BCF	INDF, ___RS
$024A	$1000			BCF	INDF, ___RW
$024B	$1380			BCF	INDF, ___DB7
$024C	$1300			BCF	INDF, ___DB6
$024D	$1280			BCF	INDF, ___DB5
$024E	$1200			BCF	INDF, ___DB4
$024F	$1680			BSF	INDF, ___DB5
$0250	$1600			BSF	INDF, ___DB4
$0251	$1580			BSF	INDF, ___ENABLE
$0252	$1180			BCF	INDF, ___ENABLE
$0253	$240D			CALL	_Delay_5500us
$0254	$1580			BSF	INDF, ___ENABLE
$0255	$1180			BCF	INDF, ___ENABLE
$0256	$240D			CALL	_Delay_5500us
$0257	$1580			BSF	INDF, ___ENABLE
$0258	$1180			BCF	INDF, ___ENABLE
$0259	$240D			CALL	_Delay_5500us
$025A	$1680			BSF	INDF, ___DB5
$025B	$1200			BCF	INDF, ___DB4
$025C	$1580			BSF	INDF, ___ENABLE
$025D	$1180			BCF	INDF, ___ENABLE
$025E	$240D			CALL	_Delay_5500us
$025F	$0180			CLRF	INDF
$0260	$1680			BSF	INDF, ___DB5
$0261	$1580			BSF	INDF, ___ENABLE
$0262	$1180			BCF	INDF, ___ENABLE
$0263	$0180			CLRF	INDF
$0264	$1780			BSF	INDF, ___DB7
$0265	$1580			BSF	INDF, ___ENABLE
$0266	$1180			BCF	INDF, ___ENABLE
$0267	$240D			CALL	_Delay_5500us
$0268	$0180			CLRF	INDF
$0269	$1600			BSF	INDF, ___DB4
$026A	$1580			BSF	INDF, ___ENABLE
$026B	$1180			BCF	INDF, ___ENABLE
$026C	$0180			CLRF	INDF
$026D	$1580			BSF	INDF, ___ENABLE
$026E	$1180			BCF	INDF, ___ENABLE
$026F	$240D			CALL	_Delay_5500us
$0270	$0180			CLRF	INDF
$0271	$1580			BSF	INDF, ___ENABLE
$0272	$1180			BCF	INDF, ___ENABLE
$0273	$1600			BSF	INDF, ___DB4
$0274	$1580			BSF	INDF, ___ENABLE
$0275	$1180			BCF	INDF, ___ENABLE
$0276	$240D			CALL	_Delay_5500us
$0277	$0180			CLRF	INDF
$0278	$1580			BSF	INDF, ___ENABLE
$0279	$1180			BCF	INDF, ___ENABLE
$027A	$1600			BSF	INDF, ___DB4
$027B	$1680			BSF	INDF, ___DB5
$027C	$1700			BSF	INDF, ___DB6
$027D	$1780			BSF	INDF, ___DB7
$027E	$1580			BSF	INDF, ___ENABLE
$027F	$1180			BCF	INDF, ___ENABLE
$0280	$240D			CALL	_Delay_5500us
$0281	$3001			MOVLW	1
$0282	$00A1			MOVWF	LCD_cmd_status
$0283	$0008			RETURN
$02C2	$	_LCD_Out:
$02C2	$2AD4			GOTO	L_LCD_Out_17
$02C3	$	L_LCD_Out_19:
$02C3	$3080			MOVLW	128
$02C4	$1303			BCF	STATUS, RP1
$02C5	$1283			BCF	STATUS, RP0
$02C6	$00E4			MOVWF	FARG_LCD_Out+0
$02C7	$2AE7			GOTO	L_LCD_Out_18
$02C8	$	L_LCD_Out_20:
$02C8	$30C0			MOVLW	192
$02C9	$00E4			MOVWF	FARG_LCD_Out+0
$02CA	$2AE7			GOTO	L_LCD_Out_18
$02CB	$	L_LCD_Out_21:
$02CB	$3094			MOVLW	148
$02CC	$00E4			MOVWF	FARG_LCD_Out+0
$02CD	$2AE7			GOTO	L_LCD_Out_18
$02CE	$	L_LCD_Out_22:
$02CE	$30D4			MOVLW	212
$02CF	$00E4			MOVWF	FARG_LCD_Out+0
$02D0	$2AE7			GOTO	L_LCD_Out_18
$02D1	$	L_LCD_Out_23:
$02D1	$3080			MOVLW	128
$02D2	$00E4			MOVWF	FARG_LCD_Out+0
$02D3	$2AE7			GOTO	L_LCD_Out_18
$02D4	$	L_LCD_Out_17:
$02D4	$1303			BCF	STATUS, RP1
$02D5	$1283			BCF	STATUS, RP0
$02D6	$0864			MOVF	FARG_LCD_Out+0, 0
$02D7	$3A01			XORLW	1
$02D8	$1903			BTFSC	STATUS, Z
$02D9	$2AC3			GOTO	L_LCD_Out_19
$02DA	$0864			MOVF	FARG_LCD_Out+0, 0
$02DB	$3A02			XORLW	2
$02DC	$1903			BTFSC	STATUS, Z
$02DD	$2AC8			GOTO	L_LCD_Out_20
$02DE	$0864			MOVF	FARG_LCD_Out+0, 0
$02DF	$3A03			XORLW	3
$02E0	$1903			BTFSC	STATUS, Z
$02E1	$2ACB			GOTO	L_LCD_Out_21
$02E2	$0864			MOVF	FARG_LCD_Out+0, 0
$02E3	$3A04			XORLW	4
$02E4	$1903			BTFSC	STATUS, Z
$02E5	$2ACE			GOTO	L_LCD_Out_22
$02E6	$2AD1			GOTO	L_LCD_Out_23
$02E7	$	L_LCD_Out_18:
$02E7	$0365			DECF	FARG_LCD_Out+1, 0
$02E8	$00F0			MOVWF	STACK_0
$02E9	$0864			MOVF	FARG_LCD_Out+0, 0
$02EA	$07F0			ADDWF	STACK_0, 1
$02EB	$0870			MOVF	STACK_0, 0
$02EC	$00E4			MOVWF	FARG_LCD_Out+0
$02ED	$0870			MOVF	STACK_0, 0
$02EE	$00E9			MOVWF	FARG_Lcd_Cmd+0
$02EF	$2284			CALL	_Lcd_Cmd
$02F0	$01A1			CLRF	LCD_cmd_status, 1
$02F1	$01E7			CLRF	LCD_Out_i_L0, 1
$02F2	$	L_LCD_Out_24:
$02F2	$0867			MOVF	LCD_Out_i_L0, 0
$02F3	$0766			ADDWF	FARG_LCD_Out+2, 0
$02F4	$0084			MOVWF	FSR
$02F5	$0800			MOVF	INDF, 0
$02F6	$00F0			MOVWF	STACK_0
$02F7	$0870			MOVF	STACK_0, 0
$02F8	$1903			BTFSC	STATUS, Z
$02F9	$2B02			GOTO	L_LCD_Out_25
$02FA	$0867			MOVF	LCD_Out_i_L0, 0
$02FB	$0766			ADDWF	FARG_LCD_Out+2, 0
$02FC	$0084			MOVWF	FSR
$02FD	$0800			MOVF	INDF, 0
$02FE	$00E8			MOVWF	FARG_Lcd_Chr_CP+0
$02FF	$241E			CALL	_Lcd_Chr_CP
$0300	$0AE7			INCF	LCD_Out_i_L0, 1
$0301	$2AF2			GOTO	L_LCD_Out_24
$0302	$	L_LCD_Out_25:
$0302	$3001			MOVLW	1
$0303	$00A1			MOVWF	LCD_cmd_status
$0304	$0008			RETURN
$012E	$	_Adc_Rd:
;adc.h,1 :: 		
;adc.h,4 :: 		
$012E	$3000			MOVLW	0
$012F	$1303			BCF	STATUS, RP1
$0130	$1283			BCF	STATUS, RP0
$0131	$0264			SUBWF	FARG_Adc_Rd+0, 0
$0132	$1C03			BTFSS	STATUS, C
$0133	$2947			GOTO	L_Adc_Rd_4
$0134	$0864			MOVF	FARG_Adc_Rd+0, 0
$0135	$3C03			SUBLW	3
$0136	$1C03			BTFSS	STATUS, C
$0137	$2947			GOTO	L_Adc_Rd_4
$0138	$	L107_ex_L_Adc_Rd_4:
;adc.h,5 :: 		
$0138	$0864			MOVF	FARG_Adc_Rd+0, 0
$0139	$00F2			MOVWF	STACK_2
$013A	$3001			MOVLW	1
$013B	$00F0			MOVWF	STACK_0
$013C	$0872			MOVF	STACK_2, 0
$013D	$	L_Adc_Rd_20:
$013D	$1903			BTFSC	STATUS, Z
$013E	$2943			GOTO	L_Adc_Rd_21
$013F	$0DF0			RLF	STACK_0, 1
$0140	$1070			BCF	STACK_0, 0
$0141	$3FFF			ADDLW	255
$0142	$293D			GOTO	L_Adc_Rd_20
$0143	$	L_Adc_Rd_21:
$0143	$0870			MOVF	STACK_0, 0
$0144	$1683			BSF	STATUS, RP0
$0145	$0485			IORWF	TRISA, 1
$0146	$2969			GOTO	L_Adc_Rd_5
$0147	$	L_Adc_Rd_4:
;adc.h,6 :: 		
$0147	$1283			BCF	STATUS, RP0
$0148	$0864			MOVF	FARG_Adc_Rd+0, 0
$0149	$3A04			XORLW	4
$014A	$1D03			BTFSS	STATUS, Z
$014B	$294F			GOTO	L_Adc_Rd_6
;adc.h,7 :: 		
$014C	$1683			BSF	STATUS, RP0
$014D	$1685			BSF	TRISA, 5
$014E	$2969			GOTO	L_Adc_Rd_7
$014F	$	L_Adc_Rd_6:
;adc.h,8 :: 		
$014F	$3005			MOVLW	5
$0150	$1283			BCF	STATUS, RP0
$0151	$0264			SUBWF	FARG_Adc_Rd+0, 0
$0152	$1C03			BTFSS	STATUS, C
$0153	$2969			GOTO	L_Adc_Rd_10
$0154	$0864			MOVF	FARG_Adc_Rd+0, 0
$0155	$3C07			SUBLW	7
$0156	$1C03			BTFSS	STATUS, C
$0157	$2969			GOTO	L_Adc_Rd_10
$0158	$	L130_ex_L_Adc_Rd_10:
;adc.h,9 :: 		
$0158	$3005			MOVLW	5
$0159	$0264			SUBWF	FARG_Adc_Rd+0, 0
$015A	$00F0			MOVWF	STACK_0
$015B	$0870			MOVF	STACK_0, 0
$015C	$00F2			MOVWF	STACK_2
$015D	$3001			MOVLW	1
$015E	$00F0			MOVWF	STACK_0
$015F	$0872			MOVF	STACK_2, 0
$0160	$	L_Adc_Rd_22:
$0160	$1903			BTFSC	STATUS, Z
$0161	$2966			GOTO	L_Adc_Rd_23
$0162	$0DF0			RLF	STACK_0, 1
$0163	$1070			BCF	STACK_0, 0
$0164	$3FFF			ADDLW	255
$0165	$2960			GOTO	L_Adc_Rd_22
$0166	$	L_Adc_Rd_23:
$0166	$0870			MOVF	STACK_0, 0
$0167	$1683			BSF	STATUS, RP0
$0168	$0489			IORWF	TRISE, 1
$0169	$	L_Adc_Rd_10:
$0169	$	L_Adc_Rd_7:
$0169	$	L_Adc_Rd_5:
;adc.h,10 :: 		
$0169	$1303			BCF	STATUS, RP1
$016A	$1683			BSF	STATUS, RP0
$016B	$1283			BCF	STATUS, RP0
$016C	$0864			MOVF	FARG_Adc_Rd+0, 0
$016D	$00F2			MOVWF	STACK_2
$016E	$3001			MOVLW	1
$016F	$00F0			MOVWF	STACK_0
$0170	$0872			MOVF	STACK_2, 0
$0171	$	L_Adc_Rd_24:
$0171	$1903			BTFSC	STATUS, Z
$0172	$2977			GOTO	L_Adc_Rd_25
$0173	$0DF0			RLF	STACK_0, 1
$0174	$1070			BCF	STACK_0, 0
$0175	$3FFF			ADDLW	255
$0176	$2971			GOTO	L_Adc_Rd_24
$0177	$	L_Adc_Rd_25:
$0177	$0870			MOVF	STACK_0, 0
$0178	$1703			BSF	STATUS, RP1
$0179	$1683			BSF	STATUS, RP0
$017A	$0488			IORWF	ANSEL, 1
;adc.h,11 :: 		
$017B	$3002			MOVLW	2
$017C	$00F4			MOVWF	STACK_4
$017D	$1303			BCF	STATUS, RP1
$017E	$1283			BCF	STATUS, RP0
$017F	$0864			MOVF	FARG_Adc_Rd+0, 0
$0180	$00F0			MOVWF	STACK_0
$0181	$0874			MOVF	STACK_4, 0
$0182	$	L_Adc_Rd_26:
$0182	$1903			BTFSC	STATUS, Z
$0183	$2988			GOTO	L_Adc_Rd_27
$0184	$0DF0			RLF	STACK_0, 1
$0185	$1070			BCF	STACK_0, 0
$0186	$3FFF			ADDLW	255
$0187	$2982			GOTO	L_Adc_Rd_26
$0188	$	L_Adc_Rd_27:
$0188	$0870			MOVF	STACK_0, 0
$0189	$3FC1			ADDLW	193
$018A	$009F			MOVWF	ADCON0
;adc.h,12 :: 		
$018B	$3010			MOVLW	16
$018C	$00FA			MOVWF	STACK_10
$018D	$0BFA			DECFSZ	STACK_10, F
$018E	$298D			GOTO	$-1
$018F	$0000			NOP
;adc.h,13 :: 		
$0190	$149F			BSF	ADCON0, 1
;adc.h,14 :: 		
$0191	$	L_Adc_Rd_11:
$0191	$189F			BTFSC	ADCON0, 1
$0192	$2991			GOTO	L_Adc_Rd_11
$0193	$	L_Adc_Rd_12:
;adc.h,15 :: 		
$0193	$3002			MOVLW	2
$0194	$00F4			MOVWF	STACK_4
$0195	$081E			MOVF	ADRESH, 0
$0196	$00E5			MOVWF	FLOC_Adc_Rd+0
$0197	$01E6			CLRF	FLOC_Adc_Rd+1
$0198	$0874			MOVF	STACK_4, 0
$0199	$	L_Adc_Rd_28:
$0199	$1903			BTFSC	STATUS, Z
$019A	$29A0			GOTO	L_Adc_Rd_29
$019B	$0DE5			RLF	FLOC_Adc_Rd+0, 1
$019C	$0DE6			RLF	FLOC_Adc_Rd+1, 1
$019D	$1065			BCF	FLOC_Adc_Rd+0, 0
$019E	$3FFF			ADDLW	255
$019F	$2999			GOTO	L_Adc_Rd_28
$01A0	$	L_Adc_Rd_29:
$01A0	$3006			MOVLW	6
$01A1	$00F4			MOVWF	STACK_4
$01A2	$1683			BSF	STATUS, RP0
$01A3	$081E			MOVF	ADRESL, 0
$01A4	$00F0			MOVWF	STACK_0
$01A5	$0874			MOVF	STACK_4, 0
$01A6	$	L_Adc_Rd_30:
$01A6	$1903			BTFSC	STATUS, Z
$01A7	$29AC			GOTO	L_Adc_Rd_31
$01A8	$0CF0			RRF	STACK_0, 1
$01A9	$13F0			BCF	STACK_0, 7
$01AA	$3FFF			ADDLW	255
$01AB	$29A6			GOTO	L_Adc_Rd_30
$01AC	$	L_Adc_Rd_31:
$01AC	$3000			MOVLW	0
$01AD	$00F1			MOVWF	STACK_0+1
$01AE	$1283			BCF	STATUS, RP0
$01AF	$0865			MOVF	FLOC_Adc_Rd+0, 0
$01B0	$07F0			ADDWF	STACK_0, 1
$01B1	$0866			MOVF	FLOC_Adc_Rd+1, 0
$01B2	$1803			BTFSC	STATUS, C
$01B3	$3F01			ADDLW	1
$01B4	$07F1			ADDWF	STACK_0+1, 1
;adc.h,16 :: 		
;adc.h,17 :: 		
$01B5	$0008			RETURN
$03F8	$	_Backward:
;motor.h,95 :: 		
;motor.h,97 :: 		
$03F8	$23C1			CALL	_Motor_Init
;motor.h,98 :: 		
$03F9	$0864			MOVF	FARG_Backward+0, 0
$03FA	$00E8			MOVWF	FARG_Change_Duty+0
$03FB	$23E2			CALL	_Change_Duty
;motor.h,99 :: 		
$03FC	$2433			CALL	_Motor_A_BWD
;motor.h,100 :: 		
$03FD	$242F			CALL	_Motor_B_BWD
;motor.h,101 :: 		
$03FE	$0008			RETURN
$03F1	$	_S_Right:
;motor.h,105 :: 		
;motor.h,107 :: 		
$03F1	$23C1			CALL	_Motor_Init
;motor.h,108 :: 		
$03F2	$0864			MOVF	FARG_S_Right+0, 0
$03F3	$00E8			MOVWF	FARG_Change_Duty+0
$03F4	$23E2			CALL	_Change_Duty
;motor.h,109 :: 		
$03F5	$2447			CALL	_Motor_A_FWD
;motor.h,110 :: 		
$03F6	$242F			CALL	_Motor_B_BWD
;motor.h,111 :: 		
$03F7	$0008			RETURN
$0406	$	_S_Left:
;motor.h,115 :: 		
;motor.h,117 :: 		
$0406	$23C1			CALL	_Motor_Init
;motor.h,118 :: 		
$0407	$0864			MOVF	FARG_S_Left+0, 0
$0408	$00E8			MOVWF	FARG_Change_Duty+0
$0409	$23E2			CALL	_Change_Duty
;motor.h,119 :: 		
$040A	$2433			CALL	_Motor_A_BWD
;motor.h,120 :: 		
$040B	$244B			CALL	_Motor_B_FWD
;motor.h,121 :: 		
$040C	$0008			RETURN
$03FF	$	_Forward:
;motor.h,85 :: 		
;motor.h,87 :: 		
$03FF	$23C1			CALL	_Motor_Init
;motor.h,88 :: 		
$0400	$0864			MOVF	FARG_Forward+0, 0
$0401	$00E8			MOVWF	FARG_Change_Duty+0
$0402	$23E2			CALL	_Change_Duty
;motor.h,89 :: 		
$0403	$2447			CALL	_Motor_A_FWD
;motor.h,90 :: 		
$0404	$244B			CALL	_Motor_B_FWD
;motor.h,91 :: 		
$0405	$0008			RETURN
$01B6	$	GlobalIniSurveyBot:
$01B6	$307F			MOVLW	127
$01B7	$1303			BCF	STATUS, RP1
$01B8	$1283			BCF	STATUS, RP0
$01B9	$00A3			MOVWF	_motor_duty_+0
$01BA	$3000			MOVLW	0
$01BB	$00A2			MOVWF	_motor_init_+0
$01BC	$3045			MOVLW	69
$01BD	$00A4			MOVWF	lstr1_SurveyBot+0
$01BE	$3064			MOVLW	100
$01BF	$00A5			MOVWF	lstr1_SurveyBot+1
$01C0	$3067			MOVLW	103
$01C1	$00A6			MOVWF	lstr1_SurveyBot+2
$01C2	$3065			MOVLW	101
$01C3	$00A7			MOVWF	lstr1_SurveyBot+3
$01C4	$3020			MOVLW	32
$01C5	$00A8			MOVWF	lstr1_SurveyBot+4
$01C6	$306F			MOVLW	111
$01C7	$00A9			MOVWF	lstr1_SurveyBot+5
$01C8	$3066			MOVLW	102
$01C9	$00AA			MOVWF	lstr1_SurveyBot+6
$01CA	$3020			MOVLW	32
$01CB	$00AB			MOVWF	lstr1_SurveyBot+7
$01CC	$3061			MOVLW	97
$01CD	$00AC			MOVWF	lstr1_SurveyBot+8
$01CE	$3020			MOVLW	32
$01CF	$00AD			MOVWF	lstr1_SurveyBot+9
$01D0	$3074			MOVLW	116
$01D1	$00AE			MOVWF	lstr1_SurveyBot+10
$01D2	$3061			MOVLW	97
$01D3	$00AF			MOVWF	lstr1_SurveyBot+11
$01D4	$3062			MOVLW	98
$01D5	$00B0			MOVWF	lstr1_SurveyBot+12
$01D6	$306C			MOVLW	108
$01D7	$00B1			MOVWF	lstr1_SurveyBot+13
$01D8	$3065			MOVLW	101
$01D9	$00B2			MOVWF	lstr1_SurveyBot+14
$01DA	$01B3			CLRF	lstr1_SurveyBot+15
$01DB	$3024			MOVLW	lstr1_SurveyBot
$01DC	$00B4			MOVWF	_text1+0
$01DD	$3046			MOVLW	70
$01DE	$00B5			MOVWF	lstr2_SurveyBot+0
$01DF	$3072			MOVLW	114
$01E0	$00B6			MOVWF	lstr2_SurveyBot+1
$01E1	$306F			MOVLW	111
$01E2	$00B7			MOVWF	lstr2_SurveyBot+2
$01E3	$306D			MOVLW	109
$01E4	$00B8			MOVWF	lstr2_SurveyBot+3
$01E5	$3020			MOVLW	32
$01E6	$00B9			MOVWF	lstr2_SurveyBot+4
$01E7	$304C			MOVLW	76
$01E8	$00BA			MOVWF	lstr2_SurveyBot+5
$01E9	$3065			MOVLW	101
$01EA	$00BB			MOVWF	lstr2_SurveyBot+6
$01EB	$3066			MOVLW	102
$01EC	$00BC			MOVWF	lstr2_SurveyBot+7
$01ED	$3074			MOVLW	116
$01EE	$00BD			MOVWF	lstr2_SurveyBot+8
$01EF	$01BE			CLRF	lstr2_SurveyBot+9
$01F0	$3035			MOVLW	lstr2_SurveyBot
$01F1	$00BF			MOVWF	_text2+0
$01F2	$3046			MOVLW	70
$01F3	$00C0			MOVWF	lstr3_SurveyBot+0
$01F4	$3072			MOVLW	114
$01F5	$00C1			MOVWF	lstr3_SurveyBot+1
$01F6	$306F			MOVLW	111
$01F7	$00C2			MOVWF	lstr3_SurveyBot+2
$01F8	$306D			MOVLW	109
$01F9	$00C3			MOVWF	lstr3_SurveyBot+3
$01FA	$3020			MOVLW	32
$01FB	$00C4			MOVWF	lstr3_SurveyBot+4
$01FC	$3052			MOVLW	82
$01FD	$00C5			MOVWF	lstr3_SurveyBot+5
$01FE	$3069			MOVLW	105
$01FF	$00C6			MOVWF	lstr3_SurveyBot+6
$0200	$3067			MOVLW	103
$0201	$00C7			MOVWF	lstr3_SurveyBot+7
$0202	$3068			MOVLW	104
$0203	$00C8			MOVWF	lstr3_SurveyBot+8
$0204	$3074			MOVLW	116
$0205	$00C9			MOVWF	lstr3_SurveyBot+9
$0206	$01CA			CLRF	lstr3_SurveyBot+10
$0207	$3040			MOVLW	lstr3_SurveyBot
$0208	$00CB			MOVWF	_text3+0
$0209	$304C			MOVLW	76
$020A	$00CC			MOVWF	lstr4_SurveyBot+0
$020B	$3065			MOVLW	101
$020C	$00CD			MOVWF	lstr4_SurveyBot+1
$020D	$3074			MOVLW	116
$020E	$00CE			MOVWF	lstr4_SurveyBot+2
$020F	$3027			MOVLW	39
$0210	$00CF			MOVWF	lstr4_SurveyBot+3
$0211	$3047			MOVLW	71
$0212	$00D0			MOVWF	lstr4_SurveyBot+4
$0213	$306F			MOVLW	111
$0214	$00D1			MOVWF	lstr4_SurveyBot+5
$0215	$01D2			CLRF	lstr4_SurveyBot+6
$0216	$304C			MOVLW	lstr4_SurveyBot
$0217	$00D3			MOVWF	_text4+0
$0218	$3052			MOVLW	82
$0219	$00D4			MOVWF	lstr5_SurveyBot+0
$021A	$306F			MOVLW	111
$021B	$00D5			MOVWF	lstr5_SurveyBot+1
$021C	$3075			MOVLW	117
$021D	$00D6			MOVWF	lstr5_SurveyBot+2
$021E	$3074			MOVLW	116
$021F	$00D7			MOVWF	lstr5_SurveyBot+3
$0220	$3065			MOVLW	101
$0221	$00D8			MOVWF	lstr5_SurveyBot+4
$0222	$3020			MOVLW	32
$0223	$00D9			MOVWF	lstr5_SurveyBot+5
$0224	$3043			MOVLW	67
$0225	$00DA			MOVWF	lstr5_SurveyBot+6
$0226	$306C			MOVLW	108
$0227	$00DB			MOVWF	lstr5_SurveyBot+7
$0228	$3065			MOVLW	101
$0229	$00DC			MOVWF	lstr5_SurveyBot+8
$022A	$3061			MOVLW	97
$022B	$00DD			MOVWF	lstr5_SurveyBot+9
$022C	$3072			MOVLW	114
$022D	$00DE			MOVWF	lstr5_SurveyBot+10
$022E	$01DF			CLRF	lstr5_SurveyBot+11
$022F	$3054			MOVLW	lstr5_SurveyBot
$0230	$00E0			MOVWF	_text5+0
$0231	$3000			MOVLW	0
$0232	$00E1			MOVWF	_flag+0
$0233	$3000			MOVLW	0
$0234	$00E2			MOVWF	_ADC+0
$0235	$3000			MOVLW	0
$0236	$00E3			MOVWF	_ADC+1
$0237	$0008			RETURN
$0004	$	_main:
$0004	$21B6			CALL	GlobalIniSurveyBot
$0005	$303C			MOVLW	60
$0006	$1683			BSF	STATUS, RP0
$0007	$00A0			MOVWF	lstr6_SurveyBot+0
$0008	$303C			MOVLW	60
$0009	$00A1			MOVWF	lstr6_SurveyBot+1
$000A	$3020			MOVLW	32
$000B	$00A2			MOVWF	lstr6_SurveyBot+2
$000C	$3052			MOVLW	82
$000D	$00A3			MOVWF	lstr6_SurveyBot+3
$000E	$3041			MOVLW	65
$000F	$00A4			MOVWF	lstr6_SurveyBot+4
$0010	$3034			MOVLW	52
$0011	$00A5			MOVWF	lstr6_SurveyBot+5
$0012	$3020			MOVLW	32
$0013	$00A6			MOVWF	lstr6_SurveyBot+6
$0014	$303E			MOVLW	62
$0015	$00A7			MOVWF	lstr6_SurveyBot+7
$0016	$303E			MOVLW	62
$0017	$00A8			MOVWF	lstr6_SurveyBot+8
$0018	$3020			MOVLW	32
$0019	$00A9			MOVWF	lstr6_SurveyBot+9
$001A	$3053			MOVLW	83
$001B	$00AA			MOVWF	lstr6_SurveyBot+10
$001C	$3074			MOVLW	116
$001D	$00AB			MOVWF	lstr6_SurveyBot+11
$001E	$3061			MOVLW	97
$001F	$00AC			MOVWF	lstr6_SurveyBot+12
$0020	$3072			MOVLW	114
$0021	$00AD			MOVWF	lstr6_SurveyBot+13
$0022	$3074			MOVLW	116
$0023	$00AE			MOVWF	lstr6_SurveyBot+14
$0024	$01AF			CLRF	lstr6_SurveyBot+15
;SurveyBot.c,14 :: 		void main()
;SurveyBot.c,16 :: 		Lcd_Init(&PORTD);                // Init LCD Port
$0025	$3008			MOVLW	PORTD
$0026	$1283			BCF	STATUS, RP0
$0027	$00E4			MOVWF	FARG_Lcd_Init+0
$0028	$2238			CALL	_Lcd_Init
;SurveyBot.c,17 :: 		Lcd_Cmd(LCD_CURSOR_OFF);         // LCD cursor off
$0029	$300C			MOVLW	12
$002A	$00E9			MOVWF	FARG_Lcd_Cmd+0
$002B	$2284			CALL	_Lcd_Cmd
;SurveyBot.c,18 :: 		Lcd_Cmd(LCD_CLEAR);
$002C	$3001			MOVLW	1
$002D	$00E9			MOVWF	FARG_Lcd_Cmd+0
$002E	$2284			CALL	_Lcd_Cmd
;SurveyBot.c,20 :: 		Lcd_Out(1,1, "<< RA4 >> Start");
$002F	$3001			MOVLW	1
$0030	$00E4			MOVWF	FARG_LCD_Out+0
$0031	$3001			MOVLW	1
$0032	$00E5			MOVWF	FARG_LCD_Out+1
$0033	$30A0			MOVLW	lstr6_SurveyBot
$0034	$00E6			MOVWF	FARG_LCD_Out+2
$0035	$22C2			CALL	_LCD_Out
;SurveyBot.c,21 :: 		while(PORTA.F4==1);
$0036	$	L_main_13:
$0036	$3000			MOVLW	0
$0037	$1A05			BTFSC	PORTA, 4
$0038	$3001			MOVLW	1
$0039	$00F2			MOVWF	STACK_2
$003A	$0872			MOVF	STACK_2, 0
$003B	$3A01			XORLW	1
$003C	$1903			BTFSC	STATUS, Z
$003D	$2836			GOTO	L_main_13
$003E	$	L_main_14:
;SurveyBot.c,23 :: 		while(1)
$003E	$	L_main_15:
;SurveyBot.c,25 :: 		ADC =Adc_Rd(0);               // Reading Sensor from Left
$003E	$01E4			CLRF	FARG_Adc_Rd+0, 1
$003F	$212E			CALL	_Adc_Rd
$0040	$0870			MOVF	STACK_0, 0
$0041	$00E2			MOVWF	_ADC
$0042	$0871			MOVF	STACK_0+1, 0
$0043	$00E3			MOVWF	_ADC+1
;SurveyBot.c,26 :: 		if (ADC<100)                  // Left Sensor Found Edge of Table ?
$0044	$3080			MOVLW	128
$0045	$0671			XORWF	STACK_0+1, 0
$0046	$00F2			MOVWF	STACK_2
$0047	$3080			MOVLW	128
$0048	$0272			SUBWF	STACK_2, 0
$0049	$1D03			BTFSS	STATUS, Z
$004A	$284D			GOTO	L_main_32
$004B	$3064			MOVLW	100
$004C	$0270			SUBWF	STACK_0, 0
$004D	$	L_main_32:
$004D	$1803			BTFSC	STATUS, C
$004E	$28A6			GOTO	L_main_17
;SurveyBot.c,28 :: 		flag=0;                  // clear flag
$004F	$01E1			CLRF	_flag, 1
;SurveyBot.c,29 :: 		Backward(255);
$0050	$30FF			MOVLW	255
$0051	$00E4			MOVWF	FARG_Backward+0
$0052	$23F8			CALL	_Backward
;SurveyBot.c,30 :: 		Lcd_Cmd(LCD_CLEAR);      // Show Text ON LCD
$0053	$3001			MOVLW	1
$0054	$00E9			MOVWF	FARG_Lcd_Cmd+0
$0055	$2284			CALL	_Lcd_Cmd
;SurveyBot.c,31 :: 		Lcd_Out(1,1,text1);
$0056	$3001			MOVLW	1
$0057	$00E4			MOVWF	FARG_LCD_Out+0
$0058	$3001			MOVLW	1
$0059	$00E5			MOVWF	FARG_LCD_Out+1
$005A	$0834			MOVF	_text1, 0
$005B	$00E6			MOVWF	FARG_LCD_Out+2
$005C	$22C2			CALL	_LCD_Out
;SurveyBot.c,32 :: 		Lcd_Out(2,1,text2);
$005D	$3002			MOVLW	2
$005E	$00E4			MOVWF	FARG_LCD_Out+0
$005F	$3001			MOVLW	1
$0060	$00E5			MOVWF	FARG_LCD_Out+1
$0061	$083F			MOVF	_text2, 0
$0062	$00E6			MOVWF	FARG_LCD_Out+2
$0063	$22C2			CALL	_LCD_Out
;SurveyBot.c,33 :: 		Delay_ms(400);
$0064	$300B			MOVLW	11
$0065	$00FC			MOVWF	STACK_12
$0066	$30FF			MOVLW	255
$0067	$00FB			MOVWF	STACK_11
$0068	$30FF			MOVLW	255
$0069	$00FA			MOVWF	STACK_10
$006A	$0BFC			DECFSZ	STACK_12, F
$006B	$286D			GOTO	$+2
$006C	$2874			GOTO	$+8
$006D	$0BFB			DECFSZ	STACK_11, F
$006E	$2870			GOTO	$+2
$006F	$2873			GOTO	$+4
$0070	$0BFA			DECFSZ	STACK_10, F
$0071	$2870			GOTO	$-1
$0072	$286D			GOTO	$-5
$0073	$286A			GOTO	$-9
$0074	$3033			MOVLW	51
$0075	$00FB			MOVWF	STACK_11
$0076	$30FF			MOVLW	255
$0077	$00FA			MOVWF	STACK_10
$0078	$0BFB			DECFSZ	STACK_11, F
$0079	$287B			GOTO	$+2
$007A	$287E			GOTO	$+4
$007B	$0BFA			DECFSZ	STACK_10, F
$007C	$287B			GOTO	$-1
$007D	$2878			GOTO	$-5
$007E	$3087			MOVLW	135
$007F	$00FA			MOVWF	STACK_10
$0080	$0BFA			DECFSZ	STACK_10, F
$0081	$2880			GOTO	$-1
$0082	$0000			NOP
$0083	$0000			NOP
$0084	$0000			NOP
;SurveyBot.c,34 :: 		S_Right(255);            // Change route
$0085	$30FF			MOVLW	255
$0086	$00E4			MOVWF	FARG_S_Right+0
$0087	$23F1			CALL	_S_Right
;SurveyBot.c,35 :: 		Delay_ms(600);
$0088	$3010			MOVLW	16
$0089	$00FC			MOVWF	STACK_12
$008A	$30FF			MOVLW	255
$008B	$00FB			MOVWF	STACK_11
$008C	$30FF			MOVLW	255
$008D	$00FA			MOVWF	STACK_10
$008E	$0BFC			DECFSZ	STACK_12, F
$008F	$2891			GOTO	$+2
$0090	$2898			GOTO	$+8
$0091	$0BFB			DECFSZ	STACK_11, F
$0092	$2894			GOTO	$+2
$0093	$2897			GOTO	$+4
$0094	$0BFA			DECFSZ	STACK_10, F
$0095	$2894			GOTO	$-1
$0096	$2891			GOTO	$-5
$0097	$288E			GOTO	$-9
$0098	$304C			MOVLW	76
$0099	$00FB			MOVWF	STACK_11
$009A	$30FF			MOVLW	255
$009B	$00FA			MOVWF	STACK_10
$009C	$0BFB			DECFSZ	STACK_11, F
$009D	$289F			GOTO	$+2
$009E	$28A2			GOTO	$+4
$009F	$0BFA			DECFSZ	STACK_10, F
$00A0	$289F			GOTO	$-1
$00A1	$289C			GOTO	$-5
$00A2	$30CE			MOVLW	206
$00A3	$00FA			MOVWF	STACK_10
$00A4	$0BFA			DECFSZ	STACK_10, F
$00A5	$28A4			GOTO	$-1
;SurveyBot.c,36 :: 		}
$00A6	$	L_main_17:
;SurveyBot.c,37 :: 		ADC =Adc_Rd(1);               // Reading Sensor from Right
$00A6	$3001			MOVLW	1
$00A7	$00E4			MOVWF	FARG_Adc_Rd+0
$00A8	$212E			CALL	_Adc_Rd
$00A9	$0870			MOVF	STACK_0, 0
$00AA	$00E2			MOVWF	_ADC
$00AB	$0871			MOVF	STACK_0+1, 0
$00AC	$00E3			MOVWF	_ADC+1
;SurveyBot.c,38 :: 		if (ADC<100)                  // Right Sensor Found Edge of Table ?
$00AD	$3080			MOVLW	128
$00AE	$0671			XORWF	STACK_0+1, 0
$00AF	$00F2			MOVWF	STACK_2
$00B0	$3080			MOVLW	128
$00B1	$0272			SUBWF	STACK_2, 0
$00B2	$1D03			BTFSS	STATUS, Z
$00B3	$28B6			GOTO	L_main_33
$00B4	$3064			MOVLW	100
$00B5	$0270			SUBWF	STACK_0, 0
$00B6	$	L_main_33:
$00B6	$1803			BTFSC	STATUS, C
$00B7	$2912			GOTO	L_main_18
;SurveyBot.c,40 :: 		flag=0;                  // Clear Flag
$00B8	$01E1			CLRF	_flag, 1
;SurveyBot.c,41 :: 		Backward(255);
$00B9	$30FF			MOVLW	255
$00BA	$00E4			MOVWF	FARG_Backward+0
$00BB	$23F8			CALL	_Backward
;SurveyBot.c,42 :: 		Lcd_Cmd(LCD_CLEAR);      // Show LCD text
$00BC	$3001			MOVLW	1
$00BD	$00E9			MOVWF	FARG_Lcd_Cmd+0
$00BE	$2284			CALL	_Lcd_Cmd
;SurveyBot.c,43 :: 		Lcd_Out(1,1,text1);
$00BF	$3001			MOVLW	1
$00C0	$00E4			MOVWF	FARG_LCD_Out+0
$00C1	$3001			MOVLW	1
$00C2	$00E5			MOVWF	FARG_LCD_Out+1
$00C3	$0834			MOVF	_text1, 0
$00C4	$00E6			MOVWF	FARG_LCD_Out+2
$00C5	$22C2			CALL	_LCD_Out
;SurveyBot.c,44 :: 		Lcd_Out(2,1,text3);
$00C6	$3002			MOVLW	2
$00C7	$00E4			MOVWF	FARG_LCD_Out+0
$00C8	$3001			MOVLW	1
$00C9	$00E5			MOVWF	FARG_LCD_Out+1
$00CA	$084B			MOVF	_text3, 0
$00CB	$00E6			MOVWF	FARG_LCD_Out+2
$00CC	$22C2			CALL	_LCD_Out
;SurveyBot.c,45 :: 		Delay_ms(400);
$00CD	$300B			MOVLW	11
$00CE	$00FC			MOVWF	STACK_12
$00CF	$30FF			MOVLW	255
$00D0	$00FB			MOVWF	STACK_11
$00D1	$30FF			MOVLW	255
$00D2	$00FA			MOVWF	STACK_10
$00D3	$0BFC			DECFSZ	STACK_12, F
$00D4	$28D6			GOTO	$+2
$00D5	$28DD			GOTO	$+8
$00D6	$0BFB			DECFSZ	STACK_11, F
$00D7	$28D9			GOTO	$+2
$00D8	$28DC			GOTO	$+4
$00D9	$0BFA			DECFSZ	STACK_10, F
$00DA	$28D9			GOTO	$-1
$00DB	$28D6			GOTO	$-5
$00DC	$28D3			GOTO	$-9
$00DD	$3033			MOVLW	51
$00DE	$00FB			MOVWF	STACK_11
$00DF	$30FF			MOVLW	255
$00E0	$00FA			MOVWF	STACK_10
$00E1	$0BFB			DECFSZ	STACK_11, F
$00E2	$28E4			GOTO	$+2
$00E3	$28E7			GOTO	$+4
$00E4	$0BFA			DECFSZ	STACK_10, F
$00E5	$28E4			GOTO	$-1
$00E6	$28E1			GOTO	$-5
$00E7	$3087			MOVLW	135
$00E8	$00FA			MOVWF	STACK_10
$00E9	$0BFA			DECFSZ	STACK_10, F
$00EA	$28E9			GOTO	$-1
$00EB	$0000			NOP
$00EC	$0000			NOP
$00ED	$0000			NOP
;SurveyBot.c,46 :: 		S_Left(255);             // Change route
$00EE	$30FF			MOVLW	255
$00EF	$00E4			MOVWF	FARG_S_Left+0
$00F0	$2406			CALL	_S_Left
;SurveyBot.c,47 :: 		Delay_ms(900);
$00F1	$3017			MOVLW	23
$00F2	$00FC			MOVWF	STACK_12
$00F3	$30FF			MOVLW	255
$00F4	$00FB			MOVWF	STACK_11
$00F5	$30FF			MOVLW	255
$00F6	$00FA			MOVWF	STACK_10
$00F7	$0BFC			DECFSZ	STACK_12, F
$00F8	$28FA			GOTO	$+2
$00F9	$2901			GOTO	$+8
$00FA	$0BFB			DECFSZ	STACK_11, F
$00FB	$28FD			GOTO	$+2
$00FC	$2900			GOTO	$+4
$00FD	$0BFA			DECFSZ	STACK_10, F
$00FE	$28FD			GOTO	$-1
$00FF	$28FA			GOTO	$-5
$0100	$28F7			GOTO	$-9
$0101	$30F1			MOVLW	241
$0102	$00FB			MOVWF	STACK_11
$0103	$30FF			MOVLW	255
$0104	$00FA			MOVWF	STACK_10
$0105	$0BFB			DECFSZ	STACK_11, F
$0106	$2908			GOTO	$+2
$0107	$290B			GOTO	$+4
$0108	$0BFA			DECFSZ	STACK_10, F
$0109	$2908			GOTO	$-1
$010A	$2905			GOTO	$-5
$010B	$30B7			MOVLW	183
$010C	$00FA			MOVWF	STACK_10
$010D	$0BFA			DECFSZ	STACK_10, F
$010E	$290D			GOTO	$-1
$010F	$0000			NOP
$0110	$0000			NOP
$0111	$0000			NOP
;SurveyBot.c,48 :: 		}
$0112	$	L_main_18:
;SurveyBot.c,49 :: 		forward(255);                 // normal ==> Forward
$0112	$30FF			MOVLW	255
$0113	$00E4			MOVWF	FARG_Forward+0
$0114	$23FF			CALL	_Forward
;SurveyBot.c,50 :: 		if (flag==0)                  // check fisrt time Show LCD ?
$0115	$0861			MOVF	_flag, 0
$0116	$3A00			XORLW	0
$0117	$1D03			BTFSS	STATUS, Z
$0118	$292C			GOTO	L_main_19
;SurveyBot.c,52 :: 		flag=1;
$0119	$3001			MOVLW	1
$011A	$00E1			MOVWF	_flag
;SurveyBot.c,53 :: 		Lcd_Cmd(LCD_CLEAR);           // Show LCD
$011B	$3001			MOVLW	1
$011C	$00E9			MOVWF	FARG_Lcd_Cmd+0
$011D	$2284			CALL	_Lcd_Cmd
;SurveyBot.c,54 :: 		Lcd_Out(1,1,text4);
$011E	$3001			MOVLW	1
$011F	$00E4			MOVWF	FARG_LCD_Out+0
$0120	$3001			MOVLW	1
$0121	$00E5			MOVWF	FARG_LCD_Out+1
$0122	$0853			MOVF	_text4, 0
$0123	$00E6			MOVWF	FARG_LCD_Out+2
$0124	$22C2			CALL	_LCD_Out
;SurveyBot.c,55 :: 		Lcd_Out(2,1,text5);
$0125	$3002			MOVLW	2
$0126	$00E4			MOVWF	FARG_LCD_Out+0
$0127	$3001			MOVLW	1
$0128	$00E5			MOVWF	FARG_LCD_Out+1
$0129	$0860			MOVF	_text5, 0
$012A	$00E6			MOVWF	FARG_LCD_Out+2
$012B	$22C2			CALL	_LCD_Out
;SurveyBot.c,56 :: 		}
$012C	$	L_main_19:
;SurveyBot.c,57 :: 		}
$012C	$283E			GOTO	L_main_15
;SurveyBot.c,59 :: 		}
$012D	$292D			GOTO	$