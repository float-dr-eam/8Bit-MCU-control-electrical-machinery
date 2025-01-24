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
	FNCALL	_main,_ADC_read
	FNCALL	_main,_Button_response
	FNCALL	_main,_Init_System
	FNCALL	_main,_Led_Gpio_Init
	FNCALL	_main,_PWM_Init
	FNCALL	_Button_response,_Motor_num
	FNCALL	_Button_response,_Set_PWM
	FNCALL	_Button_response,___awmod
	FNCALL	_Set_PWM,___lwdiv
	FNCALL	_Set_PWM,___wmul
	FNCALL	_ADC_read,_ADC_Sample
	FNCALL	_ADC_read,___ftadd
	FNCALL	_ADC_read,___ftdiv
	FNCALL	_ADC_read,___fttol
	FNCALL	_ADC_read,___lwtoft
	FNCALL	___lwtoft,___ftpack
	FNCALL	___ftdiv,___ftpack
	FNCALL	___ftadd,___ftpack
	FNROOT	_main
	FNCALL	_Isr_Timer,_Charge_num
	FNCALL	_Isr_Timer,_Display
	FNCALL	_Isr_Timer,_Uncharge_num
	FNCALL	_Uncharge_num,___lbdiv
	FNCALL	_Uncharge_num,___lbmod
	FNCALL	_Display,_Display_Scan1
	FNCALL	_Display,_Display_Scan2
	FNCALL	_Display,_Display_Scan3
	FNCALL	_Display,_Display_Scan4
	FNCALL	_Display,_Display_Scan5
	FNCALL	_Display,_Set_AllPin_INPUT
	FNCALL	_Charge_num,___lbdiv
	FNCALL	_Charge_num,___lbmod
	FNCALL	intlevel1,_Isr_Timer
	global	intlevel1
	FNROOT	intlevel1
	global	_tens
	global	_unit
	global	_hundreds
	global	_nums
	global	_num_hund
psect	idataCOMMON,class=CODE,space=0,delta=2,noexec
global __pidataCOMMON
__pidataCOMMON:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	50

;initializer for _tens
	retlw	04h
psect	idataBANK0,class=CODE,space=0,delta=2,noexec
global __pidataBANK0
__pidataBANK0:
	line	51

;initializer for _unit
	retlw	02h
	line	49

;initializer for _hundreds
	retlw	04h
psect	idataBANK1,class=CODE,space=0,delta=2,noexec
global __pidataBANK1
__pidataBANK1:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	73

;initializer for _nums
	retlw	07Eh
	retlw	030h
	retlw	06Dh
	retlw	079h
	retlw	033h
	retlw	05Bh
	retlw	05Fh
	retlw	070h
	retlw	07Fh
	retlw	07Bh
	retlw	047h
	retlw	low(0)
	line	55

;initializer for _num_hund
	retlw	low(0)
	retlw	01h
	retlw	03h
	retlw	0Dh
	retlw	0Fh
	global	_duty_steps
psect	strings,class=STRING,delta=2,noexec
global __pstrings
__pstrings:
stringtab:
	global    __stringtab
__stringtab:
;	String table - string pointers are 1 byte each
stringcode:stringdir:
movlw high(stringdir)
movwf pclath
movf fsr,w
incf fsr
	addwf pc
	global __stringbase
__stringbase:
	retlw	0
psect	strings
	global    __end_of__stringtab
__end_of__stringtab:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.h"
	line	21
_duty_steps:
	retlw	032h
	retlw	03Ch
	retlw	046h
	retlw	050h
	retlw	05Ah
	retlw	low(0)
	global __end_of_duty_steps
__end_of_duty_steps:
	global	_duty_steps
	global	_LED_Key_counter
	global	_long_press_counter
	global	_ADC_delay
	global	_power_ad
	global	Display@scan_cnt
	global	_LED_sflag
	global	_LED_lflag
	global	_T_flag
	global	_button_lflag
	global	_button_sflag
	global	_ADC_Flag
	global	_power_percent
	global	_test_adc
	global	_LED_num
	global	_pwm_duty
	global	_adresult
	global	_Time_delay
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
	global	_RAIE
_RAIE	set	115
	global	_TMR2IF
_TMR2IF	set	105
	global	_RAIF
_RAIF	set	107
	global	_RBIF
_RBIF	set	88
	global	_T0IF
_T0IF	set	90
	global	_RBIE
_RBIE	set	91
	global	_T0IE
_T0IE	set	93
	global	_GIE
_GIE	set	95
	global	_RB0
_RB0	set	48
	global	_RB1
_RB1	set	49
	global	_RB2
_RB2	set	50
	global	_RB3
_RB3	set	51
	global	_RB4
_RB4	set	52
	global	_TRISB0
_TRISB0	set	40
	global	_TRISB1
_TRISB1	set	41
	global	_TRISB2
_TRISB2	set	42
	global	_TRISB3
_TRISB3	set	43
	global	_TRISB4
_TRISB4	set	44
	global	_PWMD23H
_PWMD23H	set	158
	global	_PWMD3L
_PWMD3L	set	156
	global	_PWMD2L
_PWMD2L	set	155
	global	_ADRESH
_ADRESH	set	153
	global	_ADRESL
_ADRESL	set	152
	global	_ADCON1
_ADCON1	set	150
	global	_ADCON0
_ADCON0	set	149
	global	_IOCA
_IOCA	set	137
	global	_WPUA
_WPUA	set	136
	global	_WPDA
_WPDA	set	135
	global	_PORTA
_PORTA	set	134
	global	_TRISA
_TRISA	set	133
	global	_TMR0
_TMR0	set	129
	global	_LDO_EN
_LDO_EN	set	1202
	global	_CHS4
_CHS4	set	1206
	global	_GODONE
_GODONE	set	1193
	global	_TRISA0
_TRISA0	set	1064
	global	_TRISA1
_TRISA1	set	1065
	global	_TRISA2
_TRISA2	set	1066
	global	_TRISA4
_TRISA4	set	1068
; #config settings
	file	"SC8F072_Pwm_Demo.as"
	line	#
psect cinit,class=CODE,delta=2
global start_initialization
start_initialization:

global __initialization
__initialization:
psect	dataCOMMON,class=COMMON,space=1,noexec
global __pdataCOMMON
__pdataCOMMON:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	50
_tens:
       ds      1

psect	bssBANK0,class=BANK0,space=1,noexec
global __pbssBANK0
__pbssBANK0:
_LED_Key_counter:
       ds      2

_long_press_counter:
       ds      2

_ADC_delay:
       ds      2

_power_ad:
       ds      2

Display@scan_cnt:
       ds      1

_LED_sflag:
       ds      1

_LED_lflag:
       ds      1

_T_flag:
       ds      1

_button_lflag:
       ds      1

_button_sflag:
       ds      1

_ADC_Flag:
       ds      1

_power_percent:
       ds      1

_test_adc:
       ds      1

_LED_num:
       ds      1

_pwm_duty:
       ds      1

_adresult:
       ds      2

psect	dataBANK0,class=BANK0,space=1,noexec
global __pdataBANK0
__pdataBANK0:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	51
_unit:
       ds      1

psect	dataBANK0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	49
_hundreds:
       ds      1

psect	bssBANK1,class=BANK1,space=1,noexec
global __pbssBANK1
__pbssBANK1:
_Time_delay:
       ds      2

psect	dataBANK1,class=BANK1,space=1,noexec
global __pdataBANK1
__pdataBANK1:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	73
_nums:
       ds      12

psect	dataBANK1
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	55
_num_hund:
       ds      5

	file	"SC8F072_Pwm_Demo.as"
	line	#
; Initialize objects allocated to BANK1
	global __pidataBANK1
psect cinit,class=CODE,delta=2,merge=1
	bsf	status, 5	;RP0=1, select bank1
	fcall	__pidataBANK1+0		;fetch initializer
	movwf	__pdataBANK1+0&07fh		
	fcall	__pidataBANK1+1		;fetch initializer
	movwf	__pdataBANK1+1&07fh		
	fcall	__pidataBANK1+2		;fetch initializer
	movwf	__pdataBANK1+2&07fh		
	fcall	__pidataBANK1+3		;fetch initializer
	movwf	__pdataBANK1+3&07fh		
	fcall	__pidataBANK1+4		;fetch initializer
	movwf	__pdataBANK1+4&07fh		
	fcall	__pidataBANK1+5		;fetch initializer
	movwf	__pdataBANK1+5&07fh		
	fcall	__pidataBANK1+6		;fetch initializer
	movwf	__pdataBANK1+6&07fh		
	fcall	__pidataBANK1+7		;fetch initializer
	movwf	__pdataBANK1+7&07fh		
	fcall	__pidataBANK1+8		;fetch initializer
	movwf	__pdataBANK1+8&07fh		
	fcall	__pidataBANK1+9		;fetch initializer
	movwf	__pdataBANK1+9&07fh		
	fcall	__pidataBANK1+10		;fetch initializer
	movwf	__pdataBANK1+10&07fh		
	fcall	__pidataBANK1+11		;fetch initializer
	movwf	__pdataBANK1+11&07fh		
	fcall	__pidataBANK1+12		;fetch initializer
	movwf	__pdataBANK1+12&07fh		
	fcall	__pidataBANK1+13		;fetch initializer
	movwf	__pdataBANK1+13&07fh		
	fcall	__pidataBANK1+14		;fetch initializer
	movwf	__pdataBANK1+14&07fh		
	fcall	__pidataBANK1+15		;fetch initializer
	movwf	__pdataBANK1+15&07fh		
	fcall	__pidataBANK1+16		;fetch initializer
	movwf	__pdataBANK1+16&07fh		
; Initialize objects allocated to BANK0
	global __pidataBANK0
psect cinit,class=CODE,delta=2,merge=1
	bcf	status, 5	;RP0=0, select bank0
	fcall	__pidataBANK0+0		;fetch initializer
	movwf	__pdataBANK0+0&07fh		
	fcall	__pidataBANK0+1		;fetch initializer
	movwf	__pdataBANK0+1&07fh		
; Initialize objects allocated to COMMON
	global __pidataCOMMON
psect cinit,class=CODE,delta=2,merge=1
	fcall	__pidataCOMMON+0		;fetch initializer
	movwf	__pdataCOMMON+0&07fh		
	line	#
psect clrtext,class=CODE,delta=2
global clear_ram0
;	Called with FSR containing the base address, and
;	W with the last address+1
clear_ram0:
	clrwdt			;clear the watchdog before getting into this loop
clrloop0:
	clrf	indf		;clear RAM location pointed to by FSR
	incf	fsr,f		;increment pointer
	xorwf	fsr,w		;XOR with final address
	btfsc	status,2	;have we reached the end yet?
	retlw	0		;all done for this memory range, return
	xorwf	fsr,w		;XOR again to restore value
	goto	clrloop0		;do the next byte

; Clear objects allocated to BANK1
psect cinit,class=CODE,delta=2,merge=1
	bsf	status, 5	;RP0=1, select bank1
	clrf	((__pbssBANK1)+0)&07Fh
	clrf	((__pbssBANK1)+1)&07Fh
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2,merge=1
	bcf	status, 7	;select IRP bank0
	movlw	low(__pbssBANK0)
	movwf	fsr
	movlw	low((__pbssBANK0)+015h)
	fcall	clear_ram0
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
?_Led_Gpio_Init:	; 1 bytes @ 0x0
?_PWM_Init:	; 1 bytes @ 0x0
?_Button_response:	; 1 bytes @ 0x0
?_ADC_read:	; 1 bytes @ 0x0
?_Charge_num:	; 1 bytes @ 0x0
?_Uncharge_num:	; 1 bytes @ 0x0
?_Display:	; 1 bytes @ 0x0
??_Display:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?_Isr_Timer:	; 1 bytes @ 0x0
?_Motor_num:	; 1 bytes @ 0x0
?_Set_AllPin_INPUT:	; 1 bytes @ 0x0
??_Set_AllPin_INPUT:	; 1 bytes @ 0x0
?_Display_Scan1:	; 1 bytes @ 0x0
??_Display_Scan1:	; 1 bytes @ 0x0
?_Display_Scan2:	; 1 bytes @ 0x0
??_Display_Scan2:	; 1 bytes @ 0x0
?_Display_Scan3:	; 1 bytes @ 0x0
??_Display_Scan3:	; 1 bytes @ 0x0
?_Display_Scan4:	; 1 bytes @ 0x0
??_Display_Scan4:	; 1 bytes @ 0x0
?_Display_Scan5:	; 1 bytes @ 0x0
??_Display_Scan5:	; 1 bytes @ 0x0
?___lbmod:	; 1 bytes @ 0x0
	global	___lbmod@divisor
___lbmod@divisor:	; 1 bytes @ 0x0
	ds	1
??___lbmod:	; 1 bytes @ 0x1
	ds	1
	global	___lbmod@dividend
___lbmod@dividend:	; 1 bytes @ 0x2
	ds	1
	global	___lbmod@counter
___lbmod@counter:	; 1 bytes @ 0x3
	ds	1
	global	___lbmod@rem
___lbmod@rem:	; 1 bytes @ 0x4
	ds	1
?___lbdiv:	; 1 bytes @ 0x5
	global	___lbdiv@divisor
___lbdiv@divisor:	; 1 bytes @ 0x5
	ds	1
??___lbdiv:	; 1 bytes @ 0x6
	global	___lbdiv@dividend
___lbdiv@dividend:	; 1 bytes @ 0x6
	ds	1
	global	___lbdiv@counter
___lbdiv@counter:	; 1 bytes @ 0x7
	ds	1
	global	___lbdiv@quotient
___lbdiv@quotient:	; 1 bytes @ 0x8
	ds	1
??_Charge_num:	; 1 bytes @ 0x9
??_Uncharge_num:	; 1 bytes @ 0x9
	global	Charge_num@hundred
Charge_num@hundred:	; 1 bytes @ 0x9
	global	Uncharge_num@hundred
Uncharge_num@hundred:	; 1 bytes @ 0x9
	ds	1
??_Isr_Timer:	; 1 bytes @ 0xA
	ds	3
psect	cstackBANK0,class=BANK0,space=1,noexec
global __pcstackBANK0
__pcstackBANK0:
??_Init_System:	; 1 bytes @ 0x0
??_Led_Gpio_Init:	; 1 bytes @ 0x0
??_PWM_Init:	; 1 bytes @ 0x0
?_ADC_Sample:	; 1 bytes @ 0x0
??_Motor_num:	; 1 bytes @ 0x0
	global	?___wmul
?___wmul:	; 2 bytes @ 0x0
	global	?___awmod
?___awmod:	; 2 bytes @ 0x0
	global	?___ftpack
?___ftpack:	; 3 bytes @ 0x0
	global	ADC_Sample@adldo
ADC_Sample@adldo:	; 1 bytes @ 0x0
	global	___wmul@multiplier
___wmul@multiplier:	; 2 bytes @ 0x0
	global	___awmod@divisor
___awmod@divisor:	; 2 bytes @ 0x0
	global	___ftpack@arg
___ftpack@arg:	; 3 bytes @ 0x0
	ds	1
??_ADC_Sample:	; 1 bytes @ 0x1
	ds	1
	global	___wmul@multiplicand
___wmul@multiplicand:	; 2 bytes @ 0x2
	global	___awmod@dividend
___awmod@dividend:	; 2 bytes @ 0x2
	ds	1
	global	___ftpack@exp
___ftpack@exp:	; 1 bytes @ 0x3
	ds	1
??___wmul:	; 1 bytes @ 0x4
??___awmod:	; 1 bytes @ 0x4
	global	___awmod@counter
___awmod@counter:	; 1 bytes @ 0x4
	global	___ftpack@sign
___ftpack@sign:	; 1 bytes @ 0x4
	global	___wmul@product
___wmul@product:	; 2 bytes @ 0x4
	ds	1
??___ftpack:	; 1 bytes @ 0x5
	global	ADC_Sample@j
ADC_Sample@j:	; 1 bytes @ 0x5
	global	___awmod@sign
___awmod@sign:	; 1 bytes @ 0x5
	ds	1
	global	?___lwdiv
?___lwdiv:	; 2 bytes @ 0x6
	global	ADC_Sample@adch
ADC_Sample@adch:	; 1 bytes @ 0x6
	global	___lwdiv@divisor
___lwdiv@divisor:	; 2 bytes @ 0x6
	ds	1
	global	ADC_Sample@i
ADC_Sample@i:	; 1 bytes @ 0x7
	ds	1
	global	?___lwtoft
?___lwtoft:	; 3 bytes @ 0x8
	global	___lwdiv@dividend
___lwdiv@dividend:	; 2 bytes @ 0x8
	global	___lwtoft@c
___lwtoft@c:	; 2 bytes @ 0x8
	global	ADC_Sample@adsum
ADC_Sample@adsum:	; 4 bytes @ 0x8
	ds	2
??___lwdiv:	; 1 bytes @ 0xA
	global	___lwdiv@quotient
___lwdiv@quotient:	; 2 bytes @ 0xA
	ds	1
??___lwtoft:	; 1 bytes @ 0xB
	global	?___ftadd
?___ftadd:	; 3 bytes @ 0xB
	global	___ftadd@f1
___ftadd@f1:	; 3 bytes @ 0xB
	ds	1
	global	___lwdiv@counter
___lwdiv@counter:	; 1 bytes @ 0xC
	global	ADC_Sample@admin
ADC_Sample@admin:	; 2 bytes @ 0xC
	ds	1
?_Set_PWM:	; 1 bytes @ 0xD
	global	Set_PWM@duty
Set_PWM@duty:	; 1 bytes @ 0xD
	ds	1
??_Set_PWM:	; 1 bytes @ 0xE
	global	Set_PWM@channel
Set_PWM@channel:	; 1 bytes @ 0xE
	global	ADC_Sample@admax
ADC_Sample@admax:	; 2 bytes @ 0xE
	global	___ftadd@f2
