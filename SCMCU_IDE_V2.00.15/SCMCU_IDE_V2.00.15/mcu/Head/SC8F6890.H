

INDF		 EQU 		 H'000'
TMR0		 EQU 		 H'001'
PCL		 EQU 		 H'002'
STATUS		 EQU 		 H'003'
FSR		 EQU 		 H'004'
PORTA		 EQU 		 H'005'
PORTB		 EQU 		 H'006'
PORTC		 EQU 		 H'007'
PCLATH		 EQU 		 H'00A'
INTCON		 EQU 		 H'00B'
PIR1		 EQU 		 H'00C'
PIR2		 EQU 		 H'00D'
TMR1L		 EQU 		 H'00E'
TMR1H		 EQU 		 H'00F'
T1CON		 EQU 		 H'010'
TMR2		 EQU 		 H'011'
T2CON		 EQU 		 H'012'
T2CON2		 EQU 		 H'013'
BAUDCTL1		 EQU 		 H'015'
RCREG1		 EQU 		 H'016'
RCSTA1		 EQU 		 H'017'
RCSTA0		 EQU 		 H'018'
TXREG0		 EQU 		 H'019'
RCREG0		 EQU 		 H'01A'
ADRESH		 EQU 		 H'01E'
ADCON0		 EQU 		 H'01F'
OPTION_REG		 EQU 		 H'081'
TRISA		 EQU 		 H'085'
TRISB		 EQU 		 H'086'
TRISC		 EQU 		 H'087'
WPDA		 EQU 		 H'089'
PIE1		 EQU 		 H'08C'
PIE2		 EQU 		 H'08D'
OSCCON		 EQU 		 H'08F'
OSCTUNE		 EQU 		 H'090'
PR2		 EQU 		 H'092'
WPUB		 EQU 		 H'095'
IOCB		 EQU 		 H'096'
TXSTA1		 EQU 		 H'097'
TXSTA0		 EQU 		 H'098'
SPBRG0		 EQU 		 H'099'
SPBRGH0		 EQU 		 H'09A'
SPBRG1		 EQU 		 H'09B'
SPBRGH1		 EQU 		 H'09C'
TXREG1		 EQU 		 H'09D'
ADRESL		 EQU 		 H'09E'
ADCON1		 EQU 		 H'09F'
WDTCON		 EQU 		 H'0105'
WPDB		 EQU 		 H'0107'
WPDC		 EQU 		 H'0108'
EEDAT		 EQU 		 H'010C'
EEADR		 EQU 		 H'010D'
EEDATH		 EQU 		 H'010E'
EEADRH		 EQU 		 H'010F'
TABLE_SPH		 EQU 		 H'0110'
TABLE_SPL		 EQU 		 H'0111'
TABLE_DATAH		 EQU 		 H'0112'
LCDCON		 EQU 		 H'0114'
LVDCON		 EQU 		 H'0115'
PWMTL		 EQU 		 H'0116'
PWMTH		 EQU 		 H'0117'
PWMT4L		 EQU 		 H'0118'
PWMD0L		 EQU 		 H'0119'
PWMD1L		 EQU 		 H'011A'
PWMD2L		 EQU 		 H'011B'
PWMD3L		 EQU 		 H'011C'
PWMD4L		 EQU 		 H'011D'
PWMD01H		 EQU 		 H'011E'
PWMD23H		 EQU 		 H'011F'
BAUDCTL0		 EQU 		 H'0187'
EECON1		 EQU 		 H'018C'
EECON2		 EQU 		 H'018D'
WPUA		 EQU 		 H'018E'
WPUC		 EQU 		 H'018F'
LCDCON0		 EQU 		 H'0190'
LCDCON1		 EQU 		 H'0191'
PWMCON0		 EQU 		 H'0192'
PWMCON1		 EQU 		 H'0193'
PWMCON2		 EQU 		 H'0194'
PWM01DT		 EQU 		 H'0195'
PWM23DT		 EQU 		 H'0196'
LCDCON2		 EQU 		 H'0197'
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
RB7		 EQU 		H'07'
RB6		 EQU 		H'06'
RB5		 EQU 		H'05'
RB4		 EQU 		H'04'
RB3		 EQU 		H'03'
RB2		 EQU 		H'02'
RB1		 EQU 		H'01'
RB0		 EQU 		H'00'

