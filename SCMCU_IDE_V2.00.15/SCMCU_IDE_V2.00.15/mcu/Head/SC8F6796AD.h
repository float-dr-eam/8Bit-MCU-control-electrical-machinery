

INDF		 EQU 		 H'000'
TMR0		 EQU 		 H'001'
PCL		 EQU 		 H'002'
STATUS		 EQU 		 H'003'
FSR		 EQU 		 H'004'
PORTA		 EQU 		 H'005'
PORTB		 EQU 		 H'006'
PORTC		 EQU 		 H'007'
PORTD		 EQU 		 H'008'
ANSEL0		 EQU 		 H'009'
PCLATH		 EQU 		 H'00A'
INTCON		 EQU 		 H'00B'
PIR1		 EQU 		 H'00C'
PIR2		 EQU 		 H'00D'
TMR1L		 EQU 		 H'00E'
TMR1H		 EQU 		 H'00F'
T1CON		 EQU 		 H'010'
TMR2		 EQU 		 H'011'
T2CON		 EQU 		 H'012'
SSPBUF		 EQU 		 H'013'
SSPCON		 EQU 		 H'014'
CPTRL		 EQU 		 H'015'
CPTRH		 EQU 		 H'016'
CPTCON		 EQU 		 H'017'
RCSTA0		 EQU 		 H'018'
TXREG0		 EQU 		 H'019'
RCREG0		 EQU 		 H'01A'
TABLE_SPH		 EQU 		 H'01B'
TABLE_SPL		 EQU 		 H'01C'
TABLE_DATAH		 EQU 		 H'01D'
TXSTA0		 EQU 		 H'01E'
SPBRG0		 EQU 		 H'01F'
OPTION_REG		 EQU 		 H'081'
TRISA		 EQU 		 H'085'
TRISB		 EQU 		 H'086'
TRISC		 EQU 		 H'087'
TRISD		 EQU 		 H'088'
ANSEL1		 EQU 		 H'089'
PIE1		 EQU 		 H'08C'
PIE2		 EQU 		 H'08D'
WPUD		 EQU 		 H'08E'
OSCCON		 EQU 		 H'08F'
WDTCON		 EQU 		 H'090'
SSPCON2		 EQU 		 H'091'
PR2		 EQU 		 H'092'
SSPADD		 EQU 		 H'093'
SSPMSK		 EQU 		 H'093'
SSPSTAT		 EQU 		 H'094'
WPUB		 EQU 		 H'095'
IOCB		 EQU 		 H'096'
WPDB		 EQU 		 H'097'
WPUA		 EQU 		 H'099'
WPUC		 EQU 		 H'09A'
ANSEL2		 EQU 		 H'09B'
ADRESL		 EQU 		 H'09C'
ADRESH		 EQU 		 H'09D'
ADCON0		 EQU 		 H'09E'
ADCON1		 EQU 		 H'09F'
RCSTA1		 EQU 		 H'0105'
PWMCON0		 EQU 		 H'0106'
PWMCON1		 EQU 		 H'0107'
PWMCON2		 EQU 		 H'0108'
PWM4TL		 EQU 		 H'0109'
PWMD0L		 EQU 		 H'010C'
PWMD1L		 EQU 		 H'010D'
PWMD2L		 EQU 		 H'010E'
PWMD3L		 EQU 		 H'010F'
PWMD4L		 EQU 		 H'0110'
PWMD01H		 EQU 		 H'0111'
PWMD23H		 EQU 		 H'0112'
LEDCON0		 EQU 		 H'0113'
INTCON2		 EQU 		 H'0114'
LEDADD		 EQU 		 H'0115'
LEDDATA		 EQU 		 H'0116'
SEGEN2		 EQU 		 H'0117'
SEGEN1		 EQU 		 H'0118'
SEGEN0		 EQU 		 H'0119'
COMEN		 EQU 		 H'011A'
PWMTL		 EQU 		 H'011B'
PWMTH		 EQU 		 H'011C'
LVDCON		 EQU 		 H'0185'
EEDAT		 EQU 		 H'0186'
EEADR		 EQU 		 H'0187'
EEDATH		 EQU 		 H'0188'
EEADRH		 EQU 		 H'0189'
EECON1		 EQU 		 H'018C'
EECON2		 EQU 		 H'018D'
PWM01DT		 EQU 		 H'018E'
PWM23DT		 EQU 		 H'018F'
;------------------------ STATUS  Bits------------------------
IRP		 EQU 		H'07'
RP1		 EQU 		H'06'
RP0		 EQU 		H'05'
TO		 EQU 		H'04'
PD		 EQU 		H'03'
Z		 EQU 		H'02'
DC		 EQU 		H'01'
C		 EQU 		H'00'

