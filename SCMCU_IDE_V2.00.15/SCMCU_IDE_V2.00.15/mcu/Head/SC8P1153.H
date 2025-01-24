;**************************************************************************
;-----	BANK0	Register	-----------------------------------------------------
INDF				EQU		H'0000'	
TMR0				EQU		H'0001'	
PCL					EQU		H'0002'	
STATUS				EQU		H'0003'	
FSR					EQU		H'0004'	
PORTB				EQU		H'0005'	
TRISB				EQU		H'0006'	
OPTION_REG			EQU		H'0007'	
OSCCON				EQU		H'0008'	
INTCON				EQU		H'0009'	
PCLATH				EQU		H'000A'	
PDCONB				EQU		H'000B'	
ODCONB				EQU		H'000C'	
WPUB				EQU		H'000D'	
IOCB				EQU		H'000E'	
TMR0PRD				EQU		H'000F'	
PWMCTR0				EQU		H'0010'	
PWMCTR1				EQU		H'0011'	
PWMCTR2				EQU		H'0012'	
PWMR				EQU		H'0013'	
PWM_PRD				EQU		H'0014'	
DTCON				EQU		H'0015'	
DTREG				EQU		H'0016'	
PORTA				EQU		H'0017'	
TRISA				EQU		H'0018'	
UPDOWNA				EQU		H'0019'	

;**************************************************************************
;-----	STATUS	Bits	--------------------------------------------------------
TO					EQU		H'0004'
NOT_TO				EQU		H'0004'
PD					EQU		H'0003'
NOT_PD				EQU		H'0003'
Z					EQU		H'0002'
DC					EQU		H'0001'
C					EQU		H'0000'

;-----	PORTB	Bits	--------------------------------------------------------
PB7					EQU		H'0007'
PB6					EQU		H'0006'
PB5					EQU		H'0005'
PB4					EQU		H'0004'
PB3					EQU		H'0003'
PB2					EQU		H'0002'
PB1					EQU		H'0001'
PB0					EQU		H'0000'

;-----	PORTB	Bits	--------------------------------------------------------
PORTB7				EQU		H'0007'
PORTB6				EQU		H'0006'
PORTB5				EQU		H'0005'
PORTB4				EQU		H'0004'
PORTB3				EQU		H'0003'
PORTB2				EQU		H'0002'
PORTB1				EQU		H'0001'
PORTB0				EQU		H'0000'

;-----	TRISB	Bits	--------------------------------------------------------
TRISB7				EQU		H'0007'
TRISB6				EQU		H'0006'
TRISB5				EQU		H'0005'
TRISB4				EQU		H'0004'
TRISB3				EQU		H'0003'
TRISB2				EQU		H'0002'
TRISB1				EQU		H'0001'
TRISB0				EQU		H'0000'

;-----	OPTION_REG	Bits	----------------------------------------------------
XT_EN				EQU		H'0007'
T0SYNC				EQU		H'0006'
T0CS				EQU		H'0005'
T0SE				EQU		H'0004'
PSA					EQU		H'0003'
PS2					EQU		H'0002'
PS1					EQU		H'0001'
PS0					EQU		H'0000'

;-----	OSCCON	Bits	--------------------------------------------------------
SWDTEN				EQU		H'0007'
IRCF2				EQU		H'0006'
IRCF1				EQU		H'0005'
IRCF0				EQU		H'0004'
TMR0EN				EQU		H'0000'

;-----	INTCON	Bits	--------------------------------------------------------
GIE					EQU		H'0007'
INTEG				EQU		H'0006'
T0IE				EQU		H'0005'
INTE				EQU		H'0004'
RBIE				EQU		H'0003'
T0IF				EQU		H'0002'
INTF				EQU		H'0001'
RBIF				EQU		H'0000'

;-----	PDCONB	Bits	--------------------------------------------------------
PDCONB7				EQU		H'0007'
PDCONB6				EQU		H'0006'
PDCONB5				EQU		H'0005'
PDCONB4				EQU		H'0004'
PDCONB2				EQU		H'0002'
PDCONB1				EQU		H'0001'
PDCONB0				EQU		H'0000'


