opt subtitle "Microchip Technology Omniscient Code Generator v1.45 (PRO mode) build 201711160504"

opt pagewidth 120

	opt pm

	processor	SC8F072
opt include "H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\include\sc8f072.cgen.inc"
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
	FNCALL	_main,_DelayXms
	FNCALL	_main,_Init_System
	FNCALL	_main,_Sleep_Mode
	FNCALL	_Sleep_Mode,_Init_System
	FNROOT	_main
	global	_PWMCON0
psect	text0,local,class=CODE,delta=2,merge=1
global __ptext0
__ptext0:
_PWMCON0	set	21
	global	_OSCCON
_OSCCON	set	20
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
	global	_RAIE
_RAIE	set	115
	global	_RAIF
_RAIF	set	107
	global	_RBIF
_RBIF	set	88
	global	_RBIE
_RBIE	set	91
	global	_PEIE
_PEIE	set	94
	global	_GIE
_GIE	set	95
	global	_RB6
_RB6	set	54
	global	_ADCON1
_ADCON1	set	150
	global	_ADCON0
_ADCON0	set	149
	global	_IOCA
_IOCA	set	137
	global	_WPUA
_WPUA	set	136
	global	_PORTA
_PORTA	set	134
	global	_TRISA
_TRISA	set	133
; #config settings
	file	"SC8F072_Sleep_Demo.as"
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
?_Sleep_Mode:	; 1 bytes @ 0x0
??_Sleep_Mode:	; 1 bytes @ 0x0
?_DelayXms:	; 1 bytes @ 0x0
??_DelayXms:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
	global	DelayXms@x
DelayXms@x:	; 1 bytes @ 0x0
	ds	1
	global	DelayXms@i
DelayXms@i:	; 1 bytes @ 0x1
	ds	1
	global	DelayXms@j
DelayXms@j:	; 1 bytes @ 0x2
	ds	1
??_main:	; 1 bytes @ 0x3
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
;!    _main->_DelayXms
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
;! (0) _main                                                 0     0      0      75
;!                           _DelayXms
;!                        _Init_System
;!                         _Sleep_Mode
;! ---------------------------------------------------------------------------------
;! (1) _Sleep_Mode                                           0     0      0       0
;!                        _Init_System
;! ---------------------------------------------------------------------------------
;! (2) _Init_System                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _DelayXms                                             3     3      0      75
;!                                              0 COMMON     3     3      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _DelayXms
;!   _Init_System
;!   _Sleep_Mode
;!     _Init_System
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
;;		line 37 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
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
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_DelayXms
;;		_Init_System
;;		_Sleep_Mode
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
	line	37
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
	line	37
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 6
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	39
	
l1049:	
;SC8F072_Sleep_Demo.c: 39: Init_System();
	fcall	_Init_System
	line	42
	
