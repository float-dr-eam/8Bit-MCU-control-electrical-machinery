

; Special function register definitions

INDF        EQU     H'0x000'
TMR0        EQU     H'0x001'
PCL         EQU     H'0x002'
STATUS      EQU     H'0x003'
FSR         EQU     H'0x004'
PORTA       EQU     H'0x005'
PORTB       EQU     H'0x006'
WPUA        EQU     H'0x007'
WPUB        EQU     H'0x008'
IOCB        EQU     H'0x009'
PCLATH      EQU     H'0x00A'
INTCON      EQU     H'0x00B'
PIR1        EQU     H'0x00C'
PIE1        EQU     H'0x00D'
PWMD23H     EQU     H'0x00E'
PWM01DT     EQU     H'0x00F'
PWM23DT     EQU     H'0x010'
TMR2        EQU     H'0x011'
T2CON       EQU     H'0x012'
PWMCON0     EQU     H'0x013'
PWMCON1     EQU     H'0x014'
PWMTL       EQU     H'0x015'
PWMTH       EQU     H'0x016'
PWMD0L      EQU     H'0x017'
PWMD1L      EQU     H'0x018'
PWMD2L      EQU     H'0x019'
PWMD3L      EQU     H'0x01A'
PWMD4L      EQU     H'0x01B'
PWMD01H     EQU     H'0x01C'
PWMCON2     EQU     H'0x01D'

;INDF       EQU     H'0x080'
OPTION_REG  EQU     H'0x081'
;PCL        EQU     H'0x082'
;STATUS     EQU     H'0x083'
;FSR        EQU     H'0x084'
TRISA       EQU     H'0x085'
TRISB       EQU     H'0x086'
WPDB        EQU     H'0x087'
OSCCON      EQU     H'0x088'
;PCLATH     EQU     H'0x08A'
;INTCON     EQU     H'0x08B'

PR2         EQU     H'0x091'


OPA0CON     EQU     H'0x098'
OPA0ADJ     EQU     H'0x099'
OPA1CON     EQU     H'0x09A'
OPA1ADJ     EQU     H'0x09B'
ADCON1      EQU     H'0x09C'
ADCON0      EQU     H'0x09D'
ADRESL      EQU     H'0x09E'
ADRESH      EQU     H'0x09F'


; Definitions for STATUS register 
IRP         EQU     H'07'
RP1         EQU     H'06'
RP0         EQU     H'05'   
NOT_TO      EQU     H'04'
NOT_PD      EQU     H'03'
TO          EQU     H'04'   
PD          EQU     H'03'
Z           EQU     H'02'
DC          EQU     H'01'
C           EQU     H'00'

; Definitions for PORTA register 

RA5     EQU     H'05'
RA4     EQU     H'04'
RA3     EQU     H'03'
RA2     EQU     H'02'
RA1     EQU     H'01'
RA0     EQU     H'00'

; Definitions for PORTB register 
RB7     EQU     H'07'
RB6     EQU     H'06'
RB5     EQU     H'05'
RB4     EQU     H'04'
RB3     EQU     H'03'
RB2     EQU     H'02'
RB1     EQU     H'01'
RB0     EQU     H'00'



; Definitions for WPUA register 

WPUA5       EQU     H'05'
WPUA4       EQU     H'04'
WPUA3       EQU     H'03'
WPUA2       EQU     H'02'
WPUA1       EQU     H'01'
WPUA0       EQU     H'00'

; Definitions for WPUB register 
WPUB7       EQU     H'07'
WPUB6       EQU     H'06'
WPUB5       EQU     H'05'
WPUB4       EQU     H'04'
WPUB3       EQU     H'03'
WPUB2       EQU     H'02'
WPUB1       EQU     H'01'
WPUB0       EQU     H'00'

; Definitions for IOCB register 
IOCB7       EQU     H'07'
IOCB6       EQU     H'06'
IOCB5       EQU     H'05'
IOCB4       EQU     H'04'
IOCB3       EQU     H'03'
IOCB2       EQU     H'02'
IOCB1       EQU     H'01'
IOCB0       EQU     H'00'


; Definitions for INTCON register 
GIE EQU     H'07'
PEIE    EQU     H'06'
T0IE    EQU     H'05'
INTE    EQU     H'04'
RBIE    EQU     H'03'
T0IF    EQU     H'02'
INTF    EQU     H'01'
RBIF    EQU     H'00'

; Alternate definition for backward compatibility
;RABIE  EQU     H'03'
;T0IF   EQU     H'02'
;INTF   EQU     H'01'
;RBIF   EQU     H'00'

; Alternate definition for backward compatibility
;RABIF  EQU     H'00'




; Definitions for PIR1 register 
PWMIF   EQU     H'02'
TMR2IF  EQU     H'01'
ADIF    EQU     H'00'

; Definitions for PIE1 register 
PWMIE   EQU     H'02'
TMR2IE  EQU     H'01'
ADIE    EQU     H'00'

