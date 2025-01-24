;	XC8 PIC powerup routine
;
; This module may be modified to include custom code to be executed 
; immediately after reset. After performing whatever powerup code
; is required, it should jump to "start"

#include	"aspic.h"

	global	powerup,start
	psect	powerup,class=CODE,delta=2
powerup

;
;	Insert special powerup code here
;
;


; Now lets jump to start 
#if	defined(_PIC14)
	clrf	STATUS
	movlw	start>>8
	movwf	PCLATH
	goto	start & 0x7FF | (powerup & not 0x7FF)
#endif
#if	defined(_PIC14E) || defined(_PIC14EX)
	clrf	STATUS
	movlp	start>>8
	goto	start & 0x7FF | (powerup & not 0x7FF)
#endif
#if	defined(_PIC16)
	movlw	start>>8
	movwf	PCLATH
	movlw	start & 0xFF
	movwf	PCL
#endif
	end
