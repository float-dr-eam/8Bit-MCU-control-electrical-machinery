#include <htc.h>
#include <stdarg.h>

// Developed using compiler version 9.81.6907


//#ifdef __IT
//#if ((__IT & __IT_XMT_MASK) == __IT_XMT_DC)


/* GLOBAL VARIABLS */

volatile persistent char __DCByte;    // Data capture word for MPLAB to monitor
volatile persistent char __DCDelay;   // Transmit delay value for MPLAB to init


/* FUNCTION PROTOTYPES */

void __it_dc_xmt_pause(void);
void __it_trace_dc(char location_id);
void __it_log_dc(char location_id, char data_type, ...);



/*********************************************************************
* ___DCDelay to be initialized by REAL ICE based upon target speed
**********************************************************************/

void __it_dc_xmt_pause(void)
{
#asm
    banksel ___DCDelay
    movf    ___DCDelay,w
__it_pause:
    decfsz  9               ; WREG address
    bra     __it_pause
#endasm
    return;
}


/*********************************************************************
*
*   location_id:  trace location number 0x40-0x7f
*
**********************************************************************/

void __it_trace_dc(char location_id)
{

    __IT_DI_SAVE_INT_STATE;
    __DCByte = location_id;     // send byte
    __it_dc_xmt_pause();        // wait for xmt to complete
    __IT_RESTORE_INT_STATE;

    return;
}

/************************************************************************
*
*   location_id:  log location number 0x0-0x7f
*   data_type:    variable type in encoded format (see Trace16.h)
*   ...:          variable value, 1-4 bytes in length
*
*   Note: Due to bug in compiler, must copy variable argument.
*   Should be able to do the following:
*       va_start(args, data_type);
*       __it_ptr = (char *)args;
*       __it_ptr--;
*   then in loop:
*       __IT_XMT_BYTE(*__it_ptr--);
*
*************************************************************************/

void __it_log_dc(char location_id, char data_type, ...)
{
char len;
long data_var;      // buffer to hold 1-4 bytes of data
char *__it_ptr;
va_list args;


    len = (data_type & 0x7) + 1;
    __IT_DI_SAVE_INT_STATE;


    // GET POINTER TO DATA VARIABLE
    va_start(args, data_type);
    data_var = va_arg(args, long);  // copy variable argument
    va_end(args);
    __it_ptr = (char *)&data_var;


   // SEND TYPE AND ID BYTES

    __DCByte = data_type;
    __it_dc_xmt_pause();

    __DCByte = location_id;
    __it_dc_xmt_pause();


    // SEND DATA VALUE

    do {
        __DCByte = *__it_ptr++;
        __it_dc_xmt_pause();
    } while (--len);


    __IT_RESTORE_INT_STATE;

    return;
}

//#endif 	/* __IT_XMT_DC */
//#endif	/* __IT */
