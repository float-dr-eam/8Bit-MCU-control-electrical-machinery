

INDF            EQU    H'000'
TMR0            EQU    H'001'
PCL             EQU    H'002'
STATUS          EQU    H'003'
FSR             EQU    H'004'
PORTA           EQU    H'005'
PORTB           EQU    H'006'
WPUA            EQU    H'007'
WPUB            EQU    H'008'
IOCB            EQU    H'009'
PCLATH          EQU    H'00A'
INTCON          EQU    H'00B'
PIR1            EQU    H'00C'
PIE1            EQU    H'00D'
PWMD23H         EQU    H'00E'
PWM01DT         EQU    H'00F'
PWM23DT         EQU    H'010'
TMR2            EQU    H'011'
T2CON           EQU    H'012'
PWMCON0         EQU    H'013'
PWMCON1         EQU    H'014'
PWMTL           EQU    H'015'
PWMTH           EQU    H'016'
PWMD0L          EQU    H'017'
PWMD1L          EQU    H'018'
PWMD2L          EQU    H'019'
PWMD3L          EQU    H'01A'
PWMD4L          EQU    H'01B'
PWMD01H         EQU    H'01C'
PWMCON2         EQU    H'01D'
OPTION_REG      EQU    H'081'
TRISA           EQU    H'085'
TRISB           EQU    H'086'
WPDB            EQU    H'087'
OSCCON          EQU    H'088'
EECON1          EQU    H'08C'
EECON2          EQU    H'08D'
EEDAT           EQU    H'08E'
EEDATH          EQU    H'08F'
EEADR           EQU    H'090'
PR2             EQU    H'091'
EEADRH          EQU    H'096'
OPA0CON         EQU    H'098'
OPA0ADJ         EQU    H'099'
OPA1CON         EQU    H'09A'
OPA1ADJ         EQU    H'09B'
ADCON1          EQU    H'09C'
ADCON0          EQU    H'09D'
ADRESL          EQU    H'09E'
ADRESH          EQU    H'09F'
PIR2            EQU    H'0107'
PIE2            EQU    H'0108'
LVDCON          EQU    H'011F'
;------------------------ STATUS  Bits------------------------
IRP             EQU    H'07'
RP1             EQU    H'06'
RP0             EQU    H'05'
TO              EQU    H'04'
PD              EQU    H'03'
Z               EQU    H'02'
DC              EQU    H'01'
C               EQU    H'00'

;------------------------ PORTA  Bits------------------------
RA5             EQU    H'05'
RA4             EQU    H'04'
RA3             EQU    H'03'
RA2             EQU    H'02'
RA1             EQU    H'01'
RA0             EQU    H'00'

;------------------------ PORTB  Bits------------------------
RB7             EQU    H'07'
RB6             EQU    H'06'
RB5             EQU    H'05'
RB4             EQU    H'04'
RB3             EQU    H'03'
RB2             EQU    H'02'
RB1             EQU    H'01'
RB0             EQU    H'00'

;------------------------ WPUA  Bits------------------------
WPUA5           EQU    H'05'
WPUA4           EQU    H'04'
WPUA3           EQU    H'03'
WPUA2           EQU    H'02'
WPUA1           EQU    H'01'
WPUA0           EQU    H'00'

;------------------------ WPUB  Bits------------------------
WPUB7           EQU    H'07'
WPUB6           EQU    H'06'
WPUB5           EQU    H'05'
WPUB4           EQU    H'04'
WPUB3           EQU    H'03'
WPUB2           EQU    H'02'
WPUB1           EQU    H'01'
WPUB0           EQU    H'00'

;------------------------ IOCB  Bits------------------------
IOCB7           EQU    H'07'
IOCB6           EQU    H'06'
IOCB5           EQU    H'05'
IOCB4           EQU    H'04'
IOCB3           EQU    H'03'
IOCB2           EQU    H'02'
IOCB1           EQU    H'01'
IOCB0           EQU    H'00'

