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
	FNCALL	_Set_PWM,___awdiv
	FNCALL	_Set_PWM,___wmul
	FNCALL	_ADC_read,_ADC_Sample
	FNCALL	_ADC_read,___ftadd
	FNCALL	_ADC_read,___ftdiv
	FNCALL	_ADC_read,___fttol
	FNCALL	_ADC_read,___lwtoft
	FNCALL	___ftdiv,___ftpack
	FNCALL	_ADC_Sample,___ftadd
	FNCALL	_ADC_Sample,___ftmul
	FNCALL	_ADC_Sample,___fttol
	FNCALL	_ADC_Sample,___lwtoft
	FNCALL	___lwtoft,___ftpack
	FNCALL	___ftmul,___ftpack
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	5

;initializer for _tens
	retlw	04h
psect	idataBANK0,class=CODE,space=0,delta=2,noexec
global __pidataBANK0
__pidataBANK0:
	line	6

;initializer for _unit
	retlw	02h
	line	4

;initializer for _hundreds
	retlw	04h
psect	idataBANK1,class=CODE,space=0,delta=2,noexec
global __pidataBANK1
__pidataBANK1:
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	35
_duty_steps:
	retlw	042h
	retlw	049h
	retlw	055h
	retlw	05Bh
	retlw	05Fh
	retlw	low(0)
	global __end_of_duty_steps
__end_of_duty_steps:
	global	_duty_steps
	global	_pwm_duty
	global	_power_percent
	global	_Time_delay
	global	_long_press_counter
	global	_adc_last
	global	_ADC_delay
	global	_power_ad
	global	Display@scan_cnt
	global	_T_flag
	global	_button_lflag
	global	_button_sflag
	global	_debounce_counter
	global	_ADC_Flag
	global	_test_adc
	global	_adresult
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	5
_tens:
       ds      1

psect	bssBANK0,class=BANK0,space=1,noexec
global __pbssBANK0
__pbssBANK0:
_pwm_duty:
       ds      1

_power_percent:
       ds      1

psect	dataBANK0,class=BANK0,space=1,noexec
global __pdataBANK0
__pdataBANK0:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	6
_unit:
       ds      1

psect	dataBANK0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	4
_hundreds:
       ds      1

psect	bssBANK1,class=BANK1,space=1,noexec
global __pbssBANK1
__pbssBANK1:
_Time_delay:
       ds      2

_long_press_counter:
       ds      2

_adc_last:
       ds      2

_ADC_delay:
       ds      2

_power_ad:
       ds      2

Display@scan_cnt:
       ds      1

_T_flag:
       ds      1

_button_lflag:
       ds      1

_button_sflag:
       ds      1

_debounce_counter:
       ds      1

_ADC_Flag:
       ds      1

_test_adc:
       ds      1

_adresult:
       ds      2

psect	dataBANK1,class=BANK1,space=1,noexec
global __pdataBANK1
__pdataBANK1:
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	73
_nums:
       ds      12

psect	dataBANK1
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
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
	bcf	status, 7	;select IRP bank0
	movlw	low(__pbssBANK1)
	movwf	fsr
	movlw	low((__pbssBANK1)+013h)
	fcall	clear_ram0
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2,merge=1
	clrf	((__pbssBANK0)+0)&07Fh
	clrf	((__pbssBANK0)+1)&07Fh
psect cinit,class=CODE,delta=2,merge=1
global end_of_initialization,__end_of__initialization

;End of C runtime variable initialization code

end_of_initialization:
__end_of__initialization:
clrf status
ljmp _main	;jump to C main() function
psect	cstackBANK1,class=BANK1,space=1,noexec
global __pcstackBANK1
__pcstackBANK1:
	global	ADC_Sample@j
ADC_Sample@j:	; 1 bytes @ 0x0
	ds	1
	global	ADC_Sample@adch
ADC_Sample@adch:	; 1 bytes @ 0x1
	ds	1
	global	ADC_Sample@i
ADC_Sample@i:	; 1 bytes @ 0x2
	ds	1
	global	ADC_Sample@admin
ADC_Sample@admin:	; 2 bytes @ 0x3
	ds	2
	global	ADC_Sample@admax
ADC_Sample@admax:	; 2 bytes @ 0x5
	ds	2
	global	ADC_Sample@adsum
ADC_Sample@adsum:	; 4 bytes @ 0x7
	ds	4
	global	ADC_Sample@ad_temp
ADC_Sample@ad_temp:	; 2 bytes @ 0xB
	ds	2
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_Init_System:	; 1 bytes @ 0x0
?_Led_Gpio_Init:	; 1 bytes @ 0x0
?_PWM_Init:	; 1 bytes @ 0x0
?_Button_response:	; 1 bytes @ 0x0
?_ADC_read:	; 1 bytes @ 0x0
?_Motor_num:	; 1 bytes @ 0x0
?_Charge_num:	; 1 bytes @ 0x0
?_Uncharge_num:	; 1 bytes @ 0x0
?_Display:	; 1 bytes @ 0x0
??_Display:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?_Isr_Timer:	; 1 bytes @ 0x0
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
??_Motor_num:	; 1 bytes @ 0x0
	global	?___wmul
?___wmul:	; 2 bytes @ 0x0
	global	?___awmod
?___awmod:	; 2 bytes @ 0x0
	global	?___ftpack
?___ftpack:	; 3 bytes @ 0x0
	global	___wmul@multiplier
___wmul@multiplier:	; 2 bytes @ 0x0
	global	___awmod@divisor
___awmod@divisor:	; 2 bytes @ 0x0
	global	___ftpack@arg
___ftpack@arg:	; 3 bytes @ 0x0
	ds	2
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
	global	___awmod@sign
___awmod@sign:	; 1 bytes @ 0x5
	ds	1
	global	?___awdiv
?___awdiv:	; 2 bytes @ 0x6
	global	___awdiv@divisor
___awdiv@divisor:	; 2 bytes @ 0x6
	ds	2
	global	?___lwtoft
?___lwtoft:	; 3 bytes @ 0x8
	global	___awdiv@dividend
___awdiv@dividend:	; 2 bytes @ 0x8
	global	___lwtoft@c
___lwtoft@c:	; 2 bytes @ 0x8
	ds	2
??___awdiv:	; 1 bytes @ 0xA
	global	___awdiv@counter
___awdiv@counter:	; 1 bytes @ 0xA
	ds	1
??___lwtoft:	; 1 bytes @ 0xB
	global	?___ftmul
?___ftmul:	; 3 bytes @ 0xB
	global	___awdiv@sign
___awdiv@sign:	; 1 bytes @ 0xB
	global	___ftmul@f1
___ftmul@f1:	; 3 bytes @ 0xB
	ds	1
	global	___awdiv@quotient
___awdiv@quotient:	; 2 bytes @ 0xC
	ds	2
?_Set_PWM:	; 1 bytes @ 0xE
	global	Set_PWM@duty
Set_PWM@duty:	; 1 bytes @ 0xE
	global	___ftmul@f2
___ftmul@f2:	; 3 bytes @ 0xE
	ds	1
??_Set_PWM:	; 1 bytes @ 0xF
	global	Set_PWM@channel
Set_PWM@channel:	; 1 bytes @ 0xF
	ds	1
	global	Set_PWM@pulse_width
Set_PWM@pulse_width:	; 1 bytes @ 0x10
	ds	1
??_Button_response:	; 1 bytes @ 0x11
??___ftmul:	; 1 bytes @ 0x11
	ds	3
	global	___ftmul@exp
___ftmul@exp:	; 1 bytes @ 0x14
	ds	1
	global	___ftmul@f3_as_product
___ftmul@f3_as_product:	; 3 bytes @ 0x15
	ds	3
	global	___ftmul@cntr
___ftmul@cntr:	; 1 bytes @ 0x18
	ds	1
	global	___ftmul@sign
___ftmul@sign:	; 1 bytes @ 0x19
	ds	1
	global	?___ftadd
?___ftadd:	; 3 bytes @ 0x1A
	global	___ftadd@f1
___ftadd@f1:	; 3 bytes @ 0x1A
	ds	3
	global	___ftadd@f2
___ftadd@f2:	; 3 bytes @ 0x1D
	ds	3
??___ftadd:	; 1 bytes @ 0x20
	ds	3
	global	___ftadd@sign
___ftadd@sign:	; 1 bytes @ 0x23
	ds	1
	global	___ftadd@exp2
___ftadd@exp2:	; 1 bytes @ 0x24
	ds	1
	global	___ftadd@exp1
___ftadd@exp1:	; 1 bytes @ 0x25
	ds	1
	global	?___ftdiv
?___ftdiv:	; 3 bytes @ 0x26
	global	___ftdiv@f2
___ftdiv@f2:	; 3 bytes @ 0x26
	ds	3
	global	___ftdiv@f1
___ftdiv@f1:	; 3 bytes @ 0x29
	ds	3
??___ftdiv:	; 1 bytes @ 0x2C
	ds	3
	global	___ftdiv@cntr
___ftdiv@cntr:	; 1 bytes @ 0x2F
	ds	1
	global	___ftdiv@f3
___ftdiv@f3:	; 3 bytes @ 0x30
	ds	3
	global	___ftdiv@exp
___ftdiv@exp:	; 1 bytes @ 0x33
	ds	1
	global	___ftdiv@sign
___ftdiv@sign:	; 1 bytes @ 0x34
	ds	1
	global	?___fttol
?___fttol:	; 4 bytes @ 0x35
	global	___fttol@f1
___fttol@f1:	; 3 bytes @ 0x35
	ds	4
??___fttol:	; 1 bytes @ 0x39
	ds	3
	global	___fttol@sign1
___fttol@sign1:	; 1 bytes @ 0x3C
	ds	1
	global	___fttol@lval
___fttol@lval:	; 4 bytes @ 0x3D
	ds	4
	global	___fttol@exp1
___fttol@exp1:	; 1 bytes @ 0x41
	ds	1
?_ADC_Sample:	; 1 bytes @ 0x42
	global	ADC_Sample@adldo
ADC_Sample@adldo:	; 1 bytes @ 0x42
	ds	1
??_ADC_Sample:	; 1 bytes @ 0x43
	ds	4
??_ADC_read:	; 1 bytes @ 0x47
	ds	1
	global	ADC_read@power_temp
ADC_read@power_temp:	; 4 bytes @ 0x48
	ds	4
??_main:	; 1 bytes @ 0x4C
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    6
;!    Data        20
;!    BSS         21
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14     13      14
;!    BANK0            80     76      80
;!    BANK1            80     13      49

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
;!    _Set_PWM->___awdiv
;!    ___awdiv->___wmul
;!    _ADC_read->_ADC_Sample
;!    ___ftdiv->___ftadd
;!    _ADC_Sample->___fttol
;!    ___lwtoft->___ftpack
;!    ___fttol->___ftdiv
;!    ___ftmul->___lwtoft
;!    ___ftadd->___ftmul
;!
;!Critical Paths under _Isr_Timer in BANK0
;!
;!    None.
;!
;!Critical Paths under _main in BANK1
;!
;!    _ADC_read->_ADC_Sample
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
;! (0) _main                                                 0     0      0   17912
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
;! (1) _Button_response                                      1     1      0    2455
;!                                             17 BANK0      1     1      0
;!                          _Motor_num
;!                            _Set_PWM
;!                            ___awmod
;! ---------------------------------------------------------------------------------
;! (2) ___awmod                                              6     2      4     424
;!                                              0 BANK0      6     2      4
;! ---------------------------------------------------------------------------------
;! (2) _Set_PWM                                              3     2      1    2031
;!                                             14 BANK0      3     2      1
;!                            ___awdiv
;!                             ___wmul
;! ---------------------------------------------------------------------------------
;! (3) ___wmul                                               6     2      4     198
;!                                              0 BANK0      6     2      4
;! ---------------------------------------------------------------------------------
;! (3) ___awdiv                                              8     4      4     406
;!                                              6 BANK0      8     4      4
;!                             ___wmul (ARG)
;! ---------------------------------------------------------------------------------
;! (2) _Motor_num                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _ADC_read                                             5     5      0   15457
;!                                             71 BANK0      5     5      0
;!                         _ADC_Sample
;!                            ___ftadd
;!                            ___ftdiv
;!                            ___fttol
;!                           ___lwtoft
;! ---------------------------------------------------------------------------------
;! (2) ___ftdiv                                             15     9      6    2201
;!                                             38 BANK0     15     9      6
;!                            ___ftadd (ARG)
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) _ADC_Sample                                          18    17      1    8042
;!                                             66 BANK0      5     4      1
;!                                              0 BANK1     13    13      0
;!                            ___ftadd
;!                            ___ftmul
;!                            ___fttol
;!                           ___lwtoft
;! ---------------------------------------------------------------------------------
;! (2) ___lwtoft                                             3     0      3    1941
;!                                              8 BANK0      3     0      3
;!                           ___ftpack
;! ---------------------------------------------------------------------------------
;! (2) ___fttol                                             13     9      4     411
;!                                             53 BANK0     13     9      4
;!                            ___ftadd (ARG)
;!                            ___ftdiv (ARG)
;!                            ___ftmul (ARG)
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (3) ___ftmul                                             15     9      6    2247
;!                                             11 BANK0     15     9      6
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftadd                                             12     6      6    2839
;!                                             26 BANK0     12     6      6
;!                            ___ftmul (ARG)
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (3) ___ftpack                                             8     3      5    1707
;!                                              0 BANK0      8     3      5
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 3
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (5) _Isr_Timer                                            3     3      0    1536
;!                                             10 COMMON     3     3      0
;!                         _Charge_num
;!                            _Display
;!                       _Uncharge_num
;! ---------------------------------------------------------------------------------
;! (6) _Uncharge_num                                         1     1      0     768
;!                                              9 COMMON     1     1      0
;!                            ___lbdiv
;!                            ___lbmod
;! ---------------------------------------------------------------------------------
;! (6) _Display                                              0     0      0       0
;!                      _Display_Scan1
;!                      _Display_Scan2
;!                      _Display_Scan3
;!                      _Display_Scan4
;!                      _Display_Scan5
;!                   _Set_AllPin_INPUT
;! ---------------------------------------------------------------------------------
;! (7) _Set_AllPin_INPUT                                     0     0      0       0
;! ---------------------------------------------------------------------------------
;! (7) _Display_Scan5                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (7) _Display_Scan4                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (7) _Display_Scan3                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (7) _Display_Scan2                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (7) _Display_Scan1                                        0     0      0       0
;! ---------------------------------------------------------------------------------
;! (6) _Charge_num                                           1     1      0     768
;!                                              9 COMMON     1     1      0
;!                            ___lbdiv
;!                            ___lbmod
;! ---------------------------------------------------------------------------------
;! (7) ___lbmod                                              5     4      1     371
;!                                              0 COMMON     5     4      1
;! ---------------------------------------------------------------------------------
;! (7) ___lbdiv                                              4     3      1     374
;!                                              5 COMMON     4     3      1
;!                            ___lbmod (ARG)
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 7
;! ---------------------------------------------------------------------------------
;!
;! Call Graph Graphs:
;!
;! _main (ROOT)
;!   _ADC_read
;!     _ADC_Sample
;!       ___ftadd
;!         ___ftmul (ARG)
;!           ___ftpack
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftpack (ARG)
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftmul
;!         ___ftpack
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___fttol
;!         ___ftadd (ARG)
;!           ___ftmul (ARG)
;!             ___ftpack
;!             ___lwtoft (ARG)
;!               ___ftpack
;!           ___ftpack (ARG)
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftdiv (ARG)
;!           ___ftadd (ARG)
;!             ___ftmul (ARG)
;!               ___ftpack
;!               ___lwtoft (ARG)
;!                 ___ftpack
;!             ___ftpack (ARG)
;!             ___lwtoft (ARG)
;!               ___ftpack
;!           ___ftpack (ARG)
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftmul (ARG)
;!           ___ftpack
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___lwtoft
;!         ___ftpack
;!     ___ftadd
;!       ___ftmul (ARG)
;!         ___ftpack
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftpack (ARG)
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___ftdiv
;!       ___ftadd (ARG)
;!         ___ftmul (ARG)
;!           ___ftpack
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftpack (ARG)
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftpack (ARG)
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___fttol
;!       ___ftadd (ARG)
;!         ___ftmul (ARG)
;!           ___ftpack
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftpack (ARG)
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftdiv (ARG)
;!         ___ftadd (ARG)
;!           ___ftmul (ARG)
;!             ___ftpack
;!             ___lwtoft (ARG)
;!               ___ftpack
;!           ___ftpack (ARG)
;!           ___lwtoft (ARG)
;!             ___ftpack
;!         ___ftpack (ARG)
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___ftmul (ARG)
;!         ___ftpack
;!         ___lwtoft (ARG)
;!           ___ftpack
;!       ___lwtoft (ARG)
;!         ___ftpack
;!     ___lwtoft
;!       ___ftpack
;!   _Button_response
;!     _Motor_num
;!     _Set_PWM
;!       ___awdiv
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
;!BANK1               50      D      31       6       61.3%
;!BITBANK1            50      0       0       5        0.0%
;!SFR1                 0      0       0       2        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!BANK0               50     4C      50       4      100.0%
;!BITBANK0            50      0       0       3        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR0              0      0       0       1        0.0%
;!COMMON               E      D       E       1      100.0%
;!BITCOMMON            E      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!DATA                 0      0      8F       8        0.0%
;!ABS                  0      0      8F       7        0.0%
;!NULL                 0      0       0       0        0.0%
;!STACK                0      0       0       2        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 52 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
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
;;		On exit  : 0/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       0       0
;;      Totals:         0       0       0
;;Total ram usage:        0 bytes
;; Hardware stack levels required when called:    7
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	52
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	52
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 1
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	56
	
