;  ASM code generated by mikroVirtualMachine for PIC - V. 8.2.0.0
;  Date/Time: 4/6/2008 14:00:10
;  Info: http://www.mikroe.com


; ADDRESS	OPCODE	ASM
; ----------------------------------------------
$0000	$2804			GOTO	_main
$0004	$	_main:
;RB3_LED01.c,1 :: 		void main()
;RB3_LED01.c,3 :: 		TRISB.F3=0;     // Set RB3 ==> Output
$0004	$1303			BCF	STATUS, RP1
$0005	$1683			BSF	STATUS, RP0
$0006	$1186			BCF	TRISB, 3
;RB3_LED01.c,4 :: 		PORTB.F3=1;     // Turn on RB3
$0007	$1283			BCF	STATUS, RP0
$0008	$1586			BSF	PORTB, 3
;RB3_LED01.c,5 :: 		}
$0009	$2809			GOTO	$