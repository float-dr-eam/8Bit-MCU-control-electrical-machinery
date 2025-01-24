opt subtitle "Microchip Technology Omniscient Code Generator v1.45 (PRO mode) build 201711160504"

opt pagewidth 120

	opt pm

	processor	SC8F072
opt include "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\include\sc8f072.cgen.inc"
clrc	macro
	bcf	3,0
	endm
clrz	macro
	bcf	3,2
	endm
setc	macro
	bsf	3,0
	endm
setz	macro
	bsf	3,2
	endm
skipc	macro
	btfss	3,0
	endm
skipz	macro
	btfss	3,2
	endm
skipnc	macro
	btfsc	3,0
	endm
skipnz	macro
	btfsc	3,2
	endm
	FNCALL	_main,_Init_System
	FNROOT	_main
	global	_PWM01DT
psect	text0,local,class=CODE,delta=2,merge=1
global __ptext0
__ptext0:
_PWM01DT	set	31
	global	_PWMD01H
_PWMD01H	set	30
	global	_PWMCON2
_PWMCON2	set	29
	global	_PWMT4L
_PWMT4L	set	28
	global	_PWMD4L
_PWMD4L	set	27
	global	_PWMD1L
_PWMD1L	set	26
	global	_PWMD0L
_PWMD0L	set	25
	global	_PWMTH
_PWMTH	set	24
	global	_PWMTL
_PWMTL	set	23
	global	_PWMCON1
_PWMCON1	set	22
	global	_PWMCON0
_PWMCON0	set	21
	global	_OSCCON
_OSCCON	set	20
	global	_INTCON
_INTCON	set	11
	global	_PORTB
_PORTB	set	6
	global	_TRISB
_TRISB	set	5
	global	_OPTION_REG
_OPTION_REG	set	1
	global	_PWMD23H
_PWMD23H	set	158
	global	_PWMD3L
_PWMD3L	set	156
	global	_PWMD2L
_PWMD2L	set	155
	global	_PORTA
_PORTA	set	134
	global	_TRISA
_TRISA	set	133
; #config settings
	file	"SC8F072_Pwm_Demo.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect cinit,class=CODE,delta=2,merge=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_Init_System:	; 1 bytes @ 0x0
??_Init_System:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
??_main:	; 1 bytes @ 0x0
	global	main@delaycnt
main@delaycnt:	; 2 bytes @ 0x0
	ds	2
	global	main@pwmbuf
