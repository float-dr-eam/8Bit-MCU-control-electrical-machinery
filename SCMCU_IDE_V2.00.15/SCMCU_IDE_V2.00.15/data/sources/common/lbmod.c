// byte unsigned modulus

unsigned char
__lbmod(unsigned char dividend, unsigned char divisor)
{
	unsigned char	rem;
	unsigned char	counter;

	counter = 8;
	rem = 0;
	do {
		rem = (rem << 1) | (dividend >> 7);
		dividend <<= 1;
		if(divisor <= rem)
			rem -= divisor;
	} while(--counter != 0);
	return rem;
}
