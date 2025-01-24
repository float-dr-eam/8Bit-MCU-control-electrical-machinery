/* These sample routines are used to write to the flash memory on those
 * midrange PIC devices, which update their flash memory in 4 word 
 * and 32 word blocks.
 * These devices include the PIC16F87xA, and the PIC16F81x family.
 */

#include <htc.h>

#if _EEPROM_INT != _NVMREG_INT

#define _FWMASK (_FLASH_WRITE_SIZE - 1)
#define MEMORY_TYPE (((unsigned short)source_addr>>8)&0x80)
#define ROM 0

void requiredSequence(void){
	CARRY=0;if(GIE)CARRY=1;GIE=0;
	WREN=1;
	EECON2=0x55;
	EECON2=0xAA;
	WR=1;
	NOP();
	NOP();
	WREN=0;
	if(CARRY)GIE=1;
}

#if	(_FLASH_WRITE_SIZE == _FLASH_ERASE_SIZE) && (__FLASHTYPE == 1 || __FLASHTYPE == 2)

/* The flash_copy routine is useful when transferring larger volumes of data to a section of
 * flash memory. Lengths of up to 255 words may be copied at a time. */
void flash_copy(const unsigned short * source_addr,unsigned char length,unsigned short dest_addr)
{
	// variable declarations
	unsigned char index;
	unsigned char offset;

#if _FLASH_WRITE_SIZE > 1
	offset=(unsigned char)((unsigned char)dest_addr & _FWMASK);	// find the index into the flash sector
	dest_addr&= ~_FWMASK;	// initialise the dest_addr to point to the first address in the erasure block
#endif

#if _EEPROMSIZE > 0	
	while(WR);	// in case of any prior EEPROM writes
	EEPGD=1;	// select program memory
#endif

	while(length)	// while there are still words left to copy...
	{
#if _FLASH_WRITE_SIZE > 1
		// now begin to copy the buffer to the destination area
		for(index=0;index<_FLASH_ERASE_SIZE;index++)	// for every word in the 4 word block...
		{
			if((index>=offset)&&(length))	// if this word is to be written with new data...
			{
#endif
				EEDATA=*(source_addr++);	// else copy the word from RAM
				if (sizeof(*source_addr) <= sizeof(unsigned char))
					EEDATH=0x00;
				else
					EEDATH=*(source_addr++);
				length--;
#if _FLASH_WRITE_SIZE > 1
			} else {
				_EEADRL=(unsigned char)(dest_addr&0xff);	// load current word from destination
				EEADRH=(unsigned char)((dest_addr>>8)&0xff);
				RD=1;
				asm("nop");
				asm("nop");
			}
#endif
			_EEADRL=(unsigned char)(dest_addr&0xff);	// write the data word to the destination address
			EEADRH=(unsigned char)((dest_addr>>8)&0xff);
			requiredSequence();
			dest_addr++;
#if _FLASH_WRITE_SIZE > 1
		}
		offset=0;
#endif
	}
}


#else	// variant where WRITE and ERASE sizes differ

void flash_copy(const unsigned short * source_addr, unsigned char length, unsigned short dest_addr)
{
	// variable declarations
	unsigned char index;
	unsigned char offset;
	int	sectorindex, datalength;
	static bank1 unsigned short BUFFER[_FLASH_ERASE_SIZE];

	datalength =length;
	offset=(unsigned char)((unsigned char)dest_addr & _FWMASK);	// find the index into the flash sector
	dest_addr &= ~_FWMASK;	// initialise the dest_addr to point to the first address in the 4 word block
	
#if _EEPROMSIZE > 0	
	while(WR);	// in case of any prior EEPROM writes
	EEPGD=1;	// select program memory
#endif

#if defined(_PIC14E)
	CFGS=0;
	LWLO=1;
#endif

	for(sectorindex = 0; sectorindex < datalength; sectorindex += _FLASH_ERASE_SIZE){
					
		// fill the _FLASH_ERASE_SIZE byte data buffer either from ...
		for(index = 0; index < _FLASH_ERASE_SIZE;index++)
		{
			if( ( (index + sectorindex) >= offset) && (length) )	// specifed data area or ...
			{
				BUFFER[index]=*(source_addr++);
				length--;
			}
			else
			{					
				// otherwise from destination sector.						
				FLASH_READ(dest_addr+index+sectorindex);	
				BUFFER[index]=((EEDATH << 8) | EEDATA);	
			}				
		}
	
		// Erase flash sector before writing _FLASH_ERASE_SIZE words at a time
		// NOTE: The following code will erase a block of _FLASH_ERASE_SIZE words
		_EEADRL = (unsigned char)(dest_addr+sectorindex);			// LS Byte of Program Address to Erase
		EEADRH = (unsigned char)((dest_addr+sectorindex)>>8);		// MS Byte of Program Address to Erase
			
#if	__FLASHTYPE == 3
		// Start row erase
		FREE = 1;				// Enable Row Erase operation	
		requiredSequence();	// Order row erasure
		FREE = 0;				// Enable Row Erase operation	
#endif
	
		// now begin to copy the buffer to the destination area
		for(index = 0; index < _FLASH_ERASE_SIZE; index ++)
		{
			EEDATA=BUFFER[index] ;
			EEDATH=BUFFER[index] >> 8;
			
			_EEADRL=(unsigned char)((dest_addr+index+sectorindex)&0xff);	// write the data word to the destination address
			EEADRH=(unsigned char)(((dest_addr+index+sectorindex)>>8)&0xff);

#if defined(_PIC14E)
	 		if (index == _FLASH_ERASE_SIZE-1)
    			LWLO=0;
#endif
			
			requiredSequence();	
		}
	}
	return;
}

#endif
#endif // _EEPROM_INT != _NVMREG_INT
