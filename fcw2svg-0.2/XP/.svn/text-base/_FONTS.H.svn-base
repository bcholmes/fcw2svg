// 	===============================================================
// 	FONTS.CPY - Font Data Structures
// 	===============================================================

// 	Copyright 1994-1998 Evolution Computing
// 	All rights reserved

// 	===============================================================
// 	Old Font InfoBlock Structure
// 	===============================================================

#ifndef _FONTS_H_
#define _FONTS_H_

// 		Font table entry

typedef struct
{
	WORD	ID;
	char  CharSet;	             		// ANSI_CHARSET etc.
	char  PitchAndFamily;           // e.g. FF_SWISS or VARIABLE_PITCH
	DWORD	Hght;              				// sample height
	DWORD	Descent;              		// sample descent
	DWORD	InternalLeading;          // sample internal leading
	DWORD	Wdth;             				// sample width
	DWORD	ItalicWdth;               // italic sample width
	DWORD	BoldWdth;              		// bold sample width
	DWORD	BoldItalicWdth;           // bold italic sample width
	DWORD	MWdth;              			// max sample width
	DWORD	ItalicMWdth;             	// max italic sample width
	DWORD	BoldMWdth;             		// max bold sample width
	DWORD	BoldItalicMWdth;          // max bold italic sample width
	char  FaceName[LF_FACESIZE];		// Typeface name
}FONT;

// 	---------------------------------------------------------------
// 	Type 0 font record (FastCAD/DOS Vector .FNT)
// 	---------------------------------------------------------------

typedef struct
{
	DWORD	RLen;	  								//										=	sizeof(FONT0)
	WORD	ID;											// font id #          = 0
	WORD	TypeID;									// type 0 font        = 0
																// bit 8000h set      = font unavailable
	char	FntName[LF_FACESIZE];	 	// font name ANSIZ

	char	Flags;									// flag bits
	char	IconID;									// icon for display   = 3
	char  unused1[2];
	DWORD unused2[3];             // reserved
	DWORD	hFont;									// font mem block handle
}FONT0;


typedef struct
{
	char id;              // M†ste vara typ 2
	char width[255];
	short	offset_fhgt;
	short vectors[255];
	short height;
	short max;                    // Max height
	short baseline;
	short min;                   // Min height
	short spacing;                // Character spacing
	short linespacing;
	short flags;
	short smartfs;
	char smartfn[41];
} FNT_FONT;


// 	---------------------------------------------------------------
// 	Type 1 font record (Windows TrueType)
// 	---------------------------------------------------------------

typedef struct
{
	DWORD	RLen;	  								//										=	sizeof(FONT1)
	WORD	ID;											// font id #          = 0
	WORD	TypeID;									// type 1 font        = 1
																// bit 8000h set      = font unavailable
	char	FntName[LF_FACESIZE];	 	// font name ANSIZ

	char	Flags;									// flag bits
	char	IconID;									// icon for display   = 3

	char  unused1[2];
	DWORD unused2;      		      // reserved

	DWORD	lfHeight;								// logfont std height = 0x24
	DWORD	lfWidth;								// logfont std width  = 0x0E
	char	CharSet;								// ANSI_CHARSET, etc.
	char	PitchAndFamily;					// e.g. FF_SWISS or VARIABLE_PITCH   = 0x17
	float	HAdjust;								// height multiplier=(sampleheight)  = 1.41176
																// /(sampleheight-descender)
}FONT1;

// 	---------------------------------------------------------------
// 	Type 2 font record (ACAD Compatible Vector .SHX)
// 	---------------------------------------------------------------

typedef struct
{
	DWORD	RLen;	  								//										=	sizeof(FONT2)
	WORD	ID;											// font id #          = 0
	WORD	TypeID;									// type 2 font        = 2
																// bit 8000h set      = font unavailable
	char	FntName[LF_FACESIZE];	 	// font name ANSIZ

	char	Flags;									// flag bits
	char	IconID;									// icon for display   = 4
	char  unused1[2];
	DWORD unused2[3];             // reserved
	DWORD	hFont;									// font mem block handle
}FONT2;

typedef union
{
  FONT0 Fnt;
  FONT1 Ttf;
  FONT2 Shx;
}FONTS;


// 	===============================================================
// 	Font Service Functions
// 	===============================================================

#define FSVC_DRAW		0		// draw text geometry
#define FSVC_PICK		1		// pick test text geometry
#define FSVC_LEN		2		// calc text geometry length
#define FSVC_BOX		3		// EAX->tight-fit box around text
#define FSVC_EXBOX	4		// EAX->margin box around text
#define FSVC_ADD		5		// ESI->font name to add to IB
#define FSVC_INIT		6		// ESI->FontIB2, just initialized
#define FSVC_END		7		// ESI->FontIB2, release mem

// 	===============================================================
// 	FontID control flags
// 	===============================================================

#define FID_UNAVAIL		0x8000		// font not available
#define FID_DUP				0x4000		// font duplicated
#define FID_MASK			0x00FF		// mask for valid type id

// 	===============================================================
// 	FONTX.Flags values
// 	===============================================================

#define FF_Init			1		// has been initialized


// 		Old Font IB header

typedef struct
{
	DWORD	ERLen;			// actual length (bytes in use)  = 	sizeof(FontIB)
	char	EType;			// entity type code (always 0) = ET_IB
	char	IType;			// info block type (FF=XP)  = 	IB_FONT
	WORD	Creator;		// XPID (0=core)
	DWORD	AllocLen;		// allocation length    = 	sizeof(FontIB)
	WORD	Count;
}OldFontIB;

// 	===============================================================
// 	New Font InfoBlock Structure
// 	===============================================================

// 		New Font IB header

#define CurFontIBVer 	3		// IB Version #

typedef struct
{
	DWORD	ERLen;			// actual length (bytes in use)  	= sizeof(FontIB)
	char	EType;			// entity type code (always 0) 		= ET_IB
	char	IType;			// info block type (FF=XP)  			= IB_FONT
	WORD	Creator;		// XPID (0=core)
	DWORD	AllocLen;		// allocation length    					=	sizeof(FontIB)
	WORD	Count;   		// marks new FontIB2              = 0x0FFFF
	WORD	IBVer;			// IB Version #      							=	CurFontIBVer
	WORD	NextID;			// next font id to assign         = 256
}FontIB;

// 	The font IB header above is followed by one or more
// 	FONTX structures, then a dword = 0 to mark the end
// 	of the infoblock.


#endif
