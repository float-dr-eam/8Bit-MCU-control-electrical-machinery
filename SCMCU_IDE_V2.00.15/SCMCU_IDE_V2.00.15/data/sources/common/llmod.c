// long unsigned unsigned modulus

unsigned long int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__llmod(unsigned long int divisor, unsigned long int dividend)
#else
__llmod(unsigned long int dividend, unsigned long int divisor)
#endif
{
	unsigned char	counter;

	if(divisor != 0) {
		counter = 1;
		while((divisor & 0x80000000UL) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			if((unsigned long)divisor <= (unsigned long)dividend)
				dividend -= divisor;
			*(unsigned long int *)&divisor >>= 1;
		} while(--counter != 0);
	}
	return dividend;
}
