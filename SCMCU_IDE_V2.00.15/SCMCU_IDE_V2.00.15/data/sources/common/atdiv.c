// short long signed unsigned division

signed short long int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__atdiv(signed short long int divisor, signed short long int dividend)
#else
__atdiv(signed short long int dividend, signed short long int divisor)
#endif
{
	signed short long int	quotient;
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
		while((divisor & (unsigned short long)0x800000UL) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			quotient <<= 1;
			if((unsigned short long)divisor <= (unsigned short long)dividend) {
				dividend -= divisor;
				quotient |= 1;
			}
			*(unsigned short long int *)&divisor >>= 1;
		} while(--counter != 0);
	}
	if(sign)
		quotient = -quotient;
	return quotient;
}
