INDF		 EQU 		 H'0000'
TMR0		 EQU 		 H'0001'
PCL		     EQU 		 H'0002'
STATUS		 EQU 		 H'0003'
FSR		     EQU 		 H'0004'
PORTA		 EQU 		 H'0005'
PORTB		 EQU 		 H'0006'
WPUA		 EQU 		 H'0007'
WPDA		 EQU 		 H'0008'
IOCA		 EQU 		 H'0009'
PCLATH		 EQU 		 H'000A'
INTCON		 EQU 		 H'000B'
PIR1		 EQU 		 H'000C'
PIR2		 EQU 		 H'000D'
PWMD2L		 EQU 		 H'000E'
PWMD3L		 EQU 		 H'000F'
PWMD4L		 EQU 		 H'0010'
TMR2		 EQU 		 H'0011'
T2CON		 EQU 		 H'0012'
LCDCON0		 EQU 		 H'0013'
LCDCON1		 EQU 		 H'0014'
LCDCON		 EQU 		 H'0015'
PWMD0L		 EQU 		 H'0016'
PWMD1L		 EQU 		 H'0017'
PWMD01H		 EQU 		 H'0018'
PWMTL		 EQU 		 H'0019'
PWMTH		 EQU 		 H'001A'
PWMCON		 EQU 		 H'001B'
PWMD23H		 EQU 		 H'001C'
PWM4TL		 EQU 		 H'001D'
ADRESH		 EQU 		 H'001E'
ADCON0		 EQU 		 H'001F'
OPTION_REG	 EQU 		 H'0081'
TRISA		 EQU 		 H'0085'
TRISB		 EQU 		 H'0086'
WPDB		 EQU 		 H'0087'
WDTCON		 EQU 		 H'0088'
PIE1		 EQU 		 H'008C'
PIE2		 EQU 		 H'008D'
PWMCON1		 EQU 		 H'008E'
OSCCON		 EQU 		 H'008F'
LVDCON		 EQU 		 H'0091'
PR2		     EQU 		 H'0092'
ANSEL		 EQU 		 H'0093'
ANSELH		 EQU 		 H'0094'
WPUB		 EQU 		 H'0095'
IOCB		 EQU 		 H'0096'
TABLE_SPH	 EQU 		 H'0097'
TABLE_SPL	 EQU 		 H'0098'
TABLE_DATAH	 EQU 		 H'0099'
ADRESL		 EQU 		 H'009E'
ADCON1		 EQU 		 H'009F'

;------------------------ STATUS  Bits------------------------
RP0		 EQU 		H'05'
TO		 EQU 		H'04'
PD		 EQU 		H'03'
Z		 EQU 		H'02'
DC		 EQU 		H'01'
C		 EQU 		H'00'

;------------------------ PORTA  Bits------------------------
RA6		 EQU 		H'06'
RA5		 EQU 		H'05'
RA4		 EQU 		H'04'
RA3		 EQU 		H'03'
RA2		 EQU 		H'02'
RA1		 EQU 		H'01'
RA0		 EQU 		H'00'

;------------------------ PORTB  Bits------------------------
RB6		 EQU 		H'06'
RB5		 EQU 		H'05'
RB4		 EQU 		H'04'
RB3		 EQU 		H'03'
RB2		 EQU 		H'02'
RB1		 EQU 		H'01'
RB0		 EQU 		H'00'

;------------------------ WPUA  Bits------------------------
WPUA6		 EQU 		H'06'
WPUA5		 EQU 		H'05'
WPUA4		 EQU 		H'04'
WPUA3		 EQU 		H'03'
WPUA2		 EQU 		H'02'
WPUA1		 EQU 		H'01'
WPUA0		 EQU 		H'00'

;------------------------ WPDA  Bits------------------------
WPDA6		 EQU 		H'06'
WPDA5		 EQU 		H'05'
WPDA4		 EQU 		H'04'
WPDA3		 EQU 		H'03'
WPDA2		 EQU 		H'02'
WPDA1		 EQU 		H'01'
WPDA0		 EQU 		H'00'

;------------------------ IOCA  Bits------------------------
IOCA6		 EQU 		H'06'
IOCA5		 EQU 		H'05'
IOCA4		 EQU 		H'04'
IOCA3		 EQU 		H'03'
IOCA2		 EQU 		H'02'
IOCA1		 EQU 		H'01'
IOCA0		 EQU 		H'00'

;------------------------ INTCON  Bits------------------------
GIE		 EQU 		H'07'
PEIE		 EQU 		H'06'
T0IE		 EQU 		H'05'
INTE		 EQU 		H'04'
RBIE		 EQU 		H'03'
T0IF		 EQU 		H'02'
INTF		 EQU 		H'01'
RBIF		 EQU 		H'00'

;------------------------ PIR1  Bits------------------------
RAIF		 EQU 		H'03'
PWMIF		 EQU 		H'02'
TMR2IF		 EQU 		H'01'
ADIF		 EQU 		H'00'

;------------------------ PIR2  Bits------------------------
LVDIF		 EQU 		H'00'

;------------------------ T2CON  Bits------------------------
TOUTPS3		 EQU 		H'06'
TOUTPS2		 EQU 		H'05'
TOUTPS1		 EQU 		H'04'
TOUTPS0		 EQU 		H'03'
TMR2ON		 EQU 		H'02'
T2CKPS1		 EQU 		H'01'
T2CKPS0		 EQU 		H'00'

;------------------------ LCDCON0  Bits------------------------
COM6EN		 EQU 		H'06'
COM5EN		 EQU 		H'05'
COM4EN		 EQU 		H'04'
COM3EN		 EQU 		H'03'
COM2EN		 EQU 		H'02'
COM1EN		 EQU 		H'01'
COM0EN		 EQU 		H'00'

