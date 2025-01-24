#include <htc.h>
#include <stdarg.h>

// Developed using compiler version 9.81.6907


#ifdef __IT
#if (__IT & __IT_SPI_MASK)


/* FUNCTION PROTOTYPES */

void __IT_TRACEFUNC(char location_id);
void __IT_LOGFUNC(char location_id, char data_type, ...);


/* SPI TRANSMIT MACRO */

/* Initialization is performed by MPLAB
*
*  SPI1:                        SPI2 (16F194x):
*   TRISC3 = 0;     // SCKn         TRISD6 = 0;
*   TRISC5 = 0;     // SDOn         TRISD4 = 0;
*   SSPCON1 = 0x20;                 SSP2CON1 = 0x20;
*/

/*
// "correct way" to do spi transmit

#define __IT_XMT_BYTE(data) xchg_spi(data);

static char xchg_spi(char data)
{
    __IT_SSPBUF = data;
    while ((SSPSTAT & 0x01) == 0);  // wait for byte to xmt
    return (char)__IT_SSPBUF;       // clear flag by reading buf
}
*/

// "fast way" (fewest instructions) as recommended by Joe Julicher
//  requires spi to run at maximum clock speed
#define __IT_XMT_BYTE(data)     __IT_SSPBUF=data; \
                                _delay(8);


/*********************************************************************
*   __it_trace_spi1
*   __it_trace_spi2
*
*   location_id:  trace location number 0x40-0x7f
*
**********************************************************************/

void __IT_TRACEFUNC(char location_id)
{

    __IT_DI_SAVE_INT_STATE;
    __IT_XMT_BYTE(location_id);
    __IT_RESTORE_INT_STATE;

    return;
}


/************************************************************************
*   __it_log_spi1
*   __it_log_spi2
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

void __IT_LOGFUNC(char location_id, char data_type, ...)
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
    __IT_XMT_BYTE(data_type);
    __IT_XMT_BYTE(location_id);


    // SEND DATA VALUE
    do {
        __IT_XMT_BYTE(*__it_ptr++);
    } while (--len);


    __IT_RESTORE_INT_STATE;

    return;
}

#endif 	/* __IT_SPI_MASK */
#endif	/* __IT */
