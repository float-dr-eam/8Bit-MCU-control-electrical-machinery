#include	<htc.h>

#if	EEPROM_SIZE > 0

void
eeprom_write(unsigned char addr, unsigned char value)
{
	EEPROM_WRITE(addr, value);
}
#endif

