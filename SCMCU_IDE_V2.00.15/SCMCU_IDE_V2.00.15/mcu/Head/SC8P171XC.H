;**************************************************************************
;----- BANK0 Register -----------------------------------------------------

INDF                         EQU     H'0000'
TMR0                         EQU     H'0001'
PCL                          EQU     H'0002'
STATUS                       EQU     H'0003'
FLAGS                        EQU     H'0003'
FSR                          EQU     H'0004'
PORTA                        EQU     H'0005'
PORTB                        EQU     H'0006'
PORTC                        EQU     H'0007'
;PORTD                        EQU     H'0008'
PORTE                        EQU     H'0009'
PCLATH                       EQU     H'000A'
INTCON                       EQU     H'000B'
PIR1                         EQU     H'000C'
PIR2                         EQU     H'000D'
TMR1L                        EQU     H'000E'
TMR1H                        EQU     H'000F'
T1CON                        EQU     H'0010'
TMR2                         EQU     H'0011'
T2CON                        EQU     H'0012'
SSPBUF                       EQU     H'0013'
SSPCON                       EQU     H'0014'
CCPR1L                       EQU     H'0015'
CCPR1H                       EQU     H'0016'
CCP1CON                      EQU     H'0017'
;RCSTA                        EQU     H'0018'
;TXREG                        EQU     H'0019'
;RCREG                        EQU     H'001A'
CCPR2L                       EQU     H'001B'
CCPR2H                       EQU     H'001C'
CCP2CON                      EQU     H'001D'
ADRESH                       EQU     H'001E'
ADCON0                       EQU     H'001F'

;----- BANK1 Register -----------------------------------------------------

;INDF                         EQU     H'0080'
OPTION_REG                   EQU     H'0081'
;PCL                          EQU     H'0082'   
;STATUS                       EQU     H'0083'
;FSR                          EQU     H'0084'    
TRISA                        EQU     H'0085'
TRISB                        EQU     H'0086'
TRISC                        EQU     H'0087'
;TRISD                        EQU     H'0088'
TRISE                        EQU     H'0089'
;PCLATH                       EQU     H'008A'    
;INTCON                       EQU     H'008B'    
PIE1                         EQU     H'008C'
PIE2                         EQU     H'008D'
;PCON                         EQU     H'008E'
OSCCON                       EQU     H'008F'
OSCTUNE                      EQU     H'0090'
SSPCON2                      EQU     H'0091'
PR2                          EQU     H'0092'
SSPADD                       EQU     H'0093' 
SSPSTAT                      EQU     H'0094'
WPUB                         EQU     H'0095'
IOCB                         EQU     H'0096'
;VRCON                        EQU     H'0097'
;TXSTA                        EQU     H'0098'
;SPBRG                        EQU     H'0099'
;SPBRGH                       EQU     H'009A'
;WPUA                      EQU     H'009B'
;WPUC                       EQU     H'009C'
;WPUE                      EQU     H'009D'
ADRESL                       EQU     H'009E'
ADCON1                       EQU     H'009F'

;----- BANK2 Register -----------------------------------------------------

;INDF                         EQU     H'0100'
;TMR0                         EQU     H'0101'
;PCL                          EQU     H'0102'
;STATUS                       EQU     H'0103'
;FSR                          EQU     H'0104'
WDTCON                       EQU     H'0105'
;PORTB                        EQU     H'0106'
;CM1CON0                      EQU     H'0107'
;CM2CON0                      EQU     H'0108'
;CM2CON1                      EQU     H'0109'
;PCLATH                       EQU     H'010A'
;INTCON                       EQU     H'010B'
EEDATA                       EQU     H'010C'
EEADR                        EQU     H'010D'
EEDATH                       EQU     H'010E'
EEADRH                       EQU     H'010F'
TABLE_SPH                    EQU     H'0110'
TABLE_SPL                    EQU     H'0111'
TABLE_DATAH                  EQU     H'0112'
KEYCON0                      EQU     H'0113'
KEYCON1                      EQU     H'0114'
KEYDATAL                     EQU     H'0115'
KEYDATAH                     EQU     H'0116'

WPUE                         EQU     H'011A'
OPA0CON                      EQU     H'011C'
OPA0ADJ                      EQU     H'011D'
;----- BANK3 Register -----------------------------------------------------

