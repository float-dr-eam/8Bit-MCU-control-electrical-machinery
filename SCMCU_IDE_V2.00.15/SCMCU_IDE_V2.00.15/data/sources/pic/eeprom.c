#include	<htc.h>	

#if 	EEPROM_SIZE > 0

void
eecpymem(volatile unsigned char *to, eeprom unsigned char * from, unsigned char size)
{
	volatile unsigned char *cp = to;
#if _EEPROM_INT == _EEREG_INT
	while (WR) continue;
	EEADR = (unsigned char)from;
	while(size--) {
		while (WR) continue;
		#ifdef	__FLASHTYPE
		EECON1 &= 0x7F;
		#endif
		RD = 1;
		*cp++ = EEDATA;
		++EEADR;
	}
#elif _EEPROM_INT == _NVMREG_INT
	while (NVMCON1bits.WR) {
		continue;
	}
	NVMCON1bits.NVMREGS = 1;
	NVMADRL = (unsigned char) from;
	NVMADRH = 0x70;
	while (size--) {
		NVMCON1bits.RD = 1;
		*cp++ = NVMDATL;
		NVMADRL++;
	}
#else
#error "Unknonwn EEPROM register interface"
#endif
}

void
memcpyee(eeprom unsigned char * to, const unsigned char *from, unsigned char size)
{
	const unsigned char *ptr =from;
#if _EEPROM_INT == _EEREG_INT
	while (WR) continue;
	EEADR = (unsigned char)to - 1;
	#ifdef	__FLASHTYPE
	EECON1 &= 0x7F;
	#endif
	while(size--) {
		while (WR) continue;
		EEDATA = *ptr++;
		++EEADR;
		CARRY = 0; if (GIE) CARRY = 1; GIE = 0;
		WREN = 1;
		EECON2 = 0x55;
		EECON2 = 0xAA;
		WR = 1;
		WREN = 0;
		if (CARRY) GIE = 1;	//an opportunity for interrupts to happen
	}
#elif _EEPROM_INT == _NVMREG_INT
	while (NVMCON1bits.WR) {
		continue;
	}
	NVMCON1bits.NVMREGS = 1;
	NVMADRL = (unsigned char) to - 1;
	NVMADRH = 0x70;
	NVMDATH = 0;
	while (size--) {
		while (NVMCON1bits.WR) {
			continue;
		}
		NVMDATL = *ptr++;
		NVMADRL++;
		STATUSbits.CARRY = 0;
		if (INTCONbits.GIE) {
			STATUSbits.CARRY = 1;
		}
		NVMCON1bits.WREN = 1;
		NVMCON2 = 0x55;
		NVMCON2 = 0xAA;
		NVMCON1bits.WR = 1;
		while (NVMCON1bits.WR) {
			continue;
		}
		NVMCON1bits.WREN = 0;
		if (STATUSbits.CARRY) {
			INTCONbits.GIE = 1;
		}
	}
#else
#error "Unknonwn EEPROM register interface"
#endif
}

unsigned char
__eetoc(eeprom void *addr)
{
	unsigned char data;
	eecpymem((unsigned char *) &data,addr,1);
	return data;
}

unsigned int
__eetoi(eeprom void *addr)
{
	unsigned int data;
	eecpymem((unsigned char *) &data,addr,2);
	return data;
}

unsigned short long
__eetom(eeprom void *addr)
{
	unsigned short long data;
	eecpymem((unsigned char *) &data,addr,3);
	return data;
}

unsigned long
__eetol(eeprom void *addr)
{
	unsigned long data;
	eecpymem((unsigned char *) &data,addr,4);
	return data;
}

unsigned char
__ctoee(eeprom void *addr, unsigned char data)
{
	memcpyee(addr,(unsigned char *) &data,1);
	return data;
}

unsigned int
__itoee(eeprom void *addr, unsigned int data)
{
	memcpyee(addr,(unsigned char *) &data,2);
	return data;
}

unsigned short long 
__mtoee(eeprom void *addr, unsigned short long data)
{
	memcpyee(addr,(unsigned char *) &data,3);
	return data;
}

unsigned long
__ltoee(eeprom void *addr, unsigned long data)
{
	memcpyee(addr,(unsigned char *) &data,4);
	return data;
}

float
__eetoft(eeprom void *addr)
{
	float data;
	eecpymem((unsigned char *) &data,addr,3);
	return data;
}

double
__eetofl(eeprom void *addr)
{
	double data;
	eecpymem((unsigned char *) &data,addr,4);
	return data;
}

float
__fttoee(eeprom void *addr, float data)
{
	memcpyee(addr,(unsigned char *) &data,3);
	return data;
}

double
__fltoee(eeprom void *addr, double data)
{
	memcpyee(addr,(unsigned char *) &data,4);
	return data;
}
#endif
