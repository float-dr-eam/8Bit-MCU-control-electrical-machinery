#include <stddef.h>

/* IAR Support Functions */

void * 		
__section_begin(const char * s) 
{
	volatile void * v = s;
	v = NULL;
	return v;
}

void * 		
__section_end(const char * s) 
{
	volatile void * v = s;
	v = NULL;
	return v;
}

size_t *	
__section_size(const char * s)
{
	volatile void * v = s;
	v = NULL;
	return v;
}

void * 		
__segment_begin(const char * s) 
{
	volatile void * v = s;
	v = NULL;
	return v;
}

void * 		
__segment_end(const char * s) 
{
	volatile void * v = s;
	v = NULL;
	return v;
}

size_t *	
__segment_size(const char * s)
{
	volatile void * v = s;
	v = NULL;
	return v;
}

void * 	
__sfb(const char * s) 
{
	volatile void * v = s;
	v = NULL;
	return v;
}

void * 		
__sfe(const char * s) 
{
	volatile void * v = s;
	v = NULL;
	return v;
}

size_t *	
__sfs(const char * s)
{
	volatile void * v = s;
	v = NULL;
	return v;
}

typedef unsigned char __istate_t;

__istate_t	
__get_interrupt_state(void)
{
	return 0;
}

void		
__set_interrupt_state(__istate_t i)
{
	volatile __istate_t j = i;
}
