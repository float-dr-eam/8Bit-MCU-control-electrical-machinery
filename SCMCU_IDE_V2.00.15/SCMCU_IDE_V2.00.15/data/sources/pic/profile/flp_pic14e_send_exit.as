#include "flp_pic14e.inc"

PSECT flp_send_exit_text,class=CODE,delta=2,merge=0,split=0

GLOBAL ___flp_send_exit
___flp_send_exit:

; save WREG
	movwf ___flp_WREG_temp
; Send two zero bytes
	movlw 0
	movwf ___DCByte
	dcdelay
	movwf ___DCByte
	dcdelay
; restore WREG
	movf ___flp_WREG_temp,w

	return

