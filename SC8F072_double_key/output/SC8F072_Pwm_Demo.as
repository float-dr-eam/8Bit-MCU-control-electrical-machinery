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
	FNCALL	_Button_response,_Set_AllPin_INPUT
	FNCALL	_Button_response,_Set_PWM
	FNCALL	_Button_response,___awmod
	FNCALL	_Set_PWM,___awdiv
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
	FNCALL	_Isr_Timer,i1_Set_PWM
	FNCALL	i1_Set_PWM,i1___awdiv
	FNCALL	i1_Set_PWM,i1___wmul
	FNCALL	_Uncharge_num,___lbdiv
	FNCALL	_Uncharge_num,___lbmod
	FNCALL	_Display,_Display_Scan1
	FNCALL	_Display,_Display_Scan2
	FNCALL	_Display,_Display_Scan3
	FNCALL	_Display,_Display_Scan4
	FNCALL	_Display,_Display_Scan5
	FNCALL	_Display,i1_Set_AllPin_INPUT
	FNCALL	_Charge_num,___lbdiv
	FNCALL	_Charge_num,___lbmod
	FNCALL	intlevel1,_Isr_Timer
	global	intlevel1
	FNROOT	intlevel1
	global	_unit
	global	_tens
	global	_hundreds
	global	_nums
	global	_num_hund
psect	idataBANK0,class=CODE,space=0,delta=2,noexec
global __pidataBANK0
__pidataBANK0:
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	6

;initializer for _unit
	retlw	02h
	line	5

;initializer for _tens
	retlw	04h
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
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	37
_duty_steps:
	retlw	042h
	retlw	049h
	retlw	055h
	retlw	05Bh
	retlw	061h
	retlw	low(0)
	global __end_of_duty_steps
__end_of_duty_steps:
	global	_duty_steps
	global	_LED_delay
	global	_long_press_counter
	global	Display@scan_cnt
	global	_T_flag
	global	_button_lflag
	global	_button_sflag
	global	_debounce_counter
	global	_pwm_duty
	global	_ADC_Flag
	global	_power_percent
	global	_test_adc
	global	_Time_delay
	global	_ADC_delay
	global	_power_ad
	global	_LED_flag
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
psect	bssBANK0,class=BANK0,space=1,noexec
global __pbssBANK0
__pbssBANK0:
_LED_delay:
       ds      2

_long_press_counter:
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

_pwm_duty:
       ds      1

_ADC_Flag:
       ds      1

_power_percent:
       ds      1

_test_adc:
       ds      1

psect	dataBANK0,class=BANK0,space=1,noexec
global __pdataBANK0
__pdataBANK0:
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	6
_unit:
       ds      1

psect	dataBANK0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	5
_tens:
       ds      1

psect	dataBANK0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	4
_hundreds:
       ds      1

psect	bssBANK1,class=BANK1,space=1,noexec
global __pbssBANK1
__pbssBANK1:
_Time_delay:
       ds      2

_ADC_delay:
       ds      2

_power_ad:
       ds      2

_LED_flag:
       ds      1

_adresult:
       ds      2

psect	dataBANK1,class=BANK1,space=1,noexec
global __pdataBANK1
__pdataBANK1:
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	73
_nums:
       ds      12

psect	dataBANK1
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
	fcall	__pidataBANK0+2		;fetch initializer
	movwf	__pdataBANK0+2&07fh		
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
	movlw	low((__pbssBANK1)+09h)
	fcall	clear_ram0
; Clear objects allocated to BANK0
psect cinit,class=CODE,delta=2,merge=1
	movlw	low(__pbssBANK0)
	movwf	fsr
	movlw	low((__pbssBANK0)+0Dh)
	fcall	clear_ram0
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
	global	___fttol@sign1
___fttol@sign1:	; 1 bytes @ 0x0
	ds	1
	global	___fttol@lval
___fttol@lval:	; 4 bytes @ 0x1
	ds	4
	global	___fttol@exp1
___fttol@exp1:	; 1 bytes @ 0x5
	ds	1
	global	ADC_read@power_temp
ADC_read@power_temp:	; 4 bytes @ 0x6
	ds	4
psect	cstackCOMMON,class=COMMON,space=1,noexec
global __pcstackCOMMON
__pcstackCOMMON:
?_Init_System:	; 1 bytes @ 0x0
?_Led_Gpio_Init:	; 1 bytes @ 0x0
?_PWM_Init:	; 1 bytes @ 0x0
?_Button_response:	; 1 bytes @ 0x0
?_ADC_read:	; 1 bytes @ 0x0
?_Motor_num:	; 1 bytes @ 0x0
?_Set_AllPin_INPUT:	; 1 bytes @ 0x0
?_Charge_num:	; 1 bytes @ 0x0
?_Uncharge_num:	; 1 bytes @ 0x0
?_Display:	; 1 bytes @ 0x0
??_Display:	; 1 bytes @ 0x0
?_main:	; 1 bytes @ 0x0
?_Isr_Timer:	; 1 bytes @ 0x0
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
?i1_Set_AllPin_INPUT:	; 1 bytes @ 0x0
??i1_Set_AllPin_INPUT:	; 1 bytes @ 0x0
	global	?i1___wmul
?i1___wmul:	; 2 bytes @ 0x0
	global	___lbmod@divisor
___lbmod@divisor:	; 1 bytes @ 0x0
	global	i1___wmul@multiplier
i1___wmul@multiplier:	; 2 bytes @ 0x0
	ds	1
??___lbmod:	; 1 bytes @ 0x1
	ds	1
	global	___lbmod@dividend
___lbmod@dividend:	; 1 bytes @ 0x2
	global	i1___wmul@multiplicand
i1___wmul@multiplicand:	; 2 bytes @ 0x2
	ds	1
	global	___lbmod@counter
___lbmod@counter:	; 1 bytes @ 0x3
	ds	1
??i1___wmul:	; 1 bytes @ 0x4
	global	___lbmod@rem
___lbmod@rem:	; 1 bytes @ 0x4
	global	i1___wmul@product
i1___wmul@product:	; 2 bytes @ 0x4
	ds	1
?___lbdiv:	; 1 bytes @ 0x5
	global	___lbdiv@divisor
___lbdiv@divisor:	; 1 bytes @ 0x5
	ds	1
??___lbdiv:	; 1 bytes @ 0x6
	global	?i1___awdiv
?i1___awdiv:	; 2 bytes @ 0x6
	global	___lbdiv@dividend
___lbdiv@dividend:	; 1 bytes @ 0x6
	global	i1___awdiv@divisor
i1___awdiv@divisor:	; 2 bytes @ 0x6
	ds	1
	global	___lbdiv@counter
___lbdiv@counter:	; 1 bytes @ 0x7
	ds	1
	global	___lbdiv@quotient
___lbdiv@quotient:	; 1 bytes @ 0x8
	global	i1___awdiv@dividend
i1___awdiv@dividend:	; 2 bytes @ 0x8
	ds	1
??_Charge_num:	; 1 bytes @ 0x9
??_Uncharge_num:	; 1 bytes @ 0x9
	global	Charge_num@hundred
Charge_num@hundred:	; 1 bytes @ 0x9
	global	Uncharge_num@hundred
Uncharge_num@hundred:	; 1 bytes @ 0x9
	ds	1
??i1___awdiv:	; 1 bytes @ 0xA
	global	i1___awdiv@counter
i1___awdiv@counter:	; 1 bytes @ 0xA
	ds	1
	global	i1___awdiv@sign
i1___awdiv@sign:	; 1 bytes @ 0xB
	ds	1
	global	i1___awdiv@quotient
i1___awdiv@quotient:	; 2 bytes @ 0xC
	ds	2
??i1_Set_PWM:	; 1 bytes @ 0xE
psect	cstackBANK0,class=BANK0,space=1,noexec
global __pcstackBANK0
__pcstackBANK0:
?i1_Set_PWM:	; 1 bytes @ 0x0
	global	i1Set_PWM@duty
i1Set_PWM@duty:	; 1 bytes @ 0x0
	ds	1
	global	i1Set_PWM@channel
i1Set_PWM@channel:	; 1 bytes @ 0x1
	ds	1
	global	i1Set_PWM@pulse_width
i1Set_PWM@pulse_width:	; 2 bytes @ 0x2
	ds	2
??_Isr_Timer:	; 1 bytes @ 0x4
	ds	4
??_Init_System:	; 1 bytes @ 0x8
??_Led_Gpio_Init:	; 1 bytes @ 0x8
??_PWM_Init:	; 1 bytes @ 0x8
??_Motor_num:	; 1 bytes @ 0x8
??_Set_AllPin_INPUT:	; 1 bytes @ 0x8
?_ADC_Sample:	; 1 bytes @ 0x8
	global	?___wmul
?___wmul:	; 2 bytes @ 0x8
	global	?___awmod
?___awmod:	; 2 bytes @ 0x8
	global	?___ftpack
?___ftpack:	; 3 bytes @ 0x8
	global	ADC_Sample@adldo
ADC_Sample@adldo:	; 1 bytes @ 0x8
	global	___wmul@multiplier
___wmul@multiplier:	; 2 bytes @ 0x8
	global	___awmod@divisor
___awmod@divisor:	; 2 bytes @ 0x8
	global	___ftpack@arg
___ftpack@arg:	; 3 bytes @ 0x8
	ds	1
??_ADC_Sample:	; 1 bytes @ 0x9
	ds	1
	global	___wmul@multiplicand
___wmul@multiplicand:	; 2 bytes @ 0xA
	global	___awmod@dividend
___awmod@dividend:	; 2 bytes @ 0xA
	ds	1
	global	___ftpack@exp
___ftpack@exp:	; 1 bytes @ 0xB
	ds	1
??___wmul:	; 1 bytes @ 0xC
??___awmod:	; 1 bytes @ 0xC
	global	___awmod@counter
___awmod@counter:	; 1 bytes @ 0xC
	global	___ftpack@sign
___ftpack@sign:	; 1 bytes @ 0xC
	global	___wmul@product
___wmul@product:	; 2 bytes @ 0xC
	ds	1
??___ftpack:	; 1 bytes @ 0xD
	global	ADC_Sample@j
ADC_Sample@j:	; 1 bytes @ 0xD
	global	___awmod@sign
___awmod@sign:	; 1 bytes @ 0xD
	ds	1
	global	?___awdiv
?___awdiv:	; 2 bytes @ 0xE
	global	ADC_Sample@adch
ADC_Sample@adch:	; 1 bytes @ 0xE
	global	___awdiv@divisor
___awdiv@divisor:	; 2 bytes @ 0xE
	ds	1
	global	ADC_Sample@i
ADC_Sample@i:	; 1 bytes @ 0xF
	ds	1
	global	?___lwtoft
?___lwtoft:	; 3 bytes @ 0x10
	global	___awdiv@dividend
___awdiv@dividend:	; 2 bytes @ 0x10
	global	___lwtoft@c
___lwtoft@c:	; 2 bytes @ 0x10
	global	ADC_Sample@adsum
ADC_Sample@adsum:	; 4 bytes @ 0x10
	ds	2
??___awdiv:	; 1 bytes @ 0x12
	global	___awdiv@counter
___awdiv@counter:	; 1 bytes @ 0x12
	ds	1
??___lwtoft:	; 1 bytes @ 0x13
	global	?___ftadd
?___ftadd:	; 3 bytes @ 0x13
	global	___awdiv@sign
___awdiv@sign:	; 1 bytes @ 0x13
	global	___ftadd@f1
___ftadd@f1:	; 3 bytes @ 0x13
	ds	1
	global	ADC_Sample@admin
ADC_Sample@admin:	; 2 bytes @ 0x14
	global	___awdiv@quotient
___awdiv@quotient:	; 2 bytes @ 0x14
	ds	2
?_Set_PWM:	; 1 bytes @ 0x16
	global	Set_PWM@duty
Set_PWM@duty:	; 1 bytes @ 0x16
	global	ADC_Sample@admax
ADC_Sample@admax:	; 2 bytes @ 0x16
	global	___ftadd@f2
___ftadd@f2:	; 3 bytes @ 0x16
	ds	1
??_Set_PWM:	; 1 bytes @ 0x17
	global	Set_PWM@channel
Set_PWM@channel:	; 1 bytes @ 0x17
	ds	1
	global	Set_PWM@pulse_width
Set_PWM@pulse_width:	; 2 bytes @ 0x18
	global	ADC_Sample@ad_temp
ADC_Sample@ad_temp:	; 2 bytes @ 0x18
	ds	1
??___ftadd:	; 1 bytes @ 0x19
	ds	1
??_Button_response:	; 1 bytes @ 0x1A
	ds	2
	global	___ftadd@sign
___ftadd@sign:	; 1 bytes @ 0x1C
	ds	1
	global	___ftadd@exp2
___ftadd@exp2:	; 1 bytes @ 0x1D
	ds	1
	global	___ftadd@exp1
___ftadd@exp1:	; 1 bytes @ 0x1E
	ds	1
	global	?___ftdiv
?___ftdiv:	; 3 bytes @ 0x1F
	global	___ftdiv@f2
___ftdiv@f2:	; 3 bytes @ 0x1F
	ds	3
	global	___ftdiv@f1
___ftdiv@f1:	; 3 bytes @ 0x22
	ds	3
??___ftdiv:	; 1 bytes @ 0x25
	ds	3
	global	___ftdiv@cntr
___ftdiv@cntr:	; 1 bytes @ 0x28
	ds	1
	global	___ftdiv@f3
___ftdiv@f3:	; 3 bytes @ 0x29
	ds	3
	global	___ftdiv@exp
___ftdiv@exp:	; 1 bytes @ 0x2C
	ds	1
	global	___ftdiv@sign
___ftdiv@sign:	; 1 bytes @ 0x2D
	ds	1
	global	?___fttol
?___fttol:	; 4 bytes @ 0x2E
	global	___fttol@f1
___fttol@f1:	; 3 bytes @ 0x2E
	ds	4
??___fttol:	; 1 bytes @ 0x32
	ds	3
??_ADC_read:	; 1 bytes @ 0x35
	ds	1
??_main:	; 1 bytes @ 0x36
;!
;!Data Sizes:
;!    Strings     0
;!    Constant    6
;!    Data        20
;!    BSS         22
;!    Persistent  0
;!    Stack       0
;!
;!Auto Spaces:
;!    Space          Size  Autos    Used
;!    COMMON           14     14      14
;!    BANK0            80     54      70
;!    BANK1            80     10      36

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
;!    i1_Set_PWM->i1___awdiv
;!    i1___awdiv->i1___wmul
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
;!    _ADC_read->___fttol
;!    ___lwtoft->___ftpack
;!    ___fttol->___ftdiv
;!    ___ftdiv->___ftadd
;!    ___ftadd->___lwtoft
;!
;!Critical Paths under _Isr_Timer in BANK0
;!
;!    _Isr_Timer->i1_Set_PWM
;!
;!Critical Paths under _main in BANK1
;!
;!    _main->_ADC_read
;!    _ADC_read->___fttol
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
;! (0) _main                                                 0     0      0   12234
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
;! (1) _Button_response                                      1     1      0    2536
;!                                             26 BANK0      1     1      0
;!                          _Motor_num
;!                   _Set_AllPin_INPUT
;!                            _Set_PWM
;!                            ___awmod
;! ---------------------------------------------------------------------------------
;! (2) ___awmod                                              6     2      4     424
;!                                              8 BANK0      6     2      4
;! ---------------------------------------------------------------------------------
;! (2) _Set_PWM                                              4     3      1    2112
;!                                             22 BANK0      4     3      1
;!                            ___awdiv
;!                             ___wmul
;! ---------------------------------------------------------------------------------
;! (3) ___wmul                                               6     2      4     198
;!                                              8 BANK0      6     2      4
;! ---------------------------------------------------------------------------------
;! (3) ___awdiv                                              8     4      4     406
;!                                             14 BANK0      8     4      4
;!                             ___wmul (ARG)
;! ---------------------------------------------------------------------------------
;! (2) _Set_AllPin_INPUT                                     0     0      0       0
;! ---------------------------------------------------------------------------------
;! (2) _Motor_num                                            0     0      0       0
;! ---------------------------------------------------------------------------------
;! (1) _ADC_read                                             5     5      0    9698
;!                                             53 BANK0      1     1      0
;!                                              6 BANK1      4     4      0
;!                         _ADC_Sample
;!                            ___ftadd
;!                            ___ftdiv
;!                            ___fttol
;!                           ___lwtoft
;! ---------------------------------------------------------------------------------
;! (2) ___lwtoft                                             3     0      3    2169
;!                                             16 BANK0      3     0      3
;!                           ___ftpack
;! ---------------------------------------------------------------------------------
;! (2) ___fttol                                             13     9      4     501
;!                                             46 BANK0      7     3      4
;!                                              0 BANK1      6     6      0
;!                            ___ftadd (ARG)
;!                            ___ftdiv (ARG)
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftdiv                                             15     9      6    2694
;!                                             31 BANK0     15     9      6
;!                            ___ftadd (ARG)
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (2) ___ftadd                                             12     6      6    3453
;!                                             19 BANK0     12     6      6
;!                           ___ftpack
;!                           ___lwtoft (ARG)
;! ---------------------------------------------------------------------------------
;! (3) ___ftpack                                             8     3      5    2008
;!                                              8 BANK0      8     3      5
;! ---------------------------------------------------------------------------------
;! (2) _ADC_Sample                                          18    17      1     847
;!                                              8 BANK0     18    17      1
;! ---------------------------------------------------------------------------------
;! Estimated maximum stack depth 3
;! ---------------------------------------------------------------------------------
;! (Depth) Function   	        Calls       Base Space   Used Autos Params    Refs
;! ---------------------------------------------------------------------------------
;! (4) _Isr_Timer                                            4     4      0    2265
;!                                              4 BANK0      4     4      0
;!                         _Charge_num
;!                            _Display
;!                       _Uncharge_num
;!                          i1_Set_PWM
;! ---------------------------------------------------------------------------------
;! (5) i1_Set_PWM                                            4     3      1     729
;!                                              0 BANK0      4     3      1
;!                          i1___awdiv
;!                           i1___wmul
;! ---------------------------------------------------------------------------------
;! (6) i1___wmul                                             6     2      4     144
;!                                              0 COMMON     6     2      4
;! ---------------------------------------------------------------------------------
;! (6) i1___awdiv                                            8     4      4     352
;!                                              6 COMMON     8     4      4
;!                           i1___wmul (ARG)
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
;!                 i1_Set_AllPin_INPUT
;! ---------------------------------------------------------------------------------
;! (6) i1_Set_AllPin_INPUT                                   0     0      0       0
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
;!     _Set_AllPin_INPUT
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
;!     i1_Set_AllPin_INPUT
;!   _Uncharge_num
;!     ___lbdiv
;!       ___lbmod (ARG)
;!     ___lbmod
;!   i1_Set_PWM
;!     i1___awdiv
;!       i1___wmul (ARG)
;!     i1___wmul
;!

