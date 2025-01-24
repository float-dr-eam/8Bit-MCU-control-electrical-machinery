#include <htc.h>

void 
Delay1TCYx(unsigned char unit)
{
	do {
		_delay(1);
	} while(--unit != 0);
}

