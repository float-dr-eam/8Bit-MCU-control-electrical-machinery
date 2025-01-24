// 8 x 8 bit multiplication with 16 bit result
#include <stdint.h>
uint16_t
_Umul8_16(unsigned char multiplier, unsigned char multiplicand) {
	uint16_t product = 0;
	uint16_t word_mpld = (uint16_t) multiplicand;

#if defined(__OPTIMIZE_SPEED__)

	if (multiplier & 0x01) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x02) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x04) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x08) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x10) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x20) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x40) {
		product += word_mpld;
	}
	word_mpld <<= 1;

	if (multiplier & 0x80) {
		product += word_mpld;
	}

#else
	do {
		if (multiplier & 1) {
			product += word_mpld;
		}
		word_mpld <<= 1;
		multiplier >>= 1;
	} while (multiplier != 0);

#endif
	return product;
}
