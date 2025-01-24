/*
 * 	Definitions for the HI-TECH USB library
 *
 * 	Copyright (C) 2005 HI-TECH Software Pty. Ltd.
 */

//	USB protocol definitions

#define	GET_STATUS		0x00
#define	CLEAR_FEATURE	0x01
#define	SET_FEATURE		0x03
#define	SET_ADDRESS		0x05
#define	GET_DESCRIPTOR	0x06
#define	SET_DESCRIPTOR	0x07
#define	GET_CONFIG		0x08
#define	SET_CONFIG		0x09
#define	GET_INTERFACE	0x0A
#define	SET_INTERFACE	0x0B
#define	SYNCH_FRAME		0x0C

// Class-specific requests

#define	BOMS_RESET		0xFF		// bulk-only mass storage reset
#define	BOMS_GETMAXLUN	0xFE		// bulk-only get max lun

// Control packet offsets

#define	REQ_TYPE		0x00		// request type bits
#define	REQ_REQ			0x01		// request itself
#define	REQ_VALUE		0x02		// data value
#define	REQ_INDEX		0x04		// data value
#define	REQ_LENGTH		0x06		// data length

#define	REQ_SIZE		0x08		// size of a control request

// descriptor types

#define	DESC_DEVICE		0x01
#define	DESC_CONFIG		0x02
#define	DESC_STRING		0x03
#define	DESC_INTERFACE	0x04
#define	DESC_ENDPOINT	0x05
#define	DESC_DEVQUAL	0x06
#define	DESC_OTHERSPD	0x07
#define	DESC_INTPWR		0x08

#define	DESC_DFU		0x21		// DFU functional descriptor

//	Sizes of various descriptors

#define	DEVICE_SIZE			18
#define	ENDPOINT_SIZE		7
#define	INTERFACE_SIZE		9
#define	CONFIGURATION_SIZE	9

// offsets of things in descriptors

#define	bNumEndpoints		4		// number of endpoints in an interface
#define	bNumInterfaces		4		// number of interfaces in a configuration
#define	bEndpointAddress	2		// endpoint address
#define	bmAttributes		3		// endpoint attributes
#define	wMaxPacketSize		4		// endpoint max packet size

#ifdef	i8051
#define	__XDATA	xdata
#else
#define	__XDATA
#endif

// USB endpoint status
// These flags are set for each endpoint by interrupt routines.
// Mainline code need only test these flags to know what to do next.

#define	NUM_ENDPOINTS	4
extern unsigned char __XDATA	USB_status[NUM_ENDPOINTS];

// status bits
#define	RX_READY	0x01		// data available in the FIFO for this endpoint
#define	TX_BUSY		0x02		// output FIFO is full

// bits in endpoint 0 status
#define	USB_RESET	0x04		// USB reset detected
#define	USB_SUSPEND	0x08		// USB suspend detected
#define	PROT_RESET	0x80		// protocol reset bit (e.g. USB mass storage)

// bits in other endpoints

#define	EP_IN		0x04		// used as an input
#define	EP_OUT		0x08		// used as an output
#define	EP_HALT		0x10		// endpoint is halted

#ifndef USB_CONST
#ifdef	HI_TECH_C
#define	USB_CONST	const
#else
#define	USB_CONST	code
#endif
#endif


typedef struct
{
	unsigned char USB_CONST *				device,
							* USB_CONST *	configurations,
							* USB_CONST *	strings;
	unsigned short USB_CONST*				conf_sizes;
	unsigned char							conf_cnt, string_cnt;
}	USB_descriptor_table;
//	User-callable routines.

// initialize the usb interface using the provided descriptor table

extern reentrant void USB_init(USB_descriptor_table USB_CONST * table);

// detach from the USB bus. Must call USB_init again before can use the USB
extern reentrant void USB_detach(void);

// handle endpoint 0

extern reentrant void USB_control(void);

// read a block of data from the specified endpoint
extern reentrant unsigned short USB_read_packet(unsigned char index, unsigned char __XDATA * ptr, unsigned short cnt);

// write a block of data to the specified endpoint.

// stall an endpoint - flag is true for input endpoints

extern reentrant void USB_flushout(unsigned char index);
extern reentrant void USB_flushin(unsigned char index, unsigned char force);
extern reentrant void USB_send_byte(unsigned char index, unsigned char byte);
extern reentrant unsigned char USB_read_byte(unsigned char index);
extern reentrant void USB_halt(unsigned char idx);
