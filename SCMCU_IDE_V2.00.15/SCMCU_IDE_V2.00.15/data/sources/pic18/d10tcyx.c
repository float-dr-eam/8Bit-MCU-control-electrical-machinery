#include <htc.h>

/*
 * Delay multiples of 10 Tcy
 * Passing 0 (zero) results in a delay of 2560 cycles.
 */
void 
Delay10TCYx(unsigned char unit)
{
	do {
		_delay(10);
	} while(--unit != 0);
}