l3426:	
;SC8F072_Pwm_Demo.c: 56: Init_System();
	fcall	_Init_System
	line	57
	
l3428:	
;SC8F072_Pwm_Demo.c: 57: Led_Gpio_Init();
	fcall	_Led_Gpio_Init
	line	58
	
l3430:	
;SC8F072_Pwm_Demo.c: 58: PWM_Init();
	fcall	_PWM_Init
	line	59
;SC8F072_Pwm_Demo.c: 59: while(1)
	
l657:	
	line	61
# 61 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	line	62
	
l3432:	
;SC8F072_Pwm_Demo.c: 62: Button_response();
	fcall	_Button_response
	line	63
	
l3434:	
;SC8F072_Pwm_Demo.c: 63: if(ADC_Flag)
	bsf	status, 5	;RP0=1, select bank1
	movf	((_ADC_Flag)^080h),w	;volatile
	btfsc	status,2
	goto	u2401
	goto	u2400
u2401:
	goto	l658
u2400:
	line	65
	
l3436:	
;SC8F072_Pwm_Demo.c: 64: {
;SC8F072_Pwm_Demo.c: 65: ADC_read();
	fcall	_ADC_read
	line	66
	
l658:	
	line	67
# 67 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	goto	l657
	global	start
	ljmp	start
	opt stack 0
	line	69
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_PWM_Init

;; *************** function _PWM_Init *****************
;; Defined at:
;;		line 129 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
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
	line	129
global __ptext1
__ptext1:	;psect for function _PWM_Init
psect	text1
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	129
	global	__size_of_PWM_Init
	__size_of_PWM_Init	equ	__end_of_PWM_Init-_PWM_Init
	
_PWM_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _PWM_Init: [wreg+status,2]
	line	131
	
l3296:	
;SC8F072_Pwm_Demo.c: 131: PWMCON1 = 0B11000000;
	movlw	low(0C0h)
	movwf	(22)	;volatile
	line	132
;SC8F072_Pwm_Demo.c: 132: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	133
;SC8F072_Pwm_Demo.c: 133: PWMTL = 0XFF;
	movlw	low(0FFh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(23)	;volatile
	line	134
;SC8F072_Pwm_Demo.c: 134: PWMT4L = 0XFF;
	movlw	low(0FFh)
	movwf	(28)	;volatile
	line	135
	
l3298:	
;SC8F072_Pwm_Demo.c: 135: PWMTH = 0X00;
	clrf	(24)	;volatile
	line	140
	
l3300:	
;SC8F072_Pwm_Demo.c: 140: PWMD0L = 0X00;
	clrf	(25)	;volatile
	line	143
	
l3302:	
;SC8F072_Pwm_Demo.c: 143: PWMD1L = 0X00;
	clrf	(26)	;volatile
	line	144
	
l3304:	
;SC8F072_Pwm_Demo.c: 144: PWMD01H = 0X00;
	clrf	(30)	;volatile
	line	147
	
l3306:	
;SC8F072_Pwm_Demo.c: 147: PWMD2L = 0X00;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(155)^080h	;volatile
	line	149
	
l3308:	
;SC8F072_Pwm_Demo.c: 149: PWMD23H = 0X00;
	clrf	(158)^080h	;volatile
	line	151
	
l3310:	
;SC8F072_Pwm_Demo.c: 151: PWMD4L = 0X00;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(27)	;volatile
	line	167
	
l3312:	
;SC8F072_Pwm_Demo.c: 167: PWMCON0 = 0X17;
	movlw	low(017h)
	movwf	(21)	;volatile
	line	168
;SC8F072_Pwm_Demo.c: 168: PWMCON2 =0X00;
	clrf	(29)	;volatile
	line	170
	
l667:	
	return
	opt stack 0
GLOBAL	__end_of_PWM_Init
	__end_of_PWM_Init:
	signat	_PWM_Init,89
	global	_Led_Gpio_Init

;; *************** function _Led_Gpio_Init *****************
;; Defined at:
;;		line 76 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	76
global __ptext2
__ptext2:	;psect for function _Led_Gpio_Init
psect	text2
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	76
	global	__size_of_Led_Gpio_Init
	__size_of_Led_Gpio_Init	equ	__end_of_Led_Gpio_Init-_Led_Gpio_Init
	
_Led_Gpio_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _Led_Gpio_Init: []
	line	78
	
l3294:	
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
	
l1369:	
	return
	opt stack 0
GLOBAL	__end_of_Led_Gpio_Init
	__end_of_Led_Gpio_Init:
	signat	_Led_Gpio_Init,89
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 79 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	79
global __ptext3
__ptext3:	;psect for function _Init_System
psect	text3
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	79
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 4
; Regs used in _Init_System: [wreg+status,2]
	line	81
	
l3246:	
# 81 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
	line	82
# 82 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text3
	line	83
	
l3248:	
;SC8F072_Pwm_Demo.c: 83: INTCON = 0;
	clrf	(11)	;volatile
	line	84
	
l3250:	
;SC8F072_Pwm_Demo.c: 84: OSCCON = 0X72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	85
	
l3252:	
;SC8F072_Pwm_Demo.c: 85: OPTION_REG = 0B00000100;
	movlw	low(04h)
	movwf	(1)	;volatile
	line	86
# 86 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text3
	line	88
;SC8F072_Pwm_Demo.c: 88: WPUA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(136)^080h	;volatile
	line	89
;SC8F072_Pwm_Demo.c: 89: WPUB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(8)	;volatile
	line	90
;SC8F072_Pwm_Demo.c: 90: WPDA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(135)^080h	;volatile
	line	91
;SC8F072_Pwm_Demo.c: 91: WPDB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(7)	;volatile
	line	92
;SC8F072_Pwm_Demo.c: 92: TRISA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(133)^080h	;volatile
	line	93
;SC8F072_Pwm_Demo.c: 93: TRISB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(5)	;volatile
	line	94
;SC8F072_Pwm_Demo.c: 94: PORTA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(134)^080h	;volatile
	line	95
;SC8F072_Pwm_Demo.c: 95: PORTB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(6)	;volatile
	line	97
	
l3254:	
;SC8F072_Pwm_Demo.c: 97: TMR0 = 6;
	movlw	low(06h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(129)^080h	;volatile
	line	98
	
l3256:	
;SC8F072_Pwm_Demo.c: 98: T0IF = 0;
	bcf	(90/8),(90)&7	;volatile
	line	99
	
l3258:	
;SC8F072_Pwm_Demo.c: 99: T0IE = 1;
	bsf	(93/8),(93)&7	;volatile
	line	100
	
l3260:	
;SC8F072_Pwm_Demo.c: 100: GIE = 1;
	bsf	(95/8),(95)&7	;volatile
	line	103
	
l3262:	
;SC8F072_Pwm_Demo.c: 103: PR2 = 249;
	movlw	low(0F9h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(17)	;volatile
	line	104
	
l3264:	
;SC8F072_Pwm_Demo.c: 104: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	105
	
l3266:	
;SC8F072_Pwm_Demo.c: 105: TMR2IE = 1;
	bsf	(113/8),(113)&7	;volatile
	line	106
	
l3268:	
;SC8F072_Pwm_Demo.c: 106: T2CON = 0B00000111;
	movlw	low(07h)
	movwf	(19)	;volatile
	line	110
	
l3270:	
;SC8F072_Pwm_Demo.c: 110: WPUB = 0B00100000;
	movlw	low(020h)
	movwf	(8)	;volatile
	line	111
	
l3272:	
;SC8F072_Pwm_Demo.c: 111: TRISB= 0B00100000;
	movlw	low(020h)
	movwf	(5)	;volatile
	line	112
	
l3274:	
;SC8F072_Pwm_Demo.c: 112: IOCB = 0B00100000;
	movlw	low(020h)
	movwf	(9)	;volatile
	line	113
	
l3276:	
;SC8F072_Pwm_Demo.c: 113: RBIE = 1;
	bsf	(91/8),(91)&7	;volatile
	line	115
	
l3278:	
;SC8F072_Pwm_Demo.c: 115: PORTB;
	movf	(6),w	;volatile
	line	118
	
l3280:	
;SC8F072_Pwm_Demo.c: 118: WPUA = 0B00100000;
	movlw	low(020h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(136)^080h	;volatile
	line	119
	
l3282:	
;SC8F072_Pwm_Demo.c: 119: TRISA= 0B00100000;
	movlw	low(020h)
	movwf	(133)^080h	;volatile
	line	120
	
l3284:	
;SC8F072_Pwm_Demo.c: 120: IOCA = 0B00100000;
	movlw	low(020h)
	movwf	(137)^080h	;volatile
	line	121
	
l3286:	
;SC8F072_Pwm_Demo.c: 121: RAIE = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(115/8),(115)&7	;volatile
	line	123
	
l3288:	
;SC8F072_Pwm_Demo.c: 123: RAIF = 0;
	bcf	(107/8),(107)&7	;volatile
	line	124
	
l3290:	
;SC8F072_Pwm_Demo.c: 124: PORTA;
	bsf	status, 5	;RP0=1, select bank1
	movf	(134)^080h,w	;volatile
	line	125
	
l3292:	
;SC8F072_Pwm_Demo.c: 125: INTCON = 0xE8;
	movlw	low(0E8h)
	movwf	(11)	;volatile
	line	127
	
l664:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
	global	_Button_response

;; *************** function _Button_response *****************
;; Defined at:
;;		line 317 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
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
;;      Temps:          0       1       0
;;      Totals:         0       1       0
;;Total ram usage:        1 bytes
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
	line	317
global __ptext4
__ptext4:	;psect for function _Button_response
psect	text4
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	317
	global	__size_of_Button_response
	__size_of_Button_response	equ	__end_of_Button_response-_Button_response
	
_Button_response:	
;incstack = 0
	opt	stack 2
; Regs used in _Button_response: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	319
	
l3314:	
;SC8F072_Pwm_Demo.c: 319: if (button_sflag)
	bsf	status, 5	;RP0=1, select bank1
	movf	((_button_sflag)^080h),w	;volatile
	btfsc	status,2
	goto	u2351
	goto	u2350
u2351:
	goto	l3340
u2350:
	line	321
	
l3316:	
;SC8F072_Pwm_Demo.c: 320: {
;SC8F072_Pwm_Demo.c: 321: TRISA = 0B00101000;
	movlw	low(028h)
	movwf	(133)^080h	;volatile
	line	322
;SC8F072_Pwm_Demo.c: 322: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_Button_response+0)+0),f
	u2577:
decfsz	(??_Button_response+0)+0,f
	goto	u2577
	nop2
opt asmopt_pop

	line	323
	
l3318:	
;SC8F072_Pwm_Demo.c: 323: button_sflag = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(_button_sflag)^080h	;volatile
	line	324
;SC8F072_Pwm_Demo.c: 324: switch (pwm_duty)
	goto	l3332
	line	327
	
l3320:	
;SC8F072_Pwm_Demo.c: 327: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	328
;SC8F072_Pwm_Demo.c: 328: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	329
;SC8F072_Pwm_Demo.c: 329: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	330
;SC8F072_Pwm_Demo.c: 330: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	331
;SC8F072_Pwm_Demo.c: 331: break;
	goto	l3334
	line	333
	
l3322:	
;SC8F072_Pwm_Demo.c: 333: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	334
;SC8F072_Pwm_Demo.c: 334: Set_PWM(1, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	335
;SC8F072_Pwm_Demo.c: 335: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	336
;SC8F072_Pwm_Demo.c: 336: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	337
;SC8F072_Pwm_Demo.c: 337: break;
	goto	l3334
	line	339
	
l3324:	
;SC8F072_Pwm_Demo.c: 339: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	340
;SC8F072_Pwm_Demo.c: 340: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	341
;SC8F072_Pwm_Demo.c: 341: Set_PWM(2, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	342
;SC8F072_Pwm_Demo.c: 342: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	343
;SC8F072_Pwm_Demo.c: 343: break;
	goto	l3334
	line	345
	
l3326:	
;SC8F072_Pwm_Demo.c: 345: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	346
;SC8F072_Pwm_Demo.c: 346: Set_PWM(1, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	347
;SC8F072_Pwm_Demo.c: 347: Set_PWM(2, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	348
;SC8F072_Pwm_Demo.c: 348: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	349
;SC8F072_Pwm_Demo.c: 349: break;
	goto	l3334
	line	351
	
l3328:	
;SC8F072_Pwm_Demo.c: 351: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	352
;SC8F072_Pwm_Demo.c: 352: Set_PWM(1, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	353
;SC8F072_Pwm_Demo.c: 353: Set_PWM(2, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	354
;SC8F072_Pwm_Demo.c: 354: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	360
;SC8F072_Pwm_Demo.c: 360: break;
	goto	l3334
	line	324
	
l3332:	
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w	;volatile
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
goto l3334
movlw high(S3576)
movwf pclath
	movlw low(S3576)
	addwf fsr,w
	movwf pc
psect	swtext1,local,class=CONST,delta=2
global __pswtext1
__pswtext1:
S3576:
	ljmp	l3320
	ljmp	l3322
	ljmp	l3324
	ljmp	l3326
	ljmp	l3328
psect	text4

	line	364
	
l3334:	
;SC8F072_Pwm_Demo.c: 364: Time_delay=2500;
	movlw	0C4h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_Time_delay)^080h	;volatile
	movlw	09h
	movwf	((_Time_delay)^080h)+1	;volatile
	line	365
	
l3336:	
;SC8F072_Pwm_Demo.c: 365: Motor_num();
	fcall	_Motor_num
	line	366
	
l3338:	
;SC8F072_Pwm_Demo.c: 366: pwm_duty = (pwm_duty + 1) % 5;
	movf	(_pwm_duty),w	;volatile
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
	movwf	(_pwm_duty)	;volatile
	line	367
;SC8F072_Pwm_Demo.c: 367: T_flag=1;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_T_flag)^080h	;volatile
	line	370
	
l3340:	
;SC8F072_Pwm_Demo.c: 369: }
;SC8F072_Pwm_Demo.c: 370: if (button_lflag)
	movf	((_button_lflag)^080h),w	;volatile
	btfsc	status,2
	goto	u2361
	goto	u2360
u2361:
	goto	l717
u2360:
	line	372
	
l3342:	
;SC8F072_Pwm_Demo.c: 371: {
;SC8F072_Pwm_Demo.c: 372: button_lflag = 0;
	clrf	(_button_lflag)^080h	;volatile
	line	373
	
l3344:	
;SC8F072_Pwm_Demo.c: 373: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	374
	
l3346:	
;SC8F072_Pwm_Demo.c: 374: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	375
	
l3348:	
;SC8F072_Pwm_Demo.c: 375: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	376
	
l3350:	
;SC8F072_Pwm_Demo.c: 376: Set_PWM(4, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	377
;SC8F072_Pwm_Demo.c: 377: pwm_duty =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_pwm_duty)	;volatile
	line	378
	
l3352:	
;SC8F072_Pwm_Demo.c: 378: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	379
	
l3354:	
;SC8F072_Pwm_Demo.c: 379: TRISB = 0B00111111;
	movlw	low(03Fh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(5)	;volatile
	line	380
;SC8F072_Pwm_Demo.c: 380: T_flag=0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(_T_flag)^080h	;volatile
	line	382
# 382 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
clrwdt ;# 
	line	383
# 383 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
stop ;# 
	line	384
# 384 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
	line	385
# 385 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
psect	text4
	line	387
	
l717:	
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
	
l3128:	
	clrf	(___awmod@sign)
	line	14
	
l3130:	
	btfss	(___awmod@dividend+1),7
	goto	u2171
	goto	u2170
u2171:
	goto	l3136
u2170:
	line	15
	
l3132:	
	comf	(___awmod@dividend),f
	comf	(___awmod@dividend+1),f
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	line	16
	
l3134:	
	clrf	(___awmod@sign)
	incf	(___awmod@sign),f
	line	18
	
l3136:	
	btfss	(___awmod@divisor+1),7
	goto	u2181
	goto	u2180
u2181:
	goto	l3140
u2180:
	line	19
	
l3138:	
	comf	(___awmod@divisor),f
	comf	(___awmod@divisor+1),f
	incf	(___awmod@divisor),f
	skipnz
	incf	(___awmod@divisor+1),f
	line	20
	
l3140:	
	movf	((___awmod@divisor)),w
iorwf	((___awmod@divisor+1)),w
	btfsc	status,2
	goto	u2191
	goto	u2190
u2191:
	goto	l3156
u2190:
	line	21
	
l3142:	
	clrf	(___awmod@counter)
	incf	(___awmod@counter),f
	line	22
	goto	l3146
	line	23
	
l3144:	
	clrc
	rlf	(___awmod@divisor),f
	rlf	(___awmod@divisor+1),f
	line	24
	incf	(___awmod@counter),f
	line	22
	
l3146:	
	btfss	(___awmod@divisor+1),(15)&7
	goto	u2201
	goto	u2200
u2201:
	goto	l3144
u2200:
	line	27
	
l3148:	
	movf	(___awmod@divisor+1),w
	subwf	(___awmod@dividend+1),w
	skipz
	goto	u2215
	movf	(___awmod@divisor),w
	subwf	(___awmod@dividend),w
u2215:
	skipc
	goto	u2211
	goto	u2210
u2211:
	goto	l3152
u2210:
	line	28
	
l3150:	
	movf	(___awmod@divisor),w
	subwf	(___awmod@dividend),f
	movf	(___awmod@divisor+1),w
	skipc
	decf	(___awmod@dividend+1),f
	subwf	(___awmod@dividend+1),f
	line	29
	
l3152:	
	clrc
	rrf	(___awmod@divisor+1),f
	rrf	(___awmod@divisor),f
	line	30
	
l3154:	
	decfsz	(___awmod@counter),f
	goto	u2221
	goto	u2220
u2221:
	goto	l3148
u2220:
	line	32
	
l3156:	
	movf	((___awmod@sign)),w
	btfsc	status,2
	goto	u2231
	goto	u2230
u2231:
	goto	l3160
u2230:
	line	33
	
l3158:	
	comf	(___awmod@dividend),f
	comf	(___awmod@dividend+1),f
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	line	34
	
l3160:	
	movf	(___awmod@dividend+1),w
	movwf	(?___awmod+1)
	movf	(___awmod@dividend),w
	movwf	(?___awmod)
	line	35
	
l1567:	
	return
	opt stack 0
GLOBAL	__end_of___awmod
	__end_of___awmod:
	signat	___awmod,8314
	global	_Set_PWM

;; *************** function _Set_PWM *****************
;; Defined at:
;;		line 180 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;  channel         1    wreg     unsigned char 
;;  duty            1   14[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  channel         1   15[BANK0 ] unsigned char 
;;  pulse_width     1   16[BANK0 ] unsigned char 
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
;;      Locals:         0       2       0
;;      Temps:          0       0       0
;;      Totals:         0       3       0
;;Total ram usage:        3 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___awdiv
;;		___wmul
;; This function is called by:
;;		_Button_response
;; This function uses a non-reentrant model
;;
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	180
global __ptext6
__ptext6:	;psect for function _Set_PWM
psect	text6
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	180
	global	__size_of_Set_PWM
	__size_of_Set_PWM	equ	__end_of_Set_PWM-_Set_PWM
	
_Set_PWM:	
;incstack = 0
	opt	stack 2
; Regs used in _Set_PWM: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;Set_PWM@channel stored from wreg
	movwf	(Set_PWM@channel)
	line	182
	
l2938:	
;SC8F072_Pwm_Demo.c: 182: unsigned char pulse_width = (unsigned char)((duty * 255) / 100);
	movlw	064h
	movwf	(___awdiv@divisor)
	clrf	(___awdiv@divisor+1)
	movf	(Set_PWM@duty),w
	movwf	(___wmul@multiplier)
	clrf	(___wmul@multiplier+1)
	movlw	0FFh
	movwf	(___wmul@multiplicand)
	clrf	(___wmul@multiplicand+1)
	fcall	___wmul
	movf	(1+(?___wmul)),w
	movwf	(___awdiv@dividend+1)
	movf	(0+(?___wmul)),w
	movwf	(___awdiv@dividend)
	fcall	___awdiv
	movf	(0+(?___awdiv)),w
	movwf	(Set_PWM@pulse_width)
	line	183
;SC8F072_Pwm_Demo.c: 183: switch (channel)
	goto	l2952
	line	186
	
l2940:	
;SC8F072_Pwm_Demo.c: 186: PWMD0L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(25)	;volatile
	line	188
;SC8F072_Pwm_Demo.c: 188: break;
	goto	l678
	line	190
	
l2942:	
;SC8F072_Pwm_Demo.c: 190: PWMD1L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(26)	;volatile
	line	192
;SC8F072_Pwm_Demo.c: 192: break;
	goto	l678
	line	194
	
l2944:	
;SC8F072_Pwm_Demo.c: 194: PWMD2L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(155)^080h	;volatile
	line	196
;SC8F072_Pwm_Demo.c: 196: break;
	goto	l678
	line	198
	
l2946:	
;SC8F072_Pwm_Demo.c: 198: PWMD3L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(156)^080h	;volatile
	line	200
;SC8F072_Pwm_Demo.c: 200: break;
	goto	l678
	line	202
	
l2948:	
;SC8F072_Pwm_Demo.c: 202: PWMD4L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(27)	;volatile
	line	204
;SC8F072_Pwm_Demo.c: 204: break;
	goto	l678
	line	183
	
l2952:	
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
goto l678
movlw high(S3578)
movwf pclath
	movlw low(S3578)
	addwf fsr,w
	movwf pc
psect	swtext2,local,class=CONST,delta=2
global __pswtext2
__pswtext2:
S3578:
	ljmp	l2940
	ljmp	l2942
	ljmp	l2944
	ljmp	l2946
	ljmp	l2948
psect	text6

	line	208
	
l678:	
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
	
l2706:	
	clrf	(___wmul@product)
	clrf	(___wmul@product+1)
	line	45
	
l2708:	
	btfss	(___wmul@multiplier),(0)&7
	goto	u1371
	goto	u1370
u1371:
	goto	l2712
u1370:
	line	46
	
l2710:	
	movf	(___wmul@multiplicand),w
	addwf	(___wmul@product),f
	skipnc
	incf	(___wmul@product+1),f
	movf	(___wmul@multiplicand+1),w
	addwf	(___wmul@product+1),f
	line	47
	
l2712:	
	clrc
	rlf	(___wmul@multiplicand),f
	rlf	(___wmul@multiplicand+1),f
	line	48
	
l2714:	
	clrc
	rrf	(___wmul@multiplier+1),f
	rrf	(___wmul@multiplier),f
	line	49
	
l2716:	
	movf	((___wmul@multiplier)),w
iorwf	((___wmul@multiplier+1)),w
	btfss	status,2
	goto	u1381
	goto	u1380
u1381:
	goto	l2708
u1380:
	line	52
	
l2718:	
	movf	(___wmul@product+1),w
	movwf	(?___wmul+1)
	movf	(___wmul@product),w
	movwf	(?___wmul)
	line	53
	
l1424:	
	return
	opt stack 0
GLOBAL	__end_of___wmul
	__end_of___wmul:
	signat	___wmul,8314
	global	___awdiv

;; *************** function ___awdiv *****************
;; Defined at:
;;		line 6 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awdiv.c"
;; Parameters:    Size  Location     Type
;;  divisor         2    6[BANK0 ] int 
;;  dividend        2    8[BANK0 ] int 
;; Auto vars:     Size  Location     Type
;;  quotient        2   12[BANK0 ] int 
;;  sign            1   11[BANK0 ] unsigned char 
;;  counter         1   10[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  2    6[BANK0 ] int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       4       0
;;      Locals:         0       4       0
;;      Temps:          0       0       0
;;      Totals:         0       8       0
;;Total ram usage:        8 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Set_PWM
;; This function uses a non-reentrant model
;;
psect	text8,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awdiv.c"
	line	6
global __ptext8
__ptext8:	;psect for function ___awdiv
psect	text8
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awdiv.c"
	line	6
	global	__size_of___awdiv
	__size_of___awdiv	equ	__end_of___awdiv-___awdiv
	
___awdiv:	
;incstack = 0
	opt	stack 2
; Regs used in ___awdiv: [wreg+status,2+status,0]
	line	14
	
l2722:	
	clrf	(___awdiv@sign)
	line	15
	
l2724:	
	btfss	(___awdiv@divisor+1),7
	goto	u1391
	goto	u1390
u1391:
	goto	l2730
u1390:
	line	16
	
l2726:	
	comf	(___awdiv@divisor),f
	comf	(___awdiv@divisor+1),f
	incf	(___awdiv@divisor),f
	skipnz
	incf	(___awdiv@divisor+1),f
	line	17
	
l2728:	
	clrf	(___awdiv@sign)
	incf	(___awdiv@sign),f
	line	19
	
l2730:	
	btfss	(___awdiv@dividend+1),7
	goto	u1401
	goto	u1400
u1401:
	goto	l2736
u1400:
	line	20
	
l2732:	
	comf	(___awdiv@dividend),f
	comf	(___awdiv@dividend+1),f
	incf	(___awdiv@dividend),f
	skipnz
	incf	(___awdiv@dividend+1),f
	line	21
	
l2734:	
	movlw	low(01h)
	xorwf	(___awdiv@sign),f
	line	23
	
l2736:	
	clrf	(___awdiv@quotient)
	clrf	(___awdiv@quotient+1)
	line	24
	
l2738:	
	movf	((___awdiv@divisor)),w
iorwf	((___awdiv@divisor+1)),w
	btfsc	status,2
	goto	u1411
	goto	u1410
u1411:
	goto	l2758
u1410:
	line	25
	
l2740:	
	clrf	(___awdiv@counter)
	incf	(___awdiv@counter),f
	line	26
	goto	l2744
	line	27
	
l2742:	
	clrc
	rlf	(___awdiv@divisor),f
	rlf	(___awdiv@divisor+1),f
	line	28
	incf	(___awdiv@counter),f
	line	26
	
l2744:	
	btfss	(___awdiv@divisor+1),(15)&7
	goto	u1421
	goto	u1420
u1421:
	goto	l2742
u1420:
	line	31
	
l2746:	
	clrc
	rlf	(___awdiv@quotient),f
	rlf	(___awdiv@quotient+1),f
	line	32
	
l2748:	
	movf	(___awdiv@divisor+1),w
	subwf	(___awdiv@dividend+1),w
	skipz
	goto	u1435
	movf	(___awdiv@divisor),w
	subwf	(___awdiv@dividend),w
u1435:
	skipc
	goto	u1431
	goto	u1430
u1431:
	goto	l2754
u1430:
	line	33
	
l2750:	
	movf	(___awdiv@divisor),w
	subwf	(___awdiv@dividend),f
	movf	(___awdiv@divisor+1),w
	skipc
	decf	(___awdiv@dividend+1),f
	subwf	(___awdiv@dividend+1),f
	line	34
	
l2752:	
	bsf	(___awdiv@quotient)+(0/8),(0)&7
	line	36
	
l2754:	
	clrc
	rrf	(___awdiv@divisor+1),f
	rrf	(___awdiv@divisor),f
	line	37
	
l2756:	
	decfsz	(___awdiv@counter),f
	goto	u1441
	goto	u1440
u1441:
	goto	l2746
u1440:
	line	39
	
l2758:	
	movf	((___awdiv@sign)),w
	btfsc	status,2
	goto	u1451
	goto	u1450
u1451:
	goto	l2762
u1450:
	line	40
	
l2760:	
	comf	(___awdiv@quotient),f
	comf	(___awdiv@quotient+1),f
	incf	(___awdiv@quotient),f
	skipnz
	incf	(___awdiv@quotient+1),f
	line	41
	
l2762:	
	movf	(___awdiv@quotient+1),w
	movwf	(?___awdiv+1)
	movf	(___awdiv@quotient),w
	movwf	(?___awdiv)
	line	42
	
l1554:	
	return
	opt stack 0
GLOBAL	__end_of___awdiv
	__end_of___awdiv:
	signat	___awdiv,8314
	global	_Motor_num

;; *************** function _Motor_num *****************
;; Defined at:
;;		line 39 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	39
global __ptext9
__ptext9:	;psect for function _Motor_num
psect	text9
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	39
	global	__size_of_Motor_num
	__size_of_Motor_num	equ	__end_of_Motor_num-_Motor_num
	
_Motor_num:	
;incstack = 0
	opt	stack 3
; Regs used in _Motor_num: [wreg+status,2+status,0]
	line	41
	
l3040:	
;LED_188.c: 41: hundreds =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_hundreds)	;volatile
	line	42
;LED_188.c: 42: tens = 0;
	clrf	(_tens)	;volatile
	line	43
	
l3042:	
;LED_188.c: 43: unit = (unsigned char)(pwm_duty+1) ;
	movf	(_pwm_duty),w	;volatile
	addlw	01h
	movwf	(_unit)	;volatile
	line	44
	
l1362:	
	return
	opt stack 0
GLOBAL	__end_of_Motor_num
	__end_of_Motor_num:
	signat	_Motor_num,89
	global	_ADC_read

;; *************** function _ADC_read *****************
;; Defined at:
;;		line 299 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  power_temp      4   72[BANK0 ] volatile unsigned long 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/100
;;		On exit  : 100/100
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       4       0
;;      Temps:          0       1       0
;;      Totals:         0       5       0
;;Total ram usage:        5 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    6
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
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	299
global __ptext10
__ptext10:	;psect for function _ADC_read
psect	text10
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	299
	global	__size_of_ADC_read
	__size_of_ADC_read	equ	__end_of_ADC_read-_ADC_read
	
_ADC_read:	
;incstack = 0
	opt	stack 1
; Regs used in _ADC_read: [wreg+status,2+status,0+pclath+cstack]
	line	301
	
l3360:	
;SC8F072_Pwm_Demo.c: 301: test_adc = ADC_Sample(31, 0);
	bcf	status, 5	;RP0=0, select bank0
	clrf	(ADC_Sample@adldo)
	movlw	low(01Fh)
	fcall	_ADC_Sample
	movwf	(_test_adc)^080h	;volatile
	line	302
	
l3362:	
;SC8F072_Pwm_Demo.c: 302: if (0xA5 == test_adc)
		movlw	165
	xorwf	((_test_adc)^080h),w	;volatile
	btfss	status,2
	goto	u2371
	goto	u2370
u2371:
	goto	l3370
u2370:
	line	305
	
l3364:	
;SC8F072_Pwm_Demo.c: 303: {
;SC8F072_Pwm_Demo.c: 304: volatile unsigned long power_temp;
;SC8F072_Pwm_Demo.c: 305: power_temp = (unsigned long)(((4096UL*1.2*1000))/adresult);
	movlw	0x0
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___ftdiv@f1)
	movlw	0x96
	movwf	(___ftdiv@f1+1)
	movlw	0x4a
	movwf	(___ftdiv@f1+2)
	bsf	status, 5	;RP0=1, select bank1
	movf	(_adresult+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___lwtoft@c+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(_adresult)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
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

	line	306
	
l3366:	
;SC8F072_Pwm_Demo.c: 306: power_ad = (unsigned int)(power_temp);
	movf	(ADC_read@power_temp+1),w	;volatile
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_power_ad+1)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	(ADC_read@power_temp),w	;volatile
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_power_ad)^080h	;volatile
	line	307
	
l3368:	
;SC8F072_Pwm_Demo.c: 307: power_percent = (unsigned char)((power_ad-(1000UL*2.8))/(10UL*1.4));
	movf	(_power_ad+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___lwtoft@c+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(_power_ad)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
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
	line	308
;SC8F072_Pwm_Demo.c: 308: }
	goto	l3374
	line	311
	
l3370:	
;SC8F072_Pwm_Demo.c: 309: else
;SC8F072_Pwm_Demo.c: 310: {
;SC8F072_Pwm_Demo.c: 311: ADCON0 = 0;
	clrf	(149)^080h	;volatile
	line	312
;SC8F072_Pwm_Demo.c: 312: ADCON1 = 0;
	clrf	(150)^080h	;volatile
	line	313
	
l3372:	
;SC8F072_Pwm_Demo.c: 313: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_ADC_read+0)+0),f
	u2587:
decfsz	(??_ADC_read+0)+0,f
	goto	u2587
	nop2
opt asmopt_pop

	line	315
	
l3374:	
;SC8F072_Pwm_Demo.c: 314: }
;SC8F072_Pwm_Demo.c: 315: ADC_Flag=0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(_ADC_Flag)^080h	;volatile
	line	316
	
l704:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_read
	__end_of_ADC_read:
	signat	_ADC_read,89
	global	___ftdiv

;; *************** function ___ftdiv *****************
;; Defined at:
;;		line 56 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
;; Parameters:    Size  Location     Type
;;  f2              3   38[BANK0 ] float 
;;  f1              3   41[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  f3              3   48[BANK0 ] float 
;;  sign            1   52[BANK0 ] unsigned char 
;;  exp             1   51[BANK0 ] unsigned char 
;;  cntr            1   47[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   38[BANK0 ] float 
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
psect	text11,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
	line	56
global __ptext11
__ptext11:	;psect for function ___ftdiv
psect	text11
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
	line	56
	global	__size_of___ftdiv
	__size_of___ftdiv	equ	__end_of___ftdiv-___ftdiv
	
___ftdiv:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftdiv: [wreg+status,2+status,0+pclath+cstack]
	line	63
	
l3164:	
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
	goto	u2241
	goto	u2240
u2241:
	goto	l3168
u2240:
	line	64
	
l3166:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l1631
	line	65
	
l3168:	
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
	goto	u2251
	goto	u2250
u2251:
	goto	l1632
u2250:
	line	66
	
l3170:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l1631
	
l1632:	
	line	67
	clrf	(___ftdiv@f3)
	clrf	(___ftdiv@f3+1)
	clrf	(___ftdiv@f3+2)
	line	68
	
l3172:	
	movlw	low(089h)
	addwf	(___ftdiv@sign),w
	movwf	(??___ftdiv+0)+0
	movf	0+(??___ftdiv+0)+0,w
	subwf	(___ftdiv@exp),f
	line	69
	
l3174:	
	movf	0+(___ftdiv@f1)+02h,w
	movwf	(___ftdiv@sign)
	line	70
	
l3176:	
	movf	0+(___ftdiv@f2)+02h,w
	xorwf	(___ftdiv@sign),f
	line	71
	
l3178:	
	movlw	low(080h)
	andwf	(___ftdiv@sign),f
	line	72
	
l3180:	
	bsf	(___ftdiv@f1)+(15/8),(15)&7
	line	73
	
l3182:	
	movlw	0FFh
	andwf	(___ftdiv@f1),f
	movlw	0FFh
	andwf	(___ftdiv@f1+1),f
	movlw	0
	andwf	(___ftdiv@f1+2),f
	line	74
	
l3184:	
	bsf	(___ftdiv@f2)+(15/8),(15)&7
	line	75
	
l3186:	
	movlw	0FFh
	andwf	(___ftdiv@f2),f
	movlw	0FFh
	andwf	(___ftdiv@f2+1),f
	movlw	0
	andwf	(___ftdiv@f2+2),f
	line	76
	
l3188:	
	movlw	low(018h)
	movwf	(___ftdiv@cntr)
	line	78
	
l3190:	
	clrc
	rlf	(___ftdiv@f3),f
	rlf	(___ftdiv@f3+1),f
	rlf	(___ftdiv@f3+2),f
	line	79
	movf	(___ftdiv@f2+2),w
	subwf	(___ftdiv@f1+2),w
	skipz
	goto	u2265
	movf	(___ftdiv@f2+1),w
	subwf	(___ftdiv@f1+1),w
	skipz
	goto	u2265
	movf	(___ftdiv@f2),w
	subwf	(___ftdiv@f1),w
u2265:
	skipc
	goto	u2261
	goto	u2260
u2261:
	goto	l3196
u2260:
	line	80
	
l3192:	
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
	
l3194:	
	bsf	(___ftdiv@f3)+(0/8),(0)&7
	line	83
	
l3196:	
	clrc
	rlf	(___ftdiv@f1),f
	rlf	(___ftdiv@f1+1),f
	rlf	(___ftdiv@f1+2),f
	line	84
	
l3198:	
	decfsz	(___ftdiv@cntr),f
	goto	u2271
	goto	u2270
u2271:
	goto	l3190
u2270:
	line	85
	
l3200:	
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
	
l1631:	
	return
	opt stack 0
GLOBAL	__end_of___ftdiv
	__end_of___ftdiv:
	signat	___ftdiv,8315
	global	_ADC_Sample

;; *************** function _ADC_Sample *****************
;; Defined at:
;;		line 228 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;  adch            1    wreg     unsigned char 
;;  adldo           1   66[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  adch            1    1[BANK1 ] unsigned char 
;;  j               1    0[BANK1 ] unsigned char 
;;  adsum           4    7[BANK1 ] volatile unsigned long 
;;  ad_temp         2   11[BANK1 ] volatile unsigned int 
;;  admax           2    5[BANK1 ] volatile unsigned int 
;;  admin           2    3[BANK1 ] volatile unsigned int 
;;  i               1    2[BANK1 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      unsigned char 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/100
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       1       0
;;      Locals:         0       0      13
;;      Temps:          0       4       0
;;      Totals:         0       5      13
;;Total ram usage:       18 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    5
;; This function calls:
;;		___ftadd
;;		___ftmul
;;		___fttol
;;		___lwtoft
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text12,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	228
global __ptext12
__ptext12:	;psect for function _ADC_Sample
psect	text12
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	228
	global	__size_of_ADC_Sample
	__size_of_ADC_Sample	equ	__end_of_ADC_Sample-_ADC_Sample
	
_ADC_Sample:	
;incstack = 0
	opt	stack 1
; Regs used in _ADC_Sample: [wreg+status,2+status,0+pclath+cstack]
;ADC_Sample@adch stored from wreg
	bsf	status, 5	;RP0=1, select bank1
	movwf	(ADC_Sample@adch)^080h
	line	231
	
l2958:	
;SC8F072_Pwm_Demo.c: 231: volatile unsigned long adsum = 0;
	clrf	(ADC_Sample@adsum)^080h	;volatile
	clrf	(ADC_Sample@adsum+1)^080h	;volatile
	clrf	(ADC_Sample@adsum+2)^080h	;volatile
	clrf	(ADC_Sample@adsum+3)^080h	;volatile
	line	232
	
l2960:	
;SC8F072_Pwm_Demo.c: 232: volatile unsigned int admin = 0, admax = 0;
	clrf	(ADC_Sample@admin)^080h	;volatile
	clrf	(ADC_Sample@admin+1)^080h	;volatile
	clrf	(ADC_Sample@admax)^080h	;volatile
	clrf	(ADC_Sample@admax+1)^080h	;volatile
	line	233
;SC8F072_Pwm_Demo.c: 233: volatile unsigned int ad_temp = 0;
	clrf	(ADC_Sample@ad_temp)^080h	;volatile
	clrf	(ADC_Sample@ad_temp+1)^080h	;volatile
	line	235
	
l2962:	
;SC8F072_Pwm_Demo.c: 235: if ((!LDO_EN) && (adldo & 0x04) )
	btfsc	(1202/8)^080h,(1202)&7	;volatile
	goto	u1821
	goto	u1820
u1821:
	goto	l2968
u1820:
	
l2964:	
	bcf	status, 5	;RP0=0, select bank0
	btfss	(ADC_Sample@adldo),(2)&7
	goto	u1831
	goto	u1830
u1831:
	goto	l2968
u1830:
	line	238
	
l2966:	
;SC8F072_Pwm_Demo.c: 236: {
;SC8F072_Pwm_Demo.c: 238: ADCON1 = adldo;
	movf	(ADC_Sample@adldo),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(150)^080h	;volatile
	line	239
;SC8F072_Pwm_Demo.c: 239: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_ADC_Sample+0)+0),f
	u2597:
decfsz	(??_ADC_Sample+0)+0,f
	goto	u2597
	nop2
opt asmopt_pop

	line	240
;SC8F072_Pwm_Demo.c: 240: }
	goto	l2970
	line	242
	
l2968:	
;SC8F072_Pwm_Demo.c: 241: else
;SC8F072_Pwm_Demo.c: 242: ADCON1 = adldo;
	bcf	status, 5	;RP0=0, select bank0
	movf	(ADC_Sample@adldo),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(150)^080h	;volatile
	line	243
	
l2970:	
;SC8F072_Pwm_Demo.c: 243: if(adch & 0x10)
	bsf	status, 5	;RP0=1, select bank1
	btfss	(ADC_Sample@adch)^080h,(4)&7
	goto	u1841
	goto	u1840
u1841:
	goto	l2976
u1840:
	line	245
	
l2972:	
;SC8F072_Pwm_Demo.c: 244: {
;SC8F072_Pwm_Demo.c: 245: CHS4 = 1;
	bsf	(1206/8)^080h,(1206)&7	;volatile
	line	246
	
l2974:	
;SC8F072_Pwm_Demo.c: 246: adch &= 0x0f;
	movlw	low(0Fh)
	andwf	(ADC_Sample@adch)^080h,f
	line	248
	
l2976:	
	line	249
	
l2978:	
;SC8F072_Pwm_Demo.c: 249: for (i = 0; i < 10; i++)
	clrf	(ADC_Sample@i)^080h
	line	251
	
l2984:	
;SC8F072_Pwm_Demo.c: 250: {
;SC8F072_Pwm_Demo.c: 251: ADCON0 = (unsigned char)(0X41 | (adch << 2));
	movf	(ADC_Sample@adch)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(??_ADC_Sample+0)+0
	movlw	(02h)-1
u1855:
	clrc
	rlf	(??_ADC_Sample+0)+0,f
	addlw	-1
	skipz
	goto	u1855
	clrc
	rlf	(??_ADC_Sample+0)+0,w
	iorlw	041h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(149)^080h	;volatile
	line	252
# 252 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
	line	253
# 253 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
	line	254
# 254 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
	line	255
# 255 "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
nop ;# 
psect	text12
	line	256
	
l2986:	
;SC8F072_Pwm_Demo.c: 256: GODONE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1193/8)^080h,(1193)&7	;volatile
	line	257
	
l2988:	
;SC8F072_Pwm_Demo.c: 257: unsigned char j = 0;
	clrf	(ADC_Sample@j)^080h
	line	258
;SC8F072_Pwm_Demo.c: 258: while (GODONE)
	goto	l686
	
l687:	
	line	260
;SC8F072_Pwm_Demo.c: 259: {
;SC8F072_Pwm_Demo.c: 260: _delay((unsigned long)((2)*(16000000/4000000.0)));
		opt asmopt_push
	opt asmopt_off
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	opt asmopt_pop

	line	261
;SC8F072_Pwm_Demo.c: 261: if (0 == (--j))
	bsf	status, 5	;RP0=1, select bank1
	decfsz	(ADC_Sample@j)^080h,f
	goto	u1861
	goto	u1860
u1861:
	goto	l686
u1860:
	line	262
	
l2990:	
;SC8F072_Pwm_Demo.c: 262: return 0;
	movlw	low(0)
	goto	l689
	line	263
	
l686:	
	line	258
	btfsc	(1193/8)^080h,(1193)&7	;volatile
	goto	u1871
	goto	u1870
u1871:
	goto	l687
u1870:
	line	265
	
l2994:	
;SC8F072_Pwm_Demo.c: 263: }
;SC8F072_Pwm_Demo.c: 265: ad_temp = (unsigned int)((ADRESH << 4) + (ADRESL >> 4));
	movf	(153)^080h,w	;volatile
	movwf	(ADC_Sample@ad_temp)^080h	;volatile
	clrf	(ADC_Sample@ad_temp+1)^080h	;volatile
	swapf	(ADC_Sample@ad_temp)^080h,f	;volatile
	swapf	(ADC_Sample@ad_temp+1)^080h,f	;volatile
	movlw	0f0h
	andwf	(ADC_Sample@ad_temp+1)^080h,f	;volatile
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	andlw	0fh
	iorwf	(ADC_Sample@ad_temp+1)^080h,f	;volatile
	movlw	0f0h
	andwf	(ADC_Sample@ad_temp)^080h,f	;volatile
	
l2996:	
	swapf	(152)^080h,w	;volatile
	andlw	(0ffh shr 4) & 0ffh
	addwf	(ADC_Sample@ad_temp)^080h,f	;volatile
	skipnc
	incf	(ADC_Sample@ad_temp+1)^080h,f	;volatile
	line	267
	
l2998:	
;SC8F072_Pwm_Demo.c: 267: if (0 == admax)
	movf	((ADC_Sample@admax)^080h),w	;volatile
iorwf	((ADC_Sample@admax+1)^080h),w	;volatile
	btfss	status,2
	goto	u1881
	goto	u1880
u1881:
	goto	l3002
u1880:
	line	269
	
l3000:	
;SC8F072_Pwm_Demo.c: 268: {
;SC8F072_Pwm_Demo.c: 269: admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	movwf	(ADC_Sample@admax+1)^080h	;volatile
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	movwf	(ADC_Sample@admax)^080h	;volatile
	line	270
;SC8F072_Pwm_Demo.c: 270: admin = ad_temp;
	movf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	movwf	(ADC_Sample@admin+1)^080h	;volatile
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	movwf	(ADC_Sample@admin)^080h	;volatile
	line	271
;SC8F072_Pwm_Demo.c: 271: }
	goto	l692
	line	272
	
l3002:	
;SC8F072_Pwm_Demo.c: 272: else if (ad_temp > admax)admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	subwf	(ADC_Sample@admax+1)^080h,w	;volatile
	skipz
	goto	u1895
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	subwf	(ADC_Sample@admax)^080h,w	;volatile
u1895:
	skipnc
	goto	u1891
	goto	u1890
u1891:
	goto	l3006
u1890:
	
l3004:	
	movf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	movwf	(ADC_Sample@admax+1)^080h	;volatile
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	movwf	(ADC_Sample@admax)^080h	;volatile
	goto	l692
	line	274
	
l3006:	
;SC8F072_Pwm_Demo.c: 274: else if (ad_temp < admin)admin = ad_temp;
	movf	(ADC_Sample@admin+1)^080h,w	;volatile
	subwf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	skipz
	goto	u1905
	movf	(ADC_Sample@admin)^080h,w	;volatile
	subwf	(ADC_Sample@ad_temp)^080h,w	;volatile
u1905:
	skipnc
	goto	u1901
	goto	u1900
u1901:
	goto	l692
u1900:
	
l3008:	
	movf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	movwf	(ADC_Sample@admin+1)^080h	;volatile
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	movwf	(ADC_Sample@admin)^080h	;volatile
	line	275
	
l692:	
;SC8F072_Pwm_Demo.c: 275: adsum += ad_temp;
	movf	(ADC_Sample@ad_temp)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@ad_temp+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	addwf	(ADC_Sample@adsum)^080h,f	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	1+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u1911
	bsf	status, 5	;RP0=1, select bank1
	addwf	(ADC_Sample@adsum+1)^080h,f	;volatile
u1911:
	bcf	status, 5	;RP0=0, select bank0
	movf	2+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u1912
	bsf	status, 5	;RP0=1, select bank1
	addwf	(ADC_Sample@adsum+2)^080h,f	;volatile
u1912:
	bcf	status, 5	;RP0=0, select bank0
	movf	3+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u1913
	bsf	status, 5	;RP0=1, select bank1
	addwf	(ADC_Sample@adsum+3)^080h,f	;volatile
u1913:
	bcf	status, 5	;RP0=0, select bank0
	bsf	status, 5	;RP0=1, select bank1

	line	249
	
l3010:	
	incf	(ADC_Sample@i)^080h,f
	
l3012:	
	movlw	low(0Ah)
	subwf	(ADC_Sample@i)^080h,w
	skipc
	goto	u1921
	goto	u1920
u1921:
	goto	l2984
u1920:
	line	277
	
l3014:	
;SC8F072_Pwm_Demo.c: 276: }
;SC8F072_Pwm_Demo.c: 277: adsum -= admax;
	movf	(ADC_Sample@admax)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@admax+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum)^080h,f	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	1+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	1+(??_ADC_Sample+0)+0,w
	goto	u1935
	goto	u1936
u1935:
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+1)^080h,f	;volatile
u1936:
	bcf	status, 5	;RP0=0, select bank0
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u1937
	goto	u1938
u1937:
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+2)^080h,f	;volatile
u1938:
	bcf	status, 5	;RP0=0, select bank0
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u1939
	goto	u1930
u1939:
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+3)^080h,f	;volatile
u1930:
	bcf	status, 5	;RP0=0, select bank0
	bsf	status, 5	;RP0=1, select bank1

	line	278
;SC8F072_Pwm_Demo.c: 278: if (adsum >= admin)
	movf	(ADC_Sample@admin)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@admin+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	3+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+3)^080h,w	;volatile
	skipz
	goto	u1945
	bcf	status, 5	;RP0=0, select bank0
	movf	2+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+2)^080h,w	;volatile
	skipz
	goto	u1945
	bcf	status, 5	;RP0=0, select bank0
	movf	1+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+1)^080h,w	;volatile
	skipz
	goto	u1945
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum)^080h,w	;volatile
u1945:
	skipc
	goto	u1941
	goto	u1940
u1941:
	goto	l696
u1940:
	line	279
	
l3016:	
;SC8F072_Pwm_Demo.c: 279: adsum -= admin;
	movf	(ADC_Sample@admin)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@admin+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum)^080h,f	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	1+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	1+(??_ADC_Sample+0)+0,w
	goto	u1955
	goto	u1956
