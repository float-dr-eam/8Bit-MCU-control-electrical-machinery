// 8 bit signed division

signed char
__abdiv(signed char dividend, signed char divisor)
{
	signed char	quotient;
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
		while((divisor & 0x80U) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			quotient <<= 1;
			if((unsigned char)divisor <= (unsigned char)dividend) {
				dividend -= divisor;
				quotient |= 1;
			}
			*(unsigned char *)&divisor >>= 1;
		} while(--counter != 0);
	}
	if(sign)
		quotient = -quotient;
	return quotient;
}
