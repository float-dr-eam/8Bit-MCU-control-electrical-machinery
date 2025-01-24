// long unsigned unsigned division

unsigned long int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__lldiv(unsigned long int divisor, unsigned long int dividend)
#else
__lldiv(unsigned long int dividend, unsigned long int divisor)
#endif
{
	unsigned long int	quotient;
	unsigned char	counter;

	quotient = 0;
	if(divisor != 0) {
		counter = 1;
		while((divisor & 0x80000000UL) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			quotient <<= 1;
			if(divisor <= dividend) {
				dividend -= divisor;
				quotient |= 1;
			}
			divisor >>= 1;
		} while(--counter != 0);
	}
	return quotient;
}
