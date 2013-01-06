// 	===============================================================
// 	HEADER.CPY - Header and File ID data structures
// 	===============================================================

// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Susan Montooth 2/15/96

// 	===============================================================
// 	FILE ID (File identifier bytes)
// 	===============================================================

#ifndef _HEADER_H_
#define _HEADER_H_

#define DBVERSION	24		// correct current database

// ProgID  		SBYTE	'FCW (FastCAD for Windows) '
// VerText		SBYTE	versionStr // version # as text (4 bytes)
//		        SBYTE	' drawing file.'
//        		SBYTE	13,10,26 // end chars for DOS Type cmd.
// DBVer	  	SBYTE	DBVERSION
//	        	SBYTE	79 dup (0) // filler
//        		SBYTE	0FFh	// end marker (total 128 bytes)
//char FileID[128];		   	// Normally a struct

#define sizeFileID	128		// sizeof(FileID) treats
// 					// versionStr as 1 byte!

// 	===============================================================
// 	HEADER Information block
// 	===============================================================

// 	Text specifications sub-structure

typedef struct
{
	short 	Font;
	float		Hgt;
	float		XScl;
	float		Spac;
	float		BAng;
	short		Just;
	short		Flags;
}TSPEC;

// 	---------------------------------------------------------------

#define HDRVERSION	4	// current valid header version

typedef struct
{
	int	ERLen;		// actual length (bytes in use) = sizeof(HDR)
	char	EType;		// entity type code (always 0)  = ET_IB
	char	IType;		// info block type (FF=XP) = IB_HDR
	short	Creator;	// XPID (0=core)
	int	AllocLen;	// allocation length = sizeof(HDR)

	char  HdrVersion;	// header version = HDRVERSION
	char  DBVer;		// database version = DBVERSION

	short	DwgFlags;	// misc flags (frame, etc)
	short	FStyle;		// current fill style
	short	Color;		// current values for common stuff
	short	Layer;
	short	LStyle;		// current line style
	short	WPlane;
	short	DStyle;
	short	BColor;		// background color
	short	GridID;		// grid system

	GPOINT3 Low;        	// lowest  x,y,z extents coordinate
	GPOINT3 High;       	// highest x,y,z extents coordinate

	char	XtValid;	// extents are valid
	char	XtGrown;	// extents have grown (for SBUpd)
	char	PThick;		// Pen thickness 0->2.54mm
	char	AngFmt;		// angle display format:
                  		// bit 4 set ANGW is dms
                  		// bit 2 set BRNG is surveyors
                  		// bit 1 set BRNG is dms
                  		// else decimal degrees
	float	UnitV;    	// inches per drawing unit
	char	DistFmt;	// distance format
	char	DecP;		// decimal places
	char	FRnd;		// fractions to nearest (power of 2)
	char	unused2;	// filler
	short TrackType;	// tracking flags (to 64 bytes total)

	TSPEC TSpec;		// 22 byte text specifications
	short LastGroupID;	// last group ID # used

	short ArwStyle;		// entity ends arrow style
	float	ArwLen;		// entity ends arrow length
	float	ArwHgt;		// entity ends arrow height
	float	CurWidth;	// current width
	int  	LastTag;	// last entity tag id used
	float	WallWidth;	// wall width
	float	WallLimit;	// wall trap limit
	float	SampleWid;	// sample widths in inches (Fill Styles)
	int		ReservedV[2];	// reserved use
	float	ChamferLimit;// chamfer max angle for wide lines
	int 	unused3[30];	// (unused)
}HDR;

// 	Values for TrackType:

#define TK_ABS		0	// absolute coordinates
#define TK_REL		1	// relative
#define TK_POL		2	// polar
#define TK_NONE		3	// none

// 	Values for DwgFlags:

#define DF_FRAMES	0x01  	// frames on
#define DF_AUTOZEXT	0x02	// auto ZEXT on next load only
#define DF_SHTOCV	0x04	// sheets only current visible
#define DF_PTIN		0x08	// display pen thickness in inches

#endif

