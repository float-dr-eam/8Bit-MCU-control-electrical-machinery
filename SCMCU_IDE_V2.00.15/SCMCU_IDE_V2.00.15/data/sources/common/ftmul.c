/*	Floating point routines.

	Copyright (c) 2012 Microchip Technology Inc. All rights reserved.
*/

// this is bigendian code right now. Need to parameterise it.

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

#include	"ftarith.h"

#define	f1_as_plier	(*(unsigned short long *)&f1)
#define	f2_as_plicand	(*(unsigned short long *)&f2)

// floating addition
#ifdef _OLDLIB
#define	f3_as_product		(*(unsigned short long *)&f3)
float
__ftmul(float f1, float f2)
{
	unsigned char	exp1, sign1, cntr;
	float	f3;
	
	f3_as_product = 0;
	sign1 = __ftunpack(&f1_as_plier, &exp1);
	sign1 ^= __ftunpack(&f2_as_plicand, &cntr);
	if(cntr == 0 || exp1 == 0)
		return f3;
	exp1 += cntr-127-6;	// compute new exponent
	cntr = 7;
	do {
		if(f1_as_plier & 1)
			f3_as_product += f2_as_plicand;
		f1_as_plier >>= 1;
		f2_as_plicand <<= 1;
	} while(--cntr != 0);
	cntr = 9;
	do {
		if(f1_as_plier & 1)
			f3_as_product += f2_as_plicand;
		f1_as_plier >>= 1;
		f3_as_product >>= 1;
	} while(--cntr != 0);
	__ftpack(&f3_as_product, exp1);
	if(sign1)
		f3_as_product |= 0x800000;
	return f3;
}
#else
#define	exp2	sign
float
__ftmul(float f1, float f2)
{
	unsigned char	exp, sign, cntr;
	unsigned short long	f3_as_product;

	if((exp = f1_as_plier >> 15) == 0)
		return 0.0;
	if((exp2 = f2_as_plicand >> 15) == 0)
		return 0.0;
	exp += exp2-127-6;	// compute new exponent
	sign = f1_as_plier >> 16;
	sign ^= (unsigned char)(f2_as_plicand >> 16);
	sign &= 0x80;
	f1_as_plier |= 0x8000UL;
	//f1_as_plier &= 0xFFFFUL;		// not required
	f2_as_plicand |= 0x8000UL;
	f2_as_plicand &= 0xFFFFUL;
	f3_as_product = 0;

#define LOWBYTE(x)  (*(unsigned char *)(&x))
#define HIGHBYTE(x) (*(((unsigned char *)(&x))+1))

#define USE_SHRINK /* makes my test program smallest */

#if (_Has_hardware_multiply || _Has_large_call_stack) && defined(__OPTIMIZE_SPEED__)
/*
         
|seeeeeee|emmmmmmm|mmmmmmmm|
         1.mmmmmmm mmmmmmmm

a 16-bit multiply can be decomposed into the sum of four 8-bit multiplies
       a  b
*      c  d
-----------
   ac| 0  0
     |bc  0
     |ad  0
+    |   bd (we must not ignore this intermediate product
             because it /can/ affect the high 16 bits of the result)
===========
 */
	f1_as_plier &= 0xFFFFUL; /* required (see comment above) for this method */

        f3_as_product  = ((unsigned int)LOWBYTE(f1_as_plier) * LOWBYTE(f2_as_plicand)) >> 8;
        f3_as_product += (unsigned int)LOWBYTE(f1_as_plier) * HIGHBYTE(f2_as_plicand);
        f3_as_product += (unsigned int)HIGHBYTE(f1_as_plier) * LOWBYTE(f2_as_plicand);
#if defined(USE_MASKS)
        f3_as_product += ((unsigned short long)
			  ((unsigned int)HIGHBYTE(f1_as_plier) * HIGHBYTE(f2_as_plicand)))
		<< 8;
#elif defined(USE_SHRINK)
	*((unsigned int*)(((unsigned char*)&f3_as_product)+1)) +=
		(unsigned int)HIGHBYTE(f1_as_plier) * HIGHBYTE(f2_as_plicand);
#else
#error No method chosen
#endif

/*
assuming normalized mantissa:
smallest ac: 0x80 x 0x80 == 0x4000 .. shift down 7 bits
largest ac:  0xff x 0xff == 0xfe01 .. shift down 8
 */
	/* ensure result is normalized as expected by pack() */
	if (f3_as_product & 0x800000u) {
		f3_as_product >>= 1;
		exp++;
	}
	f3_as_product >>= 1;

#else
	/* f1 & 0x8000 == 0x8000 */
	/* f2 & 0x8000 == 0x8000 */
	cntr = 7;
	do {
		if(f1_as_plier & 1)
			f3_as_product += f2_as_plicand;
		f1_as_plier >>= 1;
		f2_as_plicand <<= 1;
	} while(--cntr != 0);
	/* f1 & 0x100 == 0x100 */
	/* f2 & 0x400000 == 0x400000 */
	cntr = 9;
	do {
		if(f1_as_plier & 1)
			f3_as_product += f2_as_plicand;
		f1_as_plier >>= 1;
		f3_as_product >>= 1;
	} while(--cntr != 0);
	/* f1 == 0 */
	/* f2 & 0x400000 == 0x400000 */
	/* because the last bit of f1 _was_ set,
	   f3 & 0x200000 == 0x200000 and
	   f3 & 0xc00000 == 0 */
#endif
	return __ftpack(f3_as_product, exp, sign);
}
#endif
