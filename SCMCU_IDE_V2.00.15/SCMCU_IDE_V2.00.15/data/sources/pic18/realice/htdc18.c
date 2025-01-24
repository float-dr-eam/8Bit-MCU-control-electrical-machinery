#include <htc.h>
#include <stdarg.h>
#include "itoption.h"

extern volatile persistent char __DCByte;   // Data capture word for MPLAB to monitor
extern volatile persistent char __DCDelay;

void __it_trace_dc(char id);
void __it_log_dc(char id, char type, ...);


void __it_trace_dc(char id)
{
	__DCByte = id;
	_delay3(__DCDelay);

	return;
}


void __it_log_dc(char id, char type, ...)
{
	char *__it_ptr;
	char len;
	long data_var;
	va_list args;

	len = (type & 0x7) + 1;

	va_start(args, type);
	data_var = va_arg(args, long);
	va_end(args);
	__it_ptr = (char *)&data_var;
	
	__DCByte = type;
	_delay3(__DCDelay);
	__DCByte = id;
	_delay3(__DCDelay);
	do {
		__DCByte = *__it_ptr++;
		_delay3(__DCDelay);
	} while (--len);

	return;
}
