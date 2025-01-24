#include <htc.h>

/*
 * Delay multiples of 10,000 Tcy
 * Passing 0 (zero) results in a delay of 2,560,000 cycles.
 */
void 
Delay10KTCYx(unsigned char unit)
{
	do {
		_delay(10000);
	} while(--unit != 0);
}