___ftadd@f2:	; 3 bytes @ 0xE
	ds	1
	global	Set_PWM@pulse_width
Set_PWM@pulse_width:	; 2 bytes @ 0xF
	ds	1
	global	ADC_Sample@ad_temp
ADC_Sample@ad_temp:	; 2 bytes @ 0x10
	ds	1
??_Button_response:	; 1 bytes @ 0x11
??___ftadd:	; 1 bytes @ 0x11
	ds	3
	global	___ftadd@sign
___ftadd@sign:	; 1 bytes @ 0x14
	ds	1
	global	___ftadd@exp2
___ftadd@exp2:	; 1 bytes @ 0x15
	ds	1
	global	___ftadd@exp1
___ftadd@exp1:	; 1 bytes @ 0x16
	ds	1
	global	?___ftdiv
?___ftdiv:	; 3 bytes @ 0x17
	global	___ftdiv@f2
___ftdiv@f2:	; 3 bytes @ 0x17
	ds	3
	global	___ftdiv@f1
___ftdiv@f1:	; 3 bytes @ 0x1A
	ds	3
??___ftdiv:	; 1 bytes @ 0x1D
	ds	3
	global	___ftdiv@cntr
___ftdiv@cntr:	; 1 bytes @ 0x20
	ds	1
	global	___ftdiv@f3
___ftdiv@f3:	; 3 bytes @ 0x21
	ds	3
	global	___ftdiv@exp
___ftdiv@exp:	; 1 bytes @ 0x24
	ds	1
	global	___ftdiv@sign
___ftdiv@sign:	; 1 bytes @ 0x25
	ds	1
	global	?___fttol
?___fttol:	; 4 bytes @ 0x26
	global	___fttol@f1
___fttol@f1:	; 3 bytes @ 0x26
	ds	4
??___fttol:	; 1 bytes @ 0x2A
	ds	3
	global	___fttol@sign1
___fttol@sign1:	; 1 bytes @ 0x2D
	ds	1
	global	___fttol@lval
___fttol@lval:	; 4 bytes @ 0x2E
	ds	4
	global	___fttol@exp1
___fttol@exp1:	; 1 bytes @ 0x32
	ds	1
??_ADC_read:	; 1 bytes @ 0x33
	ds	1
	global	ADC_read@power_temp
ADC_read@power_temp:	; 4 bytes @ 0x34
	ds	4
??_main:	; 1 bytes @ 0x38
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    6
;!    Data        20
;!    BSS         23
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14     13      14
;!    BANK0            80     56      79
;!    BANK1            80      0      19

;!
;!Pointer List with Targets:
;!
;!    None.


;!
;!Critical Paths under _main in COMMON
;!
;!    None.
;!
;!Critical Paths under _Isr_Timer in COMMON
;!
;!    _Isr_Timer->_Charge_num
;!    _Isr_Timer->_Uncharge_num
;!    _Uncharge_num->___lbdiv
;!    _Charge_num->___lbdiv
;!    ___lbdiv->___lbmod
;!
;!Critical Paths under _main in BANK0
;!
;!    _main->_ADC_read
;!    _Button_response->_Set_PWM
;!    _Set_PWM->___lwdiv
;!    ___lwdiv->___wmul
;!    _ADC_read->___fttol
;!    ___lwtoft->___ftpack
;!    ___fttol->___ftdiv
;!    ___ftdiv->___ftadd
;!    ___ftadd->___lwtoft
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
;;Main: autosize = 0, tempsize = 0, incstack = 0, save=0
;;

;!
;!Call Graph Tables:
;!
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (0) _main                                                 0     0      0   10272
;!                           _ADC_read
;!                    _Button_response
;!                        _Init_System
;!                      _Led_Gpio_Init
;!                           _PWM_Init
;! ---------------------------------------------------------------------------------
;! (1) _PWM_Init                                             0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _Led_Gpio_Init                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _Init_System                                          0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _Button_response                                      0     0      0    2657
;!                          _Motor_num
;!                            _Set_PWM
;!                            ___awmod
;! ---------------------------------------------------------------------------------
;! (2) ___awmod                                              6     2      4     552
;!                                              0 BANK0      6     2      4
;! ---------------------------------------------------------------------------------
;! (2) _Set_PWM                                              4     3      1    2105
;!                                             13 BANK0      4     3      1
;!                            ___lwdiv
;!                             ___wmul
;! ---------------------------------------------------------------------------------
;! (3) ___wmul                                               6     2      4     198
;!                                              0 BANK0      6     2      4
;! ---------------------------------------------------------------------------------
;! (3) ___lwdiv                                              7     3      4     268
;!                                              6 BANK0      7     3      4
;!                             ___wmul (ARG)
;! ---------------------------------------------------------------------------------
;! (2) _Motor_num                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _ADC_read                                             5     5      0    7615
;!                                             51 BANK0      5     5      0
;!                         _ADC_Sample
;!                            ___ftadd
;!                            ___ftdiv
;!                            ___fttol
;!                           ___lwtoft
;! ---------------------------------------------------------------------------------
;! (2) ___lwtoft                                             3     0      3    1796
;!                                              8 BANK0      3     0      3
;!                           ___ftpack
;! ---------------------------------------------------------------------------------
;! (2) ___fttol                                             13     9      4     358
;!                                             38 BANK0     13     9      4
;!                            ___ftadd (ARG)
;!                            ___ftdiv (ARG)
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftdiv                                             15     9      6    2162
;!                                             23 BANK0     15     9      6
;!                            ___ftadd (ARG)
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftadd                                             12     6      6    2694
;!                                             11 BANK0     12     6      6
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (3) ___ftpack                                             8     3      5    1668
;!                                              0 BANK0      8     3      5
;! ---------------------------------------------------------------------------------
;! (2) _ADC_Sample                                          18    17      1     582
;!                                              0 BANK0     18    17      1
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 3
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (4) _Isr_Timer                                            3     3      0    1536
;!                                             10 COMMON     3     3      0
;!                         _Charge_num
;!                            _Display
;!                       _Uncharge_num
;! ---------------------------------------------------------------------------------
;! (5) _Uncharge_num                                         1     1      0     768
;!                                              9 COMMON     1     1      0
;!                            ___lbdiv
;!                            ___lbmod
;! ---------------------------------------------------------------------------------
;! (5) _Display                                              0     0      0       0
;!                      _Display_Scan1
;!                      _Display_Scan2
;!                      _Display_Scan3
;!                      _Display_Scan4
;!                      _Display_Scan5
;!                   _Set_AllPin_INPUT
;! ---------------------------------------------------------------------------------
;! (6) _Set_AllPin_INPUT                                     0     0      0       0
;! ---------------------------------------------------------------------------------
;! (6) _Display_Scan5                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (6) _Display_Scan4                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (6) _Display_Scan3                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (6) _Display_Scan2                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (6) _Display_Scan1                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (5) _Charge_num                                           1     1      0     768
;!                                              9 COMMON     1     1      0
;!                            ___lbdiv
;!                            ___lbmod
;! ---------------------------------------------------------------------------------
;! (6) ___lbmod                                              5     4      1     371
;!                                              0 COMMON     5     4      1
;! ---------------------------------------------------------------------------------
;! (6) ___lbdiv                                              4     3      1     374
;!                                              5 COMMON     4     3      1
;!                            ___lbmod (ARG)
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 6
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _ADC_read
;!     _ADC_Sample
;!     ___ftadd
;!       ___ftpack
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___ftdiv
;!       ___ftadd (ARG)
;!         ___ftpack
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftpack (ARG)
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___fttol
;!       ___ftadd (ARG)
;!         ___ftpack
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftdiv (ARG)
;!         ___ftadd (ARG)
;!           ___ftpack
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftpack (ARG)
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___lwtoft
;!       ___ftpack
;!   _Button_response
;!     _Motor_num
;!     _Set_PWM
;!       ___lwdiv
;!         ___wmul (ARG)
;!       ___wmul
;!     ___awmod
;!   _Init_System
;!   _Led_Gpio_Init
;!   _PWM_Init
;!
;! _Isr_Timer (ROOT)
;!   _Charge_num
;!     ___lbdiv
;!       ___lbmod (ARG)
;!     ___lbmod
;!   _Display
;!     _Display_Scan1
;!     _Display_Scan2
;!     _Display_Scan3
;!     _Display_Scan4
;!     _Display_Scan5
;!     _Set_AllPin_INPUT
;!   _Uncharge_num
;!     ___lbdiv
;!       ___lbmod (ARG)
;!     ___lbmod
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BANK1               50      0      13       6       23.8%
;!BITBANK1            50      0       0       5        0.0%
;!SFR1                 0      0       0       2        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!BANK0               50     38      4F       4       98.8%
;!BITBANK0            50      0       0       3        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR0              0      0       0       1        0.0%
;!COMMON               E      D       E       1      100.0%
;!BITCOMMON            E      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!DATA                 0      0      70       8        0.0%
;!ABS                  0      0      70       7        0.0%
;!NULL                 0      0       0       0        0.0%
;!STACK                0      0       0       2        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 81 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
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
;; Hardware stack levels required when called:    6
;; This function calls:
;;		_ADC_read
;;		_Button_response
;;		_Init_System
;;		_Led_Gpio_Init
;;		_PWM_Init
;; This function is called by:
;;		Startup code after reset
;; This function uses a non-reentrant model
;;
psect	maintext,global,class=CODE,delta=2,split=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	81
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	81
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 2
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	83
	
l4665:	
;SC8F072_Pwm_Demo.c: 83: Init_System();
	fcall	_Init_System
	line	84
	
l4667:	
;SC8F072_Pwm_Demo.c: 84: Led_Gpio_Init();
	fcall	_Led_Gpio_Init
	line	85
	
l4669:	
;SC8F072_Pwm_Demo.c: 85: PWM_Init();
	fcall	_PWM_Init
	line	86
;SC8F072_Pwm_Demo.c: 86: while(1)
	
l659:	
	line	88
# 88 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	line	89
	
l4671:	
;SC8F072_Pwm_Demo.c: 89: Button_response();
	fcall	_Button_response
	line	90
# 90 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	line	91
	
l4673:	
;SC8F072_Pwm_Demo.c: 91: if(ADC_Flag)
	bcf	status, 5	;RP0=0, select bank0
	movf	((_ADC_Flag)),w
	btfsc	status,2
	goto	u2231
	goto	u2230
u2231:
	goto	l659
u2230:
	line	93
	
