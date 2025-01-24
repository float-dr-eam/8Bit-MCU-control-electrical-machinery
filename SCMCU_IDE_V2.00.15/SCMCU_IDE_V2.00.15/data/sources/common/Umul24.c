// 24 x 24 bit multiplication with 24 bit result
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

unsigned short long
__tmul(unsigned short long multiplier, unsigned short long multiplicand)
{
	unsigned short long product;

#define LOWBYTE(x)  (*(unsigned char *)(&x))
#define MIDBYTE(x)  (*(((unsigned char *)(&x))+1))
#define HIGHBYTE(x) (*(((unsigned char *)(&x))+2))

#if (_Has_hardware_multiply || _Has_large_call_stack) && defined(__OPTIMIZE_SPEED__)
	{

#define USE_SHRINK

/*
a 24-bit multiply can be decomposed into the sum of six 8-bit multiplies
          a  b  c
*         d  e  f
-----------------
        |      cf
        |   bf  0
        |af  0  0
        |   ce  0
        |be  0  0
      ae| 0  0  0 (we ignore this intermediate product
                   because it does not affect the low 24 bits of the result)
        |cd  0  0
      bd| 0  0  0 (ignore)
+  ad  0| 0  0  0 (ignore)
=================
 */
		product =  (unsigned int)LOWBYTE(multiplier) * LOWBYTE(multiplicand);

#if  defined(USE_MASKS)
		product += ((unsigned short long)
			    ((unsigned int)LOWBYTE(multiplier) * MIDBYTE(multiplicand))
			    +
			    ((unsigned int)MIDBYTE(multiplier) * LOWBYTE(multiplicand)))
			<< 8;

		/* cast to smaller type to avoid adding high bits just to discard */
		product += ((unsigned short long)
			    (unsigned char)
			    ((unsigned int)LOWBYTE(multiplier) * HIGHBYTE(multiplicand))
			    +
			    (unsigned char)
			    ((unsigned int)MIDBYTE(multiplier) * MIDBYTE(multiplicand))
			    +
			    (unsigned char)
			    ((unsigned int)HIGHBYTE(multiplier) * LOWBYTE(multiplicand)))
			<< 16;

#elif defined(USE_SHRINK)
		/* add direct to upper bytes, rather than shift and add all bytes */
		*((unsigned int*)(((unsigned char)&product)+1)) +=
			((unsigned int)LOWBYTE(multiplier) * MIDBYTE(multiplicand));
		*((unsigned int*)(((unsigned char)&product)+1)) +=
			((unsigned int)MIDBYTE(multiplier) * LOWBYTE(multiplicand));

		*(((unsigned char*)&product)+2) +=
			(unsigned char)
			((unsigned int)LOWBYTE(multiplier) * HIGHBYTE(multiplicand));
		*(((unsigned char*)&product)+2) +=
			(unsigned char)
			((unsigned int)MIDBYTE(multiplier) * MIDBYTE(multiplicand));
		*(((unsigned char*)&product)+2) +=
			(unsigned char)
			((unsigned int)HIGHBYTE(multiplier) * LOWBYTE(multiplicand));

#else
#error No method chosen
#endif
	}
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