u1955:
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+1)^080h,f	;volatile
u1956:
	bcf	status, 5	;RP0=0, select bank0
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u1957
	goto	u1958
u1957:
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+2)^080h,f	;volatile
u1958:
	bcf	status, 5	;RP0=0, select bank0
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u1959
	goto	u1950
u1959:
	bsf	status, 5	;RP0=1, select bank1
	subwf	(ADC_Sample@adsum+3)^080h,f	;volatile
u1950:
	bcf	status, 5	;RP0=0, select bank0
	bsf	status, 5	;RP0=1, select bank1

	goto	l3018
	line	280
	
l696:	
	line	281
;SC8F072_Pwm_Demo.c: 280: else
;SC8F072_Pwm_Demo.c: 281: adsum = 0;
	clrf	(ADC_Sample@adsum)^080h	;volatile
	clrf	(ADC_Sample@adsum+1)^080h	;volatile
	clrf	(ADC_Sample@adsum+2)^080h	;volatile
	clrf	(ADC_Sample@adsum+3)^080h	;volatile
	line	283
	
l3018:	
;SC8F072_Pwm_Demo.c: 283: if (adc_last)
	movf	((_adc_last)^080h),w
iorwf	((_adc_last+1)^080h),w
	btfsc	status,2
	goto	u1961
	goto	u1960
