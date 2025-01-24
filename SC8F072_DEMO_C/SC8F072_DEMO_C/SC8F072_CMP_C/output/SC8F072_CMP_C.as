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
	FNROOT	_main
	FNCALL	intlevel1,_CMP_Isr
	global	intlevel1
	FNROOT	intlevel1
	global	_OSCCON
psect	text0,local,class=CODE,delta=2,merge=1
global __ptext0
__ptext0:
_OSCCON	set	20
	global	_CMPCON1
_CMPCON1	set	16
	global	_CMPCON0
_CMPCON0	set	15
	global	_PIE1
_PIE1	set	14
	global	_ODCONB
_ODCONB	set	12
	global	_INTCON
_INTCON	set	11
	global	_IOCB
_IOCB	set	9
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
	global	_CMPEN
_CMPEN	set	127
	global	_CMPIF
_CMPIF	set	109
; #config settings
	file	"SC8F072_CMP_C.as"
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
?_CMP_Isr:	; 1 bytes @ 0x0
??_CMP_Isr:	; 1 bytes @ 0x0
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
;!Critical Paths under _CMP_Isr in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    None.
;!
;!Critical Paths under _CMP_Isr in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _CMP_Isr in BANK1
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
;! (1) _CMP_Isr                                              2     2      0       0
;!                                              0 COMMON     2     2      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 1
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!
;! _CMP_Isr (ROOT)
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
;;		line 14 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
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
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
	line	14
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
	line	14
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 7
; Regs used in _main: [wreg+status,2]
	line	16
	
l986:	
# 16 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
nop ;# 
	line	17
# 17 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
clrwdt ;# 
psect	maintext
	line	19
	
l988:	
;SC8F072_CMP_C.c: 19: OSCCON = 0x72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	20
;SC8F072_CMP_C.c: 20: OPTION_REG = 0x09;
	movlw	low(09h)
	movwf	(1)	;volatile
	line	23
	
l990:	
;SC8F072_CMP_C.c: 23: WPUB = 0B00000000;
	clrf	(8)	;volatile
	line	24
	
l992:	
;SC8F072_CMP_C.c: 24: WPDB = 0B00000000;
	clrf	(7)	;volatile
	line	25
	
l994:	
;SC8F072_CMP_C.c: 25: ODCONB = 0B00000000;
	clrf	(12)	;volatile
	line	26
	
l996:	
;SC8F072_CMP_C.c: 26: IOCB = 0B00000000;
	clrf	(9)	;volatile
	line	28
	
l998:	
;SC8F072_CMP_C.c: 28: TRISB = 0B00000000;
	clrf	(5)	;volatile
	line	54
	
l1000:	
;SC8F072_CMP_C.c: 54: CMPCON0 = 0B00111001;
	movlw	low(039h)
	movwf	(15)	;volatile
	line	69
	
l1002:	
;SC8F072_CMP_C.c: 69: CMPCON1 = 0B10010111;
	movlw	low(097h)
	movwf	(16)	;volatile
	line	72
	
l1004:	
;SC8F072_CMP_C.c: 72: INTCON = 0XC0;
	movlw	low(0C0h)
	movwf	(11)	;volatile
	line	73
	
l1006:	
;SC8F072_CMP_C.c: 73: PIE1 = 0X20;
	movlw	low(020h)
	movwf	(14)	;volatile
	line	74
	
l1008:	
;SC8F072_CMP_C.c: 74: CMPEN = 1;
	bsf	(127/8),(127)&7	;volatile
	line	75
	
l1010:	
;SC8F072_CMP_C.c: 75: CMPIF =0;
	bcf	(109/8),(109)&7	;volatile
	line	76
;SC8F072_CMP_C.c: 76: while(1)
	
l601:	
	line	78
# 78 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
clrwdt ;# 
psect	maintext
	goto	l601
	global	start
	ljmp	start
	opt stack 0
	line	82
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_CMP_Isr

;; *************** function _CMP_Isr *****************
;; Defined at:
;;		line 91 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
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
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	91
global __ptext1
__ptext1:	;psect for function _CMP_Isr
psect	text1
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_CMP_C\SC8F072_CMP_C.c"
	line	91
	global	__size_of_CMP_Isr
	__size_of_CMP_Isr	equ	__end_of_CMP_Isr-_CMP_Isr
	
_CMP_Isr:	
;incstack = 0
	opt	stack 7
; Regs used in _CMP_Isr: [wreg+status,2+status,0]
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_CMP_Isr+0)
	movf	pclath,w
	movwf	(??_CMP_Isr+1)
	ljmp	_CMP_Isr
psect	text1
	line	93
	
i1l1012:	
;SC8F072_CMP_C.c: 93: if(CMPIF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(109/8),(109)&7	;volatile
	goto	u1_21
	goto	u1_20
u1_21:
	goto	i1l610
u1_20:
	line	95
	
i1l1014:	
;SC8F072_CMP_C.c: 94: {
;SC8F072_CMP_C.c: 95: CMPIF = 0;
	bcf	(109/8),(109)&7	;volatile
	line	96
	
i1l1016:	
;SC8F072_CMP_C.c: 96: PORTB ^= 0X10;
	movlw	low(010h)
	xorwf	(6),f	;volatile
	line	99
	
i1l610:	
	movf	(??_CMP_Isr+1),w
	movwf	pclath
	swapf	(??_CMP_Isr+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_CMP_Isr
	__end_of_CMP_Isr:
	signat	_CMP_Isr,89
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