l4675:	
;SC8F072_Pwm_Demo.c: 92: {
;SC8F072_Pwm_Demo.c: 93: ADC_read();
	fcall	_ADC_read
	goto	l659
	global	start
	ljmp	start
	opt stack 0
	line	120
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_PWM_Init

;; *************** function _PWM_Init *****************
;; Defined at:
;;		line 4 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\PWM.c"
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
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text1,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\PWM.c"
	line	4
global __ptext1
__ptext1:	;psect for function _PWM_Init
psect	text1
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\PWM.c"
	line	4
	global	__size_of_PWM_Init
	__size_of_PWM_Init	equ	__end_of_PWM_Init-_PWM_Init
	
_PWM_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _PWM_Init: [wreg+status,2]
	line	6
	
l4479:	
;PWM.c: 6: PWMCON1 = 0B11000000;
	movlw	low(0C0h)
	movwf	(22)	;volatile
	line	7
;PWM.c: 7: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	8
;PWM.c: 8: PWMTL = 0XFF;
	movlw	low(0FFh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(23)	;volatile
	line	9
;PWM.c: 9: PWMT4L = 0XFF;
	movlw	low(0FFh)
	movwf	(28)	;volatile
	line	10
	
l4481:	
;PWM.c: 10: PWMTH = 0X00;
	clrf	(24)	;volatile
	line	15
	
l4483:	
;PWM.c: 15: PWMD0L = 0X00;
	clrf	(25)	;volatile
	line	18
	
l4485:	
;PWM.c: 18: PWMD1L = 0X00;
	clrf	(26)	;volatile
	line	19
	
l4487:	
;PWM.c: 19: PWMD01H = 0X00;
	clrf	(30)	;volatile
	line	22
	
l4489:	
;PWM.c: 22: PWMD2L = 0X00;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(155)^080h	;volatile
	line	24
	
l4491:	
;PWM.c: 24: PWMD23H = 0X00;
	clrf	(158)^080h	;volatile
	line	26
	
l4493:	
;PWM.c: 26: PWMD4L = 0X00;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(27)	;volatile
	line	42
	
l4495:	
;PWM.c: 42: PWMCON0 = 0X17;
	movlw	low(017h)
	movwf	(21)	;volatile
	line	43
;PWM.c: 43: PWMCON2 =0X00;
	clrf	(29)	;volatile
	line	45
	
l2634:	
	return
	opt stack 0
GLOBAL	__end_of_PWM_Init
	__end_of_PWM_Init:
	signat	_PWM_Init,89
	global	_Led_Gpio_Init

;; *************** function _Led_Gpio_Init *****************
;; Defined at:
;;		line 76 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 100/100
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text2,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	76
global __ptext2
__ptext2:	;psect for function _Led_Gpio_Init
psect	text2
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	76
	global	__size_of_Led_Gpio_Init
	__size_of_Led_Gpio_Init	equ	__end_of_Led_Gpio_Init-_Led_Gpio_Init
	
_Led_Gpio_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _Led_Gpio_Init: []
	line	78
	
l4477:	
;LED_188.c: 78: TRISB0 = 1;;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(40/8),(40)&7	;volatile
	line	79
;LED_188.c: 79: TRISB1 = 1;;
	bsf	(41/8),(41)&7	;volatile
	line	80
;LED_188.c: 80: TRISB2 = 1;;
	bsf	(42/8),(42)&7	;volatile
	line	81
;LED_188.c: 81: TRISB3 = 1;;
	bsf	(43/8),(43)&7	;volatile
	line	82
;LED_188.c: 82: TRISB4 = 1;;
	bsf	(44/8),(44)&7	;volatile
	line	83
	
l1345:	
	return
	opt stack 0
GLOBAL	__end_of_Led_Gpio_Init
	__end_of_Led_Gpio_Init:
	signat	_Led_Gpio_Init,89
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 130 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
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
;;		On exit  : 100/100
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text3,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	130
global __ptext3
__ptext3:	;psect for function _Init_System
psect	text3
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	130
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 4
; Regs used in _Init_System: [wreg+status,2]
	line	132
	
l4429:	
# 132 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	133
# 133 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text3
	line	134
	
l4431:	
;SC8F072_Pwm_Demo.c: 134: INTCON = 0;
	clrf	(11)	;volatile
	line	135
	
l4433:	
;SC8F072_Pwm_Demo.c: 135: OSCCON = 0X72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	136
	
l4435:	
;SC8F072_Pwm_Demo.c: 136: OPTION_REG = 0B00000101;
	movlw	low(05h)
	movwf	(1)	;volatile
	line	137
# 137 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text3
	line	139
;SC8F072_Pwm_Demo.c: 139: WPUA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(136)^080h	;volatile
	line	140
;SC8F072_Pwm_Demo.c: 140: WPUB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(8)	;volatile
	line	141
;SC8F072_Pwm_Demo.c: 141: WPDA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(135)^080h	;volatile
	line	142
;SC8F072_Pwm_Demo.c: 142: WPDB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(7)	;volatile
	line	143
;SC8F072_Pwm_Demo.c: 143: TRISA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(133)^080h	;volatile
	line	144
;SC8F072_Pwm_Demo.c: 144: TRISB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(5)	;volatile
	line	145
;SC8F072_Pwm_Demo.c: 145: PORTA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(134)^080h	;volatile
	line	146
;SC8F072_Pwm_Demo.c: 146: PORTB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(6)	;volatile
	line	148
	
l4437:	
;SC8F072_Pwm_Demo.c: 148: TMR0 = 6;
	movlw	low(06h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(129)^080h	;volatile
	line	149
	
l4439:	
;SC8F072_Pwm_Demo.c: 149: T0IF = 0;
	bcf	(90/8),(90)&7	;volatile
	line	150
	
l4441:	
;SC8F072_Pwm_Demo.c: 150: T0IE = 1;
	bsf	(93/8),(93)&7	;volatile
	line	151
	
l4443:	
;SC8F072_Pwm_Demo.c: 151: GIE = 1;
	bsf	(95/8),(95)&7	;volatile
	line	154
	
l4445:	
;SC8F072_Pwm_Demo.c: 154: PR2 = 249;
	movlw	low(0F9h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(17)	;volatile
	line	155
	
l4447:	
;SC8F072_Pwm_Demo.c: 155: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	156
	
l4449:	
;SC8F072_Pwm_Demo.c: 156: TMR2IE = 1;
	bsf	(113/8),(113)&7	;volatile
	line	157
	
l4451:	
;SC8F072_Pwm_Demo.c: 157: T2CON = 0B00000111;
	movlw	low(07h)
	movwf	(19)	;volatile
	line	161
	
l4453:	
;SC8F072_Pwm_Demo.c: 161: WPUB = 0B00100000;
	movlw	low(020h)
	movwf	(8)	;volatile
	line	162
	
l4455:	
;SC8F072_Pwm_Demo.c: 162: TRISB= 0B00100000;
	movlw	low(020h)
	movwf	(5)	;volatile
	line	163
	
l4457:	
;SC8F072_Pwm_Demo.c: 163: IOCB = 0B00100000;
	movlw	low(020h)
	movwf	(9)	;volatile
	line	164
	
l4459:	
;SC8F072_Pwm_Demo.c: 164: RBIE = 1;
	bsf	(91/8),(91)&7	;volatile
	line	166
	
l4461:	
;SC8F072_Pwm_Demo.c: 166: PORTB;
	movf	(6),w	;volatile
	line	169
	
l4463:	
;SC8F072_Pwm_Demo.c: 169: WPUA = 0B00101000;
	movlw	low(028h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(136)^080h	;volatile
	line	170
	
l4465:	
;SC8F072_Pwm_Demo.c: 170: TRISA= 0B00101000;
	movlw	low(028h)
	movwf	(133)^080h	;volatile
	line	171
	
l4467:	
;SC8F072_Pwm_Demo.c: 171: IOCA = 0B00101000;
	movlw	low(028h)
	movwf	(137)^080h	;volatile
	line	172
	
l4469:	
;SC8F072_Pwm_Demo.c: 172: RAIE = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(115/8),(115)&7	;volatile
	line	174
	
l4471:	
;SC8F072_Pwm_Demo.c: 174: RAIF = 0;
	bcf	(107/8),(107)&7	;volatile
	line	175
	
l4473:	
;SC8F072_Pwm_Demo.c: 175: PORTA;
	bsf	status, 5	;RP0=1, select bank1
	movf	(134)^080h,w	;volatile
	line	176
	
l4475:	
;SC8F072_Pwm_Demo.c: 176: INTCON = 0xE8;
	movlw	low(0E8h)
	movwf	(11)	;volatile
	line	178
	
l666:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
	global	_Button_response

;; *************** function _Button_response *****************
;; Defined at:
;;		line 50 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_Motor_num
;;		_Set_PWM
;;		___awmod
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text4,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
	line	50
global __ptext4
__ptext4:	;psect for function _Button_response
psect	text4
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
	line	50
	global	__size_of_Button_response
	__size_of_Button_response	equ	__end_of_Button_response-_Button_response
	
_Button_response:	
;incstack = 0
	opt	stack 2
; Regs used in _Button_response: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	52
	
l4497:	
;KEY.c: 52: if (button_sflag)
	bcf	status, 5	;RP0=0, select bank0
	movf	((_button_sflag)),w
	btfsc	status,2
	goto	u2151
	goto	u2150
u2151:
	goto	l4525
u2150:
	line	54
	
l4499:	
;KEY.c: 53: {
;KEY.c: 54: button_sflag = 0;
	clrf	(_button_sflag)
	line	55
	
l4501:	
;KEY.c: 55: TRISA4 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1068/8)^080h,(1068)&7	;volatile
	line	57
;KEY.c: 57: switch (pwm_duty)
	goto	l4515
	line	60
	
l4503:	
;KEY.c: 60: Set_PWM(4, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	61
;KEY.c: 61: break;
	goto	l4517
	line	63
	
l4505:	
;KEY.c: 63: Set_PWM(4, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	64
;KEY.c: 64: break;
	goto	l4517
	line	66
	
l4507:	
;KEY.c: 66: Set_PWM(4, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	67
;KEY.c: 67: break;
	goto	l4517
	line	69
	
l4509:	
;KEY.c: 69: Set_PWM(4, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	70
;KEY.c: 70: break;
	goto	l4517
	line	72
	
l4511:	
;KEY.c: 72: Set_PWM(4, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	74
;KEY.c: 74: break;
	goto	l4517
	line	57
	
l4515:	
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	; Switch size 1, requested type "space"
; Number of cases is 5, Range of values is 0 to 4
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           11     6 (fixed)
; simple_byte           16     9 (average)
; jumptable            260     6 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	5
	subwf	fsr,w
skipnc
goto l4517
movlw high(S4841)
movwf pclath
	movlw low(S4841)
	addwf fsr,w
	movwf pc
psect	swtext1,local,class=CONST,delta=2
global __pswtext1
__pswtext1:
S4841:
	ljmp	l4503
	ljmp	l4505
	ljmp	l4507
	ljmp	l4509
	ljmp	l4511
psect	text4

	line	78
	
l4517:	
;KEY.c: 78: Time_delay=2500;
	movlw	0C4h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_Time_delay)^080h
	movlw	09h
	movwf	((_Time_delay)^080h)+1
	line	79
	
l4519:	
;KEY.c: 79: Motor_num();
	fcall	_Motor_num
	line	80
	
l4521:	
;KEY.c: 80: pwm_duty = (unsigned char)((pwm_duty + 1) % 5);
	movf	(_pwm_duty),w
	movwf	(___awmod@dividend)
	clrf	(___awmod@dividend+1)
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	movlw	05h
	movwf	(___awmod@divisor)
	clrf	(___awmod@divisor+1)
	fcall	___awmod
	movf	(0+(?___awmod)),w
	movwf	(_pwm_duty)
	line	81
	
l4523:	
;KEY.c: 81: T_flag=1;
	clrf	(_T_flag)
	incf	(_T_flag),f
	line	83
	
l4525:	
;KEY.c: 82: }
;KEY.c: 83: if (button_lflag)
	movf	((_button_lflag)),w
	btfsc	status,2
	goto	u2161
	goto	u2160
u2161:
	goto	l4541
u2160:
	line	85
	
l4527:	
;KEY.c: 84: {
;KEY.c: 85: button_lflag = 0;
	clrf	(_button_lflag)
	line	86
	
l4529:	
;KEY.c: 86: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	87
	
l4531:	
;KEY.c: 87: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	88
	
l4533:	
;KEY.c: 88: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	89
	
l4535:	
;KEY.c: 89: Set_PWM(4, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	90
;KEY.c: 90: pwm_duty =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_pwm_duty)
	line	91
	
l4537:	
;KEY.c: 91: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	92
	
l4539:	
;KEY.c: 92: TRISB = 0B00111111;
	movlw	low(03Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	93
;KEY.c: 93: T_flag=0;
	clrf	(_T_flag)
	line	95
# 95 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
clrwdt ;# 
	line	96
# 96 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
sleep ;# 
	line	98
# 98 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
nop ;# 
	line	99
# 99 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
nop ;# 
	line	100
# 100 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
clrwdt ;# 
psect	text4
	line	102
	
l4541:	
;KEY.c: 101: }
;KEY.c: 102: if(LED_sflag)
	bcf	status, 5	;RP0=0, select bank0
	movf	((_LED_sflag)),w
	btfsc	status,2
	goto	u2171
	goto	u2170
u2171:
	goto	l4573
u2170:
	line	104
	
l4543:	
;KEY.c: 103: {
;KEY.c: 104: LED_sflag=0;
	clrf	(_LED_sflag)
	line	105
	
l4545:	
;KEY.c: 105: TRISA0 = 0;
	bsf	status, 5	;RP0=1, select bank1
	bcf	(1064/8)^080h,(1064)&7	;volatile
	line	106
	
l4547:	
;KEY.c: 106: TRISA1 = 0;
	bcf	(1065/8)^080h,(1065)&7	;volatile
	line	107
	
l4549:	
;KEY.c: 107: TRISA2 = 0;
	bcf	(1066/8)^080h,(1066)&7	;volatile
	line	108
;KEY.c: 108: switch (LED_num)
	goto	l4569
	line	113
	
l4551:	
;KEY.c: 113: Set_PWM(0,95);
	movlw	low(05Fh)
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	114
;KEY.c: 114: Set_PWM(1,95);
	movlw	low(05Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	115
;KEY.c: 115: Set_PWM(2,0);
	bcf	status, 5	;RP0=0, select bank0
	clrf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	116
;KEY.c: 116: break;
	goto	l4571
	line	120
	
l4553:	
;KEY.c: 120: Set_PWM(0,0);
	clrf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	121
;KEY.c: 121: Set_PWM(1,95);
	movlw	low(05Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	122
;KEY.c: 122: Set_PWM(2,95);
	movlw	low(05Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	123
;KEY.c: 123: break;
	goto	l4571
	line	126
	
l4555:	
;KEY.c: 126: Set_PWM(0,95);
	movlw	low(05Fh)
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	127
;KEY.c: 127: Set_PWM(1,0);
	bcf	status, 5	;RP0=0, select bank0
	clrf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	128
;KEY.c: 128: Set_PWM(2,95);
	movlw	low(05Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	129
;KEY.c: 129: break;
	goto	l4571
	line	131
	
l4557:	
;KEY.c: 131: Set_PWM(0,95);
	movlw	low(05Fh)
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	132
;KEY.c: 132: Set_PWM(1,95);
	movlw	low(05Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	133
;KEY.c: 133: Set_PWM(2,95);
	movlw	low(05Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	135
;KEY.c: 135: break;
	goto	l4571
	line	138
	
l4559:	
;KEY.c: 138: Set_PWM(0, 0);
	clrf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	139
;KEY.c: 139: Set_PWM(1, 0);
	bcf	status, 5	;RP0=0, select bank0
	clrf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	140
;KEY.c: 140: Set_PWM(2, 0);
	bcf	status, 5	;RP0=0, select bank0
	clrf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	141
	
l4561:	
;KEY.c: 141: TRISA0 = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1064/8)^080h,(1064)&7	;volatile
	line	142
	
l4563:	
;KEY.c: 142: TRISA1 = 1;
	bsf	(1065/8)^080h,(1065)&7	;volatile
	line	143
	
l4565:	
;KEY.c: 143: TRISA2 = 1;
	bsf	(1066/8)^080h,(1066)&7	;volatile
	line	144
;KEY.c: 144: break;
	goto	l4571
	line	108
	
l4569:	
	bcf	status, 5	;RP0=0, select bank0
	movf	(_LED_num),w
	; Switch size 1, requested type "space"
; Number of cases is 5, Range of values is 0 to 4
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           11     6 (fixed)
; simple_byte           16     9 (average)
; jumptable            260     6 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	5
	subwf	fsr,w
skipnc
goto l4571
movlw high(S4843)
movwf pclath
	movlw low(S4843)
	addwf fsr,w
	movwf pc
psect	swtext2,local,class=CONST,delta=2
global __pswtext2
__pswtext2:
S4843:
	ljmp	l4551
	ljmp	l4553
	ljmp	l4555
	ljmp	l4557
	ljmp	l4559
psect	text4

	line	148
	
l4571:	
;KEY.c: 148: LED_num=(unsigned char)((LED_num+1)%5);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_LED_num),w
	movwf	(___awmod@dividend)
	clrf	(___awmod@dividend+1)
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	movlw	05h
	movwf	(___awmod@divisor)
	clrf	(___awmod@divisor+1)
	fcall	___awmod
	movf	(0+(?___awmod)),w
	movwf	(_LED_num)
	line	150
	
l4573:	
;KEY.c: 149: }
;KEY.c: 150: if (LED_lflag)
	movf	((_LED_lflag)),w
	btfsc	status,2
	goto	u2181
	goto	u2180
u2181:
	goto	l2035
u2180:
	line	152
	
l4575:	
;KEY.c: 151: {
;KEY.c: 152: LED_lflag = 0;
	clrf	(_LED_lflag)
	line	153
	
l4577:	
;KEY.c: 153: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	154
	
l4579:	
;KEY.c: 154: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	155
	
l4581:	
;KEY.c: 155: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	156
	
l4583:	
;KEY.c: 156: Set_PWM(4, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	157
;KEY.c: 157: pwm_duty =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_pwm_duty)
	line	158
	
l4585:	
;KEY.c: 158: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	159
	
l4587:	
;KEY.c: 159: TRISB = 0B00111111;
	movlw	low(03Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	160
;KEY.c: 160: T_flag=0;
	clrf	(_T_flag)
	line	162
# 162 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
clrwdt ;# 
	line	163
# 163 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
sleep ;# 
	line	165
# 165 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
nop ;# 
	line	166
# 166 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
nop ;# 
	line	167
# 167 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\KEY.c"
clrwdt ;# 
psect	text4
	line	169
	
l2035:	
	return
	opt stack 0
GLOBAL	__end_of_Button_response
	__end_of_Button_response:
	signat	_Button_response,89
	global	___awmod

;; *************** function ___awmod *****************
;; Defined at:
;;		line 6 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awmod.c"
;; Parameters:    Size  Location     Type
;;  divisor         2    0[BANK0 ] int 
;;  dividend        2    2[BANK0 ] int 
;; Auto vars:     Size  Location     Type
;;  sign            1    5[BANK0 ] unsigned char 
;;  counter         1    4[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  2    0[BANK0 ] int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       4       0
;;      Locals:         0       2       0
;;      Temps:          0       0       0
;;      Totals:         0       6       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Button_response
;; This function uses a non-reentrant model
;;
psect	text5,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awmod.c"
	line	6
global __ptext5
__ptext5:	;psect for function ___awmod
psect	text5
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awmod.c"
	line	6
	global	__size_of___awmod
	__size_of___awmod	equ	__end_of___awmod-___awmod
	
___awmod:	
;incstack = 0
	opt	stack 3
; Regs used in ___awmod: [wreg+status,2+status,0]
	line	13
	
l4191:	
	clrf	(___awmod@sign)
	line	14
	
l4193:	
	btfss	(___awmod@dividend+1),7
	goto	u1691
	goto	u1690
u1691:
	goto	l4199
u1690:
	line	15
	
l4195:	
	comf	(___awmod@dividend),f
	comf	(___awmod@dividend+1),f
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	line	16
	
l4197:	
	clrf	(___awmod@sign)
	incf	(___awmod@sign),f
	line	18
	
l4199:	
	btfss	(___awmod@divisor+1),7
	goto	u1701
	goto	u1700
u1701:
	goto	l4203
u1700:
	line	19
	
l4201:	
	comf	(___awmod@divisor),f
	comf	(___awmod@divisor+1),f
	incf	(___awmod@divisor),f
	skipnz
	incf	(___awmod@divisor+1),f
	line	20
	
l4203:	
	movf	((___awmod@divisor)),w
iorwf	((___awmod@divisor+1)),w
	btfsc	status,2
	goto	u1711
	goto	u1710
u1711:
	goto	l4219
u1710:
	line	21
	
l4205:	
	clrf	(___awmod@counter)
	incf	(___awmod@counter),f
	line	22
	goto	l4209
	line	23
	
l4207:	
	clrc
	rlf	(___awmod@divisor),f
	rlf	(___awmod@divisor+1),f
	line	24
	incf	(___awmod@counter),f
	line	22
	
l4209:	
	btfss	(___awmod@divisor+1),(15)&7
	goto	u1721
	goto	u1720
u1721:
	goto	l4207
u1720:
	line	27
	
l4211:	
	movf	(___awmod@divisor+1),w
	subwf	(___awmod@dividend+1),w
	skipz
	goto	u1735
	movf	(___awmod@divisor),w
	subwf	(___awmod@dividend),w
u1735:
	skipc
	goto	u1731
	goto	u1730
u1731:
	goto	l4215
u1730:
	line	28
	
l4213:	
	movf	(___awmod@divisor),w
	subwf	(___awmod@dividend),f
	movf	(___awmod@divisor+1),w
	skipc
	decf	(___awmod@dividend+1),f
	subwf	(___awmod@dividend+1),f
	line	29
	
l4215:	
	clrc
	rrf	(___awmod@divisor+1),f
	rrf	(___awmod@divisor),f
	line	30
	
l4217:	
	decfsz	(___awmod@counter),f
	goto	u1741
	goto	u1740
u1741:
	goto	l4211
u1740:
	line	32
	
l4219:	
	movf	((___awmod@sign)),w
	btfsc	status,2
	goto	u1751
	goto	u1750
u1751:
	goto	l4223
u1750:
	line	33
	
l4221:	
	comf	(___awmod@dividend),f
	comf	(___awmod@dividend+1),f
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	line	34
	
l4223:	
	movf	(___awmod@dividend+1),w
	movwf	(?___awmod+1)
	movf	(___awmod@dividend),w
	movwf	(?___awmod)
	line	35
	
l2794:	
	return
	opt stack 0
GLOBAL	__end_of___awmod
	__end_of___awmod:
	signat	___awmod,8314
	global	_Set_PWM

;; *************** function _Set_PWM *****************
;; Defined at:
;;		line 55 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\PWM.c"
;; Parameters:    Size  Location     Type
;;  channel         1    wreg     unsigned char 
;;  duty            1   13[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  channel         1   14[BANK0 ] unsigned char 
;;  pulse_width     2   15[BANK0 ] unsigned short 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       1       0
;;      Locals:         0       3       0
;;      Temps:          0       0       0
;;      Totals:         0       4       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___lwdiv
;;		___wmul
;; This function is called by:
;;		_Button_response
;; This function uses a non-reentrant model
;;
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\PWM.c"
	line	55
global __ptext6
__ptext6:	;psect for function _Set_PWM
psect	text6
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\PWM.c"
	line	55
	global	__size_of_Set_PWM
	__size_of_Set_PWM	equ	__end_of_Set_PWM-_Set_PWM
	
_Set_PWM:	
;incstack = 0
	opt	stack 2
; Regs used in _Set_PWM: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;Set_PWM@channel stored from wreg
	movwf	(Set_PWM@channel)
	line	57
	
l4171:	
;PWM.c: 57: unsigned short pulse_width = (unsigned short)(duty * 255) / 100;
	movlw	064h
	movwf	(___lwdiv@divisor)
	clrf	(___lwdiv@divisor+1)
	movf	(Set_PWM@duty),w
	movwf	(___wmul@multiplier)
	clrf	(___wmul@multiplier+1)
	movlw	0FFh
	movwf	(___wmul@multiplicand)
	clrf	(___wmul@multiplicand+1)
	fcall	___wmul
	movf	(1+(?___wmul)),w
	movwf	(___lwdiv@dividend+1)
	movf	(0+(?___wmul)),w
	movwf	(___lwdiv@dividend)
	fcall	___lwdiv
	movf	(1+(?___lwdiv)),w
	movwf	(Set_PWM@pulse_width+1)
	movf	(0+(?___lwdiv)),w
	movwf	(Set_PWM@pulse_width)
	line	58
;PWM.c: 58: switch (channel)
	goto	l4185
	line	61
	
l4173:	
;PWM.c: 61: PWMD0L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(25)	;volatile
	line	63
;PWM.c: 63: break;
	goto	l2645
	line	65
	
l4175:	
;PWM.c: 65: PWMD1L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(26)	;volatile
	line	67
;PWM.c: 67: break;
	goto	l2645
	line	69
	
l4177:	
;PWM.c: 69: PWMD2L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(155)^080h	;volatile
	line	71
;PWM.c: 71: break;
	goto	l2645
	line	73
	
l4179:	
;PWM.c: 73: PWMD3L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(156)^080h	;volatile
	line	75
;PWM.c: 75: break;
	goto	l2645
	line	77
	
l4181:	
;PWM.c: 77: PWMD4L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(27)	;volatile
	line	79
;PWM.c: 79: break;
	goto	l2645
	line	58
	
l4185:	
	movf	(Set_PWM@channel),w
	; Switch size 1, requested type "space"
; Number of cases is 5, Range of values is 0 to 4
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           11     6 (fixed)
; simple_byte           16     9 (average)
; jumptable            260     6 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	5
	subwf	fsr,w
skipnc
goto l2645
movlw high(S4845)
movwf pclath
	movlw low(S4845)
	addwf fsr,w
	movwf pc
psect	swtext3,local,class=CONST,delta=2
global __pswtext3
__pswtext3:
S4845:
	ljmp	l4173
	ljmp	l4175
	ljmp	l4177
	ljmp	l4179
	ljmp	l4181
psect	text6

	line	83
	
l2645:	
	return
	opt stack 0
GLOBAL	__end_of_Set_PWM
	__end_of_Set_PWM:
	signat	_Set_PWM,8313
	global	___wmul

;; *************** function ___wmul *****************
;; Defined at:
;;		line 15 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\Umul16.c"
;; Parameters:    Size  Location     Type
;;  multiplier      2    0[BANK0 ] unsigned int 
;;  multiplicand    2    2[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;  product         2    4[BANK0 ] unsigned int 
;; Return value:  Size  Location     Type
;;                  2    0[BANK0 ] unsigned int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       4       0
;;      Locals:         0       2       0
;;      Temps:          0       0       0
;;      Totals:         0       6       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Set_PWM
;; This function uses a non-reentrant model
;;
psect	text7,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\Umul16.c"
	line	15
global __ptext7
__ptext7:	;psect for function ___wmul
psect	text7
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\Umul16.c"
	line	15
	global	__size_of___wmul
	__size_of___wmul	equ	__end_of___wmul-___wmul
	
___wmul:	
;incstack = 0
	opt	stack 2
; Regs used in ___wmul: [wreg+status,2+status,0]
	line	43
	
l3945:	
	clrf	(___wmul@product)
	clrf	(___wmul@product+1)
	line	45
	
l3947:	
	btfss	(___wmul@multiplier),(0)&7
	goto	u1221
	goto	u1220
u1221:
	goto	l3951
u1220:
	line	46
	
l3949:	
	movf	(___wmul@multiplicand),w
	addwf	(___wmul@product),f
	skipnc
	incf	(___wmul@product+1),f
	movf	(___wmul@multiplicand+1),w
	addwf	(___wmul@product+1),f
	line	47
	
l3951:	
	clrc
	rlf	(___wmul@multiplicand),f
	rlf	(___wmul@multiplicand+1),f
	line	48
	
l3953:	
	clrc
	rrf	(___wmul@multiplier+1),f
	rrf	(___wmul@multiplier),f
	line	49
	
l3955:	
	movf	((___wmul@multiplier)),w
iorwf	((___wmul@multiplier+1)),w
	btfss	status,2
	goto	u1231
	goto	u1230
u1231:
	goto	l3947
u1230:
	line	52
	
l3957:	
	movf	(___wmul@product+1),w
	movwf	(?___wmul+1)
	movf	(___wmul@product),w
	movwf	(?___wmul)
	line	53
	
l2651:	
	return
	opt stack 0
GLOBAL	__end_of___wmul
	__end_of___wmul:
	signat	___wmul,8314
	global	___lwdiv

;; *************** function ___lwdiv *****************
;; Defined at:
;;		line 6 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwdiv.c"
;; Parameters:    Size  Location     Type
;;  divisor         2    6[BANK0 ] unsigned int 
;;  dividend        2    8[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;  quotient        2   10[BANK0 ] unsigned int 
;;  counter         1   12[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  2    6[BANK0 ] unsigned int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       4       0
;;      Locals:         0       3       0
;;      Temps:          0       0       0
;;      Totals:         0       7       0
;;Total ram usage:        7 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Set_PWM
;; This function uses a non-reentrant model
;;
psect	text8,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwdiv.c"
	line	6
global __ptext8
__ptext8:	;psect for function ___lwdiv
psect	text8
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwdiv.c"
	line	6
	global	__size_of___lwdiv
	__size_of___lwdiv	equ	__end_of___lwdiv-___lwdiv
	
___lwdiv:	
;incstack = 0
	opt	stack 2
; Regs used in ___lwdiv: [wreg+status,2+status,0]
	line	14
	
l3985:	
	clrf	(___lwdiv@quotient)
	clrf	(___lwdiv@quotient+1)
	line	15
	
l3987:	
	movf	((___lwdiv@divisor)),w
iorwf	((___lwdiv@divisor+1)),w
	btfsc	status,2
	goto	u1321
	goto	u1320
u1321:
	goto	l4007
u1320:
	line	16
	
l3989:	
	clrf	(___lwdiv@counter)
	incf	(___lwdiv@counter),f
	line	17
	goto	l3993
	line	18
	
l3991:	
	clrc
	rlf	(___lwdiv@divisor),f
	rlf	(___lwdiv@divisor+1),f
	line	19
	incf	(___lwdiv@counter),f
	line	17
	
l3993:	
	btfss	(___lwdiv@divisor+1),(15)&7
	goto	u1331
	goto	u1330
u1331:
	goto	l3991
u1330:
	line	22
	
l3995:	
	clrc
	rlf	(___lwdiv@quotient),f
	rlf	(___lwdiv@quotient+1),f
	line	23
	
l3997:	
	movf	(___lwdiv@divisor+1),w
	subwf	(___lwdiv@dividend+1),w
	skipz
	goto	u1345
	movf	(___lwdiv@divisor),w
	subwf	(___lwdiv@dividend),w
u1345:
	skipc
	goto	u1341
	goto	u1340
u1341:
	goto	l4003
u1340:
	line	24
	
l3999:	
	movf	(___lwdiv@divisor),w
	subwf	(___lwdiv@dividend),f
	movf	(___lwdiv@divisor+1),w
	skipc
	decf	(___lwdiv@dividend+1),f
	subwf	(___lwdiv@dividend+1),f
	line	25
	
l4001:	
	bsf	(___lwdiv@quotient)+(0/8),(0)&7
	line	27
	
l4003:	
	clrc
	rrf	(___lwdiv@divisor+1),f
	rrf	(___lwdiv@divisor),f
	line	28
	
l4005:	
	decfsz	(___lwdiv@counter),f
	goto	u1351
	goto	u1350
u1351:
	goto	l3995
u1350:
	line	30
	
l4007:	
	movf	(___lwdiv@quotient+1),w
	movwf	(?___lwdiv+1)
	movf	(___lwdiv@quotient),w
	movwf	(?___lwdiv)
	line	31
	
l2988:	
	return
	opt stack 0
GLOBAL	__end_of___lwdiv
	__end_of___lwdiv:
	signat	___lwdiv,8314
	global	_Motor_num

;; *************** function _Motor_num *****************
;; Defined at:
;;		line 39 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/100
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Button_response
;; This function uses a non-reentrant model
;;
psect	text9,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	39
global __ptext9
__ptext9:	;psect for function _Motor_num
psect	text9
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	39
	global	__size_of_Motor_num
	__size_of_Motor_num	equ	__end_of_Motor_num-_Motor_num
	
_Motor_num:	
;incstack = 0
	opt	stack 3
; Regs used in _Motor_num: [wreg+status,2+status,0]
	line	41
	
l4083:	
;LED_188.c: 41: hundreds =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_hundreds)
	line	42
;LED_188.c: 42: tens = 0;
	clrf	(_tens)
	line	43
	
l4085:	
;LED_188.c: 43: unit = (unsigned char)(pwm_duty+1) ;
	movf	(_pwm_duty),w
	addlw	01h
	movwf	(_unit)
	line	44
	
l1338:	
	return
	opt stack 0
GLOBAL	__end_of_Motor_num
	__end_of_Motor_num:
	signat	_Motor_num,89
	global	_ADC_read

;; *************** function _ADC_read *****************
;; Defined at:
;;		line 259 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  power_temp      4   52[BANK0 ] volatile unsigned long 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       4       0
;;      Temps:          0       1       0
;;      Totals:         0       5       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		_ADC_Sample
;;		___ftadd
;;		___ftdiv
;;		___fttol
;;		___lwtoft
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text10,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	259
global __ptext10
__ptext10:	;psect for function _ADC_read
psect	text10
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	259
	global	__size_of_ADC_read
	__size_of_ADC_read	equ	__end_of_ADC_read-_ADC_read
	
_ADC_read:	
;incstack = 0
	opt	stack 2
; Regs used in _ADC_read: [wreg+status,2+status,0+pclath+cstack]
	line	261
	
l4597:	
;SC8F072_Pwm_Demo.c: 261: test_adc = ADC_Sample(31, 0);
	clrf	(ADC_Sample@adldo)
	movlw	low(01Fh)
	fcall	_ADC_Sample
	movwf	(_test_adc)	;volatile
	line	262
	
l4599:	
;SC8F072_Pwm_Demo.c: 262: if (0xA5 == test_adc)
		movlw	165
	xorwf	((_test_adc)),w	;volatile
	btfss	status,2
	goto	u2191
	goto	u2190
u2191:
	goto	l4609
u2190:
	line	265
	
l4601:	
;SC8F072_Pwm_Demo.c: 263: {
;SC8F072_Pwm_Demo.c: 264: volatile unsigned long power_temp;
;SC8F072_Pwm_Demo.c: 265: power_temp = (unsigned long)(((4096UL*1.2*1000))/adresult);
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
	movwf	(ADC_read@power_temp+3)	;volatile
	movf	(2+(?___fttol)),w
	movwf	(ADC_read@power_temp+2)	;volatile
	movf	(1+(?___fttol)),w
	movwf	(ADC_read@power_temp+1)	;volatile
	movf	(0+(?___fttol)),w
	movwf	(ADC_read@power_temp)	;volatile

	line	266
	
l4603:	
;SC8F072_Pwm_Demo.c: 266: power_ad = (unsigned int)(power_temp);
	movf	(ADC_read@power_temp+1),w	;volatile
	movwf	(_power_ad+1)	;volatile
	movf	(ADC_read@power_temp),w	;volatile
	movwf	(_power_ad)	;volatile
	line	267
	
l4605:	
;SC8F072_Pwm_Demo.c: 267: power_percent = (unsigned char)((power_ad-(1000UL*2.8))/(10UL*1.4));
	movf	(_power_ad+1),w	;volatile
	movwf	(___lwtoft@c+1)
	movf	(_power_ad),w	;volatile
	movwf	(___lwtoft@c)
	fcall	___lwtoft
	movf	(0+(?___lwtoft)),w
	movwf	(___ftadd@f2)
	movf	(1+(?___lwtoft)),w
	movwf	(___ftadd@f2+1)
	movf	(2+(?___lwtoft)),w
	movwf	(___ftadd@f2+2)
	movlw	0x0
	movwf	(___ftadd@f1)
	movlw	0x2f
	movwf	(___ftadd@f1+1)
	movlw	0xc5
	movwf	(___ftadd@f1+2)
	fcall	___ftadd
	movf	(0+(?___ftadd)),w
	movwf	(___ftdiv@f1)
	movf	(1+(?___ftadd)),w
	movwf	(___ftdiv@f1+1)
	movf	(2+(?___ftadd)),w
	movwf	(___ftdiv@f1+2)
	movlw	0x0
	movwf	(___ftdiv@f2)
	movlw	0x60
	movwf	(___ftdiv@f2+1)
	movlw	0x41
	movwf	(___ftdiv@f2+2)
	fcall	___ftdiv
	movf	(0+(?___ftdiv)),w
	movwf	(___fttol@f1)
	movf	(1+(?___ftdiv)),w
	movwf	(___fttol@f1+1)
	movf	(2+(?___ftdiv)),w
	movwf	(___fttol@f1+2)
	fcall	___fttol
	movf	(0+(?___fttol)),w
	movwf	(_power_percent)	;volatile
	line	268
;SC8F072_Pwm_Demo.c: 268: if(power_percent>100)
	movlw	low(065h)
	subwf	(_power_percent),w	;volatile
	skipc
	goto	u2201
	goto	u2200
u2201:
	goto	l4613
u2200:
	line	270
	
l4607:	
;SC8F072_Pwm_Demo.c: 269: {
;SC8F072_Pwm_Demo.c: 270: power_percent=100;
	movlw	low(064h)
	movwf	(_power_percent)	;volatile
	goto	l4613
	line	275
	
l4609:	
;SC8F072_Pwm_Demo.c: 273: else
;SC8F072_Pwm_Demo.c: 274: {
;SC8F072_Pwm_Demo.c: 275: ADCON0 = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(149)^080h	;volatile
	line	276
;SC8F072_Pwm_Demo.c: 276: ADCON1 = 0;
	clrf	(150)^080h	;volatile
	line	277
	
l4611:	
;SC8F072_Pwm_Demo.c: 277: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_ADC_read+0)+0),f
	u2437:
decfsz	(??_ADC_read+0)+0,f
	goto	u2437
	nop2
opt asmopt_pop

	line	279
	
l4613:	
;SC8F072_Pwm_Demo.c: 278: }
;SC8F072_Pwm_Demo.c: 279: ADC_Flag=0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_ADC_Flag)
	line	281
	
l691:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_read
	__end_of_ADC_read:
	signat	_ADC_read,89
	global	___lwtoft

;; *************** function ___lwtoft *****************
;; Defined at:
;;		line 28 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
;; Parameters:    Size  Location     Type
;;  c               2    8[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3    8[BANK0 ] float 
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
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text11,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
	line	28
global __ptext11
__ptext11:	;psect for function ___lwtoft
psect	text11
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
	line	28
	global	__size_of___lwtoft
	__size_of___lwtoft	equ	__end_of___lwtoft-___lwtoft
	
___lwtoft:	
;incstack = 0
	opt	stack 2
; Regs used in ___lwtoft: [wreg+status,2+status,0+pclath+cstack]
	line	30
	
l4425:	
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
	
l3003:	
	return
	opt stack 0
GLOBAL	__end_of___lwtoft
	__end_of___lwtoft:
	signat	___lwtoft,4219
	global	___fttol

;; *************** function ___fttol *****************
;; Defined at:
;;		line 44 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
;; Parameters:    Size  Location     Type
;;  f1              3   38[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  lval            4   46[BANK0 ] unsigned long 
;;  exp1            1   50[BANK0 ] unsigned char 
;;  sign1           1   45[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   38[BANK0 ] long 
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
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text12,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
	line	44
global __ptext12
__ptext12:	;psect for function ___fttol
psect	text12
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
	line	44
	global	__size_of___fttol
	__size_of___fttol	equ	__end_of___fttol-___fttol
	
___fttol:	
;incstack = 0
	opt	stack 3
; Regs used in ___fttol: [wreg+status,2+status,0]
	line	49
	
l4343:	
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
	goto	u2001
	goto	u2000
u2001:
	goto	l4347
u2000:
	line	50
	
l4345:	
	clrf	(?___fttol)
	clrf	(?___fttol+1)
	clrf	(?___fttol+2)
	clrf	(?___fttol+3)
	goto	l2894
	line	51
	
l4347:	
	movf	(___fttol@f1),w
	movwf	((??___fttol+0)+0)
	movf	(___fttol@f1+1),w
	movwf	((??___fttol+0)+0+1)
	movf	(___fttol@f1+2),w
	movwf	((??___fttol+0)+0+2)
	movlw	017h
u2015:
	clrc
	rrf	(??___fttol+0)+2,f
	rrf	(??___fttol+0)+1,f
	rrf	(??___fttol+0)+0,f
u2010:
	addlw	-1
	skipz
	goto	u2015
	movf	0+(??___fttol+0)+0,w
	movwf	(___fttol@sign1)
	line	52
	
l4349:	
	bsf	(___fttol@f1)+(15/8),(15)&7
	line	53
	
l4351:	
	movlw	0FFh
	andwf	(___fttol@f1),f
	movlw	0FFh
	andwf	(___fttol@f1+1),f
	movlw	0
	andwf	(___fttol@f1+2),f
	line	54
	
l4353:	
	movf	(___fttol@f1),w
	movwf	(___fttol@lval)
	movf	(___fttol@f1+1),w
	movwf	((___fttol@lval))+1
	movf	(___fttol@f1+2),w
	movwf	((___fttol@lval))+2
	clrf	((___fttol@lval))+3
	line	55
	
l4355:	
	movlw	08Eh
	subwf	(___fttol@exp1),f
	line	56
	
l4357:	
	btfss	(___fttol@exp1),7
	goto	u2021
	goto	u2020
u2021:
	goto	l4367
u2020:
	line	57
	
l4359:	
	movf	(___fttol@exp1),w
	xorlw	80h
	addlw	-((-15)^80h)
	skipnc
	goto	u2031
	goto	u2030
u2031:
	goto	l4363
u2030:
	goto	l4345
	line	60
	
l4363:	
	clrc
	rrf	(___fttol@lval+3),f
	rrf	(___fttol@lval+2),f
	rrf	(___fttol@lval+1),f
	rrf	(___fttol@lval),f
	line	61
	
l4365:	
	incfsz	(___fttol@exp1),f
	goto	u2041
	goto	u2040
u2041:
	goto	l4363
u2040:
	goto	l4375
	line	63
	
l4367:	
	movlw	low(018h)
	subwf	(___fttol@exp1),w
	skipc
	goto	u2051
	goto	u2050
u2051:
	goto	l4373
u2050:
	goto	l4345
	line	66
	
l4371:	
	clrc
	rlf	(___fttol@lval),f
	rlf	(___fttol@lval+1),f
	rlf	(___fttol@lval+2),f
	rlf	(___fttol@lval+3),f
	line	67
	decf	(___fttol@exp1),f
	line	65
	
l4373:	
	movf	((___fttol@exp1)),w
	btfss	status,2
	goto	u2061
	goto	u2060
u2061:
	goto	l4371
u2060:
	line	70
	
l4375:	
	movf	((___fttol@sign1)),w
	btfsc	status,2
	goto	u2071
	goto	u2070
u2071:
	goto	l4379
u2070:
	line	71
	
l4377:	
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
	
l4379:	
	movf	(___fttol@lval+3),w
	movwf	(?___fttol+3)
	movf	(___fttol@lval+2),w
	movwf	(?___fttol+2)
	movf	(___fttol@lval+1),w
	movwf	(?___fttol+1)
	movf	(___fttol@lval),w
	movwf	(?___fttol)

	line	73
	
l2894:	
	return
	opt stack 0
GLOBAL	__end_of___fttol
	__end_of___fttol:
	signat	___fttol,4220
	global	___ftdiv

;; *************** function ___ftdiv *****************
;; Defined at:
;;		line 56 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
;; Parameters:    Size  Location     Type
;;  f2              3   23[BANK0 ] float 
;;  f1              3   26[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  f3              3   33[BANK0 ] float 
;;  sign            1   37[BANK0 ] unsigned char 
;;  exp             1   36[BANK0 ] unsigned char 
;;  cntr            1   32[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   23[BANK0 ] float 
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
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text13,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
	line	56
global __ptext13
__ptext13:	;psect for function ___ftdiv
psect	text13
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
	line	56
	global	__size_of___ftdiv
	__size_of___ftdiv	equ	__end_of___ftdiv-___ftdiv
	
___ftdiv:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftdiv: [wreg+status,2+status,0+pclath+cstack]
	line	63
	
l4303:	
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
	goto	u1961
	goto	u1960
u1961:
	goto	l4307
u1960:
	line	64
	
l4305:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l2858
	line	65
	
l4307:	
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
	goto	u1971
	goto	u1970
u1971:
	goto	l2859
u1970:
	line	66
	
l4309:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l2858
	
l2859:	
	line	67
	clrf	(___ftdiv@f3)
	clrf	(___ftdiv@f3+1)
	clrf	(___ftdiv@f3+2)
	line	68
	
l4311:	
	movlw	low(089h)
	addwf	(___ftdiv@sign),w
	movwf	(??___ftdiv+0)+0
	movf	0+(??___ftdiv+0)+0,w
	subwf	(___ftdiv@exp),f
	line	69
	
l4313:	
	movf	0+(___ftdiv@f1)+02h,w
	movwf	(___ftdiv@sign)
	line	70
	
l4315:	
	movf	0+(___ftdiv@f2)+02h,w
	xorwf	(___ftdiv@sign),f
	line	71
	
l4317:	
	movlw	low(080h)
	andwf	(___ftdiv@sign),f
	line	72
	
l4319:	
	bsf	(___ftdiv@f1)+(15/8),(15)&7
	line	73
	
l4321:	
	movlw	0FFh
	andwf	(___ftdiv@f1),f
	movlw	0FFh
	andwf	(___ftdiv@f1+1),f
	movlw	0
	andwf	(___ftdiv@f1+2),f
	line	74
	
l4323:	
	bsf	(___ftdiv@f2)+(15/8),(15)&7
	line	75
	
l4325:	
	movlw	0FFh
	andwf	(___ftdiv@f2),f
	movlw	0FFh
	andwf	(___ftdiv@f2+1),f
	movlw	0
	andwf	(___ftdiv@f2+2),f
	line	76
	
l4327:	
	movlw	low(018h)
	movwf	(___ftdiv@cntr)
	line	78
	
l4329:	
	clrc
	rlf	(___ftdiv@f3),f
	rlf	(___ftdiv@f3+1),f
	rlf	(___ftdiv@f3+2),f
	line	79
	movf	(___ftdiv@f2+2),w
	subwf	(___ftdiv@f1+2),w
	skipz
	goto	u1985
	movf	(___ftdiv@f2+1),w
	subwf	(___ftdiv@f1+1),w
	skipz
	goto	u1985
	movf	(___ftdiv@f2),w
	subwf	(___ftdiv@f1),w
u1985:
	skipc
	goto	u1981
	goto	u1980
u1981:
	goto	l4335
u1980:
	line	80
	
l4331:	
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
	
l4333:	
	bsf	(___ftdiv@f3)+(0/8),(0)&7
	line	83
	
l4335:	
	clrc
	rlf	(___ftdiv@f1),f
	rlf	(___ftdiv@f1+1),f
	rlf	(___ftdiv@f1+2),f
	line	84
	
l4337:	
	decfsz	(___ftdiv@cntr),f
	goto	u1991
	goto	u1990
u1991:
	goto	l4329
u1990:
	line	85
	
l4339:	
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
	
l2858:	
	return
	opt stack 0
GLOBAL	__end_of___ftdiv
	__end_of___ftdiv:
	signat	___ftdiv,8315
	global	___ftadd

;; *************** function ___ftadd *****************
;; Defined at:
;;		line 86 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
;; Parameters:    Size  Location     Type
;;  f1              3   11[BANK0 ] float 
;;  f2              3   14[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  exp1            1   22[BANK0 ] unsigned char 
;;  exp2            1   21[BANK0 ] unsigned char 
;;  sign            1   20[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   11[BANK0 ] float 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       6       0
;;      Locals:         0       3       0
;;      Temps:          0       3       0
;;      Totals:         0      12       0
;;Total ram usage:       12 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text14,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
	line	86
global __ptext14
__ptext14:	;psect for function ___ftadd
psect	text14
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
	line	86
	global	__size_of___ftadd
	__size_of___ftadd	equ	__end_of___ftadd-___ftadd
	
___ftadd:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftadd: [wreg+status,2+status,0+pclath+cstack]
	line	90
	
l4227:	
	movf	(___ftadd@f1),w
	movwf	((??___ftadd+0)+0)
	movf	(___ftadd@f1+1),w
	movwf	((??___ftadd+0)+0+1)
	movf	(___ftadd@f1+2),w
	movwf	((??___ftadd+0)+0+2)
	clrc
	rlf	(??___ftadd+0)+1,w
	rlf	(??___ftadd+0)+2,w
	movwf	(___ftadd@exp1)
	line	91
	movf	(___ftadd@f2),w
	movwf	((??___ftadd+0)+0)
	movf	(___ftadd@f2+1),w
	movwf	((??___ftadd+0)+0+1)
	movf	(___ftadd@f2+2),w
	movwf	((??___ftadd+0)+0+2)
	clrc
	rlf	(??___ftadd+0)+1,w
	rlf	(??___ftadd+0)+2,w
	movwf	(___ftadd@exp2)
	line	92
	movf	((___ftadd@exp1)),w
	btfsc	status,2
	goto	u1761
	goto	u1760
u1761:
	goto	l4233
u1760:
	
l4229:	
	movf	(___ftadd@exp2),w
	subwf	(___ftadd@exp1),w
	skipnc
	goto	u1771
	goto	u1770
u1771:
	goto	l4237
u1770:
	
l4231:	
	movf	(___ftadd@exp2),w
	movwf	(??___ftadd+0)+0
	movf	(___ftadd@exp1),w
	subwf	(??___ftadd+0)+0,f
	movlw	low(019h)
	subwf	0+(??___ftadd+0)+0,w
	skipc
	goto	u1781
	goto	u1780
u1781:
	goto	l4237
u1780:
	line	93
	
l4233:	
	movf	(___ftadd@f2),w
	movwf	(?___ftadd)
	movf	(___ftadd@f2+1),w
	movwf	(?___ftadd+1)
	movf	(___ftadd@f2+2),w
	movwf	(?___ftadd+2)
	goto	l2827
	line	94
	
l4237:	
	movf	((___ftadd@exp2)),w
	btfsc	status,2
	goto	u1791
	goto	u1790
u1791:
	goto	l2830
u1790:
	
l4239:	
	movf	(___ftadd@exp1),w
	subwf	(___ftadd@exp2),w
	skipnc
	goto	u1801
	goto	u1800
u1801:
	goto	l4243
u1800:
	
l4241:	
	movf	(___ftadd@exp1),w
	movwf	(??___ftadd+0)+0
	movf	(___ftadd@exp2),w
	subwf	(??___ftadd+0)+0,f
	movlw	low(019h)
	subwf	0+(??___ftadd+0)+0,w
	skipc
	goto	u1811
	goto	u1810
u1811:
	goto	l4243
u1810:
	
l2830:	
	line	95
	goto	l2827
	line	96
	
l4243:	
	movlw	low(06h)
	movwf	(___ftadd@sign)
	line	97
	
l4245:	
	btfss	(___ftadd@f1+2),(23)&7
	goto	u1821
	goto	u1820
u1821:
	goto	l2831
u1820:
	line	98
	
l4247:	
	bsf	(___ftadd@sign)+(7/8),(7)&7
	
l2831:	
	line	99
	btfss	(___ftadd@f2+2),(23)&7
	goto	u1831
	goto	u1830
u1831:
	goto	l2832
u1830:
	line	100
	
l4249:	
	bsf	(___ftadd@sign)+(6/8),(6)&7
	
l2832:	
	line	101
	bsf	(___ftadd@f1)+(15/8),(15)&7
	line	102
	
l4251:	
	movlw	0FFh
	andwf	(___ftadd@f1),f
	movlw	0FFh
	andwf	(___ftadd@f1+1),f
	movlw	0
	andwf	(___ftadd@f1+2),f
	line	103
	
l4253:	
	bsf	(___ftadd@f2)+(15/8),(15)&7
	line	104
	movlw	0FFh
	andwf	(___ftadd@f2),f
	movlw	0FFh
	andwf	(___ftadd@f2+1),f
	movlw	0
	andwf	(___ftadd@f2+2),f
	line	106
	movf	(___ftadd@exp2),w
	subwf	(___ftadd@exp1),w
	skipnc
	goto	u1841
	goto	u1840
u1841:
	goto	l4265
u1840:
	line	110
	
l4255:	
	clrc
	rlf	(___ftadd@f2),f
	rlf	(___ftadd@f2+1),f
	rlf	(___ftadd@f2+2),f
	line	111
	decf	(___ftadd@exp2),f
	line	112
	
l4257:	
	movf	(___ftadd@exp2),w
	xorwf	(___ftadd@exp1),w
	skipnz
	goto	u1851
	goto	u1850
u1851:
	goto	l4263
u1850:
	
l4259:	
	decf	(___ftadd@sign),f
	movf	((___ftadd@sign)),w
	andlw	07h
	btfss	status,2
	goto	u1861
	goto	u1860
u1861:
	goto	l4255
u1860:
	goto	l4263
	line	114
	
l4261:	
	clrc
	rrf	(___ftadd@f1+2),f
	rrf	(___ftadd@f1+1),f
	rrf	(___ftadd@f1),f
	line	115
	incf	(___ftadd@exp1),f
	line	113
	
l4263:	
	movf	(___ftadd@exp1),w
	xorwf	(___ftadd@exp2),w
	skipz
	goto	u1871
	goto	u1870
u1871:
	goto	l4261
u1870:
	goto	l2841
	line	117
	
l4265:	
	movf	(___ftadd@exp1),w
	subwf	(___ftadd@exp2),w
	skipnc
	goto	u1881
	goto	u1880
u1881:
	goto	l2841
u1880:
	line	121
	
l4267:	
	clrc
	rlf	(___ftadd@f1),f
	rlf	(___ftadd@f1+1),f
	rlf	(___ftadd@f1+2),f
	line	122
	decf	(___ftadd@exp1),f
	line	123
	
l4269:	
	movf	(___ftadd@exp2),w
	xorwf	(___ftadd@exp1),w
	skipnz
	goto	u1891
	goto	u1890
u1891:
	goto	l4275
u1890:
	
l4271:	
	decf	(___ftadd@sign),f
	movf	((___ftadd@sign)),w
	andlw	07h
	btfss	status,2
	goto	u1901
	goto	u1900
u1901:
	goto	l4267
u1900:
	goto	l4275
	line	125
	
l4273:	
	clrc
	rrf	(___ftadd@f2+2),f
	rrf	(___ftadd@f2+1),f
	rrf	(___ftadd@f2),f
	line	126
	incf	(___ftadd@exp2),f
	line	124
	
l4275:	
	movf	(___ftadd@exp1),w
	xorwf	(___ftadd@exp2),w
	skipz
	goto	u1911
	goto	u1910
u1911:
	goto	l4273
u1910:
	line	129
	
l2841:	
	btfss	(___ftadd@sign),(7)&7
	goto	u1921
	goto	u1920
u1921:
	goto	l4281
u1920:
	line	131
	
l4277:	
	movlw	0FFh
	xorwf	(___ftadd@f1),f
	movlw	0FFh
	xorwf	(___ftadd@f1+1),f
	movlw	0FFh
	xorwf	(___ftadd@f1+2),f
	line	132
	
l4279:	
	incf	(___ftadd@f1),f
	skipnz
	incf	(___ftadd@f1+1),f
	skipnz
	incf	(___ftadd@f1+2),f
	line	134
	
l4281:	
	btfss	(___ftadd@sign),(6)&7
	goto	u1931
	goto	u1930
u1931:
	goto	l4287
u1930:
	line	136
	
l4283:	
	movlw	0FFh
	xorwf	(___ftadd@f2),f
	movlw	0FFh
	xorwf	(___ftadd@f2+1),f
	movlw	0FFh
	xorwf	(___ftadd@f2+2),f
	line	137
	
l4285:	
	incf	(___ftadd@f2),f
	skipnz
	incf	(___ftadd@f2+1),f
	skipnz
	incf	(___ftadd@f2+2),f
	line	139
	
l4287:	
	clrf	(___ftadd@sign)
	line	140
	
l4289:	
	movf	(___ftadd@f1),w
	addwf	(___ftadd@f2),f
	movf	(___ftadd@f1+1),w
	clrz
	skipnc
	incf	(___ftadd@f1+1),w
	skipnz
	goto	u1941
	addwf	(___ftadd@f2+1),f
u1941:
	movf	(___ftadd@f1+2),w
	clrz
	skipnc
	incf	(___ftadd@f1+2),w
	skipnz
	goto	u1942
	addwf	(___ftadd@f2+2),f
u1942:

	line	141
	
l4291:	
	btfss	(___ftadd@f2+2),(23)&7
	goto	u1951
	goto	u1950
u1951:
	goto	l4299
u1950:
	line	142
	
l4293:	
	movlw	0FFh
	xorwf	(___ftadd@f2),f
	movlw	0FFh
	xorwf	(___ftadd@f2+1),f
	movlw	0FFh
	xorwf	(___ftadd@f2+2),f
	line	143
	
l4295:	
	incf	(___ftadd@f2),f
	skipnz
	incf	(___ftadd@f2+1),f
	skipnz
	incf	(___ftadd@f2+2),f
	line	144
	
l4297:	
	clrf	(___ftadd@sign)
	incf	(___ftadd@sign),f
	line	146
	
l4299:	
	movf	(___ftadd@f2),w
	movwf	(___ftpack@arg)
	movf	(___ftadd@f2+1),w
	movwf	(___ftpack@arg+1)
	movf	(___ftadd@f2+2),w
	movwf	(___ftpack@arg+2)
	movf	(___ftadd@exp1),w
	movwf	(___ftpack@exp)
	movf	(___ftadd@sign),w
	movwf	(___ftpack@sign)
	fcall	___ftpack
	movf	(0+(?___ftpack)),w
	movwf	(?___ftadd)
	movf	(1+(?___ftpack)),w
	movwf	(?___ftadd+1)
	movf	(2+(?___ftpack)),w
	movwf	(?___ftadd+2)
	line	148
	
l2827:	
	return
	opt stack 0
GLOBAL	__end_of___ftadd
	__end_of___ftadd:
	signat	___ftadd,8315
	global	___ftpack

;; *************** function ___ftpack *****************
;; Defined at:
;;		line 62 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
;; Parameters:    Size  Location     Type
;;  arg             3    0[BANK0 ] unsigned um
;;  exp             1    3[BANK0 ] unsigned char 
;;  sign            1    4[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3    0[BANK0 ] float 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       5       0
;;      Locals:         0       0       0
;;      Temps:          0       3       0
;;      Totals:         0       8       0
;;Total ram usage:        8 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		___ftadd
;;		___ftdiv
;;		___lwtoft
;; This function uses a non-reentrant model
;;
psect	text15,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
	line	62
global __ptext15
__ptext15:	;psect for function ___ftpack
psect	text15
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
	line	62
	global	__size_of___ftpack
	__size_of___ftpack	equ	__end_of___ftpack-___ftpack
	
___ftpack:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftpack: [wreg+status,2+status,0]
	line	64
	
l3961:	
	movf	((___ftpack@exp)),w
	btfsc	status,2
	goto	u1241
	goto	u1240
u1241:
	goto	l2805
u1240:
	
l3963:	
	movf	(___ftpack@arg+2),w
	iorwf	(___ftpack@arg+1),w
	iorwf	(___ftpack@arg),w
	skipz
	goto	u1251
	goto	u1250
u1251:
	goto	l3967
u1250:
	
l2805:	
	line	65
	clrf	(?___ftpack)
	clrf	(?___ftpack+1)
	clrf	(?___ftpack+2)
	goto	l2806
	line	67
	
l3965:	
	incf	(___ftpack@exp),f
	line	68
	clrc
	rrf	(___ftpack@arg+2),f
	rrf	(___ftpack@arg+1),f
	rrf	(___ftpack@arg),f
	line	66
	
l3967:	
	movlw	low highword(0FE0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u1261
	goto	u1260
u1261:
	goto	l3965
u1260:
	goto	l3971
	line	71
	
l3969:	
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
	
l3971:	
	movlw	low highword(0FF0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u1271
	goto	u1270
u1271:
	goto	l3969
u1270:
	goto	l3975
	line	76
	
l3973:	
	decf	(___ftpack@exp),f
	line	77
	clrc
	rlf	(___ftpack@arg),f
	rlf	(___ftpack@arg+1),f
	rlf	(___ftpack@arg+2),f
	line	75
	
l3975:	
	btfsc	(___ftpack@arg+1),(15)&7
	goto	u1281
	goto	u1280
u1281:
	goto	l2817
u1280:
	
l3977:	
	movlw	low(02h)
	subwf	(___ftpack@exp),w
	skipnc
	goto	u1291
	goto	u1290
u1291:
	goto	l3973
u1290:
	
l2817:	
	line	79
	btfsc	(___ftpack@exp),(0)&7
	goto	u1301
	goto	u1300
u1301:
	goto	l2818
u1300:
	line	80
	
l3979:	
	bcf	(___ftpack@arg)+(15/8),(15)&7
	
l2818:	
	line	81
	clrc
	rrf	(___ftpack@exp),f
	line	82
	
l3981:	
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
	goto	u1311
	goto	u1310
u1311:
	goto	l2819
u1310:
	line	84
	
l3983:	
	bsf	(___ftpack@arg)+(23/8),(23)&7
	
l2819:	
	line	85
	line	86
	
l2806:	
	return
	opt stack 0
GLOBAL	__end_of___ftpack
	__end_of___ftpack:
	signat	___ftpack,12411
	global	_ADC_Sample

;; *************** function _ADC_Sample *****************
;; Defined at:
;;		line 199 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;  adch            1    wreg     unsigned char 
;;  adldo           1    0[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  adch            1    6[BANK0 ] unsigned char 
;;  j               1    5[BANK0 ] unsigned char 
;;  adsum           4    8[BANK0 ] volatile unsigned long 
;;  ad_temp         2   16[BANK0 ] volatile unsigned int 
;;  admax           2   14[BANK0 ] volatile unsigned int 
;;  admin           2   12[BANK0 ] volatile unsigned int 
;;  i               1    7[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       1       0
;;      Locals:         0      13       0
;;      Temps:          0       4       0
;;      Totals:         0      18       0
;;Total ram usage:       18 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text16,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	199
global __ptext16
__ptext16:	;psect for function _ADC_Sample
psect	text16
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	199
	global	__size_of_ADC_Sample
	__size_of_ADC_Sample	equ	__end_of_ADC_Sample-_ADC_Sample
	
_ADC_Sample:	
;incstack = 0
	opt	stack 3
; Regs used in _ADC_Sample: [wreg+status,2+status,0]
;ADC_Sample@adch stored from wreg
	movwf	(ADC_Sample@adch)
	line	201
	
l4011:	
;SC8F072_Pwm_Demo.c: 201: volatile unsigned long adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	202
	
l4013:	
;SC8F072_Pwm_Demo.c: 202: volatile unsigned int admin = 0, admax = 0;
	clrf	(ADC_Sample@admin)	;volatile
	clrf	(ADC_Sample@admin+1)	;volatile
	clrf	(ADC_Sample@admax)	;volatile
	clrf	(ADC_Sample@admax+1)	;volatile
	line	203
;SC8F072_Pwm_Demo.c: 203: volatile unsigned int ad_temp = 0;
	clrf	(ADC_Sample@ad_temp)	;volatile
	clrf	(ADC_Sample@ad_temp+1)	;volatile
	line	205
	
l4015:	
;SC8F072_Pwm_Demo.c: 205: if ((!LDO_EN) && (adldo & 0x04) )
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(1202/8)^080h,(1202)&7	;volatile
	goto	u1361
	goto	u1360
u1361:
	goto	l4021
u1360:
	
l4017:	
	bcf	status, 5	;RP0=0, select bank0
	btfss	(ADC_Sample@adldo),(2)&7
	goto	u1371
	goto	u1370
u1371:
	goto	l4021
u1370:
	line	208
	
l4019:	
;SC8F072_Pwm_Demo.c: 206: {
;SC8F072_Pwm_Demo.c: 208: ADCON1 = adldo;
	movf	(ADC_Sample@adldo),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(150)^080h	;volatile
	line	209
;SC8F072_Pwm_Demo.c: 209: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_ADC_Sample+0)+0),f
	u2447:
decfsz	(??_ADC_Sample+0)+0,f
	goto	u2447
	nop2
opt asmopt_pop

	line	210
;SC8F072_Pwm_Demo.c: 210: }
	goto	l4023
	line	212
	
l4021:	
;SC8F072_Pwm_Demo.c: 211: else
;SC8F072_Pwm_Demo.c: 212: ADCON1 = adldo;
	bcf	status, 5	;RP0=0, select bank0
	movf	(ADC_Sample@adldo),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(150)^080h	;volatile
	line	213
	
l4023:	
;SC8F072_Pwm_Demo.c: 213: if(adch & 0x10)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(ADC_Sample@adch),(4)&7
	goto	u1381
	goto	u1380
u1381:
	goto	l4029
u1380:
	line	215
	
l4025:	
;SC8F072_Pwm_Demo.c: 214: {
;SC8F072_Pwm_Demo.c: 215: CHS4 = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1206/8)^080h,(1206)&7	;volatile
	line	216
	
l4027:	
;SC8F072_Pwm_Demo.c: 216: adch &= 0x0f;
	movlw	low(0Fh)
	bcf	status, 5	;RP0=0, select bank0
	andwf	(ADC_Sample@adch),f
	line	218
	
l4029:	
	line	219
	
l4031:	
;SC8F072_Pwm_Demo.c: 219: for (i = 0; i < 10; i++)
	clrf	(ADC_Sample@i)
	line	221
	
l4037:	
;SC8F072_Pwm_Demo.c: 220: {
;SC8F072_Pwm_Demo.c: 221: ADCON0 = (unsigned char)(0X41 | (adch << 2));
	movf	(ADC_Sample@adch),w
	movwf	(??_ADC_Sample+0)+0
	movlw	(02h)-1
u1395:
	clrc
	rlf	(??_ADC_Sample+0)+0,f
	addlw	-1
	skipz
	goto	u1395
	clrc
	rlf	(??_ADC_Sample+0)+0,w
	iorlw	041h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(149)^080h	;volatile
	line	222
# 222 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	223
# 223 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	224
# 224 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	225
# 225 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
psect	text16
	line	226
	
l4039:	
;SC8F072_Pwm_Demo.c: 226: GODONE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1193/8)^080h,(1193)&7	;volatile
	line	227
	
l4041:	
;SC8F072_Pwm_Demo.c: 227: unsigned char j = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(ADC_Sample@j)
	line	228
;SC8F072_Pwm_Demo.c: 228: while (GODONE)
	goto	l674
	
l675:	
	line	230
;SC8F072_Pwm_Demo.c: 229: {
;SC8F072_Pwm_Demo.c: 230: _delay((unsigned long)((2)*(16000000/4000000.0)));
		opt asmopt_push
	opt asmopt_off
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	opt asmopt_pop

	line	231
;SC8F072_Pwm_Demo.c: 231: if (0 == (--j))
	bcf	status, 5	;RP0=0, select bank0
	decfsz	(ADC_Sample@j),f
	goto	u1401
	goto	u1400
u1401:
	goto	l674
u1400:
	line	232
	
l4043:	
;SC8F072_Pwm_Demo.c: 232: return 0;
	movlw	low(0)
	goto	l677
	line	233
	
l674:	
	line	228
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(1193/8)^080h,(1193)&7	;volatile
	goto	u1411
	goto	u1410
u1411:
	goto	l675
u1410:
	line	235
	
l4047:	
;SC8F072_Pwm_Demo.c: 233: }
;SC8F072_Pwm_Demo.c: 235: ad_temp = (unsigned int)((ADRESH << 4) + (ADRESL >> 4));
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
	
l4049:	
	bsf	status, 5	;RP0=1, select bank1
	swapf	(152)^080h,w	;volatile
	andlw	(0ffh shr 4) & 0ffh
	bcf	status, 5	;RP0=0, select bank0
	addwf	(ADC_Sample@ad_temp),f	;volatile
	skipnc
	incf	(ADC_Sample@ad_temp+1),f	;volatile
	line	237
	
l4051:	
;SC8F072_Pwm_Demo.c: 237: if (0 == admax)
	movf	((ADC_Sample@admax)),w	;volatile
iorwf	((ADC_Sample@admax+1)),w	;volatile
	btfss	status,2
	goto	u1421
	goto	u1420
u1421:
	goto	l4055
u1420:
	line	239
	
l4053:	
;SC8F072_Pwm_Demo.c: 238: {
;SC8F072_Pwm_Demo.c: 239: admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admax+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admax)	;volatile
	line	240
;SC8F072_Pwm_Demo.c: 240: admin = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admin+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admin)	;volatile
	line	241
;SC8F072_Pwm_Demo.c: 241: }
	goto	l680
	line	242
	
l4055:	
;SC8F072_Pwm_Demo.c: 242: else if (ad_temp > admax)admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	subwf	(ADC_Sample@admax+1),w	;volatile
	skipz
	goto	u1435
	movf	(ADC_Sample@ad_temp),w	;volatile
	subwf	(ADC_Sample@admax),w	;volatile
u1435:
	skipnc
	goto	u1431
	goto	u1430
u1431:
	goto	l4059
u1430:
	
l4057:	
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admax+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admax)	;volatile
	goto	l680
	line	244
	
l4059:	
;SC8F072_Pwm_Demo.c: 244: else if (ad_temp < admin)admin = ad_temp;
	movf	(ADC_Sample@admin+1),w	;volatile
	subwf	(ADC_Sample@ad_temp+1),w	;volatile
	skipz
	goto	u1445
	movf	(ADC_Sample@admin),w	;volatile
	subwf	(ADC_Sample@ad_temp),w	;volatile
u1445:
	skipnc
	goto	u1441
	goto	u1440
u1441:
	goto	l680
u1440:
	
l4061:	
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admin+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admin)	;volatile
	line	245
	
l680:	
;SC8F072_Pwm_Demo.c: 245: adsum += ad_temp;
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
	goto	u1451
	addwf	(ADC_Sample@adsum+1),f	;volatile
u1451:
	movf	2+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u1452
	addwf	(ADC_Sample@adsum+2),f	;volatile
u1452:
	movf	3+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u1453
	addwf	(ADC_Sample@adsum+3),f	;volatile
u1453:

	line	219
	
l4063:	
	incf	(ADC_Sample@i),f
	
l4065:	
	movlw	low(0Ah)
	subwf	(ADC_Sample@i),w
	skipc
	goto	u1461
	goto	u1460
u1461:
	goto	l4037
u1460:
	line	247
	
l4067:	
;SC8F072_Pwm_Demo.c: 246: }
;SC8F072_Pwm_Demo.c: 247: adsum -= admax;
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
	goto	u1475
	goto	u1476
u1475:
	subwf	(ADC_Sample@adsum+1),f	;volatile
u1476:
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u1477
	goto	u1478
u1477:
	subwf	(ADC_Sample@adsum+2),f	;volatile
u1478:
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u1479
	goto	u1470
u1479:
	subwf	(ADC_Sample@adsum+3),f	;volatile
u1470:

	line	248
;SC8F072_Pwm_Demo.c: 248: if (adsum >= admin)
	movf	(ADC_Sample@admin),w	;volatile
	movwf	((??_ADC_Sample+0)+0)
	movf	(ADC_Sample@admin+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	3+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+3),w	;volatile
	skipz
	goto	u1485
	movf	2+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+2),w	;volatile
	skipz
	goto	u1485
	movf	1+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+1),w	;volatile
	skipz
	goto	u1485
	movf	0+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum),w	;volatile
u1485:
	skipc
	goto	u1481
	goto	u1480
u1481:
	goto	l684
u1480:
	line	249
	
l4069:	
;SC8F072_Pwm_Demo.c: 249: adsum -= admin;
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
	goto	u1495
	goto	u1496
u1495:
	subwf	(ADC_Sample@adsum+1),f	;volatile
u1496:
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u1497
	goto	u1498
u1497:
	subwf	(ADC_Sample@adsum+2),f	;volatile
u1498:
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u1499
	goto	u1490
u1499:
	subwf	(ADC_Sample@adsum+3),f	;volatile
u1490:

	goto	l4071
	line	250
	
l684:	
	line	251
;SC8F072_Pwm_Demo.c: 250: else
;SC8F072_Pwm_Demo.c: 251: adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	252
	
l4071:	
;SC8F072_Pwm_Demo.c: 252: adresult = adsum >> 3;
	movf	(ADC_Sample@adsum),w	;volatile
	movwf	(??_ADC_Sample+0)+0
	movf	(ADC_Sample@adsum+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	movf	(ADC_Sample@adsum+2),w	;volatile
	movwf	((??_ADC_Sample+0)+0+2)
	movf	(ADC_Sample@adsum+3),w	;volatile
	movwf	((??_ADC_Sample+0)+0+3)
	movlw	03h
u1505:
	clrc
	rrf	(??_ADC_Sample+0)+3,f
	rrf	(??_ADC_Sample+0)+2,f
	rrf	(??_ADC_Sample+0)+1,f
	rrf	(??_ADC_Sample+0)+0,f
u1500:
	addlw	-1
	skipz
	goto	u1505
	movf	1+(??_ADC_Sample+0)+0,w
	movwf	(_adresult+1)	;volatile
	movf	0+(??_ADC_Sample+0)+0,w
	movwf	(_adresult)	;volatile
	line	253
	
l4073:	
;SC8F072_Pwm_Demo.c: 253: adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	254
	
l4075:	
;SC8F072_Pwm_Demo.c: 254: admin = 0;
	clrf	(ADC_Sample@admin)	;volatile
	clrf	(ADC_Sample@admin+1)	;volatile
	line	255
	
l4077:	
;SC8F072_Pwm_Demo.c: 255: admax = 0;
	clrf	(ADC_Sample@admax)	;volatile
	clrf	(ADC_Sample@admax+1)	;volatile
	line	256
	
l4079:	
;SC8F072_Pwm_Demo.c: 256: return 0xA5;
	movlw	low(0A5h)
	line	257
	
l677:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_Sample
	__end_of_ADC_Sample:
	signat	_ADC_Sample,8313
	global	_Isr_Timer

;; *************** function _Isr_Timer *****************
;; Defined at:
;;		line 283 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 0/0
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          3       0       0
;;      Totals:         3       0       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_Charge_num
;;		_Display
;;		_Uncharge_num
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text17,local,class=CODE,delta=2,merge=1,group=0
	line	283
global __ptext17
__ptext17:	;psect for function _Isr_Timer
psect	text17
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\SC8F072_Pwm_Demo.c"
	line	283
	global	__size_of_Isr_Timer
	__size_of_Isr_Timer	equ	__end_of_Isr_Timer-_Isr_Timer
	
_Isr_Timer:	
;incstack = 0
	opt	stack 2
; Regs used in _Isr_Timer: [wreg-fsr0h+status,2+status,0+pclath+cstack]
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
	movf	fsr0,w
	movwf	(??_Isr_Timer+1)
	movf	pclath,w
	movwf	(??_Isr_Timer+2)
	ljmp	_Isr_Timer
psect	text17
	line	285
	
i1l4677:	
;SC8F072_Pwm_Demo.c: 285: if(RAIF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(107/8),(107)&7	;volatile
	goto	u224_21
	goto	u224_20
u224_21:
	goto	i1l4701
u224_20:
	line	287
	
i1l4679:	
;SC8F072_Pwm_Demo.c: 286: {
;SC8F072_Pwm_Demo.c: 287: RAIF = 0;
	bcf	(107/8),(107)&7	;volatile
	line	288
;SC8F072_Pwm_Demo.c: 288: if (!(PORTA & 0x04))
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(134)^080h,(2)&7	;volatile
	goto	u225_21
	goto	u225_20
u225_21:
	goto	i1l4693
u225_20:
	line	290
	
i1l4681:	
;SC8F072_Pwm_Demo.c: 289: {
;SC8F072_Pwm_Demo.c: 290: if(LED_Key_counter > 1015 )
	movlw	03h
	bcf	status, 5	;RP0=0, select bank0
	subwf	(_LED_Key_counter+1),w
	movlw	0F8h
	skipnz
	subwf	(_LED_Key_counter),w
	skipc
	goto	u226_21
	goto	u226_20
u226_21:
	goto	i1l4685
u226_20:
	line	292
	
i1l4683:	
;SC8F072_Pwm_Demo.c: 291: {
;SC8F072_Pwm_Demo.c: 292: LED_lflag = 1;
	clrf	(_LED_lflag)
	incf	(_LED_lflag),f
	line	293
;SC8F072_Pwm_Demo.c: 293: }
	goto	i1l4691
	line	294
	
i1l4685:	
;SC8F072_Pwm_Demo.c: 294: else if(LED_Key_counter<=1015 && LED_Key_counter>=150)
	movlw	03h
	subwf	(_LED_Key_counter+1),w
	movlw	0F8h
	skipnz
	subwf	(_LED_Key_counter),w
	skipnc
	goto	u227_21
	goto	u227_20
u227_21:
	goto	i1l4691
u227_20:
	
i1l4687:	
	movlw	0
	subwf	(_LED_Key_counter+1),w
	movlw	096h
	skipnz
	subwf	(_LED_Key_counter),w
	skipc
	goto	u228_21
	goto	u228_20
u228_21:
	goto	i1l4691
u228_20:
	line	296
	
i1l4689:	
;SC8F072_Pwm_Demo.c: 295: {
;SC8F072_Pwm_Demo.c: 296: LED_sflag = 1;
	clrf	(_LED_sflag)
	incf	(_LED_sflag),f
	line	298
	
i1l4691:	
;SC8F072_Pwm_Demo.c: 297: }
;SC8F072_Pwm_Demo.c: 298: LED_Key_counter = 0;
	clrf	(_LED_Key_counter)
	clrf	(_LED_Key_counter+1)
	line	317
	
i1l4693:	
;SC8F072_Pwm_Demo.c: 299: }
;SC8F072_Pwm_Demo.c: 317: if (!(PORTA & 0x20))
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(134)^080h,(5)&7	;volatile
	goto	u229_21
	goto	u229_20
u229_21:
	goto	i1l701
u229_20:
	line	319
	
i1l4695:	
;SC8F072_Pwm_Demo.c: 318: {
;SC8F072_Pwm_Demo.c: 319: T_flag = 1;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_T_flag)
	incf	(_T_flag),f
	line	320
	
i1l4697:	
;SC8F072_Pwm_Demo.c: 320: Charge_num();
	fcall	_Charge_num
	line	321
;SC8F072_Pwm_Demo.c: 321: }
	goto	i1l4701
	line	322
	
i1l701:	
	line	324
;SC8F072_Pwm_Demo.c: 322: else
;SC8F072_Pwm_Demo.c: 323: {
;SC8F072_Pwm_Demo.c: 324: T_flag = 1;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_T_flag)
	incf	(_T_flag),f
	line	325
	
i1l4699:	
;SC8F072_Pwm_Demo.c: 325: Uncharge_num();
	fcall	_Uncharge_num
	line	329
	
i1l4701:	
;SC8F072_Pwm_Demo.c: 326: }
;SC8F072_Pwm_Demo.c: 327: }
;SC8F072_Pwm_Demo.c: 329: if(RBIF)
	btfss	(88/8),(88)&7	;volatile
	goto	u230_21
	goto	u230_20
u230_21:
	goto	i1l4717
u230_20:
	line	331
	
i1l4703:	
;SC8F072_Pwm_Demo.c: 330: {
;SC8F072_Pwm_Demo.c: 331: RBIF = 0;
	bcf	(88/8),(88)&7	;volatile
	line	332
;SC8F072_Pwm_Demo.c: 332: if (PORTB & 0x20)
	btfss	(6),(5)&7	;volatile
	goto	u231_21
	goto	u231_20
u231_21:
	goto	i1l4717
u231_20:
	line	334
	
i1l4705:	
;SC8F072_Pwm_Demo.c: 333: {
;SC8F072_Pwm_Demo.c: 334: if (long_press_counter > 1015)
	movlw	03h
	subwf	(_long_press_counter+1),w
	movlw	0F8h
	skipnz
	subwf	(_long_press_counter),w
	skipc
	goto	u232_21
	goto	u232_20
u232_21:
	goto	i1l4709
u232_20:
	line	336
	
i1l4707:	
;SC8F072_Pwm_Demo.c: 335: {
;SC8F072_Pwm_Demo.c: 336: button_lflag = 1;
	clrf	(_button_lflag)
	incf	(_button_lflag),f
	line	337
;SC8F072_Pwm_Demo.c: 337: }
	goto	i1l4715
	line	338
	
i1l4709:	
;SC8F072_Pwm_Demo.c: 338: else if(long_press_counter<=1015 && long_press_counter>=65)
	movlw	03h
	subwf	(_long_press_counter+1),w
	movlw	0F8h
	skipnz
	subwf	(_long_press_counter),w
	skipnc
	goto	u233_21
	goto	u233_20
u233_21:
	goto	i1l4715
u233_20:
	
i1l4711:	
	movlw	0
	subwf	(_long_press_counter+1),w
	movlw	041h
	skipnz
	subwf	(_long_press_counter),w
	skipc
	goto	u234_21
	goto	u234_20
u234_21:
	goto	i1l4715
u234_20:
	line	340
	
i1l4713:	
;SC8F072_Pwm_Demo.c: 339: {
;SC8F072_Pwm_Demo.c: 340: button_sflag = 1;
	clrf	(_button_sflag)
	incf	(_button_sflag),f
	line	342
	
i1l4715:	
;SC8F072_Pwm_Demo.c: 341: }
;SC8F072_Pwm_Demo.c: 342: long_press_counter = 0;
	clrf	(_long_press_counter)
	clrf	(_long_press_counter+1)
	line	345
	
i1l4717:	
;SC8F072_Pwm_Demo.c: 343: }
;SC8F072_Pwm_Demo.c: 344: }
;SC8F072_Pwm_Demo.c: 345: if(T0IF)
	btfss	(90/8),(90)&7	;volatile
	goto	u235_21
	goto	u235_20
u235_21:
	goto	i1l4733
u235_20:
	line	347
	
i1l4719:	
;SC8F072_Pwm_Demo.c: 346: {
;SC8F072_Pwm_Demo.c: 347: TMR0 += 6;
	movlw	low(06h)
	bsf	status, 5	;RP0=1, select bank1
	addwf	(129)^080h,f	;volatile
	line	348
	
i1l4721:	
;SC8F072_Pwm_Demo.c: 348: T0IF = 0;
	bcf	(90/8),(90)&7	;volatile
	line	349
;SC8F072_Pwm_Demo.c: 349: if(T_flag)
	bcf	status, 5	;RP0=0, select bank0
	movf	((_T_flag)),w
	btfsc	status,2
	goto	u236_21
	goto	u236_20
u236_21:
	goto	i1l4725
u236_20:
	line	351
	
i1l4723:	
;SC8F072_Pwm_Demo.c: 350: {
;SC8F072_Pwm_Demo.c: 351: Display();
	fcall	_Display
	line	355
	
i1l4725:	
;SC8F072_Pwm_Demo.c: 352: }
;SC8F072_Pwm_Demo.c: 355: if(ADC_delay > 0)
	movf	((_ADC_delay)),w
iorwf	((_ADC_delay+1)),w
	btfsc	status,2
	goto	u237_21
	goto	u237_20
u237_21:
	goto	i1l4729
u237_20:
	line	357
	
i1l4727:	
;SC8F072_Pwm_Demo.c: 356: {
;SC8F072_Pwm_Demo.c: 357: ADC_delay--;
	movlw	01h
	subwf	(_ADC_delay),f
	movlw	0
	skipc
	decf	(_ADC_delay+1),f
	subwf	(_ADC_delay+1),f
	line	358
;SC8F072_Pwm_Demo.c: 358: }
	goto	i1l4733
	line	361
	
i1l4729:	
;SC8F072_Pwm_Demo.c: 359: else
;SC8F072_Pwm_Demo.c: 360: {
;SC8F072_Pwm_Demo.c: 361: ADC_delay=1000;
	movlw	0E8h
	movwf	(_ADC_delay)
	movlw	03h
	movwf	((_ADC_delay))+1
	line	362
	
i1l4731:	
;SC8F072_Pwm_Demo.c: 362: ADC_Flag=1;
	clrf	(_ADC_Flag)
	incf	(_ADC_Flag),f
	line	365
	
i1l4733:	
;SC8F072_Pwm_Demo.c: 363: }
;SC8F072_Pwm_Demo.c: 364: }
;SC8F072_Pwm_Demo.c: 365: if(TMR2IF)
	btfss	(105/8),(105)&7	;volatile
	goto	u238_21
	goto	u238_20
u238_21:
	goto	i1l719
u238_20:
	line	367
	
i1l4735:	
;SC8F072_Pwm_Demo.c: 366: {
;SC8F072_Pwm_Demo.c: 367: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	387
;SC8F072_Pwm_Demo.c: 387: if (!(PORTA & 0x04))
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(134)^080h,(2)&7	;volatile
	goto	u239_21
	goto	u239_20
u239_21:
	goto	i1l4739
u239_20:
	line	389
	
i1l4737:	
;SC8F072_Pwm_Demo.c: 388: {
;SC8F072_Pwm_Demo.c: 389: LED_Key_counter++;
	bcf	status, 5	;RP0=0, select bank0
	incf	(_LED_Key_counter),f
	skipnz
	incf	(_LED_Key_counter+1),f
	line	393
	
i1l4739:	
;SC8F072_Pwm_Demo.c: 390: }
;SC8F072_Pwm_Demo.c: 393: if (!(PORTB & 0x20))
	bcf	status, 5	;RP0=0, select bank0
	btfsc	(6),(5)&7	;volatile
	goto	u240_21
	goto	u240_20
u240_21:
	goto	i1l4743
u240_20:
	line	395
	
i1l4741:	
;SC8F072_Pwm_Demo.c: 394: {
;SC8F072_Pwm_Demo.c: 395: long_press_counter++;
	incf	(_long_press_counter),f
	skipnz
	incf	(_long_press_counter+1),f
	line	398
	
i1l4743:	
;SC8F072_Pwm_Demo.c: 396: }
;SC8F072_Pwm_Demo.c: 398: if(Time_delay > 0)
	bsf	status, 5	;RP0=1, select bank1
	movf	((_Time_delay)^080h),w
iorwf	((_Time_delay+1)^080h),w
	btfsc	status,2
	goto	u241_21
	goto	u241_20
u241_21:
	goto	i1l715
u241_20:
	line	400
	
i1l4745:	
;SC8F072_Pwm_Demo.c: 399: {
;SC8F072_Pwm_Demo.c: 400: Time_delay--;
	movlw	01h
	subwf	(_Time_delay)^080h,f
	movlw	0
	skipc
	decf	(_Time_delay+1)^080h,f
	subwf	(_Time_delay+1)^080h,f
	line	401
;SC8F072_Pwm_Demo.c: 401: }
	goto	i1l719
	line	402
	
i1l715:	
	line	404
;SC8F072_Pwm_Demo.c: 402: else
;SC8F072_Pwm_Demo.c: 403: {
;SC8F072_Pwm_Demo.c: 404: if (!(PORTA & 0x20))
	btfsc	(134)^080h,(5)&7	;volatile
	goto	u242_21
	goto	u242_20
u242_21:
	goto	i1l4749
u242_20:
	line	406
	
i1l4747:	
;SC8F072_Pwm_Demo.c: 405: {
;SC8F072_Pwm_Demo.c: 406: Charge_num();
	fcall	_Charge_num
	line	407
;SC8F072_Pwm_Demo.c: 407: }
	goto	i1l719
	line	410
	
i1l4749:	
;SC8F072_Pwm_Demo.c: 408: else
;SC8F072_Pwm_Demo.c: 409: {
;SC8F072_Pwm_Demo.c: 410: Uncharge_num();
	fcall	_Uncharge_num
	line	414
	
i1l719:	
	movf	(??_Isr_Timer+2),w
	movwf	pclath
	movf	(??_Isr_Timer+1),w
	movwf	fsr0
	swapf	(??_Isr_Timer+0)^0FFFFFF80h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_Isr_Timer
	__end_of_Isr_Timer:
	signat	_Isr_Timer,89
	global	_Uncharge_num

;; *************** function _Uncharge_num *****************
;; Defined at:
;;		line 25 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  hundred         1    9[COMMON] unsigned char 
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
;;      Locals:         1       0       0
;;      Temps:          0       0       0
;;      Totals:         1       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		___lbdiv
;;		___lbmod
;; This function is called by:
;;		_Isr_Timer
;; This function uses a non-reentrant model
;;
psect	text18,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	25
global __ptext18
__ptext18:	;psect for function _Uncharge_num
psect	text18
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	25
	global	__size_of_Uncharge_num
	__size_of_Uncharge_num	equ	__end_of_Uncharge_num-_Uncharge_num
	
_Uncharge_num:	
;incstack = 0
	opt	stack 2
; Regs used in _Uncharge_num: [wreg+status,2+status,0+pclath+cstack]
	line	27
	
i1l4625:	
;LED_188.c: 27: bool hundred = (bool)(power_percent / 100);
	movlw	low(064h)
	movwf	(___lbdiv@divisor)
	bcf	status, 5	;RP0=0, select bank0
	movf	(_power_percent),w	;volatile
	fcall	___lbdiv
	movwf	(Uncharge_num@hundred)
	line	28
;LED_188.c: 28: tens = (unsigned char)((power_percent % 100) / 10);
	movlw	low(0Ah)
	movwf	(___lbdiv@divisor)
	movlw	low(064h)
	movwf	(___lbmod@divisor)
	movf	(_power_percent),w	;volatile
	fcall	___lbmod
	fcall	___lbdiv
	movwf	(_tens)
	line	29
;LED_188.c: 29: unit = (unsigned char)(power_percent % 10);
	movlw	low(0Ah)
	movwf	(___lbmod@divisor)
	movf	(_power_percent),w	;volatile
	fcall	___lbmod
	movwf	(_unit)
	line	30
	
i1l4627:	
;LED_188.c: 30: if(hundred)
	movf	((Uncharge_num@hundred)),w
	btfsc	status,2
	goto	u222_21
	goto	u222_20
u222_21:
	goto	i1l1333
u222_20:
	line	32
	
i1l4629:	
;LED_188.c: 31: {
;LED_188.c: 32: hundreds = 3;
	movlw	low(03h)
	movwf	(_hundreds)
	line	33
;LED_188.c: 33: }
	goto	i1l1335
	line	34
	
i1l1333:	
	line	36
;LED_188.c: 34: else
;LED_188.c: 35: {
;LED_188.c: 36: hundreds = 1;
	clrf	(_hundreds)
	incf	(_hundreds),f
	line	38
	
i1l1335:	
	return
	opt stack 0
GLOBAL	__end_of_Uncharge_num
	__end_of_Uncharge_num:
	signat	_Uncharge_num,89
	global	_Display

;; *************** function _Display *****************
;; Defined at:
;;		line 170 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
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
;;		_Display_Scan1
;;		_Display_Scan2
;;		_Display_Scan3
;;		_Display_Scan4
;;		_Display_Scan5
;;		_Set_AllPin_INPUT
;; This function is called by:
;;		_Isr_Timer
;; This function uses a non-reentrant model
;;
psect	text19,local,class=CODE,delta=2,merge=1,group=0
	line	170
global __ptext19
__ptext19:	;psect for function _Display
psect	text19
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	170
	global	__size_of_Display
	__size_of_Display	equ	__end_of_Display-_Display
	
_Display:	
;incstack = 0
	opt	stack 2
; Regs used in _Display: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	173
	
i1l4631:	
;LED_188.c: 172: static unsigned char scan_cnt;
;LED_188.c: 173: Set_AllPin_INPUT();
	fcall	_Set_AllPin_INPUT
	line	175
;LED_188.c: 175: switch(scan_cnt)
	goto	i1l4657
	line	177
	
i1l4633:	
	fcall	_Display_Scan1
	
i1l4635:	
	incf	(Display@scan_cnt),f
	goto	i1l1394
	line	178
	
i1l4637:	
	fcall	_Display_Scan2
	goto	i1l4635
	line	179
	
i1l4641:	
	fcall	_Display_Scan3
	goto	i1l4635
	line	180
	
i1l4645:	
	fcall	_Display_Scan4
	goto	i1l4635
	line	181
	
i1l4649:	
	fcall	_Display_Scan5
	
i1l4651:	
	clrf	(Display@scan_cnt)
	goto	i1l1394
	line	175
	
i1l4657:	
	movf	(Display@scan_cnt),w
	; Switch size 1, requested type "space"
; Number of cases is 5, Range of values is 0 to 4
; switch strategies available:
; Name         Instructions Cycles
; direct_byte           11     6 (fixed)
; simple_byte           16     9 (average)
; jumptable            260     6 (fixed)
;	Chosen strategy is direct_byte

	movwf fsr
	movlw	5
	subwf	fsr,w
skipnc
goto i1l4651
movlw high(i1S4847)
movwf pclath
	movlw low(i1S4847)
	addwf fsr,w
	movwf pc
psect	swtext4,local,class=CONST,delta=2
global __pswtext4
__pswtext4:
i1S4847:
	ljmp	i1l4633
	ljmp	i1l4637
	ljmp	i1l4641
	ljmp	i1l4645
	ljmp	i1l4649
psect	text19

	line	184
	
i1l1394:	
	return
	opt stack 0
GLOBAL	__end_of_Display
	__end_of_Display:
	signat	_Display,89
	global	_Set_AllPin_INPUT

;; *************** function _Set_AllPin_INPUT *****************
;; Defined at:
;;		line 85 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		None
;; Tracked objects:
;;		On entry : 100/0
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
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text20,local,class=CODE,delta=2,merge=1,group=0
	line	85
global __ptext20
__ptext20:	;psect for function _Set_AllPin_INPUT
psect	text20
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	85
	global	__size_of_Set_AllPin_INPUT
	__size_of_Set_AllPin_INPUT	equ	__end_of_Set_AllPin_INPUT-_Set_AllPin_INPUT
	
_Set_AllPin_INPUT:	
;incstack = 0
	opt	stack 2
; Regs used in _Set_AllPin_INPUT: []
	line	87
	
i1l4087:	
;LED_188.c: 87: TRISB0 = 1;;
	bsf	(40/8),(40)&7	;volatile
	line	88
;LED_188.c: 88: TRISB1 = 1;;
	bsf	(41/8),(41)&7	;volatile
	line	89
;LED_188.c: 89: TRISB2 = 1;;
	bsf	(42/8),(42)&7	;volatile
	line	90
;LED_188.c: 90: TRISB3 = 1;;
	bsf	(43/8),(43)&7	;volatile
	line	91
;LED_188.c: 91: TRISB4 = 1;;
	bsf	(44/8),(44)&7	;volatile
	line	92
	
i1l1348:	
	return
	opt stack 0
GLOBAL	__end_of_Set_AllPin_INPUT
	__end_of_Set_AllPin_INPUT:
	signat	_Set_AllPin_INPUT,89
	global	_Display_Scan5

;; *************** function _Display_Scan5 *****************
;; Defined at:
;;		line 161 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 900/0
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
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text21,local,class=CODE,delta=2,merge=1,group=0
	line	161
global __ptext21
__ptext21:	;psect for function _Display_Scan5
psect	text21
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	161
	global	__size_of_Display_Scan5
	__size_of_Display_Scan5	equ	__end_of_Display_Scan5-_Display_Scan5
	
_Display_Scan5:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan5: [wreg-fsr0h+status,2+status,0]
	line	163
	
i1l4161:	
;LED_188.c: 163: TRISB4 = 0;RB4 = 0;;
	bcf	(44/8),(44)&7	;volatile
	bcf	(52/8),(52)&7	;volatile
	line	164
	
i1l4163:	
;LED_188.c: 164: if(num_hund[hundreds] & 0x02)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(1)&7
	goto	u167_21
	goto	u167_20
u167_21:
	goto	i1l1379
u167_20:
	line	165
	
i1l4165:	
;LED_188.c: 165: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1379:	
	bsf	(50/8),(50)&7	;volatile
	line	166
	
i1l4167:	
;LED_188.c: 166: if(num_hund[hundreds] & 0x01)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u168_21
	goto	u168_20
u168_21:
	goto	i1l1380
u168_20:
	line	167
	
i1l4169:	
;LED_188.c: 167: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1380:	
	bsf	(49/8),(49)&7	;volatile
	line	168
	
i1l1381:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan5
	__end_of_Display_Scan5:
	signat	_Display_Scan5,89
	global	_Display_Scan4

;; *************** function _Display_Scan4 *****************
;; Defined at:
;;		line 147 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 900/0
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
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text22,local,class=CODE,delta=2,merge=1,group=0
	line	147
global __ptext22
__ptext22:	;psect for function _Display_Scan4
psect	text22
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	147
	global	__size_of_Display_Scan4
	__size_of_Display_Scan4	equ	__end_of_Display_Scan4-_Display_Scan4
	
_Display_Scan4:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan4: [wreg-fsr0h+status,2+status,0]
	line	149
	
i1l4143:	
;LED_188.c: 149: TRISB3 = 0;RB3 = 0;;
	bcf	(43/8),(43)&7	;volatile
	bcf	(51/8),(51)&7	;volatile
	line	150
	
i1l4145:	
;LED_188.c: 150: if(nums[unit] & 0x04)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(2)&7
	goto	u163_21
	goto	u163_20
u163_21:
	goto	i1l1372
u163_20:
	line	151
	
i1l4147:	
;LED_188.c: 151: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1372:	
	bsf	(48/8),(48)&7	;volatile
	line	152
	
i1l4149:	
;LED_188.c: 152: if(num_hund[hundreds] & 0x04)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(2)&7
	goto	u164_21
	goto	u164_20
u164_21:
	goto	i1l1373
u164_20:
	line	153
	
i1l4151:	
;LED_188.c: 153: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1373:	
	bsf	(49/8),(49)&7	;volatile
	line	154
	
i1l4153:	
;LED_188.c: 154: if(num_hund[hundreds] & 0x08)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u165_21
	goto	u165_20
u165_21:
	goto	i1l1374
u165_20:
	line	155
	
i1l4155:	
;LED_188.c: 155: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1374:	
	bsf	(50/8),(50)&7	;volatile
	line	156
	
i1l4157:	
;LED_188.c: 156: if(nums[tens] & 0x01)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u166_21
	goto	u166_20
u166_21:
	goto	i1l1375
u166_20:
	line	157
	
i1l4159:	
;LED_188.c: 157: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1375:	
	bsf	(52/8),(52)&7	;volatile
	line	158
	
i1l1376:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan4
	__end_of_Display_Scan4:
	signat	_Display_Scan4,89
	global	_Display_Scan3

;; *************** function _Display_Scan3 *****************
;; Defined at:
;;		line 133 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 900/0
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
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text23,local,class=CODE,delta=2,merge=1,group=0
	line	133
global __ptext23
__ptext23:	;psect for function _Display_Scan3
psect	text23
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	133
	global	__size_of_Display_Scan3
	__size_of_Display_Scan3	equ	__end_of_Display_Scan3-_Display_Scan3
	
_Display_Scan3:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan3: [wreg-fsr0h+status,2+status,0]
	line	135
	
i1l4125:	
;LED_188.c: 135: TRISB2 = 0;RB2 = 0;;
	bcf	(42/8),(42)&7	;volatile
	bcf	(50/8),(50)&7	;volatile
	line	136
	
i1l4127:	
;LED_188.c: 136: if(nums[unit] & 0x10)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(4)&7
	goto	u159_21
	goto	u159_20
u159_21:
	goto	i1l1365
u159_20:
	line	137
	
i1l4129:	
;LED_188.c: 137: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1365:	
	bsf	(48/8),(48)&7	;volatile
	line	138
	
i1l4131:	
;LED_188.c: 138: if(nums[tens] & 0x40)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(6)&7
	goto	u160_21
	goto	u160_20
u160_21:
	goto	i1l1366
u160_20:
	line	139
	
i1l4133:	
;LED_188.c: 139: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1366:	
	bsf	(49/8),(49)&7	;volatile
	line	140
	
i1l4135:	
;LED_188.c: 140: if(nums[tens] & 0x10)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(4)&7
	goto	u161_21
	goto	u161_20
u161_21:
	goto	i1l1367
u161_20:
	line	141
	
i1l4137:	
;LED_188.c: 141: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1367:	
	bsf	(51/8),(51)&7	;volatile
	line	142
	
i1l4139:	
;LED_188.c: 142: if(nums[tens] & 0x02)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(1)&7
	goto	u162_21
	goto	u162_20
u162_21:
	goto	i1l1368
u162_20:
	line	143
	
i1l4141:	
;LED_188.c: 143: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1368:	
	bsf	(52/8),(52)&7	;volatile
	line	144
	
i1l1369:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan3
	__end_of_Display_Scan3:
	signat	_Display_Scan3,89
	global	_Display_Scan2

;; *************** function _Display_Scan2 *****************
;; Defined at:
;;		line 119 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 900/0
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
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text24,local,class=CODE,delta=2,merge=1,group=0
	line	119
global __ptext24
__ptext24:	;psect for function _Display_Scan2
psect	text24
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	119
	global	__size_of_Display_Scan2
	__size_of_Display_Scan2	equ	__end_of_Display_Scan2-_Display_Scan2
	
_Display_Scan2:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan2: [wreg-fsr0h+status,2+status,0]
	line	121
	
i1l4107:	
;LED_188.c: 121: TRISB1 = 0;RB1 = 0;;
	bcf	(41/8),(41)&7	;volatile
	bcf	(49/8),(49)&7	;volatile
	line	122
	
i1l4109:	
;LED_188.c: 122: if(nums[unit] &0x40)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(6)&7
	goto	u155_21
	goto	u155_20
u155_21:
	goto	i1l1358
u155_20:
	line	123
	
i1l4111:	
;LED_188.c: 123: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1358:	
	bsf	(48/8),(48)&7	;volatile
	line	124
	
i1l4113:	
;LED_188.c: 124: if(nums[tens] & 0x20)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(5)&7
	goto	u156_21
	goto	u156_20
u156_21:
	goto	i1l1359
u156_20:
	line	125
	
i1l4115:	
;LED_188.c: 125: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1359:	
	bsf	(50/8),(50)&7	;volatile
	line	126
	
i1l4117:	
;LED_188.c: 126: if(nums[tens] & 0x08)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u157_21
	goto	u157_20
u157_21:
	goto	i1l1360
u157_20:
	line	127
	
i1l4119:	
;LED_188.c: 127: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1360:	
	bsf	(51/8),(51)&7	;volatile
	line	128
	
i1l4121:	
;LED_188.c: 128: if(nums[tens] & 0x04)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(2)&7
	goto	u158_21
	goto	u158_20
u158_21:
	goto	i1l1361
u158_20:
	line	129
	
i1l4123:	
;LED_188.c: 129: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1361:	
	bsf	(52/8),(52)&7	;volatile
	line	130
	
i1l1362:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan2
	__end_of_Display_Scan2:
	signat	_Display_Scan2,89
	global	_Display_Scan1

;; *************** function _Display_Scan1 *****************
;; Defined at:
;;		line 105 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 900/0
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
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text25,local,class=CODE,delta=2,merge=1,group=0
	line	105
global __ptext25
__ptext25:	;psect for function _Display_Scan1
psect	text25
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	105
	global	__size_of_Display_Scan1
	__size_of_Display_Scan1	equ	__end_of_Display_Scan1-_Display_Scan1
	
_Display_Scan1:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan1: [wreg-fsr0h+status,2+status,0]
	line	107
	
i1l4089:	
;LED_188.c: 107: TRISB0 = 0;RB0 = 0;;
	bcf	(40/8),(40)&7	;volatile
	bcf	(48/8),(48)&7	;volatile
	line	108
	
i1l4091:	
;LED_188.c: 108: if(nums[unit] & 0x20)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(5)&7
	goto	u151_21
	goto	u151_20
u151_21:
	goto	i1l1351
u151_20:
	line	109
	
i1l4093:	
;LED_188.c: 109: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1351:	
	bsf	(49/8),(49)&7	;volatile
	line	110
	
i1l4095:	
;LED_188.c: 110: if(nums[unit] & 0x08)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u152_21
	goto	u152_20
u152_21:
	goto	i1l1352
u152_20:
	line	111
	
i1l4097:	
;LED_188.c: 111: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1352:	
	bsf	(50/8),(50)&7	;volatile
	line	112
	
i1l4099:	
;LED_188.c: 112: if(nums[unit] & 0x02)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(1)&7
	goto	u153_21
	goto	u153_20
u153_21:
	goto	i1l1353
u153_20:
	line	113
	
i1l4101:	
;LED_188.c: 113: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1353:	
	bsf	(51/8),(51)&7	;volatile
	line	114
	
i1l4103:	
;LED_188.c: 114: if(nums[unit] &0x01)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u154_21
	goto	u154_20
u154_21:
	goto	i1l1354
u154_20:
	line	115
	
i1l4105:	
;LED_188.c: 115: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1354:	
	bsf	(52/8),(52)&7	;volatile
	line	116
	
i1l1355:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan1
	__end_of_Display_Scan1:
	signat	_Display_Scan1,89
	global	_Charge_num

;; *************** function _Charge_num *****************
;; Defined at:
;;		line 11 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  hundred         1    9[COMMON] unsigned char 
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
;;      Locals:         1       0       0
;;      Temps:          0       0       0
;;      Totals:         1       0       0
;;Total ram usage:        1 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    1
;; This function calls:
;;		___lbdiv
;;		___lbmod
;; This function is called by:
;;		_Isr_Timer
;; This function uses a non-reentrant model
;;
psect	text26,local,class=CODE,delta=2,merge=1,group=0
	line	11
global __ptext26
__ptext26:	;psect for function _Charge_num
psect	text26
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_double_key\LED_188.c"
	line	11
	global	__size_of_Charge_num
	__size_of_Charge_num	equ	__end_of_Charge_num-_Charge_num
	
_Charge_num:	
;incstack = 0
	opt	stack 2
; Regs used in _Charge_num: [wreg+status,2+status,0+pclath+cstack]
	line	13
	
i1l4617:	
;LED_188.c: 13: bool hundred = (bool)(power_percent / 100);
	movlw	low(064h)
	movwf	(___lbdiv@divisor)
	bcf	status, 5	;RP0=0, select bank0
	movf	(_power_percent),w	;volatile
	fcall	___lbdiv
	movwf	(Charge_num@hundred)
	line	14
;LED_188.c: 14: tens = (unsigned char)((power_percent % 100) / 10);
	movlw	low(0Ah)
	movwf	(___lbdiv@divisor)
	movlw	low(064h)
	movwf	(___lbmod@divisor)
	movf	(_power_percent),w	;volatile
	fcall	___lbmod
	fcall	___lbdiv
	movwf	(_tens)
	line	15
;LED_188.c: 15: unit = (unsigned char)(power_percent % 10);
	movlw	low(0Ah)
	movwf	(___lbmod@divisor)
	movf	(_power_percent),w	;volatile
	fcall	___lbmod
	movwf	(_unit)
	line	16
	
i1l4619:	
;LED_188.c: 16: if(hundred)
	movf	((Charge_num@hundred)),w
	btfsc	status,2
	goto	u221_21
	goto	u221_20
u221_21:
	goto	i1l4623
u221_20:
	line	18
	
i1l4621:	
;LED_188.c: 17: {
;LED_188.c: 18: hundreds = 4;
	movlw	low(04h)
	movwf	(_hundreds)
	line	19
;LED_188.c: 19: }
	goto	i1l1330
	line	22
	
i1l4623:	
;LED_188.c: 20: else
;LED_188.c: 21: {
;LED_188.c: 22: hundreds = 2;
	movlw	low(02h)
	movwf	(_hundreds)
	line	24
	
i1l1330:	
	return
	opt stack 0
GLOBAL	__end_of_Charge_num
	__end_of_Charge_num:
	signat	_Charge_num,89
	global	___lbmod

;; *************** function ___lbmod *****************
;; Defined at:
;;		line 4 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbmod.c"
;; Parameters:    Size  Location     Type
;;  dividend        1    wreg     unsigned char 
;;  divisor         1    0[COMMON] unsigned char 
;; Auto vars:     Size  Location     Type
;;  dividend        1    2[COMMON] unsigned char 
;;  rem             1    4[COMMON] unsigned char 
;;  counter         1    3[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 100/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         1       0       0
;;      Locals:         3       0       0
;;      Temps:          1       0       0
;;      Totals:         5       0       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Charge_num
;;		_Uncharge_num
;; This function uses a non-reentrant model
;;
psect	text27,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbmod.c"
	line	4
global __ptext27
__ptext27:	;psect for function ___lbmod
psect	text27
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbmod.c"
	line	4
	global	__size_of___lbmod
	__size_of___lbmod	equ	__end_of___lbmod-___lbmod
	
___lbmod:	
;incstack = 0
	opt	stack 2
; Regs used in ___lbmod: [wreg+status,2+status,0]
;___lbmod@dividend stored from wreg
	movwf	(___lbmod@dividend)
	line	9
	
i1l4407:	
	movlw	low(08h)
	movwf	(___lbmod@counter)
	line	10
	
i1l4409:	
	clrf	(___lbmod@rem)
	line	12
	
i1l4411:	
	movf	(___lbmod@dividend),w
	movwf	(??___lbmod+0)+0
	movlw	07h
u212_25:
	clrc
	rrf	(??___lbmod+0)+0,f
	addlw	-1
	skipz
	goto	u212_25
	clrc
	rlf	(___lbmod@rem),w
	iorwf	0+(??___lbmod+0)+0,w
	movwf	(___lbmod@rem)
	line	13
	
i1l4413:	
	clrc
	rlf	(___lbmod@dividend),f
	line	14
	
i1l4415:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),w
	skipc
	goto	u213_21
	goto	u213_20
u213_21:
	goto	i1l4419
u213_20:
	line	15
	
i1l4417:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),f
	line	16
	
i1l4419:	
	decfsz	(___lbmod@counter),f
	goto	u214_21
	goto	u214_20
u214_21:
	goto	i1l4411
u214_20:
	line	17
	
i1l4421:	
	movf	(___lbmod@rem),w
	line	18
	
i1l2920:	
	return
	opt stack 0
GLOBAL	__end_of___lbmod
	__end_of___lbmod:
	signat	___lbmod,8313
	global	___lbdiv

;; *************** function ___lbdiv *****************
;; Defined at:
;;		line 4 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbdiv.c"
;; Parameters:    Size  Location     Type
;;  dividend        1    wreg     unsigned char 
;;  divisor         1    5[COMMON] unsigned char 
;; Auto vars:     Size  Location     Type
;;  dividend        1    6[COMMON] unsigned char 
;;  quotient        1    8[COMMON] unsigned char 
;;  counter         1    7[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 100/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         1       0       0
;;      Locals:         3       0       0
;;      Temps:          0       0       0
;;      Totals:         4       0       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Charge_num
;;		_Uncharge_num
;; This function uses a non-reentrant model
;;
psect	text28,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbdiv.c"
	line	4
global __ptext28
__ptext28:	;psect for function ___lbdiv
psect	text28
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbdiv.c"
	line	4
	global	__size_of___lbdiv
	__size_of___lbdiv	equ	__end_of___lbdiv-___lbdiv
	
___lbdiv:	
;incstack = 0
	opt	stack 2
; Regs used in ___lbdiv: [wreg+status,2+status,0]
;___lbdiv@dividend stored from wreg
	movwf	(___lbdiv@dividend)
	line	9
	
i1l4383:	
	clrf	(___lbdiv@quotient)
	line	10
	
i1l4385:	
	movf	((___lbdiv@divisor)),w
	btfsc	status,2
	goto	u208_21
	goto	u208_20
u208_21:
	goto	i1l4403
u208_20:
	line	11
	
i1l4387:	
	clrf	(___lbdiv@counter)
	incf	(___lbdiv@counter),f
	line	12
	goto	i1l4391
	
i1l2909:	
	line	13
	clrc
	rlf	(___lbdiv@divisor),f
	line	14
	
i1l4389:	
	incf	(___lbdiv@counter),f
	line	12
	
i1l4391:	
	btfss	(___lbdiv@divisor),(7)&7
	goto	u209_21
	goto	u209_20
u209_21:
	goto	i1l2909
u209_20:
	line	16
	
i1l2911:	
	line	17
	clrc
	rlf	(___lbdiv@quotient),f
	line	18
	
i1l4393:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),w
	skipc
	goto	u210_21
	goto	u210_20
u210_21:
	goto	i1l4399
u210_20:
	line	19
	
i1l4395:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),f
	line	20
	
i1l4397:	
	bsf	(___lbdiv@quotient)+(0/8),(0)&7
	line	22
	
i1l4399:	
	clrc
	rrf	(___lbdiv@divisor),f
	line	23
	
i1l4401:	
	decfsz	(___lbdiv@counter),f
	goto	u211_21
	goto	u211_20
u211_21:
	goto	i1l2911
u211_20:
	line	25
	
i1l4403:	
	movf	(___lbdiv@quotient),w
	line	26
	
i1l2914:	
	return
	opt stack 0
GLOBAL	__end_of___lbdiv
	__end_of___lbdiv:
	signat	___lbdiv,8313
global	___latbits
___latbits	equ	0
	global	btemp
	btemp set 07Eh

	DABS	1,126,2	;btemp
	global	wtemp0
	wtemp0 set btemp+0
	end