u1961:
	goto	l3026
u1960:
	line	285
	
l3020:	
;SC8F072_Pwm_Demo.c: 284: {
;SC8F072_Pwm_Demo.c: 285: adresult = adsum>>3;
	movf	(ADC_Sample@adsum)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(??_ADC_Sample+0)+0
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@adsum+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@adsum+2)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+2)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@adsum+3)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+3)
	movlw	03h
u1975:
	clrc
	rrf	(??_ADC_Sample+0)+3,f
	rrf	(??_ADC_Sample+0)+2,f
	rrf	(??_ADC_Sample+0)+1,f
	rrf	(??_ADC_Sample+0)+0,f
u1970:
	addlw	-1
	skipz
	goto	u1975
	movf	1+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult+1)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult)^080h	;volatile
	line	286
	
l3022:	
;SC8F072_Pwm_Demo.c: 286: adresult = (int)(0.3*adresult + 0.7*adc_last);
	movf	(_adresult+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___lwtoft@c+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(_adresult)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___lwtoft@c)
	fcall	___lwtoft
	movf	(0+(?___lwtoft)),w
	movwf	(___ftmul@f2)
	movf	(1+(?___lwtoft)),w
	movwf	(___ftmul@f2+1)
	movf	(2+(?___lwtoft)),w
	movwf	(___ftmul@f2+2)
	movlw	0x9a
	movwf	(___ftmul@f1)
	movlw	0x99
	movwf	(___ftmul@f1+1)
	movlw	0x3e
	movwf	(___ftmul@f1+2)
	fcall	___ftmul
	movf	(0+(?___ftmul)),w
	movwf	(___ftadd@f2)
	movf	(1+(?___ftmul)),w
	movwf	(___ftadd@f2+1)
	movf	(2+(?___ftmul)),w
	movwf	(___ftadd@f2+2)
	bsf	status, 5	;RP0=1, select bank1
	movf	(_adc_last+1)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___lwtoft@c+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(_adc_last)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(___lwtoft@c)
	fcall	___lwtoft
	movf	(0+(?___lwtoft)),w
	movwf	(___ftmul@f2)
	movf	(1+(?___lwtoft)),w
	movwf	(___ftmul@f2+1)
	movf	(2+(?___lwtoft)),w
	movwf	(___ftmul@f2+2)
	movlw	0x33
	movwf	(___ftmul@f1)
	movlw	0x33
	movwf	(___ftmul@f1+1)
	movlw	0x3f
	movwf	(___ftmul@f1+2)
	fcall	___ftmul
	movf	(0+(?___ftmul)),w
	movwf	(___ftadd@f1)
	movf	(1+(?___ftmul)),w
	movwf	(___ftadd@f1+1)
	movf	(2+(?___ftmul)),w
	movwf	(___ftadd@f1+2)
	fcall	___ftadd
	movf	(0+(?___ftadd)),w
	movwf	(___fttol@f1)
	movf	(1+(?___ftadd)),w
	movwf	(___fttol@f1+1)
	movf	(2+(?___ftadd)),w
	movwf	(___fttol@f1+2)
	fcall	___fttol
	movf	(1+(?___fttol)),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult+1)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	(0+(?___fttol)),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult)^080h	;volatile
	line	287
	