;------------------------ INTCON  Bits------------------------
GIE             EQU    H'07'
PEIE            EQU    H'06'
T0IE            EQU    H'05'
INTE            EQU    H'04'
RBIE            EQU    H'03'
T0IF            EQU    H'02'
INTF            EQU    H'01'
RBIF            EQU    H'00'

;------------------------ PIR1  Bits------------------------
EEIF            EQU    H'06'
PWMIF           EQU    H'02'
TMR2IF          EQU    H'01'
ADIF            EQU    H'00'

;------------------------ PIE1  Bits------------------------
EEIE            EQU    H'06'
PWMIE           EQU    H'02'
TMR2IE          EQU    H'01'
ADIE            EQU    H'00'

;------------------------ PWMD23H  Bits------------------------
PWMD39          EQU    H'05'
PWMD38          EQU    H'04'
PWMD29          EQU    H'01'
PWMD28          EQU    H'00'

;------------------------ T2CON  Bits------------------------
CLK_SEL         EQU    H'07'
TOUTPS3         EQU    H'06'
TOUTPS2         EQU    H'05'
TOUTPS1         EQU    H'04'
TOUTPS0         EQU    H'03'
TMR2ON          EQU    H'02'
T2CKPS1         EQU    H'01'
T2CKPS0         EQU    H'00'

;------------------------ PWMCON0  Bits------------------------
CLKDIV2         EQU    H'07'
CLKDIV1         EQU    H'06'
CLKDIV0         EQU    H'05'
PWM4EN          EQU    H'04'
PWM3EN          EQU    H'03'
PWM2EN          EQU    H'02'
PWM1EN          EQU    H'01'
PWM0EN          EQU    H'00'

;------------------------ PWMCON1  Bits------------------------
PWMIO_SEL1      EQU    H'07'
PWMIO_SEL0      EQU    H'06'
PWM2DTEN        EQU    H'05'
PWM0DTEN        EQU    H'04'
DT_DIV1         EQU    H'01'
DT_DIV0         EQU    H'00'

;------------------------ PWMTH  Bits------------------------
PWMD49          EQU    H'05'
PWMD48          EQU    H'04'
PWMT9           EQU    H'01'
PWMT8           EQU    H'00'

;------------------------ PWMD01H  Bits------------------------
PWMD19          EQU    H'05'
PWMD18          EQU    H'04'
PWMD09          EQU    H'01'
PWMD08          EQU    H'00'

;------------------------ PWMCON2  Bits------------------------
PWM4DIR         EQU    H'04'
PWM3DIR         EQU    H'03'
PWM2DIR         EQU    H'02'
PWM1DIR         EQU    H'01'
PWM0DIR         EQU    H'00'

;------------------------ OPTION_REG  Bits------------------------
INTEDG          EQU    H'06'
T0CS            EQU    H'05'
T0SE            EQU    H'04'
PSA             EQU    H'03'
PS2             EQU    H'02'
PS1             EQU    H'01'
PS0             EQU    H'00'

;------------------------ TRISA  Bits------------------------
TRISA5          EQU    H'05'
TRISA4          EQU    H'04'
TRISA3          EQU    H'03'
TRISA2          EQU    H'02'
TRISA1          EQU    H'01'
TRISA0          EQU    H'00'

;------------------------ TRISB  Bits------------------------
TRISB7          EQU    H'07'
TRISB6          EQU    H'06'
TRISB5          EQU    H'05'
TRISB4          EQU    H'04'
TRISB3          EQU    H'03'
TRISB2          EQU    H'02'
TRISB1          EQU    H'01'
TRISB0          EQU    H'00'

;------------------------ WPDB  Bits------------------------
WPDB7           EQU    H'07'
WPDB6           EQU    H'06'
WPDB5           EQU    H'05'
WPDB4           EQU    H'04'
WPDB3           EQU    H'03'
WPDB2           EQU    H'02'
WPDB1           EQU    H'01'
WPDB0           EQU    H'00'

;------------------------ OSCCON  Bits------------------------
IRCF2           EQU    H'06'
IRCF1           EQU    H'05'
IRCF0           EQU    H'04'
SWDTEN          EQU    H'01'

