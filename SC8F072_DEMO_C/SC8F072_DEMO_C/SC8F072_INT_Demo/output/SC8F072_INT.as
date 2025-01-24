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
	FNROOT	_main
	FNCALL	intlevel1,_PB_Isr
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
	global	_IOCB
_IOCB	set	9
	global	_WPUB
_WPUB	set	8
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
	global	_RBIF
_RBIF	set	88
	global	_RBIE
_RBIE	set	91
	global	_PORTA
_PORTA	set	134
	global	_TRISA
_TRISA	set	133
	global	_RA2
_RA2	set	1074
; #config settings
	file	"SC8F072_INT.as"
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
?_main:	; 1 bytes @ 0x0
?_PB_Isr:	; 1 bytes @ 0x0
??_PB_Isr:	; 1 bytes @ 0x0
	ds	2
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
;!Critical Paths under _PB_Isr in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _PB_Isr in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _PB_Isr in BANK1
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
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 0
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (1) _PB_Isr                                               2     2      0       0
;!                                              0 COMMON     2     2      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!
;! _PB_Isr (ROOT)
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
;;		line 14 in file "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
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
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
	line	14
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
	line	14
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 7
; Regs used in _main: [wreg+status,2]
	line	16
	
l987:	
# 16 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
nop ;# 
	line	17
# 17 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
clrwdt ;# 
psect	maintext
	line	19
	
l989:	
;PB_Interrupt_Demo.c: 19: OSCCON = 0x70;
	movlw	low(070h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	20
	
l991:	
;PB_Interrupt_Demo.c: 20: OPTION_REG = 0;
	clrf	(1)	;volatile
	line	21
	
l993:	
;PB_Interrupt_Demo.c: 21: TRISA = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(133)^080h	;volatile
	line	23
;PB_Interrupt_Demo.c: 23: PR2 = 249;
	movlw	low(0F9h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(17)	;volatile
	line	24
	
l995:	
;PB_Interrupt_Demo.c: 24: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	25
	
l997:	
;PB_Interrupt_Demo.c: 25: TMR2IE = 1;
	bsf	(113/8),(113)&7	;volatile
	line	27
;PB_Interrupt_Demo.c: 27: T2CON = 0B00000101;
	movlw	low(05h)
	movwf	(19)	;volatile
	line	30
;PB_Interrupt_Demo.c: 30: WPUB = 0B00001000;
	movlw	low(08h)
	movwf	(8)	;volatile
	line	31
;PB_Interrupt_Demo.c: 31: TRISB = 0B00001000;
	movlw	low(08h)
	movwf	(5)	;volatile
	line	32
;PB_Interrupt_Demo.c: 32: IOCB = 0B00001000;
	movlw	low(08h)
	movwf	(9)	;volatile
	line	33
	
l999:	
;PB_Interrupt_Demo.c: 33: RBIE = 1;
	bsf	(91/8),(91)&7	;volatile
	line	34
;PB_Interrupt_Demo.c: 34: INTCON = 0xC8;
	movlw	low(0C8h)
	movwf	(11)	;volatile
	line	35
;PB_Interrupt_Demo.c: 35: PORTB;
	movf	(6),w	;volatile
	line	38
;PB_Interrupt_Demo.c: 38: while(1)
	
l601:	
	line	40
# 40 "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
clrwdt ;# 
psect	maintext
	goto	l601
	global	start
	ljmp	start
	opt stack 0
	line	42
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_PB_Isr

;; *************** function _PB_Isr *****************
;; Defined at:
;;		line 52 in file "C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
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
;;		On exit  : 0/0
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
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	52
global __ptext1
__ptext1:	;psect for function _PB_Isr
psect	text1
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_DEMO_C\SC8F072_DEMO_C\SC8F072_INT_Demo\PB_Interrupt_Demo.c"
	line	52
	global	__size_of_PB_Isr
	__size_of_PB_Isr	equ	__end_of_PB_Isr-_PB_Isr
	
_PB_Isr:	
;incstack = 0
	opt	stack 7
; Regs used in _PB_Isr: [wreg+status,2+status,0]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_PB_Isr+0)
	movf	pclath,w
	movwf	(??_PB_Isr+1)
	ljmp	_PB_Isr
psect	text1
	line	54
	
i1l1001:	
;PB_Interrupt_Demo.c: 54: if(RBIF)
	btfss	(88/8),(88)&7	;volatile
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l1007
u1_20:
	line	56
	
i1l1003:	
;PB_Interrupt_Demo.c: 55: {
;PB_Interrupt_Demo.c: 56: RBIF = 0;
	bcf	(88/8),(88)&7	;volatile
	line	57
	
i1l1005:	
;PB_Interrupt_Demo.c: 57: RA2 = !RA2;
	movlw	1<<((1074)&7)
	bsf	status, 5	;RP0=1, select bank1
	xorwf	((1074)/8)^080h,f
	line	58
;PB_Interrupt_Demo.c: 58: PORTB;
	bcf	status, 5	;RP0=0, select bank0
	movf	(6),w	;volatile
	line	61
	
i1l1007:	
;PB_Interrupt_Demo.c: 60: }
;PB_Interrupt_Demo.c: 61: if(TMR2IF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(105/8),(105)&7	;volatile
	goto	u2_21
	goto	u2_20
u2_21:
	goto	i1l611
u2_20:
	line	63
	
i1l1009:	
;PB_Interrupt_Demo.c: 62: {
;PB_Interrupt_Demo.c: 63: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	65
	
i1l1011:	
;PB_Interrupt_Demo.c: 65: PORTA ^= 0X02;
	movlw	low(02h)
	bsf	status, 5	;RP0=1, select bank1
	xorwf	(134)^080h,f	;volatile
	line	67
	
i1l611:	
	movf	(??_PB_Isr+1),w
	movwf	pclath
	swapf	(??_PB_Isr+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_PB_Isr
	__end_of_PB_Isr:
	signat	_PB_Isr,89
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