l3024:	
;SC8F072_Pwm_Demo.c: 287: adc_last = adresult;
	movf	(_adresult+1)^080h,w	;volatile
	movwf	(_adc_last+1)^080h
	movf	(_adresult)^080h,w	;volatile
	movwf	(_adc_last)^080h
	line	288
;SC8F072_Pwm_Demo.c: 288: } else
	goto	l3030
	line	290
	
l3026:	
;SC8F072_Pwm_Demo.c: 289: {
;SC8F072_Pwm_Demo.c: 290: adresult = adsum>>3;
	movf	(ADC_Sample@adsum)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	(??_ADC_Sample+0)+0
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@adsum+1)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@adsum+2)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+2)
	bsf	status, 5	;RP0=1, select bank1
	movf	(ADC_Sample@adsum+3)^080h,w	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movwf	((??_ADC_Sample+0)+0+3)
	movlw	03h
u1985:
	clrc
	rrf	(??_ADC_Sample+0)+3,f
	rrf	(??_ADC_Sample+0)+2,f
	rrf	(??_ADC_Sample+0)+1,f
	rrf	(??_ADC_Sample+0)+0,f
u1980:
	addlw	-1
	skipz
	goto	u1985
	movf	1+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult+1)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult)^080h	;volatile
	goto	l3024
	line	293
	
l3030:	
;SC8F072_Pwm_Demo.c: 292: }
;SC8F072_Pwm_Demo.c: 293: adsum = 0;
	clrf	(ADC_Sample@adsum)^080h	;volatile
	clrf	(ADC_Sample@adsum+1)^080h	;volatile
	clrf	(ADC_Sample@adsum+2)^080h	;volatile
	clrf	(ADC_Sample@adsum+3)^080h	;volatile
	line	294
	
l3032:	
;SC8F072_Pwm_Demo.c: 294: admin = 0;
	clrf	(ADC_Sample@admin)^080h	;volatile
	clrf	(ADC_Sample@admin+1)^080h	;volatile
	line	295
	
l3034:	
;SC8F072_Pwm_Demo.c: 295: admax = 0;
	clrf	(ADC_Sample@admax)^080h	;volatile
	clrf	(ADC_Sample@admax+1)^080h	;volatile
	line	296
	
l3036:	
;SC8F072_Pwm_Demo.c: 296: return 0xA5;
	movlw	low(0A5h)
	line	297
	
l689:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_Sample
	__end_of_ADC_Sample:
	signat	_ADC_Sample,8313
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
;;		_ADC_Sample
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text13,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
	line	28
global __ptext13
__ptext13:	;psect for function ___lwtoft
psect	text13
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
	line	28
	global	__size_of___lwtoft
	__size_of___lwtoft	equ	__end_of___lwtoft-___lwtoft
	
___lwtoft:	
;incstack = 0
	opt	stack 2
; Regs used in ___lwtoft: [wreg+status,2+status,0+pclath+cstack]
	line	30
	
l2934:	
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
	
