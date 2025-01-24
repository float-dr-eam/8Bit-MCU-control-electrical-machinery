#include "flp_pic18.inc"

;
; Send entry marker sub-routine:
; Transmits the PC stored in the top of the hardware stack
; via the data capture channel.
;

PSECT flp_send_entry_text,class=CODE,reloc=2,delta=1

GLOBAL ___flp_send_entry
___flp_send_entry:

; Save WREG
	movwf ___flp_WREG_temp, c
; Send the low byte of the PC
	movff TOSL, ___DCByte
	dcdelay
; Send the high byte of the PC
	movff TOSH, ___DCByte
	dcdelay
; Send the upper byte of the PC
	movff TOSU, ___DCByte
	dcdelay
; Restore WREG
	movf ___flp_WREG_temp, w, c

	return

