#include "flp_pic14e.inc"

;
; Send a byte located at 'src' in banked memory via the data capture channel
; 
send_dcbyte MACRO src
	BANKSEL(src)
	movf src && 0x7f,w
	movwf ___DCByte && 0x7f
ENDM

;
; Send entry sub-routine:
; Transmits the PC stored in the top of the hardware stack
; via the data capture channel.
;

PSECT send_entry_text,class=CODE,delta=2,merge=0,split=0

GLOBAL ___flp_send_entry
___flp_send_entry:

; save WREG
	movwf ___flp_WREG_temp
; send the low byte of PC
	send_dcbyte TOSL
	dcdelay
; send the high byte of the PC
	send_dcbyte TOSH
	dcdelay
; restore WREG
	movf ___flp_WREG_temp,w

	return
	 
