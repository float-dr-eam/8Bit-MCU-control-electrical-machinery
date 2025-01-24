

INDF            EQU    H'000'
OPTION_REG      EQU    H'001'
PCL             EQU    H'002'
STATUS          EQU    H'003'
FSR             EQU    H'004'
TRISB           EQU    H'005'
PORTB           EQU    H'006'
WPDB            EQU    H'007'
WPUB            EQU    H'008'
IOCB            EQU    H'009'
PCLATH          EQU    H'00A'
INTCON          EQU    H'00B'
ODCONB          EQU    H'00C'
PIR1            EQU    H'00D'
PIE1            EQU    H'00E'
CMPCON0         EQU    H'00F'
CMPCON1         EQU    H'010'
PR2             EQU    H'011'
TMR2            EQU    H'012'
T2CON           EQU    H'013'
OSCCON          EQU    H'014'
PWMCON0         EQU    H'015'
PWMCON1         EQU    H'016'
PWMTL           EQU    H'017'
PWMTH           EQU    H'018'
PWMD0L          EQU    H'019'
PWMD1L          EQU    H'01A'
PWMD4L          EQU    H'01B'
PWMT4L          EQU    H'01C'
PWMCON2         EQU    H'01D'
PWMD01H         EQU    H'01E'
PWM01DT         EQU    H'01F'
TMR0            EQU    H'081'
EECON1          EQU    H'08D'
EECON2          EQU    H'08E'
EEDAT           EQU    H'08F'
EEDATH          EQU    H'090'
EEADR           EQU    H'091'
EEADRH          EQU    H'092'
;------------------------ OPTION_REG  Bits------------------------
T0LSE_EN        EQU    H'07'
INTEDG          EQU    H'06'
T0CS            EQU    H'05'
T0SE            EQU    H'04'
PSA             EQU    H'03'
PS2             EQU    H'02'
PS1             EQU    H'01'
PS0             EQU    H'00'

;------------------------ STATUS  Bits------------------------
IRP             EQU    H'07'
RP1             EQU    H'06'
RP0             EQU    H'05'
TO              EQU    H'04'
PD              EQU    H'03'
Z               EQU    H'02'
DC              EQU    H'01'
C               EQU    H'00'

;------------------------ TRISB  Bits------------------------
TRISB5          EQU    H'05'
TRISB4          EQU    H'04'
TRISB3          EQU    H'03'
TRISB2          EQU    H'02'
TRISB1          EQU    H'01'
TRISB0          EQU    H'00'

;------------------------ PORTB  Bits------------------------
RB5             EQU    H'05'
RB4             EQU    H'04'
RB3             EQU    H'03'
RB2             EQU    H'02'
RB1             EQU    H'01'
RB0             EQU    H'00'

;------------------------ WPDB  Bits------------------------
WPDB5           EQU    H'05'
WPDB4           EQU    H'04'
WPDB3           EQU    H'03'
WPDB2           EQU    H'02'
WPDB1           EQU    H'01'
WPDB0           EQU    H'00'

;------------------------ WPUB  Bits------------------------
WPUB5           EQU    H'05'
WPUB4           EQU    H'04'
WPUB3           EQU    H'03'
WPUB2           EQU    H'02'
WPUB1           EQU    H'01'
WPUB0           EQU    H'00'

;------------------------ IOCB  Bits------------------------
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

;------------------------ ODCONB  Bits------------------------
ODCONB5         EQU    H'05'
ODCONB4         EQU    H'04'
ODCONB3         EQU    H'03'
ODCONB2         EQU    H'02'
ODCONB1         EQU    H'01'
ODCONB0         EQU    H'00'

;------------------------ PIR1  Bits------------------------
CMPIF           EQU    H'05'
PWMIF           EQU    H'04'
TMR2IF          EQU    H'01'

;------------------------ PIE1  Bits------------------------
CMPIE           EQU    H'05'
PWMIE           EQU    H'04'
TMR2IE          EQU    H'01'

;------------------------ CMPCON0  Bits------------------------
CMPEN           EQU    H'07'
CMPPS           EQU    H'06'
CMPNS2          EQU    H'05'
CMPNS1          EQU    H'04'
CMPNS0          EQU    H'03'
CMPNV           EQU    H'02'
CMPOUT          EQU    H'01'
CMPOEN          EQU    H'00'

;------------------------ CMPCON1  Bits------------------------
CMPIM           EQU    H'07'
AN_EN           EQU    H'06'
RBIAS_H         EQU    H'05'
RBIAS_L         EQU    H'04'
LVDS3           EQU    H'03'
LVDS2           EQU    H'02'
LVDS1           EQU    H'01'
LVDS0           EQU    H'00'

;------------------------ T2CON  Bits------------------------
TOUTPS3         EQU    H'06'
TOUTPS2         EQU    H'05'
TOUTPS1         EQU    H'04'
TOUTPS0         EQU    H'03'
TMR2ON          EQU    H'02'
T2CKPS1         EQU    H'01'
T2CKPS0         EQU    H'00'

;------------------------ OSCCON  Bits------------------------
IRCF2           EQU    H'06'
IRCF1           EQU    H'05'
IRCF0           EQU    H'04'
SWDTEN          EQU    H'01'

;------------------------ PWMCON0  Bits------------------------
CLKDIV2         EQU    H'07'
CLKDIV1         EQU    H'06'
CLKDIV0         EQU    H'05'
PWM4EN          EQU    H'04'
PWM1EN          EQU    H'01'
PWM0EN          EQU    H'00'

;------------------------ PWMCON1  Bits------------------------
PWM0DTEN        EQU    H'04'
DT_DIV1         EQU    H'01'
DT_DIV0         EQU    H'00'

;------------------------ PWMTH  Bits------------------------
PWM4D9          EQU    H'05'
PWM4D8          EQU    H'04'
PWM4T9          EQU    H'03'
PWM4T8          EQU    H'02'
PWMT9           EQU    H'01'
PWMT8           EQU    H'00'

;------------------------ PWMCON2  Bits------------------------
PWM4DIR         EQU    H'04'
PWM1DIR         EQU    H'01'
PWM0DIR         EQU    H'00'

;------------------------ PWMD01H  Bits------------------------
PWMD19          EQU    H'05'
PWMD18          EQU    H'04'
PWMD09          EQU    H'01'
PWMD08          EQU    H'00'

;------------------------ PWM01DT  Bits------------------------
PWM01DT5        EQU    H'05'
PWM01DT4        EQU    H'04'
PWM01DT3        EQU    H'03'
PWM01DT2        EQU    H'02'
PWM01DT1        EQU    H'01'
PWM01DT0        EQU    H'00'

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
EEADRH1         EQU    H'01'
EEADRH0         EQU    H'00'

