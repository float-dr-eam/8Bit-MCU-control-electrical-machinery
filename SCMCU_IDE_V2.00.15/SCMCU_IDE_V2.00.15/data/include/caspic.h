#ifndef _CASPIC_H_
#define	_CASPIC_H_

#ifndef BANKMASK
#if defined(_PIC14) || defined(_PIC14E)
#define BANKMASK(addr)	((addr)&07fh)
#else
#define BANKMASK(addr)	((addr)&01fh)
#endif
#endif

#include <pic_cas_chip_select.h>

#endif
