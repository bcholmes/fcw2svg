//////// _GEOMTRY.H - FormSt Packets - FastCAD-32 XP include file /////////
//
//	Written by Mike Riddle 5-24-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _GEOMTRY_H_
#define _GEOMTRY_H_
        
typedef struct 
{
	float x;
	float y;
} GPOINT2;

typedef struct
{
	float x;
	float y;
	float z;
} GPOINT3;

typedef struct
{
	GPOINT2 p1;
	GPOINT2 p2;
} GLINE2;

typedef struct
{
	GPOINT2 Low;
	GPOINT2 High;
} EXTENTS2;

typedef struct
{
	GPOINT3 p1;
	GPOINT3 p2;
} GLINE3;

typedef struct 
{
	GPOINT2 Center;
	float Radius;
} GCIR2;

typedef struct
{
	GCIR2 Circle;
	float SAng;
	float AngW;
} GARC2;

typedef struct
{
	GCIR2 Circle;
	float Ecc;
	float Incl;
} GELP2;

typedef struct
{
	GELP2 Elp;
	float SAng;
	float AngW;
} GELA2;

//////////////////////////////////////////////////////////////////////////

typedef struct 
{
	short	Font;
	GPOINT2 Origin;
	float	Hght;
	float	XScl;
	float	BAng;
	float	Spacing;
	short	TFlags;
	short	DFlags;
	short	Just;
	char	TData[1];
} GTEXT2;

//	Text style flags (TFlags byte):

#define	TS_VERT			 1	//Vertical text flag
#define	TS_FILL 		 2	//Filled text flag (unused in FCW)
#define	TS_MIRROR		 4	//Mirrored text flag (unused in FCW)
#define	TS_BOLD 		16	//Bold text
#define	TS_ITALIC 	32	//Italic text
#define	TS_UNDER		64	//Underscore text
#define	TS_STRIKE	 128	//Strikeout text
#define	TS_OUTLINE 256	//Outline only
#define TS_ANGFIX  512  //Text angle doesn't transform

//	Text data flags (DFlags byte):

#define	TD_FILE		1	//data is file name string
#define	TD_MACRO	2	//data is macro variable name
	
//	Text justification codes (Just byte) as illustrated below

#define	TJ_BL		0	//bottom left
#define	TJ_BC		1	//bottom center
#define	TJ_BR		2	//bottom right
#define	TJ_ML		3	//mid left
#define	TJ_MC		4	//mid center
#define	TJ_MR		5	//mid right
#define	TJ_TL		6	//top left
#define	TJ_TC		7	//top center
#define	TJ_TR		8	//top right
#define	TJ_XML		9	//extended mid left
#define	TJ_XMR		10	//extended mid right
#define	TJ_XXBL		11	//extended bottom extended left
#define	TJ_XBL		12	//extended bottom left
#define	TJ_XBC		13	//extended bottom center
#define	TJ_XBR		14	//extended bottom right
#define	TJ_XXBR		15	//extended bottom extended right
#define	TJ_XXTL		16	//extended top extended left
#define	TJ_XTL		17	//extended top left
#define	TJ_XTC		18	//extended top center
#define	TJ_XTR		19	//extended top right
#define	TJ_XXTR		20	//extended top extended right

// 	     16---17----------18----------19---20
//	      |    |	       |	   |	|
// 	      |    6-----------7-----------8	|
//	      |    |	       |	   |	|
//	      |    |	       |	   |	|
//	      9----3-----------4-----------5---10
//	      |    |	       |	   |	|
//	      |    |	       |	   |	|
//	      |    0-----------1-----------2	|
//	      |    |	       |	   |	|
//	     11---12----------13----------14---15

//////////////////////////////////////////////////////////////////////////

// Nodelist

typedef struct 
{
	short	Count;
	char	Flags;
	char	unused;
	GPOINT2	Nodes[];
} GNLIST2;

// Path

typedef struct 
{
	char	SmType;
	char	SRes;
	float	SParm;
	float	EParm;
	WORD	Count;
	char	Flags;
	char	unused;
	GPOINT2	Nodes[];
} GPATH2;

typedef struct 
{
	char	SmType;
	char	SRes;
	float	SParm;
	float	EParm;
	short	Count;
	char	Flags;
	char	unused;
	GPOINT2 P1;
	GPOINT2 P2;
	GPOINT2 P3;
	GPOINT2 P4;
} GBOX2;

//	Values for NFlags

#define NL_CLS  0x80  // 1 = close node list (polygon)
#define NL_SLD  0x40  // 1 = interior is solid (filled)

//	Bits 01h,02h,04h specify the type of node list:

#define NL_2D   00  // 2D node list (8 bytes per node)
#define NL_2DW  01  // 2D node list with W parameter (12 bytes per node)
#define NL_3D   02  // 3D node list (12 bytes per node)
#define NL_3DW  03  // 3D node list with W parameter (16 bytes per node)

//	Values for Smoother Flags

#define SM_NO 0 // no smoothing
#define SM_CB 1 // Cubic B-Spline (as in FastCAD 2.x)
#define SM_PB 2 // Parabolic Blend (through-point)
#define SM_BZ 3 // Bezier

//////////////////////////////////////////////////////////////////////////

#endif