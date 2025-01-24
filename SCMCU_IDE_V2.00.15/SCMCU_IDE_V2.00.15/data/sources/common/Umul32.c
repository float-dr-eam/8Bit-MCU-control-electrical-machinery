// 32 x 32 bit multiplication with 32 bit result
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

unsigned long
__lmul(unsigned long multiplier, unsigned long multiplicand)
{
	unsigned long product;

#define LOWBYTE(x)  (*(unsigned char *)(&x))
#define LMIDBYTE(x) (*(((unsigned char *)(&x))+1))
#define HMIDBYTE(x) (*(((unsigned char *)(&x))+2))
#define HIGHBYTE(x) (*(((unsigned char *)(&x))+3))

#if (_Has_hardware_multiply || _Has_large_call_stack) && defined(__OPTIMIZE_SPEED__)
	{

#define USE_SHRINK

/*
a 32-bit multiply can be decomposed into the sum of ten 8-bit multiplies
             a  b  c  d
*            e  f  g  h
-----------------------
           |         dh
           |      ch  0
           |   bh  0  0
           |ah  0  0  0
           |      dg  0
           |   cg  0  0
           |bg  0  0  0
         ag| 0  0  0  0 (we ignore this intermediate product
                         because it does not affect the low 32 bits of the result)
           |   df  0  0
           |cf  0  0  0
         bf| 0  0  0  0 (ignore)
      af  0| 0  0  0  0 (ignore)
           |de  0  0  0
         ce| 0  0  0  0 (ignore)
      be  0| 0  0  0  0 (ignore)
+  ae  0  0| 0  0  0  0 (ignore)
=======================
 */
		product =  (unsigned int)LOWBYTE(multiplier) * LOWBYTE(multiplicand);

#if defined(USE_MASKS)
		product += ((unsigned long)
			     ((unsigned int)LOWBYTE(multiplier) * LMIDBYTE(multiplicand))
			     +
			     ((unsigned int)LMIDBYTE(multiplier) * LOWBYTE(multiplicand)))
			<< 8;

		product += ((unsigned long)
			    ((unsigned int)LOWBYTE(multiplier) * HMIDBYTE(multiplicand))
			    +
			    ((unsigned int)LMIDBYTE(multiplier) * LMIDBYTE(multiplicand))
			    +
			    ((unsigned int)HMIDBYTE(multiplier) * LOWBYTE(multiplicand)))
			<< 16;

		/* cast to smaller type to avoid adding high bits just to discard */
		product += ((unsigned long)
			    (unsigned char)
			    ((unsigned int)LOWBYTE(multiplier) * HIGHBYTE(multiplicand))
			    +
			    (unsigned char)
			    ((unsigned int)LMIDBYTE(multiplier) * HMIDBYTE(multiplicand))
			    +
			    (unsigned char)
			    ((unsigned int)HMIDBYTE(multiplier) * LMIDBYTE(multiplicand))
			    +
			    (unsigned char)
			    ((unsigned int)HIGHBYTE(multiplier) * LOWBYTE(multiplicand)))
			<< 24;

#elif defined(USE_SHRINK)
		/* add direct to upper bytes, rather than shift and add all bytes */
		*((unsigned short long*)(((unsigned char*)&product)+1)) +=
			((unsigned int)LOWBYTE(multiplier) * LMIDBYTE(multiplicand));
		*((unsigned short long*)(((unsigned char*)&product)+1)) +=
			((unsigned int)LMIDBYTE(multiplier) * LOWBYTE(multiplicand));


		*((unsigned int*)(((unsigned char*)&product)+2)) +=
			((unsigned int)LOWBYTE(multiplier) * HMIDBYTE(multiplicand));
		*((unsigned int*)(((unsigned char*)&product)+2)) +=
			((unsigned int)LMIDBYTE(multiplier) * LMIDBYTE(multiplicand));
		*((unsigned int*)(((unsigned char*)&product)+2)) +=
			((unsigned int)HMIDBYTE(multiplier) * LOWBYTE(multiplicand));

		*(((unsigned char*)&product)+3) +=
			(unsigned char)
			((unsigned int)LOWBYTE(multiplier) * HIGHBYTE(multiplicand));
		*(((unsigned char*)&product)+3) +=
			(unsigned char)
			((unsigned int)LMIDBYTE(multiplier) * HMIDBYTE(multiplicand));
		*(((unsigned char*)&product)+3) +=
			(unsigned char)
			((unsigned int)HMIDBYTE(multiplier) * LMIDBYTE(multiplicand));
		*(((unsigned char*)&product)+3) +=
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
