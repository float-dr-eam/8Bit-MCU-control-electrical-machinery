INDF        EQU      H'0000'
TMR0        EQU      H'0001'
PCL         EQU      H'0002'
STATUS      EQU      H'0003'
FSR         EQU      H'0004'
PORTA       EQU      H'0005'
PORTB       EQU      H'0006'
WPUA        EQU      H'0007'
WPUB        EQU      H'0008'
IOCB        EQU      H'0009'
PCLATH      EQU      H'000A'
INTCON      EQU      H'000B'
PIR1        EQU      H'000C'
PIE1        EQU      H'000D'
PWMD23H     EQU      H'000E'
PWM01DT     EQU      H'000F'
PWM23DT     EQU      H'0010'
TMR2        EQU      H'0011'
T2CON       EQU      H'0012'
PWMCON0     EQU      H'0013'
PWMCON1     EQU      H'0014'
PWMTL       EQU      H'0015'
PWMTH       EQU      H'0016'
PWMD0L      EQU      H'0017'
PWMD1L      EQU      H'0018'
PWMD2L      EQU      H'0019'
PWMD3L      EQU      H'001A'
PWMD4L      EQU      H'001B'
PWMD01H     EQU      H'001C'
PWMCON2     EQU      H'001D'
PWM4TL      EQU      H'001E'
OPTION_REG  EQU      H'0081'
TRISA       EQU      H'0085'
TRISB       EQU      H'0086'
WPDB        EQU      H'0087'
OSCCON      EQU      H'0088'
EECON1      EQU      H'008C'
EECON2      EQU      H'008D'
EEDAT       EQU      H'008E'
EEDATH      EQU      H'008F'
EEADR       EQU      H'0090'
PR2         EQU      H'0091'
PORTC       EQU      H'0092'
TRISC       EQU      H'0093'
IOCC        EQU      H'0094'
IOCA        EQU      H'0095'
EEADRH      EQU      H'0096'
WPDA        EQU      H'0097'
WPDC        EQU      H'0098'
WPUC        EQU      H'0099'
PGACON      EQU      H'009A'
ECIGCON     EQU      H'009B'
ADCON1      EQU      H'009C'
ADCON0      EQU      H'009D'
ADRESH      EQU      H'009E'
ADRESL      EQU      H'009F'
PIR2        EQU      H'0107'
PIE2        EQU      H'0108'
IICADD      EQU      H'0109'
IICCON      EQU      H'010C'
IICCON2     EQU      H'010D'
IICBUF      EQU      H'010E'
IICSTAT     EQU      H'010F'
ANSEL0      EQU      H'0110'
ANSEL1      EQU      H'0111'
ANSEL2      EQU      H'0112'
COMPCON     EQU          H'0115'
TXSTA       EQU      H'0117'
RCSTA       EQU      H'0118'
SPBRG       EQU      H'0119'
TXREG       EQU      H'011A'
RCREG       EQU      H'011B'
SPIBUF      EQU      H'011C'
SPICON      EQU      H'011D'
SPICON2     EQU      H'011E'
LVDCON      EQU      H'011F'
KEYCON0     EQU      H'018C'
KEYCON1     EQU      H'018D'
KEYCON2     EQU      H'018E'
KEYDATL     EQU      H'0190'
KEYDATH     EQU      H'0191'        
        
