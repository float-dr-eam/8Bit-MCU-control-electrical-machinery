#define	f1	(*(unsigned long *)&ff1)

double
__fpnormalize(double ff1) {
	if((sizeof(double) == 4) && ((f1 & 0x7F800000UL)== 0)) {
			return 0.0;
	}
	return ff1;
}

