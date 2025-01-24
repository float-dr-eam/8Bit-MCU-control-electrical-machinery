

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
PWM4TL          EQU    H'01E'
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
ADCON1          EQU    H'09C'
ADCON0          EQU    H'09D'
ADRESL          EQU    H'09E'
ADRESH          EQU    H'09F'
BUZCON          EQU    H'0105'
PIR2            EQU    H'0107'
PIE2            EQU    H'0108'
IICADD          EQU    H'0109'
IICCON          EQU    H'010C'
IICCON2         EQU    H'010D'
IICBUF          EQU    H'010E'
IICSTAT         EQU    H'010F'
ANSEL0          EQU    H'0110'
ANSEL1          EQU    H'0111'
ANSEL2          EQU    H'0112'
WPDA            EQU    H'0113'
TXSTA           EQU    H'0117'
RCSTA           EQU    H'0118'
SPBRG           EQU    H'0119'
TXREG           EQU    H'011A'
RCREG           EQU    H'011B'
SPIBUF          EQU    H'011C'
SPICON          EQU    H'011D'
SPICON2         EQU    H'011E'
LVDCON          EQU    H'011F'
IOCA            EQU    H'0188'
PWMIOS0         EQU    H'018C'
PWMIOS1         EQU    H'018D'
PWMIOS2         EQU    H'018E'
LCDCON          EQU    H'018F'
CSSEL0          EQU    H'0190'
CSSEL1          EQU    H'0191'
CSEN0           EQU    H'0193'
CSEN1           EQU    H'0194'
TABLE_SPL       EQU    H'0196'
TABLE_SPH       EQU    H'0197'
TABLE_DATAH     EQU    H'0198'
TMR1L           EQU    H'0199'
TMR1H           EQU    H'019A'
T1CON           EQU    H'019B'
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
RA6             EQU    H'06'
RA5             EQU    H'05'
RA4             EQU    H'04'
RA3             EQU    H'03'
RA2             EQU    H'02'
RA1             EQU    H'01'
RA0             EQU    H'00'

;------------------------ PORTB  Bits------------------------
RB6             EQU    H'06'
RB5             EQU    H'05'
RB4             EQU    H'04'
RB3             EQU    H'03'
RB2             EQU    H'02'
RB1             EQU    H'01'
RB0             EQU    H'00'

;------------------------ WPUA  Bits------------------------
WPUA6           EQU    H'06'
WPUA5           EQU    H'05'
WPUA4           EQU    H'04'
WPUA3           EQU    H'03'
WPUA2           EQU    H'02'
WPUA1           EQU    H'01'
WPUA0           EQU    H'00'

;------------------------ WPUB  Bits------------------------
WPUB6           EQU    H'06'
WPUB5           EQU    H'05'
WPUB4           EQU    H'04'
WPUB3           EQU    H'03'
WPUB2           EQU    H'02'
WPUB1           EQU    H'01'
WPUB0           EQU    H'00'

;------------------------ IOCB  Bits------------------------
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
TMR1IF          EQU    H'07'
EEIF            EQU    H'06'
RCIF            EQU    H'05'
TXIF            EQU    H'04'
SPIIF           EQU    H'03'
PWMIF           EQU    H'02'
TMR2IF          EQU    H'01'
ADIF            EQU    H'00'

;------------------------ PIE1  Bits------------------------
TMR1IE          EQU    H'07'
EEIE            EQU    H'06'
RCIE            EQU    H'05'
TXIE            EQU    H'04'
SPIIE           EQU    H'03'
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
PWM2DTEN        EQU    H'05'
PWM0DTEN        EQU    H'04'
DT_DIV1         EQU    H'01'
DT_DIV0         EQU    H'00'

;------------------------ PWMTH  Bits------------------------
PWMD49          EQU    H'05'
PWMD48          EQU    H'04'
PWM4T9          EQU    H'03'
PWM4T8          EQU    H'02'
PWMT9           EQU    H'01'
PWMT8           EQU    H'00'

;------------------------ PWMD01H  Bits------------------------
PWMD19          EQU    H'05'
PWMD18          EQU    H'04'
PWMD09          EQU    H'01'
PWMD08          EQU    H'00'