;------------------------ EECON1  Bits------------------------
EEPGD           EQU    H'07'
WRERR           EQU    H'03'
WREN            EQU    H'02'
WR              EQU    H'01'
RD              EQU    H'00'

;------------------------ EEDAT  Bits------------------------
EEDAT7          EQU    H'07'
EEDAT6          EQU    H'06'
EEDAT5          EQU    H'05'
EEDAT4          EQU    H'04'
EEDAT3          EQU    H'03'
EEDAT2          EQU    H'02'
EEDAT1          EQU    H'01'
EEDAT0          EQU    H'00'

;------------------------ EEDATH  Bits------------------------
EEDATH7         EQU    H'07'
EEDATH6         EQU    H'06'
EEDATH5         EQU    H'05'
EEDATH4         EQU    H'04'
EEDATH3         EQU    H'03'
EEDATH2         EQU    H'02'
EEDATH1         EQU    H'01'
EEDATH0         EQU    H'00'

;------------------------ EEADR  Bits------------------------
EEADR7          EQU    H'07'
EEADR6          EQU    H'06'
EEADR5          EQU    H'05'
EEADR4          EQU    H'04'
EEADR3          EQU    H'03'
EEADR2          EQU    H'02'
EEADR1          EQU    H'01'
EEADR0          EQU    H'00'

;------------------------ EEADRH  Bits------------------------
EEADRH3         EQU    H'03'
EEADRH2         EQU    H'02'
EEADRH1         EQU    H'01'
EEADRH0         EQU    H'00'

;------------------------ OPA0CON  Bits------------------------
OPA0EN          EQU    H'07'
OPA0OEN         EQU    H'06'
CMP0MODE        EQU    H'05'
OPA0_ADC        EQU    H'04'
OPA0FT          EQU    H'00'

;------------------------ OPA0ADJ  Bits------------------------
OPA0OUT         EQU    H'07'
OPA0COFM        EQU    H'06'
OPA0CRS         EQU    H'05'
OPA0_ADJ4       EQU    H'04'
OPA0_ADJ3       EQU    H'03'
OPA0_ADJ2       EQU    H'02'
OPA0_ADJ1       EQU    H'01'
OPA0_ADJ0       EQU    H'00'

;------------------------ OPA1CON  Bits------------------------
OPA1EN          EQU    H'07'
OPA1OEN         EQU    H'06'
CMP1MODE        EQU    H'05'
OPA1_ADC        EQU    H'04'
OPA1FT          EQU    H'00'

;------------------------ OPA1ADJ  Bits------------------------
OPA1OUT         EQU    H'07'
OPA1COFM        EQU    H'06'
OPA1CRS         EQU    H'05'
OPA1_ADJ4       EQU    H'04'
OPA1_ADJ3       EQU    H'03'
OPA1_ADJ2       EQU    H'02'
OPA1_ADJ1       EQU    H'01'
OPA1_ADJ0       EQU    H'00'

;------------------------ ADCON1  Bits------------------------
ADFM            EQU    H'07'
LDO_EN          EQU    H'02'
LDO_SEL1        EQU    H'01'
LDO_SEL0        EQU    H'00'

;------------------------ ADCON0  Bits------------------------
ADCS1           EQU    H'07'
ADCS0           EQU    H'06'
CHS3            EQU    H'05'
CHS2            EQU    H'04'
CHS1            EQU    H'03'
CHS0            EQU    H'02'
GODONE          EQU    H'01'
ADON            EQU    H'00'

;------------------------ PIR2  Bits------------------------
LVDIF           EQU    H'00'

;------------------------ PIE2  Bits------------------------
LVDIE           EQU    H'00'

;------------------------ LVDCON  Bits------------------------
LVD_RES         EQU    H'07'
LVD_SEL2        EQU    H'03'
LVD_SEL1        EQU    H'02'
LVD_SEL0        EQU    H'01'
LVDEN           EQU    H'00'

