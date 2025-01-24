// word unsigned division

unsigned int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__lwdiv(unsigned int divisor, unsigned int dividend)
#else
__lwdiv(unsigned int dividend, unsigned int divisor)
#endif
{
	unsigned int	quotient;
	unsigned char	counter;

	quotient = 0;
	if(divisor != 0) {
		counter = 1;
		while((divisor & 0x8000) == 0) {
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
