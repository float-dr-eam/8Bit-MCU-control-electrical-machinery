#include <stdlib.h>

#ifndef _ABORT_MACRO_
void
abort(void) {
	exit(-1);
}
#endif

