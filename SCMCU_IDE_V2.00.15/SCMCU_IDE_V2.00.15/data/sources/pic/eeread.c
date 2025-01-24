#include	<htc.h>

#if	EEPROM_SIZE > 0

unsigned char
eeprom_read(unsigned char addr)
{
	do
		CLRWDT();
	while(WR);
	return EEPROM_READ(addr);
}
#endif