;------------------------ PORTA  Bits------------------------
RA7		 EQU 		H'07'
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

;------------------------ PORTC  Bits------------------------
RC7		 EQU 		H'07'
RC6		 EQU 		H'06'
RC5		 EQU 		H'05'
RC4		 EQU 		H'04'
RC3		 EQU 		H'03'
RC2		 EQU 		H'02'
RC1		 EQU 		H'01'
RC0		 EQU 		H'00'

;------------------------ PORTD  Bits------------------------
RD2		 EQU 		H'02'
RD1		 EQU 		H'01'
RD0		 EQU 		H'00'

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
PWMIF		 EQU 		H'07'
ADIF		 EQU 		H'06'
RC0IF		 EQU 		H'05'
TX0IF		 EQU 		H'04'
SSPIF		 EQU 		H'03'
CPTIF		 EQU 		H'02'
TMR2IF		 EQU 		H'01'
TMR1IF		 EQU 		H'00'

;------------------------ PIR2  Bits------------------------
LVDIF		 EQU 		H'07'
EEIF		 EQU 		H'04'
BCLIF		 EQU 		H'03'

;------------------------ T1CON  Bits------------------------
T1GINV		 EQU 		H'07'
TMR1GE		 EQU 		H'06'
T1CKPS1		 EQU 		H'05'
T1CKPS0		 EQU 		H'04'
T1SYNC		 EQU 		H'02'
TMR1CS		 EQU 		H'01'
TMR1ON		 EQU 		H'00'

;------------------------ T2CON  Bits------------------------
TOUTPS3		 EQU 		H'06'
TOUTPS2		 EQU 		H'05'
TOUTPS1		 EQU 		H'04'
TOUTPS0		 EQU 		H'03'
TMR2ON		 EQU 		H'02'
T2CKPS1		 EQU 		H'01'
T2CKPS0		 EQU 		H'00'

;------------------------ SSPCON  Bits------------------------
WCOL		 EQU 		H'07'
SSPOV		 EQU 		H'06'
SSPEN		 EQU 		H'05'
CKP		 EQU 		H'04'
SSPM3		 EQU 		H'03'
SSPM2		 EQU 		H'02'
SSPM1		 EQU 		H'01'
SSPM0		 EQU 		H'00'

;------------------------ CPTCON  Bits------------------------
CPTIO_SEL1		 EQU 		H'05'
CPTIO_SEL0		 EQU 		H'04'
CPTM3		 EQU 		H'03'
CPTM2		 EQU 		H'02'
CPTM1		 EQU 		H'01'
CPTM0		 EQU 		H'00'

;------------------------ RCSTA0  Bits------------------------
SPEN0		 EQU 		H'07'
RX9EN0		 EQU 		H'06'
SREN0		 EQU 		H'05'
CREN0		 EQU 		H'04'
RCIDL0		 EQU 		H'03'
FERR0		 EQU 		H'02'
OERR0		 EQU 		H'01'
RX9D0		 EQU 		H'00'

;------------------------ TXSTA0  Bits------------------------
CSRC0		 EQU 		H'07'
TX9EN0		 EQU 		H'06'
TXEN0		 EQU 		H'05'
SYNC0		 EQU 		H'04'
SCKP0		 EQU 		H'03'
TRMT0		 EQU 		H'01'
TX9D0		 EQU 		H'00'

;------------------------ SPBRG0  Bits------------------------
BRG07		 EQU 		H'07'
BRG06		 EQU 		H'06'
BRG05		 EQU 		H'05'
BRG04		 EQU 		H'04'
BRG03		 EQU 		H'03'
BRG02		 EQU 		H'02'
BRG01		 EQU 		H'01'
BRG00		 EQU 		H'00'

;------------------------ OPTION_REG  Bits------------------------
RBPU		 EQU 		H'07'
INTEDG		 EQU 		H'06'
T0CS		 EQU 		H'05'
T0SE		 EQU 		H'04'
PSA		 EQU 		H'03'
PS2		 EQU 		H'02'
PS1		 EQU 		H'01'
PS0		 EQU 		H'00'

;------------------------ TRISA  Bits------------------------
TRISA7		 EQU 		H'07'
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

;------------------------ TRISC  Bits------------------------
TRISC7		 EQU 		H'07'
TRISC6		 EQU 		H'06'
TRISC5		 EQU 		H'05'
TRISC4		 EQU 		H'04'
TRISC3		 EQU 		H'03'
TRISC2		 EQU 		H'02'
TRISC1		 EQU 		H'01'
TRISC0		 EQU 		H'00'

