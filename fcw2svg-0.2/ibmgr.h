// 	===============================================================
// 	IBMGR.CPY - Information Block Structures
// 	===============================================================
// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Susan Montooth 2/96

// 	Automatically included with global.cpy

// 	Information blocks store drawing-specific settings.
// 	They are stored with the drawing on disk, but separately
// 	in memory (each in its own global memory block).

#ifndef _IBMGR_H_
#define _IBMGR_H_

// 	===============================================================
// 	Header Structure for all information blocks
// 	===============================================================

#define ET_IB			0

typedef struct
{
	int  ERLen;			// actual length (bytes in use)     = 	sizeof(IBHDR)
	char EType;			// entity type code (always 0) 	   	=  	ET_IB
	char IType;			// info block type
									// 80h=no writeback (dflt unchgd)
	short Creator;	// XPID (0=core)
	int AllocLen;		// allocation length                =   sizeof(IBHDR)
									// (0=use ERLen for allocation)
}IBHDR;

// 	===============================================================
// 	info block types in use by core
// 	===============================================================

#define IB_DFLT			0x080		// no writeback flag

#define IB_HDR			0x00		// defined in header.cpy
#define IB_STYLE		0x01		// styles.cpy (deleted)
#define IB_SVIEW		0x02		// svib.cpy
#define IB_LAYER		0x03		// layers.cpy
#define IB_GRID			0x04		// grids.cpy
#define IB_PRINT		0x05		// print.cpy (printer settings)

#define IB_LSTYLE		0x06		// lstyles.cpy
#define IB_FSTYLE		0x07		// fstyles.cpy
#define IB_NVIEW		0x08		// nviews.cpy
#define IB_LWCMAP		0x09		// color map data

#define IB_DSTYLE		0x10		// dstyles.cpy
#define IB_FONT			0x11		// fonts.cpy

#define IB_Max			0x12		// maximum # of IBlks

// 	===============================================================
// 	IBlkSVC Function Codes (in EBX)
// 	===============================================================

#define IBS_REORG			0			// change dwg origin
										 				//  ESI-> X,Y,Z GPnt3 struc
#define IBS_UNITSCHG	1			// change dwg UNITS
										 				//  ESI-> REAL4 Scale Difference
#define IBS_INIT			2			// init IBlk on dwg load
#define IBS_SELCUR		3			// select new current IBAdr
#define IBS_UPDSAVE		4			// prep for dwg save

#endif