;------------------------ PORTC  Bits------------------------
RC1		 EQU 		H'01'
RC0		 EQU 		H'00'

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
RC1IF		 EQU 		H'07'
TX1IF		 EQU 		H'06'
RC0IF		 EQU 		H'05'
TX0IF		 EQU 		H'04'
EEIF		 EQU 		H'03'
ADIF		 EQU 		H'02'
TMR2IF		 EQU 		H'01'
TMR1IF		 EQU 		H'00'

;------------------------ PIR2  Bits------------------------
PWMIF		 EQU 		H'01'
LVDIF		 EQU 		H'00'

;------------------------ T1CON  Bits------------------------
T1GINV		 EQU 		H'07'
TMR1GE		 EQU 		H'06'
T1CKPS1		 EQU 		H'05'
T1CKPS0		 EQU 		H'04'
T0OSCEN		 EQU 		H'03'
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

;------------------------ T2CON2  Bits------------------------
T2CLK		 EQU 		H'00'

;------------------------ BAUDCTL1  Bits------------------------
RCIDL1		 EQU 		H'06'
SCKP1		 EQU 		H'04'
BRG16EN1		 EQU 		H'03'

;------------------------ RCSTA1  Bits------------------------
SPEN1		 EQU 		H'07'
RX9EN1		 EQU 		H'06'
SREN1		 EQU 		H'05'
CREN1		 EQU 		H'04'
FERR1		 EQU 		H'02'
OERR1		 EQU 		H'01'
RX9D1		 EQU 		H'00'

;------------------------ RCSTA0  Bits------------------------
SPEN0		 EQU 		H'07'
RX9EN0		 EQU 		H'06'
SREN0		 EQU 		H'05'
CREN0		 EQU 		H'04'
FERR0		 EQU 		H'02'
OERR0		 EQU 		H'01'
RX9D0		 EQU 		H'00'

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
TRISA7		 EQU 		H'07'
TRISA6		 EQU 		H'06'
TRISA5		 EQU 		H'05'
TRISA4		 EQU 		H'04'
TRISA3		 EQU 		H'03'
TRISA2		 EQU 		H'02'
TRISA1		 EQU 		H'01'
TRISA0		 EQU 		H'00'

;------------------------ TRISB  Bits------------------------
TRISB7		 EQU 		H'07'
TRISB6		 EQU 		H'06'
TRISB5		 EQU 		H'05'
TRISB4		 EQU 		H'04'
TRISB3		 EQU 		H'03'
TRISB2		 EQU 		H'02'
TRISB1		 EQU 		H'01'
TRISB0		 EQU 		H'00'

;------------------------ TRISC  Bits------------------------
TRISC1		 EQU 		H'01'
TRISC0		 EQU 		H'00'

;------------------------ WPDA  Bits------------------------
WPDA7		 EQU 		H'07'
WPDA6		 EQU 		H'06'
WPDA5		 EQU 		H'05'
WPDA4		 EQU 		H'04'
WPDA3		 EQU 		H'03'
WPDA2		 EQU 		H'02'
WPDA1		 EQU 		H'01'
WPDA0		 EQU 		H'00'

;------------------------ PIE1  Bits------------------------
RC1IE		 EQU 		H'07'
TX1IE		 EQU 		H'06'
RC0IE		 EQU 		H'05'
TX0IE		 EQU 		H'04'
EEIE		 EQU 		H'03'
ADIE		 EQU 		H'02'
TMR2IE		 EQU 		H'01'
TMR1IE		 EQU 		H'00'

;------------------------ PIE2  Bits------------------------
PWMIE		 EQU 		H'01'
LVDIE		 EQU 		H'00'

;------------------------ OSCCON  Bits------------------------
IRCF2		 EQU 		H'06'
IRCF1		 EQU 		H'05'
IRCF0		 EQU 		H'04'
SCS		 EQU 		H'00'

;------------------------ OSCTUNE  Bits------------------------
TUN6		 EQU 		H'06'
TUN5		 EQU 		H'05'
TUN4		 EQU 		H'04'
TUN3		 EQU 		H'03'
TUN2		 EQU 		H'02'
TUN1		 EQU 		H'01'
TUN0		 EQU 		H'00'

