// 	===============================================================
// 	LSTYLES.CPY - Line Style Structures
// 	===============================================================

// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 4-23-96

// 	===============================================================
// 	LS: struc to define one line style
// 	===============================================================

#ifndef _LSTYLES_H_
#define _LSTYLES_H_

// 	flags bit values:

#define LS_S1V			1		// segment 1 draws
												// code depends on LS_S1V being 1
#define LS_ENDS			4		// scale to fit ends
#define LS_PAPER		8		// paper scale (else dwg units)

typedef struct
{
	DWORD	RLen;				// size of structure       = 	sizeof(LS)
	WORD  ID;					// LSTY id #
	float SWid;	 			// (style line width - obsolete)
	float SLen;				// style real length
	WORD  NSegs;			// current # style segments     = 	1
	WORD  flags;			// options bits       = 	LS_S1V+LS_ENDS+LS_PAPER
	char  lsname[32];	// lstyle name
}LS;

#define LS_S			sizeof(LS)	// overhead size in bytes

// 	The LS structure is immediately followed by a list of real4
// 	segment lengths (units are fraction of 1.0 = SLen T parameters)

// 	===============================================================
// 	LSTYIB: Line Styles Information block header
// 	===============================================================

// 	CurHdr.LStyle = the currently selected style ID
// 	It determines the currently selected line style

#define CurLSTYIBVer	1		// current version #

typedef struct
{
	DWORD	ERLen;				// std info block header          = SIZEOF (LSTYIB)
	char  EType;				// EType = Info Block             = ET_IB
	char 	IType;				// IB type = Line Styles          = IB_LSTYLE
	WORD	Creator;			// XPID (0=core)
	DWORD  AllocLen;			// allocation length (0=ERLen)

	WORD	IBVer;				// LSTYIB version id             	=	CurLSTYIBVer
	WORD	NextID;				// next ID to use                	= 256

	WORD	NrLStyles;		// current # defined styles    		= 6

	LS    LS[1];			// 																=	<LS_S,0,,,0,,"Solid">
	DWORD	endmark;   		// 																= 0
}LSTYIB;


#endif _LSTYLES_H_
