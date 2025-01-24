// since we use tests on the size of operands, suppress the warnings that
// would be generated
#pragma warning disable 757

/* Convert an integer to a 32-bit floating point value.
 * sign : is val actually a signed value
 * val  : the incoming integer (signed or unsigned) for conversion, cast to a signed long
 */ 
double
__xxtofl(unsigned char sign, signed long val)
{
	unsigned char exp;
	unsigned long arg;

	if(sign && val < 0) {
		arg = -val;
	}
	else {
		arg = val;
	}
	if(val == 0)
		return 0.0;
	exp = (127 + 23);
	while(arg & ~0x1FFFFFFUL) {
		++exp;
		arg >>= 1;
	}
	while(arg & ~0xFFFFFFUL) {
		++exp;
		++arg;
		arg >>= 1;
	}
	while(!(arg & 0x800000UL) && exp > 1) {
		--exp;
		arg <<= 1;
	}
	if(!(exp & 1))
		arg &= ~0x800000UL;
	exp >>= 1;
	arg |= (unsigned long)exp << 24;
	if(sign && val < 0)
		arg |= 0x80000000UL;
	return *(double *)&arg;
}