;INDF                         EQU     H'0180'
;OPTION_REG                   EQU     H'0181'
;PCL                          EQU     H'0182'   
;STATUS                       EQU     H'0183'
;FSR                          EQU     H'0184' 
;SRCON                        EQU     H'0185'
;TRISB                        EQU     H'0186'
;BAUDCTL                      EQU     H'0187'
ANSEL                        EQU     H'0188'
ANSELH                       EQU     H'0189'
;PCLATH                       EQU     H'018A'
;INTCON                       EQU     H'018B'  
EECON1                       EQU     H'018C'  
EECON2                       EQU     H'018D'  
WPUA                         EQU     H'018E'  
WPUC                         EQU     H'018F' 

LCDCON0						EQU			H'0190'  
LEDCON0						EQU			H'0190'
LCDCON1						EQU			H'0191' 
LEDCON1						EQU			H'0191'
LCDADD						EQU			H'0192'  
LEDADD						EQU			H'0192'
LCDDATA						EQU			H'0193'
LEDDATA						EQU			H'0193'

SEGEN2						EQU			H'0194'
SEGEN1						EQU			H'0195'
SEGEN0						EQU			H'0196'
COMEN						EQU			H'0197'

;**************************************************************************
;----- STATUS Bits --------------------------------------------------------

IRP                          EQU     H'0007'
RP1                          EQU     H'0006' 
RP0                          EQU     H'0005'  
NOT_TO                       EQU     H'0004' 
NOT_PD                       EQU     H'0003'  
Z                            EQU     H'0002'
DC                           EQU     H'0001'
C                            EQU     H'0000'

;----- INTCON Bits --------------------------------------------------------

GIE                          EQU     H'0007'
PEIE                         EQU     H'0006'
T0IE                         EQU     H'0005' 
INTE                         EQU     H'0004'  
RBIE                         EQU     H'0003'
T0IF                         EQU     H'0002'
INTF                         EQU     H'0001'
RBIF                         EQU     H'0000'

;----- PIR1 Bits ----------------------------------------------------------

ADIF                         EQU     H'0006'
RCIF                         EQU     H'0005'
TXIF                         EQU     H'0004'
SSPIF                        EQU     H'0003'
CCP1IF                       EQU     H'0002'
TMR2IF                       EQU     H'0001'
TMR1IF                       EQU     H'0000'

;----- PIR2 Bits ----------------------------------------------------------

;OSFIF                        EQU     H'0007'
C2IF                          EQU     H'0006'
C1IF                          EQU     H'0005'
EEIF                         EQU     H'0004'
BCLIF                        EQU     H'0003'
;ULPWUIF                      EQU     H'0002'
CCP2IF                       EQU     H'0000'

;----- T1CON Bits ---------------------------------------------------------

T1GIV                        EQU     H'0007'
TMR1GE                       EQU     H'0006'
T1CKPS1                      EQU     H'0005'
T1CKPS0                      EQU     H'0004'
T1OSCEN                      EQU     H'0003'     
T1SYNC                       EQU     H'0002'
TMR1CS                       EQU     H'0001'
TMR1ON                       EQU     H'0000'

;----- T2CON Bits ---------------------------------------------------------

TOUTPS3                      EQU     H'0006'
TOUTPS2                      EQU     H'0005'
TOUTPS1                      EQU     H'0004'
TOUTPS0                      EQU     H'0003'
TMR2ON                       EQU     H'0002'
T2CKPS1                      EQU     H'0001'
T2CKPS0                      EQU     H'0000'

;----- SSPCON Bits --------------------------------------------------------

WCOL                         EQU     H'0007'
SSPOV                        EQU     H'0006'
SSPEN                        EQU     H'0005'
CKP                          EQU     H'0004'
SSPM3                        EQU     H'0003'
SSPM2                        EQU     H'0002'
SSPM1                        EQU     H'0001'
SSPM0                        EQU     H'0000'

;----- SSPCON2 Bits -------------------------------------------------------

GCEN                         EQU     H'0007'
ACKSTAT                      EQU     H'0006'
ACKDT                        EQU     H'0005'
ACKEN                        EQU     H'0004'
RCEN                         EQU     H'0003'
PEN                          EQU     H'0002'
RSEN                         EQU     H'0001'   
SEN                          EQU     H'0000'  

;----- SSPSTAT Bits -------------------------------------------------------

SMP                          EQU     H'0007'
CKE                          EQU     H'0006'
D                            EQU     H'0005'
NOT_A                        EQU     H'0005'
P                            EQU     H'0004'
S                            EQU     H'0003'
R                            EQU     H'0002'
NOT_W                        EQU     H'0002'
UA                           EQU     H'0001'
BF                           EQU     H'0000'

