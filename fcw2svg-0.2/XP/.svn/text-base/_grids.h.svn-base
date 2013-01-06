// 	===============================================================
// 	GRIDS.CPY - Grid & Snap systems data structures
// 	===============================================================
// 
// 	Copyright 1994-1995 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 7-2-94
// 		with additional work by
// 		Susan Montooth 1/95
// 
//	===============================================================


void _stdcall GridIBRevised(void);


// 	===============================================================
// 	Rectangular grid (supported by GRIDR.ASM)
// 	===============================================================

#define L_RECTGS	sizeof(RECTGS)

typedef struct
{
	DWORD	RLen;
	WORD	ID;
	char	GName[32];
	WORD	GClass;				// RectGS class = 0
	float	AlignX;				// all types of GS have
	float	AlignY;				// len thru AlignZ in same posn
	float	AlignZ;

	float	DeltaX;				// GS class-specific data starts
	float	DeltaY;				// with DeltaX
	float	DeltaZ;
	WORD	SnapN;
	WORD	Flags;
	float	SnapX;
	float	SnapY;
	float	SnapZ;
}RECTGS;

// 	values for RectGS.Flags:
#define RGS_SQUARE	1		// x spacing = y spacing
#define RGS_TRIGRID	2		// y = x * tan(30) *1.5

// 	===============================================================
// 	Circular grid (supported by GRIDC.ASM)
// 	===============================================================

#define L_CIRGS		sizeof(CIRGS)

typedef struct
{
	DWORD	RLen;
	WORD	ID;
	char	GName[32];
	WORD	GClass;				// CirGS class = 1
	float	AlignX;				// all types of GS have
	float	AlignY;				// len thru AlignZ in same posn
	float	AlignZ;
 
	float	DeltaA;			
	float	DeltaR;		
	float	DeltaZ;
	WORD	SnapN;
	WORD	Flags;
	float	SnapA;
	float	SnapR;
	float	SnapZ;
}CIRGS;

// 	===============================================================
// 	Angular grid (supported by XPGRIDA.ASM)
// 	===============================================================

#define L_ANGGS		sizeof(ANGGS)

typedef struct
{
	DWORD	RLen;
	WORD	ID;
	char	GName[32];
	WORD	GClass;				// AngGS class = 2
	float	AlignX;				// all types of GS have
	float	AlignY;				// len thru AlignZ in same posn
	float	AlignZ;
 
	float	DeltaX;				// GS class-specific data starts
	float	DeltaY;				// with DeltaX
	float	DeltaZ;
	WORD	SnapN;
	WORD	Flags;
	float	SnapX;
	float	SnapY;
	float	SnapZ;
 
	// 	Specify grid workplane in 3d
 
	float	RotXY;				// 3d rotation angles for plane
	float	RotYZ;
	float	RotZX;
	float	ODist;				// prp offset dist to plane

	// 	Transforms back and forth
 
	TMAT W2G;		// world coord to rect grid coord
	TMAT G2W;		// rect grid to world coord
}ANGGS;

// 	values for AngGS.Flags:

#define AGS_SQUARE		1		// x spacing = y spacing
#define AGS_3D				4		// 1=3d grid, else 2d

// 	===============================================================
// 	Hex grid (supported by GRIDX.ASM)
// 	===============================================================

#define L_HEXGS		sizeof(HEXGS)

typedef struct
{
	DWORD	RLen;
	WORD	ID;
	char	GName[32];
	WORD	GClass;		  // RectGS class = 3
	float	AlignX;		
	float	AlignY;		
	float	AlignZ;

	float	Wid;				// hex cell width
	float	Hgt;				// hex cell height
	
	// 	calculated cell offsets
	
											// vertical				horizontal
											// ========				==========
	float	hdelta;				// width					width*1.5
	float	vdelta;				// width*sin(60)	width*.5
	float	hofst;				// width*.5				width*.75
	float	h1;						// width*.5				width*.25
	float	h2;						// width*.25			width*.375
	float	h3;						// width*.5				width*.5
	float	v1;						// height*.25			height*.5
	float	v2;						// height*.375		height*.25
	float	v3;						// height*.5			height*.5

	DWORD	flags;		// draw and snap flags
	DWORD	orient;		// 1=horizontal, 2=vertical
}HEXGS;

// 	values for HexGS.Flags:

#define XGS_DXCEN		 1		// draw center points
#define XGS_DXEPT		 2		// draw endpoints
#define XGS_DXMID		 4		// draw midpoints
#define XGS_SXCEN	0x10		// snap center points
#define XGS_SXEPT	0x20		// snap endpoints
#define XGS_SXMID	0x40		// snap midpoints


// 	===============================================================
// 	Grid Information block header
// 	===============================================================

//#define IB_GRID		 4		// grid info block type #
#define MaxGS			20		// approx max # grid systems

typedef struct
{
	DWORD	ERLen;					// std info block header
	char	EType;					// EType = Info Block
	char	IType;					// IB type = Grid					 IB_GRID+IB_DFLT	
	WORD	Creator;				// XPID (0=core)
	DWORD	AllocLen;				// allocation length
	WORD	flags;					// button flags
	WORD	NextID;       	// next after predefined grids
	DWORD	NextOfst;		    // offset to next free:   GBIB.NxtFree-GBIB.ERLen
	WORD	CurGridNr;		  // current grid instance ID #
	DWORD	CurGridOfst;		// offset to current GS:   GBIB.StdRect-GBIB.ERLen
	RECTGS	StdRect;			// 0: standard rectangular grid
	CIRGS		StdCir;				// 1: standard circular grid system
	DWORD	 NxtFree;				// current end marker
}GBIB;

// 	GBIB.flags values

#define GS_GRID			1		// grid button on/off
#define GS_SNAP			2		// snap button on/off
#define GS_CSNAP		4		// cursor snap button on/off
#define GS_ORTHO		8		// ortho button on/off

//	for use with AskGridStatus function only:

#define GS_ATTACH	0x0100		// attach button on/off
#define GS_LOCK		0x0200		// group lock button on/off

typedef struct		// generic grid structure
{
	DWORD	RLen;
	WORD	ID;
	char	GName[32];
	WORD	GClass;		
	float	AlignX;		
	float	AlignY;		
	float	AlignZ;
}GRID;


// 	NOTE: Some drawings do not have a valid dword endmarker
// 	written, although it is included in the IB record length.
// 	A workaround is to take the IB starting address and add
// 	the GBIB.NextOfst value to it. This is the address that
// 	should have the dword 0 written to it. Check for this
// 	address when scanning - at or above it is the end of
// 	the infoblock.

