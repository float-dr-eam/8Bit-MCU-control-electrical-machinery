/* Floating point format and common support definition */
#include <stdint.h>

/* SP only */

/* Single precision format parameters */
#define SPSGNM ((int32_t)1 << 31)		/* Sign bit mask */
#define SPEXPM (((int16_t)1 << 8) - 1)		/* Exponent mask */
#define SPFRCB 23				/* # fraction bits */
#define SPFRCM (((int32_t)1 << SPFRCB) - 1)	/* Fraction mask */

/* Right declaration of SP 32-bit FP for different compilers */
#ifdef __XC8__
#define SP double
#else
#define SP float
#endif

/* IEEE format container */
typedef union {
	int32_t i;
	SP f;
	struct {
		unsigned char a, b, c, d;
	} fAsBytes;
	struct {
		int16_t wordA, wordB;
	} fAsWords;
} SFP;

typedef union {
        int16_t i;
	uint16_t n;
	struct {
		unsigned char a, b;
	} nAsBytes;
} wordProduct;

/* Library routines */
#ifdef __XC8__
#define SPADD __fladd
#define SPSUB __flsub
#define SPMUL __flmul
#define SPDIV __fldiv
#define SPSQRT sqrt
#define SPCMP spcmp
#define SPEQ __fleq
#define SPNE __flne
#define SPGT __flgt
#define SPGE __flge
#define SPLT __fllt
#define SPLE __flle
#endif
#ifdef __XC16__
#define SPADD __addsf3
#define SPSUB __subsf3
#define SPMUL __mulsf3
#define SPDIV __divsf3
#define SPCMP spcmp
#define SPSQRT sqrtf
#define SPEQ __eqsf2
#define SPNE __nesf2
#define SPGT __gtsf2
#define SPGE __gesf2
#define SPLT __ltsf2
#define SPLE __lesf2
#endif
#ifdef __XC32__
#define SPADD fpadd
#define SPSUB fpsub
#define SPMUL fpmul
#define SPDIV fpdiv
#define SPCMP fpcmp
#define SPSQRT fpsqrt
#endif

extern SP SPADD(SP x, SP y);
extern SP SPSUB(SP x, SP y);
extern SP SPMUL(SP x, SP y);
extern SP SPDIV(SP x, SP y);
extern int SPCMP(SP x, SP y);
extern SP SPSQRT(SP x);

extern unsigned int _Umul8_16(unsigned char multiplier, unsigned char multiplicand);