;------------------------ TRISD  Bits------------------------
TRISD2		 EQU 		H'02'
TRISD1		 EQU 		H'01'
TRISD0		 EQU 		H'00'

;------------------------ PIE1  Bits------------------------
PWMIE		 EQU 		H'07'
ADIE		 EQU 		H'06'
RC0IE		 EQU 		H'05'
TX0IE		 EQU 		H'04'
SSPIE		 EQU 		H'03'
CPTIE		 EQU 		H'02'
TMR2IE		 EQU 		H'01'
TMR1IE		 EQU 		H'00'

;------------------------ PIE2  Bits------------------------
LVDIE		 EQU 		H'07'
EEIE		 EQU 		H'04'
BCLIE		 EQU 		H'03'

;------------------------ WPUD  Bits------------------------
WPUD2		 EQU 		H'02'
WPUD1		 EQU 		H'01'
WPUD0		 EQU 		H'00'

;------------------------ OSCCON  Bits------------------------
IRCF2		 EQU 		H'06'
IRCF1		 EQU 		H'05'
IRCF0		 EQU 		H'04'

;------------------------ WDTCON  Bits------------------------
SWDTEN		 EQU 		H'00'

;------------------------ SSPCON2  Bits------------------------
GCEN		 EQU 		H'07'
ACKSTAT		 EQU 		H'06'
ACKDT		 EQU 		H'05'
ACKEN		 EQU 		H'04'
RCEN		 EQU 		H'03'
PEN		 EQU 		H'02'
RSEN		 EQU 		H'01'
SEN		 EQU 		H'00'

;------------------------ SSPMSK  Bits------------------------
MSK7		 EQU 		H'07'
MSK6		 EQU 		H'06'
MSK5		 EQU 		H'05'
MSK4		 EQU 		H'04'
MSK3		 EQU 		H'03'
MSK2		 EQU 		H'02'
MSK1		 EQU 		H'01'
MSK0		 EQU 		H'00'

;------------------------ SSPSTAT  Bits------------------------
CKE		 EQU 		H'06'
DA		 EQU 		H'05'
P		 EQU 		H'04'
S		 EQU 		H'03'
RW		 EQU 		H'02'
IICTOF		 EQU 		H'01'
BF		 EQU 		H'00'

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

;------------------------ WPDB  Bits------------------------
WPDB6		 EQU 		H'06'
WPDB5		 EQU 		H'05'
WPDB4		 EQU 		H'04'
WPDB3		 EQU 		H'03'
WPDB2		 EQU 		H'02'
WPDB1		 EQU 		H'01'
WPDB0		 EQU 		H'00'

;------------------------ WPUA  Bits------------------------
WPUA7		 EQU 		H'07'
WPUA6		 EQU 		H'06'
WPUA5		 EQU 		H'05'
WPUA4		 EQU 		H'04'
WPUA3		 EQU 		H'03'
WPUA2		 EQU 		H'02'
WPUA1		 EQU 		H'01'
WPUA0		 EQU 		H'00'

;------------------------ WPUC  Bits------------------------
WPUC7		 EQU 		H'07'
WPUC6		 EQU 		H'06'
WPUC5		 EQU 		H'05'
WPUC4		 EQU 		H'04'
WPUC3		 EQU 		H'03'
WPUC2		 EQU 		H'02'
WPUC1		 EQU 		H'01'
WPUC0		 EQU 		H'00'

;------------------------ ADCON0  Bits------------------------
ADCS1		 EQU 		H'07'
ADCS0		 EQU 		H'06'
CHS3		 EQU 		H'05'
CHS2		 EQU 		H'04'
CHS1		 EQU 		H'03'
CHS0		 EQU 		H'02'
GODONE		 EQU 		H'01'
ADON		 EQU 		H'00'

;------------------------ ADCON1  Bits------------------------
ADFM		 EQU 		H'07'
CHS4		 EQU 		H'06'

;------------------------ RCSTA1  Bits------------------------
SPEN1		 EQU 		H'07'
RX9EN1		 EQU 		H'06'
SREN1		 EQU 		H'05'
CREN1		 EQU 		H'04'
RCIDL1		 EQU 		H'03'
FERR1		 EQU 		H'02'
OERR1		 EQU 		H'01'
RX9D1		 EQU 		H'00'

;------------------------ PWMCON0  Bits------------------------
CLKDIV2		 EQU 		H'07'
CLKDIV1		 EQU 		H'06'
CLKDIV0		 EQU 		H'05'
PWM4EN		 EQU 		H'04'
PWM3EN		 EQU 		H'03'
PWM2EN		 EQU 		H'02'
PWM1EN		 EQU 		H'01'
PWM0EN		 EQU 		H'00'

