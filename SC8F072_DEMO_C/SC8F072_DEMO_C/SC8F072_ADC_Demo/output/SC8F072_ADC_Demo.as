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
	FNCALL	_main,_ADC_Sample
	FNCALL	_main,_AD_Init
	FNCALL	_main,_Init_System
	FNCALL	_main,___ftdiv
	FNCALL	_main,___fttol
	FNCALL	_main,___lwtoft
	FNCALL	___lwtoft,___ftpack
	FNCALL	___ftdiv,___ftpack
	FNROOT	_main
	FNCALL	intlevel1,_Isr_Timer
	global	intlevel1
	FNROOT	intlevel1
	global	_result
	global	_power_ad
	global	_adresult
	global	_test_adc
psect	nvBANK0,class=BANK0,space=1,noexec
global __pnvBANK0
__pnvBANK0:
_test_adc:
       ds      1

	global	_OSCCON
_OSCCON	set	20
	global	_T2CON
_T2CON	set	19
	global	_PR2
_PR2	set	17
	global	_INTCON
_INTCON	set	11
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
	global	_TRISB7
_TRISB7	set	47
	global	_ADRESH
_ADRESH	set	153
	global	_ADRESL
_ADRESL	set	152
	global	_ADCON1
_ADCON1	set	150
	global	_ADCON0
_ADCON0	set	149
	global	_ANSEL1
_ANSEL1	set	148
	global	_WPUA
_WPUA	set	136
	global	_PORTA
_PORTA	set	134
	global	_TRISA
_TRISA	set	133
	global	_LDO_EN
_LDO_EN	set	1202
	global	_CHS4
_CHS4	set	1206
	global	_GODONE
_GODONE	set	1193
; #config settings
	file	"SC8F072_ADC_Demo.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	bssCOMMON,class=COMMON,space=1,noexec
global __pbssCOMMON
__pbssCOMMON:
_result:
       ds      2

psect	bssBANK0,class=BANK0,space=1,noexec
global __pbssBANK0
__pbssBANK0:
_power_ad:
       ds      2

_adresult:
       ds      2

	file	"SC8F072_ADC_Demo.as"
	line	#
; Clear objects allocated to COMMON
psect cinit,class=CODE,delta=2,merge=1
	clrf	((__pbssCOMMON)+0)&07Fh
	clrf	((__pbssCOMMON)+1)&07Fh
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2,merge=1
	bcf	status, 5	;RP0=0, select bank0
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
	clrf	((__pbssBANK0)+2)&07Fh
	clrf	((__pbssBANK0)+3)&07Fh
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
?_AD_Init:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?_Isr_Timer:	; 1 bytes @ 0x0
??_Isr_Timer:	; 1 bytes @ 0x0
	ds	2
??_Init_System:	; 1 bytes @ 0x2
??_AD_Init:	; 1 bytes @ 0x2
?_ADC_Sample:	; 1 bytes @ 0x2
	global	?___ftpack
?___ftpack:	; 3 bytes @ 0x2
	global	ADC_Sample@adldo
ADC_Sample@adldo:	; 1 bytes @ 0x2
	global	___ftpack@arg
___ftpack@arg:	; 3 bytes @ 0x2
	ds	1
??_ADC_Sample:	; 1 bytes @ 0x3
	ds	2
	global	___ftpack@exp
___ftpack@exp:	; 1 bytes @ 0x5
	ds	1
	global	___ftpack@sign
___ftpack@sign:	; 1 bytes @ 0x6
	ds	1
??___ftpack:	; 1 bytes @ 0x7
	ds	3
??___lwtoft:	; 1 bytes @ 0xA
psect	cstackBANK0,class=BANK0,space=1,noexec
global __pcstackBANK0
__pcstackBANK0:
	global	?___lwtoft
?___lwtoft:	; 3 bytes @ 0x0
	global	ADC_Sample@j
ADC_Sample@j:	; 1 bytes @ 0x0
	global	___lwtoft@c
___lwtoft@c:	; 2 bytes @ 0x0
	ds	1
	global	ADC_Sample@adch
ADC_Sample@adch:	; 1 bytes @ 0x1
	ds	1
	global	ADC_Sample@i
ADC_Sample@i:	; 1 bytes @ 0x2
	ds	1
	global	?___ftdiv
?___ftdiv:	; 3 bytes @ 0x3
	global	___ftdiv@f2
___ftdiv@f2:	; 3 bytes @ 0x3
	global	ADC_Sample@adsum
ADC_Sample@adsum:	; 4 bytes @ 0x3
	ds	3
	global	___ftdiv@f1
___ftdiv@f1:	; 3 bytes @ 0x6
	ds	1
	global	ADC_Sample@admin
ADC_Sample@admin:	; 2 bytes @ 0x7
	ds	2
??___ftdiv:	; 1 bytes @ 0x9
	global	ADC_Sample@admax
ADC_Sample@admax:	; 2 bytes @ 0x9
	ds	2
	global	ADC_Sample@ad_temp
ADC_Sample@ad_temp:	; 2 bytes @ 0xB
	ds	1
	global	___ftdiv@cntr
___ftdiv@cntr:	; 1 bytes @ 0xC
	ds	1
	global	___ftdiv@f3
___ftdiv@f3:	; 3 bytes @ 0xD
	ds	3
	global	___ftdiv@exp
___ftdiv@exp:	; 1 bytes @ 0x10
	ds	1
	global	___ftdiv@sign
___ftdiv@sign:	; 1 bytes @ 0x11
	ds	1
	global	?___fttol
?___fttol:	; 4 bytes @ 0x12
	global	___fttol@f1
___fttol@f1:	; 3 bytes @ 0x12
	ds	4
??___fttol:	; 1 bytes @ 0x16
	ds	3
	global	___fttol@sign1
___fttol@sign1:	; 1 bytes @ 0x19
	ds	1
	global	___fttol@lval
___fttol@lval:	; 4 bytes @ 0x1A
	ds	4
	global	___fttol@exp1
___fttol@exp1:	; 1 bytes @ 0x1E
	ds	1
??_main:	; 1 bytes @ 0x1F
	ds	1
	global	main@power_temp