;! Address spaces:

;!Name               Size   Autos  Total    Cost      Usage
;!BANK1               50      A      24       6       45.0%
;!BITBANK1            50      0       0       5        0.0%
;!SFR1                 0      0       0       2        0.0%
;!BITSFR1              0      0       0       2        0.0%
;!BANK0               50     36      46       4       87.5%
;!BITBANK0            50      0       0       3        0.0%
;!SFR0                 0      0       0       1        0.0%
;!BITSFR0              0      0       0       1        0.0%
;!COMMON               E      E       E       1      100.0%
;!BITCOMMON            E      0       0       0        0.0%
;!CODE                 0      0       0       0        0.0%
;!DATA                 0      0      78       8        0.0%
;!ABS                  0      0      78       7        0.0%
;!NULL                 0      0       0       0        0.0%
;!STACK                0      0       0       2        0.0%

	global	_main

;; *************** function _main *****************
;; Defined at:
;;		line 56 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
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
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	56
global __pmaintext
__pmaintext:	;psect for function _main
psect	maintext
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	56
	global	__size_of_main
	__size_of_main	equ	__end_of_main-_main
	
_main:	
;incstack = 0
	opt	stack 2
; Regs used in _main: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	58
	
l3983:	
;SC8F072_Pwm_Demo.c: 58: Init_System();
	fcall	_Init_System
	line	59
	
l3985:	
;SC8F072_Pwm_Demo.c: 59: Led_Gpio_Init();
	fcall	_Led_Gpio_Init
	line	60
	
l3987:	
;SC8F072_Pwm_Demo.c: 60: PWM_Init();
	fcall	_PWM_Init
	line	61
;SC8F072_Pwm_Demo.c: 61: while(1)
	
l661:	
	line	63
# 63 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	line	64
	
l3989:	
;SC8F072_Pwm_Demo.c: 64: Button_response();
	fcall	_Button_response
	line	65
	
l3991:	
;SC8F072_Pwm_Demo.c: 65: if(ADC_Flag)
	bcf	status, 5	;RP0=0, select bank0
	movf	((_ADC_Flag)),w	;volatile
	btfsc	status,2
	goto	u3191
	goto	u3190
u3191:
	goto	l662
u3190:
	line	67
	
