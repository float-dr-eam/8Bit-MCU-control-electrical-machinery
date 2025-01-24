#include <htc.h>

/*
 * Delay multiples of 100 Tcy
 * Passing 0 (zero) results in a delay of 25,600 cycles.
 */
void 
Delay100TCYx(unsigned char unit)
{
	do {
		_delay(100);
	} while(--unit != 0);
}
