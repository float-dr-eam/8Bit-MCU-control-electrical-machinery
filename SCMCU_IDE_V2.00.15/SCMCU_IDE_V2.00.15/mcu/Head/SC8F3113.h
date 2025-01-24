		
INDF	    EQU	     H'0000'
TMR0	    EQU	     H'0001'
PCL	    EQU	     H'0002'
STATUS	    EQU	     H'0003'
FSR	    EQU	     H'0004'
PORTA	    EQU	     H'0005'
PORTB	    EQU	     H'0006'
WPUA	    EQU	     H'0007'
WPUB	    EQU	     H'0008'
IOCA	    EQU	     H'0009'
PCLATH	    EQU	     H'000A'
INTCON	    EQU	     H'000B'
PIR1	    EQU	     H'000C'
ANSEL0	    EQU	     H'000D'
TMR1L	    EQU	     H'000E'
TMR1H	    EQU	     H'000F'
T1CON	    EQU	     H'0010'
PWMCON0	    EQU	     H'0011'
PWMTL	    EQU	     H'0012'
PWMTH	    EQU	     H'0013'
PWMD0L	    EQU	     H'0014'
PWMD1L	    EQU	     H'0015'
PWMD2L	    EQU	     H'0016'
PWMD3L	    EQU	     H'0017'
PWMD4L	    EQU	     H'0018'
PWMD01H	    EQU	     H'0019'
PWMD23H	    EQU	     H'001A'
CMPCON0	    EQU	     H'001B'
CMPCON1	    EQU	     H'001C'
OSCCON	    EQU	     H'001D'
LVDCON	    EQU	     H'001E'
WDTCON	    EQU	     H'001F'
OPTION_REG	    EQU	     H'0081'
TRISA	    EQU	     H'0085'
TRISB	    EQU	     H'0086'
WPDA	    EQU	     H'0087'
WPDB	    EQU	     H'0088'
IOCB	    EQU	     H'0089'
PIE1	    EQU	     H'008C'
TABLE_SPH	    EQU	     H'008D'
TABLE_SPL	    EQU	     H'008E'
TABLE_DATAH	    EQU	     H'008F'
		
		
		
		
;------------------------STATUS  Bits-------------------------------		
RP1	   EQU	    H'06'
RP0	   EQU	    H'05'
TO	   EQU	    H'04'
PD	   EQU	    H'03'
Z	   EQU	    H'02'
DC	   EQU	    H'01'
C	   EQU	    H'00'
		
		
;------------------------PORTA  Bits-------------------------------		
RA6	   EQU	    H'06'
RA5	   EQU	    H'05'
RA4	   EQU	    H'04'
RA3	   EQU	    H'03'
RA2	   EQU	    H'02'
RA1	   EQU	    H'01'
RA0	   EQU	    H'00'
		
		
;------------------------PORTB  Bits-------------------------------		
RB6	   EQU	    H'06'
RB5	   EQU	    H'05'
RB4	   EQU	    H'04'
RB3	   EQU	    H'03'
RB2	   EQU	    H'02'
RB1	   EQU	    H'01'
RB0	   EQU	    H'00'
		
		
;------------------------WPUA  Bits-------------------------------		
WPUA6	   EQU	    H'06'
WPUA5	   EQU	    H'05'
WPUA4	   EQU	    H'04'
WPUA3	   EQU	    H'03'
WPUA2	   EQU	    H'02'
WPUA1	   EQU	    H'01'
WPUA0	   EQU	    H'00'
		
		
;------------------------WPUB  Bits-------------------------------		
WPUB6	   EQU	    H'06'
WPUB5	   EQU	    H'05'
WPUB4	   EQU	    H'04'
WPUB3	   EQU	    H'03'
WPUB2	   EQU	    H'02'
WPUB1	   EQU	    H'01'
WPUB0	   EQU	    H'00'
		
		
;------------------------IOCA  Bits-------------------------------		
IOCA6	   EQU	    H'06'
IOCA5	   EQU	    H'05'
IOCA4	   EQU	    H'04'
IOCA3	   EQU	    H'03'
IOCA2	   EQU	    H'02'
IOCA1	   EQU	    H'01'
IOCA0	   EQU	    H'00'
		
		
;------------------------INTCON  Bits-------------------------------		
GIE	   EQU	    H'07'
PEIE	   EQU	    H'06'
T0IE	   EQU	    H'05'
INTE	   EQU	    H'04'
RBIE	   EQU	    H'03'
T0IF	   EQU	    H'02'
INTF	   EQU	    H'01'
RBIF	   EQU	    H'00'
		
		
;------------------------PIR1  Bits-------------------------------		
CMPIF	   EQU	    H'04'
LVDIF	   EQU	    H'03'
PWMIF	   EQU	    H'02'
RACIF	   EQU	    H'01'
TMR1IF	   EQU	    H'00'
		
		
;------------------------ANSEL0  Bits-------------------------------		
ANS6	   EQU	    H'06'
ANS5	   EQU	    H'05'
ANS4	   EQU	    H'04'
		
		
;------------------------T1CON  Bits-------------------------------		
T1GINV	   EQU	    H'07'
TMR1GE	   EQU	    H'06'
T1CKPS1	   EQU	    H'05'
T1CKPS0	   EQU	    H'04'
T1SYNC	   EQU	    H'02'
TMR1CS	   EQU	    H'01'
TMR1ON	   EQU	    H'00'
		
		
;------------------------PWMCON0  Bits-------------------------------		
CLKDIV2	   EQU	    H'07'
CLKDIV1	   EQU	    H'06'
CLKDIV0	   EQU	    H'05'
PWM4EN	   EQU	    H'04'
PWM3EN	   EQU	    H'03'
PWM2EN	   EQU	    H'02'
PWM1EN	   EQU	    H'01'
PWM0EN	   EQU	    H'00'
		
		
;------------------------PWMTH  Bits-------------------------------		
PWMD49	   EQU	    H'05'
PWMD48	   EQU	    H'04'
PWMT9	   EQU	    H'01'
PWMT8	   EQU	    H'00'
		
		
;------------------------PWMD01H  Bits-------------------------------		
PWMD19	   EQU	    H'05'
PWMD18	   EQU	    H'04'
PWMD09	   EQU	    H'01'
PWMD08	   EQU	    H'00'
		
		
;------------------------PWMD23H  Bits-------------------------------		
PWMD39	   EQU	    H'05'
PWMD38	   EQU	    H'04'
PWMD29	   EQU	    H'01'
PWMD28	   EQU	    H'00'
		
		
;------------------------CMPCON0  Bits-------------------------------		
CMPO	   EQU	    H'07'
CMP_EDGE	   EQU	    H'02'
SLP_CMPEN	   EQU	    H'01'
CMPEN	   EQU	    H'00'
		
		
;------------------------CMPCON1  Bits-------------------------------		
CMP_PSEL1	   EQU	    H'07'
CMP_PSEL0	   EQU	    H'06'
CMP_CRVO5	   EQU	    H'05'
CMP_CRVO4	   EQU	    H'04'
CMP_CRVO3	   EQU	    H'03'
CMP_CRVO2	   EQU	    H'02'
CMP_CRVO1	   EQU	    H'01'
CMP_CRVO0	   EQU	    H'00'
		
		
;------------------------OSCCON  Bits-------------------------------		
IRCF2	   EQU	    H'06'
IRCF1	   EQU	    H'05'
IRCF0	   EQU	    H'04'
		
		
;------------------------LVDCON  Bits-------------------------------		
LVD_RES	   EQU	    H'07'
LVD_SEL2	   EQU	    H'03'
LVD_SEL1	   EQU	    H'02'
LVD_SEL0	   EQU	    H'01'
LVDEN	   EQU	    H'00'
		
		
;------------------------WDTCON  Bits-------------------------------		
SWDTEN	   EQU	    H'00'
		
		
;------------------------OPTION_REG  Bits-------------------------------		
INTEDG	   EQU	    H'06'
T0CS	   EQU	    H'05'
T0SE	   EQU	    H'04'
PSA	   EQU	    H'03'
PS2	   EQU	    H'02'
PS1	   EQU	    H'01'
PS0	   EQU	    H'00'
		
		
;------------------------TRISA  Bits-------------------------------		
TRISA6	   EQU	    H'06'
TRISA5	   EQU	    H'05'
TRISA4	   EQU	    H'04'
TRISA3	   EQU	    H'03'
TRISA2	   EQU	    H'02'
TRISA1	   EQU	    H'01'
TRISA0	   EQU	    H'00'
		
		
;------------------------TRISB  Bits-------------------------------		
TRISB6	   EQU	    H'06'
TRISB5	   EQU	    H'05'
TRISB4	   EQU	    H'04'
TRISB3	   EQU	    H'03'
TRISB2	   EQU	    H'02'
TRISB1	   EQU	    H'01'
TRISB0	   EQU	    H'00'
		
		
;------------------------WPDA  Bits-------------------------------		
WPDA6	   EQU	    H'06'
WPDA5	   EQU	    H'05'
WPDA4	   EQU	    H'04'
WPDA3	   EQU	    H'03'
WPDA2	   EQU	    H'02'
WPDA1	   EQU	    H'01'
WPDA0	   EQU	    H'00'
		
		
;------------------------WPDB  Bits-------------------------------		
WPDB6	   EQU	    H'06'
WPDB5	   EQU	    H'05'
WPDB4	   EQU	    H'04'
WPDB3	   EQU	    H'03'
WPDB2	   EQU	    H'02'
WPDB1	   EQU	    H'01'
WPDB0	   EQU	    H'00'
		
		
;------------------------IOCB  Bits-------------------------------		
IOCB6	   EQU	    H'06'
IOCB5	   EQU	    H'05'
IOCB4	   EQU	    H'04'
IOCB3	   EQU	    H'03'
IOCB2	   EQU	    H'02'
IOCB1	   EQU	    H'01'
IOCB0	   EQU	    H'00'
		
		
;------------------------PIE1  Bits-------------------------------		
CMPIE	   EQU	    H'04'
LVDIE	   EQU	    H'03'
PWMIE	   EQU	    H'02'
RACIE	   EQU	    H'01'
TMR1IE	   EQU	    H'00'