;----- RCSTA Bits ---------------------------------------------------------

;SPEN                         EQU     H'0007'
;RX9                          EQU     H'0006'
;RC9                          EQU     H'0006'    ; Backward compatibility only
;NOT_RC8                      EQU     H'0006'    ; Backward compatibility only
;RC8_9                        EQU     H'0006'    ; Backward compatibility only
;SREN                         EQU     H'0005'
;CREN                         EQU     H'0004'
;ADDEN                        EQU     H'0003'
;FERR                         EQU     H'0002'
;OERR                         EQU     H'0001'
;RX9D                         EQU     H'0000'
;RCD8                         EQU     H'0000'    ; Backward compatibility only

;----- CCP1CON Bits -------------------------------------------------------

P1M1                         EQU     H'0007'
P1M0                         EQU     H'0006'
DC1B1                        EQU     H'0005'
CCP1X                        EQU     H'0005'     
DC1B0                        EQU     H'0004'     
CCP1M3                       EQU     H'0003'
CCP1M2                       EQU     H'0002'
CCP1M1                       EQU     H'0001'
CCP1M0                       EQU     H'0000'

;----- CCP2CON Bits -------------------------------------------------------

DC2B1                        EQU     H'0005'
DC2B0                        EQU     H'0004'
CCP2M3                       EQU     H'0003'
CCP2M2                       EQU     H'0002'
CCP2M1                       EQU     H'0001'
CCP2M0                       EQU     H'0000'

;----- ADCON0 Bits --------------------------------------------------------

ADCS1                        EQU     H'0007'
ADCS0                        EQU     H'0006'
CHS3                         EQU     H'0005'
CHS2                         EQU     H'0004'
CHS1                         EQU     H'0003'
CHS0                         EQU     H'0002'
GO                           EQU     H'0001'
NOT_DONE                     EQU     H'0001'
ADON                         EQU     H'0000'

;----- OPTION_REG Bits ----------------------------------------------------

NOT_RBPU                     EQU     H'0007'
INTEDG                       EQU     H'0006'
T0CS                         EQU     H'0005'
T0SE                         EQU     H'0004'
PSA                          EQU     H'0003'
PS2                          EQU     H'0002'
PS1                          EQU     H'0001'
PS0                          EQU     H'0000'

;----- ADCON1 Bits --------------------------------------------------------

ADFM                         EQU      H'0007'
VCFG1                        EQU      H'0005'
VCFG0                        EQU      H'0004'

;----- PIE1 Bits ----------------------------------------------------------

ADIE                         EQU     H'0006'
RCIE                         EQU     H'0005'
TXIE                         EQU     H'0004'
SSPIE                        EQU     H'0003'
CCP1IE                       EQU     H'0002'
TMR2IE                       EQU     H'0001'
TMR1IE                       EQU     H'0000'

;----- PIE2 Bits ----------------------------------------------------------

;OSFIE                       EQU     H'0007'
C2IE                         EQU     H'0006'
C1IE                         EQU     H'0005'
EEIE                         EQU     H'0004'
BCLIE                        EQU     H'0003'
;ULPWUIE                      EQU     H'0002'
CCP2IE                       EQU     H'0000'

;----- PCON Bits ----------------------------------------------------------

;ULPWUE                      EQU     H'0005'
;SBOREN                      EQU     H'0004'
;NOT_POR                      EQU     H'0001'
;NOT_BO                       EQU     H'0000'
;NOT_BOR                      EQU     H'0000'

;----- OSCCON Bits --------------------------------------------------------

IRCF2                        EQU     H'0006'
IRCF1                        EQU     H'0005'
IRCF0                        EQU     H'0004'
;OSTS                         EQU     H'0003'
;HTS                          EQU     H'0002'
;LTS                          EQU     H'0001'
SCS                          EQU     H'0000'

;----- OSCTUNE Bits -------------------------------------------------------

TUN4                         EQU     H'0004'
TUN3                         EQU     H'0003'
TUN2                         EQU     H'0002'
TUN1                         EQU     H'0001'
TUN0                         EQU     H'0000'

;----- WPUB Bits ----------------------------------------------------------

WPUB7                        EQU     H'0007'
WPUB6                        EQU     H'0006'
WPUB5                        EQU     H'0005'
WPUB4                        EQU     H'0004'
WPUB3                        EQU     H'0003'
WPUB2                        EQU     H'0002'
WPUB1                        EQU     H'0001'
;WPUB0                        EQU     H'0000'

