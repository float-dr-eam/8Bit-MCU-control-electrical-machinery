// 8 bit integer signed unsigned modulus

signed char
__abmod(signed char dividend, signed char divisor)
{
	unsigned char	counter, sign;

	sign = 0;
	if(dividend < 0) {
		dividend = -dividend;
		sign = 1;
	}
	if(divisor < 0)
		divisor = -divisor;
	if(divisor != 0) {
		counter = 1;
		while(((unsigned char)divisor & 0x80U) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			if((unsigned char)divisor <= (unsigned char)dividend)
				dividend -= divisor;
			*(unsigned char *)&divisor >>= 1;
		} while(--counter != 0);
	}
	if(sign)
		dividend = -dividend;
	return dividend;
}