;------------------------ WPUB  Bits------------------------
WPUB7		 EQU 		H'07'
WPUB6		 EQU 		H'06'
WPUB5		 EQU 		H'05'
WPUB4		 EQU 		H'04'
WPUB3		 EQU 		H'03'
WPUB2		 EQU 		H'02'
WPUB1		 EQU 		H'01'
WPUB0		 EQU 		H'00'

;------------------------ IOCB  Bits------------------------
IOCB7		 EQU 		H'07'
IOCB6		 EQU 		H'06'
IOCB5		 EQU 		H'05'
IOCB4		 EQU 		H'04'
IOCB3		 EQU 		H'03'
IOCB2		 EQU 		H'02'
IOCB1		 EQU 		H'01'
IOCB0		 EQU 		H'00'

;------------------------ TXSTA1  Bits------------------------
CSRC1		 EQU 		H'07'
TX9EN1		 EQU 		H'06'
TXEN1		 EQU 		H'05'
SYNC1		 EQU 		H'04'
BRGHEN1		 EQU 		H'02'
TRMT1		 EQU 		H'01'
TX9D1		 EQU 		H'00'

;------------------------ TXSTA0  Bits------------------------
CSRC0		 EQU 		H'07'
TX9EN0		 EQU 		H'06'
TXEN0		 EQU 		H'05'
SYNC0		 EQU 		H'04'
BRGHEN0		 EQU 		H'02'
TRMT0		 EQU 		H'01'
TX9D0		 EQU 		H'00'

;------------------------ ADCON1  Bits------------------------
ADFM		 EQU 		H'07'
CHS4		 EQU 		H'06'
LDOEN		 EQU 		H'02'
LDOSEL		 EQU 		H'00'

;------------------------ WDTCON  Bits------------------------
SWDTEN		 EQU 		H'00'

;------------------------ WPDB  Bits------------------------
WPDB7		 EQU 		H'07'
WPDB6		 EQU 		H'06'
WPDB5		 EQU 		H'05'
WPDB4		 EQU 		H'04'
WPDB3		 EQU 		H'03'
WPDB2		 EQU 		H'02'
WPDB1		 EQU 		H'01'
WPDB0		 EQU 		H'00'

;------------------------ WPDC  Bits------------------------
WPDC1		 EQU 		H'01'
WPDC0		 EQU 		H'00'

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

;------------------------ LCDCON  Bits------------------------
LCDEN		 EQU 		H'07'

;------------------------ LVDCON  Bits------------------------
LVD_RES		 EQU 		H'07'
LVD_SEL2		 EQU 		H'03'
LVD_SEL1		 EQU 		H'02'
LVD_SEL0		 EQU 		H'01'
LVDEN		 EQU 		H'00'

;------------------------ PWMTL  Bits------------------------
PWMT7		 EQU 		H'07'
PWMT6		 EQU 		H'06'
PWMT5		 EQU 		H'05'
PWMT4		 EQU 		H'04'
PWMT3		 EQU 		H'03'
PWMT2		 EQU 		H'02'
PWMT1		 EQU 		H'01'
PWMT0		 EQU 		H'00'

;------------------------ PWMTH  Bits------------------------
PWM4D9		 EQU 		H'05'
PWM4D8		 EQU 		H'04'
PWM4T9		 EQU 		H'03'
PWM4T8		 EQU 		H'02'
PWMT9		 EQU 		H'01'
PWMT8		 EQU 		H'00'

;------------------------ PWMT4L  Bits------------------------
PWMT4L7		 EQU 		H'07'
PWMT4L6		 EQU 		H'06'
PWMT4L5		 EQU 		H'05'
PWMT4L4		 EQU 		H'04'
PWMT4L3		 EQU 		H'03'
PWMT4L2		 EQU 		H'02'
PWMT4L1		 EQU 		H'01'
PWMT4L0		 EQU 		H'00'