;------------------------ PWMCON1  Bits------------------------
PWMIO_SEL		 EQU 		H'06'
PWM2DTEN		 EQU 		H'05'
PWM0DTEN		 EQU 		H'04'
DT_DIV1		 EQU 		H'01'
DT_DIV0		 EQU 		H'00'

;------------------------ PWMCON2  Bits------------------------
PWM4DIR		 EQU 		H'04'
PWM3DIR		 EQU 		H'03'
PWM2DIR		 EQU 		H'02'
PWM1DIR		 EQU 		H'01'
PWM0DIR		 EQU 		H'00'

;------------------------ PWMD01H  Bits------------------------
PWMD19		 EQU 		H'05'
PWMD18		 EQU 		H'04'
PWMD09		 EQU 		H'01'
PWMD08		 EQU 		H'00'

;------------------------ PWMD23H  Bits------------------------
PWMD39		 EQU 		H'05'
PWMD38		 EQU 		H'04'
PWMD29		 EQU 		H'01'
PWMD28		 EQU 		H'00'

;------------------------ LEDCON0  Bits------------------------
LEDEN		 EQU 		H'06'
COMSEL1		 EQU 		H'05'
COMSEL0		 EQU 		H'04'
LEDCLK3		 EQU 		H'03'
LEDCLK2		 EQU 		H'02'
LEDCLK1		 EQU 		H'01'
LEDCLK0		 EQU 		H'00'

;------------------------ INTCON2  Bits------------------------
INTSTAT1		 EQU 		H'07'
INTSTAT0		 EQU 		H'06'
HPRIIF		 EQU 		H'05'
INTPS4		 EQU 		H'04'
INTPS3		 EQU 		H'03'
INTPS2		 EQU 		H'02'
INTPS1		 EQU 		H'01'
INTPS0		 EQU 		H'00'

;------------------------ LEDADD  Bits------------------------
LEDCS		 EQU 		H'07'
LEDM		 EQU 		H'06'
COMSEL2		 EQU 		H'05'
LEDADD4		 EQU 		H'04'
LEDADD3		 EQU 		H'03'
LEDADD2		 EQU 		H'02'
LEDADD1		 EQU 		H'01'
LEDADD0		 EQU 		H'00'

;------------------------ PWMTH  Bits------------------------
PWMD49		 EQU 		H'05'
PWMD48		 EQU 		H'04'
PWM4T9		 EQU 		H'03'
PWM4T8		 EQU 		H'02'
PWMT9		 EQU 		H'01'
PWMT8		 EQU 		H'00'

;------------------------ LVDCON  Bits------------------------
LVD_RES		 EQU 		H'07'
LVD_SEL2		 EQU 		H'03'
LVD_SEL1		 EQU 		H'02'
LVD_SEL0		 EQU 		H'01'
LVDEN		 EQU 		H'00'

;------------------------ EEDAT  Bits------------------------
EEDAT7		 EQU 		H'07'
EEDAT6		 EQU 		H'06'
EEDAT5		 EQU 		H'05'
EEDAT4		 EQU 		H'04'
EEDAT3		 EQU 		H'03'
EEDAT2		 EQU 		H'02'
EEDAT1		 EQU 		H'01'
EEDAT0		 EQU 		H'00'

;------------------------ EEADR  Bits------------------------
EEADR7		 EQU 		H'07'
EEADR6		 EQU 		H'06'
EEADR5		 EQU 		H'05'
EEADR4		 EQU 		H'04'
EEADR3		 EQU 		H'03'
EEADR2		 EQU 		H'02'
EEADR1		 EQU 		H'01'
EEADR0		 EQU 		H'00'

;------------------------ EEDATH  Bits------------------------
EEDATH7		 EQU 		H'07'
EEDATH6		 EQU 		H'06'
EEDATH5		 EQU 		H'05'
EEDATH4		 EQU 		H'04'
EEDATH3		 EQU 		H'03'
EEDATH2		 EQU 		H'02'
EEDATH1		 EQU 		H'01'
EEDATH0		 EQU 		H'00'

;------------------------ EEADRH  Bits------------------------
EEADRH4		 EQU 		H'04'
EEADRH3		 EQU 		H'03'
EEADRH2		 EQU 		H'02'
EEADRH1		 EQU 		H'01'
EEADRH0		 EQU 		H'00'

;------------------------ EECON1  Bits------------------------
EEPGD		 EQU 		H'07'
WRERR		 EQU 		H'03'
WREN		 EQU 		H'02'
WR		 EQU 		H'01'
RD		 EQU 		H'00'