;----- IOCB Bits ----------------------------------------------------------

IOCB7                        EQU     H'0007'
IOCB6                        EQU     H'0006'
IOCB5                        EQU     H'0005'
IOCB4                        EQU     H'0004'
IOCB3                        EQU     H'0003'
IOCB2                        EQU     H'0002'
IOCB1                        EQU     H'0001'
;IOCB0                        EQU     H'0000'

;----- VRCON Bits ---------------------------------------------------------

VREN                         EQU     H'0007'
VROE                         EQU     H'0006'
VRR                          EQU     H'0005'
VRSS                         EQU     H'0004'
VR3                          EQU     H'0003'
VR2                          EQU     H'0002'
VR1                          EQU     H'0001'
VR0                          EQU     H'0000'

;----- TXSTA Bits ---------------------------------------------------------

;CSRC                         EQU     H'0007'
;TX9                          EQU     H'0006'
;NOT_TX8                      EQU     H'0006'    
;TX8_9                        EQU     H'0006'    
;TXEN                         EQU     H'0005'
;SYNC                         EQU     H'0004'
;SENDB                        EQU     H'0003'
;BRGH                         EQU     H'0002'
;TRMT                         EQU     H'0001'
;TX9D                         EQU     H'0000'
;TXD8                         EQU     H'0000'    

;----- SPBRG Bits ---------------------------------------------------------

;BRG7                         EQU     H'0007'
;BRG6                         EQU     H'0006'
;BRG5                         EQU     H'0005'
;BRG4                         EQU     H'0004'
;BRG3                         EQU     H'0003'
;BRG2                         EQU     H'0002'
;BRG1                         EQU     H'0001'
;BRG0                         EQU     H'0000'

;----- SPBRGH Bits --------------------------------------------------------

;BRG15                        EQU     H'0007'
;BRG14                        EQU     H'0006'
;BRG13                        EQU     H'0005'
;BRG12                        EQU     H'0004'
;BRG11                        EQU     H'0003'
;BRG10                        EQU     H'0002'
;BRG9                         EQU     H'0001'
;BRG8                         EQU     H'0000'

;----- PWM1CON Bits -------------------------------------------------------

PRSEN                        EQU     H'0007'
PDC6                         EQU     H'0006'
PDC5                         EQU     H'0005'
PDC4                         EQU     H'0004'
PDC3                         EQU     H'0003'
PDC2                         EQU     H'0002'
PDC1                         EQU     H'0001'
PDC0                         EQU     H'0000'

;----- ECCPAS Bits --------------------------------------------------------

ECCPASE                      EQU     H'0007'
ECCPAS2                      EQU     H'0006'
ECCPAS1                      EQU     H'0005'
ECCPAS0                      EQU     H'0004'
PSSAC1                       EQU     H'0003'
PSSAC0                       EQU     H'0002'
PSSBD1                       EQU     H'0001'
PSSBD0                       EQU     H'0000'

;----- PSTRCON Bits -------------------------------------------------------

STRSYNC                      EQU     H'0004'
STRD                         EQU     H'0003'
STRC                         EQU     H'0002'
STRB                         EQU     H'0001'
STRA                         EQU     H'0000'

;----- WDTCON Bits --------------------------------------------------------

WDTPS3                       EQU     H'0004'
WDTPS2                       EQU     H'0003'
WDTPS1                       EQU     H'0002'
WDTPS0                       EQU     H'0001'
;SWDTEN                       EQU     H'0000'

;----- CM1CON0 Bits -------------------------------------------------------

C1ON                         EQU     H'0007'
C1OUT                        EQU     H'0006'
C1OE                         EQU     H'0005'
C1POL                        EQU     H'0004'
C1R                          EQU     H'0002'
C1CH1                        EQU     H'0001'
C1CH0                        EQU     H'0000'

;----- CM2CON0 Bits -------------------------------------------------------

C2ON                         EQU     H'0007'
C2OUT                        EQU     H'0006'
C2OE                         EQU     H'0005'
C2POL                        EQU     H'0004'
C2R                          EQU     H'0002'
C2CH1                        EQU     H'0001'
C2CH0                        EQU     H'0000'

;----- CM2CON1 Bits -------------------------------------------------------

MC1OUT                       EQU     H'0007'
MC2OUT                       EQU     H'0006'
C1RSEL                       EQU     H'0005'
C2RSEL                       EQU     H'0004'
T1GSS                        EQU     H'0001'
C2SYNC                       EQU     H'0000'