;------------------------ LCDCON1  Bits------------------------
COM14EN		 EQU 		H'06'
COM13EN		 EQU 		H'05'
COM12EN		 EQU 		H'04'
COM11EN		 EQU 		H'03'
COM9EN		 EQU 		H'01'
COM8EN		 EQU 		H'00'

;------------------------ LCDCON  Bits------------------------
LCDEN		 EQU 		H'07'
LCD_ISLE1		 EQU 		H'01'
LCD_ISLE0		 EQU 		H'00'

;------------------------ PWMD01H  Bits------------------------
PWMD19		 EQU 		H'03'
PWMD18		 EQU 		H'02'
PWMD09		 EQU 		H'01'
PWMD08		 EQU 		H'00'

;------------------------ PWMCON  Bits------------------------
CLKDIV2		 EQU 		H'07'
CLKDIV1		 EQU 		H'06'
CLKDIV0		 EQU 		H'05'
PWM1DIR		 EQU 		H'03'
PWM0DIR		 EQU 		H'02'
PWM1EN		 EQU 		H'01'
PWM0EN		 EQU 		H'00'

;------------------------ PWMD23H  Bits------------------------
PWMD39		 EQU 		H'03'
PWMD38		 EQU 		H'02'
PWMD29		 EQU 		H'01'
PWMD28		 EQU 		H'00'

;------------------------ ADCON0  Bits------------------------
ADCS1		 EQU 		H'07'
ADCS0		 EQU 		H'06'
CHS3		 EQU 		H'05'
CHS2		 EQU 		H'04'
CHS1		 EQU 		H'03'
CHS0		 EQU 		H'02'
GODONE		 EQU 		H'01'
ADON		 EQU 		H'00'

;------------------------ OPTION_REG  Bits------------------------
INTEDG		 EQU 		H'06'
T0CS		 EQU 		H'05'
T0SE		 EQU 		H'04'
PSA		 EQU 		H'03'
PS2		 EQU 		H'02'
PS1		 EQU 		H'01'
PS0		 EQU 		H'00'

;------------------------ TRISA  Bits------------------------
TRISA6		 EQU 		H'06'
TRISA5		 EQU 		H'05'
TRISA4		 EQU 		H'04'
TRISA3		 EQU 		H'03'
TRISA2		 EQU 		H'02'
TRISA1		 EQU 		H'01'
TRISA0		 EQU 		H'00'

;------------------------ TRISB  Bits------------------------
TRISB6		 EQU 		H'06'
TRISB5		 EQU 		H'05'
TRISB4		 EQU 		H'04'
TRISB3		 EQU 		H'03'
TRISB2		 EQU 		H'02'
TRISB1		 EQU 		H'01'
TRISB0		 EQU 		H'00'

;------------------------ WPDB  Bits------------------------
WPDB6		 EQU 		H'06'
WPDB5		 EQU 		H'05'
WPDB4		 EQU 		H'04'
WPDB3		 EQU 		H'03'
WPDB1		 EQU 		H'01'
WPDB0		 EQU 		H'00'

;------------------------ WDTCON  Bits------------------------
SWDTEN		 EQU 		H'00'

;------------------------ PIE1  Bits------------------------
RAIE		 EQU 		H'03'
PWMIE		 EQU 		H'02'
TMR2IE		 EQU 		H'01'
ADIE		 EQU 		H'00'

;------------------------ PIE2  Bits------------------------
LVDIE		 EQU 		H'00'

;------------------------ PWMCON1  Bits------------------------
PMW4DIR		 EQU 		H'05'
PWM3DIR		 EQU 		H'04'
PWM2DIR		 EQU 		H'03'
PWM4EN		 EQU 		H'02'
PWM3EN		 EQU 		H'01'
PWM2EN		 EQU 		H'00'

;------------------------ OSCCON  Bits------------------------
IRCF2		 EQU 		H'06'
IRCF1		 EQU 		H'05'
IRCF0		 EQU 		H'04'

;------------------------ LVDCON  Bits------------------------
LVD_RES		 EQU 		H'07'
LVD_SEL2		 EQU 		H'03'
LVD_SEL1		 EQU 		H'02'
LVD_SEL0		 EQU 		H'01'
LVDEN		 EQU 		H'00'

;------------------------ ANSEL  Bits------------------------
ANS6		 EQU 		H'06'
ANS5		 EQU 		H'05'
ANS4		 EQU 		H'04'
ANS3		 EQU 		H'03'
ANS2		 EQU 		H'02'
ANS1		 EQU 		H'01'
ANS0		 EQU 		H'00'

;------------------------ ANSELH  Bits------------------------
ANS14		 EQU 		H'06'
ANS13		 EQU 		H'05'
ANS12		 EQU 		H'04'
ANS11		 EQU 		H'03'
ANS9		 EQU 		H'01'
ANS8		 EQU 		H'00'

;------------------------ WPUB  Bits------------------------
WPUB6		 EQU 		H'06'
WPUB5		 EQU 		H'05'
WPUB4		 EQU 		H'04'
WPUB3		 EQU 		H'03'
WPUB2		 EQU 		H'02'
WPUB1		 EQU 		H'01'
WPUB0		 EQU 		H'00'

;------------------------ IOCB  Bits------------------------
IOCB6		 EQU 		H'06'
IOCB5		 EQU 		H'05'
IOCB4		 EQU 		H'04'
IOCB3		 EQU 		H'03'
IOCB2		 EQU 		H'02'
IOCB1		 EQU 		H'01'
IOCB0		 EQU 		H'00'

;------------------------ ADCON1  Bits------------------------
ADFM		 EQU 		H'07'
TADSEL		 EQU 		H'03'
LDOEN		 EQU 		H'02'
LDOSEL		 EQU 		H'00'

