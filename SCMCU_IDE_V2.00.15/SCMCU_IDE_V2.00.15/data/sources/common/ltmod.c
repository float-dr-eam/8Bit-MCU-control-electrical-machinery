// short long unsigned unsigned modulus

unsigned short long int
#ifdef __PICC__
#warning TODO: update cgpic and this file to use the other prototype
__ltmod(unsigned short long int divisor, unsigned short long int dividend)
#else
__ltmod(unsigned short long int dividend, unsigned short long int divisor)
#endif
{
	unsigned char	counter;

	if(divisor != 0) {
		counter = 1;
		while((divisor & (unsigned short long)0x800000UL) == 0) {
			divisor <<= 1;
			counter++;
		}
		do {
			if((unsigned short long)divisor <= (unsigned short long)dividend)
				dividend -= divisor;
			*(unsigned short long int *)&divisor >>= 1;
		} while(--counter != 0);
	}
	return dividend;
}
