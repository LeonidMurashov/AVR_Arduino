;  ASM code generated by mikroVirtualMachine for PIC - V. 8.2.0.0
;  Date/Time: 4/6/2008 14:09:44
;  Info: http://www.mikroe.com


; ADDRESS	OPCODE	ASM
; ----------------------------------------------
$0000	$2850			GOTO	_main
$01B3	$	_Delay_1us:
;delays.c,7 :: 		void Delay_1us() {
;delays.c,8 :: 		Delay_us(1);
$01B3	$3001			MOVLW	1
$01B4	$1303			BCF	STATUS, RP1
$01B5	$1283			BCF	STATUS, RP0
$01B6	$00FA			MOVWF	STACK_10
$01B7	$0BFA			DECFSZ	STACK_10, F
$01B8	$29B7			GOTO	$-1
$01B9	$0000			NOP
;delays.c,9 :: 		}
$01BA	$0008			RETURN
$0199	$	_Delay_5500us:
;delays.c,31 :: 		void Delay_5500us() {
;delays.c,32 :: 		Delay_us(5500);
$0199	$3024			MOVLW	36
$019A	$1303			BCF	STATUS, RP1
$019B	$1283			BCF	STATUS, RP0
$019C	$00FB			MOVWF	STACK_11
$019D	$30FF			MOVLW	255
$019E	$00FA			MOVWF	STACK_10
$019F	$0BFB			DECFSZ	STACK_11, F
$01A0	$29A2			GOTO	$+2
$01A1	$29A5			GOTO	$+4
$01A2	$0BFA			DECFSZ	STACK_10, F
$01A3	$29A2			GOTO	$-1
$01A4	$299F			GOTO	$-5
$01A5	$309E			MOVLW	158
$01A6	$00FA			MOVWF	STACK_10
$01A7	$0BFA			DECFSZ	STACK_10, F
$01A8	$29A7			GOTO	$-1
;delays.c,33 :: 		}
$01A9	$0008			RETURN
$01C2	$	_Delay_50us:
;delays.c,19 :: 		void Delay_50us() {
;delays.c,20 :: 		Delay_us(50);
$01C2	$3053			MOVLW	83
$01C3	$1303			BCF	STATUS, RP1
$01C4	$1283			BCF	STATUS, RP0
$01C5	$00FA			MOVWF	STACK_10
$01C6	$0BFA			DECFSZ	STACK_10, F
$01C7	$29C6			GOTO	$-1
;delays.c,21 :: 		}
$01C8	$0008			RETURN
$00FB	$	_Lcd_Cmd:
$00FB	$1303			BCF	STATUS, RP1
$00FC	$1283			BCF	STATUS, RP0
$00FD	$0820			MOVF	LCD_port_address, 0
$00FE	$0084			MOVWF	FSR
$00FF	$083A			MOVF	FARG_Lcd_Cmd+0, 0
$0100	$1903			BTFSC	STATUS, Z
$0101	$2902			GOTO	L_Lcd_Cmd_0
$0102	$	L_Lcd_Cmd_0:
$0102	$1180			BCF	INDF, ___ENABLE
$0103	$1100			BCF	INDF, ___RS
$0104	$1380			BCF	INDF, ___DB7
$0105	$1300			BCF	INDF, ___DB6
$0106	$1280			BCF	INDF, ___DB5
$0107	$1200			BCF	INDF, ___DB4
$0108	$1BBA			BTFSC	FARG_Lcd_Cmd+0, 7
$0109	$1780			BSF	INDF, ___DB7
$010A	$1B3A			BTFSC	FARG_Lcd_Cmd+0, 6
$010B	$1700			BSF	INDF, ___DB6
$010C	$1ABA			BTFSC	FARG_Lcd_Cmd+0, 5
$010D	$1680			BSF	INDF, ___DB5
$010E	$1A3A			BTFSC	FARG_Lcd_Cmd+0, 4
$010F	$1600			BSF	INDF, ___DB4
$0110	$0821			MOVF	LCD_cmd_status, 0
$0111	$1903			BTFSC	STATUS, Z
$0112	$2915			GOTO	L_Lcd_Cmd_1
$0113	$1100			BCF	INDF, ___RS
$0114	$2916			GOTO	L_Lcd_Cmd_2
$0115	$	L_Lcd_Cmd_1:
$0115	$1500			BSF	INDF, ___RS
$0116	$	L_Lcd_Cmd_2:
$0116	$1580			BSF	INDF, ___ENABLE
$0117	$21B3			CALL	_Delay_1us
$0118	$083A			MOVF	FARG_Lcd_Cmd+0, 0
$0119	$1903			BTFSC	STATUS, Z
$011A	$291B			GOTO	L_Lcd_Cmd_3
$011B	$	L_Lcd_Cmd_3:
$011B	$1180			BCF	INDF, ___ENABLE
$011C	$1100			BCF	INDF, ___RS
$011D	$1380			BCF	INDF, ___DB7
$011E	$1300			BCF	INDF, ___DB6
$011F	$1280			BCF	INDF, ___DB5
$0120	$1200			BCF	INDF, ___DB4
$0121	$19BA			BTFSC	FARG_Lcd_Cmd+0, 3
$0122	$1780			BSF	INDF, ___DB7
$0123	$193A			BTFSC	FARG_Lcd_Cmd+0, 2
$0124	$1700			BSF	INDF, ___DB6
$0125	$18BA			BTFSC	FARG_Lcd_Cmd+0, 1
$0126	$1680			BSF	INDF, ___DB5
$0127	$183A			BTFSC	FARG_Lcd_Cmd+0, 0
$0128	$1600			BSF	INDF, ___DB4
$0129	$0821			MOVF	LCD_cmd_status, 0
$012A	$1903			BTFSC	STATUS, Z
$012B	$292E			GOTO	L_Lcd_Cmd_4
$012C	$1100			BCF	INDF, ___RS
$012D	$292F			GOTO	L_Lcd_Cmd_5
$012E	$	L_Lcd_Cmd_4:
$012E	$1500			BSF	INDF, ___RS
$012F	$	L_Lcd_Cmd_5:
$012F	$1580			BSF	INDF, ___ENABLE
$0130	$21B3			CALL	_Delay_1us
$0131	$1180			BCF	INDF, ___ENABLE
$0132	$0821			MOVF	LCD_cmd_status, 0
$0133	$1903			BTFSC	STATUS, Z
$0134	$2937			GOTO	L_Lcd_Cmd_6
$0135	$2199			CALL	_Delay_5500us
$0136	$2938			GOTO	L_Lcd_Cmd_7
$0137	$	L_Lcd_Cmd_6:
$0137	$21C2			CALL	_Delay_50us
$0138	$	L_Lcd_Cmd_7:
$0138	$0008			RETURN
$01AA	$	_Lcd_Chr_CP:
$01AA	$1303			BCF	STATUS, RP1
$01AB	$1283			BCF	STATUS, RP0
$01AC	$01A1			CLRF	LCD_cmd_status, 1
$01AD	$0839			MOVF	FARG_Lcd_Chr_CP+0, 0
$01AE	$00BA			MOVWF	FARG_Lcd_Cmd+0
$01AF	$20FB			CALL	_Lcd_Cmd
$01B0	$3001			MOVLW	1
$01B1	$00A1			MOVWF	LCD_cmd_status
$01B2	$0008			RETURN
$017C	$	_Div_16x16_U:
$017C	$1303			BCF	STATUS, RP1
$017D	$1283			BCF	STATUS, RP0
$017E	$01F8			CLRF	STACK_8
$017F	$01F9			CLRF	STACK_9
$0180	$3010			MOVLW	16
$0181	$00FC			MOVWF	STACK_12
$0182	$0D71			RLF	STACK_1, W
$0183	$0DF8			RLF	STACK_8, F
$0184	$0DF9			RLF	STACK_9, F
$0185	$0874			MOVF	STACK_4, W
$0186	$02F8			SUBWF	STACK_8, F
$0187	$0875			MOVF	STACK_5, W
$0188	$1C03			BTFSS	STATUS, C
$0189	$0F75			INCFSZ	STACK_5, W
$018A	$02F9			SUBWF	STACK_9, F
$018B	$1803			BTFSC	STATUS, C
$018C	$2994			GOTO	$+8
$018D	$0874			MOVF	STACK_4, W
$018E	$07F8			ADDWF	STACK_8, F
$018F	$0875			MOVF	STACK_5, W
$0190	$1803			BTFSC	STATUS, C
$0191	$0F75			INCFSZ	STACK_5, W
$0192	$07F9			ADDWF	STACK_9, F
$0193	$1003			BCF	STATUS, C
$0194	$0DF0			RLF	STACK_0, F
$0195	$0DF1			RLF	STACK_1, F
$0196	$0BFC			DECFSZ	STACK_12, F
$0197	$2982			GOTO	$-21
$0198	$0008			RETURN
$0004	$	_Lcd_Init:
$0004	$2199			CALL	_Delay_5500us
$0005	$2199			CALL	_Delay_5500us
$0006	$2199			CALL	_Delay_5500us
$0007	$0834			MOVF	FARG_Lcd_Init+0, 0
$0008	$00A0			MOVWF	LCD_port_address
$0009	$0834			MOVF	FARG_Lcd_Init+0, 0
$000A	$0084			MOVWF	FSR
$000B	$1784			BSF	FSR, 7
$000C	$1180			BCF	INDF, ___ENABLE
$000D	$1100			BCF	INDF, ___RS
$000E	$1000			BCF	INDF, ___RW
$000F	$1380			BCF	INDF, ___DB7
$0010	$1300			BCF	INDF, ___DB6
$0011	$1280			BCF	INDF, ___DB5
$0012	$1200			BCF	INDF, ___DB4
$0013	$1384			BCF	FSR, 7
$0014	$1180			BCF	INDF, ___ENABLE
$0015	$1100			BCF	INDF, ___RS
$0016	$1000			BCF	INDF, ___RW
$0017	$1380			BCF	INDF, ___DB7
$0018	$1300			BCF	INDF, ___DB6
$0019	$1280			BCF	INDF, ___DB5
$001A	$1200			BCF	INDF, ___DB4
$001B	$1680			BSF	INDF, ___DB5
$001C	$1600			BSF	INDF, ___DB4
$001D	$1580			BSF	INDF, ___ENABLE
$001E	$1180			BCF	INDF, ___ENABLE
$001F	$2199			CALL	_Delay_5500us
$0020	$1580			BSF	INDF, ___ENABLE
$0021	$1180			BCF	INDF, ___ENABLE
$0022	$2199			CALL	_Delay_5500us
$0023	$1580			BSF	INDF, ___ENABLE
$0024	$1180			BCF	INDF, ___ENABLE
$0025	$2199			CALL	_Delay_5500us
$0026	$1680			BSF	INDF, ___DB5
$0027	$1200			BCF	INDF, ___DB4
$0028	$1580			BSF	INDF, ___ENABLE
$0029	$1180			BCF	INDF, ___ENABLE
$002A	$2199			CALL	_Delay_5500us
$002B	$0180			CLRF	INDF
$002C	$1680			BSF	INDF, ___DB5
$002D	$1580			BSF	INDF, ___ENABLE
$002E	$1180			BCF	INDF, ___ENABLE
$002F	$0180			CLRF	INDF
$0030	$1780			BSF	INDF, ___DB7
$0031	$1580			BSF	INDF, ___ENABLE
$0032	$1180			BCF	INDF, ___ENABLE
$0033	$2199			CALL	_Delay_5500us
$0034	$0180			CLRF	INDF
$0035	$1600			BSF	INDF, ___DB4
$0036	$1580			BSF	INDF, ___ENABLE
$0037	$1180			BCF	INDF, ___ENABLE
$0038	$0180			CLRF	INDF
$0039	$1580			BSF	INDF, ___ENABLE
$003A	$1180			BCF	INDF, ___ENABLE
$003B	$2199			CALL	_Delay_5500us
$003C	$0180			CLRF	INDF
$003D	$1580			BSF	INDF, ___ENABLE
$003E	$1180			BCF	INDF, ___ENABLE
$003F	$1600			BSF	INDF, ___DB4
$0040	$1580			BSF	INDF, ___ENABLE
$0041	$1180			BCF	INDF, ___ENABLE
$0042	$2199			CALL	_Delay_5500us
$0043	$0180			CLRF	INDF
$0044	$1580			BSF	INDF, ___ENABLE
$0045	$1180			BCF	INDF, ___ENABLE
$0046	$1600			BSF	INDF, ___DB4
$0047	$1680			BSF	INDF, ___DB5
$0048	$1700			BSF	INDF, ___DB6
$0049	$1780			BSF	INDF, ___DB7
$004A	$1580			BSF	INDF, ___ENABLE
$004B	$1180			BCF	INDF, ___ENABLE
$004C	$2199			CALL	_Delay_5500us
$004D	$3001			MOVLW	1
$004E	$00A1			MOVWF	LCD_cmd_status
$004F	$0008			RETURN
$0139	$	_LCD_Out:
$0139	$294B			GOTO	L_LCD_Out_17
$013A	$	L_LCD_Out_19:
$013A	$3080			MOVLW	128
$013B	$1303			BCF	STATUS, RP1
$013C	$1283			BCF	STATUS, RP0
$013D	$00B4			MOVWF	FARG_LCD_Out+0
$013E	$295E			GOTO	L_LCD_Out_18
$013F	$	L_LCD_Out_20:
$013F	$30C0			MOVLW	192
$0140	$00B4			MOVWF	FARG_LCD_Out+0
$0141	$295E			GOTO	L_LCD_Out_18
$0142	$	L_LCD_Out_21:
$0142	$3094			MOVLW	148
$0143	$00B4			MOVWF	FARG_LCD_Out+0
$0144	$295E			GOTO	L_LCD_Out_18
$0145	$	L_LCD_Out_22:
$0145	$30D4			MOVLW	212
$0146	$00B4			MOVWF	FARG_LCD_Out+0
$0147	$295E			GOTO	L_LCD_Out_18
$0148	$	L_LCD_Out_23:
$0148	$3080			MOVLW	128
$0149	$00B4			MOVWF	FARG_LCD_Out+0
$014A	$295E			GOTO	L_LCD_Out_18
$014B	$	L_LCD_Out_17:
$014B	$1303			BCF	STATUS, RP1
$014C	$1283			BCF	STATUS, RP0
$014D	$0834			MOVF	FARG_LCD_Out+0, 0
$014E	$3A01			XORLW	1
$014F	$1903			BTFSC	STATUS, Z
$0150	$293A			GOTO	L_LCD_Out_19
$0151	$0834			MOVF	FARG_LCD_Out+0, 0
$0152	$3A02			XORLW	2
$0153	$1903			BTFSC	STATUS, Z
$0154	$293F			GOTO	L_LCD_Out_20
$0155	$0834			MOVF	FARG_LCD_Out+0, 0
$0156	$3A03			XORLW	3
$0157	$1903			BTFSC	STATUS, Z
$0158	$2942			GOTO	L_LCD_Out_21
$0159	$0834			MOVF	FARG_LCD_Out+0, 0
$015A	$3A04			XORLW	4
$015B	$1903			BTFSC	STATUS, Z
$015C	$2945			GOTO	L_LCD_Out_22
$015D	$2948			GOTO	L_LCD_Out_23
$015E	$	L_LCD_Out_18:
$015E	$0335			DECF	FARG_LCD_Out+1, 0
$015F	$00F0			MOVWF	STACK_0
$0160	$0834			MOVF	FARG_LCD_Out+0, 0
$0161	$07F0			ADDWF	STACK_0, 1
$0162	$0870			MOVF	STACK_0, 0
$0163	$00B4			MOVWF	FARG_LCD_Out+0
$0164	$0870			MOVF	STACK_0, 0
$0165	$00BA			MOVWF	FARG_Lcd_Cmd+0
$0166	$20FB			CALL	_Lcd_Cmd
$0167	$01A1			CLRF	LCD_cmd_status, 1
$0168	$01B7			CLRF	LCD_Out_i_L0, 1
$0169	$	L_LCD_Out_24:
$0169	$0837			MOVF	LCD_Out_i_L0, 0
$016A	$0736			ADDWF	FARG_LCD_Out+2, 0
$016B	$0084			MOVWF	FSR
$016C	$0800			MOVF	INDF, 0
$016D	$00F0			MOVWF	STACK_0
$016E	$0870			MOVF	STACK_0, 0
$016F	$1903			BTFSC	STATUS, Z
$0170	$2979			GOTO	L_LCD_Out_25
$0171	$0837			MOVF	LCD_Out_i_L0, 0
$0172	$0736			ADDWF	FARG_LCD_Out+2, 0
$0173	$0084			MOVWF	FSR
$0174	$0800			MOVF	INDF, 0
$0175	$00B9			MOVWF	FARG_Lcd_Chr_CP+0
$0176	$21AA			CALL	_Lcd_Chr_CP
$0177	$0AB7			INCF	LCD_Out_i_L0, 1
$0178	$2969			GOTO	L_LCD_Out_24
$0179	$	L_LCD_Out_25:
$0179	$3001			MOVLW	1
$017A	$00A1			MOVWF	LCD_cmd_status
$017B	$0008			RETURN
$00A6	$	_WordToStr:
$00A6	$1303			BCF	STATUS, RP1
$00A7	$1283			BCF	STATUS, RP0
$00A8	$0836			MOVF	FARG_WordToStr+2, 0
$00A9	$0084			MOVWF	FSR
$00AA	$3020			MOVLW	32
$00AB	$0080			MOVWF	INDF
$00AC	$0A36			INCF	FARG_WordToStr+2, 0
$00AD	$00F0			MOVWF	STACK_0
$00AE	$0870			MOVF	STACK_0, 0
$00AF	$0084			MOVWF	FSR
$00B0	$3020			MOVLW	32
$00B1	$0080			MOVWF	INDF
$00B2	$3002			MOVLW	2
$00B3	$0736			ADDWF	FARG_WordToStr+2, 0
$00B4	$00F0			MOVWF	STACK_0
$00B5	$0870			MOVF	STACK_0, 0
$00B6	$0084			MOVWF	FSR
$00B7	$3020			MOVLW	32
$00B8	$0080			MOVWF	INDF
$00B9	$3003			MOVLW	3
$00BA	$0736			ADDWF	FARG_WordToStr+2, 0
$00BB	$00F0			MOVWF	STACK_0
$00BC	$0870			MOVF	STACK_0, 0
$00BD	$0084			MOVWF	FSR
$00BE	$3020			MOVLW	32
$00BF	$0080			MOVWF	INDF
$00C0	$3004			MOVLW	4
$00C1	$0736			ADDWF	FARG_WordToStr+2, 0
$00C2	$00F0			MOVWF	STACK_0
$00C3	$0870			MOVF	STACK_0, 0
$00C4	$0084			MOVWF	FSR
$00C5	$3030			MOVLW	48
$00C6	$0080			MOVWF	INDF
$00C7	$3005			MOVLW	5
$00C8	$0736			ADDWF	FARG_WordToStr+2, 0
$00C9	$00F0			MOVWF	STACK_0
$00CA	$0870			MOVF	STACK_0, 0
$00CB	$0084			MOVWF	FSR
$00CC	$0180			CLRF	INDF, 1
$00CD	$3004			MOVLW	4
$00CE	$00B7			MOVWF	WordToStr_pos_L0
$00CF	$	L_WordToStr_4:
$00CF	$0835			MOVF	FARG_WordToStr+1, 0
$00D0	$3C00			SUBLW	0
$00D1	$1D03			BTFSS	STATUS, Z
$00D2	$28D5			GOTO	L_WordToStr_51
$00D3	$0834			MOVF	FARG_WordToStr+0, 0
$00D4	$3C00			SUBLW	0
$00D5	$	L_WordToStr_51:
$00D5	$1803			BTFSC	STATUS, C
$00D6	$28FA			GOTO	L_WordToStr_5
$00D7	$0837			MOVF	WordToStr_pos_L0, 0
$00D8	$0736			ADDWF	FARG_WordToStr+2, 0
$00D9	$00B8			MOVWF	FLOC_WordToStr+1
$00DA	$300A			MOVLW	10
$00DB	$00F4			MOVWF	STACK_4
$00DC	$01F5			CLRF	STACK_4+1
$00DD	$0834			MOVF	FARG_WordToStr+0, 0
$00DE	$00F0			MOVWF	STACK_0
$00DF	$0835			MOVF	FARG_WordToStr+1, 0
$00E0	$00F1			MOVWF	STACK_0+1
$00E1	$217C			CALL	_div_16x16_u
$00E2	$0878			MOVF	STACK_8, 0
$00E3	$00F0			MOVWF	STACK_0
$00E4	$0879			MOVF	STACK_9, 0
$00E5	$00F1			MOVWF	STACK_1
$00E6	$3030			MOVLW	48
$00E7	$07F0			ADDWF	STACK_0, 1
$00E8	$0838			MOVF	FLOC_WordToStr+1, 0
$00E9	$0084			MOVWF	FSR
$00EA	$0870			MOVF	STACK_0, 0
$00EB	$0080			MOVWF	INDF
$00EC	$300A			MOVLW	10
$00ED	$00F4			MOVWF	STACK_4
$00EE	$01F5			CLRF	STACK_4+1
$00EF	$0834			MOVF	FARG_WordToStr+0, 0
$00F0	$00F0			MOVWF	STACK_0
$00F1	$0835			MOVF	FARG_WordToStr+1, 0
$00F2	$00F1			MOVWF	STACK_0+1
$00F3	$217C			CALL	_div_16x16_u
$00F4	$0870			MOVF	STACK_0, 0
$00F5	$00B4			MOVWF	FARG_WordToStr+0
$00F6	$0871			MOVF	STACK_0+1, 0
$00F7	$00B5			MOVWF	FARG_WordToStr+1
$00F8	$03B7			DECF	WordToStr_pos_L0, 1
$00F9	$28CF			GOTO	L_WordToStr_4
$00FA	$	L_WordToStr_5:
$00FA	$0008			RETURN
$01BB	$	GlobalIniLCDNum_Test:
$01BB	$3000			MOVLW	0
$01BC	$1303			BCF	STATUS, RP1
$01BD	$1283			BCF	STATUS, RP0
$01BE	$00A2			MOVWF	_i+0
$01BF	$3000			MOVLW	0
$01C0	$00A3			MOVWF	_i+1
$01C1	$0008			RETURN
$0050	$	_main:
$0050	$21BB			CALL	GlobalIniLCDNum_Test
$0051	$3043			MOVLW	67
$0052	$00AA			MOVWF	lstr1_LCDNum_Test+0
$0053	$306F			MOVLW	111
$0054	$00AB			MOVWF	lstr1_LCDNum_Test+1
$0055	$3075			MOVLW	117
$0056	$00AC			MOVWF	lstr1_LCDNum_Test+2
$0057	$306E			MOVLW	110
$0058	$00AD			MOVWF	lstr1_LCDNum_Test+3
$0059	$3074			MOVLW	116
$005A	$00AE			MOVWF	lstr1_LCDNum_Test+4
$005B	$3065			MOVLW	101
$005C	$00AF			MOVWF	lstr1_LCDNum_Test+5
$005D	$3072			MOVLW	114
$005E	$00B0			MOVWF	lstr1_LCDNum_Test+6
$005F	$303D			MOVLW	61
$0060	$00B1			MOVWF	lstr1_LCDNum_Test+7
$0061	$3020			MOVLW	32
$0062	$00B2			MOVWF	lstr1_LCDNum_Test+8
$0063	$01B3			CLRF	lstr1_LCDNum_Test+9
;LCDNum_Test.c,3 :: 		void main()
;LCDNum_Test.c,5 :: 		Lcd_Init(&PORTD);                // Config PORTD connect LCD
$0064	$3008			MOVLW	PORTD
$0065	$00B4			MOVWF	FARG_Lcd_Init+0
$0066	$2004			CALL	_Lcd_Init
;LCDNum_Test.c,6 :: 		Lcd_Cmd(LCD_CURSOR_OFF);         // Setting cursor of LCD off
$0067	$300C			MOVLW	12
$0068	$00BA			MOVWF	FARG_Lcd_Cmd+0
$0069	$20FB			CALL	_Lcd_Cmd
;LCDNum_Test.c,7 :: 		Lcd_Cmd(LCD_CLEAR);              // Clear Screen First
$006A	$3001			MOVLW	1
$006B	$00BA			MOVWF	FARG_Lcd_Cmd+0
$006C	$20FB			CALL	_Lcd_Cmd
;LCDNum_Test.c,8 :: 		Lcd_Out(1,1,"Counter= ");        // Show Text
$006D	$3001			MOVLW	1
$006E	$00B4			MOVWF	FARG_LCD_Out+0
$006F	$3001			MOVLW	1
$0070	$00B5			MOVWF	FARG_LCD_Out+1
$0071	$302A			MOVLW	lstr1_LCDNum_Test
$0072	$00B6			MOVWF	FARG_LCD_Out+2
$0073	$2139			CALL	_LCD_Out
;LCDNum_Test.c,10 :: 		while(1)
$0074	$	L_main_0:
;LCDNum_Test.c,12 :: 		i++;                          // Count
$0074	$0AA2			INCF	_i, 1
$0075	$1903			BTFSC	STATUS, Z
$0076	$0AA3			INCF	_i+1, 1
;LCDNum_Test.c,13 :: 		WordToStr(i,txt);             // Convert to String
$0077	$0822			MOVF	_i, 0
$0078	$00B4			MOVWF	FARG_WordToStr+0
$0079	$0823			MOVF	_i+1, 0
$007A	$00B5			MOVWF	FARG_WordToStr+1
$007B	$3024			MOVLW	_txt
$007C	$00B6			MOVWF	FARG_WordToStr+2
$007D	$20A6			CALL	_WordToStr
;LCDNum_Test.c,14 :: 		Lcd_Out(1,10,txt);            // Show Counter ==> LCD
$007E	$3001			MOVLW	1
$007F	$00B4			MOVWF	FARG_LCD_Out+0
$0080	$300A			MOVLW	10
$0081	$00B5			MOVWF	FARG_LCD_Out+1
$0082	$3024			MOVLW	_txt
$0083	$00B6			MOVWF	FARG_LCD_Out+2
$0084	$2139			CALL	_LCD_Out
;LCDNum_Test.c,15 :: 		Delay_ms(100);
$0085	$3003			MOVLW	3
$0086	$00FC			MOVWF	STACK_12
$0087	$30FF			MOVLW	255
$0088	$00FB			MOVWF	STACK_11
$0089	$30FF			MOVLW	255
$008A	$00FA			MOVWF	STACK_10
$008B	$0BFC			DECFSZ	STACK_12, F
$008C	$288E			GOTO	$+2
$008D	$2895			GOTO	$+8
$008E	$0BFB			DECFSZ	STACK_11, F
$008F	$2891			GOTO	$+2
$0090	$2894			GOTO	$+4
$0091	$0BFA			DECFSZ	STACK_10, F
$0092	$2891			GOTO	$-1
$0093	$288E			GOTO	$-5
$0094	$288B			GOTO	$-9
$0095	$308C			MOVLW	140
$0096	$00FB			MOVWF	STACK_11
$0097	$30FF			MOVLW	255
$0098	$00FA			MOVWF	STACK_10
$0099	$0BFB			DECFSZ	STACK_11, F
$009A	$289C			GOTO	$+2
$009B	$289F			GOTO	$+4
$009C	$0BFA			DECFSZ	STACK_10, F
$009D	$289C			GOTO	$-1
$009E	$2899			GOTO	$-5
$009F	$30A1			MOVLW	161
$00A0	$00FA			MOVWF	STACK_10
$00A1	$0BFA			DECFSZ	STACK_10, F
$00A2	$28A1			GOTO	$-1
$00A3	$0000			NOP
;LCDNum_Test.c,16 :: 		}
$00A4	$2874			GOTO	L_main_0
;LCDNum_Test.c,17 :: 		}
$00A5	$28A5			GOTO	$
