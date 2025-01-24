// long signed unsigned division

signed long int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__aldiv(signed long int divisor, signed long int dividend)
#else
__aldiv(signed long int dividend, signed long int divisor)
#endif
{
	signed long int	quotient;
	unsigned char	counter, sign;

	sign = 0;
	if(divisor < 0) {
		divisor = -divisor;
		sign = 1;
	}
	if(dividend < 0) {
		dividend = -dividend;
		sign ^= 1;
	}
	quotient = 0;
	if(divisor != 0) {
		counter = 1;
		while((divisor & 0x80000000UL) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			quotient <<= 1;
			if((unsigned long)divisor <= (unsigned long)dividend) {
				dividend -= divisor;
				quotient |= 1;
			}
			*(unsigned long int *)&divisor >>= 1;
		} while(--counter != 0);
	}
	if(sign)
		quotient = -quotient;
	return quotient;
}