; Definitions for PWMD01H register 

PWMD39  EQU     H'05'
PWMD38  EQU     H'04'

PWMD29  EQU     H'01'
PWMD28  EQU     H'00'


; Definitions for T2CON register 
CLK_SEL EQU     H'07'
TOUTPS3 EQU     H'06'
TOUTPS2 EQU     H'05'
TOUTPS1 EQU     H'04'
TOUTPS0 EQU     H'03'
TMR2ON  EQU     H'02'
T2CKPS1 EQU     H'01'
T2CKPS0 EQU     H'00'

; Definitions for PWMCON0 register 
CLKDIV2 EQU     H'07'
CLKDIV1 EQU     H'06'
CLKDIV0 EQU     H'05'
PWM4EN  EQU     H'04'
PWM3EN  EQU     H'03'
PWM2EN  EQU     H'02'
PWM1EN  EQU     H'01'
PWM0EN  EQU     H'00'

; Definitions for PWMCON1 register 
PWMIO_SEL1  EQU     H'07'
PWMIO_SEL0  EQU     H'06'
PWM2DTEN    EQU     H'05'
PWM0DETN    EQU     H'04'

DT_DIV1     EQU     H'01'
DT_DIV0     EQU     H'00'


; Definitions for PWMD01H register 

PWMD19  EQU     H'05'
PWMD18  EQU     H'04'

PWMD09  EQU     H'01'
PWMD08  EQU     H'00'


; Definitions for PWMCON2 register 

PWM4DIR EQU     H'04'
PWM3DIR EQU     H'03'
PWM2DIR EQU     H'02'
PWM1DIR EQU     H'01'
PWM0DIR EQU     H'00'

; Definitions for OPTION_REG register 
RBPU    EQU     H'07'
INTEDG  EQU     H'06'
T0CS    EQU     H'05'
T0SE    EQU     H'04'
PSA     EQU     H'03'
PS2     EQU     H'02'
PS1     EQU     H'01'
PS0     EQU     H'00'







; Definitions for TRISA register 

TRISA5  EQU     H'05'
TRISA4  EQU     H'04'
TRISA3  EQU     H'03'
TRISA2  EQU     H'02'
TRISA1  EQU     H'01'
TRISA0  EQU     H'00'

; Definitions for TRISB register 
TRISB7  EQU     H'07'
TRISB6  EQU     H'06'
TRISB5  EQU     H'05'
TRISB4  EQU     H'04'
TRISB3  EQU     H'03'
TRISB2  EQU     H'02'
TRISB1  EQU     H'01'
TRISB0  EQU     H'00'

; Definitions for WPDB register 
WPDB7   EQU     H'07'
WPDB6   EQU     H'06'
WPDB5   EQU     H'05'
WPDB4   EQU     H'04'
WPDB3   EQU     H'03'
WPDB2   EQU     H'02'
WPDB1   EQU     H'01'
WPDB0   EQU     H'00'

; Definitions for OSCCON register 
IRCF2   EQU     H'06'
IRCF1   EQU     H'05'
IRCF0   EQU     H'04'
SWDTEN  EQU     H'01'

; Definitions for OPA0CON register 
OPA0_CON    EQU     H'07'
OPA0EN  EQU     H'06'
CMP0MODE    EQU     H'05'
OPA0_ADC    EQU     H'04'
OPA0FT  EQU     H'00'

; Definitions for OPA0ADJ register 
OPA0OUT     EQU     H'07'
OPA0COFM    EQU     H'06'
OPA0CRS     EQU     H'05'
OPA0ADJ4    EQU     H'04'
OPA0ADJ3    EQU     H'03'
OPA0ADJ2    EQU     H'02'
OPA0ADJ1    EQU     H'01'
OPA0ADJ0    EQU     H'00'

; Definitions for OPA1CON register 
OPA1_CON        EQU     H'07'
OPA1EN      EQU     H'06'
CMP1MODE    EQU     H'05'
OPA1_ADC    EQU     H'04'
OPA1FT      EQU     H'00'

; Definitions for OPA1ADJ register 
OPA1OUT     EQU     H'07'
OPA1COFM    EQU     H'06'
OPA1CRS     EQU     H'05'
OPA1ADJ4    EQU     H'04'
OPA1ADJ3    EQU     H'03'
OPA1ADJ2    EQU     H'02'
OPA1ADJ1    EQU     H'01'
OPA1ADJ0    EQU     H'00'



; Definitions for ADCON1 register 
ADFM        EQU     H'07'
LDO_EN      EQU     H'02'
LDO_SEL1    EQU     H'01'
LDO_SEL0    EQU     H'00'



; Definitions for ADCON0 register 
ADCS1   EQU     H'07'
ADCS0   EQU     H'06'
CHS3    EQU     H'05'
CHS2    EQU     H'04'
CHS1    EQU     H'03'
CHS0    EQU     H'02'
GODONE  EQU     H'01'
ADON    EQU     H'00'