main@power_temp:	; 4 bytes @ 0x20
	ds	4
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    0
;!    Data        0
;!    BSS         6
;!    Persistent  1
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14     10      12
;!    BANK0            80     36      41
;!    BANK1            80      0       0

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMMON
;!
;!    ___lwtoft->___ftpack
;!    ___ftdiv->___ftpack
;!
;!Critical Paths under _Isr_Timer in COMMON
;!
;!    None.
;!
;!Critical Paths under _main in BANK0
;!
;!    _main->___fttol
;!    ___fttol->___ftdiv
;!    ___ftdiv->___lwtoft
;!
;!Critical Paths under _Isr_Timer in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    None.
;!
;!Critical Paths under _Isr_Timer in BANK1
;!
;!    None.

;;
;;Main: autosize = 0, tempsize = 1, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 5     5      0    4695
;!                                             31 BANK0      5     5      0
;!                         _ADC_Sample
;!                            _AD_Init
;!                        _Init_System
;!                            ___ftdiv
;!                            ___fttol
;!                           ___lwtoft
;! ---------------------------------------------------------------------------------
;! (1) ___lwtoft                                             3     0      3    1704
;!                                              0 BANK0      3     0      3
;!                           ___ftpack
;! ---------------------------------------------------------------------------------
;! (1) ___fttol                                             13     9      4     305
;!                                             18 BANK0     13     9      4
;!                            ___ftdiv (ARG)
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (1) ___ftdiv                                             15     9      6    2017
;!                                              3 BANK0     15     9      6
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftpack                                             8     3      5    1629
;!                                              2 COMMON     8     3      5
;! ---------------------------------------------------------------------------------
;! (1) _Init_System                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _AD_Init                                              0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _ADC_Sample                                          18    17      1     635
;!                                              2 COMMON     5     4      1
;!                                              0 BANK0     13    13      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 2
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (3) _Isr_Timer                                            2     2      0       0
;!                                              0 COMMON     2     2      0
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 3
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _ADC_Sample
;!   _AD_Init
;!   _Init_System
;!   ___ftdiv
;!     ___ftpack
;!     ___lwtoft (ARG)
;!       ___ftpack
;!   ___fttol
;!     ___ftdiv (ARG)
;!       ___ftpack
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___lwtoft (ARG)
;!       ___ftpack
;!   ___lwtoft
;!     ___ftpack
;!
;! _Isr_Timer (ROOT)
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BITCOMMON            E      0       0       0        0.0%
;!NULL                 0      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!COMMON               E      A       C       1       85.7%
;!BITSFR0              0      0       0       1        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!SFR1                 0      0       0       2        0.0%
;!STACK                0      0       0       2        0.0%
;!BITBANK0            50      0       0       3        0.0%
;!BANK0               50     24      29       4       51.3%
;!BITBANK1            50      0       0       5        0.0%
;!BANK1               50      0       0       6        0.0%
;!ABS                  0      0      35       7        0.0%
;!DATA                 0      0      35       8        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 118 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  power_temp      4   32[BANK0 ] volatile unsigned long 
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
;;      Locals:         0       4       0
;;      Temps:          0       1       0
;;      Totals:         0       5       0
;;Total ram usage:        5 bytes
;; Hardware stack levels required when called:    3
;; This function calls:
;;		_ADC_Sample
;;		_AD_Init
;;		_Init_System
;;		___ftdiv
;;		___fttol
;;		___lwtoft
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	118
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	118
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 5
; Regs used in _main: [wreg+status,2+status,0+pclath+cstack]
	line	120
	
l1476:	
;SC8F072_ADC.c: 120: Init_System();
	fcall	_Init_System
	line	121
;SC8F072_ADC.c: 121: AD_Init();
	fcall	_AD_Init
	line	123
;SC8F072_ADC.c: 123: while (1)
	
l606:	
	line	125
# 125 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
clrwdt ;# 
psect	maintext
	line	128
	
l1478:	
;SC8F072_ADC.c: 128: TRISB7 = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(47/8),(47)&7	;volatile
	line	129
	
l1480:	
;SC8F072_ADC.c: 129: ANSEL1 |= 0X80;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(148)^080h+(7/8),(7)&7	;volatile
	line	130
;SC8F072_ADC.c: 130: test_adc = ADC_Sample(15, 7);
	movlw	low(07h)
	movwf	(ADC_Sample@adldo)
	movlw	low(0Fh)
	fcall	_ADC_Sample
	movwf	(_test_adc)	;volatile
	line	131
	
l1482:	
;SC8F072_ADC.c: 131: if (0xA5 == test_adc)
		movlw	165
	xorwf	((_test_adc)),w	;volatile
	btfss	status,2
	goto	u761
	goto	u760
u761:
	goto	l1486
u760:
	goto	l1490
	line	137
	
l1486:	
;SC8F072_ADC.c: 135: else
;SC8F072_ADC.c: 136: {
;SC8F072_ADC.c: 137: ADCON0 = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(149)^080h	;volatile
	line	138
;SC8F072_ADC.c: 138: ADCON1 = 0;
	clrf	(150)^080h	;volatile
	line	139
	
l1488:	
;SC8F072_ADC.c: 139: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_main+0)+0),f
	u787:
decfsz	(??_main+0)+0,f
	goto	u787
	nop2
opt asmopt_pop

	line	142
	
l1490:	
;SC8F072_ADC.c: 140: }
;SC8F072_ADC.c: 142: test_adc = ADC_Sample(31, 0);
	clrf	(ADC_Sample@adldo)
	movlw	low(01Fh)
	fcall	_ADC_Sample
	movwf	(_test_adc)	;volatile
	line	143
	
l1492:	
;SC8F072_ADC.c: 143: if (0xA5 == test_adc)
		movlw	165
	xorwf	((_test_adc)),w	;volatile
	btfss	status,2
	goto	u771
	goto	u770
u771:
	goto	l606
u770:
	line	147
	