l1051:	
;SC8F072_Sleep_Demo.c: 41: {
;SC8F072_Sleep_Demo.c: 42: RB6=1;
	bsf	(54/8),(54)&7	;volatile
	line	43
;SC8F072_Sleep_Demo.c: 43: DelayXms(100);
	movlw	low(064h)
	fcall	_DelayXms
	line	44
	
l1053:	
;SC8F072_Sleep_Demo.c: 44: RB6 = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(54/8),(54)&7	;volatile
	line	45
;SC8F072_Sleep_Demo.c: 45: DelayXms(100);
	movlw	low(064h)
	fcall	_DelayXms
	line	46
	
l1055:	
;SC8F072_Sleep_Demo.c: 46: RB6=1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(54/8),(54)&7	;volatile
	line	47
;SC8F072_Sleep_Demo.c: 47: DelayXms(100);
	movlw	low(064h)
	fcall	_DelayXms
	line	48
;SC8F072_Sleep_Demo.c: 48: Sleep_Mode();
	fcall	_Sleep_Mode
	goto	l1051
	global	start
	ljmp	start
	opt stack 0
	line	50
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_Sleep_Mode

;; *************** function _Sleep_Mode *****************
;; Defined at:
;;		line 60 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
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
;;		_Init_System
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	line	60
global __ptext1
__ptext1:	;psect for function _Sleep_Mode
psect	text1
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
	line	60
	global	__size_of_Sleep_Mode
	__size_of_Sleep_Mode	equ	__end_of_Sleep_Mode-_Sleep_Mode
	
_Sleep_Mode:	
;incstack = 0
	opt	stack 6
; Regs used in _Sleep_Mode: [wreg+status,2+status,0+pclath+cstack]
	line	62
	
l1001:	
;SC8F072_Sleep_Demo.c: 62: INTCON = 0;
	clrf	(11)	;volatile
	line	64
;SC8F072_Sleep_Demo.c: 64: OPTION_REG = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(1)	;volatile
	line	66
	
l1003:	
;SC8F072_Sleep_Demo.c: 66: TRISA = 0B00000001;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	67
	
l1005:	
;SC8F072_Sleep_Demo.c: 67: WPUA = 0B00000001;
	movlw	low(01h)
	movwf	(136)^080h	;volatile
	line	69
	
l1007:	
;SC8F072_Sleep_Demo.c: 69: TRISB = 0B00001000;
	movlw	low(08h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	70
	
l1009:	
;SC8F072_Sleep_Demo.c: 70: PORTB = 0B00000000;
	clrf	(6)	;volatile
	line	71
;SC8F072_Sleep_Demo.c: 71: WPUB = 0B00001000;
	movlw	low(08h)
	movwf	(8)	;volatile
	line	73
	
l1011:	
;SC8F072_Sleep_Demo.c: 73: ADCON0 = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(149)^080h	;volatile
	line	74
	
l1013:	
;SC8F072_Sleep_Demo.c: 74: ADCON1 = 0;
	clrf	(150)^080h	;volatile
	line	76
	
l1015:	
;SC8F072_Sleep_Demo.c: 76: PWMCON0 = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(21)	;volatile
	line	78
	
l1017:	
;SC8F072_Sleep_Demo.c: 78: OSCCON = 0X70;
	movlw	low(070h)
	movwf	(20)	;volatile
	line	80
	
l1019:	
;SC8F072_Sleep_Demo.c: 80: IOCA = 0B00000001;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(137)^080h	;volatile
	line	81
	
l1021:	
;SC8F072_Sleep_Demo.c: 81: IOCB = 0B00001000;
	movlw	low(08h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(9)	;volatile
	line	83
	
l1023:	
;SC8F072_Sleep_Demo.c: 83: RAIE = 1;
	bsf	(115/8),(115)&7	;volatile
	line	84
	
l1025:	
;SC8F072_Sleep_Demo.c: 84: PEIE = 1;
	bsf	(94/8),(94)&7	;volatile
	line	85
	
l1027:	
;SC8F072_Sleep_Demo.c: 85: RBIE = 1;
	bsf	(91/8),(91)&7	;volatile
	line	86
	
l1029:	
;SC8F072_Sleep_Demo.c: 86: GIE = 0;
	bcf	(95/8),(95)&7	;volatile
	line	89
	
l1031:	
;SC8F072_Sleep_Demo.c: 89: PORTA;
	bsf	status, 5	;RP0=1, select bank1
	movf	(134)^080h,w	;volatile
	line	90
	
l1033:	
;SC8F072_Sleep_Demo.c: 90: RAIF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(107/8),(107)&7	;volatile
	line	91
	
l1035:	
;SC8F072_Sleep_Demo.c: 91: PORTB;
	movf	(6),w	;volatile
	line	92
	
l1037:	
;SC8F072_Sleep_Demo.c: 92: RBIF = 0;
	bcf	(88/8),(88)&7	;volatile
	line	93
# 93 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
clrwdt ;# 
	line	95
# 95 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
sleep ;# 
	line	97
# 97 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
nop ;# 
	line	98
# 98 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
clrwdt ;# 
psect	text1
	line	99
	
l1039:	
;SC8F072_Sleep_Demo.c: 99: if(RAIF) RAIF = 0;
	bcf	status, 5	;RP0=0, select bank0
	btfss	(107/8),(107)&7	;volatile
	goto	u31
	goto	u30
u31:
	goto	l590
u30:
	
l1041:	
	bcf	(107/8),(107)&7	;volatile
	
l590:	
	line	100
;SC8F072_Sleep_Demo.c: 100: if(RBIF) RBIF = 0;
	btfss	(88/8),(88)&7	;volatile
	goto	u41
	goto	u40
u41:
	goto	l1045
u40:
	
l1043:	
	bcf	(88/8),(88)&7	;volatile
	line	101
	
l1045:	
;SC8F072_Sleep_Demo.c: 101: PORTA ^= 0X08;
	movlw	low(08h)
	bsf	status, 5	;RP0=1, select bank1
	xorwf	(134)^080h,f	;volatile
	line	102
	
l1047:	
;SC8F072_Sleep_Demo.c: 102: Init_System();
	fcall	_Init_System
	line	103
	
l592:	
	return
	opt stack 0
GLOBAL	__end_of_Sleep_Mode
	__end_of_Sleep_Mode:
	signat	_Sleep_Mode,89
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 112 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 0/0
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
;;		_Sleep_Mode
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	line	112
global __ptext2
__ptext2:	;psect for function _Init_System
psect	text2
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
	line	112
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 6
; Regs used in _Init_System: [wreg+status,2]
	line	114
	
l971:	
# 114 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
nop ;# 
	line	115
# 115 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
clrwdt ;# 
psect	text2
	line	116
	
l973:	
;SC8F072_Sleep_Demo.c: 116: INTCON = 0;
	clrf	(11)	;volatile
	line	117
	
l975:	
;SC8F072_Sleep_Demo.c: 117: OSCCON = 0X72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	118
	
l977:	
;SC8F072_Sleep_Demo.c: 118: OPTION_REG = 0;
	clrf	(1)	;volatile
	line	120
;SC8F072_Sleep_Demo.c: 120: WPUA = 0B00000001;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(136)^080h	;volatile
	line	121
;SC8F072_Sleep_Demo.c: 121: WPUB = 0B00001000;
	movlw	low(08h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(8)	;volatile
	line	124
;SC8F072_Sleep_Demo.c: 124: TRISA = 0B00000001;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	125
;SC8F072_Sleep_Demo.c: 125: TRISB = 0B00001000;
	movlw	low(08h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	128
	
l979:	
;SC8F072_Sleep_Demo.c: 128: PORTB = 0B00000000;
	clrf	(6)	;volatile
	line	130
	
l595:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
	global	_DelayXms

;; *************** function _DelayXms *****************
;; Defined at:
;;		line 25 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
;; Parameters:    Size  Location     Type
;;  x               1    wreg     unsigned char 
;; Auto vars:     Size  Location     Type
;;  x               1    0[COMMON] unsigned char 
;;  j               1    2[COMMON] unsigned char 
;;  i               1    1[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         3       0       0
;;      Temps:          0       0       0
;;      Totals:         3       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=0
	line	25
global __ptext3
__ptext3:	;psect for function _DelayXms
psect	text3
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
	line	25
	global	__size_of_DelayXms
	__size_of_DelayXms	equ	__end_of_DelayXms-_DelayXms
	
_DelayXms:	
;incstack = 0
	opt	stack 7
; Regs used in _DelayXms: [wreg+status,2+status,0]
;DelayXms@x stored from wreg
	movwf	(DelayXms@x)
	line	28
	
l981:	
;SC8F072_Sleep_Demo.c: 27: unsigned char i,j;
;SC8F072_Sleep_Demo.c: 28: for(i=x;i>0;i--)
	movf	(DelayXms@x),w
	movwf	(DelayXms@i)
	
l983:	
	movf	((DelayXms@i)),w
	btfss	status,2
	goto	u11
	goto	u10
u11:
	goto	l575
u10:
	goto	l579
	line	29
	
l575:	
	line	30
# 30 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_Sleep_Demo\SC8F072_Sleep_Demo.c"
clrwdt ;# 
psect	text3
	line	31
	
l987:	
;SC8F072_Sleep_Demo.c: 31: for(j=153;j>0;j--);
	movlw	low(099h)
	movwf	(DelayXms@j)
	
l993:	
	decf	(DelayXms@j),f
	
l995:	
	movf	((DelayXms@j)),w
	btfss	status,2
	goto	u21
	goto	u20
u21:
	goto	l993
u20:
	line	28
	
l997:	
	decf	(DelayXms@i),f
	goto	l983
	line	33
	
l579:	
	return
	opt stack 0
GLOBAL	__end_of_DelayXms
	__end_of_DelayXms:
	signat	_DelayXms,4217
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