;------------------------STATUS  Bits-------------------------------        
IRP    EQU      H'07'
RP1    EQU      H'06'
RP0    EQU      H'05'
TO     EQU      H'04'
PD     EQU      H'03'
Z      EQU      H'02'
DC     EQU      H'01'
C      EQU      H'00'
        
        
;------------------------PORTA  Bits-------------------------------     
RA7    EQU      H'07'
RA6    EQU      H'06'
RA5    EQU      H'05'
RA4    EQU      H'04'
RA3    EQU      H'03'
RA2    EQU      H'02'
RA1    EQU      H'01'
RA0    EQU      H'00'
        
        
;------------------------PORTB  Bits-------------------------------     
RB7    EQU      H'07'
RB6    EQU      H'06'
RB5    EQU      H'05'
RB4    EQU      H'04'
RB3    EQU      H'03'
RB2    EQU      H'02'
RB1    EQU      H'01'
RB0    EQU      H'00'
        
        
;------------------------WPUA  Bits-------------------------------      
WPUA7      EQU      H'07'
WPUA6      EQU      H'06'
WPUA5      EQU      H'05'
WPUA4      EQU      H'04'
WPUA3      EQU      H'03'
WPUA2      EQU      H'02'
WPUA1      EQU      H'01'
WPUA0      EQU      H'00'
        
        
;------------------------WPUB  Bits-------------------------------      
WPUB7      EQU      H'07'
WPUB6      EQU      H'06'
WPUB5      EQU      H'05'
WPUB4      EQU      H'04'
WPUB3      EQU      H'03'
WPUB2      EQU      H'02'
WPUB1      EQU      H'01'
WPUB0      EQU      H'00'
        
        
;------------------------IOCB  Bits-------------------------------      
IOCB7      EQU      H'07'
IOCB6      EQU      H'06'
IOCB5      EQU      H'05'
IOCB4      EQU      H'04'
IOCB3      EQU      H'03'
IOCB2      EQU      H'02'
IOCB1      EQU      H'01'
IOCB0      EQU      H'00'
        
        
;------------------------INTCON  Bits-------------------------------        
GIE    EQU      H'07'
PEIE       EQU      H'06'
T0IE       EQU      H'05'
INTE       EQU      H'04'
RBIE       EQU      H'03'
T0IF       EQU      H'02'
INTF       EQU      H'01'
RBIF       EQU      H'00'
        
        
;------------------------PIR1  Bits-------------------------------      
EEIF       EQU      H'06'
RCIF       EQU      H'05'
TXIF       EQU      H'04'
SPIIF      EQU      H'03'
PWMIF      EQU      H'02'
TMR2IF     EQU      H'01'
ADIF       EQU      H'00'
        
        
;------------------------PIE1  Bits-------------------------------      
EEIE       EQU      H'06'
RCIE       EQU      H'05'
TXIE       EQU      H'04'
SPIIE      EQU      H'03'
PWMIE      EQU      H'02'
TMR2IE     EQU      H'01'
ADIE       EQU      H'00'
        
        
;------------------------PWMD23H  Bits-------------------------------       
PWMD39     EQU      H'05'
PWMD38     EQU      H'04'
PWMD29     EQU      H'01'
PWMD28     EQU      H'00'
        
        
;------------------------T2CON  Bits-------------------------------     
CLK_SEL    EQU      H'07'
TOUTPS3    EQU      H'06'
TOUTPS2    EQU      H'05'
TOUTPS1    EQU      H'04'
TOUTPS0    EQU      H'03'
TMR2ON     EQU      H'02'
T2CKPS1    EQU      H'01'
T2CKPS0    EQU      H'00'
        
        
;------------------------PWMCON0  Bits-------------------------------       
CLKDIV2    EQU      H'07'
CLKDIV1    EQU      H'06'
CLKDIV0    EQU      H'05'
PWM4EN     EQU      H'04'
PWM3EN     EQU      H'03'
PWM2EN     EQU      H'02'
PWM1EN     EQU      H'01'
PWM0EN     EQU      H'00'
        
        
;------------------------PWMCON1  Bits-------------------------------       
PWMIO_SEL1     EQU      H'07'
PWMIO_SEL0     EQU      H'06'
PWM2DTEN       EQU      H'05'
PWM0DTEN       EQU      H'04'
DT_DIV1    EQU      H'01'
DT_DIV0    EQU      H'00'
        
        
;------------------------PWMTH  Bits-------------------------------     
PWMD49     EQU      H'05'
PWMD48     EQU      H'04'
PWM4T9     EQU      H'03'
PWM4T8     EQU      H'02'
PWMT9      EQU      H'01'
PWMT8      EQU      H'00'
        
        
;------------------------PWMD01H  Bits-------------------------------       
PWMD19     EQU      H'05'
PWMD18     EQU      H'04'
PWMD09     EQU      H'01'
PWMD08     EQU      H'00'
        
        
;------------------------PWMCON2  Bits-------------------------------       
PWM4DIR    EQU      H'04'
PWM3DIR    EQU      H'03'
PWM2DIR    EQU      H'02'
PWM1DIR    EQU      H'01'
PWM0DIR    EQU      H'00'
        
        
;------------------------OPTION_REG  Bits-------------------------------        
INTEDG     EQU      H'06'
T0CS       EQU      H'05'
T0SE       EQU      H'04'
PSA    EQU      H'03'
PS2    EQU      H'02'
PS1    EQU      H'01'
PS0    EQU      H'00'
        
        
;------------------------TRISA  Bits-------------------------------     
TRISA7     EQU      H'07'
TRISA6     EQU      H'06'
TRISA5     EQU      H'05'
TRISA4     EQU      H'04'
TRISA3     EQU      H'03'
TRISA2     EQU      H'02'
TRISA1     EQU      H'01'
TRISA0     EQU      H'00'
        
        
;------------------------TRISB  Bits-------------------------------     
TRISB7     EQU      H'07'
TRISB6     EQU      H'06'
TRISB5     EQU      H'05'
TRISB4     EQU      H'04'
TRISB3     EQU      H'03'
TRISB2     EQU      H'02'
TRISB1     EQU      H'01'
TRISB0     EQU      H'00'
        
        
;------------------------WPDB  Bits-------------------------------      
WPDB7      EQU      H'07'
WPDB6      EQU      H'06'
WPDB5      EQU      H'05'
WPDB4      EQU      H'04'
WPDB3      EQU      H'03'
WPDB2      EQU      H'02'
WPDB1      EQU      H'01'
WPDB0      EQU      H'00'
        
        
;------------------------OSCCON  Bits-------------------------------        
IRCF2      EQU      H'06'
IRCF1      EQU      H'05'
IRCF0      EQU      H'04'
SWDTEN     EQU      H'01'
        
        
;------------------------EECON1  Bits-------------------------------        
EEPGD      EQU      H'07'
EETIME     EQU      H'04'
WRERR      EQU      H'03'
WREN       EQU      H'02'
WR     EQU      H'01'
RD     EQU      H'00'
        
        
;------------------------EEDAT  Bits-------------------------------     
EEDAT7     EQU      H'07'
EEDAT6     EQU      H'06'
EEDAT5     EQU      H'05'
EEDAT4     EQU      H'04'
EEDAT3     EQU      H'03'
EEDAT2     EQU      H'02'
EEDAT1     EQU      H'01'
EEDAT0     EQU      H'00'
        
        
;------------------------EEDATH  Bits-------------------------------        
EEDATH7    EQU      H'07'
EEDATH6    EQU      H'06'
EEDATH5    EQU      H'05'
EEDATH4    EQU      H'04'
EEDATH3    EQU      H'03'
EEDATH2    EQU      H'02'
EEDATH1    EQU      H'01'
EEDATH0    EQU      H'00'
        
        
;------------------------EEADR  Bits-------------------------------     
EEADR7     EQU      H'07'
EEADR6     EQU      H'06'
EEADR5     EQU      H'05'
EEADR4     EQU      H'04'
EEADR3     EQU      H'03'
EEADR2     EQU      H'02'
EEADR1     EQU      H'01'
EEADR0     EQU      H'00'
        
        
;------------------------PORTC  Bits-------------------------------     
RC3    EQU      H'03'
RC2    EQU      H'02'
RC1    EQU      H'01'
RC0    EQU      H'00'
        
        
;------------------------TRISC  Bits-------------------------------     
TRISC3     EQU      H'03'
TRISC2     EQU      H'02'
TRISC1     EQU      H'01'
TRISC0     EQU      H'00'
        
        
;------------------------IOCC  Bits-------------------------------      
IOCC3      EQU      H'03'
IOCC2      EQU      H'02'
IOCC1      EQU      H'01'
IOCC0      EQU      H'00'
        
        
;------------------------IOCA  Bits-------------------------------      
IOCA7      EQU      H'07'
IOCA6      EQU      H'06'
IOCA5      EQU      H'05'
IOCA4      EQU      H'04'
IOCA3      EQU      H'03'
IOCA2      EQU      H'02'
IOCA1      EQU      H'01'
IOCA0      EQU      H'00'
        
        
;------------------------EEADRH  Bits-------------------------------        
EEADRH3    EQU      H'03'
EEADRH2    EQU      H'02'
EEADRH1    EQU      H'01'
EEADRH0    EQU      H'00'
        
        
;------------------------WPDA  Bits-------------------------------      
WPDA7      EQU      H'07'
WPDA6      EQU      H'06'
WPDA5      EQU      H'05'
WPDA4      EQU      H'04'
WPDA3      EQU      H'03'
WPDA2      EQU      H'02'
WPDA1      EQU      H'01'
WPDA0      EQU      H'00'
        
        
;------------------------WPDC  Bits-------------------------------      
WPDC3      EQU      H'03'
WPDC2      EQU      H'02'
WPDC1      EQU      H'01'
WPDC0      EQU      H'00'
        
        
;------------------------WPUC  Bits-------------------------------      
WPUC3      EQU      H'03'
WPUC2      EQU      H'02'
WPUC1      EQU      H'01'
WPUC0      EQU      H'00'
        
        
;------------------------PGACON  Bits-------------------------------        
PGAEN      EQU      H'07'
PGACH      EQU      H'06'
GAIN1      EQU      H'01'
GAIN0      EQU      H'00'
        
        
;------------------------ECIGCON  Bits-------------------------------       
ECIGEN     EQU      H'07'
ECIGADJ5       EQU      H'05'
ECIGADJ4       EQU      H'04'
ECIGADJ3       EQU      H'03'
ECIGADJ2       EQU      H'02'
ECIGADJ1       EQU      H'01'
ECIGADJ0       EQU      H'00'
        
        
;------------------------ADCON1  Bits-------------------------------        
ADFM       EQU      H'07'
CHS4       EQU      H'06'
ADCS2      EQU      H'05'
LDO_EN     EQU      H'02'
LDO_SEL1       EQU      H'01'
LDO_SEL0       EQU      H'00'
        
        
;------------------------ADCON0  Bits-------------------------------        
ADCS1      EQU      H'07'
ADCS0      EQU      H'06'
CHS3       EQU      H'05'
CHS2       EQU      H'04'
CHS1       EQU      H'03'
CHS0       EQU      H'02'
GODONE     EQU      H'01'
ADON       EQU      H'00'
        
        
;------------------------PIR2  Bits-------------------------------      
TKIF       EQU      H'06'
COMPIF     EQU      H'05'
IICIF      EQU      H'04'
BCLIF      EQU      H'03'
RCCIF      EQU      H'02'
RACIF      EQU      H'01'
LVDIF      EQU      H'00'
        
        
;------------------------PIE2  Bits-------------------------------      
TKIE       EQU      H'06'
COMPIE     EQU      H'05'
IICIE      EQU      H'04'
BCLIE      EQU      H'03'
RCCIE      EQU      H'02'
RACIE      EQU      H'01'
LVDIE      EQU      H'00'
        
        
;------------------------IICCON  Bits-------------------------------        
IICWCOL    EQU      H'07'
SSPOV      EQU      H'06'
IICEN      EQU      H'05'
IICCKP     EQU      H'04'
IICM1      EQU      H'01'
IICM0      EQU      H'00'
        
        
;------------------------IICCON2  Bits-------------------------------       
GCEN       EQU      H'07'
ACKSTAT    EQU      H'06'
ACKDT      EQU      H'05'
ACKEN      EQU      H'04'
RCEN       EQU      H'03'
PEN    EQU      H'02'
RSEN       EQU      H'01'
SEN    EQU      H'00'
        
        
;------------------------IICSTAT  Bits-------------------------------       
IDLE       EQU      H'06'
DA     EQU      H'05'
P      EQU      H'04'
S      EQU      H'03'
RW     EQU      H'02'
BF     EQU      H'00'
        
        
;------------------------ANSEL0  Bits-------------------------------        
ANS7       EQU      H'07'
ANS6       EQU      H'06'
ANS5       EQU      H'05'
ANS4       EQU      H'04'
ANS3       EQU      H'03'
ANS2       EQU      H'02'
ANS1       EQU      H'01'
ANS0       EQU      H'00'
        
        
;------------------------ANSEL1  Bits-------------------------------        
ANS15      EQU      H'07'
ANS14      EQU      H'06'
ANS13      EQU      H'05'
ANS12      EQU      H'04'
ANS11      EQU      H'03'
ANS10      EQU      H'02'
ANS9       EQU      H'01'
ANS8       EQU      H'00'
        
        
;------------------------ANSEL2  Bits-------------------------------        
ANS18      EQU      H'02'
ANS17      EQU      H'01'
ANS16      EQU      H'00'