;------------------------ PWMCON2  Bits------------------------
BUZEN           EQU    H'07'
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
TRISA6          EQU    H'06'
TRISA5          EQU    H'05'
TRISA4          EQU    H'04'
TRISA3          EQU    H'03'
TRISA2          EQU    H'02'
TRISA1          EQU    H'01'
TRISA0          EQU    H'00'

;------------------------ TRISB  Bits------------------------
TRISB6          EQU    H'06'
TRISB5          EQU    H'05'
TRISB4          EQU    H'04'
TRISB3          EQU    H'03'
TRISB2          EQU    H'02'
TRISB1          EQU    H'01'
TRISB0          EQU    H'00'

;------------------------ WPDB  Bits------------------------
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

;------------------------ ADCON1  Bits------------------------
ADFM            EQU    H'07'
CHS4            EQU    H'06'
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

;------------------------ BUZCON  Bits------------------------
BUZDIV1         EQU    H'07'
BUZDIV0         EQU    H'06'
BUZDATA5        EQU    H'05'
BUZDATA4        EQU    H'04'
BUZDATA3        EQU    H'03'
BUZDATA2        EQU    H'02'
BUZDATA1        EQU    H'01'
BUZDATA0        EQU    H'00'

;------------------------ PIR2  Bits------------------------
IICIF           EQU    H'04'
BCLIF           EQU    H'03'
RCCIF           EQU    H'02'
RACIF           EQU    H'01'
LVDIF           EQU    H'00'

;------------------------ PIE2  Bits------------------------
IICIE           EQU    H'04'
BCLIE           EQU    H'03'
RCCIE           EQU    H'02'
RACIE           EQU    H'01'
LVDIE           EQU    H'00'

;------------------------ IICCON  Bits------------------------
IICWCOL         EQU    H'07'
SSPOV           EQU    H'06'
IICEN           EQU    H'05'
IICCKP          EQU    H'04'
IICTOS1         EQU    H'03'
IICTOS0         EQU    H'02'
IICM1           EQU    H'01'
IICM0           EQU    H'00'

;------------------------ IICCON2  Bits------------------------
GCEN            EQU    H'07'
ACKSTAT         EQU    H'06'
ACKDT           EQU    H'05'
ACKEN           EQU    H'04'
RCEN            EQU    H'03'
PEN             EQU    H'02'
RSEN            EQU    H'01'
SEN             EQU    H'00'

;------------------------ IICSTAT  Bits------------------------
IDLE            EQU    H'06'
DA              EQU    H'05'
P               EQU    H'04'
S               EQU    H'03'
RW              EQU    H'02'
IICTOF          EQU    H'01'
BF              EQU    H'00'

;------------------------ ANSEL0  Bits------------------------
ANS7            EQU    H'07'
ANS5            EQU    H'05'
ANS4            EQU    H'04'
ANS3            EQU    H'03'
ANS2            EQU    H'02'
ANS1            EQU    H'01'
ANS0            EQU    H'00'

;------------------------ ANSEL1  Bits------------------------
ANS13           EQU    H'05'
ANS12           EQU    H'04'
ANS11           EQU    H'03'
ANS10           EQU    H'02'
ANS9            EQU    H'01'
ANS8            EQU    H'00'

;------------------------ ANSEL2  Bits------------------------
ANS16           EQU    H'00'

;------------------------ WPDA  Bits------------------------
WPDA6           EQU    H'06'
WPDA5           EQU    H'05'
WPDA4           EQU    H'04'
WPDA3           EQU    H'03'
WPDA2           EQU    H'02'
WPDA1           EQU    H'01'
WPDA0           EQU    H'00'

;------------------------ TXSTA  Bits------------------------
CSRC            EQU    H'07'
TX9EN           EQU    H'06'
TXEN            EQU    H'05'
SYNC            EQU    H'04'
SCKP            EQU    H'03'
STOPBIT         EQU    H'02'
TRMT            EQU    H'01'
TX9D            EQU    H'00'

