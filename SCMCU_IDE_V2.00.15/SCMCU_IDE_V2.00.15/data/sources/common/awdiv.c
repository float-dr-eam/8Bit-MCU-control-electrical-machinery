// integer signed division

signed int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__awdiv(signed int divisor, signed int dividend)
#else
__awdiv(signed int dividend, signed int divisor)
#endif
{
	signed int	quotient;
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
		while((divisor & 0x8000U) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			quotient <<= 1;
			if((unsigned int)divisor <= (unsigned int)dividend) {
				dividend -= divisor;
				quotient |= 1;
			}
			*(unsigned int *)&divisor >>= 1;
		} while(--counter != 0);
	}
	if(sign)
		quotient = -quotient;
	return quotient;
}