;-----	ODCONB	Bits	--------------------------------------------------------
ODCONB7				EQU		H'0007'
ODCONB6				EQU		H'0006'
ODCONB5				EQU		H'0005'
ODCONB4				EQU		H'0004'
ODCONB2				EQU		H'0002'
ODCONB1				EQU		H'0001'
ODCONB0				EQU		H'0000'

;-----	WPUB	Bits	--------------------------------------------------------
WPUB7				EQU		H'0007'
WPUB6				EQU		H'0006'
WPUB5				EQU		H'0005'
WPUB4				EQU		H'0004'
WPUB3				EQU		H'0003'
WPUB2				EQU		H'0002'
WPUB1				EQU		H'0001'
WPUB0				EQU		H'0000'

;-----	IOCB	Bits	--------------------------------------------------------
IOCB7				EQU		H'0007'
IOCB6				EQU		H'0006'
IOCB5				EQU		H'0005'
IOCB4				EQU		H'0004'
IOCB3				EQU		H'0003'
IOCB2				EQU		H'0002'
IOCB1				EQU		H'0001'
IOCB0				EQU		H'0000'

;-----	PWMCTR0	Bits	--------------------------------------------------------
PWMR49				EQU		H'0007'
PWMR48				EQU		H'0006'
PWMEN4				EQU		H'0004'
PWMEN3				EQU		H'0003'
PWMEN2				EQU		H'0002'
PWMEN1				EQU		H'0001'
PWMEN0				EQU		H'0000'

PWM4EN				EQU		H'0004'
PWM3EN				EQU		H'0003'
PWM2EN				EQU		H'0002'
PWM1EN				EQU		H'0001'
PWM0EN				EQU		H'0000'

;-----	PWMCTR1	Bits	--------------------------------------------------------
PWMR39				EQU		H'0007'
PWMR38				EQU		H'0006'
PWMR29				EQU		H'0005'
PWMR28				EQU		H'0004'
PWMR19				EQU		H'0003'
PWMR18				EQU		H'0002'
PWMR09				EQU		H'0001'
PWMR08				EQU		H'0000'

;-----	PWMCTR2	Bits	--------------------------------------------------------
PWMPRD9				EQU		H'0007'
PWMPRD8				EQU		H'0006'
T2CKPS1				EQU		H'0005'
T2CKPS0				EQU		H'0004'
SEL2				EQU		H'0002'
SEL1				EQU		H'0001'
SEL0				EQU		H'0000'

PWMCK1				EQU		H'0005'
PWMCK0				EQU		H'0004'
PWMS2				EQU		H'0002'
PWMS1				EQU		H'0001'
PWMS0				EQU		H'0000'

;-----	DTCON	Bits	--------------------------------------------------------
DTSEL1				EQU		H'0007'
DTSEL0				EQU		H'0006'
DTSEL				EQU		H'0006'
ENDT1				EQU		H'0003'
ENDT0				EQU		H'0002'
ENCM1				EQU		H'0001'
ENCM0				EQU		H'0000'

;-----	PORTA	Bits	--------------------------------------------------------
PA3					EQU		H'0003'
PA2					EQU		H'0002'
PA1					EQU		H'0001'
PA0					EQU		H'0000'

;-----	PORTA	Bits	--------------------------------------------------------
PORTA3					EQU		H'0003'
PORTA2					EQU		H'0002'
PORTA1					EQU		H'0001'
PORTA0					EQU		H'0000'

;-----	TRISA	Bits	--------------------------------------------------------
TRISA3				EQU		H'0003'
TRISA2				EQU		H'0002'
TRISA1				EQU		H'0001'
TRISA0				EQU		H'0000'

;-----	UPDOWNA	Bits	--------------------------------------------------------
WPUA3				EQU		H'0007'
WPUA2				EQU		H'0006'
WPUA1				EQU		H'0005'
WPUA0				EQU		H'0004'
PDCONA3				EQU		H'0003'
PDCONA2				EQU		H'0002'
PDCONA1				EQU		H'0001'
PDCONA0				EQU		H'0000'