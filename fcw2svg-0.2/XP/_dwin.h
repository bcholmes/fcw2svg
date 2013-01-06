// 	===============================================================
// 	DWIN.CPY - Drawing Window Data Structure
// 	===============================================================
// 	Copyright 1995 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 6-15-95
// 	---------------------------------------------------------------

#ifndef _DWIN_H_
#define _DWIN_H_

#include <_DEVU.H>

// 	sizeof(ViewP) must be multiple of 4 bytes

typedef struct
{
	float VWidth;		// current view width
	float VHgt;			// current view height
	float VCenX;		// current view center X
	float VCenY;		// current view center Y
	float VCenZ;		// current view center Z
	float VRotXY;		// current view rotation about XY
	float VRotYZ;		// current view rotation about YZ
	float VRotZX;		// current view rotation about ZX
	float Nleft;		// normalized 0..1 screen location
	float Ntop;
	float Nright;
	float Nbottom;
	int   VType;		// view type bits
	char  VName[28];		// view name
}ViewP;

#define VSetCt			8		// # dwords to copy for view set

// 	---------------------------------------------------------------

typedef struct
{
	int len;			// record length     = 	SIZEOF(DWIN)
	int hDWin;		// child win is accessed thru handle
  DWORD GridF;	// current grid flags

	DevU LocalDevU;		// this windows' DevU structure

	// The OpenGL support data (added in 6.021 removed in 6.14)

//	DWORD hDC;				// hDC for OpenGL
//	DWORD hRC;				// rendering context

	ViewP LocalViewP;	// Drawing window view specifications

	// 	Main window client area current DWIN coordinates
	// 	These values are calc from N values above when
	// 	the main windows' size changes.

	int	Cleft;
	int	Ctop;
	int	Cright;
	int	Cbottom;

	// 	Child (drawing window) client area coordinates
	// 	These are used by the drawing primitives

	int	Dleft;
	int	Dtop;
	int	Dright;
	int	Dbottom;

	// 	Current cursor information

	int CType;	// cursor type
	int CFlags;	// current RDF flags for this cursor
	int CAtch;  // 1=draw pick box also

	// 	note: the following must match 3d line geometry (CSRMGR)

	float DWVecX;			// DWVecX..DWOrgZ = 3d "on-line" vector
	float DWVecY;
	float DWVecZ;
	float DWOrgX;			// cursor origin
	float DWOrgY;
	float DWOrgZ;
	float DWCsrX;			// cursor position
	float DWCsrY;
	float DWCsrZ;

	// 	Scroll Bar Information

	int HSBPos;	// range 0..100
	int VSBPos;	// range 0..100

	//	Separate Drawing List Window Information

	hDLIST hDList;		// 0 = normal window
	DWORD CloseProc;	// <>0 call proc on window close
	DWORD LVBkgnd;		// last valid background color

	// 	2d Window Information

	int wxsiz;		// window pixel sizes
	int wysiz;
	float rxsiz;	// real window size
	float rysiz;
	float rxlow;		// real window extents
	float rylow;
	float rxhi;
	float ryhi;
	float wry;		// wysiz/rysiz (vert pixels per real unit)
	float wrx;		// wxsiz/rxsiz (horiz pixels per real unit)

	// 	3d Window Information

	float WTM[16];	// real pt to 0..1 clip cube xform (draw)
	float ITM[16];	// 0..1 clip cube to real (dig)
	float VTM[16];	// real pt to view centric real pt

	// 				// (view horz = x, vert = y, world scale)

	float	IVTM[16];		// inverse VTM - back to world coord

	float	WFDVX;			// window forward direction vector
	float	WFDVY;
	float	WFDVZ;
	float	ZDpth;		// Z Buffer Real Depth
	int   ZHdl;			// Z Buffer Memory Handle

	DPAK DynPak;		// DynTrak data
}DWIN;

// 	---------------------------------------------------------------
// 	View type bit equates
// 	---------------------------------------------------------------

#define VT_3d				0x01		// 1 if 3d, else 2d
#define VT_Persp		0x02		// 1 if perspective, else ortho
#define VT_Hide			0x04		// 1 if 3d hidden surface view
#define VT_NGrd			0x08		// 1 if grid display inhibited
#define VT_FitW			0x10		// width sets scale (overrules VT_FitV)
#define VT_FitH			0x20		// height sets scale
#define VT_Off			0x8000		// 1 if draw window is off (not drawn)
#define VT_Max			0x4000		// window is maximized
#define VT_Min			0x2000		// window is minimized
#define VT_ZEXT			0x1000		// win needs ZExtSetup on redraw


#endif
