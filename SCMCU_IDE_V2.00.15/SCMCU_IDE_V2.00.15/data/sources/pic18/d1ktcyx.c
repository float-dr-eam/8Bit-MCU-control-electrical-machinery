#include <htc.h>

/*
 * Delay multiples of 1000 Tcy
 * Passing 0 (zero) results in a delay of 256,000 cycles.
 */
void 
Delay1KTCYx(unsigned char unit)
{
	do {
		_delay(1000);
	} while(--unit != 0);
}
