// 	===============================================================
// 	PRINT.CPY - Print Infoblock structure
// 	===============================================================
// 
// 	Copyright 1997-1999 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 1-13-97
// 	Added tiling/sheets data, CurPRIBVer 2 1-4-99
// 

#ifndef _PRINT_H_
#define _PRINT_H_

#define CurPRIBVer		3		// current version

typedef struct
{

	int   ERLen;			// std info block header =SIZEOF(PRIB)
	char  EType;	  	// EType = Info Block  	= ET_IB
	char  IType;			// IB type = Print Settings   = ID_PRINT
	short Creator;		// XPID (0=core)
	int   AllocLen;	 	// allocation length (0=ERLen)
	short IBVer;			// PRINT version id

	DWORD	dmFields;					// order,size same as DEVMODE
	WORD	dmOrientation;		// single partial block of data
	WORD	dmPaperSize;
	WORD	dmPaperLength;
	WORD	dmPaperWidth;
	WORD	dmScale;
	WORD	dmCopies;
	WORD	dmDefaultSource;
	WORD	dmPrintQuality;
	WORD	dmColor;
	WORD	dmDuplex;
	WORD	dmYResolution;
	WORD	dmTTOption;

	DWORD	OurPrData;				// our pgm data   =EndOurPrData-OurPrData
	DWORD	ViewRB;						// 0 named 1 all 2 current
	DWORD	ScaleRB;					// 0 scale 1 fit
	float	PDist;						// paperdist
	float	DDist;						// drawing distance
	DWORD	PrSwapColor;			// color swap mode for printing
	char	valid;						// valid data flag
	char	szCurName[46];		// current view name
	char	unused;						// unused - align
 
	DWORD	TileNX;						// # horizontal tiles
	DWORD	TileNY;						// # vertical tiles
	DWORD	TileOvl;					// tile overlap, % (0..100)
	DWORD	SheetN;						// Sheet Select
	DWORD	SheetF;						// 1=common prints on all sheets
	DWORD	PBkgnd;						// 1 = print background
	DWORD	Reserved[9];			// reserved
	unsigned char	EndOurPrData;			// end marker  = 0FEh
}PRIB;

// 		DEVMODE data block copy size in bytes
// 		PRINT.ASM::GetPrintIB depends on this

//#define PRIBcsz		PRIB.OurPrData-PRIB.dmFields

#define DEVMcnt		12			// # words to set in DEVMODE
 													// from the PRIB
 													// dmOrientation..dmTTOption
 													// must get to OurPrData
 													// PRINT.ASM::UpdPrintIB
 													// depends on this.

#endif