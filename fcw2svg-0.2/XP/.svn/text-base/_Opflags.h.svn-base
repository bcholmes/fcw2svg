// 	===============================================================
// 	OPFLAGS.H - Options & Drawing Operations Flags
// 	===============================================================

// 	Copyright 1997 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 7-4-97

#ifndef _OPFLAGS_H_
#define _OPFLAGS_H_

int *_stdcall GetOptionsAdr(void);
int *_stdcall GetPrBitScaleAdr(void);


// 	-----------------------------------------------------------------
// 	Values for Options (part of desktop structure in FCW32):
// 	-----------------------------------------------------------------
// 	The standard default options bits are 0FFFF0000h

#define OPT_ToolTips	0x080000000	// tooltips enabled
#define OPT_PartGroup	0x040000000	// parts are grouped
#define OPT_MaxCovers	0x020000000	// maximized windows covers others
#define OPT_EMF				0x000000001	// ok to write EMF to clipboard
#define OPT_TextCsr		0x010000000	// use text dyncsr not box
#define OPT_DynPan		0x008000000	// enable DynPan/DynScroll
#define OPT_NECaps		0x000000002	// suppress endcaps on LS Wide Lines
#define OPT_LocalNC		0x000000004	// force local enum of # copies
#define OPT_BkgndPal	0x004000000	// 0=no repaint on other app pal chg
#define OPT_ESCCloseT	0x002000000	// 1=enable ESC to close text windows
#define OPT_ICO24			0x000000008	// 1=use 24x24 icons, else 16x16
#define OPT_PrintBit  0x001000000

// 	-----------------------------------------------------------------
// 	Values for LWFlags (part of desktop structure in FCW32):
// 	-----------------------------------------------------------------

#define LWF_NoDisp		 1		// ignore width for display
#define LWF_NoPrn			 2		// ignore width for printing
#define LWF_CMap			 4		// width mapped from color
#define LWF_AllBlk		 8		// print is actually plotting
#define LWF_PaperScl	16		// widths are paper scale
#define LWF_UseWPen		32		// use windows pens for solid lines
#define LWF_Inches		64		// pen width units in cmap:
								 						// 0 = millimeters
 														// 1 = inches

// 	-----------------------------------------------------------------
// 	Values for DrawFlags - Valid after call to Header::UseCStuff
// 	-----------------------------------------------------------------
// 	These are used to make quick decisions in geometry drawing logic:
// 
// 		mov	eax,DrawFlags
// 		and	eax,NOT (QWID+QNLS+QNCSR)
// 		jz	DrawSingleFilled
// 
// 		test	DrawFlags,QNWID+QCSR+QNFIL
// 		jnz	DrawThinUnfilled
// 
// 	See the macros defined below.
// 	-----------------------------------------------------------------

#define QWS								1		// line width is specified
#define QNWS			 0x010000		// not QWS
#define QWID							2		// line width spec and not ignored
#define QNWID			 0x020000		// not QWID
#define QFIL							4		// fill style not hollow
#define QNFIL			 0x040000		// not QFIL
#define QFOL			 				8		// fill style is outlined
#define QNFOL			 0x080000		// not QFOL
#define QLS						0x010		// non-solid line style
#define QNLS			0x0100000		// not QLS
#define QPRN					0x020		// printing or print preview
#define QNPRN			0x0200000		// not QPRN
#define QCSR					0x040		// drawing cursor
#define QNCSR			0x0400000		// not QCSR
#define QPVW		      0x080		// drawing a print preview
#define QNPVW		  0x0800000		// not QPVW
#define QFLS		     0x0100		// is solid filled
#define QNFLS		 0x01000000		// not QFLS
#define QSYMF		     0x0200		// now doing symbol fill
#define QNSYMF	 0x02000000		// not QSYMF
#define QHATCH	     0x0400		// now doing hatch fill
#define QNHATCH	 0x04000000		// not QNHATCH
#define QNECAP	0x040000000		// no endcaps on wide lines
#define QNPW		0x080000000		// inhibit GDI pen width flag


// 	----------------------------------------------------------
// 	Clipboard options format
// 	----------------------------------------------------------

typedef struct
{
	DWORD	CBInfo;				// length of clipboard reg data
	DWORD	CBBitmapR;		// bitmap rectangle
	DWORD CBBitmapR1;
	DWORD	CBBitmapX;		// clipboard bitmap horizontal size
	DWORD	CBBitmapY;		// clipboard bitmap vertical size
	float	CBMFSizeX;		// clipboard metafile max X dim
	float	CBMFSizeY;		// clipboard metafile max Y dim
	DWORD	CBMFUnits;		// clipboard units: 0 = in, 1 = cm
	DWORD	CBBkgnd;			// 1 = paint background color
	DWORD	CBBits;				// 1 = 24 bits, 0=8 bits
}CBDATA;

// 	----------------------------------------------------------
// 	GetSysVAdr - Get system variable address
// 	----------------------------------------------------------

void *_stdcall GetSysVAdr(DWORD n);

#define SV_ADWIN			0
#define SV_OPTIONS		1
#define SV_LWFLAGS		2
#define SV_CBINFO			3
#define SV_LBACT	    4
#define SV_SELMENUS	  5
#define SV_CANPRESEL	6
#define SV_SAVEMODE	  7
#define SV_NOREDRAW   8
#define SV_NOPACK     9

#endif