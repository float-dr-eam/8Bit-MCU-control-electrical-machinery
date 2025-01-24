
	; Microchip MPLAB XC8 C Compiler V1.45
	; Copyright (C) 1984-2017 HI-TECH Software

	; Auto-generated runtime startup code for final link stage.

	;
	; Compiler options:
	;
	; -oSC8F072_Pwm_Demo.cof -mSC8F072_Pwm_Demo.map \
	; --summary=default,-psect,-class --fill=0xFFFF --output=intel \
	; SC8F072_Pwm_Demo.p1 LED_188.p1 KEY.p1 PWM.p1 --chip=SC8F072 -P \
	; --runtime=default, --opt=-local,-asmfile,+asm,-speed,+space,-debug \
	; -E+cmscerr.err -D__DEBUG=1 -g --asmlist --warn=-9 \
	; --stack=compiled:auto:auto:auto --addrqual=request --mode=pro \
	; --errformat=Error[%n]:	%f	第%l行	%s --msgformat=Advisory[%n]	%s \
	; --warnformat=Warning[%n]:	%f	第%l行	%s
	;


	processor	SC8F072

	global	_main,start,reset_vec
	fnroot	_main
	psect	config,class=CONFIG,delta=2,noexec
	psect	idloc,class=IDLOC,delta=2,noexec
	psect	code,class=CODE,delta=2
	psect	powerup,class=CODE,delta=2
	psect	reset_vec,class=CODE,delta=2
	psect	maintext,class=CODE,delta=2
	C	set	0
	Z	set	2
	PCL	set	2
	INDF	set	0

	STATUS	equ	3
	PCLATH	equ	0Ah

	psect	eeprom_data,class=EEDATA,delta=2,space=3,noexec
	psect	intentry,class=CODE,delta=2
	psect	functab,class=ENTRY,delta=2
	global	intlevel0,intlevel1,intlevel2, intlevel3, intlevel4, intlevel5
intlevel0:
intlevel1:
intlevel2:
intlevel3:
intlevel4:
intlevel5:
	psect	init,class=CODE,delta=2
	psect	cinit,class=CODE,delta=2
	psect	text,class=CODE,delta=2
	psect	end_init,class=CODE,delta=2
	psect	clrtext,class=CODE,delta=2
	FSR	set	4
	psect	strings,class=CODE,delta=2,reloc=256

	global stacklo, stackhi
	stacklo	equ	0
	stackhi	equ	0


	psect	stack,class=STACK,space=2,noexec
	global ___sp,___int_sp
	___sp:
	___int_sp:
	psect	reset_vec
reset_vec:
	; No powerup routine
	global start

; jump to start
	goto	start & 0x7FF | (reset_vec & not 0x7FF)



	psect	init
start
	psect	end_init
	global start_initialization
	ljmp start_initialization	;jump to C runtime clear & initialization


psect common,class=COMMON,space=1
psect bank0,class=BANK0,space=1
psect bank1,class=BANK1,space=1
psect ram,class=RAM,space=1
psect abs1,class=ABS1,space=1
psect sfr0,class=SFR0,space=1
psect sfr1,class=SFR1,space=1


	end	start
