// 	===============================================================
// 	NVIEW.CPY - Named Views Info Block structure
// 	===============================================================
// 
// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 10-7-96
// 
// 	===============================================================
// 	Named Views Information block header
// 	===============================================================

#ifndef _NVIEW_H_
#define _NVIEW_H_

typedef struct
{
	DWORD ERLen;							// std info block header
	unsigned char EType;			// EType = Info Block
	unsigned char IType;			// IB type = Named Views
	unsigned short Creator;		// XPID (0=core)
	DWORD AllocLen;						// allocation length = ERLen
	unsigned short Flags;			// flags (unused)
	unsigned short nNames;		// current # of named views
	ViewP LastView[0];				// named views start here
}NVIB;

#endif