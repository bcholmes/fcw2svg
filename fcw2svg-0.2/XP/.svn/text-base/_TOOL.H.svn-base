// 	===============================================================
// 	Tool Controls Constants & Structure
// 	===============================================================
// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 7-16-96
// 	---------------------------------------------------------------

#ifndef _TOOL_H_
#define _TOOL_H_

#define TAKE_L			0			// take from left
#define TAKE_T			1			// take from top
#define TAKE_R			2			// take from right
#define TAKE_B			3			// take from bottom
#define TAKE_N			4			// take none - control disabled
#define TAKE_MASK		7			// takde direction bits mask
#define TAKE_NOH		8			// ctrl can not be horizontal
#define TAKE_NOV		16		// ctrl can not be vertical
#define TAKE_SCAT		32		// ctrl is the symbol catalog

typedef struct
{
	DWORD Cleft;			// client RECT (read-only)
	DWORD Ctop;
	DWORD Cright;
	DWORD Cbottom;
	DWORD Fleft;			// take from RECT
	DWORD Ftop;
	DWORD Fright;
	DWORD Fbottom;
	DWORD Tleft;			// taken RECT (temp use)
	DWORD Ttop;
	DWORD TRight;
	DWORD TBottom;
	DWORD TxHgt;			// text height
//	DWORD MaxMrgn;		// maximize margin (0 or +)   OBS removed in 6.14
	DWORD hPWin;			// handle to parent window
	DWORD Unused1;		// reserved, unused
	DWORD Unused2;		// reserved, unused
	DWORD ScrnRes;		// Screen resolution code
					 					//  0 =  640 x 480
					 					//  1 =  800 x 600
					 					//  2 = 1024 x 768
					 					//  3 = 1280 x 1024 or larger
}TAKE;

typedef struct
{
	HWND  hWin;			// handle to window
	DWORD TDir;			// take direction
	DWORD TName;		// tool name text/RSCID
	DWORD TProc;		// tool service procedure
	DWORD IID;			// instance id #
	DWORD BList;		// button list adrs
	DWORD IRec;			// instance record adrs
	DWORD Stat;			// status 1=vis, 0=hide
}CTRL;

typedef struct
{
	DWORD rlen;				// specific tool size here  = sizeof(TOOL)
	HWND  hPWin;			// parent window handle
	HWND  hTool;			// Tool window handle
	DWORD Pleft;			// child window rectangle
	DWORD Ptop;				// in parent window coordinates
	DWORD Pright;
	DWORD Pbottom;
	DWORD wid;				// width (right-left+1)
	DWORD hgt;				// height (bot-top+1)
	DWORD left;				// child window rectangle
	DWORD top;				// in repaint coordinates
	DWORD right;
	DWORD bottom;
	CTRL *ctrlp;			// adrs of CTRL struc
	DWORD IID;				// instance id #
}TOOL;

#endif