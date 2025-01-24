// short long unsigned unsigned division

unsigned short long int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__ltdiv(unsigned short long int divisor, unsigned short long int dividend)
#else
__ltdiv(unsigned short long int dividend, unsigned short long int divisor)
#endif
{
	unsigned short long int	quotient;
	unsigned char	counter;

	quotient = 0;
	if(divisor != 0) {
		counter = 1;
		while((divisor & (unsigned short long)0x800000UL) == 0) {
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
