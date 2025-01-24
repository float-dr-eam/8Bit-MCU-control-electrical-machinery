// 8 x 8 bit multiplication with 8 bit result

unsigned char
__bmul(unsigned char multiplier, unsigned char multiplicand)
{
	unsigned char product = 0;

#if defined(__OPTIMIZE_SPEED__)

	if(multiplier & 0x01)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x02)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x04)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x08)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x10)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x20)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x40)
		product = (product + multiplicand) & 0xff;
	multiplicand <<= 1;

	if(multiplier & 0x80)
		product = (product + multiplicand) & 0xff;

#else
	do {
		if(multiplier & 1)
			product += multiplicand;
		multiplicand <<= 1;
		multiplier >>= 1;
	} while(multiplier != 0);

#endif
	return product;
}
