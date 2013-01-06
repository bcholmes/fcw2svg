// 	===============================================================
// 	LWCMAP.CPY - Line Width -> Color Mapping InfoBlock Structure
// 	===============================================================
// 	Copyright 1999 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 4-30-99
// 	===============================================================

#ifndef _LWCMAP_H_
#define _LWCMAP_H_

#define CurCMapVer	1		// current version #

typedef struct
{
	int   ERLen;				// std info block header =SIZEOF(CMAPIB)
	char  EType;	  		// EType = Info Block  	= ET_IB
	char  IType;				// IB type = Layers = IB_LWCMAP
	short Creator;			// XPID (0=core)
	int   AllocLen;	 		// allocation length (0=ERLen)
	WORD  IBVer;				// LyrIB version id  = CurCMapVer

	float WData[256];		// color map data
	WORD  Flags;				// LWFlags copy
	BYTE  PBlack[256];	// print black flags
}CMAPIB;

#endif