l1776:	
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
;;  f1              3   53[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  lval            4   61[BANK0 ] unsigned long 
;;  exp1            1   65[BANK0 ] unsigned char 
;;  sign1           1   60[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   53[BANK0 ] long 
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
;;		_ADC_Sample
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text14,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
	line	44
global __ptext14
__ptext14:	;psect for function ___fttol
psect	text14
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
	line	44
	global	__size_of___fttol
	__size_of___fttol	equ	__end_of___fttol-___fttol
	
___fttol:	
;incstack = 0
	opt	stack 3
; Regs used in ___fttol: [wreg+status,2+status,0]
	line	49
	
l2894:	
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
	goto	u1741
	goto	u1740
u1741:
	goto	l2898
u1740:
	line	50
	
l2896:	
	clrf	(?___fttol)
	clrf	(?___fttol+1)
	clrf	(?___fttol+2)
	clrf	(?___fttol+3)
	goto	l1667
	line	51
	
l2898:	
	movf	(___fttol@f1),w
	movwf	((??___fttol+0)+0)
	movf	(___fttol@f1+1),w
	movwf	((??___fttol+0)+0+1)
	movf	(___fttol@f1+2),w
	movwf	((??___fttol+0)+0+2)
	movlw	017h
u1755:
	clrc
	rrf	(??___fttol+0)+2,f
	rrf	(??___fttol+0)+1,f
	rrf	(??___fttol+0)+0,f
u1750:
	addlw	-1
	skipz
	goto	u1755
	movf	0+(??___fttol+0)+0,w
	movwf	(___fttol@sign1)
	line	52
	
l2900:	
	bsf	(___fttol@f1)+(15/8),(15)&7
	line	53
	
l2902:	
	movlw	0FFh
	andwf	(___fttol@f1),f
	movlw	0FFh
	andwf	(___fttol@f1+1),f
	movlw	0
	andwf	(___fttol@f1+2),f
	line	54
	
l2904:	
	movf	(___fttol@f1),w
	movwf	(___fttol@lval)
	movf	(___fttol@f1+1),w
	movwf	((___fttol@lval))+1
	movf	(___fttol@f1+2),w
	movwf	((___fttol@lval))+2
	clrf	((___fttol@lval))+3
	line	55
	
l2906:	
	movlw	08Eh
	subwf	(___fttol@exp1),f
	line	56
	
l2908:	
	btfss	(___fttol@exp1),7
	goto	u1761
	goto	u1760
u1761:
	goto	l2918
u1760:
	line	57
	
l2910:	
	movf	(___fttol@exp1),w
	xorlw	80h
	addlw	-((-15)^80h)
	skipnc
	goto	u1771
	goto	u1770
u1771:
	goto	l2914
u1770:
	goto	l2896
	line	60
	
l2914:	
	clrc
	rrf	(___fttol@lval+3),f
	rrf	(___fttol@lval+2),f
	rrf	(___fttol@lval+1),f
	rrf	(___fttol@lval),f
	line	61
	
l2916:	
	incfsz	(___fttol@exp1),f
	goto	u1781
	goto	u1780
u1781:
	goto	l2914
u1780:
	goto	l2926
	line	63
	
l2918:	
	movlw	low(018h)
	subwf	(___fttol@exp1),w
	skipc
	goto	u1791
	goto	u1790
u1791:
	goto	l2924
u1790:
	goto	l2896
	line	66
	
l2922:	
	clrc
	rlf	(___fttol@lval),f
	rlf	(___fttol@lval+1),f
	rlf	(___fttol@lval+2),f
	rlf	(___fttol@lval+3),f
	line	67
	decf	(___fttol@exp1),f
	line	65
	
l2924:	
	movf	((___fttol@exp1)),w
	btfss	status,2
	goto	u1801
	goto	u1800
u1801:
	goto	l2922
u1800:
	line	70
	
l2926:	
	movf	((___fttol@sign1)),w
	btfsc	status,2
	goto	u1811
	goto	u1810
u1811:
	goto	l2930
u1810:
	line	71
	
l2928:	
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
	
l2930:	
	movf	(___fttol@lval+3),w
	movwf	(?___fttol+3)
	movf	(___fttol@lval+2),w
	movwf	(?___fttol+2)
	movf	(___fttol@lval+1),w
	movwf	(?___fttol+1)
	movf	(___fttol@lval),w
	movwf	(?___fttol)

	line	73
	
l1667:	
	return
	opt stack 0
GLOBAL	__end_of___fttol
	__end_of___fttol:
	signat	___fttol,4220
	global	___ftmul

;; *************** function ___ftmul *****************
;; Defined at:
;;		line 62 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftmul.c"
;; Parameters:    Size  Location     Type
;;  f1              3   11[BANK0 ] float 
;;  f2              3   14[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  f3_as_produc    3   21[BANK0 ] unsigned um
;;  sign            1   25[BANK0 ] unsigned char 
;;  cntr            1   24[BANK0 ] unsigned char 
;;  exp             1   20[BANK0 ] unsigned char 
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
;;      Locals:         0       6       0
;;      Temps:          0       3       0
;;      Totals:         0      15       0
;;Total ram usage:       15 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    4
;; This function calls:
;;		___ftpack
;; This function is called by:
;;		_ADC_Sample
;; This function uses a non-reentrant model
;;
psect	text15,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftmul.c"
	line	62
global __ptext15
__ptext15:	;psect for function ___ftmul
psect	text15
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftmul.c"
	line	62
	global	__size_of___ftmul
	__size_of___ftmul	equ	__end_of___ftmul-___ftmul
	
___ftmul:	
;incstack = 0
	opt	stack 1
; Regs used in ___ftmul: [wreg+status,2+status,0+pclath+cstack]
	line	67
	
l2842:	
	movf	(___ftmul@f1),w
	movwf	((??___ftmul+0)+0)
	movf	(___ftmul@f1+1),w
	movwf	((??___ftmul+0)+0+1)
	movf	(___ftmul@f1+2),w
	movwf	((??___ftmul+0)+0+2)
	clrc
	rlf	(??___ftmul+0)+1,w
	rlf	(??___ftmul+0)+2,w
	movwf	(___ftmul@exp)
	movf	(((___ftmul@exp))),w
	btfss	status,2
	goto	u1661
	goto	u1660
u1661:
	goto	l2846
u1660:
	line	68
	
l2844:	
	clrf	(?___ftmul)
	clrf	(?___ftmul+1)
	clrf	(?___ftmul+2)
	goto	l1646
	line	69
	
l2846:	
	movf	(___ftmul@f2),w
	movwf	((??___ftmul+0)+0)
	movf	(___ftmul@f2+1),w
	movwf	((??___ftmul+0)+0+1)
	movf	(___ftmul@f2+2),w
	movwf	((??___ftmul+0)+0+2)
	clrc
	rlf	(??___ftmul+0)+1,w
	rlf	(??___ftmul+0)+2,w
	movwf	(___ftmul@sign)
	movf	(((___ftmul@sign))),w
	btfss	status,2
	goto	u1671
	goto	u1670
u1671:
	goto	l2850
u1670:
	line	70
	
l2848:	
	clrf	(?___ftmul)
	clrf	(?___ftmul+1)
	clrf	(?___ftmul+2)
	goto	l1646
	line	71
	
l2850:	
	movf	(___ftmul@sign),w
	addlw	07Bh
	addwf	(___ftmul@exp),f
	line	72
	
l2852:	
	movf	0+(___ftmul@f1)+02h,w
	movwf	(___ftmul@sign)
	line	73
	
l2854:	
	movf	0+(___ftmul@f2)+02h,w
	xorwf	(___ftmul@sign),f
	line	74
	
l2856:	
	movlw	low(080h)
	andwf	(___ftmul@sign),f
	line	75
	
l2858:	
	bsf	(___ftmul@f1)+(15/8),(15)&7
	line	77
	
l2860:	
	bsf	(___ftmul@f2)+(15/8),(15)&7
	line	78
	
l2862:	
	movlw	0FFh
	andwf	(___ftmul@f2),f
	movlw	0FFh
	andwf	(___ftmul@f2+1),f
	movlw	0
	andwf	(___ftmul@f2+2),f
	line	79
	
l2864:	
	clrf	(___ftmul@f3_as_product)
	clrf	(___ftmul@f3_as_product+1)
	clrf	(___ftmul@f3_as_product+2)
	line	134
	
l2866:	
	movlw	low(07h)
	movwf	(___ftmul@cntr)
	line	136
	
l2868:	
	btfss	(___ftmul@f1),(0)&7
	goto	u1681
	goto	u1680
u1681:
	goto	l2872
u1680:
	line	137
	
l2870:	
	movf	(___ftmul@f2),w
	addwf	(___ftmul@f3_as_product),f
	movf	(___ftmul@f2+1),w
	clrz
	skipnc
	incf	(___ftmul@f2+1),w
	skipnz
	goto	u1691
	addwf	(___ftmul@f3_as_product+1),f
u1691:
	movf	(___ftmul@f2+2),w
	clrz
	skipnc
	incf	(___ftmul@f2+2),w
	skipnz
	goto	u1692
	addwf	(___ftmul@f3_as_product+2),f
u1692:

	line	138
	
l2872:	
	clrc
	rrf	(___ftmul@f1+2),f
	rrf	(___ftmul@f1+1),f
	rrf	(___ftmul@f1),f
	line	139
	
l2874:	
	clrc
	rlf	(___ftmul@f2),f
	rlf	(___ftmul@f2+1),f
	rlf	(___ftmul@f2+2),f
	line	140
	
l2876:	
	decfsz	(___ftmul@cntr),f
	goto	u1701
	goto	u1700
u1701:
	goto	l2868
u1700:
	line	143
	
l2878:	
	movlw	low(09h)
	movwf	(___ftmul@cntr)
	line	145
	
l2880:	
	btfss	(___ftmul@f1),(0)&7
	goto	u1711
	goto	u1710
u1711:
	goto	l2884
u1710:
	line	146
	
l2882:	
	movf	(___ftmul@f2),w
	addwf	(___ftmul@f3_as_product),f
	movf	(___ftmul@f2+1),w
	clrz
	skipnc
	incf	(___ftmul@f2+1),w
	skipnz
	goto	u1721
	addwf	(___ftmul@f3_as_product+1),f
u1721:
	movf	(___ftmul@f2+2),w
	clrz
	skipnc
	incf	(___ftmul@f2+2),w
	skipnz
	goto	u1722
	addwf	(___ftmul@f3_as_product+2),f
u1722:

	line	147
	
l2884:	
	clrc
	rrf	(___ftmul@f1+2),f
	rrf	(___ftmul@f1+1),f
	rrf	(___ftmul@f1),f
	line	148
	
l2886:	
	clrc
	rrf	(___ftmul@f3_as_product+2),f
	rrf	(___ftmul@f3_as_product+1),f
	rrf	(___ftmul@f3_as_product),f
	line	149
	
l2888:	
	decfsz	(___ftmul@cntr),f
	goto	u1731
	goto	u1730
u1731:
	goto	l2880
u1730:
	line	156
	
l2890:	
	movf	(___ftmul@f3_as_product),w
	movwf	(___ftpack@arg)
	movf	(___ftmul@f3_as_product+1),w
	movwf	(___ftpack@arg+1)
	movf	(___ftmul@f3_as_product+2),w
	movwf	(___ftpack@arg+2)
	movf	(___ftmul@exp),w
	movwf	(___ftpack@exp)
	movf	(___ftmul@sign),w
	movwf	(___ftpack@sign)
	fcall	___ftpack
	movf	(0+(?___ftpack)),w
	movwf	(?___ftmul)
	movf	(1+(?___ftpack)),w
	movwf	(?___ftmul+1)
	movf	(2+(?___ftpack)),w
	movwf	(?___ftmul+2)
	line	157
	
l1646:	
	return
	opt stack 0
GLOBAL	__end_of___ftmul
	__end_of___ftmul:
	signat	___ftmul,8315
	global	___ftadd

;; *************** function ___ftadd *****************
;; Defined at:
;;		line 86 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
;; Parameters:    Size  Location     Type
;;  f1              3   26[BANK0 ] float 
;;  f2              3   29[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  exp1            1   37[BANK0 ] unsigned char 
;;  exp2            1   36[BANK0 ] unsigned char 
;;  sign            1   35[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   26[BANK0 ] float 
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
;;		_ADC_Sample
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text16,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
	line	86
global __ptext16
__ptext16:	;psect for function ___ftadd
psect	text16
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
	line	86
	global	__size_of___ftadd
	__size_of___ftadd	equ	__end_of___ftadd-___ftadd
	
___ftadd:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftadd: [wreg+status,2+status,0+pclath+cstack]
	line	90
	
l2766:	
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
	goto	u1461
	goto	u1460
u1461:
	goto	l2772
u1460:
	
l2768:	
	movf	(___ftadd@exp2),w
	subwf	(___ftadd@exp1),w
	skipnc
	goto	u1471
	goto	u1470
u1471:
	goto	l2776
u1470:
	
l2770:	
	movf	(___ftadd@exp2),w
	movwf	(??___ftadd+0)+0
	movf	(___ftadd@exp1),w
	subwf	(??___ftadd+0)+0,f
	movlw	low(019h)
	subwf	0+(??___ftadd+0)+0,w
	skipc
	goto	u1481
	goto	u1480
u1481:
	goto	l2776
u1480:
	line	93
	
l2772:	
	movf	(___ftadd@f2),w
	movwf	(?___ftadd)
	movf	(___ftadd@f2+1),w
	movwf	(?___ftadd+1)
	movf	(___ftadd@f2+2),w
	movwf	(?___ftadd+2)
	goto	l1600
	line	94
	
l2776:	
	movf	((___ftadd@exp2)),w
	btfsc	status,2
	goto	u1491
	goto	u1490
u1491:
	goto	l1603
u1490:
	
l2778:	
	movf	(___ftadd@exp1),w
	subwf	(___ftadd@exp2),w
	skipnc
	goto	u1501
	goto	u1500
u1501:
	goto	l2782
u1500:
	
l2780:	
	movf	(___ftadd@exp1),w
	movwf	(??___ftadd+0)+0
	movf	(___ftadd@exp2),w
	subwf	(??___ftadd+0)+0,f
	movlw	low(019h)
	subwf	0+(??___ftadd+0)+0,w
	skipc
	goto	u1511
	goto	u1510
u1511:
	goto	l2782
u1510:
	
l1603:	
	line	95
	goto	l1600
	line	96
	
l2782:	
	movlw	low(06h)
	movwf	(___ftadd@sign)
	line	97
	
l2784:	
	btfss	(___ftadd@f1+2),(23)&7
	goto	u1521
	goto	u1520
u1521:
	goto	l1604
u1520:
	line	98
	
l2786:	
	bsf	(___ftadd@sign)+(7/8),(7)&7
	
l1604:	
	line	99
	btfss	(___ftadd@f2+2),(23)&7
	goto	u1531
	goto	u1530
u1531:
	goto	l1605
u1530:
	line	100
	
l2788:	
	bsf	(___ftadd@sign)+(6/8),(6)&7
	
l1605:	
	line	101
	bsf	(___ftadd@f1)+(15/8),(15)&7
	line	102
	
l2790:	
	movlw	0FFh
	andwf	(___ftadd@f1),f
	movlw	0FFh
	andwf	(___ftadd@f1+1),f
	movlw	0
	andwf	(___ftadd@f1+2),f
	line	103
	
l2792:	
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
	goto	u1541
	goto	u1540
u1541:
	goto	l2804
u1540:
	line	110
	
l2794:	
	clrc
	rlf	(___ftadd@f2),f
	rlf	(___ftadd@f2+1),f
	rlf	(___ftadd@f2+2),f
	line	111
	decf	(___ftadd@exp2),f
	line	112
	
l2796:	
	movf	(___ftadd@exp2),w
	xorwf	(___ftadd@exp1),w
	skipnz
	goto	u1551
	goto	u1550
u1551:
	goto	l2802
u1550:
	
l2798:	
	decf	(___ftadd@sign),f
	movf	((___ftadd@sign)),w
	andlw	07h
	btfss	status,2
	goto	u1561
	goto	u1560
u1561:
	goto	l2794
u1560:
	goto	l2802
	line	114
	
l2800:	
	clrc
	rrf	(___ftadd@f1+2),f
	rrf	(___ftadd@f1+1),f
	rrf	(___ftadd@f1),f
	line	115
	incf	(___ftadd@exp1),f
	line	113
	
l2802:	
	movf	(___ftadd@exp1),w
	xorwf	(___ftadd@exp2),w
	skipz
	goto	u1571
	goto	u1570
u1571:
	goto	l2800
u1570:
	goto	l1614
	line	117
	
l2804:	
	movf	(___ftadd@exp1),w
	subwf	(___ftadd@exp2),w
	skipnc
	goto	u1581
	goto	u1580
u1581:
	goto	l1614
u1580:
	line	121
	
l2806:	
	clrc
	rlf	(___ftadd@f1),f
	rlf	(___ftadd@f1+1),f
	rlf	(___ftadd@f1+2),f
	line	122
	decf	(___ftadd@exp1),f
	line	123
	
l2808:	
	movf	(___ftadd@exp2),w
	xorwf	(___ftadd@exp1),w
	skipnz
	goto	u1591
	goto	u1590
u1591:
	goto	l2814
u1590:
	
l2810:	
	decf	(___ftadd@sign),f
	movf	((___ftadd@sign)),w
	andlw	07h
	btfss	status,2
	goto	u1601
	goto	u1600
u1601:
	goto	l2806
u1600:
	goto	l2814
	line	125
	
l2812:	
	clrc
	rrf	(___ftadd@f2+2),f
	rrf	(___ftadd@f2+1),f
	rrf	(___ftadd@f2),f
	line	126
	incf	(___ftadd@exp2),f
	line	124
	
l2814:	
	movf	(___ftadd@exp1),w
	xorwf	(___ftadd@exp2),w
	skipz
	goto	u1611
	goto	u1610
u1611:
	goto	l2812
u1610:
	line	129
	
l1614:	
	btfss	(___ftadd@sign),(7)&7
	goto	u1621
	goto	u1620
u1621:
	goto	l2820
u1620:
	line	131
	
l2816:	
	movlw	0FFh
	xorwf	(___ftadd@f1),f
	movlw	0FFh
	xorwf	(___ftadd@f1+1),f
	movlw	0FFh
	xorwf	(___ftadd@f1+2),f
	line	132
	
l2818:	
	incf	(___ftadd@f1),f
	skipnz
	incf	(___ftadd@f1+1),f
	skipnz
	incf	(___ftadd@f1+2),f
	line	134
	
l2820:	
	btfss	(___ftadd@sign),(6)&7
	goto	u1631
	goto	u1630
u1631:
	goto	l2826
u1630:
	line	136
	
l2822:	
	movlw	0FFh
	xorwf	(___ftadd@f2),f
	movlw	0FFh
	xorwf	(___ftadd@f2+1),f
	movlw	0FFh
	xorwf	(___ftadd@f2+2),f
	line	137
	
l2824:	
	incf	(___ftadd@f2),f
	skipnz
	incf	(___ftadd@f2+1),f
	skipnz
	incf	(___ftadd@f2+2),f
	line	139
	
l2826:	
	clrf	(___ftadd@sign)
	line	140
	
l2828:	
	movf	(___ftadd@f1),w
	addwf	(___ftadd@f2),f
	movf	(___ftadd@f1+1),w
	clrz
	skipnc
	incf	(___ftadd@f1+1),w
	skipnz
	goto	u1641
	addwf	(___ftadd@f2+1),f
u1641:
	movf	(___ftadd@f1+2),w
	clrz
	skipnc
	incf	(___ftadd@f1+2),w
	skipnz
	goto	u1642
	addwf	(___ftadd@f2+2),f
u1642:

	line	141
	
l2830:	
	btfss	(___ftadd@f2+2),(23)&7
	goto	u1651
	goto	u1650
u1651:
	goto	l2838
u1650:
	line	142
	
l2832:	
	movlw	0FFh
	xorwf	(___ftadd@f2),f
	movlw	0FFh
	xorwf	(___ftadd@f2+1),f
	movlw	0FFh
	xorwf	(___ftadd@f2+2),f
	line	143
	
l2834:	
	incf	(___ftadd@f2),f
	skipnz
	incf	(___ftadd@f2+1),f
	skipnz
	incf	(___ftadd@f2+2),f
	line	144
	
l2836:	
	clrf	(___ftadd@sign)
	incf	(___ftadd@sign),f
	line	146
	
l2838:	
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
	
l1600:	
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
;;		___ftmul
;;		___lwtoft
;; This function uses a non-reentrant model
;;
psect	text17,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
	line	62
global __ptext17
__ptext17:	;psect for function ___ftpack
psect	text17
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
	line	62
	global	__size_of___ftpack
	__size_of___ftpack	equ	__end_of___ftpack-___ftpack
	
___ftpack:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftpack: [wreg+status,2+status,0]
	line	64
	
l2682:	
	movf	((___ftpack@exp)),w
	btfsc	status,2
	goto	u1291
	goto	u1290
u1291:
	goto	l1578
u1290:
	
l2684:	
	movf	(___ftpack@arg+2),w
	iorwf	(___ftpack@arg+1),w
	iorwf	(___ftpack@arg),w
	skipz
	goto	u1301
	goto	u1300
u1301:
	goto	l2688
u1300:
	
l1578:	
	line	65
	clrf	(?___ftpack)
	clrf	(?___ftpack+1)
	clrf	(?___ftpack+2)
	goto	l1579
	line	67
	
l2686:	
	incf	(___ftpack@exp),f
	line	68
	clrc
	rrf	(___ftpack@arg+2),f
	rrf	(___ftpack@arg+1),f
	rrf	(___ftpack@arg),f
	line	66
	
l2688:	
	movlw	low highword(0FE0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u1311
	goto	u1310
u1311:
	goto	l2686
u1310:
	goto	l2692
	line	71
	
l2690:	
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
	
l2692:	
	movlw	low highword(0FF0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u1321
	goto	u1320
u1321:
	goto	l2690
u1320:
	goto	l2696
	line	76
	
l2694:	
	decf	(___ftpack@exp),f
	line	77
	clrc
	rlf	(___ftpack@arg),f
	rlf	(___ftpack@arg+1),f
	rlf	(___ftpack@arg+2),f
	line	75
	
l2696:	
	btfsc	(___ftpack@arg+1),(15)&7
	goto	u1331
	goto	u1330
u1331:
	goto	l1590
u1330:
	
l2698:	
	movlw	low(02h)
	subwf	(___ftpack@exp),w
	skipnc
	goto	u1341
	goto	u1340
u1341:
	goto	l2694
u1340:
	
l1590:	
	line	79
	btfsc	(___ftpack@exp),(0)&7
	goto	u1351
	goto	u1350
u1351:
	goto	l1591
u1350:
	line	80
	
l2700:	
	bcf	(___ftpack@arg)+(15/8),(15)&7
	
l1591:	
	line	81
	clrc
	rrf	(___ftpack@exp),f
	line	82
	
l2702:	
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
	goto	u1361
	goto	u1360
u1361:
	goto	l1592
u1360:
	line	84
	
l2704:	
	bsf	(___ftpack@arg)+(23/8),(23)&7
	
l1592:	
	line	85
	line	86
	
l1579:	
	return
	opt stack 0
GLOBAL	__end_of___ftpack
	__end_of___ftpack:
	signat	___ftpack,12411
	global	_Isr_Timer

;; *************** function _Isr_Timer *****************
;; Defined at:
;;		line 390 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
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
psect	text18,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	390
global __ptext18
__ptext18:	;psect for function _Isr_Timer
psect	text18
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\SC8F072_Pwm_Demo.c"
	line	390
	global	__size_of_Isr_Timer
	__size_of_Isr_Timer	equ	__end_of_Isr_Timer-_Isr_Timer
	
_Isr_Timer:	
;incstack = 0
	opt	stack 1
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
psect	text18
	line	392
	
i1l3438:	
;SC8F072_Pwm_Demo.c: 392: if(RAIF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(107/8),(107)&7	;volatile
	goto	u241_21
	goto	u241_20
u241_21:
	goto	i1l3450
u241_20:
	line	394
	
i1l3440:	
;SC8F072_Pwm_Demo.c: 393: {
;SC8F072_Pwm_Demo.c: 394: T_flag=1;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_T_flag)^080h	;volatile
	line	395
	
i1l3442:	
;SC8F072_Pwm_Demo.c: 395: if (!(PORTA & 0x20))
	btfsc	(134)^080h,(5)&7	;volatile
	goto	u242_21
	goto	u242_20
u242_21:
	goto	i1l3446
u242_20:
	line	397
	
i1l3444:	
;SC8F072_Pwm_Demo.c: 396: {
;SC8F072_Pwm_Demo.c: 397: Charge_num();
	fcall	_Charge_num
	line	398
;SC8F072_Pwm_Demo.c: 398: }
	goto	i1l3448
	line	401
	
i1l3446:	
;SC8F072_Pwm_Demo.c: 399: else
;SC8F072_Pwm_Demo.c: 400: {
;SC8F072_Pwm_Demo.c: 401: Uncharge_num();
	fcall	_Uncharge_num
	line	403
	
i1l3448:	
;SC8F072_Pwm_Demo.c: 402: }
;SC8F072_Pwm_Demo.c: 403: RAIF = 0;
	bcf	(107/8),(107)&7	;volatile
	line	405
	
i1l3450:	
;SC8F072_Pwm_Demo.c: 404: }
;SC8F072_Pwm_Demo.c: 405: if(RBIF)
	btfss	(88/8),(88)&7	;volatile
	goto	u243_21
	goto	u243_20
u243_21:
	goto	i1l3468
u243_20:
	line	411
	
i1l3452:	
;SC8F072_Pwm_Demo.c: 406: {
;SC8F072_Pwm_Demo.c: 411: if (PORTB & 0x20)
	btfss	(6),(5)&7	;volatile
	goto	u244_21
	goto	u244_20
u244_21:
	goto	i1l3466
u244_20:
	line	413
	
i1l3454:	
;SC8F072_Pwm_Demo.c: 412: {
;SC8F072_Pwm_Demo.c: 413: if (long_press_counter >= 1000)
	movlw	03h
	bsf	status, 5	;RP0=1, select bank1
	subwf	(_long_press_counter+1)^080h,w	;volatile
	movlw	0E8h
	skipnz
	subwf	(_long_press_counter)^080h,w	;volatile
	skipc
	goto	u245_21
	goto	u245_20
u245_21:
	goto	i1l3458
u245_20:
	line	415
	
i1l3456:	
;SC8F072_Pwm_Demo.c: 414: {
;SC8F072_Pwm_Demo.c: 415: button_lflag = 1;
	movlw	low(01h)
	movwf	(_button_lflag)^080h	;volatile
	line	416
;SC8F072_Pwm_Demo.c: 416: }
	goto	i1l3464
	line	417
	
i1l3458:	
;SC8F072_Pwm_Demo.c: 417: else if(long_press_counter<=1000 && long_press_counter>=50)
	movlw	03h
	subwf	(_long_press_counter+1)^080h,w	;volatile
	movlw	0E9h
	skipnz
	subwf	(_long_press_counter)^080h,w	;volatile
	skipnc
	goto	u246_21
	goto	u246_20
u246_21:
	goto	i1l3464
u246_20:
	
i1l3460:	
	movlw	0
	subwf	(_long_press_counter+1)^080h,w	;volatile
	movlw	032h
	skipnz
	subwf	(_long_press_counter)^080h,w	;volatile
	skipc
	goto	u247_21
	goto	u247_20
u247_21:
	goto	i1l3464
u247_20:
	line	419
	
i1l3462:	
;SC8F072_Pwm_Demo.c: 418: {
;SC8F072_Pwm_Demo.c: 419: button_sflag = 1;
	movlw	low(01h)
	movwf	(_button_sflag)^080h	;volatile
	line	421
	
i1l3464:	
;SC8F072_Pwm_Demo.c: 420: }
;SC8F072_Pwm_Demo.c: 421: long_press_counter = 0;
	clrf	(_long_press_counter)^080h	;volatile
	clrf	(_long_press_counter+1)^080h	;volatile
	line	423
	
i1l3466:	
;SC8F072_Pwm_Demo.c: 422: }
;SC8F072_Pwm_Demo.c: 423: RBIF = 0;
	bcf	(88/8),(88)&7	;volatile
	line	425
	
i1l3468:	
;SC8F072_Pwm_Demo.c: 424: }
;SC8F072_Pwm_Demo.c: 425: if(T0IF)
	btfss	(90/8),(90)&7	;volatile
	goto	u248_21
	goto	u248_20
u248_21:
	goto	i1l3484
u248_20:
	line	427
	
i1l3470:	
;SC8F072_Pwm_Demo.c: 426: {
;SC8F072_Pwm_Demo.c: 427: if(T_flag)
	bsf	status, 5	;RP0=1, select bank1
	movf	((_T_flag)^080h),w	;volatile
	btfsc	status,2
	goto	u249_21
	goto	u249_20
u249_21:
	goto	i1l3474
u249_20:
	line	429
	
i1l3472:	
;SC8F072_Pwm_Demo.c: 428: {
;SC8F072_Pwm_Demo.c: 429: Display();
	fcall	_Display
	line	431
	
i1l3474:	
;SC8F072_Pwm_Demo.c: 430: }
;SC8F072_Pwm_Demo.c: 431: TMR0 += 6;
	movlw	low(06h)
	addwf	(129)^080h,f	;volatile
	line	432
	
i1l3476:	
;SC8F072_Pwm_Demo.c: 432: T0IF = 0;
	bcf	(90/8),(90)&7	;volatile
	line	434
	
i1l3478:	
;SC8F072_Pwm_Demo.c: 434: if(ADC_delay > 0)
	movf	((_ADC_delay)^080h),w	;volatile
iorwf	((_ADC_delay+1)^080h),w	;volatile
	btfsc	status,2
	goto	u250_21
	goto	u250_20
u250_21:
	goto	i1l3482
u250_20:
	line	436
	
i1l3480:	
;SC8F072_Pwm_Demo.c: 435: {
;SC8F072_Pwm_Demo.c: 436: ADC_delay--;
	movlw	01h
	subwf	(_ADC_delay)^080h,f	;volatile
	movlw	0
	skipc
	decf	(_ADC_delay+1)^080h,f	;volatile
	subwf	(_ADC_delay+1)^080h,f	;volatile
	line	437
;SC8F072_Pwm_Demo.c: 437: }
	goto	i1l3484
	line	440
	
i1l3482:	
;SC8F072_Pwm_Demo.c: 438: else
;SC8F072_Pwm_Demo.c: 439: {
;SC8F072_Pwm_Demo.c: 440: ADC_delay=1000;
	movlw	0E8h
	movwf	(_ADC_delay)^080h	;volatile
	movlw	03h
	movwf	((_ADC_delay)^080h)+1	;volatile
	line	441
;SC8F072_Pwm_Demo.c: 441: ADC_Flag=1;
	movlw	low(01h)
	movwf	(_ADC_Flag)^080h	;volatile
	line	444
	
i1l3484:	
;SC8F072_Pwm_Demo.c: 442: }
;SC8F072_Pwm_Demo.c: 443: }
;SC8F072_Pwm_Demo.c: 444: if(TMR2IF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(105/8),(105)&7	;volatile
	goto	u251_21
	goto	u251_20
u251_21:
	goto	i1l743
u251_20:
	line	446
	
i1l3486:	
;SC8F072_Pwm_Demo.c: 445: {
;SC8F072_Pwm_Demo.c: 446: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	465
;SC8F072_Pwm_Demo.c: 465: if (!(PORTB & 0x20))
	btfsc	(6),(5)&7	;volatile
	goto	u252_21
	goto	u252_20
u252_21:
	goto	i1l3496
u252_20:
	line	467
	
i1l3488:	
;SC8F072_Pwm_Demo.c: 466: {
;SC8F072_Pwm_Demo.c: 467: if (debounce_counter < 15) debounce_counter++;
	movlw	low(0Fh)
	bsf	status, 5	;RP0=1, select bank1
	subwf	(_debounce_counter)^080h,w	;volatile
	skipnc
	goto	u253_21
	goto	u253_20
u253_21:
	goto	i1l3492
u253_20:
	
i1l3490:	
	incf	(_debounce_counter)^080h,f	;volatile
	line	468
	
i1l3492:	
;SC8F072_Pwm_Demo.c: 468: if (debounce_counter == 15) long_press_counter++;
		movlw	15
	xorwf	((_debounce_counter)^080h),w	;volatile
	btfss	status,2
	goto	u254_21
	goto	u254_20
u254_21:
	goto	i1l3498
u254_20:
	
i1l3494:	
	incf	(_long_press_counter)^080h,f	;volatile
	skipnz
	incf	(_long_press_counter+1)^080h,f	;volatile
	goto	i1l3498
	line	472
	
i1l3496:	
;SC8F072_Pwm_Demo.c: 470: else
;SC8F072_Pwm_Demo.c: 471: {
;SC8F072_Pwm_Demo.c: 472: debounce_counter = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(_debounce_counter)^080h	;volatile
	line	476
	
i1l3498:	
;SC8F072_Pwm_Demo.c: 473: }
;SC8F072_Pwm_Demo.c: 476: if(Time_delay > 0)
	movf	((_Time_delay)^080h),w	;volatile
iorwf	((_Time_delay+1)^080h),w	;volatile
	btfsc	status,2
	goto	u255_21
	goto	u255_20
u255_21:
	goto	i1l739
u255_20:
	line	478
	
i1l3500:	
;SC8F072_Pwm_Demo.c: 477: {
;SC8F072_Pwm_Demo.c: 478: Time_delay--;
	movlw	01h
	subwf	(_Time_delay)^080h,f	;volatile
	movlw	0
	skipc
	decf	(_Time_delay+1)^080h,f	;volatile
	subwf	(_Time_delay+1)^080h,f	;volatile
	line	479
;SC8F072_Pwm_Demo.c: 479: }
	goto	i1l743
	line	480
	
i1l739:	
	line	482
;SC8F072_Pwm_Demo.c: 480: else
;SC8F072_Pwm_Demo.c: 481: {
;SC8F072_Pwm_Demo.c: 482: if (!(PORTA & 0x20))
	btfsc	(134)^080h,(5)&7	;volatile
	goto	u256_21
	goto	u256_20
u256_21:
	goto	i1l3504
u256_20:
	line	484
	
i1l3502:	
;SC8F072_Pwm_Demo.c: 483: {
;SC8F072_Pwm_Demo.c: 484: Charge_num();
	fcall	_Charge_num
	line	485
;SC8F072_Pwm_Demo.c: 485: }
	goto	i1l743
	line	488
	
i1l3504:	
;SC8F072_Pwm_Demo.c: 486: else
;SC8F072_Pwm_Demo.c: 487: {
;SC8F072_Pwm_Demo.c: 488: Uncharge_num();
	fcall	_Uncharge_num
	line	492
	
i1l743:	
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
;;		line 25 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  hundred         1    9[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/100
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
psect	text19,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	25
global __ptext19
__ptext19:	;psect for function _Uncharge_num
psect	text19
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	25
	global	__size_of_Uncharge_num
	__size_of_Uncharge_num	equ	__end_of_Uncharge_num-_Uncharge_num
	
_Uncharge_num:	
;incstack = 0
	opt	stack 1
; Regs used in _Uncharge_num: [wreg+status,2+status,0+pclath+cstack]
	line	27
	
i1l3384:	
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
	movwf	(_tens)	;volatile
	line	29
;LED_188.c: 29: unit = (unsigned char)(power_percent % 10);
	movlw	low(0Ah)
	movwf	(___lbmod@divisor)
	movf	(_power_percent),w	;volatile
	fcall	___lbmod
	movwf	(_unit)	;volatile
	line	30
	
i1l3386:	
;LED_188.c: 30: if(hundred)
	movf	((Uncharge_num@hundred)),w
	btfsc	status,2
	goto	u239_21
	goto	u239_20
u239_21:
	goto	i1l3390
u239_20:
	line	32
	
i1l3388:	
;LED_188.c: 31: {
;LED_188.c: 32: hundreds = 3;
	movlw	low(03h)
	movwf	(_hundreds)	;volatile
	line	33
;LED_188.c: 33: }
	goto	i1l1359
	line	36
	
i1l3390:	
;LED_188.c: 34: else
;LED_188.c: 35: {
;LED_188.c: 36: hundreds = 1;
	movlw	low(01h)
	movwf	(_hundreds)	;volatile
	line	38
	
i1l1359:	
	return
	opt stack 0
GLOBAL	__end_of_Uncharge_num
	__end_of_Uncharge_num:
	signat	_Uncharge_num,89
	global	_Display

;; *************** function _Display *****************
;; Defined at:
;;		line 170 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/100
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
psect	text20,local,class=CODE,delta=2,merge=1,group=0
	line	170
global __ptext20
__ptext20:	;psect for function _Display
psect	text20
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	170
	global	__size_of_Display
	__size_of_Display	equ	__end_of_Display-_Display
	
_Display:	
;incstack = 0
	opt	stack 1
; Regs used in _Display: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	173
	
i1l3392:	
;LED_188.c: 172: static unsigned char scan_cnt;
;LED_188.c: 173: Set_AllPin_INPUT();
	fcall	_Set_AllPin_INPUT
	line	175
;LED_188.c: 175: switch(scan_cnt)
	goto	i1l3418
	line	177
	
i1l3394:	
	fcall	_Display_Scan1
	
i1l3396:	
	bsf	status, 5	;RP0=1, select bank1
	incf	(Display@scan_cnt)^080h,f
	goto	i1l1418
	line	178
	
i1l3398:	
	fcall	_Display_Scan2
	goto	i1l3396
	line	179
	
i1l3402:	
	fcall	_Display_Scan3
	goto	i1l3396
	line	180
	
i1l3406:	
	fcall	_Display_Scan4
	goto	i1l3396
	line	181
	
i1l3410:	
	fcall	_Display_Scan5
	
i1l3412:	
	bsf	status, 5	;RP0=1, select bank1
	clrf	(Display@scan_cnt)^080h
	goto	i1l1418
	line	175
	
i1l3418:	
	bsf	status, 5	;RP0=1, select bank1
	movf	(Display@scan_cnt)^080h,w
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
goto i1l3412
movlw high(i1S3580)
movwf pclath
	movlw low(i1S3580)
	addwf fsr,w
	movwf pc
psect	swtext3,local,class=CONST,delta=2
global __pswtext3
__pswtext3:
i1S3580:
	ljmp	i1l3394
	ljmp	i1l3398
	ljmp	i1l3402
	ljmp	i1l3406
	ljmp	i1l3410
psect	text20

	line	184
	
i1l1418:	
	return
	opt stack 0
GLOBAL	__end_of_Display
	__end_of_Display:
	signat	_Display,89
	global	_Set_AllPin_INPUT

;; *************** function _Set_AllPin_INPUT *****************
;; Defined at:
;;		line 85 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
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
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Display
;; This function uses a non-reentrant model
;;
psect	text21,local,class=CODE,delta=2,merge=1,group=0
	line	85
global __ptext21
__ptext21:	;psect for function _Set_AllPin_INPUT
psect	text21
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	85
	global	__size_of_Set_AllPin_INPUT
	__size_of_Set_AllPin_INPUT	equ	__end_of_Set_AllPin_INPUT-_Set_AllPin_INPUT
	
_Set_AllPin_INPUT:	
;incstack = 0
	opt	stack 1
; Regs used in _Set_AllPin_INPUT: []
	line	87
	
i1l3044:	
;LED_188.c: 87: TRISB0 = 1;;
	bcf	status, 5	;RP0=0, select bank0
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
	
i1l1372:	
	return
	opt stack 0
GLOBAL	__end_of_Set_AllPin_INPUT
	__end_of_Set_AllPin_INPUT:
	signat	_Set_AllPin_INPUT,89
	global	_Display_Scan5

;; *************** function _Display_Scan5 *****************
;; Defined at:
;;		line 161 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/100
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
	line	161
global __ptext22
__ptext22:	;psect for function _Display_Scan5
psect	text22
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	161
	global	__size_of_Display_Scan5
	__size_of_Display_Scan5	equ	__end_of_Display_Scan5-_Display_Scan5
	
_Display_Scan5:	
;incstack = 0
	opt	stack 1
; Regs used in _Display_Scan5: [wreg-fsr0h+status,2+status,0]
	line	163
	
i1l3118:	
;LED_188.c: 163: TRISB4 = 0;RB4 = 0;;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(44/8),(44)&7	;volatile
	bcf	(52/8),(52)&7	;volatile
	line	164
	
i1l3120:	
;LED_188.c: 164: if(num_hund[hundreds] & 0x02)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(1)&7
	goto	u215_21
	goto	u215_20
u215_21:
	goto	i1l1403
u215_20:
	line	165
	
i1l3122:	
;LED_188.c: 165: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1403:	
	bsf	(50/8),(50)&7	;volatile
	line	166
	
i1l3124:	
;LED_188.c: 166: if(num_hund[hundreds] & 0x01)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u216_21
	goto	u216_20
u216_21:
	goto	i1l1404
u216_20:
	line	167
	
i1l3126:	
;LED_188.c: 167: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1404:	
	bsf	(49/8),(49)&7	;volatile
	line	168
	
i1l1405:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan5
	__end_of_Display_Scan5:
	signat	_Display_Scan5,89
	global	_Display_Scan4

;; *************** function _Display_Scan4 *****************
;; Defined at:
;;		line 147 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/100
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
	line	147
global __ptext23
__ptext23:	;psect for function _Display_Scan4
psect	text23
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	147
	global	__size_of_Display_Scan4
	__size_of_Display_Scan4	equ	__end_of_Display_Scan4-_Display_Scan4
	
_Display_Scan4:	
;incstack = 0
	opt	stack 1
; Regs used in _Display_Scan4: [wreg-fsr0h+status,2+status,0]
	line	149
	
i1l3100:	
;LED_188.c: 149: TRISB3 = 0;RB3 = 0;;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(43/8),(43)&7	;volatile
	bcf	(51/8),(51)&7	;volatile
	line	150
	
i1l3102:	
;LED_188.c: 150: if(nums[unit] & 0x04)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(2)&7
	goto	u211_21
	goto	u211_20
u211_21:
	goto	i1l1396
u211_20:
	line	151
	
i1l3104:	
;LED_188.c: 151: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1396:	
	bsf	(48/8),(48)&7	;volatile
	line	152
	
i1l3106:	
;LED_188.c: 152: if(num_hund[hundreds] & 0x04)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(2)&7
	goto	u212_21
	goto	u212_20
u212_21:
	goto	i1l1397
u212_20:
	line	153
	
i1l3108:	
;LED_188.c: 153: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1397:	
	bsf	(49/8),(49)&7	;volatile
	line	154
	
i1l3110:	
;LED_188.c: 154: if(num_hund[hundreds] & 0x08)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u213_21
	goto	u213_20
u213_21:
	goto	i1l1398
u213_20:
	line	155
	
i1l3112:	
;LED_188.c: 155: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1398:	
	bsf	(50/8),(50)&7	;volatile
	line	156
	
i1l3114:	
;LED_188.c: 156: if(nums[tens] & 0x01)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u214_21
	goto	u214_20
u214_21:
	goto	i1l1399
u214_20:
	line	157
	
i1l3116:	
;LED_188.c: 157: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1399:	
	bsf	(52/8),(52)&7	;volatile
	line	158
	
i1l1400:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan4
	__end_of_Display_Scan4:
	signat	_Display_Scan4,89
	global	_Display_Scan3

;; *************** function _Display_Scan3 *****************
;; Defined at:
;;		line 133 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/100
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
	line	133
global __ptext24
__ptext24:	;psect for function _Display_Scan3
psect	text24
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	133
	global	__size_of_Display_Scan3
	__size_of_Display_Scan3	equ	__end_of_Display_Scan3-_Display_Scan3
	
_Display_Scan3:	
;incstack = 0
	opt	stack 1
; Regs used in _Display_Scan3: [wreg-fsr0h+status,2+status,0]
	line	135
	
i1l3082:	
;LED_188.c: 135: TRISB2 = 0;RB2 = 0;;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(42/8),(42)&7	;volatile
	bcf	(50/8),(50)&7	;volatile
	line	136
	
i1l3084:	
;LED_188.c: 136: if(nums[unit] & 0x10)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(4)&7
	goto	u207_21
	goto	u207_20
u207_21:
	goto	i1l1389
u207_20:
	line	137
	
i1l3086:	
;LED_188.c: 137: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1389:	
	bsf	(48/8),(48)&7	;volatile
	line	138
	
i1l3088:	
;LED_188.c: 138: if(nums[tens] & 0x40)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(6)&7
	goto	u208_21
	goto	u208_20
u208_21:
	goto	i1l1390
u208_20:
	line	139
	
i1l3090:	
;LED_188.c: 139: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1390:	
	bsf	(49/8),(49)&7	;volatile
	line	140
	
i1l3092:	
;LED_188.c: 140: if(nums[tens] & 0x10)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(4)&7
	goto	u209_21
	goto	u209_20
u209_21:
	goto	i1l1391
u209_20:
	line	141
	
i1l3094:	
;LED_188.c: 141: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1391:	
	bsf	(51/8),(51)&7	;volatile
	line	142
	
i1l3096:	
;LED_188.c: 142: if(nums[tens] & 0x02)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(1)&7
	goto	u210_21
	goto	u210_20
u210_21:
	goto	i1l1392
u210_20:
	line	143
	
i1l3098:	
;LED_188.c: 143: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1392:	
	bsf	(52/8),(52)&7	;volatile
	line	144
	
i1l1393:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan3
	__end_of_Display_Scan3:
	signat	_Display_Scan3,89
	global	_Display_Scan2

;; *************** function _Display_Scan2 *****************
;; Defined at:
;;		line 119 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/100
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
	line	119
global __ptext25
__ptext25:	;psect for function _Display_Scan2
psect	text25
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	119
	global	__size_of_Display_Scan2
	__size_of_Display_Scan2	equ	__end_of_Display_Scan2-_Display_Scan2
	
_Display_Scan2:	
;incstack = 0
	opt	stack 1
; Regs used in _Display_Scan2: [wreg-fsr0h+status,2+status,0]
	line	121
	
i1l3064:	
;LED_188.c: 121: TRISB1 = 0;RB1 = 0;;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(41/8),(41)&7	;volatile
	bcf	(49/8),(49)&7	;volatile
	line	122
	
i1l3066:	
;LED_188.c: 122: if(nums[unit] &0x40)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(6)&7
	goto	u203_21
	goto	u203_20
u203_21:
	goto	i1l1382
u203_20:
	line	123
	
i1l3068:	
;LED_188.c: 123: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1382:	
	bsf	(48/8),(48)&7	;volatile
	line	124
	
i1l3070:	
;LED_188.c: 124: if(nums[tens] & 0x20)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(5)&7
	goto	u204_21
	goto	u204_20
u204_21:
	goto	i1l1383
u204_20:
	line	125
	
i1l3072:	
;LED_188.c: 125: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1383:	
	bsf	(50/8),(50)&7	;volatile
	line	126
	
i1l3074:	
;LED_188.c: 126: if(nums[tens] & 0x08)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u205_21
	goto	u205_20
u205_21:
	goto	i1l1384
u205_20:
	line	127
	
i1l3076:	
;LED_188.c: 127: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1384:	
	bsf	(51/8),(51)&7	;volatile
	line	128
	
i1l3078:	
;LED_188.c: 128: if(nums[tens] & 0x04)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(2)&7
	goto	u206_21
	goto	u206_20
u206_21:
	goto	i1l1385
u206_20:
	line	129
	
i1l3080:	
;LED_188.c: 129: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1385:	
	bsf	(52/8),(52)&7	;volatile
	line	130
	
i1l1386:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan2
	__end_of_Display_Scan2:
	signat	_Display_Scan2,89
	global	_Display_Scan1

;; *************** function _Display_Scan1 *****************
;; Defined at:
;;		line 105 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, fsr0l, fsr0h, status,2, status,0
;; Tracked objects:
;;		On entry : 100/100
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
psect	text26,local,class=CODE,delta=2,merge=1,group=0
	line	105
global __ptext26
__ptext26:	;psect for function _Display_Scan1
psect	text26
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	105
	global	__size_of_Display_Scan1
	__size_of_Display_Scan1	equ	__end_of_Display_Scan1-_Display_Scan1
	
_Display_Scan1:	
;incstack = 0
	opt	stack 1
; Regs used in _Display_Scan1: [wreg-fsr0h+status,2+status,0]
	line	107
	
i1l3046:	
;LED_188.c: 107: TRISB0 = 0;RB0 = 0;;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(40/8),(40)&7	;volatile
	bcf	(48/8),(48)&7	;volatile
	line	108
	
i1l3048:	
;LED_188.c: 108: if(nums[unit] & 0x20)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(5)&7
	goto	u199_21
	goto	u199_20
u199_21:
	goto	i1l1375
u199_20:
	line	109
	
i1l3050:	
;LED_188.c: 109: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1375:	
	bsf	(49/8),(49)&7	;volatile
	line	110
	
i1l3052:	
;LED_188.c: 110: if(nums[unit] & 0x08)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u200_21
	goto	u200_20
u200_21:
	goto	i1l1376
u200_20:
	line	111
	
i1l3054:	
;LED_188.c: 111: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1376:	
	bsf	(50/8),(50)&7	;volatile
	line	112
	
i1l3056:	
;LED_188.c: 112: if(nums[unit] & 0x02)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(1)&7
	goto	u201_21
	goto	u201_20
u201_21:
	goto	i1l1377
u201_20:
	line	113
	
i1l3058:	
;LED_188.c: 113: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1377:	
	bsf	(51/8),(51)&7	;volatile
	line	114
	
i1l3060:	
;LED_188.c: 114: if(nums[unit] &0x01)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u202_21
	goto	u202_20
u202_21:
	goto	i1l1378
u202_20:
	line	115
	
i1l3062:	
;LED_188.c: 115: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1378:	
	bsf	(52/8),(52)&7	;volatile
	line	116
	
i1l1379:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan1
	__end_of_Display_Scan1:
	signat	_Display_Scan1,89
	global	_Charge_num

;; *************** function _Charge_num *****************
;; Defined at:
;;		line 11 in file "C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  hundred         1    9[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/100
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
psect	text27,local,class=CODE,delta=2,merge=1,group=0
	line	11
global __ptext27
__ptext27:	;psect for function _Charge_num
psect	text27
	file	"C:\Users\86135\Desktop\项目实践\project\SC8F072_Pwm_Demo\LED_188.c"
	line	11
	global	__size_of_Charge_num
	__size_of_Charge_num	equ	__end_of_Charge_num-_Charge_num
	
_Charge_num:	
;incstack = 0
	opt	stack 1
; Regs used in _Charge_num: [wreg+status,2+status,0+pclath+cstack]
	line	13
	
i1l3376:	
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
	movwf	(_tens)	;volatile
	line	15
;LED_188.c: 15: unit = (unsigned char)(power_percent % 10);
	movlw	low(0Ah)
	movwf	(___lbmod@divisor)
	movf	(_power_percent),w	;volatile
	fcall	___lbmod
	movwf	(_unit)	;volatile
	line	16
	
i1l3378:	
;LED_188.c: 16: if(hundred)
	movf	((Charge_num@hundred)),w
	btfsc	status,2
	goto	u238_21
	goto	u238_20
u238_21:
	goto	i1l3382
u238_20:
	line	18
	
i1l3380:	
;LED_188.c: 17: {
;LED_188.c: 18: hundreds = 4;
	movlw	low(04h)
	movwf	(_hundreds)	;volatile
	line	19
;LED_188.c: 19: }
	goto	i1l1354
	line	22
	
i1l3382:	
;LED_188.c: 20: else
;LED_188.c: 21: {
;LED_188.c: 22: hundreds = 2;
	movlw	low(02h)
	movwf	(_hundreds)	;volatile
	line	24
	
i1l1354:	
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
psect	text28,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbmod.c"
	line	4
global __ptext28
__ptext28:	;psect for function ___lbmod
psect	text28
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbmod.c"
	line	4
	global	__size_of___lbmod
	__size_of___lbmod	equ	__end_of___lbmod-___lbmod
	
___lbmod:	
;incstack = 0
	opt	stack 1
; Regs used in ___lbmod: [wreg+status,2+status,0]
;___lbmod@dividend stored from wreg
	movwf	(___lbmod@dividend)
	line	9
	
i1l3228:	
	movlw	low(08h)
	movwf	(___lbmod@counter)
	line	10
	
i1l3230:	
	clrf	(___lbmod@rem)
	line	12
	
i1l3232:	
	movf	(___lbmod@dividend),w
	movwf	(??___lbmod+0)+0
	movlw	07h
u232_25:
	clrc
	rrf	(??___lbmod+0)+0,f
	addlw	-1
	skipz
	goto	u232_25
	clrc
	rlf	(___lbmod@rem),w
	iorwf	0+(??___lbmod+0)+0,w
	movwf	(___lbmod@rem)
	line	13
	
i1l3234:	
	clrc
	rlf	(___lbmod@dividend),f
	line	14
	
i1l3236:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),w
	skipc
	goto	u233_21
	goto	u233_20
u233_21:
	goto	i1l3240
u233_20:
	line	15
	
i1l3238:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),f
	line	16
	
i1l3240:	
	decfsz	(___lbmod@counter),f
	goto	u234_21
	goto	u234_20
u234_21:
	goto	i1l3232
u234_20:
	line	17
	
i1l3242:	
	movf	(___lbmod@rem),w
	line	18
	
i1l1693:	
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
psect	text29,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbdiv.c"
	line	4
global __ptext29
__ptext29:	;psect for function ___lbdiv
psect	text29
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbdiv.c"
	line	4
	global	__size_of___lbdiv
	__size_of___lbdiv	equ	__end_of___lbdiv-___lbdiv
	
___lbdiv:	
;incstack = 0
	opt	stack 1
; Regs used in ___lbdiv: [wreg+status,2+status,0]
;___lbdiv@dividend stored from wreg
	movwf	(___lbdiv@dividend)
	line	9
	
i1l3204:	
	clrf	(___lbdiv@quotient)
	line	10
	
i1l3206:	
	movf	((___lbdiv@divisor)),w
	btfsc	status,2
	goto	u228_21
	goto	u228_20
u228_21:
	goto	i1l3224
u228_20:
	line	11
	
i1l3208:	
	clrf	(___lbdiv@counter)
	incf	(___lbdiv@counter),f
	line	12
	goto	i1l3212
	
i1l1682:	
	line	13
	clrc
	rlf	(___lbdiv@divisor),f
	line	14
	
i1l3210:	
	incf	(___lbdiv@counter),f
	line	12
	
i1l3212:	
	btfss	(___lbdiv@divisor),(7)&7
	goto	u229_21
	goto	u229_20
u229_21:
	goto	i1l1682
u229_20:
	line	16
	
i1l1684:	
	line	17
	clrc
	rlf	(___lbdiv@quotient),f
	line	18
	
i1l3214:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),w
	skipc
	goto	u230_21
	goto	u230_20
u230_21:
	goto	i1l3220
u230_20:
	line	19
	
i1l3216:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),f
	line	20
	
i1l3218:	
	bsf	(___lbdiv@quotient)+(0/8),(0)&7
	line	22
	
i1l3220:	
	clrc
	rrf	(___lbdiv@divisor),f
	line	23
	
i1l3222:	
	decfsz	(___lbdiv@counter),f
	goto	u231_21
	goto	u231_20
u231_21:
	goto	i1l1684
u231_20:
	line	25
	
i1l3224:	
	movf	(___lbdiv@quotient),w
	line	26
	
i1l1687:	
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