l3993:	
;SC8F072_Pwm_Demo.c: 66: {
;SC8F072_Pwm_Demo.c: 67: ADC_read();
	fcall	_ADC_read
	line	68
	
l662:	
	line	69
# 69 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	maintext
	goto	l661
	global	start
	ljmp	start
	opt stack 0
	line	71
GLOBAL	__end_of_main
	__end_of_main:
	signat	_main,89
	global	_PWM_Init

;; *************** function _PWM_Init *****************
;; Defined at:
;;		line 132 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
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
	line	132
global __ptext1
__ptext1:	;psect for function _PWM_Init
psect	text1
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	132
	global	__size_of_PWM_Init
	__size_of_PWM_Init	equ	__end_of_PWM_Init-_PWM_Init
	
_PWM_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _PWM_Init: [wreg+status,2]
	line	134
	
l3367:	
;SC8F072_Pwm_Demo.c: 134: PWMCON1 = 0B11000000;
	movlw	low(0C0h)
	movwf	(22)	;volatile
	line	135
;SC8F072_Pwm_Demo.c: 135: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	136
;SC8F072_Pwm_Demo.c: 136: PWMTL = 0XFF;
	movlw	low(0FFh)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(23)	;volatile
	line	137
;SC8F072_Pwm_Demo.c: 137: PWMT4L = 0XFF;
	movlw	low(0FFh)
	movwf	(28)	;volatile
	line	138
	
l3369:	
;SC8F072_Pwm_Demo.c: 138: PWMTH = 0X00;
	clrf	(24)	;volatile
	line	143
	
l3371:	
;SC8F072_Pwm_Demo.c: 143: PWMD0L = 0X00;
	clrf	(25)	;volatile
	line	146
	
l3373:	
;SC8F072_Pwm_Demo.c: 146: PWMD1L = 0X00;
	clrf	(26)	;volatile
	line	147
	
l3375:	
;SC8F072_Pwm_Demo.c: 147: PWMD01H = 0X00;
	clrf	(30)	;volatile
	line	150
	
l3377:	
;SC8F072_Pwm_Demo.c: 150: PWMD2L = 0X00;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(155)^080h	;volatile
	line	152
	
l3379:	
;SC8F072_Pwm_Demo.c: 152: PWMD23H = 0X00;
	clrf	(158)^080h	;volatile
	line	154
	
l3381:	
;SC8F072_Pwm_Demo.c: 154: PWMD4L = 0X00;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(27)	;volatile
	line	170
	
l3383:	
;SC8F072_Pwm_Demo.c: 170: PWMCON0 = 0X17;
	movlw	low(017h)
	movwf	(21)	;volatile
	line	171
;SC8F072_Pwm_Demo.c: 171: PWMCON2 =0X00;
	clrf	(29)	;volatile
	line	173
	
l671:	
	return
	opt stack 0
GLOBAL	__end_of_PWM_Init
	__end_of_PWM_Init:
	signat	_PWM_Init,89
	global	_Led_Gpio_Init

;; *************** function _Led_Gpio_Init *****************
;; Defined at:
;;		line 76 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	76
global __ptext2
__ptext2:	;psect for function _Led_Gpio_Init
psect	text2
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	76
	global	__size_of_Led_Gpio_Init
	__size_of_Led_Gpio_Init	equ	__end_of_Led_Gpio_Init-_Led_Gpio_Init
	
_Led_Gpio_Init:	
;incstack = 0
	opt	stack 4
; Regs used in _Led_Gpio_Init: []
	line	78
	
l3365:	
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
	
l1376:	
	return
	opt stack 0
GLOBAL	__end_of_Led_Gpio_Init
	__end_of_Led_Gpio_Init:
	signat	_Led_Gpio_Init,89
	global	_Init_System

;; *************** function _Init_System *****************
;; Defined at:
;;		line 81 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
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
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	81
global __ptext3
__ptext3:	;psect for function _Init_System
psect	text3
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	81
	global	__size_of_Init_System
	__size_of_Init_System	equ	__end_of_Init_System-_Init_System
	
_Init_System:	
;incstack = 0
	opt	stack 4
; Regs used in _Init_System: [wreg+status,2]
	line	83
	
l3317:	
# 83 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	84
# 84 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text3
	line	85
	
l3319:	
;SC8F072_Pwm_Demo.c: 85: INTCON = 0;
	clrf	(11)	;volatile
	line	86
	
l3321:	
;SC8F072_Pwm_Demo.c: 86: OSCCON = 0X72;
	movlw	low(072h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(20)	;volatile
	line	87
	
l3323:	
;SC8F072_Pwm_Demo.c: 87: OPTION_REG = 0B00000100;
	movlw	low(04h)
	movwf	(1)	;volatile
	line	88
# 88 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
psect	text3
	line	90
;SC8F072_Pwm_Demo.c: 90: WPUA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(136)^080h	;volatile
	line	91
;SC8F072_Pwm_Demo.c: 91: WPUB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(8)	;volatile
	line	92
;SC8F072_Pwm_Demo.c: 92: WPDA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(135)^080h	;volatile
	line	93
;SC8F072_Pwm_Demo.c: 93: WPDB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(7)	;volatile
	line	94
;SC8F072_Pwm_Demo.c: 94: TRISA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(133)^080h	;volatile
	line	95
;SC8F072_Pwm_Demo.c: 95: TRISB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(5)	;volatile
	line	96
;SC8F072_Pwm_Demo.c: 96: PORTA = 0B00000000;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(134)^080h	;volatile
	line	97
;SC8F072_Pwm_Demo.c: 97: PORTB = 0B00000000;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(6)	;volatile
	line	99
	
l3325:	
;SC8F072_Pwm_Demo.c: 99: TMR0 = 6;
	movlw	low(06h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(129)^080h	;volatile
	line	100
	
l3327:	
;SC8F072_Pwm_Demo.c: 100: T0IF = 0;
	bcf	(90/8),(90)&7	;volatile
	line	101
	
l3329:	
;SC8F072_Pwm_Demo.c: 101: T0IE = 1;
	bsf	(93/8),(93)&7	;volatile
	line	102
	
l3331:	
;SC8F072_Pwm_Demo.c: 102: GIE = 1;
	bsf	(95/8),(95)&7	;volatile
	line	105
	
l3333:	
;SC8F072_Pwm_Demo.c: 105: PR2 = 249;
	movlw	low(0F9h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(17)	;volatile
	line	106
	
l3335:	
;SC8F072_Pwm_Demo.c: 106: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	107
	
l3337:	
;SC8F072_Pwm_Demo.c: 107: TMR2IE = 1;
	bsf	(113/8),(113)&7	;volatile
	line	108
	
l3339:	
;SC8F072_Pwm_Demo.c: 108: T2CON = 0B00000111;
	movlw	low(07h)
	movwf	(19)	;volatile
	line	112
	
l3341:	
;SC8F072_Pwm_Demo.c: 112: WPUB = 0B00100000;
	movlw	low(020h)
	movwf	(8)	;volatile
	line	113
	
l3343:	
;SC8F072_Pwm_Demo.c: 113: TRISB= 0B00100000;
	movlw	low(020h)
	movwf	(5)	;volatile
	line	114
	
l3345:	
;SC8F072_Pwm_Demo.c: 114: IOCB = 0B00100000;
	movlw	low(020h)
	movwf	(9)	;volatile
	line	115
	
l3347:	
;SC8F072_Pwm_Demo.c: 115: RBIE = 1;
	bsf	(91/8),(91)&7	;volatile
	line	116
	
l3349:	
;SC8F072_Pwm_Demo.c: 116: PORTB;
	movf	(6),w	;volatile
	line	120
	
l3351:	
;SC8F072_Pwm_Demo.c: 120: WPUA = 0B00101000;
	movlw	low(028h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(136)^080h	;volatile
	line	121
	
l3353:	
;SC8F072_Pwm_Demo.c: 121: TRISA= 0B00101000;
	movlw	low(028h)
	movwf	(133)^080h	;volatile
	line	122
	
l3355:	
;SC8F072_Pwm_Demo.c: 122: IOCA = 0B00101000;
	movlw	low(028h)
	movwf	(137)^080h	;volatile
	line	123
	
l3357:	
;SC8F072_Pwm_Demo.c: 123: RAIE = 1;
	bcf	status, 5	;RP0=0, select bank0
	bsf	(115/8),(115)&7	;volatile
	line	125
	
l3359:	
;SC8F072_Pwm_Demo.c: 125: RAIF = 0;
	bcf	(107/8),(107)&7	;volatile
	line	126
	
l3361:	
;SC8F072_Pwm_Demo.c: 126: PORTA;
	bsf	status, 5	;RP0=1, select bank1
	movf	(134)^080h,w	;volatile
	line	128
	
l3363:	
;SC8F072_Pwm_Demo.c: 128: INTCON = 0xE8;
	movlw	low(0E8h)
	movwf	(11)	;volatile
	line	130
	
l668:	
	return
	opt stack 0
GLOBAL	__end_of_Init_System
	__end_of_Init_System:
	signat	_Init_System,89
	global	_Button_response

;; *************** function _Button_response *****************
;; Defined at:
;;		line 310 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
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
;;		_Set_AllPin_INPUT
;;		_Set_PWM
;;		___awmod
;; This function is called by:
;;		_main
;; This function uses a non-reentrant model
;;
psect	text4,local,class=CODE,delta=2,merge=1,group=0
	line	310
global __ptext4
__ptext4:	;psect for function _Button_response
psect	text4
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	310
	global	__size_of_Button_response
	__size_of_Button_response	equ	__end_of_Button_response-_Button_response
	
_Button_response:	
;incstack = 0
	opt	stack 2
; Regs used in _Button_response: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	312
	
l3385:	
;SC8F072_Pwm_Demo.c: 312: if (button_sflag)
	bcf	status, 5	;RP0=0, select bank0
	movf	((_button_sflag)),w	;volatile
	btfsc	status,2
	goto	u2371
	goto	u2370
u2371:
	goto	l3413
u2370:
	line	314
	
l3387:	
;SC8F072_Pwm_Demo.c: 313: {
;SC8F072_Pwm_Demo.c: 314: TRISA = 0B00101000;
	movlw	low(028h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	315
;SC8F072_Pwm_Demo.c: 315: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_Button_response+0)+0),f
	u3207:
decfsz	(??_Button_response+0)+0,f
	goto	u3207
	nop2
opt asmopt_pop

	line	316
	
l3389:	
;SC8F072_Pwm_Demo.c: 316: button_sflag = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_button_sflag)	;volatile
	line	317
;SC8F072_Pwm_Demo.c: 317: switch (pwm_duty)
	goto	l3405
	line	320
	
l3391:	
;SC8F072_Pwm_Demo.c: 320: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	321
;SC8F072_Pwm_Demo.c: 321: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	322
;SC8F072_Pwm_Demo.c: 322: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	323
;SC8F072_Pwm_Demo.c: 323: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	324
;SC8F072_Pwm_Demo.c: 324: break;
	goto	l3407
	line	326
	
l3393:	
;SC8F072_Pwm_Demo.c: 326: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	327
;SC8F072_Pwm_Demo.c: 327: Set_PWM(1, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	328
;SC8F072_Pwm_Demo.c: 328: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	329
;SC8F072_Pwm_Demo.c: 329: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	330
;SC8F072_Pwm_Demo.c: 330: break;
	goto	l3407
	line	332
	
l3395:	
;SC8F072_Pwm_Demo.c: 332: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	333
;SC8F072_Pwm_Demo.c: 333: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	334
;SC8F072_Pwm_Demo.c: 334: Set_PWM(2, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	335
;SC8F072_Pwm_Demo.c: 335: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	336
;SC8F072_Pwm_Demo.c: 336: break;
	goto	l3407
	line	338
	
l3397:	
;SC8F072_Pwm_Demo.c: 338: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	339
;SC8F072_Pwm_Demo.c: 339: Set_PWM(1, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	340
;SC8F072_Pwm_Demo.c: 340: Set_PWM(2, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	341
;SC8F072_Pwm_Demo.c: 341: Set_PWM(4, duty_steps[pwm_duty]);
	bcf	status, 5	;RP0=0, select bank0
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	342
;SC8F072_Pwm_Demo.c: 342: break;
	goto	l3407
	line	344
	
l3399:	
;SC8F072_Pwm_Demo.c: 344: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	345
;SC8F072_Pwm_Demo.c: 345: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	346
;SC8F072_Pwm_Demo.c: 346: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	347
;SC8F072_Pwm_Demo.c: 347: Set_PWM(4, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	348
	
l3401:	
;SC8F072_Pwm_Demo.c: 348: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	349
;SC8F072_Pwm_Demo.c: 349: break;
	goto	l3407
	line	317
	
l3405:	
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
goto l3407
movlw high(S4085)
movwf pclath
	movlw low(S4085)
	addwf fsr,w
	movwf pc
psect	swtext1,local,class=CONST,delta=2
global __pswtext1
__pswtext1:
S4085:
	ljmp	l3391
	ljmp	l3393
	ljmp	l3395
	ljmp	l3397
	ljmp	l3399
psect	text4

	line	353
	
l3407:	
;SC8F072_Pwm_Demo.c: 353: Motor_num();
	fcall	_Motor_num
	line	354
;SC8F072_Pwm_Demo.c: 354: pwm_duty = (pwm_duty + 1) % 5;
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
	line	355
	
l3409:	
;SC8F072_Pwm_Demo.c: 355: Time_delay=2500;
	movlw	0C4h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_Time_delay)^080h	;volatile
	movlw	09h
	movwf	((_Time_delay)^080h)+1	;volatile
	line	356
	
l3411:	
;SC8F072_Pwm_Demo.c: 356: T_flag=1;
	movlw	low(01h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(_T_flag)	;volatile
	line	359
	
l3413:	
;SC8F072_Pwm_Demo.c: 358: }
;SC8F072_Pwm_Demo.c: 359: if (button_lflag)
	movf	((_button_lflag)),w	;volatile
	btfsc	status,2
	goto	u2381
	goto	u2380
u2381:
	goto	l719
u2380:
	line	361
	
l3415:	
;SC8F072_Pwm_Demo.c: 360: {
;SC8F072_Pwm_Demo.c: 361: button_lflag = 0;
	clrf	(_button_lflag)	;volatile
	line	362
	
l3417:	
;SC8F072_Pwm_Demo.c: 362: Set_PWM(0, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(Set_PWM@duty)
	movlw	low(0)
	fcall	_Set_PWM
	line	363
	
l3419:	
;SC8F072_Pwm_Demo.c: 363: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(01h)
	fcall	_Set_PWM
	line	364
	
l3421:	
;SC8F072_Pwm_Demo.c: 364: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(02h)
	fcall	_Set_PWM
	line	365
	
l3423:	
;SC8F072_Pwm_Demo.c: 365: Set_PWM(4, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(Set_PWM@duty)
	movlw	low(04h)
	fcall	_Set_PWM
	line	366
;SC8F072_Pwm_Demo.c: 366: pwm_duty =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_pwm_duty)	;volatile
	line	367
	
l3425:	
;SC8F072_Pwm_Demo.c: 367: TRISA = 0B00111111;
	movlw	low(03Fh)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(133)^080h	;volatile
	line	368
	
l3427:	
;SC8F072_Pwm_Demo.c: 368: T_flag=0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_T_flag)	;volatile
	line	369
	
l3429:	
;SC8F072_Pwm_Demo.c: 369: Set_AllPin_INPUT();
	fcall	_Set_AllPin_INPUT
	line	370
# 370 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
clrwdt ;# 
	line	371
# 371 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
stop ;# 
	line	372
# 372 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	373
# 373 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
psect	text4
	line	375
	
l719:	
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
;;  divisor         2    8[BANK0 ] int 
;;  dividend        2   10[BANK0 ] int 
;; Auto vars:     Size  Location     Type
;;  sign            1   13[BANK0 ] unsigned char 
;;  counter         1   12[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  2    8[BANK0 ] int 
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
	
l3017:	
	clrf	(___awmod@sign)
	line	14
	
l3019:	
	btfss	(___awmod@dividend+1),7
	goto	u1821
	goto	u1820
u1821:
	goto	l3025
u1820:
	line	15
	
l3021:	
	comf	(___awmod@dividend),f
	comf	(___awmod@dividend+1),f
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	line	16
	
l3023:	
	clrf	(___awmod@sign)
	incf	(___awmod@sign),f
	line	18
	
l3025:	
	btfss	(___awmod@divisor+1),7
	goto	u1831
	goto	u1830
u1831:
	goto	l3029
u1830:
	line	19
	
l3027:	
	comf	(___awmod@divisor),f
	comf	(___awmod@divisor+1),f
	incf	(___awmod@divisor),f
	skipnz
	incf	(___awmod@divisor+1),f
	line	20
	
l3029:	
	movf	((___awmod@divisor)),w
iorwf	((___awmod@divisor+1)),w
	btfsc	status,2
	goto	u1841
	goto	u1840
u1841:
	goto	l3045
u1840:
	line	21
	
l3031:	
	clrf	(___awmod@counter)
	incf	(___awmod@counter),f
	line	22
	goto	l3035
	line	23
	
l3033:	
	clrc
	rlf	(___awmod@divisor),f
	rlf	(___awmod@divisor+1),f
	line	24
	incf	(___awmod@counter),f
	line	22
	
l3035:	
	btfss	(___awmod@divisor+1),(15)&7
	goto	u1851
	goto	u1850
u1851:
	goto	l3033
u1850:
	line	27
	
l3037:	
	movf	(___awmod@divisor+1),w
	subwf	(___awmod@dividend+1),w
	skipz
	goto	u1865
	movf	(___awmod@divisor),w
	subwf	(___awmod@dividend),w
u1865:
	skipc
	goto	u1861
	goto	u1860
u1861:
	goto	l3041
u1860:
	line	28
	
l3039:	
	movf	(___awmod@divisor),w
	subwf	(___awmod@dividend),f
	movf	(___awmod@divisor+1),w
	skipc
	decf	(___awmod@dividend+1),f
	subwf	(___awmod@dividend+1),f
	line	29
	
l3041:	
	clrc
	rrf	(___awmod@divisor+1),f
	rrf	(___awmod@divisor),f
	line	30
	
l3043:	
	decfsz	(___awmod@counter),f
	goto	u1871
	goto	u1870
u1871:
	goto	l3037
u1870:
	line	32
	
l3045:	
	movf	((___awmod@sign)),w
	btfsc	status,2
	goto	u1881
	goto	u1880
u1881:
	goto	l3049
u1880:
	line	33
	
l3047:	
	comf	(___awmod@dividend),f
	comf	(___awmod@dividend+1),f
	incf	(___awmod@dividend),f
	skipnz
	incf	(___awmod@dividend+1),f
	line	34
	
l3049:	
	movf	(___awmod@dividend+1),w
	movwf	(?___awmod+1)
	movf	(___awmod@dividend),w
	movwf	(?___awmod)
	line	35
	
l1574:	
	return
	opt stack 0
GLOBAL	__end_of___awmod
	__end_of___awmod:
	signat	___awmod,8314
	global	_Set_PWM

;; *************** function _Set_PWM *****************
;; Defined at:
;;		line 183 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;  channel         1    wreg     unsigned char 
;;  duty            1   22[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  channel         1   23[BANK0 ] unsigned char 
;;  pulse_width     2   24[BANK0 ] unsigned short 
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
;;		___awdiv
;;		___wmul
;; This function is called by:
;;		_Button_response
;; This function uses a non-reentrant model
;;
psect	text6,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	183
global __ptext6
__ptext6:	;psect for function _Set_PWM
psect	text6
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	183
	global	__size_of_Set_PWM
	__size_of_Set_PWM	equ	__end_of_Set_PWM-_Set_PWM
	
_Set_PWM:	
;incstack = 0
	opt	stack 2
; Regs used in _Set_PWM: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;Set_PWM@channel stored from wreg
	movwf	(Set_PWM@channel)
	line	185
	
l2837:	
;SC8F072_Pwm_Demo.c: 185: unsigned short pulse_width = (duty * 255) / 100;
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
	movf	(1+(?___awdiv)),w
	movwf	(Set_PWM@pulse_width+1)
	movf	(0+(?___awdiv)),w
	movwf	(Set_PWM@pulse_width)
	line	186
;SC8F072_Pwm_Demo.c: 186: switch (channel)
	goto	l2851
	line	189
	
l2839:	
;SC8F072_Pwm_Demo.c: 189: PWMD0L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(25)	;volatile
	line	191
;SC8F072_Pwm_Demo.c: 191: break;
	goto	l682
	line	193
	
l2841:	
;SC8F072_Pwm_Demo.c: 193: PWMD1L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(26)	;volatile
	line	195
;SC8F072_Pwm_Demo.c: 195: break;
	goto	l682
	line	197
	
l2843:	
;SC8F072_Pwm_Demo.c: 197: PWMD2L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(155)^080h	;volatile
	line	199
;SC8F072_Pwm_Demo.c: 199: break;
	goto	l682
	line	201
	
l2845:	
;SC8F072_Pwm_Demo.c: 201: PWMD3L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(156)^080h	;volatile
	line	203
;SC8F072_Pwm_Demo.c: 203: break;
	goto	l682
	line	205
	
l2847:	
;SC8F072_Pwm_Demo.c: 205: PWMD4L = pulse_width & 0xFF;
	movf	(Set_PWM@pulse_width),w
	movwf	(27)	;volatile
	line	207
;SC8F072_Pwm_Demo.c: 207: break;
	goto	l682
	line	186
	
l2851:	
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
goto l682
movlw high(S4087)
movwf pclath
	movlw low(S4087)
	addwf fsr,w
	movwf pc
psect	swtext2,local,class=CONST,delta=2
global __pswtext2
__pswtext2:
S4087:
	ljmp	l2839
	ljmp	l2841
	ljmp	l2843
	ljmp	l2845
	ljmp	l2847
psect	text6

	line	211
	
l682:	
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
;;  multiplier      2    8[BANK0 ] unsigned int 
;;  multiplicand    2   10[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;  product         2   12[BANK0 ] unsigned int 
;; Return value:  Size  Location     Type
;;                  2    8[BANK0 ] unsigned int 
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
	
l2753:	
	clrf	(___wmul@product)
	clrf	(___wmul@product+1)
	line	45
	
l2755:	
	btfss	(___wmul@multiplier),(0)&7
	goto	u1321
	goto	u1320
u1321:
	goto	l2759
u1320:
	line	46
	
l2757:	
	movf	(___wmul@multiplicand),w
	addwf	(___wmul@product),f
	skipnc
	incf	(___wmul@product+1),f
	movf	(___wmul@multiplicand+1),w
	addwf	(___wmul@product+1),f
	line	47
	
l2759:	
	clrc
	rlf	(___wmul@multiplicand),f
	rlf	(___wmul@multiplicand+1),f
	line	48
	
l2761:	
	clrc
	rrf	(___wmul@multiplier+1),f
	rrf	(___wmul@multiplier),f
	line	49
	
l2763:	
	movf	((___wmul@multiplier)),w
iorwf	((___wmul@multiplier+1)),w
	btfss	status,2
	goto	u1331
	goto	u1330
u1331:
	goto	l2755
u1330:
	line	52
	
l2765:	
	movf	(___wmul@product+1),w
	movwf	(?___wmul+1)
	movf	(___wmul@product),w
	movwf	(?___wmul)
	line	53
	
l1431:	
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
;;  divisor         2   14[BANK0 ] int 
;;  dividend        2   16[BANK0 ] int 
;; Auto vars:     Size  Location     Type
;;  quotient        2   20[BANK0 ] int 
;;  sign            1   19[BANK0 ] unsigned char 
;;  counter         1   18[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  2   14[BANK0 ] int 
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
	
l2793:	
	clrf	(___awdiv@sign)
	line	15
	
l2795:	
	btfss	(___awdiv@divisor+1),7
	goto	u1421
	goto	u1420
u1421:
	goto	l2801
u1420:
	line	16
	
l2797:	
	comf	(___awdiv@divisor),f
	comf	(___awdiv@divisor+1),f
	incf	(___awdiv@divisor),f
	skipnz
	incf	(___awdiv@divisor+1),f
	line	17
	
l2799:	
	clrf	(___awdiv@sign)
	incf	(___awdiv@sign),f
	line	19
	
l2801:	
	btfss	(___awdiv@dividend+1),7
	goto	u1431
	goto	u1430
u1431:
	goto	l2807
u1430:
	line	20
	
l2803:	
	comf	(___awdiv@dividend),f
	comf	(___awdiv@dividend+1),f
	incf	(___awdiv@dividend),f
	skipnz
	incf	(___awdiv@dividend+1),f
	line	21
	
l2805:	
	movlw	low(01h)
	xorwf	(___awdiv@sign),f
	line	23
	
l2807:	
	clrf	(___awdiv@quotient)
	clrf	(___awdiv@quotient+1)
	line	24
	
l2809:	
	movf	((___awdiv@divisor)),w
iorwf	((___awdiv@divisor+1)),w
	btfsc	status,2
	goto	u1441
	goto	u1440
u1441:
	goto	l2829
u1440:
	line	25
	
l2811:	
	clrf	(___awdiv@counter)
	incf	(___awdiv@counter),f
	line	26
	goto	l2815
	line	27
	
l2813:	
	clrc
	rlf	(___awdiv@divisor),f
	rlf	(___awdiv@divisor+1),f
	line	28
	incf	(___awdiv@counter),f
	line	26
	
l2815:	
	btfss	(___awdiv@divisor+1),(15)&7
	goto	u1451
	goto	u1450
u1451:
	goto	l2813
u1450:
	line	31
	
l2817:	
	clrc
	rlf	(___awdiv@quotient),f
	rlf	(___awdiv@quotient+1),f
	line	32
	
l2819:	
	movf	(___awdiv@divisor+1),w
	subwf	(___awdiv@dividend+1),w
	skipz
	goto	u1465
	movf	(___awdiv@divisor),w
	subwf	(___awdiv@dividend),w
u1465:
	skipc
	goto	u1461
	goto	u1460
u1461:
	goto	l2825
u1460:
	line	33
	
l2821:	
	movf	(___awdiv@divisor),w
	subwf	(___awdiv@dividend),f
	movf	(___awdiv@divisor+1),w
	skipc
	decf	(___awdiv@dividend+1),f
	subwf	(___awdiv@dividend+1),f
	line	34
	
l2823:	
	bsf	(___awdiv@quotient)+(0/8),(0)&7
	line	36
	
l2825:	
	clrc
	rrf	(___awdiv@divisor+1),f
	rrf	(___awdiv@divisor),f
	line	37
	
l2827:	
	decfsz	(___awdiv@counter),f
	goto	u1471
	goto	u1470
u1471:
	goto	l2817
u1470:
	line	39
	
l2829:	
	movf	((___awdiv@sign)),w
	btfsc	status,2
	goto	u1481
	goto	u1480
u1481:
	goto	l2833
u1480:
	line	40
	
l2831:	
	comf	(___awdiv@quotient),f
	comf	(___awdiv@quotient+1),f
	incf	(___awdiv@quotient),f
	skipnz
	incf	(___awdiv@quotient+1),f
	line	41
	
l2833:	
	movf	(___awdiv@quotient+1),w
	movwf	(?___awdiv+1)
	movf	(___awdiv@quotient),w
	movwf	(?___awdiv)
	line	42
	
l1561:	
	return
	opt stack 0
GLOBAL	__end_of___awdiv
	__end_of___awdiv:
	signat	___awdiv,8314
	global	_Set_AllPin_INPUT

;; *************** function _Set_AllPin_INPUT *****************
;; Defined at:
;;		line 85 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_Button_response
;; This function uses a non-reentrant model
;;
psect	text9,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	85
global __ptext9
__ptext9:	;psect for function _Set_AllPin_INPUT
psect	text9
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	85
	global	__size_of_Set_AllPin_INPUT
	__size_of_Set_AllPin_INPUT	equ	__end_of_Set_AllPin_INPUT-_Set_AllPin_INPUT
	
_Set_AllPin_INPUT:	
;incstack = 0
	opt	stack 3
; Regs used in _Set_AllPin_INPUT: []
	line	87
	
l2933:	
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
	
l1379:	
	return
	opt stack 0
GLOBAL	__end_of_Set_AllPin_INPUT
	__end_of_Set_AllPin_INPUT:
	signat	_Set_AllPin_INPUT,89
	global	_Motor_num

;; *************** function _Motor_num *****************
;; Defined at:
;;		line 39 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text10,local,class=CODE,delta=2,merge=1,group=0
	line	39
global __ptext10
__ptext10:	;psect for function _Motor_num
psect	text10
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	39
	global	__size_of_Motor_num
	__size_of_Motor_num	equ	__end_of_Motor_num-_Motor_num
	
_Motor_num:	
;incstack = 0
	opt	stack 3
; Regs used in _Motor_num: [wreg+status,2+status,0]
	line	41
	
l2929:	
;LED_188.c: 41: hundreds =0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_hundreds)	;volatile
	line	42
;LED_188.c: 42: tens = 0;
	clrf	(_tens)	;volatile
	line	43
	
l2931:	
;LED_188.c: 43: unit = (unsigned char)(pwm_duty+1) ;
	movf	(_pwm_duty),w	;volatile
	addlw	01h
	movwf	(_unit)	;volatile
	line	44
	
l1369:	
	return
	opt stack 0
GLOBAL	__end_of_Motor_num
	__end_of_Motor_num:
	signat	_Motor_num,89
	global	_ADC_read

;; *************** function _ADC_read *****************
;; Defined at:
;;		line 291 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;		None
;; Auto vars:     Size  Location     Type
;;  power_temp      4    6[BANK1 ] volatile unsigned long 
;; Return value:  Size  Location     Type
;;                  1    wreg      void 
;; Registers used:
;;		wreg, status,2, status,0, pclath, cstack
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       4
;;      Temps:          0       1       0
;;      Totals:         0       1       4
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
psect	text11,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	291
global __ptext11
__ptext11:	;psect for function _ADC_read
psect	text11
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	291
	global	__size_of_ADC_read
	__size_of_ADC_read	equ	__end_of_ADC_read-_ADC_read
	
_ADC_read:	
;incstack = 0
	opt	stack 2
; Regs used in _ADC_read: [wreg+status,2+status,0+pclath+cstack]
	line	293
	
l3967:	
;SC8F072_Pwm_Demo.c: 293: test_adc = ADC_Sample(31, 0);
	clrf	(ADC_Sample@adldo)
	movlw	low(01Fh)
	fcall	_ADC_Sample
	movwf	(_test_adc)	;volatile
	line	295
	
l3969:	
;SC8F072_Pwm_Demo.c: 295: if (0xA5 == test_adc)
		movlw	165
	xorwf	((_test_adc)),w	;volatile
	btfss	status,2
	goto	u3181
	goto	u3180
u3181:
	goto	l3977
u3180:
	line	298
	
l3971:	
;SC8F072_Pwm_Demo.c: 296: {
;SC8F072_Pwm_Demo.c: 297: volatile unsigned long power_temp;
;SC8F072_Pwm_Demo.c: 298: power_temp = (unsigned long)(((4096UL*1.2*1000))/adresult);
	movlw	0x0
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
	bsf	status, 5	;RP0=1, select bank1
	movwf	(ADC_read@power_temp+3)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	(2+(?___fttol)),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(ADC_read@power_temp+2)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	(1+(?___fttol)),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(ADC_read@power_temp+1)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	(0+(?___fttol)),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(ADC_read@power_temp)^080h	;volatile

	line	299
	
l3973:	
;SC8F072_Pwm_Demo.c: 299: power_ad = (unsigned int)(power_temp);
	movf	(ADC_read@power_temp+1)^080h,w	;volatile
	movwf	(_power_ad+1)^080h	;volatile
	movf	(ADC_read@power_temp)^080h,w	;volatile
	movwf	(_power_ad)^080h	;volatile
	line	300
	
l3975:	
;SC8F072_Pwm_Demo.c: 300: power_percent = (unsigned char)((power_ad-(1000UL*2.8))/(10UL*1.4));
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
	line	301
;SC8F072_Pwm_Demo.c: 301: }
	goto	l3981
	line	304
	
l3977:	
;SC8F072_Pwm_Demo.c: 302: else
;SC8F072_Pwm_Demo.c: 303: {
;SC8F072_Pwm_Demo.c: 304: ADCON0 = 0;
	bsf	status, 5	;RP0=1, select bank1
	clrf	(149)^080h	;volatile
	line	305
;SC8F072_Pwm_Demo.c: 305: ADCON1 = 0;
	clrf	(150)^080h	;volatile
	line	306
	
l3979:	
;SC8F072_Pwm_Demo.c: 306: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_ADC_read+0)+0),f
	u3217:
decfsz	(??_ADC_read+0)+0,f
	goto	u3217
	nop2
opt asmopt_pop

	line	308
	
l3981:	
;SC8F072_Pwm_Demo.c: 307: }
;SC8F072_Pwm_Demo.c: 308: ADC_Flag=0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(_ADC_Flag)	;volatile
	line	309
	
l706:	
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
;;  c               2   16[BANK0 ] unsigned int 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3   16[BANK0 ] float 
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
psect	text12,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
	line	28
global __ptext12
__ptext12:	;psect for function ___lwtoft
psect	text12
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lwtoft.c"
	line	28
	global	__size_of___lwtoft
	__size_of___lwtoft	equ	__end_of___lwtoft-___lwtoft
	
___lwtoft:	
;incstack = 0
	opt	stack 2
; Regs used in ___lwtoft: [wreg+status,2+status,0+pclath+cstack]
	line	30
	
l3963:	
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
	
l1783:	
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
;;  f1              3   46[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  lval            4    1[BANK1 ] unsigned long 
;;  exp1            1    5[BANK1 ] unsigned char 
;;  sign1           1    0[BANK1 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  4   46[BANK0 ] long 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       4       0
;;      Locals:         0       0       6
;;      Temps:          0       3       0
;;      Totals:         0       7       6
;;Total ram usage:       13 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    3
;; This function calls:
;;		Nothing
;; This function is called by:
;;		_ADC_read
;; This function uses a non-reentrant model
;;
psect	text13,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
	line	44
global __ptext13
__ptext13:	;psect for function ___fttol
psect	text13
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\fttol.c"
	line	44
	global	__size_of___fttol
	__size_of___fttol	equ	__end_of___fttol-___fttol
	
___fttol:	
;incstack = 0
	opt	stack 3
; Regs used in ___fttol: [wreg+status,2+status,0]
	line	49
	
l3923:	
	movf	(___fttol@f1),w
	movwf	((??___fttol+0)+0)
	movf	(___fttol@f1+1),w
	movwf	((??___fttol+0)+0+1)
	movf	(___fttol@f1+2),w
	movwf	((??___fttol+0)+0+2)
	clrc
	rlf	(??___fttol+0)+1,w
	rlf	(??___fttol+0)+2,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(___fttol@exp1)^080h
	movf	(((___fttol@exp1)^080h)),w
	btfss	status,2
	goto	u3101
	goto	u3100
u3101:
	goto	l3927
u3100:
	line	50
	
l3925:	
	bcf	status, 5	;RP0=0, select bank0
	clrf	(?___fttol)
	clrf	(?___fttol+1)
	clrf	(?___fttol+2)
	clrf	(?___fttol+3)
	goto	l1674
	line	51
	
l3927:	
	bcf	status, 5	;RP0=0, select bank0
	movf	(___fttol@f1),w
	movwf	((??___fttol+0)+0)
	movf	(___fttol@f1+1),w
	movwf	((??___fttol+0)+0+1)
	movf	(___fttol@f1+2),w
	movwf	((??___fttol+0)+0+2)
	movlw	017h
u3115:
	clrc
	rrf	(??___fttol+0)+2,f
	rrf	(??___fttol+0)+1,f
	rrf	(??___fttol+0)+0,f
u3110:
	addlw	-1
	skipz
	goto	u3115
	movf	0+(??___fttol+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(___fttol@sign1)^080h
	line	52
	
l3929:	
	bcf	status, 5	;RP0=0, select bank0
	bsf	(___fttol@f1)+(15/8),(15)&7
	line	53
	
l3931:	
	movlw	0FFh
	andwf	(___fttol@f1),f
	movlw	0FFh
	andwf	(___fttol@f1+1),f
	movlw	0
	andwf	(___fttol@f1+2),f
	line	54
	
l3933:	
	movf	(___fttol@f1),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(___fttol@lval)^080h
	bcf	status, 5	;RP0=0, select bank0
	movf	(___fttol@f1+1),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	((___fttol@lval)^080h)+1
	bcf	status, 5	;RP0=0, select bank0
	movf	(___fttol@f1+2),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	((___fttol@lval)^080h)+2
	clrf	((___fttol@lval)^080h)+3
	line	55
	
l3935:	
	movlw	08Eh
	subwf	(___fttol@exp1)^080h,f
	line	56
	
l3937:	
	btfss	(___fttol@exp1)^080h,7
	goto	u3121
	goto	u3120
u3121:
	goto	l3947
u3120:
	line	57
	
l3939:	
	movf	(___fttol@exp1)^080h,w
	xorlw	80h
	addlw	-((-15)^80h)
	skipnc
	goto	u3131
	goto	u3130
u3131:
	goto	l3943
u3130:
	goto	l3925
	line	60
	
l3943:	
	clrc
	rrf	(___fttol@lval+3)^080h,f
	rrf	(___fttol@lval+2)^080h,f
	rrf	(___fttol@lval+1)^080h,f
	rrf	(___fttol@lval)^080h,f
	line	61
	
l3945:	
	incfsz	(___fttol@exp1)^080h,f
	goto	u3141
	goto	u3140
u3141:
	goto	l3943
u3140:
	goto	l3955
	line	63
	
l3947:	
	movlw	low(018h)
	subwf	(___fttol@exp1)^080h,w
	skipc
	goto	u3151
	goto	u3150
u3151:
	goto	l3953
u3150:
	goto	l3925
	line	66
	
l3951:	
	clrc
	rlf	(___fttol@lval)^080h,f
	rlf	(___fttol@lval+1)^080h,f
	rlf	(___fttol@lval+2)^080h,f
	rlf	(___fttol@lval+3)^080h,f
	line	67
	decf	(___fttol@exp1)^080h,f
	line	65
	
l3953:	
	movf	((___fttol@exp1)^080h),w
	btfss	status,2
	goto	u3161
	goto	u3160
u3161:
	goto	l3951
u3160:
	line	70
	
l3955:	
	movf	((___fttol@sign1)^080h),w
	btfsc	status,2
	goto	u3171
	goto	u3170
u3171:
	goto	l3959
u3170:
	line	71
	
l3957:	
	comf	(___fttol@lval)^080h,f
	comf	(___fttol@lval+1)^080h,f
	comf	(___fttol@lval+2)^080h,f
	comf	(___fttol@lval+3)^080h,f
	incf	(___fttol@lval)^080h,f
	skipnz
	incf	(___fttol@lval+1)^080h,f
	skipnz
	incf	(___fttol@lval+2)^080h,f
	skipnz
	incf	(___fttol@lval+3)^080h,f
	line	72
	
l3959:	
	movf	(___fttol@lval+3)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(?___fttol+3)
	bsf	status, 5	;RP0=1, select bank1
	movf	(___fttol@lval+2)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(?___fttol+2)
	bsf	status, 5	;RP0=1, select bank1
	movf	(___fttol@lval+1)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(?___fttol+1)
	bsf	status, 5	;RP0=1, select bank1
	movf	(___fttol@lval)^080h,w
	bcf	status, 5	;RP0=0, select bank0
	movwf	(?___fttol)

	line	73
	
l1674:	
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
;;  f2              3   31[BANK0 ] float 
;;  f1              3   34[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  f3              3   41[BANK0 ] float 
;;  sign            1   45[BANK0 ] unsigned char 
;;  exp             1   44[BANK0 ] unsigned char 
;;  cntr            1   40[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   31[BANK0 ] float 
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
psect	text14,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
	line	56
global __ptext14
__ptext14:	;psect for function ___ftdiv
psect	text14
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftdiv.c"
	line	56
	global	__size_of___ftdiv
	__size_of___ftdiv	equ	__end_of___ftdiv-___ftdiv
	
___ftdiv:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftdiv: [wreg+status,2+status,0+pclath+cstack]
	line	63
	
l3883:	
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
	goto	u3061
	goto	u3060
u3061:
	goto	l3887
u3060:
	line	64
	
l3885:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l1638
	line	65
	
l3887:	
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
	goto	u3071
	goto	u3070
u3071:
	goto	l1639
u3070:
	line	66
	
l3889:	
	clrf	(?___ftdiv)
	clrf	(?___ftdiv+1)
	clrf	(?___ftdiv+2)
	goto	l1638
	
l1639:	
	line	67
	clrf	(___ftdiv@f3)
	clrf	(___ftdiv@f3+1)
	clrf	(___ftdiv@f3+2)
	line	68
	
l3891:	
	movlw	low(089h)
	addwf	(___ftdiv@sign),w
	movwf	(??___ftdiv+0)+0
	movf	0+(??___ftdiv+0)+0,w
	subwf	(___ftdiv@exp),f
	line	69
	
l3893:	
	movf	0+(___ftdiv@f1)+02h,w
	movwf	(___ftdiv@sign)
	line	70
	
l3895:	
	movf	0+(___ftdiv@f2)+02h,w
	xorwf	(___ftdiv@sign),f
	line	71
	
l3897:	
	movlw	low(080h)
	andwf	(___ftdiv@sign),f
	line	72
	
l3899:	
	bsf	(___ftdiv@f1)+(15/8),(15)&7
	line	73
	
l3901:	
	movlw	0FFh
	andwf	(___ftdiv@f1),f
	movlw	0FFh
	andwf	(___ftdiv@f1+1),f
	movlw	0
	andwf	(___ftdiv@f1+2),f
	line	74
	
l3903:	
	bsf	(___ftdiv@f2)+(15/8),(15)&7
	line	75
	
l3905:	
	movlw	0FFh
	andwf	(___ftdiv@f2),f
	movlw	0FFh
	andwf	(___ftdiv@f2+1),f
	movlw	0
	andwf	(___ftdiv@f2+2),f
	line	76
	
l3907:	
	movlw	low(018h)
	movwf	(___ftdiv@cntr)
	line	78
	
l3909:	
	clrc
	rlf	(___ftdiv@f3),f
	rlf	(___ftdiv@f3+1),f
	rlf	(___ftdiv@f3+2),f
	line	79
	movf	(___ftdiv@f2+2),w
	subwf	(___ftdiv@f1+2),w
	skipz
	goto	u3085
	movf	(___ftdiv@f2+1),w
	subwf	(___ftdiv@f1+1),w
	skipz
	goto	u3085
	movf	(___ftdiv@f2),w
	subwf	(___ftdiv@f1),w
u3085:
	skipc
	goto	u3081
	goto	u3080
u3081:
	goto	l3915
u3080:
	line	80
	
l3911:	
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
	
l3913:	
	bsf	(___ftdiv@f3)+(0/8),(0)&7
	line	83
	
l3915:	
	clrc
	rlf	(___ftdiv@f1),f
	rlf	(___ftdiv@f1+1),f
	rlf	(___ftdiv@f1+2),f
	line	84
	
l3917:	
	decfsz	(___ftdiv@cntr),f
	goto	u3091
	goto	u3090
u3091:
	goto	l3909
u3090:
	line	85
	
l3919:	
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
	
l1638:	
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
;;  f1              3   19[BANK0 ] float 
;;  f2              3   22[BANK0 ] float 
;; Auto vars:     Size  Location     Type
;;  exp1            1   30[BANK0 ] unsigned char 
;;  exp2            1   29[BANK0 ] unsigned char 
;;  sign            1   28[BANK0 ] unsigned char 
;; Return value:  Size  Location     Type
;;                  3   19[BANK0 ] float 
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
psect	text15,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
	line	86
global __ptext15
__ptext15:	;psect for function ___ftadd
psect	text15
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\ftadd.c"
	line	86
	global	__size_of___ftadd
	__size_of___ftadd	equ	__end_of___ftadd-___ftadd
	
___ftadd:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftadd: [wreg+status,2+status,0+pclath+cstack]
	line	90
	
l3807:	
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
	goto	u2861
	goto	u2860
u2861:
	goto	l3813
u2860:
	
l3809:	
	movf	(___ftadd@exp2),w
	subwf	(___ftadd@exp1),w
	skipnc
	goto	u2871
	goto	u2870
u2871:
	goto	l3817
u2870:
	
l3811:	
	movf	(___ftadd@exp2),w
	movwf	(??___ftadd+0)+0
	movf	(___ftadd@exp1),w
	subwf	(??___ftadd+0)+0,f
	movlw	low(019h)
	subwf	0+(??___ftadd+0)+0,w
	skipc
	goto	u2881
	goto	u2880
u2881:
	goto	l3817
u2880:
	line	93
	
l3813:	
	movf	(___ftadd@f2),w
	movwf	(?___ftadd)
	movf	(___ftadd@f2+1),w
	movwf	(?___ftadd+1)
	movf	(___ftadd@f2+2),w
	movwf	(?___ftadd+2)
	goto	l1607
	line	94
	
l3817:	
	movf	((___ftadd@exp2)),w
	btfsc	status,2
	goto	u2891
	goto	u2890
u2891:
	goto	l1610
u2890:
	
l3819:	
	movf	(___ftadd@exp1),w
	subwf	(___ftadd@exp2),w
	skipnc
	goto	u2901
	goto	u2900
u2901:
	goto	l3823
u2900:
	
l3821:	
	movf	(___ftadd@exp1),w
	movwf	(??___ftadd+0)+0
	movf	(___ftadd@exp2),w
	subwf	(??___ftadd+0)+0,f
	movlw	low(019h)
	subwf	0+(??___ftadd+0)+0,w
	skipc
	goto	u2911
	goto	u2910
u2911:
	goto	l3823
u2910:
	
l1610:	
	line	95
	goto	l1607
	line	96
	
l3823:	
	movlw	low(06h)
	movwf	(___ftadd@sign)
	line	97
	
l3825:	
	btfss	(___ftadd@f1+2),(23)&7
	goto	u2921
	goto	u2920
u2921:
	goto	l1611
u2920:
	line	98
	
l3827:	
	bsf	(___ftadd@sign)+(7/8),(7)&7
	
l1611:	
	line	99
	btfss	(___ftadd@f2+2),(23)&7
	goto	u2931
	goto	u2930
u2931:
	goto	l1612
u2930:
	line	100
	
l3829:	
	bsf	(___ftadd@sign)+(6/8),(6)&7
	
l1612:	
	line	101
	bsf	(___ftadd@f1)+(15/8),(15)&7
	line	102
	
l3831:	
	movlw	0FFh
	andwf	(___ftadd@f1),f
	movlw	0FFh
	andwf	(___ftadd@f1+1),f
	movlw	0
	andwf	(___ftadd@f1+2),f
	line	103
	
l3833:	
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
	goto	u2941
	goto	u2940
u2941:
	goto	l3845
u2940:
	line	110
	
l3835:	
	clrc
	rlf	(___ftadd@f2),f
	rlf	(___ftadd@f2+1),f
	rlf	(___ftadd@f2+2),f
	line	111
	decf	(___ftadd@exp2),f
	line	112
	
l3837:	
	movf	(___ftadd@exp2),w
	xorwf	(___ftadd@exp1),w
	skipnz
	goto	u2951
	goto	u2950
u2951:
	goto	l3843
u2950:
	
l3839:	
	decf	(___ftadd@sign),f
	movf	((___ftadd@sign)),w
	andlw	07h
	btfss	status,2
	goto	u2961
	goto	u2960
u2961:
	goto	l3835
u2960:
	goto	l3843
	line	114
	
l3841:	
	clrc
	rrf	(___ftadd@f1+2),f
	rrf	(___ftadd@f1+1),f
	rrf	(___ftadd@f1),f
	line	115
	incf	(___ftadd@exp1),f
	line	113
	
l3843:	
	movf	(___ftadd@exp1),w
	xorwf	(___ftadd@exp2),w
	skipz
	goto	u2971
	goto	u2970
u2971:
	goto	l3841
u2970:
	goto	l1621
	line	117
	
l3845:	
	movf	(___ftadd@exp1),w
	subwf	(___ftadd@exp2),w
	skipnc
	goto	u2981
	goto	u2980
u2981:
	goto	l1621
u2980:
	line	121
	
l3847:	
	clrc
	rlf	(___ftadd@f1),f
	rlf	(___ftadd@f1+1),f
	rlf	(___ftadd@f1+2),f
	line	122
	decf	(___ftadd@exp1),f
	line	123
	
l3849:	
	movf	(___ftadd@exp2),w
	xorwf	(___ftadd@exp1),w
	skipnz
	goto	u2991
	goto	u2990
u2991:
	goto	l3855
u2990:
	
l3851:	
	decf	(___ftadd@sign),f
	movf	((___ftadd@sign)),w
	andlw	07h
	btfss	status,2
	goto	u3001
	goto	u3000
u3001:
	goto	l3847
u3000:
	goto	l3855
	line	125
	
l3853:	
	clrc
	rrf	(___ftadd@f2+2),f
	rrf	(___ftadd@f2+1),f
	rrf	(___ftadd@f2),f
	line	126
	incf	(___ftadd@exp2),f
	line	124
	
l3855:	
	movf	(___ftadd@exp1),w
	xorwf	(___ftadd@exp2),w
	skipz
	goto	u3011
	goto	u3010
u3011:
	goto	l3853
u3010:
	line	129
	
l1621:	
	btfss	(___ftadd@sign),(7)&7
	goto	u3021
	goto	u3020
u3021:
	goto	l3861
u3020:
	line	131
	
l3857:	
	movlw	0FFh
	xorwf	(___ftadd@f1),f
	movlw	0FFh
	xorwf	(___ftadd@f1+1),f
	movlw	0FFh
	xorwf	(___ftadd@f1+2),f
	line	132
	
l3859:	
	incf	(___ftadd@f1),f
	skipnz
	incf	(___ftadd@f1+1),f
	skipnz
	incf	(___ftadd@f1+2),f
	line	134
	
l3861:	
	btfss	(___ftadd@sign),(6)&7
	goto	u3031
	goto	u3030
u3031:
	goto	l3867
u3030:
	line	136
	
l3863:	
	movlw	0FFh
	xorwf	(___ftadd@f2),f
	movlw	0FFh
	xorwf	(___ftadd@f2+1),f
	movlw	0FFh
	xorwf	(___ftadd@f2+2),f
	line	137
	
l3865:	
	incf	(___ftadd@f2),f
	skipnz
	incf	(___ftadd@f2+1),f
	skipnz
	incf	(___ftadd@f2+2),f
	line	139
	
l3867:	
	clrf	(___ftadd@sign)
	line	140
	
l3869:	
	movf	(___ftadd@f1),w
	addwf	(___ftadd@f2),f
	movf	(___ftadd@f1+1),w
	clrz
	skipnc
	incf	(___ftadd@f1+1),w
	skipnz
	goto	u3041
	addwf	(___ftadd@f2+1),f
u3041:
	movf	(___ftadd@f1+2),w
	clrz
	skipnc
	incf	(___ftadd@f1+2),w
	skipnz
	goto	u3042
	addwf	(___ftadd@f2+2),f
u3042:

	line	141
	
l3871:	
	btfss	(___ftadd@f2+2),(23)&7
	goto	u3051
	goto	u3050
u3051:
	goto	l3879
u3050:
	line	142
	
l3873:	
	movlw	0FFh
	xorwf	(___ftadd@f2),f
	movlw	0FFh
	xorwf	(___ftadd@f2+1),f
	movlw	0FFh
	xorwf	(___ftadd@f2+2),f
	line	143
	
l3875:	
	incf	(___ftadd@f2),f
	skipnz
	incf	(___ftadd@f2+1),f
	skipnz
	incf	(___ftadd@f2+2),f
	line	144
	
l3877:	
	clrf	(___ftadd@sign)
	incf	(___ftadd@sign),f
	line	146
	
l3879:	
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
	
l1607:	
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
;;  arg             3    8[BANK0 ] unsigned um
;;  exp             1   11[BANK0 ] unsigned char 
;;  sign            1   12[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;		None
;; Return value:  Size  Location     Type
;;                  3    8[BANK0 ] float 
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
psect	text16,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
	line	62
global __ptext16
__ptext16:	;psect for function ___ftpack
psect	text16
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\float.c"
	line	62
	global	__size_of___ftpack
	__size_of___ftpack	equ	__end_of___ftpack-___ftpack
	
___ftpack:	
;incstack = 0
	opt	stack 2
; Regs used in ___ftpack: [wreg+status,2+status,0]
	line	64
	
l3711:	
	movf	((___ftpack@exp)),w
	btfsc	status,2
	goto	u2631
	goto	u2630
u2631:
	goto	l1585
u2630:
	
l3713:	
	movf	(___ftpack@arg+2),w
	iorwf	(___ftpack@arg+1),w
	iorwf	(___ftpack@arg),w
	skipz
	goto	u2641
	goto	u2640
u2641:
	goto	l3717
u2640:
	
l1585:	
	line	65
	clrf	(?___ftpack)
	clrf	(?___ftpack+1)
	clrf	(?___ftpack+2)
	goto	l1586
	line	67
	
l3715:	
	incf	(___ftpack@exp),f
	line	68
	clrc
	rrf	(___ftpack@arg+2),f
	rrf	(___ftpack@arg+1),f
	rrf	(___ftpack@arg),f
	line	66
	
l3717:	
	movlw	low highword(0FE0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u2651
	goto	u2650
u2651:
	goto	l3715
u2650:
	goto	l3721
	line	71
	
l3719:	
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
	
l3721:	
	movlw	low highword(0FF0000h)
	andwf	(___ftpack@arg+2),w
	btfss	status,2
	goto	u2661
	goto	u2660
u2661:
	goto	l3719
u2660:
	goto	l3725
	line	76
	
l3723:	
	decf	(___ftpack@exp),f
	line	77
	clrc
	rlf	(___ftpack@arg),f
	rlf	(___ftpack@arg+1),f
	rlf	(___ftpack@arg+2),f
	line	75
	
l3725:	
	btfsc	(___ftpack@arg+1),(15)&7
	goto	u2671
	goto	u2670
u2671:
	goto	l1597
u2670:
	
l3727:	
	movlw	low(02h)
	subwf	(___ftpack@exp),w
	skipnc
	goto	u2681
	goto	u2680
u2681:
	goto	l3723
u2680:
	
l1597:	
	line	79
	btfsc	(___ftpack@exp),(0)&7
	goto	u2691
	goto	u2690
u2691:
	goto	l1598
u2690:
	line	80
	
l3729:	
	bcf	(___ftpack@arg)+(15/8),(15)&7
	
l1598:	
	line	81
	clrc
	rrf	(___ftpack@exp),f
	line	82
	
l3731:	
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
	goto	u2701
	goto	u2700
u2701:
	goto	l1599
u2700:
	line	84
	
l3733:	
	bsf	(___ftpack@arg)+(23/8),(23)&7
	
l1599:	
	line	85
	line	86
	
l1586:	
	return
	opt stack 0
GLOBAL	__end_of___ftpack
	__end_of___ftpack:
	signat	___ftpack,12411
	global	_ADC_Sample

;; *************** function _ADC_Sample *****************
;; Defined at:
;;		line 231 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;  adch            1    wreg     unsigned char 
;;  adldo           1    8[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  adch            1   14[BANK0 ] unsigned char 
;;  j               1   13[BANK0 ] unsigned char 
;;  adsum           4   16[BANK0 ] volatile unsigned long 
;;  ad_temp         2   24[BANK0 ] volatile unsigned int 
;;  admax           2   22[BANK0 ] volatile unsigned int 
;;  admin           2   20[BANK0 ] volatile unsigned int 
;;  i               1   15[BANK0 ] unsigned char 
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
psect	text17,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	231
global __ptext17
__ptext17:	;psect for function _ADC_Sample
psect	text17
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	231
	global	__size_of_ADC_Sample
	__size_of_ADC_Sample	equ	__end_of_ADC_Sample-_ADC_Sample
	
_ADC_Sample:	
;incstack = 0
	opt	stack 3
; Regs used in _ADC_Sample: [wreg+status,2+status,0]
;ADC_Sample@adch stored from wreg
	movwf	(ADC_Sample@adch)
	line	233
	
l3735:	
;SC8F072_Pwm_Demo.c: 233: volatile unsigned long adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	234
	
l3737:	
;SC8F072_Pwm_Demo.c: 234: volatile unsigned int admin = 0, admax = 0;
	clrf	(ADC_Sample@admin)	;volatile
	clrf	(ADC_Sample@admin+1)	;volatile
	clrf	(ADC_Sample@admax)	;volatile
	clrf	(ADC_Sample@admax+1)	;volatile
	line	235
;SC8F072_Pwm_Demo.c: 235: volatile unsigned int ad_temp = 0;
	clrf	(ADC_Sample@ad_temp)	;volatile
	clrf	(ADC_Sample@ad_temp+1)	;volatile
	line	237
	
l3739:	
;SC8F072_Pwm_Demo.c: 237: if ((!LDO_EN) && (adldo & 0x04) )
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(1202/8)^080h,(1202)&7	;volatile
	goto	u2711
	goto	u2710
u2711:
	goto	l3745
u2710:
	
l3741:	
	bcf	status, 5	;RP0=0, select bank0
	btfss	(ADC_Sample@adldo),(2)&7
	goto	u2721
	goto	u2720
u2721:
	goto	l3745
u2720:
	line	240
	
l3743:	
;SC8F072_Pwm_Demo.c: 238: {
;SC8F072_Pwm_Demo.c: 240: ADCON1 = adldo;
	movf	(ADC_Sample@adldo),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(150)^080h	;volatile
	line	241
;SC8F072_Pwm_Demo.c: 241: _delay((unsigned long)((100)*(16000000/4000000.0)));
	opt asmopt_push
opt asmopt_off
	movlw	132
	bcf	status, 5	;RP0=0, select bank0
movwf	((??_ADC_Sample+0)+0),f
	u3227:
decfsz	(??_ADC_Sample+0)+0,f
	goto	u3227
	nop2
opt asmopt_pop

	line	242
;SC8F072_Pwm_Demo.c: 242: }
	goto	l3747
	line	244
	
l3745:	
;SC8F072_Pwm_Demo.c: 243: else
;SC8F072_Pwm_Demo.c: 244: ADCON1 = adldo;
	bcf	status, 5	;RP0=0, select bank0
	movf	(ADC_Sample@adldo),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(150)^080h	;volatile
	line	245
	
l3747:	
;SC8F072_Pwm_Demo.c: 245: if(adch & 0x10)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(ADC_Sample@adch),(4)&7
	goto	u2731
	goto	u2730
u2731:
	goto	l3753
u2730:
	line	247
	
l3749:	
;SC8F072_Pwm_Demo.c: 246: {
;SC8F072_Pwm_Demo.c: 247: CHS4 = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1206/8)^080h,(1206)&7	;volatile
	line	248
	
l3751:	
;SC8F072_Pwm_Demo.c: 248: adch &= 0x0f;
	movlw	low(0Fh)
	bcf	status, 5	;RP0=0, select bank0
	andwf	(ADC_Sample@adch),f
	line	250
	
l3753:	
	line	251
	
l3755:	
;SC8F072_Pwm_Demo.c: 251: for (i = 0; i < 10; i++)
	clrf	(ADC_Sample@i)
	line	253
	
l3761:	
;SC8F072_Pwm_Demo.c: 252: {
;SC8F072_Pwm_Demo.c: 253: ADCON0 = (unsigned char)(0X41 | (adch << 2));
	movf	(ADC_Sample@adch),w
	movwf	(??_ADC_Sample+0)+0
	movlw	(02h)-1
u2745:
	clrc
	rlf	(??_ADC_Sample+0)+0,f
	addlw	-1
	skipz
	goto	u2745
	clrc
	rlf	(??_ADC_Sample+0)+0,w
	iorlw	041h
	bsf	status, 5	;RP0=1, select bank1
	movwf	(149)^080h	;volatile
	line	254
# 254 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	255
# 255 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	256
# 256 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
	line	257
# 257 "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
nop ;# 
psect	text17
	line	258
	
l3763:	
;SC8F072_Pwm_Demo.c: 258: GODONE = 1;
	bsf	status, 5	;RP0=1, select bank1
	bsf	(1193/8)^080h,(1193)&7	;volatile
	line	259
	
l3765:	
;SC8F072_Pwm_Demo.c: 259: unsigned char j = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(ADC_Sample@j)
	line	260
;SC8F072_Pwm_Demo.c: 260: while (GODONE)
	goto	l690
	
l691:	
	line	262
;SC8F072_Pwm_Demo.c: 261: {
;SC8F072_Pwm_Demo.c: 262: _delay((unsigned long)((2)*(16000000/4000000.0)));
		opt asmopt_push
	opt asmopt_off
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	nop2	;2 cycle nop
	opt asmopt_pop

	line	263
;SC8F072_Pwm_Demo.c: 263: if (0 == (--j))
	bcf	status, 5	;RP0=0, select bank0
	decfsz	(ADC_Sample@j),f
	goto	u2751
	goto	u2750
u2751:
	goto	l690
u2750:
	line	264
	
l3767:	
;SC8F072_Pwm_Demo.c: 264: return 0;
	movlw	low(0)
	goto	l693
	line	265
	
l690:	
	line	260
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(1193/8)^080h,(1193)&7	;volatile
	goto	u2761
	goto	u2760
u2761:
	goto	l691
u2760:
	line	267
	
l3771:	
;SC8F072_Pwm_Demo.c: 265: }
;SC8F072_Pwm_Demo.c: 267: ad_temp = (unsigned int)((ADRESH << 4) + (ADRESL >> 4));
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
	
l3773:	
	bsf	status, 5	;RP0=1, select bank1
	swapf	(152)^080h,w	;volatile
	andlw	(0ffh shr 4) & 0ffh
	bcf	status, 5	;RP0=0, select bank0
	addwf	(ADC_Sample@ad_temp),f	;volatile
	skipnc
	incf	(ADC_Sample@ad_temp+1),f	;volatile
	line	269
	
l3775:	
;SC8F072_Pwm_Demo.c: 269: if (0 == admax)
	movf	((ADC_Sample@admax)),w	;volatile
iorwf	((ADC_Sample@admax+1)),w	;volatile
	btfss	status,2
	goto	u2771
	goto	u2770
u2771:
	goto	l3779
u2770:
	line	271
	
l3777:	
;SC8F072_Pwm_Demo.c: 270: {
;SC8F072_Pwm_Demo.c: 271: admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admax+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admax)	;volatile
	line	272
;SC8F072_Pwm_Demo.c: 272: admin = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admin+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admin)	;volatile
	line	273
;SC8F072_Pwm_Demo.c: 273: }
	goto	l696
	line	274
	
l3779:	
;SC8F072_Pwm_Demo.c: 274: else if (ad_temp > admax)admax = ad_temp;
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	subwf	(ADC_Sample@admax+1),w	;volatile
	skipz
	goto	u2785
	movf	(ADC_Sample@ad_temp),w	;volatile
	subwf	(ADC_Sample@admax),w	;volatile
u2785:
	skipnc
	goto	u2781
	goto	u2780
u2781:
	goto	l3783
u2780:
	
l3781:	
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admax+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admax)	;volatile
	goto	l696
	line	276
	
l3783:	
;SC8F072_Pwm_Demo.c: 276: else if (ad_temp < admin)admin = ad_temp;
	movf	(ADC_Sample@admin+1),w	;volatile
	subwf	(ADC_Sample@ad_temp+1),w	;volatile
	skipz
	goto	u2795
	movf	(ADC_Sample@admin),w	;volatile
	subwf	(ADC_Sample@ad_temp),w	;volatile
u2795:
	skipnc
	goto	u2791
	goto	u2790
u2791:
	goto	l696
u2790:
	
l3785:	
	movf	(ADC_Sample@ad_temp+1),w	;volatile
	movwf	(ADC_Sample@admin+1)	;volatile
	movf	(ADC_Sample@ad_temp),w	;volatile
	movwf	(ADC_Sample@admin)	;volatile
	line	277
	
l696:	
;SC8F072_Pwm_Demo.c: 277: adsum += ad_temp;
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
	goto	u2801
	addwf	(ADC_Sample@adsum+1),f	;volatile
u2801:
	movf	2+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u2802
	addwf	(ADC_Sample@adsum+2),f	;volatile
u2802:
	movf	3+(??_ADC_Sample+0)+0,w
	clrz
	skipnc
	addlw	1
	skipnz
	goto	u2803
	addwf	(ADC_Sample@adsum+3),f	;volatile
u2803:

	line	251
	
l3787:	
	incf	(ADC_Sample@i),f
	
l3789:	
	movlw	low(0Ah)
	subwf	(ADC_Sample@i),w
	skipc
	goto	u2811
	goto	u2810
u2811:
	goto	l3761
u2810:
	line	279
	
l3791:	
;SC8F072_Pwm_Demo.c: 278: }
;SC8F072_Pwm_Demo.c: 279: adsum -= admax;
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
	goto	u2825
	goto	u2826
u2825:
	subwf	(ADC_Sample@adsum+1),f	;volatile
u2826:
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u2827
	goto	u2828
u2827:
	subwf	(ADC_Sample@adsum+2),f	;volatile
u2828:
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u2829
	goto	u2820
u2829:
	subwf	(ADC_Sample@adsum+3),f	;volatile
u2820:

	line	280
;SC8F072_Pwm_Demo.c: 280: if (adsum >= admin)
	movf	(ADC_Sample@admin),w	;volatile
	movwf	((??_ADC_Sample+0)+0)
	movf	(ADC_Sample@admin+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	clrf	((??_ADC_Sample+0)+0+2)
	clrf	((??_ADC_Sample+0)+0+3)
	movf	3+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+3),w	;volatile
	skipz
	goto	u2835
	movf	2+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+2),w	;volatile
	skipz
	goto	u2835
	movf	1+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum+1),w	;volatile
	skipz
	goto	u2835
	movf	0+(??_ADC_Sample+0)+0,w
	subwf	(ADC_Sample@adsum),w	;volatile
u2835:
	skipc
	goto	u2831
	goto	u2830
u2831:
	goto	l700
u2830:
	line	281
	
l3793:	
;SC8F072_Pwm_Demo.c: 281: adsum -= admin;
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
	goto	u2845
	goto	u2846
u2845:
	subwf	(ADC_Sample@adsum+1),f	;volatile
u2846:
	movf	2+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	2+(??_ADC_Sample+0)+0,w
	goto	u2847
	goto	u2848
u2847:
	subwf	(ADC_Sample@adsum+2),f	;volatile
u2848:
	movf	3+(??_ADC_Sample+0)+0,w
	skipc
	incfsz	3+(??_ADC_Sample+0)+0,w
	goto	u2849
	goto	u2840
u2849:
	subwf	(ADC_Sample@adsum+3),f	;volatile
u2840:

	goto	l3795
	line	282
	
l700:	
	line	283
;SC8F072_Pwm_Demo.c: 282: else
;SC8F072_Pwm_Demo.c: 283: adsum = 0;
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	284
	
l3795:	
;SC8F072_Pwm_Demo.c: 284: adresult = adsum >> 3;
	movf	(ADC_Sample@adsum),w	;volatile
	movwf	(??_ADC_Sample+0)+0
	movf	(ADC_Sample@adsum+1),w	;volatile
	movwf	((??_ADC_Sample+0)+0+1)
	movf	(ADC_Sample@adsum+2),w	;volatile
	movwf	((??_ADC_Sample+0)+0+2)
	movf	(ADC_Sample@adsum+3),w	;volatile
	movwf	((??_ADC_Sample+0)+0+3)
	movlw	03h
u2855:
	clrc
	rrf	(??_ADC_Sample+0)+3,f
	rrf	(??_ADC_Sample+0)+2,f
	rrf	(??_ADC_Sample+0)+1,f
	rrf	(??_ADC_Sample+0)+0,f
u2850:
	addlw	-1
	skipz
	goto	u2855
	movf	1+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult+1)^080h	;volatile
	bcf	status, 5	;RP0=0, select bank0
	movf	0+(??_ADC_Sample+0)+0,w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_adresult)^080h	;volatile
	line	285
	
l3797:	
;SC8F072_Pwm_Demo.c: 285: adsum = 0;
	bcf	status, 5	;RP0=0, select bank0
	clrf	(ADC_Sample@adsum)	;volatile
	clrf	(ADC_Sample@adsum+1)	;volatile
	clrf	(ADC_Sample@adsum+2)	;volatile
	clrf	(ADC_Sample@adsum+3)	;volatile
	line	286
	
l3799:	
;SC8F072_Pwm_Demo.c: 286: admin = 0;
	clrf	(ADC_Sample@admin)	;volatile
	clrf	(ADC_Sample@admin+1)	;volatile
	line	287
	
l3801:	
;SC8F072_Pwm_Demo.c: 287: admax = 0;
	clrf	(ADC_Sample@admax)	;volatile
	clrf	(ADC_Sample@admax+1)	;volatile
	line	288
	
l3803:	
;SC8F072_Pwm_Demo.c: 288: return 0xA5;
	movlw	low(0A5h)
	line	289
	
l693:	
	return
	opt stack 0
GLOBAL	__end_of_ADC_Sample
	__end_of_ADC_Sample:
	signat	_ADC_Sample,8313
	global	_Isr_Timer

;; *************** function _Isr_Timer *****************
;; Defined at:
;;		line 385 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
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
;;		On exit  : 100/0
;;		Unchanged: 0/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         0       0       0
;;      Locals:         0       0       0
;;      Temps:          0       4       0
;;      Totals:         0       4       0
;;Total ram usage:        4 bytes
;; Hardware stack levels used:    1
;; Hardware stack levels required when called:    2
;; This function calls:
;;		_Charge_num
;;		_Display
;;		_Uncharge_num
;;		i1_Set_PWM
;; This function is called by:
;;		Interrupt level 1
;; This function uses a non-reentrant model
;;
psect	text18,local,class=CODE,delta=2,merge=1,group=0
	line	385
global __ptext18
__ptext18:	;psect for function _Isr_Timer
psect	text18
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	385
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
	bcf	status, 5	;RP0=0, select bank0
	movwf	(??_Isr_Timer+0)
	movf	fsr0,w
	movwf	(??_Isr_Timer+1)
	movf	pclath,w
	movwf	(??_Isr_Timer+2)
	movf	btemp+1,w
	movwf	(??_Isr_Timer+3)
	ljmp	_Isr_Timer
psect	text18
	line	387
	
i1l3533:	
;SC8F072_Pwm_Demo.c: 387: if(RAIF)
	btfss	(107/8),(107)&7	;volatile
	goto	u243_21
	goto	u243_20
u243_21:
	goto	i1l3553
u243_20:
	line	389
	
i1l3535:	
;SC8F072_Pwm_Demo.c: 388: {
;SC8F072_Pwm_Demo.c: 389: if (!(PORTA & 0x20))
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(134)^080h,(5)&7	;volatile
	goto	u244_21
	goto	u244_20
u244_21:
	goto	i1l3545
u244_20:
	line	391
	
i1l3537:	
;SC8F072_Pwm_Demo.c: 390: {
;SC8F072_Pwm_Demo.c: 391: Charge_num();
	fcall	_Charge_num
	line	392
	
i1l3539:	
;SC8F072_Pwm_Demo.c: 392: Set_PWM(0, duty_steps[pwm_duty]);
	movf	(_pwm_duty),w
	addlw	low((((_duty_steps)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	movwf	(i1Set_PWM@duty)
	movlw	low(0)
	fcall	i1_Set_PWM
	line	393
	
i1l3541:	
;SC8F072_Pwm_Demo.c: 393: Set_PWM(1, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(i1Set_PWM@duty)
	movlw	low(01h)
	fcall	i1_Set_PWM
	line	394
	
i1l3543:	
;SC8F072_Pwm_Demo.c: 394: Set_PWM(2, duty_steps[5]);
	movlw	low((((_duty_steps+05h)-__stringbase)|8000h))
	movwf	fsr0
	fcall	stringdir
	bcf	status, 5	;RP0=0, select bank0
	movwf	(i1Set_PWM@duty)
	movlw	low(02h)
	fcall	i1_Set_PWM
	line	395
;SC8F072_Pwm_Demo.c: 395: }
	goto	i1l3547
	line	398
	
i1l3545:	
;SC8F072_Pwm_Demo.c: 396: else
;SC8F072_Pwm_Demo.c: 397: {
;SC8F072_Pwm_Demo.c: 398: Uncharge_num();
	fcall	_Uncharge_num
	line	401
	
i1l3547:	
;SC8F072_Pwm_Demo.c: 399: }
;SC8F072_Pwm_Demo.c: 401: if(!(PORTA & 0x04))
	bsf	status, 5	;RP0=1, select bank1
	btfsc	(134)^080h,(2)&7	;volatile
	goto	u245_21
	goto	u245_20
u245_21:
	goto	i1l3551
u245_20:
	line	403
	
i1l3549:	
;SC8F072_Pwm_Demo.c: 402: {
;SC8F072_Pwm_Demo.c: 403: LED_delay=21;
	movlw	015h
	bcf	status, 5	;RP0=0, select bank0
	movwf	(_LED_delay)	;volatile
	clrf	(_LED_delay+1)	;volatile
	line	406
	
i1l3551:	
;SC8F072_Pwm_Demo.c: 404: }
;SC8F072_Pwm_Demo.c: 406: RAIF = 0;
	bcf	status, 5	;RP0=0, select bank0
	bcf	(107/8),(107)&7	;volatile
	line	409
	
i1l3553:	
;SC8F072_Pwm_Demo.c: 407: }
;SC8F072_Pwm_Demo.c: 409: if(RBIF)
	btfss	(88/8),(88)&7	;volatile
	goto	u246_21
	goto	u246_20
u246_21:
	goto	i1l3569
u246_20:
	line	411
	
i1l3555:	
;SC8F072_Pwm_Demo.c: 410: {
;SC8F072_Pwm_Demo.c: 411: RBIF = 0;
	bcf	(88/8),(88)&7	;volatile
	line	416
;SC8F072_Pwm_Demo.c: 416: if (PORTB & 0x20)
	btfss	(6),(5)&7	;volatile
	goto	u247_21
	goto	u247_20
u247_21:
	goto	i1l3569
u247_20:
	line	418
	
i1l3557:	
;SC8F072_Pwm_Demo.c: 417: {
;SC8F072_Pwm_Demo.c: 418: if (long_press_counter >= 1000)
	movlw	03h
	subwf	(_long_press_counter+1),w	;volatile
	movlw	0E8h
	skipnz
	subwf	(_long_press_counter),w	;volatile
	skipc
	goto	u248_21
	goto	u248_20
u248_21:
	goto	i1l3561
u248_20:
	line	420
	
i1l3559:	
;SC8F072_Pwm_Demo.c: 419: {
;SC8F072_Pwm_Demo.c: 420: button_lflag = 1;
	movlw	low(01h)
	movwf	(_button_lflag)	;volatile
	line	421
;SC8F072_Pwm_Demo.c: 421: }
	goto	i1l3567
	line	422
	
i1l3561:	
;SC8F072_Pwm_Demo.c: 422: else if(long_press_counter<=1000 && long_press_counter>=50)
	movlw	03h
	subwf	(_long_press_counter+1),w	;volatile
	movlw	0E9h
	skipnz
	subwf	(_long_press_counter),w	;volatile
	skipnc
	goto	u249_21
	goto	u249_20
u249_21:
	goto	i1l3567
u249_20:
	
i1l3563:	
	movlw	0
	subwf	(_long_press_counter+1),w	;volatile
	movlw	032h
	skipnz
	subwf	(_long_press_counter),w	;volatile
	skipc
	goto	u250_21
	goto	u250_20
u250_21:
	goto	i1l3567
u250_20:
	line	424
	
i1l3565:	
;SC8F072_Pwm_Demo.c: 423: {
;SC8F072_Pwm_Demo.c: 424: button_sflag = 1;
	movlw	low(01h)
	movwf	(_button_sflag)	;volatile
	line	426
	
i1l3567:	
;SC8F072_Pwm_Demo.c: 425: }
;SC8F072_Pwm_Demo.c: 426: long_press_counter = 0;
	clrf	(_long_press_counter)	;volatile
	clrf	(_long_press_counter+1)	;volatile
	line	430
	
i1l3569:	
;SC8F072_Pwm_Demo.c: 427: }
;SC8F072_Pwm_Demo.c: 429: }
;SC8F072_Pwm_Demo.c: 430: if(T0IF)
	btfss	(90/8),(90)&7	;volatile
	goto	u251_21
	goto	u251_20
u251_21:
	goto	i1l3585
u251_20:
	line	432
	
i1l3571:	
;SC8F072_Pwm_Demo.c: 431: {
;SC8F072_Pwm_Demo.c: 432: T0IF = 0;
	bcf	(90/8),(90)&7	;volatile
	line	433
	
i1l3573:	
;SC8F072_Pwm_Demo.c: 433: if(T_flag)
	movf	((_T_flag)),w	;volatile
	btfsc	status,2
	goto	u252_21
	goto	u252_20
u252_21:
	goto	i1l3577
u252_20:
	line	435
	
i1l3575:	
;SC8F072_Pwm_Demo.c: 434: {
;SC8F072_Pwm_Demo.c: 435: Display();
	fcall	_Display
	line	437
	
i1l3577:	
;SC8F072_Pwm_Demo.c: 436: }
;SC8F072_Pwm_Demo.c: 437: TMR0 += 6;
	movlw	low(06h)
	bsf	status, 5	;RP0=1, select bank1
	addwf	(129)^080h,f	;volatile
	line	440
	
i1l3579:	
;SC8F072_Pwm_Demo.c: 440: if(ADC_delay > 0)
	movf	((_ADC_delay)^080h),w	;volatile
iorwf	((_ADC_delay+1)^080h),w	;volatile
	btfsc	status,2
	goto	u253_21
	goto	u253_20
u253_21:
	goto	i1l3583
u253_20:
	line	442
	
i1l3581:	
;SC8F072_Pwm_Demo.c: 441: {
;SC8F072_Pwm_Demo.c: 442: ADC_delay--;
	movlw	01h
	subwf	(_ADC_delay)^080h,f	;volatile
	movlw	0
	skipc
	decf	(_ADC_delay+1)^080h,f	;volatile
	subwf	(_ADC_delay+1)^080h,f	;volatile
	line	443
;SC8F072_Pwm_Demo.c: 443: }
	goto	i1l3585
	line	446
	
i1l3583:	
;SC8F072_Pwm_Demo.c: 444: else
;SC8F072_Pwm_Demo.c: 445: {
;SC8F072_Pwm_Demo.c: 446: ADC_delay=1000;
	movlw	0E8h
	movwf	(_ADC_delay)^080h	;volatile
	movlw	03h
	movwf	((_ADC_delay)^080h)+1	;volatile
	line	447
;SC8F072_Pwm_Demo.c: 447: ADC_Flag=1;
	movlw	low(01h)
	bcf	status, 5	;RP0=0, select bank0
	movwf	(_ADC_Flag)	;volatile
	line	450
	
i1l3585:	
;SC8F072_Pwm_Demo.c: 448: }
;SC8F072_Pwm_Demo.c: 449: }
;SC8F072_Pwm_Demo.c: 450: if(TMR2IF)
	bcf	status, 5	;RP0=0, select bank0
	btfss	(105/8),(105)&7	;volatile
	goto	u254_21
	goto	u254_20
u254_21:
	goto	i1l750
u254_20:
	line	452
	
i1l3587:	
;SC8F072_Pwm_Demo.c: 451: {
;SC8F072_Pwm_Demo.c: 452: TMR2IF = 0;
	bcf	(105/8),(105)&7	;volatile
	line	453
	
i1l3589:	
;SC8F072_Pwm_Demo.c: 453: if(LED_delay>1)
	movlw	0
	subwf	(_LED_delay+1),w	;volatile
	movlw	02h
	skipnz
	subwf	(_LED_delay),w	;volatile
	skipc
	goto	u255_21
	goto	u255_20
u255_21:
	goto	i1l3593
u255_20:
	line	455
	
i1l3591:	
;SC8F072_Pwm_Demo.c: 454: {
;SC8F072_Pwm_Demo.c: 455: LED_delay--;
	movlw	01h
	subwf	(_LED_delay),f	;volatile
	movlw	0
	skipc
	decf	(_LED_delay+1),f	;volatile
	subwf	(_LED_delay+1),f	;volatile
	line	456
;SC8F072_Pwm_Demo.c: 456: }
	goto	i1l3601
	line	457
	
i1l3593:	
;SC8F072_Pwm_Demo.c: 457: else if(LED_delay==1)
		decf	((_LED_delay)),w	;volatile
iorwf	((_LED_delay+1)),w	;volatile
	btfss	status,2
	goto	u256_21
	goto	u256_20
u256_21:
	goto	i1l3601
u256_20:
	line	459
	
i1l3595:	
;SC8F072_Pwm_Demo.c: 458: {
;SC8F072_Pwm_Demo.c: 459: LED_delay=0;
	clrf	(_LED_delay)	;volatile
	clrf	(_LED_delay+1)	;volatile
	line	460
	
i1l3597:	
;SC8F072_Pwm_Demo.c: 460: if (!(PORTB & 0x20))
	btfsc	(6),(5)&7	;volatile
	goto	u257_21
	goto	u257_20
u257_21:
	goto	i1l3601
u257_20:
	line	462
	
i1l3599:	
;SC8F072_Pwm_Demo.c: 461: {
;SC8F072_Pwm_Demo.c: 462: LED_flag = 1;
	movlw	low(01h)
	bsf	status, 5	;RP0=1, select bank1
	movwf	(_LED_flag)^080h	;volatile
	line	467
	
i1l3601:	
;SC8F072_Pwm_Demo.c: 463: }
;SC8F072_Pwm_Demo.c: 464: }
;SC8F072_Pwm_Demo.c: 467: if (!(PORTB & 0x20))
	bcf	status, 5	;RP0=0, select bank0
	btfsc	(6),(5)&7	;volatile
	goto	u258_21
	goto	u258_20
u258_21:
	goto	i1l3611
u258_20:
	line	469
	
i1l3603:	
;SC8F072_Pwm_Demo.c: 468: {
;SC8F072_Pwm_Demo.c: 469: if (debounce_counter < 15) debounce_counter++;
	movlw	low(0Fh)
	subwf	(_debounce_counter),w	;volatile
	skipnc
	goto	u259_21
	goto	u259_20
u259_21:
	goto	i1l3607
u259_20:
	
i1l3605:	
	incf	(_debounce_counter),f	;volatile
	line	470
	
i1l3607:	
;SC8F072_Pwm_Demo.c: 470: if (debounce_counter == 15) long_press_counter++;
		movlw	15
	xorwf	((_debounce_counter)),w	;volatile
	btfss	status,2
	goto	u260_21
	goto	u260_20
u260_21:
	goto	i1l3613
u260_20:
	
i1l3609:	
	incf	(_long_press_counter),f	;volatile
	skipnz
	incf	(_long_press_counter+1),f	;volatile
	goto	i1l3613
	line	474
	
i1l3611:	
;SC8F072_Pwm_Demo.c: 472: else
;SC8F072_Pwm_Demo.c: 473: {
;SC8F072_Pwm_Demo.c: 474: debounce_counter = 0;
	clrf	(_debounce_counter)	;volatile
	line	478
	
i1l3613:	
;SC8F072_Pwm_Demo.c: 475: }
;SC8F072_Pwm_Demo.c: 478: if(Time_delay > 0)
	bsf	status, 5	;RP0=1, select bank1
	movf	((_Time_delay)^080h),w	;volatile
iorwf	((_Time_delay+1)^080h),w	;volatile
	btfsc	status,2
	goto	u261_21
	goto	u261_20
u261_21:
	goto	i1l746
u261_20:
	line	480
	
i1l3615:	
;SC8F072_Pwm_Demo.c: 479: {
;SC8F072_Pwm_Demo.c: 480: Time_delay--;
	movlw	01h
	subwf	(_Time_delay)^080h,f	;volatile
	movlw	0
	skipc
	decf	(_Time_delay+1)^080h,f	;volatile
	subwf	(_Time_delay+1)^080h,f	;volatile
	line	481
;SC8F072_Pwm_Demo.c: 481: }
	goto	i1l750
	line	482
	
i1l746:	
	line	484
;SC8F072_Pwm_Demo.c: 482: else
;SC8F072_Pwm_Demo.c: 483: {
;SC8F072_Pwm_Demo.c: 484: if (!(PORTA & 0x20))
	btfsc	(134)^080h,(5)&7	;volatile
	goto	u262_21
	goto	u262_20
u262_21:
	goto	i1l3619
u262_20:
	line	486
	
i1l3617:	
;SC8F072_Pwm_Demo.c: 485: {
;SC8F072_Pwm_Demo.c: 486: Charge_num();
	fcall	_Charge_num
	line	487
;SC8F072_Pwm_Demo.c: 487: }
	goto	i1l750
	line	490
	
i1l3619:	
;SC8F072_Pwm_Demo.c: 488: else
;SC8F072_Pwm_Demo.c: 489: {
;SC8F072_Pwm_Demo.c: 490: Uncharge_num();
	fcall	_Uncharge_num
	line	494
	
i1l750:	
	bcf	status, 5	;RP0=0, select bank0
	movf	(??_Isr_Timer+3),w
	movwf	btemp+1
	movf	(??_Isr_Timer+2),w
	movwf	pclath
	movf	(??_Isr_Timer+1),w
	movwf	fsr0
	swapf	(??_Isr_Timer+0)^00h,w
	movwf	status
	swapf	saved_w,f
	swapf	saved_w,w
	retfie
	opt stack 0
GLOBAL	__end_of_Isr_Timer
	__end_of_Isr_Timer:
	signat	_Isr_Timer,89
	global	i1_Set_PWM

;; *************** function i1_Set_PWM *****************
;; Defined at:
;;		line 183 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
;; Parameters:    Size  Location     Type
;;  channel         1    wreg     unsigned char 
;;  duty            1    0[BANK0 ] unsigned char 
;; Auto vars:     Size  Location     Type
;;  channel         1    1[BANK0 ] unsigned char 
;;  Set_PWM         2    2[BANK0 ] unsigned short 
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
;; Hardware stack levels required when called:    1
;; This function calls:
;;		i1___awdiv
;;		i1___wmul
;; This function is called by:
;;		_Isr_Timer
;; This function uses a non-reentrant model
;;
psect	text19,local,class=CODE,delta=2,merge=1,group=0
	line	183
global __ptext19
__ptext19:	;psect for function i1_Set_PWM
psect	text19
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\SC8F072_Pwm_Demo.c"
	line	183
	global	__size_ofi1_Set_PWM
	__size_ofi1_Set_PWM	equ	__end_ofi1_Set_PWM-i1_Set_PWM
	
i1_Set_PWM:	
;incstack = 0
	opt	stack 2
; Regs used in i1_Set_PWM: [wreg-fsr0h+status,2+status,0+pclath+cstack]
;i1Set_PWM@channel stored from wreg
	movwf	(i1Set_PWM@channel)
	line	185
	
i1l3501:	
;SC8F072_Pwm_Demo.c: 185: unsigned short pulse_width = (duty * 255) / 100;
	movlw	064h
	movwf	(i1___awdiv@divisor)
	clrf	(i1___awdiv@divisor+1)
	movf	(i1Set_PWM@duty),w
	movwf	(i1___wmul@multiplier)
	clrf	(i1___wmul@multiplier+1)
	movlw	0FFh
	movwf	(i1___wmul@multiplicand)
	clrf	(i1___wmul@multiplicand+1)
	fcall	i1___wmul
	movf	(1+(?i1___wmul)),w
	movwf	(i1___awdiv@dividend+1)
	movf	(0+(?i1___wmul)),w
	movwf	(i1___awdiv@dividend)
	fcall	i1___awdiv
	movf	(1+(?i1___awdiv)),w
	movwf	(i1Set_PWM@pulse_width+1)
	movf	(0+(?i1___awdiv)),w
	movwf	(i1Set_PWM@pulse_width)
	line	186
;SC8F072_Pwm_Demo.c: 186: switch (channel)
	goto	i1l3515
	line	189
	
i1l3503:	
;SC8F072_Pwm_Demo.c: 189: PWMD0L = pulse_width & 0xFF;
	movf	(i1Set_PWM@pulse_width),w
	movwf	(25)	;volatile
	line	191
;SC8F072_Pwm_Demo.c: 191: break;
	goto	i1l682
	line	193
	
i1l3505:	
;SC8F072_Pwm_Demo.c: 193: PWMD1L = pulse_width & 0xFF;
	movf	(i1Set_PWM@pulse_width),w
	movwf	(26)	;volatile
	line	195
;SC8F072_Pwm_Demo.c: 195: break;
	goto	i1l682
	line	197
	
i1l3507:	
;SC8F072_Pwm_Demo.c: 197: PWMD2L = pulse_width & 0xFF;
	movf	(i1Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(155)^080h	;volatile
	line	199
;SC8F072_Pwm_Demo.c: 199: break;
	goto	i1l682
	line	201
	
i1l3509:	
;SC8F072_Pwm_Demo.c: 201: PWMD3L = pulse_width & 0xFF;
	movf	(i1Set_PWM@pulse_width),w
	bsf	status, 5	;RP0=1, select bank1
	movwf	(156)^080h	;volatile
	line	203
;SC8F072_Pwm_Demo.c: 203: break;
	goto	i1l682
	line	205
	
i1l3511:	
;SC8F072_Pwm_Demo.c: 205: PWMD4L = pulse_width & 0xFF;
	movf	(i1Set_PWM@pulse_width),w
	movwf	(27)	;volatile
	line	207
;SC8F072_Pwm_Demo.c: 207: break;
	goto	i1l682
	line	186
	
i1l3515:	
	movf	(i1Set_PWM@channel),w
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
goto i1l682
movlw high(i1S4089)
movwf pclath
	movlw low(i1S4089)
	addwf fsr,w
	movwf pc
psect	swtext3,local,class=CONST,delta=2
global __pswtext3
__pswtext3:
i1S4089:
	ljmp	i1l3503
	ljmp	i1l3505
	ljmp	i1l3507
	ljmp	i1l3509
	ljmp	i1l3511
psect	text19

	line	211
	
i1l682:	
	return
	opt stack 0
GLOBAL	__end_ofi1_Set_PWM
	__end_ofi1_Set_PWM:
	signat	i1_Set_PWM,89
	global	i1___wmul

;; *************** function i1___wmul *****************
;; Defined at:
;;		line 15 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\Umul16.c"
;; Parameters:    Size  Location     Type
;;  multiplier      2    0[COMMON] unsigned int 
;;  multiplicand    2    2[COMMON] unsigned int 
;; Auto vars:     Size  Location     Type
;;  __wmul          2    4[COMMON] unsigned int 
;; Return value:  Size  Location     Type
;;                  2    0[COMMON] unsigned int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 100/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         4       0       0
;;      Locals:         2       0       0
;;      Temps:          0       0       0
;;      Totals:         6       0       0
;;Total ram usage:        6 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		i1_Set_PWM
;; This function uses a non-reentrant model
;;
psect	text20,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\Umul16.c"
	line	15
global __ptext20
__ptext20:	;psect for function i1___wmul
psect	text20
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\Umul16.c"
	line	15
	global	__size_ofi1___wmul
	__size_ofi1___wmul	equ	__end_ofi1___wmul-i1___wmul
	
i1___wmul:	
;incstack = 0
	opt	stack 2
; Regs used in i1___wmul: [wreg+status,2+status,0]
	line	43
	
i1l3257:	
	clrf	(i1___wmul@product)
	clrf	(i1___wmul@product+1)
	line	45
	
i1l3259:	
	btfss	(i1___wmul@multiplier),(0)&7
	goto	u228_21
	goto	u228_20
u228_21:
	goto	i1l3263
u228_20:
	line	46
	
i1l3261:	
	movf	(i1___wmul@multiplicand),w
	addwf	(i1___wmul@product),f
	skipnc
	incf	(i1___wmul@product+1),f
	movf	(i1___wmul@multiplicand+1),w
	addwf	(i1___wmul@product+1),f
	line	47
	
i1l3263:	
	clrc
	rlf	(i1___wmul@multiplicand),f
	rlf	(i1___wmul@multiplicand+1),f
	line	48
	
i1l3265:	
	clrc
	rrf	(i1___wmul@multiplier+1),f
	rrf	(i1___wmul@multiplier),f
	line	49
	
i1l3267:	
	movf	((i1___wmul@multiplier)),w
iorwf	((i1___wmul@multiplier+1)),w
	btfss	status,2
	goto	u229_21
	goto	u229_20
u229_21:
	goto	i1l3259
u229_20:
	line	52
	
i1l3269:	
	movf	(i1___wmul@product+1),w
	movwf	(?i1___wmul+1)
	movf	(i1___wmul@product),w
	movwf	(?i1___wmul)
	line	53
	
i1l1431:	
	return
	opt stack 0
GLOBAL	__end_ofi1___wmul
	__end_ofi1___wmul:
	signat	i1___wmul,90
	global	i1___awdiv

;; *************** function i1___awdiv *****************
;; Defined at:
;;		line 6 in file "C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awdiv.c"
;; Parameters:    Size  Location     Type
;;  divisor         2    6[COMMON] int 
;;  dividend        2    8[COMMON] int 
;; Auto vars:     Size  Location     Type
;;  __awdiv         2   12[COMMON] int 
;;  __awdiv         1   11[COMMON] unsigned char 
;;  __awdiv         1   10[COMMON] unsigned char 
;; Return value:  Size  Location     Type
;;                  2    6[COMMON] int 
;; Registers used:
;;		wreg, status,2, status,0
;; Tracked objects:
;;		On entry : 100/0
;;		On exit  : 100/0
;;		Unchanged: 100/0
;; Data sizes:     COMMON   BANK0   BANK1
;;      Params:         4       0       0
;;      Locals:         4       0       0
;;      Temps:          0       0       0
;;      Totals:         8       0       0
;;Total ram usage:        8 bytes
;; Hardware stack levels used:    1
;; This function calls:
;;		Nothing
;; This function is called by:
;;		i1_Set_PWM
;; This function uses a non-reentrant model
;;
psect	text21,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awdiv.c"
	line	6
global __ptext21
__ptext21:	;psect for function i1___awdiv
psect	text21
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\awdiv.c"
	line	6
	global	__size_ofi1___awdiv
	__size_ofi1___awdiv	equ	__end_ofi1___awdiv-i1___awdiv
	
i1___awdiv:	
;incstack = 0
	opt	stack 2
; Regs used in i1___awdiv: [wreg+status,2+status,0]
	line	14
	
i1l3273:	
	clrf	(i1___awdiv@sign)
	line	15
	
i1l3275:	
	btfss	(i1___awdiv@divisor+1),7
	goto	u230_21
	goto	u230_20
u230_21:
	goto	i1l3281
u230_20:
	line	16
	
i1l3277:	
	comf	(i1___awdiv@divisor),f
	comf	(i1___awdiv@divisor+1),f
	incf	(i1___awdiv@divisor),f
	skipnz
	incf	(i1___awdiv@divisor+1),f
	line	17
	
i1l3279:	
	clrf	(i1___awdiv@sign)
	incf	(i1___awdiv@sign),f
	line	19
	
i1l3281:	
	btfss	(i1___awdiv@dividend+1),7
	goto	u231_21
	goto	u231_20
u231_21:
	goto	i1l3287
u231_20:
	line	20
	
i1l3283:	
	comf	(i1___awdiv@dividend),f
	comf	(i1___awdiv@dividend+1),f
	incf	(i1___awdiv@dividend),f
	skipnz
	incf	(i1___awdiv@dividend+1),f
	line	21
	
i1l3285:	
	movlw	low(01h)
	xorwf	(i1___awdiv@sign),f
	line	23
	
i1l3287:	
	clrf	(i1___awdiv@quotient)
	clrf	(i1___awdiv@quotient+1)
	line	24
	
i1l3289:	
	movf	((i1___awdiv@divisor)),w
iorwf	((i1___awdiv@divisor+1)),w
	btfsc	status,2
	goto	u232_21
	goto	u232_20
u232_21:
	goto	i1l3309
u232_20:
	line	25
	
i1l3291:	
	clrf	(i1___awdiv@counter)
	incf	(i1___awdiv@counter),f
	line	26
	goto	i1l3295
	line	27
	
i1l3293:	
	clrc
	rlf	(i1___awdiv@divisor),f
	rlf	(i1___awdiv@divisor+1),f
	line	28
	incf	(i1___awdiv@counter),f
	line	26
	
i1l3295:	
	btfss	(i1___awdiv@divisor+1),(15)&7
	goto	u233_21
	goto	u233_20
u233_21:
	goto	i1l3293
u233_20:
	line	31
	
i1l3297:	
	clrc
	rlf	(i1___awdiv@quotient),f
	rlf	(i1___awdiv@quotient+1),f
	line	32
	
i1l3299:	
	movf	(i1___awdiv@divisor+1),w
	subwf	(i1___awdiv@dividend+1),w
	skipz
	goto	u234_25
	movf	(i1___awdiv@divisor),w
	subwf	(i1___awdiv@dividend),w
u234_25:
	skipc
	goto	u234_21
	goto	u234_20
u234_21:
	goto	i1l3305
u234_20:
	line	33
	
i1l3301:	
	movf	(i1___awdiv@divisor),w
	subwf	(i1___awdiv@dividend),f
	movf	(i1___awdiv@divisor+1),w
	skipc
	decf	(i1___awdiv@dividend+1),f
	subwf	(i1___awdiv@dividend+1),f
	line	34
	
i1l3303:	
	bsf	(i1___awdiv@quotient)+(0/8),(0)&7
	line	36
	
i1l3305:	
	clrc
	rrf	(i1___awdiv@divisor+1),f
	rrf	(i1___awdiv@divisor),f
	line	37
	
i1l3307:	
	decfsz	(i1___awdiv@counter),f
	goto	u235_21
	goto	u235_20
u235_21:
	goto	i1l3297
u235_20:
	line	39
	
i1l3309:	
	movf	((i1___awdiv@sign)),w
	btfsc	status,2
	goto	u236_21
	goto	u236_20
u236_21:
	goto	i1l3313
u236_20:
	line	40
	
i1l3311:	
	comf	(i1___awdiv@quotient),f
	comf	(i1___awdiv@quotient+1),f
	incf	(i1___awdiv@quotient),f
	skipnz
	incf	(i1___awdiv@quotient+1),f
	line	41
	
i1l3313:	
	movf	(i1___awdiv@quotient+1),w
	movwf	(?i1___awdiv+1)
	movf	(i1___awdiv@quotient),w
	movwf	(?i1___awdiv)
	line	42
	
i1l1561:	
	return
	opt stack 0
GLOBAL	__end_ofi1___awdiv
	__end_ofi1___awdiv:
	signat	i1___awdiv,90
	global	_Uncharge_num

;; *************** function _Uncharge_num *****************
;; Defined at:
;;		line 25 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text22,local,class=CODE,delta=2,merge=1,group=0
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	25
global __ptext22
__ptext22:	;psect for function _Uncharge_num
psect	text22
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	25
	global	__size_of_Uncharge_num
	__size_of_Uncharge_num	equ	__end_of_Uncharge_num-_Uncharge_num
	
_Uncharge_num:	
;incstack = 0
	opt	stack 2
; Regs used in _Uncharge_num: [wreg+status,2+status,0+pclath+cstack]
	line	27
	
i1l3459:	
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
	
i1l3461:	
;LED_188.c: 30: if(hundred)
	movf	((Uncharge_num@hundred)),w
	btfsc	status,2
	goto	u241_21
	goto	u241_20
u241_21:
	goto	i1l3465
u241_20:
	line	32
	
i1l3463:	
;LED_188.c: 31: {
;LED_188.c: 32: hundreds = 3;
	movlw	low(03h)
	movwf	(_hundreds)	;volatile
	line	33
;LED_188.c: 33: }
	goto	i1l1366
	line	36
	
i1l3465:	
;LED_188.c: 34: else
;LED_188.c: 35: {
;LED_188.c: 36: hundreds = 1;
	movlw	low(01h)
	movwf	(_hundreds)	;volatile
	line	38
	
i1l1366:	
	return
	opt stack 0
GLOBAL	__end_of_Uncharge_num
	__end_of_Uncharge_num:
	signat	_Uncharge_num,89
	global	_Display

;; *************** function _Display *****************
;; Defined at:
;;		line 170 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
;;		i1_Set_AllPin_INPUT
;; This function is called by:
;;		_Isr_Timer
;; This function uses a non-reentrant model
;;
psect	text23,local,class=CODE,delta=2,merge=1,group=0
	line	170
global __ptext23
__ptext23:	;psect for function _Display
psect	text23
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	170
	global	__size_of_Display
	__size_of_Display	equ	__end_of_Display-_Display
	
_Display:	
;incstack = 0
	opt	stack 2
; Regs used in _Display: [wreg-fsr0h+status,2+status,0+pclath+cstack]
	line	173
	
i1l3467:	
;LED_188.c: 172: static unsigned char scan_cnt;
;LED_188.c: 173: Set_AllPin_INPUT();
	fcall	i1_Set_AllPin_INPUT
	line	175
;LED_188.c: 175: switch(scan_cnt)
	goto	i1l3493
	line	177
	
i1l3469:	
	fcall	_Display_Scan1
	
i1l3471:	
	incf	(Display@scan_cnt),f
	goto	i1l1425
	line	178
	
i1l3473:	
	fcall	_Display_Scan2
	goto	i1l3471
	line	179
	
i1l3477:	
	fcall	_Display_Scan3
	goto	i1l3471
	line	180
	
i1l3481:	
	fcall	_Display_Scan4
	goto	i1l3471
	line	181
	
i1l3485:	
	fcall	_Display_Scan5
	
i1l3487:	
	clrf	(Display@scan_cnt)
	goto	i1l1425
	line	175
	
i1l3493:	
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
goto i1l3487
movlw high(i1S4091)
movwf pclath
	movlw low(i1S4091)
	addwf fsr,w
	movwf pc
psect	swtext4,local,class=CONST,delta=2
global __pswtext4
__pswtext4:
i1S4091:
	ljmp	i1l3469
	ljmp	i1l3473
	ljmp	i1l3477
	ljmp	i1l3481
	ljmp	i1l3485
psect	text23

	line	184
	
i1l1425:	
	return
	opt stack 0
GLOBAL	__end_of_Display
	__end_of_Display:
	signat	_Display,89
	global	i1_Set_AllPin_INPUT

;; *************** function i1_Set_AllPin_INPUT *****************
;; Defined at:
;;		line 85 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text24,local,class=CODE,delta=2,merge=1,group=0
	line	85
global __ptext24
__ptext24:	;psect for function i1_Set_AllPin_INPUT
psect	text24
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	85
	global	__size_ofi1_Set_AllPin_INPUT
	__size_ofi1_Set_AllPin_INPUT	equ	__end_ofi1_Set_AllPin_INPUT-i1_Set_AllPin_INPUT
	
i1_Set_AllPin_INPUT:	
;incstack = 0
	opt	stack 2
; Regs used in i1_Set_AllPin_INPUT: []
	line	87
	
i1l3255:	
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
	
i1l1379:	
	return
	opt stack 0
GLOBAL	__end_ofi1_Set_AllPin_INPUT
	__end_ofi1_Set_AllPin_INPUT:
	signat	i1_Set_AllPin_INPUT,89
	global	_Display_Scan5

;; *************** function _Display_Scan5 *****************
;; Defined at:
;;		line 161 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
	line	161
global __ptext25
__ptext25:	;psect for function _Display_Scan5
psect	text25
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	161
	global	__size_of_Display_Scan5
	__size_of_Display_Scan5	equ	__end_of_Display_Scan5-_Display_Scan5
	
_Display_Scan5:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan5: [wreg-fsr0h+status,2+status,0]
	line	163
	
i1l3007:	
;LED_188.c: 163: TRISB4 = 0;RB4 = 0;;
	bcf	(44/8),(44)&7	;volatile
	bcf	(52/8),(52)&7	;volatile
	line	164
	
i1l3009:	
;LED_188.c: 164: if(num_hund[hundreds] & 0x02)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(1)&7
	goto	u180_21
	goto	u180_20
u180_21:
	goto	i1l1410
u180_20:
	line	165
	
i1l3011:	
;LED_188.c: 165: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1410:	
	bsf	(50/8),(50)&7	;volatile
	line	166
	
i1l3013:	
;LED_188.c: 166: if(num_hund[hundreds] & 0x01)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u181_21
	goto	u181_20
u181_21:
	goto	i1l1411
u181_20:
	line	167
	
i1l3015:	
;LED_188.c: 167: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1411:	
	bsf	(49/8),(49)&7	;volatile
	line	168
	
i1l1412:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan5
	__end_of_Display_Scan5:
	signat	_Display_Scan5,89
	global	_Display_Scan4

;; *************** function _Display_Scan4 *****************
;; Defined at:
;;		line 147 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text26,local,class=CODE,delta=2,merge=1,group=0
	line	147
global __ptext26
__ptext26:	;psect for function _Display_Scan4
psect	text26
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	147
	global	__size_of_Display_Scan4
	__size_of_Display_Scan4	equ	__end_of_Display_Scan4-_Display_Scan4
	
_Display_Scan4:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan4: [wreg-fsr0h+status,2+status,0]
	line	149
	
i1l2989:	
;LED_188.c: 149: TRISB3 = 0;RB3 = 0;;
	bcf	(43/8),(43)&7	;volatile
	bcf	(51/8),(51)&7	;volatile
	line	150
	
i1l2991:	
;LED_188.c: 150: if(nums[unit] & 0x04)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(2)&7
	goto	u176_21
	goto	u176_20
u176_21:
	goto	i1l1403
u176_20:
	line	151
	
i1l2993:	
;LED_188.c: 151: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1403:	
	bsf	(48/8),(48)&7	;volatile
	line	152
	
i1l2995:	
;LED_188.c: 152: if(num_hund[hundreds] & 0x04)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(2)&7
	goto	u177_21
	goto	u177_20
u177_21:
	goto	i1l1404
u177_20:
	line	153
	
i1l2997:	
;LED_188.c: 153: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1404:	
	bsf	(49/8),(49)&7	;volatile
	line	154
	
i1l2999:	
;LED_188.c: 154: if(num_hund[hundreds] & 0x08)
	movf	(_hundreds),w
	addlw	low(_num_hund|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u178_21
	goto	u178_20
u178_21:
	goto	i1l1405
u178_20:
	line	155
	
i1l3001:	
;LED_188.c: 155: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1405:	
	bsf	(50/8),(50)&7	;volatile
	line	156
	
i1l3003:	
;LED_188.c: 156: if(nums[tens] & 0x01)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u179_21
	goto	u179_20
u179_21:
	goto	i1l1406
u179_20:
	line	157
	
i1l3005:	
;LED_188.c: 157: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1406:	
	bsf	(52/8),(52)&7	;volatile
	line	158
	
i1l1407:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan4
	__end_of_Display_Scan4:
	signat	_Display_Scan4,89
	global	_Display_Scan3

;; *************** function _Display_Scan3 *****************
;; Defined at:
;;		line 133 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text27,local,class=CODE,delta=2,merge=1,group=0
	line	133
global __ptext27
__ptext27:	;psect for function _Display_Scan3
psect	text27
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	133
	global	__size_of_Display_Scan3
	__size_of_Display_Scan3	equ	__end_of_Display_Scan3-_Display_Scan3
	
_Display_Scan3:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan3: [wreg-fsr0h+status,2+status,0]
	line	135
	
i1l2971:	
;LED_188.c: 135: TRISB2 = 0;RB2 = 0;;
	bcf	(42/8),(42)&7	;volatile
	bcf	(50/8),(50)&7	;volatile
	line	136
	
i1l2973:	
;LED_188.c: 136: if(nums[unit] & 0x10)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(4)&7
	goto	u172_21
	goto	u172_20
u172_21:
	goto	i1l1396
u172_20:
	line	137
	
i1l2975:	
;LED_188.c: 137: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1396:	
	bsf	(48/8),(48)&7	;volatile
	line	138
	
i1l2977:	
;LED_188.c: 138: if(nums[tens] & 0x40)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(6)&7
	goto	u173_21
	goto	u173_20
u173_21:
	goto	i1l1397
u173_20:
	line	139
	
i1l2979:	
;LED_188.c: 139: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1397:	
	bsf	(49/8),(49)&7	;volatile
	line	140
	
i1l2981:	
;LED_188.c: 140: if(nums[tens] & 0x10)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(4)&7
	goto	u174_21
	goto	u174_20
u174_21:
	goto	i1l1398
u174_20:
	line	141
	
i1l2983:	
;LED_188.c: 141: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1398:	
	bsf	(51/8),(51)&7	;volatile
	line	142
	
i1l2985:	
;LED_188.c: 142: if(nums[tens] & 0x02)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(1)&7
	goto	u175_21
	goto	u175_20
u175_21:
	goto	i1l1399
u175_20:
	line	143
	
i1l2987:	
;LED_188.c: 143: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1399:	
	bsf	(52/8),(52)&7	;volatile
	line	144
	
i1l1400:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan3
	__end_of_Display_Scan3:
	signat	_Display_Scan3,89
	global	_Display_Scan2

;; *************** function _Display_Scan2 *****************
;; Defined at:
;;		line 119 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text28,local,class=CODE,delta=2,merge=1,group=0
	line	119
global __ptext28
__ptext28:	;psect for function _Display_Scan2
psect	text28
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	119
	global	__size_of_Display_Scan2
	__size_of_Display_Scan2	equ	__end_of_Display_Scan2-_Display_Scan2
	
_Display_Scan2:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan2: [wreg-fsr0h+status,2+status,0]
	line	121
	
i1l2953:	
;LED_188.c: 121: TRISB1 = 0;RB1 = 0;;
	bcf	(41/8),(41)&7	;volatile
	bcf	(49/8),(49)&7	;volatile
	line	122
	
i1l2955:	
;LED_188.c: 122: if(nums[unit] &0x40)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(6)&7
	goto	u168_21
	goto	u168_20
u168_21:
	goto	i1l1389
u168_20:
	line	123
	
i1l2957:	
;LED_188.c: 123: TRISB0 = 0;RB0 = 1;;
	bcf	(40/8),(40)&7	;volatile
	
i1l1389:	
	bsf	(48/8),(48)&7	;volatile
	line	124
	
i1l2959:	
;LED_188.c: 124: if(nums[tens] & 0x20)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(5)&7
	goto	u169_21
	goto	u169_20
u169_21:
	goto	i1l1390
u169_20:
	line	125
	
i1l2961:	
;LED_188.c: 125: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1390:	
	bsf	(50/8),(50)&7	;volatile
	line	126
	
i1l2963:	
;LED_188.c: 126: if(nums[tens] & 0x08)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u170_21
	goto	u170_20
u170_21:
	goto	i1l1391
u170_20:
	line	127
	
i1l2965:	
;LED_188.c: 127: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1391:	
	bsf	(51/8),(51)&7	;volatile
	line	128
	
i1l2967:	
;LED_188.c: 128: if(nums[tens] & 0x04)
	movf	(_tens),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(2)&7
	goto	u171_21
	goto	u171_20
u171_21:
	goto	i1l1392
u171_20:
	line	129
	
i1l2969:	
;LED_188.c: 129: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1392:	
	bsf	(52/8),(52)&7	;volatile
	line	130
	
i1l1393:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan2
	__end_of_Display_Scan2:
	signat	_Display_Scan2,89
	global	_Display_Scan1

;; *************** function _Display_Scan1 *****************
;; Defined at:
;;		line 105 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text29,local,class=CODE,delta=2,merge=1,group=0
	line	105
global __ptext29
__ptext29:	;psect for function _Display_Scan1
psect	text29
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	105
	global	__size_of_Display_Scan1
	__size_of_Display_Scan1	equ	__end_of_Display_Scan1-_Display_Scan1
	
_Display_Scan1:	
;incstack = 0
	opt	stack 2
; Regs used in _Display_Scan1: [wreg-fsr0h+status,2+status,0]
	line	107
	
i1l2935:	
;LED_188.c: 107: TRISB0 = 0;RB0 = 0;;
	bcf	(40/8),(40)&7	;volatile
	bcf	(48/8),(48)&7	;volatile
	line	108
	
i1l2937:	
;LED_188.c: 108: if(nums[unit] & 0x20)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	bcf	status, 7	;select IRP bank1
	btfss	indf,(5)&7
	goto	u164_21
	goto	u164_20
u164_21:
	goto	i1l1382
u164_20:
	line	109
	
i1l2939:	
;LED_188.c: 109: TRISB1 = 0;RB1 = 1;;
	bcf	(41/8),(41)&7	;volatile
	
i1l1382:	
	bsf	(49/8),(49)&7	;volatile
	line	110
	
i1l2941:	
;LED_188.c: 110: if(nums[unit] & 0x08)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(3)&7
	goto	u165_21
	goto	u165_20
u165_21:
	goto	i1l1383
u165_20:
	line	111
	
i1l2943:	
;LED_188.c: 111: TRISB2 = 0;RB2 = 1;;
	bcf	(42/8),(42)&7	;volatile
	
i1l1383:	
	bsf	(50/8),(50)&7	;volatile
	line	112
	
i1l2945:	
;LED_188.c: 112: if(nums[unit] & 0x02)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(1)&7
	goto	u166_21
	goto	u166_20
u166_21:
	goto	i1l1384
u166_20:
	line	113
	
i1l2947:	
;LED_188.c: 113: TRISB3 = 0;RB3 = 1;;
	bcf	(43/8),(43)&7	;volatile
	
i1l1384:	
	bsf	(51/8),(51)&7	;volatile
	line	114
	
i1l2949:	
;LED_188.c: 114: if(nums[unit] &0x01)
	movf	(_unit),w
	addlw	low(_nums|((0x0)<<8))&0ffh
	movwf	fsr0
	btfss	indf,(0)&7
	goto	u167_21
	goto	u167_20
u167_21:
	goto	i1l1385
u167_20:
	line	115
	
i1l2951:	
;LED_188.c: 115: TRISB4 = 0;RB4 = 1;;
	bcf	(44/8),(44)&7	;volatile
	
i1l1385:	
	bsf	(52/8),(52)&7	;volatile
	line	116
	
i1l1386:	
	return
	opt stack 0
GLOBAL	__end_of_Display_Scan1
	__end_of_Display_Scan1:
	signat	_Display_Scan1,89
	global	_Charge_num

;; *************** function _Charge_num *****************
;; Defined at:
;;		line 11 in file "C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
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
psect	text30,local,class=CODE,delta=2,merge=1,group=0
	line	11
global __ptext30
__ptext30:	;psect for function _Charge_num
psect	text30
	file	"C:\Users\86135\Desktop\项目实践\SC8F072_double_key\LED_188.c"
	line	11
	global	__size_of_Charge_num
	__size_of_Charge_num	equ	__end_of_Charge_num-_Charge_num
	
_Charge_num:	
;incstack = 0
	opt	stack 2
; Regs used in _Charge_num: [wreg+status,2+status,0+pclath+cstack]
	line	13
	
i1l3451:	
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
	
i1l3453:	
;LED_188.c: 16: if(hundred)
	movf	((Charge_num@hundred)),w
	btfsc	status,2
	goto	u240_21
	goto	u240_20
u240_21:
	goto	i1l3457
u240_20:
	line	18
	
i1l3455:	
;LED_188.c: 17: {
;LED_188.c: 18: hundreds = 4;
	movlw	low(04h)
	movwf	(_hundreds)	;volatile
	line	19
;LED_188.c: 19: }
	goto	i1l1361
	line	22
	
i1l3457:	
;LED_188.c: 20: else
;LED_188.c: 21: {
;LED_188.c: 22: hundreds = 2;
	movlw	low(02h)
	movwf	(_hundreds)	;volatile
	line	24
	
i1l1361:	
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
psect	text31,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbmod.c"
	line	4
global __ptext31
__ptext31:	;psect for function ___lbmod
psect	text31
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
	
i1l3233:	
	movlw	low(08h)
	movwf	(___lbmod@counter)
	line	10
	
i1l3235:	
	clrf	(___lbmod@rem)
	line	12
	
i1l3237:	
	movf	(___lbmod@dividend),w
	movwf	(??___lbmod+0)+0
	movlw	07h
u225_25:
	clrc
	rrf	(??___lbmod+0)+0,f
	addlw	-1
	skipz
	goto	u225_25
	clrc
	rlf	(___lbmod@rem),w
	iorwf	0+(??___lbmod+0)+0,w
	movwf	(___lbmod@rem)
	line	13
	
i1l3239:	
	clrc
	rlf	(___lbmod@dividend),f
	line	14
	
i1l3241:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),w
	skipc
	goto	u226_21
	goto	u226_20
u226_21:
	goto	i1l3245
u226_20:
	line	15
	
i1l3243:	
	movf	(___lbmod@divisor),w
	subwf	(___lbmod@rem),f
	line	16
	
i1l3245:	
	decfsz	(___lbmod@counter),f
	goto	u227_21
	goto	u227_20
u227_21:
	goto	i1l3237
u227_20:
	line	17
	
i1l3247:	
	movf	(___lbmod@rem),w
	line	18
	
i1l1700:	
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
psect	text32,local,class=CODE,delta=2,merge=1,group=1
	file	"C:\Users\86135\Desktop\项目实践\SCMCU_IDE_V2.00.15\SCMCU_IDE_V2.00.15\data\sources\common\lbdiv.c"
	line	4
global __ptext32
__ptext32:	;psect for function ___lbdiv
psect	text32
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
	
i1l3209:	
	clrf	(___lbdiv@quotient)
	line	10
	
i1l3211:	
	movf	((___lbdiv@divisor)),w
	btfsc	status,2
	goto	u221_21
	goto	u221_20
u221_21:
	goto	i1l3229
u221_20:
	line	11
	
i1l3213:	
	clrf	(___lbdiv@counter)
	incf	(___lbdiv@counter),f
	line	12
	goto	i1l3217
	
i1l1689:	
	line	13
	clrc
	rlf	(___lbdiv@divisor),f
	line	14
	
i1l3215:	
	incf	(___lbdiv@counter),f
	line	12
	
i1l3217:	
	btfss	(___lbdiv@divisor),(7)&7
	goto	u222_21
	goto	u222_20
u222_21:
	goto	i1l1689
u222_20:
	line	16
	
i1l1691:	
	line	17
	clrc
	rlf	(___lbdiv@quotient),f
	line	18
	
i1l3219:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),w
	skipc
	goto	u223_21
	goto	u223_20
u223_21:
	goto	i1l3225
u223_20:
	line	19
	
i1l3221:	
	movf	(___lbdiv@divisor),w
	subwf	(___lbdiv@dividend),f
	line	20
	
i1l3223:	
	bsf	(___lbdiv@quotient)+(0/8),(0)&7
	line	22
	
i1l3225:	
	clrc
	rrf	(___lbdiv@divisor),f
	line	23
	
i1l3227:	
	decfsz	(___lbdiv@counter),f
	goto	u224_21
	goto	u224_20
u224_21:
	goto	i1l1691
u224_20:
	line	25
	
i1l3229:	
	movf	(___lbdiv@quotient),w
	line	26
	
i1l1694:	
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
