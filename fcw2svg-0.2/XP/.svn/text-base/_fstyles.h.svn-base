// 	===============================================================
// 	FSTYLES.CPY - Fill Style Structures
// 	===============================================================

// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 12-1-96

// 	===============================================================
// 	FSTYIB: Fill Styles Information block header
// 	===============================================================

// 	CurHdr.FStyle = the currently selected style ID
// 	It determines the currently selected fill style

#ifndef _FSTYLES_H_
#define _FSTYLES_H_

#define CurFSTYIBVer	2			// current version #
														// 1=old BMPSTY data - no xdata, FS_CENTER


// 	===============================================================
// 	Individual FSTY style definitions
// 	===============================================================

#define FS_PAT			0			// brush pattern style
#define FS_HATCH		1			// metric hatch style
#define FS_BMP			2			// bitmap file style
#define FS_SYM			3			// symbol fill style

typedef struct
{
	DWORD	RLen;							// style record length in bytes
	char	fstype;						// style type id (FS_XXXX)
	char	dofst;						// # bytes from rlen to data start
	WORD	ID;								// fill style id (magic cookie)
	char	flags;						// options flags
	char	fsname[10];					 	// ANSIZ fill style name
}FSTY;

// 	Values for FSTY.flags:

#define FS_OUTL				 1	// outline the filled shape
// #define FS_TRANS		0x80	// transparent color specified

// 	---------------------------------------------------------------
// 	Pattern styles have an 8 byte bitmap following the FSTY header
// 	---------------------------------------------------------------

/*
PatSty		macro	id,nm
		local	epat,spat
spat		dword	(epat-spat)+8
		sbyte	FS_PAT
		sbyte	(epat-spat)
		word	id
		sbyte	FS_OUTL
		sbyte	nm
		sbyte	0
epat		label	byte
		endm
*/

// 	---------------------------------------------------------------
// 	Hatch Styles have 4*SIZEOF(HATCH) hatch data following the header
// 	---------------------------------------------------------------

typedef struct
{
	WORD	lsty;				// 0 = solid line
	float	siz;				// 0.0 = this set not drawn
	float	ang;				// line bearing angle
	float	xofst;			// offset to start of line draw
	float	yofst;			// (only affects styled lines)
}HATCH;

#define NrHatch		4

/*
HatchSty	macro	id,nm
		local	epat,spat
spat		dword	(epat-spat)+(NrHatch*SIZEOF(HATCH))
		sbyte	FS_HATCH
		sbyte	(epat-spat)
		word	id
		sbyte	FS_OUTL
		sbyte	nm
		sbyte	0
epat		label	byte
		endm
*/

// 	---------------------------------------------------------------
// 	Bitmap styles: data
// 	---------------------------------------------------------------

typedef struct
{
	BYTE	fit;					// fit code      = 	FS_EXPFILL
	BYTE	tcode;				// transparency code
	BYTE	flags;				// options
	BYTE	rsvdf;				// unused flags = 0
	float rwidth;				// real units width
	float rheight;			// real units height
	float rang;					// bitmap rotation (radians)
	DWORD tcolor;				// transparent color 0x00BBGGRR
	DWORD rsvd;					// unused = 0
	char	bmpname[1];		// bmp file name (ANSIZ)
}BMPSTY;


/*
BmpSty		macro	id,nm,fit,fn
		local	epat,spat,fpat
spat		dword	(fpat-spat)
		sbyte	FS_BMP
		sbyte	(epat-spat)
		word	id
		sbyte	FS_OUTL
		sbyte	nm
		sbyte	0
epat		label	byte
		db	fit
		db	0,0,0
		real4	1.0,1.0,0.0
		dword	00000000h
		dword	0
		sbyte	fn
		sbyte	0
fpat		label	byte
		endm
*/

// 	Bitmap fit code values

#define FS_TILE				1
#define FS_EXPFILL		2
#define FS_EXPFIT			3
#define FS_COPY				4

#define FS_CENTER			5		// CurFSTYIBVer=1 didn't support
#define FS_COVER			6		// CurFSTYIBVer=1 didn't support

// 	BMPSTY.tcode values	// CurFSTYIBVer=1 didn't support

#define FSB_OPAQUE			0		// no transparency
#define FSB_ULTCOLOR 	1		// upper-left pixel is transparent color
#define FSB_TCOLOR			2		// BMPSTY.tcolor is transparent color
#define FSB_ALPHA			3		// file is 32-bit 0xAABBGGRR pixels

// 	BMPSTY.flags values	// CurFSTYIBVer=1 didn't support

#define FSB_SCALE			1		// rwidth,rheight scale is valid
#define FSB_ROT				2		// rang is valid - rotate bitmap

// 	---------------------------------------------------------------
// 	Symbol Styles
// 	---------------------------------------------------------------

typedef struct
{
	float	xstep;					// repeat stepping distance
	float	ystep;
	float	xscale;					// individual copy tforms
	float	yscale;
	float	xyrot;
	char	symname[1];			// bmp file name (ANSIZ)
}SYMSTY;

/*
SymSty		macro	id,nm,fit,fn
		local	epat,spat,fpat
spat		dword	(fpat-spat)
		sbyte	FS_SYM
		sbyte	(epat-spat)
		word	id
		sbyte	FS_OUTL
		sbyte	nm
		sbyte	0
epat		label	byte
		real4	1.0
		real4	1.0
		real4	1.0
		real4	1.0
		real4	0.0
		sbyte	fn
		sbyte	0
fpat		label	byte
		endm
*/



typedef struct
{
	DWORD	ERLen;							// std info block header    		= SIZEOF(FSTYIB)
	char	EType;							// EType = Info Block     			= ET_IB
	char	IType;							// IB type = Fill Styles    		=	IB_FSTYLE
	WORD	Creator;						// XPID (0=core)
	DWORD	AllocLen;						// allocation length (0=ERLen)

	WORD	IBVer;							// FSTYIB version id  					= CurFSTYIBVer
	WORD	NextID;							// next ID to use     					=	256


	FSTY  FS[1];							// fill style instance data starts here
														// A record length of 0 ends the list
}FSTYIB;


#endif