;------------------------COMPCON Bits-------------------------------
COMPEN       EQU        H'07'
COMPRES      EQU        H'06'
INT_SEL      EQU        H'05'
ILIM1        EQU        H'01'
ILIM0        EQU        H'00'
      
;------------------------TXSTA  Bits-------------------------------     
CSRC       EQU      H'07'
TX9EN      EQU      H'06'
TXEN       EQU      H'05'
SYNC       EQU      H'04'
SCKP       EQU      H'03'
STOPBIT    EQU      H'02'
TRMT       EQU      H'01'
TX9D       EQU      H'00'
        
        
;------------------------RCSTA  Bits-------------------------------     
SPEN       EQU      H'07'
RX9EN      EQU      H'06'
SREN       EQU      H'05'
CREN       EQU      H'04'
RCIDL      EQU      H'03'
FERR       EQU      H'02'
OERR       EQU      H'01'
RX9D       EQU      H'00'
        
        
;------------------------SPICON  Bits-------------------------------        
SPIWCOL    EQU      H'07'
SPIOV      EQU      H'06'
SPIEN      EQU      H'05'
SPICKP     EQU      H'04'
SPIM3      EQU      H'03'
SPIM2      EQU      H'02'
SPIM1      EQU      H'01'
SPIM0      EQU      H'00'
        
        
;------------------------SPICON2  Bits-------------------------------       
CKE    EQU      H'06'
MODE       EQU      H'05'
SPIBF      EQU      H'00'
        
        
;------------------------LVDCON  Bits-------------------------------        
LVD_RES    EQU      H'07'
LVD_SEL2       EQU      H'03'
LVD_SEL1       EQU      H'02'
LVD_SEL0       EQU      H'01'
LVDEN      EQU      H'00'

;------------------------KEYCON0  Bits-------------------------------        
KDONE   EQU      H'07'
CAPK2   EQU      H'05'
CAPK1   EQU      H'04'
CAPK0   EQU      H'03'
KTOUT   EQU      H'02'
KCAP    EQU      H'01'
KEN     EQU      H'00'

;------------------------KEYCON1  Bits-------------------------------        
KVREF1  EQU      H'07'
KVREF0  EQU      H'06'
KCLK1   EQU      H'05'
KCLK0   EQU      H'04'
KCHS3   EQU      H'03'
KCHS2   EQU      H'02'
KCHS1   EQU      H'01'
KCHS0   EQU      H'00'

;------------------------KEYCON2  Bits-------------------------------        
CAP_LVBO2  EQU      H'07'
CAP_LVBO1  EQU      H'06'
CAP_LVBO0  EQU      H'05'
LDOEN      EQU      H'03'
TKEN       EQU      H'00'