l1494:	
;SC8F072_ADC.c: 144: {
;SC8F072_ADC.c: 145: volatile unsigned long power_temp;
;SC8F072_ADC.c: 147: power_temp = (unsigned long)(((4096UL*1.2*1000))/adresult);
	movlw	0x0
	movwf	(___ftdiv@f1)
	movlw	0x96
	movwf	(___ftdiv@f1+1)
	movlw	0x4a
	movwf	(___ftdiv@f1+2)
	movf	(_adresult+1),w	;volatile
	movwf	(___lwtoft@c+1)
	movf	(_adresult),w	;volatile
	movwf	(___lwtoft@c)
	fcall	___lwtoft
	movf	(0+(?___lwtoft)),w
	movwf	(___ftdiv@f2)
	movf	(1+(?___lwtoft)),w
	movwf	(___ftdiv@f2+1)
	movf	(2+(?___lwtoft)),w
	movwf	(___ftdiv@f2+2)
	fcall	___ftdiv
	movf	(0+(?___ftdiv)),w
	movwf	(___fttol@f1)
	movf	(1+(?___ftdiv)),w
	movwf	(___fttol@f1+1)
	movf	(2+(?___ftdiv)),w
	movwf	(___fttol@f1+2)
	fcall	___fttol
	movf	(3+(?___fttol)),w
	movwf	(main@power_temp+3)	;volatile
	movf	(2+(?___fttol)),w
	movwf	(main@power_temp+2)	;volatile
	movf	(1+(?___fttol)),w
	movwf	(main@power_temp+1)	;volatile
	movf	(0+(?___fttol)),w
	movwf	(main@power_temp)	;volatile

	line	148
	
l1496:	
;SC8F072_ADC.c: 148: power_ad = (unsigned int)(power_temp);
	movf	(main@power_temp+1),w	;volatile
	movwf	(_power_ad+1)	;volatile
	movf	(main@power_temp),w	;volatile
	movwf	(_power_ad)	;volatile
	goto	l606
	global	start
	ljmp	start
	opt stack 0
	line	153
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	___lwtoft

;; *************** function ___lwtoft *****************
;; Defined at:
;;		line 28 in file "H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\lwtoft.c"
;; Parameters:    Size  Location     Type
;;  c               2    0[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3    0[BANK0 ] float 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       3       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       3       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=1
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\lwtoft.c"
	line	28
global __ptext1
__ptext1:	;psect for function ___lwtoft
psect	text1
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\lwtoft.c"
	line	28
	global	__size_of___lwtoft
	__size_of___lwtoft	equ	__end_of___lwtoft-___lwtoft
	
___lwtoft:	
;incstack = 0
	opt	stack 5
; Regs used in ___lwtoft: [wreg+status,2+status,0+pclath+cstack]
	line	30
	
l1450:	
	movf	(___lwtoft@c),w
	movwf	(___ftpack@arg)
	movf	(___lwtoft@c+1),w
	movwf	(___ftpack@arg+1)
	clrf	(___ftpack@arg+2)
	movlw	low(08Eh)
	movwf	(___ftpack@exp)
	clrf	(___ftpack@sign)
	fcall	___ftpack
	movf	(0+(?___ftpack)),w
	movwf	(?___lwtoft)
	movf	(1+(?___ftpack)),w
	movwf	(?___lwtoft+1)
	movf	(2+(?___ftpack)),w
	movwf	(?___lwtoft+2)
	line	31
	
l982:	
	return
	opt stack 0
GLOBAL	__end_of___lwtoft
	__end_of___lwtoft:
	signat	___lwtoft,4219
	global	___fttol

;; *************** function ___fttol *****************
;; Defined at:
;;		line 44 in file "H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\fttol.c"
;; Parameters:    Size  Location     Type
;;  f1              3   18[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  lval            4   26[BANK0 ] unsigned long 
;;  exp1            1   30[BANK0 ] unsigned char 
;;  sign1           1   25[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   18[BANK0 ] long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       4       0
;;      Locals:         0       6       0
;;      Temps:          0       3       0
;;      Totals:         0      13       0
;;Total ram usage:       13 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=1
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\fttol.c"
	line	44
global __ptext2
__ptext2:	;psect for function ___fttol
psect	text2
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\fttol.c"
	line	44
	global	__size_of___fttol
	__size_of___fttol	equ	__end_of___fttol-___fttol
	
___fttol:	
;incstack = 0
	opt	stack 6
; Regs used in ___fttol: [wreg+status,2+status,0]
	line	49
	
l1410:	
	movf	(___fttol@f1),w
	movwf	((??___fttol+0)+0)
	movf	(___fttol@f1+1),w
	movwf	((??___fttol+0)+0+1)
	movf	(___fttol@f1+2),w
	movwf	((??___fttol+0)+0+2)
	clrc
	rlf	(??___fttol+0)+1,w
	rlf	(??___fttol+0)+2,w
	movwf	(___fttol@exp1)
	movf	(((___fttol@exp1))),w
	btfss	status,2
	goto	u661
	goto	u660
u661:
	goto	l1414
u660:
	line	50
	
l1412:	
	clrf	(?___fttol)
	clrf	(?___fttol+1)
	clrf	(?___fttol+2)
	clrf	(?___fttol+3)
	goto	l873
	line	51
	
l1414:	
	movf	(___fttol@f1),w
	movwf	((??___fttol+0)+0)
	movf	(___fttol@f1+1),w
	movwf	((??___fttol+0)+0+1)
	movf	(___fttol@f1+2),w
	movwf	((??___fttol+0)+0+2)
	movlw	017h
u675:
	clrc
	rrf	(??___fttol+0)+2,f
	rrf	(??___fttol+0)+1,f
	rrf	(??___fttol+0)+0,f
u670:
	addlw	-1
	skipz
	goto	u675
	movf	0+(??___fttol+0)+0,w
	movwf	(___fttol@sign1)
	line	52
	
l1416:	
	bsf	(___fttol@f1)+(15/8),(15)&7
	line	53
	
l1418:	
	movlw	0FFh
	andwf	(___fttol@f1),f
	movlw	0FFh
	andwf	(___fttol@f1+1),f
	movlw	0
	andwf	(___fttol@f1+2),f
	line	54
	
l1420:	
	movf	(___fttol@f1),w
	movwf	(___fttol@lval)
	movf	(___fttol@f1+1),w
	movwf	((___fttol@lval))+1
	movf	(___fttol@f1+2),w
	movwf	((___fttol@lval))+2
	clrf	((___fttol@lval))+3
	line	55
	
l1422:	
	movlw	08Eh
	subwf	(___fttol@exp1),f
	line	56
	
l1424:	
	btfss	(___fttol@exp1),7
	goto	u681
	goto	u680
u681:
	goto	l1434
u680:
	line	57
	
l1426:	
	movf	(___fttol@exp1),w
	xorlw	80h
	addlw	-((-15)^80h)
	skipnc
	goto	u691
	goto	u690
u691:
	goto	l1430
u690:
	goto	l1412
	line	60
	
l1430:	
	clrc
	rrf	(___fttol@lval+3),f
	rrf	(___fttol@lval+2),f
	rrf	(___fttol@lval+1),f
	rrf	(___fttol@lval),f
	line	61
	
l1432:	
	incfsz	(___fttol@exp1),f
	goto	u701
	goto	u700
u701:
	goto	l1430
u700:
	goto	l1442
	line	63
	
l1434:	
	movlw	low(018h)
	subwf	(___fttol@exp1),w
	skipc
	goto	u711
	goto	u710
u711:
	goto	l1440
u710:
	goto	l1412
	line	66
	
l1438:	
	clrc
	rlf	(___fttol@lval),f
	rlf	(___fttol@lval+1),f
	rlf	(___fttol@lval+2),f
	rlf	(___fttol@lval+3),f
	line	67
	decf	(___fttol@exp1),f
	line	65
	
l1440:	
	movf	((___fttol@exp1)),w
	btfss	status,2
	goto	u721
	goto	u720
u721:
	goto	l1438
u720:
	line	70
	
l1442:	
	movf	((___fttol@sign1)),w
	btfsc	status,2
	goto	u731
	goto	u730
u731:
	goto	l1446
u730:
	line	71
	
l1444:	
	comf	(___fttol@lval),f
	comf	(___fttol@lval+1),f
	comf	(___fttol@lval+2),f
	comf	(___fttol@lval+3),f
	incf	(___fttol@lval),f
	skipnz
	incf	(___fttol@lval+1),f
	skipnz
	incf	(___fttol@lval+2),f
	skipnz
	incf	(___fttol@lval+3),f
	line	72
	
l1446:	
	movf	(___fttol@lval+3),w
	movwf	(?___fttol+3)
	movf	(___fttol@lval+2),w
	movwf	(?___fttol+2)
	movf	(___fttol@lval+1),w
	movwf	(?___fttol+1)
	movf	(___fttol@lval),w
	movwf	(?___fttol)

	line	73
	
l873:	
	return
	opt stack 0
GLOBAL	__end_of___fttol
	__end_of___fttol:
	signat	___fttol,4220
	global	___ftdiv

;; *************** function ___ftdiv *****************
;; Defined at:
;;		line 56 in file "H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\ftdiv.c"
;; Parameters:    Size  Location     Type
;;  f2              3    3[BANK0 ] float 
;;  f1              3    6[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  f3              3   13[BANK0 ] float 
;;  sign            1   17[BANK0 ] unsigned char 
;;  exp             1   16[BANK0 ] unsigned char 
;;  cntr            1   12[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3    3[BANK0 ] float 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       6       0
;;      Locals:         0       6       0
;;      Temps:          0       3       0
;;      Totals:         0      15       0
;;Total ram usage:       15 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=1
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\ftdiv.c"
	line	56
global __ptext3
__ptext3:	;psect for function ___ftdiv
psect	text3
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\ftdiv.c"
	line	56
	global	__size_of___ftdiv
	__size_of___ftdiv	equ	__end_of___ftdiv-___ftdiv
	
___ftdiv:	
;incstack = 0
	opt	stack 5
; Regs used in ___ftdiv: [wreg+status,2+status,0+pclath+cstack]
	line	63
	
l1370:	
	movf	(___ftdiv@f1),w
	movwf	((??___ftdiv+0)+0)
	movf	(___ftdiv@f1+1),w
	movwf	((??___ftdiv+0)+0+1)
	movf	(___ftdiv@f1+2),w
	movwf	((??___ftdiv+0)+0+2)
	clrc
	rlf	(??___ftdiv+0)+1,w
	rlf	(??___ftdiv+0)+2,w
	movwf	(___ftdiv@exp)
	movf	(((___ftdiv@exp))),w
	btfss	status,2
	goto	u621
	goto	u620
u621:
	goto	l1374
u620:
	line	64
	
l1372:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l837
	line	65
	
l1374:	
	movf	(___ftdiv@f2),w
	movwf	((??___ftdiv+0)+0)
	movf	(___ftdiv@f2+1),w
	movwf	((??___ftdiv+0)+0+1)
	movf	(___ftdiv@f2+2),w
	movwf	((??___ftdiv+0)+0+2)
	clrc
	rlf	(??___ftdiv+0)+1,w
	rlf	(??___ftdiv+0)+2,w
	movwf	(___ftdiv@sign)
	movf	(((___ftdiv@sign))),w
	btfss	status,2
	goto	u631
	goto	u630
u631:
	goto	l838
u630:
	line	66
	
l1376:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l837
	
l838:	
	line	67
	clrf	(___ftdiv@f3)
	clrf	(___ftdiv@f3+1)
	clrf	(___ftdiv@f3+2)
	line	68
	
l1378:	
	movlw	low(089h)
	addwf	(___ftdiv@sign),w
	movwf	(??___ftdiv+0)+0
	movf	0+(??___ftdiv+0)+0,w
	subwf	(___ftdiv@exp),f
	line	69
	
l1380:	
	movf	0+(___ftdiv@f1)+02h,w
	movwf	(___ftdiv@sign)
	line	70
	
l1382:	
	movf	0+(___ftdiv@f2)+02h,w
	xorwf	(___ftdiv@sign),f
	line	71
	
l1384:	
	movlw	low(080h)
	andwf	(___ftdiv@sign),f
	line	72
	
l1386:	
	bsf	(___ftdiv@f1)+(15/8),(15)&7
	line	73
	
l1388:	
	movlw	0FFh
	andwf	(___ftdiv@f1),f
	movlw	0FFh
	andwf	(___ftdiv@f1+1),f
	movlw	0
	andwf	(___ftdiv@f1+2),f
	line	74
	
l1390:	
	bsf	(___ftdiv@f2)+(15/8),(15)&7
	line	75
	
l1392:	
	movlw	0FFh
	andwf	(___ftdiv@f2),f
	movlw	0FFh
	andwf	(___ftdiv@f2+1),f
	movlw	0
	andwf	(___ftdiv@f2+2),f
	line	76
	
l1394:	
	movlw	low(018h)
	movwf	(___ftdiv@cntr)
	line	78
	
l1396:	
	clrc
	rlf	(___ftdiv@f3),f
	rlf	(___ftdiv@f3+1),f
	rlf	(___ftdiv@f3+2),f
	line	79
	movf	(___ftdiv@f2+2),w
	subwf	(___ftdiv@f1+2),w
	skipz
	goto	u645
	movf	(___ftdiv@f2+1),w
	subwf	(___ftdiv@f1+1),w
	skipz
	goto	u645
	movf	(___ftdiv@f2),w
	subwf	(___ftdiv@f1),w
u645:
	skipc
	goto	u641
	goto	u640
u641:
	goto	l1402
u640:
	line	80
	
l1398:	
	movf	(___ftdiv@f2),w
	subwf	(___ftdiv@f1),f
	movf	(___ftdiv@f2+1),w
	skipc
	incfsz	(___ftdiv@f2+1),w
	subwf	(___ftdiv@f1+1),f
	movf	(___ftdiv@f2+2),w
	skipc
	incf	(___ftdiv@f2+2),w
	subwf	(___ftdiv@f1+2),f
	line	81
	
l1400:	
	bsf	(___ftdiv@f3)+(0/8),(0)&7
	line	83
	
l1402:	
	clrc
	rlf	(___ftdiv@f1),f
	rlf	(___ftdiv@f1+1),f
	rlf	(___ftdiv@f1+2),f
	line	84
	
l1404:	
	decfsz	(___ftdiv@cntr),f
	goto	u651
	goto	u650
u651:
	goto	l1396
u650:
	line	85
	
l1406:	
	movf	(___ftdiv@f3),w
	movwf	(___ftpack@arg)
	movf	(___ftdiv@f3+1),w
	movwf	(___ftpack@arg+1)
	movf	(___ftdiv@f3+2),w
	movwf	(___ftpack@arg+2)
	movf	(___ftdiv@exp),w
	movwf	(___ftpack@exp)
	movf	(___ftdiv@sign),w
	movwf	(___ftpack@sign)
	fcall	___ftpack
	movf	(0+(?___ftpack)),w
	movwf	(?___ftdiv)
	movf	(1+(?___ftpack)),w
	movwf	(?___ftdiv+1)
	movf	(2+(?___ftpack)),w
	movwf	(?___ftdiv+2)
	line	86
	
l837:	
	return
	opt stack 0
GLOBAL	__end_of___ftdiv
	__end_of___ftdiv:
	signat	___ftdiv,8315
	global	___ftpack

;; *************** function ___ftpack *****************
;; Defined at:
;;		line 62 in file "H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\float.c"
;; Parameters:    Size  Location     Type
;;  arg             3    2[COMMON] unsigned um
;;  exp             1    5[COMMON] unsigned char 
;;  sign            1    6[COMMON] unsigned char 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3    2[COMMON] float 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 100/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         5       0       0
;;      Locals:         0       0       0
;;      Temps:          3       0       0
;;      Totals:         8       0       0
;;Total ram usage:        8 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		___ftdiv
;;		___lwtoft
;; This function uses a non-reentrant model
;;
psect	text4,local,class=CODE,delta=2,merge=1,group=1
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\float.c"
	line	62
global __ptext4
__ptext4:	;psect for function ___ftpack
psect	text4
	file	"H:\MyDownloads\IDE_RAR\SCMCU_IDE_V2.00.15_Alpha1\data\sources\common\float.c"
	line	62
	global	__size_of___ftpack
	__size_of___ftpack	equ	__end_of___ftpack-___ftpack
	
___ftpack:	
;incstack = 0
	opt	stack 5
; Regs used in ___ftpack: [wreg+status,2+status,0]
	line	64
	
l1242:	
	movf	((___ftpack@exp)),w
	btfsc	status,2
	goto	u391
	goto	u390
u391:
	goto	l784
u390:
	
l1244:	
	movf	(___ftpack@arg+2),w
	iorwf	(___ftpack@arg+1),w
	iorwf	(___ftpack@arg),w
	skipz
	goto	u401
	goto	u400
u401:
	goto	l1248
u400:
	
l784:	
	line	65
	clrf	(?___ftpack)
	clrf	(?___ftpack+1)
	clrf	(?___ftpack+2)
	goto	l785
	line	67
	
l1246:	
	incf	(___ftpack@exp),f
	line	68
	clrc
	rrf	(___ftpack@arg+2),f
	rrf	(___ftpack@arg+1),f
	rrf	(___ftpack@arg),f
	line	66
	
l1248:	
	movlw	low highword(0FE0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u411
	goto	u410
u411:
	goto	l1246
u410:
	goto	l1252
	line	71
	
l1250:	
	incf	(___ftpack@exp),f
	line	72
	incf	(___ftpack@arg),f
	skipnz
	incf	(___ftpack@arg+1),f
	skipnz
	incf	(___ftpack@arg+2),f
	line	73
	clrc
	rrf	(___ftpack@arg+2),f
	rrf	(___ftpack@arg+1),f
	rrf	(___ftpack@arg),f
	line	70
	
l1252:	
	movlw	low highword(0FF0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u421
	goto	u420
u421:
	goto	l1250
u420:
	goto	l1256
	line	76
	
l1254:	
	decf	(___ftpack@exp),f
	line	77
	clrc
	rlf	(___ftpack@arg),f
	rlf	(___ftpack@arg+1),f
	rlf	(___ftpack@arg+2),f
	line	75
	
l1256:	
	btfsc	(___ftpack@arg+1),(15)&7
	goto	u431
	goto	u430
u431:
	goto	l796
u430:
	
l1258:	
	movlw	low(02h)
	subwf	(___ftpack@exp),w
	skipnc
	goto	u441
	goto	u440
u441:
	goto	l1254
u440:
	
l796:	
	line	79
	btfsc	(___ftpack@exp),(0)&7
	goto	u451
	goto	u450
u451:
	goto	l797
u450:
	line	80
	
l1260:	
	bcf	(___ftpack@arg)+(15/8),(15)&7
	
l797:	
	line	81
	clrc
	rrf	(___ftpack@exp),f
	line	82
	
l1262:	
	movf	(___ftpack@exp),w
	movwf	((??___ftpack+0)+0+2)
	clrf	((??___ftpack+0)+0+1)
	clrf	((??___ftpack+0)+0+0)
	movf	0+(??___ftpack+0)+0,w
	iorwf	(___ftpack@arg),f
	movf	1+(??___ftpack+0)+0,w
	iorwf	(___ftpack@arg+1),f
	movf	2+(??___ftpack+0)+0,w
	iorwf	(___ftpack@arg+2),f
	line	83
	movf	((___ftpack@sign)),w
	btfsc	status,2
	goto	u461
	goto	u460
u461:
	goto	l798
u460:
	line	84
	
l1264:	
	bsf	(___ftpack@arg)+(23/8),(23)&7
	
l798:	
	line	85
	line	86
	
l785:	
	return
	opt stack 0
GLOBAL	__end_of___ftpack
	__end_of___ftpack:
	signat	___ftpack,12411
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 162 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
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
psect	text5,local,class=CODE,delta=2,merge=1,group=0
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	162
global __ptext5
__ptext5:	;psect for function _Init_System
psect	text5
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	162
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 6
; Regs used in _Init_System: [wreg+status,2]
	line	164
	
l1338:	
# 164 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
nop ;# 
	line	165
# 165 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
clrwdt ;# 
psect	text5
	line	166
	
l1340:	
;SC8F072_ADC.c: 166: OPTION_REG = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(1)	;volatile
	line	167
# 167 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
clrwdt ;# 
psect	text5
	line	168
	
l1342:	
;SC8F072_ADC.c: 168: OSCCON = 0X70;
	movlw	low(070h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	170
	
l1344:	
;SC8F072_ADC.c: 170: WPUA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(136)^080h	;volatile
	line	171
	
l1346:	
;SC8F072_ADC.c: 171: WPUB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(8)	;volatile
	line	173
	
l1348:	
;SC8F072_ADC.c: 173: TRISA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(133)^080h	;volatile
	line	174
	
l1350:	
;SC8F072_ADC.c: 174: TRISB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(5)	;volatile
	line	176
	
l1352:	
;SC8F072_ADC.c: 176: PORTA = 0X00;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(134)^080h	;volatile
	line	177
	
l1354:	
;SC8F072_ADC.c: 177: PORTB = 0X00;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(6)	;volatile
	line	181
	
l1356:	
;SC8F072_ADC.c: 181: PR2 = 249;
	movlw	low(0F9h)
	movwf	(17)	;volatile
	line	182
	
l1358:	
;SC8F072_ADC.c: 182: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	183
	
l1360:	
;SC8F072_ADC.c: 183: TMR2IE = 1;
	bsf	(113/8),(113)&7	;volatile
	line	185
	
l1362:	
;SC8F072_ADC.c: 185: T2CON = 0B00000100;
	movlw	low(04h)
	movwf	(19)	;volatile
	line	186
	
l1364:	
;SC8F072_ADC.c: 186: INTCON = 0XC0;
	movlw	low(0C0h)
	movwf	(11)	;volatile
	line	187
	
l615:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
	global	_AD_Init

;; *************** function _AD_Init *****************
;; Defined at:
;;		line 217 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/100
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
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	line	217
global __ptext6
__ptext6:	;psect for function _AD_Init
psect	text6
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	217
	global	__size_of_AD_Init
	__size_of_AD_Init	equ	__end_of_AD_Init-_AD_Init
	
_AD_Init:	
;incstack = 0
	opt	stack 6
; Regs used in _AD_Init: [wreg+status,2]
	line	250
	
l1366:	
;SC8F072_ADC.c: 250: ADCON0 = 0X41;
	movlw	low(041h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(149)^080h	;volatile
	line	267
	
l1368:	
;SC8F072_ADC.c: 267: ADCON1 = 0;
	clrf	(150)^080h	;volatile
	line	268
	
l624:	
	return
	opt stack 0
GLOBAL	__end_of_AD_Init
	__end_of_AD_Init:
	signat	_AD_Init,89
	global	_ADC_Sample

;; *************** function _ADC_Sample *****************
;; Defined at:
;;		line 46 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
;; Parameters:    Size  Location     Type
;;  adch            1    wreg     unsigned char 
;;  adldo           1    2[COMMON] unsigned char 
;; Auto vars:     Size  Location     Type
;;  adch            1    1[BANK0 ] unsigned char 
;;  j               1    0[BANK0 ] unsigned char 
;;  adsum           4    3[BANK0 ] volatile unsigned long 
;;  ad_temp         2   11[BANK0 ] volatile unsigned int 
;;  admax           2    9[BANK0 ] volatile unsigned int 
;;  admin           2    7[BANK0 ] volatile unsigned int 
;;  i               1    2[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 0/100
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         1       0       0
;;      Locals:         0      13       0
;;      Temps:          4       0       0
;;      Totals:         5      13       0
;;Total ram usage:       18 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text7,local,class=CODE,delta=2,merge=1,group=0
	line	46
global __ptext7
__ptext7:	;psect for function _ADC_Sample
psect	text7
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	46
	global	__size_of_ADC_Sample
	__size_of_ADC_Sample	equ	__end_of_ADC_Sample-_ADC_Sample
	
_ADC_Sample:	
;incstack = 0
	opt	stack 6
; Regs used in _ADC_Sample: [wreg+status,2+status,0]
;ADC_Sample@adch stored from wreg
	bcf	status, 5	;RP0=0, select bank0
	movwf	(ADC_Sample@adch)
	line	48
	
l1266:	
;SC8F072_ADC.c: 48: volatile unsigned long adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	49
	
l1268:	
;SC8F072_ADC.c: 49: volatile unsigned int admin = 0, admax = 0;
	clrf	(ADC_Sample@admin)	;volatile
	clrf	(ADC_Sample@admin+1)	;volatile
	clrf	(ADC_Sample@admax)	;volatile
	clrf	(ADC_Sample@admax+1)	;volatile
	line	50
;SC8F072_ADC.c: 50: volatile unsigned int ad_temp = 0;
	clrf	(ADC_Sample@ad_temp)	;volatile
	clrf	(ADC_Sample@ad_temp+1)	;volatile
	line	52
	
l1270:	
;SC8F072_ADC.c: 52: if ((!LDO_EN) && (adldo & 0x04) )
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(1202/8)^080h,(1202)&7	;volatile
	goto	u471
	goto	u470
u471:
	goto	l1276
u470:
	
l1272:	
	btfss	(ADC_Sample@adldo),(2)&7
	goto	u481
	goto	u480
u481:
	goto	l1276
u480:
	line	55
	
l1274:	
;SC8F072_ADC.c: 53: {
;SC8F072_ADC.c: 55: ADCON1 = adldo;
	movf	(ADC_Sample@adldo),w
	movwf	(150)^080h	;volatile
	line	56
;SC8F072_ADC.c: 56: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	133
movwf	((??_ADC_Sample+0)+0),f
	u797:
decfsz	(??_ADC_Sample+0)+0,f
	goto	u797
opt asmopt_pop

	line	57
;SC8F072_ADC.c: 57: }
	goto	l1278
	line	59
	
l1276:	
;SC8F072_ADC.c: 58: else
;SC8F072_ADC.c: 59: ADCON1 = adldo;
	movf	(ADC_Sample@adldo),w
	movwf	(150)^080h	;volatile
	line	61
	
l1278:	
;SC8F072_ADC.c: 61: if(adch & 0x10)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(ADC_Sample@adch),(4)&7
	goto	u491
	goto	u490
u491:
	goto	l1284
u490:
	line	63
	
l1280:	
;SC8F072_ADC.c: 62: {
;SC8F072_ADC.c: 63: CHS4 = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1206/8)^080h,(1206)&7	;volatile
	line	64
	
l1282:	
;SC8F072_ADC.c: 64: adch &= 0x0f;
	movlw	low(0Fh)
	bcf	status, 5	;RP0=0, select bank0
	andwf	(ADC_Sample@adch),f
	line	66
	
l1284:	
	line	67
	
l1286:	
;SC8F072_ADC.c: 67: for (i = 0; i < 10; i++)
	clrf	(ADC_Sample@i)
	line	69
	
l1292:	
;SC8F072_ADC.c: 68: {
;SC8F072_ADC.c: 69: ADCON0 = (unsigned char)(0X41 | (adch << 2));
	movf	(ADC_Sample@adch),w
	movwf	(??_ADC_Sample+0)+0
	movlw	(02h)-1
u505:
	clrc
	rlf	(??_ADC_Sample+0)+0,f
	addlw	-1
	skipz
	goto	u505
	clrc
	rlf	(??_ADC_Sample+0)+0,w
	iorlw	041h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(149)^080h	;volatile
	line	70
# 70 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
nop ;# 
	line	71
# 71 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
nop ;# 
	line	72
# 72 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
nop ;# 
	line	73
# 73 "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
nop ;# 
psect	text7
	line	74
	
l1294:	
;SC8F072_ADC.c: 74: GODONE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1193/8)^080h,(1193)&7	;volatile
	line	76
	
l1296:	
;SC8F072_ADC.c: 76: unsigned char j = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(ADC_Sample@j)
	line	77
;SC8F072_ADC.c: 77: while (GODONE)
	goto	l590
	
l591:	
	line	79
;SC8F072_ADC.c: 78: {
;SC8F072_ADC.c: 79: _delay((unsigned long)((2)*(16000000/4000000.0)));
		opt asmopt_push
	opt asmopt_off
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	opt asmopt_pop

	line	81
;SC8F072_ADC.c: 81: if (0 == (--j))
	bcf	status, 5	;RP0=0, select bank0
	decfsz	(ADC_Sample@j),f
	goto	u511
	goto	u510
u511:
	goto	l590
u510:
	line	82
	
l1298:	
;SC8F072_ADC.c: 82: return 0;
	movlw	low(0)
	goto	l593
	line	83
	
l590:	
	line	77
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(1193/8)^080h,(1193)&7	;volatile
	goto	u521
	goto	u520
u521:
	goto	l591
u520:
	line	85
	
l1302:	
;SC8F072_ADC.c: 83: }
;SC8F072_ADC.c: 85: ad_temp = (unsigned int)((ADRESH << 4) + (ADRESL >> 4));
	movf	(153)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(ADC_Sample@ad_temp)	;volatile
	clrf	(ADC_Sample@ad_temp+1)	;volatile
	swapf	(ADC_Sample@ad_temp),f	;volatile
	swapf	(ADC_Sample@ad_temp+1),f	;volatile
	movlw	0f0h
	andwf	(ADC_Sample@ad_temp+1),f	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	andlw	0fh
	iorwf	(ADC_Sample@ad_temp+1),f	;volatile
	movlw	0f0h
	andwf	(ADC_Sample@ad_temp),f	;volatile
	
l1304:	
	bsf	status, 5	;RP0=1, select bank1
	swapf	(152)^080h,w	;volatile
	andlw	(0ffh shr 4) & 0ffh
	bcf	status, 5	;RP0=0, select bank0
	addwf	(ADC_Sample@ad_temp),f	;volatile
	skipnc
	incf	(ADC_Sample@ad_temp+1),f	;volatile
	line	87
	
l1306:	
;SC8F072_ADC.c: 87: if (0 == admax)
	movf	((ADC_Sample@admax)),w	;volatile
iorwf	((ADC_Sample@admax+1)),w	;volatile
	btfss	status,2
	goto	u531
	goto	u530
u531:
	goto	l1310
u530:
	line	89
	
l1308:	
;SC8F072_ADC.c: 88: {
;SC8F072_ADC.c: 89: admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admax+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admax)	;volatile
	line	90
;SC8F072_ADC.c: 90: admin = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admin+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admin)	;volatile
	line	91
;SC8F072_ADC.c: 91: }
	goto	l596
	line	92
	
l1310:	
;SC8F072_ADC.c: 92: else if (ad_temp > admax)
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	subwf	(ADC_Sample@admax+1),w	;volatile
	skipz
	goto	u545
	movf	(ADC_Sample@ad_temp),w	;volatile
	subwf	(ADC_Sample@admax),w	;volatile
u545:
	skipnc
	goto	u541
	goto	u540
u541:
	goto	l1314
u540:
	line	93
	
l1312:	
;SC8F072_ADC.c: 93: admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admax+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admax)	;volatile
	goto	l596
	line	94
	
l1314:	
;SC8F072_ADC.c: 94: else if (ad_temp < admin)
	movf	(ADC_Sample@admin+1),w	;volatile
	subwf	(ADC_Sample@ad_temp+1),w	;volatile
	skipz
	goto	u555
	movf	(ADC_Sample@admin),w	;volatile
	subwf	(ADC_Sample@ad_temp),w	;volatile
u555:
	skipnc
	goto	u551
	goto	u550
u551:
	goto	l596
u550:
	line	95
	
l1316:	
;SC8F072_ADC.c: 95: admin = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admin+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admin)	;volatile
	line	97
	
l596:	
;SC8F072_ADC.c: 97: adsum += ad_temp;
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	((??_ADC_Sample+0)+0)
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	0+(??_ADC_Sample+0)+0,w
	addwf	(ADC_Sample@adsum),f	;volatile
	movf	1+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u561
	addwf	(ADC_Sample@adsum+1),f	;volatile
u561:
	movf	2+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u562
	addwf	(ADC_Sample@adsum+2),f	;volatile
u562:
	movf	3+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u563
	addwf	(ADC_Sample@adsum+3),f	;volatile
u563:

	line	67
	
l1318:	
	incf	(ADC_Sample@i),f
	
l1320:	
	movlw	low(0Ah)
	subwf	(ADC_Sample@i),w
	skipc
	goto	u571
	goto	u570
u571:
	goto	l1292
u570:
	line	99
	
l1322:	
;SC8F072_ADC.c: 98: }
;SC8F072_ADC.c: 99: adsum -= admax;
	movf	(ADC_Sample@admax),w	;volatile
	movwf	((??_ADC_Sample+0)+0)
	movf	(ADC_Sample@admax+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	0+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum),f	;volatile
	movf	1+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	1+(??_ADC_Sample+0)+0,w
	goto	u585
	goto	u586
u585:
	subwf	(ADC_Sample@adsum+1),f	;volatile
u586:
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u587
	goto	u588
u587:
	subwf	(ADC_Sample@adsum+2),f	;volatile
u588:
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u589
	goto	u580
u589:
	subwf	(ADC_Sample@adsum+3),f	;volatile
u580:

	line	100
;SC8F072_ADC.c: 100: if (adsum >= admin)
	movf	(ADC_Sample@admin),w	;volatile
	movwf	((??_ADC_Sample+0)+0)
	movf	(ADC_Sample@admin+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	3+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+3),w	;volatile
	skipz
	goto	u595
	movf	2+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+2),w	;volatile
	skipz
	goto	u595
	movf	1+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+1),w	;volatile
	skipz
	goto	u595
	movf	0+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum),w	;volatile
u595:
	skipc
	goto	u591
	goto	u590
u591:
	goto	l600
u590:
	line	101
	
l1324:	
;SC8F072_ADC.c: 101: adsum -= admin;
	movf	(ADC_Sample@admin),w	;volatile
	movwf	((??_ADC_Sample+0)+0)
	movf	(ADC_Sample@admin+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	0+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum),f	;volatile
	movf	1+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	1+(??_ADC_Sample+0)+0,w
	goto	u605
	goto	u606
u605:
	subwf	(ADC_Sample@adsum+1),f	;volatile
u606:
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u607
	goto	u608
u607:
	subwf	(ADC_Sample@adsum+2),f	;volatile
u608:
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u609
	goto	u600
u609:
	subwf	(ADC_Sample@adsum+3),f	;volatile
u600:

	goto	l1326
	line	102
	
l600:	
	line	103
;SC8F072_ADC.c: 102: else
;SC8F072_ADC.c: 103: adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	105
	
l1326:	
;SC8F072_ADC.c: 105: adresult = adsum >> 3;
	movf	(ADC_Sample@adsum),w	;volatile
	movwf	(??_ADC_Sample+0)+0
	movf	(ADC_Sample@adsum+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	movf	(ADC_Sample@adsum+2),w	;volatile
	movwf	((??_ADC_Sample+0)+0+2)
	movf	(ADC_Sample@adsum+3),w	;volatile
	movwf	((??_ADC_Sample+0)+0+3)
	movlw	03h
u615:
	clrc
	rrf	(??_ADC_Sample+0)+3,f
	rrf	(??_ADC_Sample+0)+2,f
	rrf	(??_ADC_Sample+0)+1,f
	rrf	(??_ADC_Sample+0)+0,f
u610:
	addlw	-1
	skipz
	goto	u615
	movf	1+(??_ADC_Sample+0)+0,w
	movwf	(_adresult+1)	;volatile
	movf	0+(??_ADC_Sample+0)+0,w
	movwf	(_adresult)	;volatile
	line	107
	
l1328:	
;SC8F072_ADC.c: 107: adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	108
	
l1330:	
;SC8F072_ADC.c: 108: admin = 0;
	clrf	(ADC_Sample@admin)	;volatile
	clrf	(ADC_Sample@admin+1)	;volatile
	line	109
	
l1332:	
;SC8F072_ADC.c: 109: admax = 0;
	clrf	(ADC_Sample@admax)	;volatile
	clrf	(ADC_Sample@admax+1)	;volatile
	line	110
	
l1334:	
;SC8F072_ADC.c: 110: return 0xA5;
	movlw	low(0A5h)
	line	112
	
l593:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_Sample
	__end_of_ADC_Sample:
	signat	_ADC_Sample,8313
	global	_Isr_Timer

;; *************** function _Isr_Timer *****************
;; Defined at:
;;		line 198 in file "H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
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
psect	text8,local,class=CODE,delta=2,merge=1,group=0
	line	198
global __ptext8
__ptext8:	;psect for function _Isr_Timer
psect	text8
	file	"H:\MyDownloads\说明书&测试报告\开发包\SC8F072开发包\SC8F072_DEMO_C\SC8F072_ADC_Demo\SC8F072_ADC.c"
	line	198
	global	__size_of_Isr_Timer
	__size_of_Isr_Timer	equ	__end_of_Isr_Timer-_Isr_Timer
	
_Isr_Timer:	
;incstack = 0
	opt	stack 5
; Regs used in _Isr_Timer: []
psect	intentry,class=CODE,delta=2
global __pintentry
__pintentry:
global interrupt_function
interrupt_function:
	global saved_w
	saved_w	set	btemp+0
	movwf	saved_w
	swapf	status,w
	movwf	(??_Isr_Timer+0)
	movf	pclath,w
	movwf	(??_Isr_Timer+1)
	ljmp	_Isr_Timer
psect	text8
	line	200
	
i1l1238:	
;SC8F072_ADC.c: 200: if (TMR2IF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(105/8),(105)&7	;volatile
	goto	u38_21
	goto	u38_20
u38_21:
	goto	i1l621
u38_20:
	line	202
	
i1l1240:	
;SC8F072_ADC.c: 201: {
;SC8F072_ADC.c: 202: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	206
	
i1l621:	
	movf	(??_Isr_Timer+1),w
	movwf	pclath
	swapf	(??_Isr_Timer+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_Isr_Timer
	__end_of_Isr_Timer:
	signat	_Isr_Timer,89
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
