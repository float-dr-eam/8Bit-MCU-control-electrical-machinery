// 16 x 16 bit multiplication with 16 bit result
#ifdef _PIC18
#define _Has_hardware_multiply 1
#else
#define _Has_hardware_multiply 0
#endif

#if defined(_PIC14E) || defined(_PIC14EX) || defined(_PIC18)
#define _Has_large_call_stack 1
#else
#define _Has_large_call_stack 0
#endif

unsigned int
__wmul(unsigned int multiplier, unsigned int multiplicand)
{
        unsigned int product;

#if _Has_hardware_multiply || _Has_large_call_stack

#define LOWBYTE(x)  (*(unsigned char *)(&x))
#define HIGHBYTE(x) (*(((unsigned char *)(&x))+1))

	// optimized to allow use of the 8 x 8 bit hardware multiply instruction
/*
a 16-bit multiply can be decomposed into the sum of three 8-bit multiplies
       a  b
*      c  d
-----------
     |   bd
     |ad  0
     |bc  0
+  ac| 0  0 (we ignore this intermediate product
             because it does not affect the low 16 bits of the result)
===========
 */
        product =  LOWBYTE(multiplier) * LOWBYTE(multiplicand);
        product += (LOWBYTE(multiplier) * HIGHBYTE(multiplicand)) << 8;
        product += (HIGHBYTE(multiplier) * LOWBYTE(multiplicand)) << 8;

#else

	product = 0;
	do {
		if(multiplier & 1)
			product += multiplicand;
		multiplicand <<= 1;
		multiplier >>= 1;
	} while(multiplier != 0);

#endif
        return product;
}
