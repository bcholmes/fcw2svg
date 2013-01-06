//////// _SVIB.H - Screen Views Info Block structure - FastCAD-32 XP include file /////////
//
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _SVIB_H_
#define _SVIB_H_

#include <_DWIN.H>

// 	===============================================================
// 	Screen set structure (one instance of screen layout)
// 	===============================================================

typedef struct
{
	int  	RLen;				// current size of this screen set  = SIZEOF(SSet)
	char 	SName[32];	// name of screen set
	short	NrWin;			// # of DWINs in this set     1
	short	AwNr;				// active window # 0..NrWin-1
	ViewP	SView;			// DWIN view parms for win #0
}SSet;

// 	===============================================================
// 	Screen Views Information block header
// 	===============================================================

typedef struct
{
	int		ERLen;			// std info block header     = SIZEOF (SVIB)
	char	EType;			// EType = Info Block        = ET_IB
	char  IType;			// IB type = Screen Views  	 = IB_SVIEW
	short Creator;		// XPID (0=core)
	int 	AllocLen;		// allocation length         = sizeof(SVIB)
	short	flags;			// flags (unused)
	short nsets;			// current # of screen sets
	short cset;				// current selected screen set #
  SSet  stdset[1];  // standard screen set
                    // additional SSets follow
}SVIB;


#endif
