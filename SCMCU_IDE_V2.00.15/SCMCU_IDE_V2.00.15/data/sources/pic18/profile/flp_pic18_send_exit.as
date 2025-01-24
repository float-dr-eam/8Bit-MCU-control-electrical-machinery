#include "flp_pic18.inc"

;
; Send exit marker sub-routine:
; Transmits 3 zero bytes via the data capture channel.
;

PSECT flp_send_exit_text,class=CODE,reloc=2,delta=1

GLOBAL ___flp_send_exit
___flp_send_exit:

; Save WREG
	movwf ___flp_WREG_temp, c
; Send three zero bytes
	movlw 0
	movff WREG, ___DCByte
	dcdelay
	movff WREG, ___DCByte
	dcdelay
	movff WREG, ___DCByte
	dcdelay
; Restore WREG
	movf ___flp_WREG_temp, w, c

	return