main@pwmbuf:	; 1 bytes @ 0x2
	ds	1
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         0
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14      3       3
;!    BANK0            80      0       0
;!    BANK1            80      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 3     3      0      45
;!                                              0 COMMON     3     3      0
;!                        _Init_System
;! ---------------------------------------------------------------------------------
;! (1) _Init_System                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _Init_System
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      3       3       1       21.4%
;!BITSFR0              0      0       0       1        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!SFR1                 0      0       0       2        0.0%
;!STACK                0      0       0       2        0.0%
;!BITBANK0            50      0       0       3        0.0%
;!BANK0               50      0       0       4        0.0%
;!BITBANK1            50      0       0       5        0.0%
;!BANK1               50      0       0       6        0.0%
;!ABS                  0      0       0       7        0.0%
;!DATA                 0      0       0       8        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 8 in file "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  delaycnt        2    0[COMMON] unsigned int 
;;  pwmbuf          1    2[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         3       0       0
;;      Temps:          0       0       0
;;      Totals:         3       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		_Init_System
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	8
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	8
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 7
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	10
	
l1001:	
;SC8F072_Pwm_Demo.c: 10: unsigned int delaycnt = 0;
	clrf	(main@delaycnt)
	clrf	(main@delaycnt+1)
	line	11
	
l1003:	
;SC8F072_Pwm_Demo.c: 11: unsigned char pwmbuf = 0X1F;
	movlw	low(01Fh)
	movwf	(main@pwmbuf)
	line	13
	
l1005:	
;SC8F072_Pwm_Demo.c: 13: Init_System();
	fcall	_Init_System
	line	35
	
l1007:	
;SC8F072_Pwm_Demo.c: 35: PWMCON1 = 0B11010010;
	movlw	low(0D2h)
	movwf	(22)	;volatile
	line	37
	
l1009:	
;SC8F072_Pwm_Demo.c: 37: TRISA = 0B00011111;
	movlw	low(01Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	38
	
l1011:	
;SC8F072_Pwm_Demo.c: 38: PWMTL = 0XFF;
	movlw	low(0FFh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(23)	;volatile
	line	39
	
l1013:	
;SC8F072_Pwm_Demo.c: 39: PWMT4L = 0XFF;
	movlw	low(0FFh)
	movwf	(28)	;volatile
	line	40
	
l1015:	
;SC8F072_Pwm_Demo.c: 40: PWMTH = 0X0C;
	movlw	low(0Ch)
	movwf	(24)	;volatile
	line	43
	
l1017:	
;SC8F072_Pwm_Demo.c: 43: PWMD0L = 0X1F;
	movlw	low(01Fh)
	movwf	(25)	;volatile
	line	46
	
l1019:	
;SC8F072_Pwm_Demo.c: 46: PWMD1L = 0X7F;
	movlw	low(07Fh)
	movwf	(26)	;volatile
	line	47
	
l1021:	
;SC8F072_Pwm_Demo.c: 47: PWMD01H = 0;
	clrf	(30)	;volatile
	line	49
	
l1023:	
;SC8F072_Pwm_Demo.c: 49: PWM01DT = 0X03;
	movlw	low(03h)
	movwf	(31)	;volatile
	line	52
	
l1025:	
;SC8F072_Pwm_Demo.c: 52: PWMD2L = 0X3F;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(155)^080h	;volatile
	line	53
	
l1027:	
;SC8F072_Pwm_Demo.c: 53: PWMD3L = 0X7F;
	movlw	low(07Fh)
	movwf	(156)^080h	;volatile
	line	54
	
l1029:	
;SC8F072_Pwm_Demo.c: 54: PWMD23H = 0;
	clrf	(158)^080h	;volatile
	line	56
	
l1031:	
;SC8F072_Pwm_Demo.c: 56: PWMD4L = 0X1F;
	movlw	low(01Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(27)	;volatile
	line	72
	
l1033:	
;SC8F072_Pwm_Demo.c: 72: PWMCON0 = 0X1F;
	movlw	low(01Fh)
	movwf	(21)	;volatile
	line	73
	
l1035:	
;SC8F072_Pwm_Demo.c: 73: PWMCON2 =0X10;
	movlw	low(010h)
	movwf	(29)	;volatile
	line	74
	
l1037:	
;SC8F072_Pwm_Demo.c: 74: TRISA = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(133)^080h	;volatile
	line	76
;SC8F072_Pwm_Demo.c: 76: while(1)
	
l603:	
	line	78
# 78 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	line	79
	
l1039:	
;SC8F072_Pwm_Demo.c: 79: if(++delaycnt > 5000)
	incf	(main@delaycnt),f
	skipnz
	incf	(main@delaycnt+1),f
	movlw	013h
	subwf	((main@delaycnt+1)),w
	movlw	089h
	skipnz
	subwf	((main@delaycnt)),w
	skipc
	goto	u11
	goto	u10
u11:
	goto	l603
u10:
	line	81
	
l1041:	
;SC8F072_Pwm_Demo.c: 80: {
;SC8F072_Pwm_Demo.c: 81: delaycnt = 0;
	clrf	(main@delaycnt)
	clrf	(main@delaycnt+1)
	line	82
	
l1043:	
;SC8F072_Pwm_Demo.c: 82: if(++pwmbuf > 0xfe)
	incf	(main@pwmbuf),f
		incf	(((main@pwmbuf))),w
	btfss	status,2
	goto	u21
	goto	u20
u21:
	goto	l605
u20:
	line	84
	
l1045:	
;SC8F072_Pwm_Demo.c: 83: {
;SC8F072_Pwm_Demo.c: 84: pwmbuf = 0x01f;
	movlw	low(01Fh)
	movwf	(main@pwmbuf)
	line	85
	
l605:	
	line	86
;SC8F072_Pwm_Demo.c: 85: }
;SC8F072_Pwm_Demo.c: 86: PWMD0L = pwmbuf;
	movf	(main@pwmbuf),w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(25)	;volatile
	goto	l603
	global	start
	ljmp	start
	opt stack 0
	line	89
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 99 in file "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	99
global __ptext1
__ptext1:	;psect for function _Init_System
psect	text1
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	99
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 7
; Regs used in _Init_System: [wreg+status,2]
	line	101
	
l987:	
# 101 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
	line	102
# 102 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text1
	line	103
	
l989:	
;SC8F072_Pwm_Demo.c: 103: INTCON = 0;
	clrf	(11)	;volatile
	line	104
	
l991:	
;SC8F072_Pwm_Demo.c: 104: OSCCON = 0X72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	105
	
l993:	
;SC8F072_Pwm_Demo.c: 105: OPTION_REG = 0;
	clrf	(1)	;volatile
	line	106
# 106 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text1
	line	108
;SC8F072_Pwm_Demo.c: 108: TRISA = 0B00011111;
	movlw	low(01Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	109
	
l995:	
;SC8F072_Pwm_Demo.c: 109: TRISB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(5)	;volatile
	line	111
	
l997:	
;SC8F072_Pwm_Demo.c: 111: PORTA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(134)^080h	;volatile
	line	112
	
l999:	
;SC8F072_Pwm_Demo.c: 112: PORTB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(6)	;volatile
	line	114
	
l611:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