;------------------------ RCSTA  Bits------------------------
SPEN            EQU    H'07'
RX9EN           EQU    H'06'
SREN            EQU    H'05'
CREN            EQU    H'04'
RCIDL           EQU    H'03'
FERR            EQU    H'02'
OERR            EQU    H'01'
RX9D            EQU    H'00'

;------------------------ SPICON  Bits------------------------
SPIWCOL         EQU    H'07'
SPIOV           EQU    H'06'
SPIEN           EQU    H'05'
SPICKP          EQU    H'04'
SPIM3           EQU    H'03'
SPIM2           EQU    H'02'
SPIM1           EQU    H'01'
SPIM0           EQU    H'00'

;------------------------ SPICON2  Bits------------------------
CKE             EQU    H'06'
MODE            EQU    H'05'
SPIBF           EQU    H'00'

;------------------------ LVDCON  Bits------------------------
LVD_RES         EQU    H'07'
LVD_SEL2        EQU    H'03'
LVD_SEL1        EQU    H'02'
LVD_SEL0        EQU    H'01'
LVDEN           EQU    H'00'

;------------------------ IOCA  Bits------------------------
IOCA6           EQU    H'06'
IOCA5           EQU    H'05'
IOCA4           EQU    H'04'
IOCA3           EQU    H'03'
IOCA2           EQU    H'02'
IOCA1           EQU    H'01'
IOCA0           EQU    H'00'

;------------------------ PWMIOS0  Bits------------------------
PWM1IOS2        EQU    H'06'
PWM1IOS1        EQU    H'05'
PWM1IOS0        EQU    H'04'
PWM0IOS2        EQU    H'02'
PWM0IOS1        EQU    H'01'
PWM0IOS0        EQU    H'00'

;------------------------ PWMIOS1  Bits------------------------
PWM3IOS2        EQU    H'06'
PWM3IOS1        EQU    H'05'
PWM3IOS0        EQU    H'04'
PWM2IOS2        EQU    H'02'
PWM2IOS1        EQU    H'01'
PWM2IOS0        EQU    H'00'

;------------------------ PWMIOS2  Bits------------------------
PWM4IOS2        EQU    H'02'
PWM4IOS1        EQU    H'01'
PWM4IOS0        EQU    H'00'

;------------------------ LCDCON  Bits------------------------
LCDEN           EQU    H'07'
FRAME           EQU    H'06'
BIAS            EQU    H'05'
LCDISLE1        EQU    H'01'
LCDISLE0        EQU    H'00'

;------------------------ CSSEL0  Bits------------------------
CS6SEL          EQU    H'06'
CS5SEL          EQU    H'05'
CS4SEL          EQU    H'04'
CS3SEL          EQU    H'03'
CS2SEL          EQU    H'02'
CS1SEL          EQU    H'01'
CS0SEL          EQU    H'00'

;------------------------ CSSEL1  Bits------------------------
CS14SEL         EQU    H'06'
CS13SEL         EQU    H'05'
CS12SEL         EQU    H'04'
CS11SEL         EQU    H'03'
CS10SEL         EQU    H'02'
CS9SEL          EQU    H'01'
CS8SEL          EQU    H'00'

;------------------------ CSEN0  Bits------------------------
CS6EN           EQU    H'06'
CS5EN           EQU    H'05'
CS4EN           EQU    H'04'
CS3EN           EQU    H'03'
CS2EN           EQU    H'02'
CS1EN           EQU    H'01'
CS0EN           EQU    H'00'

;------------------------ CSEN1  Bits------------------------
CS14EN          EQU    H'06'
CS13EN          EQU    H'05'
CS12EN          EQU    H'04'
CS11EN          EQU    H'03'
CS10EN          EQU    H'02'
CS9EN           EQU    H'01'
CS8EN           EQU    H'00'

;------------------------ T1CON  Bits------------------------
T1CKPS1         EQU    H'05'
T1CKPS0         EQU    H'04'
T0OSCEN         EQU    H'03'
T1SYNC          EQU    H'02'
TMR1CS          EQU    H'01'
TMR1ON          EQU    H'00'