;------------------------ PWMD0L  Bits------------------------
PWMD07		 EQU 		H'07'
PWMD06		 EQU 		H'06'
PWMD05		 EQU 		H'05'
PWMD04		 EQU 		H'04'
PWMD03		 EQU 		H'03'
PWMD02		 EQU 		H'02'
PWMD01		 EQU 		H'01'
PWMD00		 EQU 		H'00'

;------------------------ PWMD1L  Bits------------------------
PWMD17		 EQU 		H'07'
PWMD16		 EQU 		H'06'
PWMD15		 EQU 		H'05'
PWMD14		 EQU 		H'04'
PWMD13		 EQU 		H'03'
PWMD12		 EQU 		H'02'
PWMD11		 EQU 		H'01'
PWMD10		 EQU 		H'00'

;------------------------ PWMD2L  Bits------------------------
PWMD27		 EQU 		H'07'
PWMD26		 EQU 		H'06'
PWMD25		 EQU 		H'05'
PWMD24		 EQU 		H'04'
PWMD23		 EQU 		H'03'
PWMD22		 EQU 		H'02'
PWMD21		 EQU 		H'01'
PWMD20		 EQU 		H'00'

;------------------------ PWMD3L  Bits------------------------
PWMD37		 EQU 		H'07'
PWMD36		 EQU 		H'06'
PWMD35		 EQU 		H'05'
PWMD34		 EQU 		H'04'
PWMD33		 EQU 		H'03'
PWMD32		 EQU 		H'02'
PWMD31		 EQU 		H'01'
PWMD30		 EQU 		H'00'

;------------------------ PWMD4L  Bits------------------------
PWMD47		 EQU 		H'07'
PWMD46		 EQU 		H'06'
PWMD45		 EQU 		H'05'
PWMD44		 EQU 		H'04'
PWMD43		 EQU 		H'03'
PWMD42		 EQU 		H'02'
PWMD41		 EQU 		H'01'
PWMD40		 EQU 		H'00'

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

;------------------------ BAUDCTL0  Bits------------------------
RCIDL0		 EQU 		H'06'
SCKP0		 EQU 		H'04'
BRG16EN0		 EQU 		H'03'

;------------------------ EECON1  Bits------------------------
EEPGD		 EQU 		H'07'
EETIME1		 EQU 		H'05'
EETIME0		 EQU 		H'04'
WRERR		 EQU 		H'03'
WREN		 EQU 		H'02'
WR		 EQU 		H'01'
RD		 EQU 		H'00'

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
WPUC1		 EQU 		H'01'
WPUC0		 EQU 		H'00'

;------------------------ LCDCON0  Bits------------------------
COM7EN		 EQU 		H'07'
COM6EN		 EQU 		H'06'
COM5EN		 EQU 		H'05'
COM4EN		 EQU 		H'04'
COM3EN		 EQU 		H'03'
COM2EN		 EQU 		H'02'
COM1EN		 EQU 		H'01'
COM0EN		 EQU 		H'00'

;------------------------ LCDCON1  Bits------------------------
COM15EN		 EQU 		H'07'
COM14EN		 EQU 		H'06'
COM13EN		 EQU 		H'05'
COM12EN		 EQU 		H'04'
COM11EN		 EQU 		H'03'
COM10EN		 EQU 		H'02'
COM9EN		 EQU 		H'01'
COM8EN		 EQU 		H'00'

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
PWM01_SEL		 EQU 		H'06'
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

;------------------------ PWM01DT  Bits------------------------
PWM01DT5		 EQU 		H'05'
PWM01DT4		 EQU 		H'04'
PWM01DT3		 EQU 		H'03'
PWM01DT2		 EQU 		H'02'
PWM01DT1		 EQU 		H'01'
PWM01DT0		 EQU 		H'00'

;------------------------ PWM23DT  Bits------------------------
PWM23DT5		 EQU 		H'05'
PWM23DT4		 EQU 		H'04'
PWM23DT3		 EQU 		H'03'
PWM23DT2		 EQU 		H'02'
PWM23DT1		 EQU 		H'01'
PWM23DT0		 EQU 		H'00'

;------------------------ LCDCON2  Bits------------------------
LCDISEL1		 EQU 		H'07'
LCDISEL0		 EQU 		H'06'
COM17EN		 EQU 		H'01'
COM16EN		 EQU 		H'00'

