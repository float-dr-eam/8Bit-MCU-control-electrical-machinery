#define	f1	(*(unsigned short long *)&ff1)
#define	f2	(*(unsigned short long *)&ff2)
bit
__ftge(float ff1, float ff2)
{
	if(f1 &  0x800000UL)
		f1 = 0x800000UL - f1;
	if(f2 &  0x800000UL)
		f2 = 0x800000UL - f2;
	f1 ^= 0x800000UL;
	f2 ^= 0x800000UL;
	return f1 >= f2;
}
