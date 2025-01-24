/* Errata symbols and codes that may
 * be present in preprocessor
 * symbol _ERRATA_TYPES.
 */

#ifndef _ERRATA_H_
#define _ERRATA_H_

#define	ERRATA_4000	(1<<0)	// Program mem accesses/jumps across 4000h address boundary
#define	ERRATA_FASTINTS (1<<1)	// Fast interrupt shadow registers corruption
#define	ERRATA_LFSR	(1<<2)	// Broken LFSR instruction
#define	ERRATA_MINUS40	(1<<3)	// Program memory reads at -40 degrees
#define	ERRATA_RESET	(1<<4)	// GOTO instruction cannot exist at reset vector
#define	ERRATA_BSR15	(1<<5)	// Flag problems when BSR holds value 15
#define	ERRATA_DAW	(1<<6)	// Broken DAW instruction
#define	ERRATA_EEDATARD	(1<<7)	// Read EEDAT in immeadiate instruction after RD set
#define	ERRATA_EEADR	(1<<8)	// Don't set RD bit immediately after loading EEADR
#define	ERRATA_EE_LVD	(1<<9)	// LVD must stabilise before writing EEPROM
#define	ERRATA_FL_LVD	(1<<10)	// LVD must stabilise before writing Flash
#define	ERRATA_TBLWTINT	(1<<11)	// Clear interrupt registers before tblwt instruction
#define	ERRATA_FW4000	(1<<12)	// Flash write exe must act on opposite side of 4000h boundary.
#define	ERRATA_RESETRAM	(1<<13)	// RAM contents can corrupt if async. reset occur during write access.
#define	ERRATA_FETCH	(1<<14)	// Corruptable instruction fetch. Apply FFFFh at required locations.

#endif
