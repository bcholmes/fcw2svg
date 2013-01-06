// 	===============================================================
// 	DEVU.CPY - DC Use Structure (manage tools in DC's)
// 	===============================================================

// 	Copyright 1995 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 4-3-95

// 	---------------------------------------------------------------

#ifndef _DEVU_H_
#define _DEVU_H_

// 	Values for DevU.flags

#define DevU_Untool				0x0001	// DevUsePrior releases tools
#define DevU_ReleaseDC		0x0002	// DevUsePrior releases DC
#define DevU_PalValid			0x0004	// hDC palette currently valid

#define DevU_ValidPen			0x0010	// pen avail in hDC
#define DevU_DelPen				0x0020	// DevUntool deletes pen
#define DevU_ValidBrush		0x0100	// brush avail in hDC
#define DevU_DelBrush			0x0200	// DevUntool deletes brush

#define DevU_XOR					0x0400	// now doing XOR mode
#define DevU_BkImage	    0x0800	// DEVU should use a backimage

#define DevU_HaveCaps			0x080000000		// already have DevCaps data
#define DevU_Print				0x040000000		// is a printer DC
#define DevU_BM						0x020000000		// is a bitmap DC
#define DevU_MF						0x010000000		// is an enhanced metafile DC
#define DevU_DWIN					0x008000000		// is a DWIN
#define DevU_ODraw		    0x004000000	  // is an owner draw control item

// 	Types of brush/pen

#define T_NONE				0
#define T_SOLID				1
#define T_STY					2

// 	Device-Use structure (DC & Tools management)

typedef struct
{
	DWORD flags;			// current need/valid flags
	DWORD SavePtr;		// DevUsePrior copy back adr (0=none)
	HDC hDC;				  // handle of device context	for drawing
	DWORD hWin;				// handle of window owning DC
	DWORD RCaps;			// RASTERCAPS flags
	DWORD XPI;				// X pixels/inch
	DWORD YPI;				// Y pixels/inch
	DWORD SqPix;			// square pixels
	DWORD XTotal;			// X total pixels
	DWORD YTotal;			// Y total pixels
	float PScale;			// paper scale correction

	DWORD ColorIdx;		// current tools color index
	DWORD ColorRef;		// COLORREF data to use
	DWORD BkColorIdx;	// background color index
	DWORD BkColorRef;	// background COLORREF data to use
	DWORD NColors;		// max # colors for hDC

	DWORD Color2Idx;	// Second entity color index

	DWORD hPal;				// handle of palette
	DWORD hOldPal;		// handle of old palette

	DWORD hPen;				// handle of pen
	DWORD PenWidth;		// width of current pen
	DWORD hOldPen;		// handle of old pen
	DWORD rePen;			// proc to recreate pen (new color etc.)
	DWORD tPen;				// type of pen
	DWORD	PThick;			// Pen thickness 0->2.54 mm (0..254)

	DWORD hBrush;			// handle of brush
	DWORD hOldBrush;	// handle of old brush
	DWORD reBrush;		// proc to recreate brush (new color etc.
	DWORD tBrush;			// type of brush

	DWORD EndProc;		// proc called when being DevUsePrior'd

	HDC hWinDC;			// window/print DC
	HDC hBmpDC;			// bitmap of dib section
	void  *hBMP;			// handle of bkimage bitmap
	DWORD hOldBMP;		// old handle to restore before delete
	DWORD *pBits;			// pointer to bit array
	DWORD nPixBytes;	// # bytes in pixel bits image
	DWORD nRowSize;		// # of bytes in a row of pixels
	DWORD nPixSize;		// # bytes in a pixel
	DWORD bwid;				// bitmap width in pixels
	DWORD bhgt;				// bitmap hieght in pixels


	DWORD ODItemLeft;	// owner draw item rectangle
	DWORD ODItemTop;
	DWORD ODItemRight;
	DWORD ODItemBottom;

}DevU;

#endif