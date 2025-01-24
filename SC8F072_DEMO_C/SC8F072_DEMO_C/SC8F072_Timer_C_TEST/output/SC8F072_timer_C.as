opt subtitle "Microchip Technology Omniscient Code Generator v1.45 (PRO mode) build 201711160504"

opt pagewidth 120

	opt pm

	processor	SC8F072
opt include "H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Beta5\data\include\sc8f072.cgen.inc"
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
	FNCALL	intlevel1,_Timer_Isr
	global	intlevel1
	FNROOT	intlevel1
	global	_OSCCON
psect	text0,local,class=CODE,delta=2,merge=1
global __ptext0
__ptext0:
_OSCCON	set	20
	global	_T2CON
_T2CON	set	19
	global	_PR2
_PR2	set	17
	global	_INTCON
_INTCON	set	11
	global	_WPUB
_WPUB	set	8
	global	_WPDB
_WPDB	set	7
	global	_PORTB
_PORTB	set	6
	global	_TRISB
_TRISB	set	5
	global	_OPTION_REG
_OPTION_REG	set	1
	global	_TMR2IE
_TMR2IE	set	113
	global	_TMR2IF
_TMR2IF	set	105
; #config settings
	file	"SC8F072_timer_C.as"
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
?_main:	; 1 bytes @ 0x0
?_Timer_Isr:	; 1 bytes @ 0x0
??_Timer_Isr:	; 1 bytes @ 0x0
	ds	2
??_Init_System:	; 1 bytes @ 0x2
??_main:	; 1 bytes @ 0x2
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
;!    COMMON           14      2       2
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
;!Critical Paths under _Timer_Isr in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _Timer_Isr in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _Timer_Isr in BANK1
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
;! (0) _main                                                 0     0      0       0
;!                        _Init_System
;! ---------------------------------------------------------------------------------
;! (1) _Init_System                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (2) _Timer_Isr                                            2     2      0       0
;!                                              0 COMMON     2     2      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _Init_System
;!
;! _Timer_Isr (ROOT)
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      2       2       1       14.3%
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
;;		line 16 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : B00/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_Init_System
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
	line	16
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
	line	16
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 6
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	18
	
l1013:	
;SC8F072_Timer2_C.c: 18: Init_System();
	fcall	_Init_System
	line	19
;SC8F072_Timer2_C.c: 19: while(1)
	
l603:	
	line	21
# 21 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
clrwdt ;# 
psect	maintext
	goto	l603
	global	start
	ljmp	start
	opt stack 0
	line	23
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 49 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
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
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	49
global __ptext1
__ptext1:	;psect for function _Init_System
psect	text1
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
	line	49
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 6
; Regs used in _Init_System: [wreg+status,2]
	line	51
	
l991:	
# 51 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
nop ;# 
	line	52
# 52 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
clrwdt ;# 
psect	text1
	line	53
	
l993:	
;SC8F072_Timer2_C.c: 53: INTCON = 0;
	clrf	(11)	;volatile
	line	54
	
l995:	
;SC8F072_Timer2_C.c: 54: OSCCON = 0x72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	55
	
l997:	
;SC8F072_Timer2_C.c: 55: OPTION_REG = 0x00;
	clrf	(1)	;volatile
	line	56
# 56 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
clrwdt ;# 
psect	text1
	line	58
;SC8F072_Timer2_C.c: 58: WPUB = 0B00111000;
	movlw	low(038h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(8)	;volatile
	line	59
	
l999:	
;SC8F072_Timer2_C.c: 59: WPDB = 0B00000000;
	clrf	(7)	;volatile
	line	60
	
l1001:	
;SC8F072_Timer2_C.c: 60: TRISB = 0B00111000;
	movlw	low(038h)
	movwf	(5)	;volatile
	line	61
;SC8F072_Timer2_C.c: 61: PORTB = 0B00000000;
	clrf	(6)	;volatile
	line	93
	
l1003:	
;SC8F072_Timer2_C.c: 93: PR2 = 249;
	movlw	low(0F9h)
	movwf	(17)	;volatile
	line	94
	
l1005:	
;SC8F072_Timer2_C.c: 94: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	95
	
l1007:	
;SC8F072_Timer2_C.c: 95: TMR2IE = 1;
	bsf	(113/8),(113)&7	;volatile
	line	97
	
l1009:	
;SC8F072_Timer2_C.c: 97: T2CON = 0B00000101;
	movlw	low(05h)
	movwf	(19)	;volatile
	line	99
	
l1011:	
;SC8F072_Timer2_C.c: 99: INTCON = 0XC0;
	movlw	low(0C0h)
	movwf	(11)	;volatile
	line	101
	
l615:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
	global	_Timer_Isr

;; *************** function _Timer_Isr *****************
;; Defined at:
;;		line 33 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          2       0       0
;;      Totals:         2       0       0
;;Total ram usage:        2 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	33
global __ptext2
__ptext2:	;psect for function _Timer_Isr
psect	text2
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Timer_C_TEST\SC8F072_Timer2_C.c"
	line	33
	global	__size_of_Timer_Isr
	__size_of_Timer_Isr	equ	__end_of_Timer_Isr-_Timer_Isr
	
_Timer_Isr:	
;incstack = 0
	opt	stack 6
; Regs used in _Timer_Isr: [wreg+status,2+status,0]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_Timer_Isr+0)
	movf	pclath,w
	movwf	(??_Timer_Isr+1)
	ljmp	_Timer_Isr
psect	text2
	line	35
	
i1l1015:	
;SC8F072_Timer2_C.c: 35: if(TMR2IF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(105/8),(105)&7	;volatile
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l612
u1_20:
	line	37
	
i1l1017:	
;SC8F072_Timer2_C.c: 36: {
;SC8F072_Timer2_C.c: 37: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	38
	
i1l1019:	
;SC8F072_Timer2_C.c: 38: PORTB ^= 0X01;
	movlw	low(01h)
	xorwf	(6),f	;volatile
	line	40
	
i1l612:	
	movf	(??_Timer_Isr+1),w
	movwf	pclath
	swapf	(??_Timer_Isr+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_Timer_Isr
	__end_of_Timer_Isr:
	signat	_Timer_Isr,89
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