;----- C1ADJ Bits ---------------------------------------------------------

C1OUT1                        EQU     H'0007'
C1COFM                       EQU     H'0006'
C1CRS                        EQU     H'0005'
C1ADJ3                       EQU     H'0003'
C1ADJ2                       EQU     H'0002'
C1ADJ1                       EQU     H'0001'
C1ADJ0                       EQU     H'0000'

;----- C2ADJ Bits ---------------------------------------------------------

C2OUT1                        EQU     H'0007'
C2COFM                       EQU     H'0006'
C2CRS                        EQU     H'0005'
C2ADJ3                       EQU     H'0003'
C2ADJ2                       EQU     H'0002'
C2ADJ1                       EQU     H'0001'
C2ADJ0                       EQU     H'0000'

;----- SRCON Bits ---------------------------------------------------------

SR1                          EQU     H'0007'
SR0                          EQU     H'0006'
C1SEN                        EQU     H'0005'
C2REN                        EQU     H'0004'
PULSS                        EQU     H'0003'
PULSR                        EQU     H'0002'
FVREN                        EQU     H'0000'

;----- BAUDCTL Bits -------------------------------------------------------

;ABDOVF                       EQU     H'0007'
;RCIDL                        EQU     H'0006'
;SCKP                         EQU     H'0004'
;BRG16                        EQU     H'0003'
;WUE                          EQU     H'0001'
;ABDEN                        EQU     H'0000'

;----- ANSEL Bits ---------------------------------------------------------

ANS7                         EQU     H'0007'
ANS6                         EQU     H'0006'
ANS5                         EQU     H'0005'
ANS4                         EQU     H'0004'
ANS3                         EQU     H'0003'
ANS2                         EQU     H'0002'
ANS1                         EQU     H'0001'
ANS0                         EQU     H'0000'

;----- ANSELH Bits --------------------------------------------------------

ANS13                        EQU     H'0005'
ANS12                        EQU     H'0004'
ANS11                        EQU     H'0003'
ANS10                        EQU     H'0002'
ANS9                         EQU     H'0001'
ANS8                         EQU     H'0000'

;----- EECON1 Bits --------------------------------------------------------

EEPGD                        EQU     H'0007'
WRERR                        EQU     H'0003'
WREN                         EQU     H'0002'
WR                           EQU     H'0001'
RD                           EQU     H'0000'

;----- KEYCON0 Bits -------------------------------------------------------

KDONE                        EQU     H'0007'
CAPK2                        EQU     H'0005'
CAPK1                        EQU     H'0004'
CAPK0                        EQU     H'0003'
KTOUT                        EQU     H'0002'
KCAP                         EQU     H'0001'
KEN                          EQU     H'0000'              

;----- KEYCON1 Bits -------------------------------------------------------

KVREF1                       EQU     H'0007'
KVREF0                       EQU     H'0006'
KCLK1                        EQU     H'0005'
KCLK0                        EQU     H'0004'
KCHS3                        EQU     H'0003'
KCHS2                        EQU     H'0002'
KCHS1                        EQU     H'0001'
KCHS0                        EQU     H'0000'              

;----- LCDCON0 Bits -------------------------------------------------------

LCDEN                        EQU     H'0007'
LEDEN                        EQU     H'0006'
COMSEL1                      EQU     H'0005'
COMSEL0                      EQU     H'0004'
LCDCLK3                      EQU     H'0003'
LCDCLK2                      EQU     H'0002'
LCDCLK1                      EQU     H'0001'
LCDCLK0                      EQU     H'0000'              

;----- LCDCON1 Bits -------------------------------------------------------

VLCDS                        EQU     H'0007'
SEGOUT1                      EQU     H'0005'
SEGOUT0                      EQU     H'0004'
VSTEPS3                      EQU     H'0003'
VSTEPS2                      EQU     H'0002'
VSTEPS1                      EQU     H'0001'
VSTEPS0                      EQU     H'0000'              

;----- LCDADD Bits --------------------------------------------------------

LCDCS                        EQU     H'0007'            
LCDADD6                      EQU     H'0006'
LCDADD5                      EQU     H'0005'
LCDADD4                      EQU     H'0004'
LCDADD3                      EQU     H'0003'
LCDADD2                      EQU     H'0002'
LCDADD1                      EQU     H'0001'
LCDADD0                      EQU     H'0000'


