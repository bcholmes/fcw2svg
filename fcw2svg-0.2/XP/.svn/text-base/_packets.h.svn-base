// 	===============================================================
// 	PACKETS.CPY - Core Services Structure definitions
// 	===============================================================
// 	Copyright 1995 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 4-26-95
// 	---------------------------------------------------------------

#ifndef _PACKETS_H_
#define _PACKETS_H_

typedef struct
{
	DWORD	left;			// button rectangle
	DWORD	top;
	DWORD	right;
	DWORD	bottom;
	HWND	hSBar;		// handle of containing SBAR window
	DWORD	take;			// size of button to take
	DWORD	value;		// 0=up, 1=down, 2=shallow down
									//  4=noframe, 8=btnclr outline
	DWORD	flags;		// 8000h=left text, else centered
									// 4000h=text adrs is icon handle
	char *txptr0;		// adrs of ANSIZ "up" text (0=none)
	int	  txptr1;		// adrs of ANSIZ "down" text
									// 0=none, -1=use txptr0
	DWORD	btnclr;		// button text color #
	DWORD	btnbkgnd;	// button background color
	DWORD	digproc;	// proc called on dig in button
									// 0 = none (esi will be BTN pkt adrs)
	DWORD	button2;	// if <>0, then 2nd text sub-button
	DWORD	Rdigproc;	// proc called on right dig in button
									// 0 = none (esi will be BTN pkt adrs)
}BTN;

#define BV_DOWN			1	// button is sunken
#define BV_UP				0	// button is up
#define BV_TRAY			2	// shallow down tray frame
#define BV_PLAIN		4	// no frame
#define BV_OUTLINE	8	// btn color outline

#undef BF_LEFT   // Defined as a borderflag in WINUSER.H

#define BF_LEFT			0x8000	// left justify text
#define BF_CENTER		0				// center justify text
#define BF_TOGGLE		0x2000	// enable toggle BV_DOWN on dig
#define BF_ICON			0x4000	// txptrn is bitmap handle
#define BF_TAKER		1				// take space on right of SBar (else left)
#define BF_TAKEA		2				// take all remaining space
#define BF_TAKEN		4				// take no space (used for dual btns - ANS)

typedef struct
{
	DWORD	TknBfr;		// ptr to ASNIZ string buffer
	DWORD	ScanPtr;	// token build scanner
	DWORD	BtnPtr;		// adrs of button to display (0=none)
	DWORD	flags;		// control/function flags
	DWORD	TknProc;	// token procedure: called on token delimiter
}KEYSINK;

// 	KEYSINK flags values

#define KS_NxNewLine		0x000000001	// next chr starts a new line
#define KS_NoDisplay		0x000000002	// don't display anything

typedef struct
{
	DWORD	Start;		// started at adrs
	DWORD	Last;		// last valid adrs
	DWORD	Scan;		// current scan adrs
	DWORD	flags;	// flag bits
}SCRIPT;

#define SF_Release	0x000000001	// RelMem Start adrs at end script
#define SF_CtxRst		0x000000002	// Context Restore at end

typedef struct
{
	DWORD	hkey;			// =	HKEY_CURRENT_USER
	DWORD	kname;		// address of key name string/rscid
	DWORD	vname;		// address of value name string/rscid
	DWORD	vbfr;			// adrs of value data bfr
	DWORD	vbfrmax;	// max chrs in vbfr
	DWORD	vtype;		// data type code
	DWORD	vbsize;		// actual data size returned
	DWORD	vbres;		// create/open key result code
}REGKEY;

typedef struct
{
	DWORD	resbfr;		// result ANSIZ file name bfr\rscid
	DWORD	deffn;		// default file name to init\rscid
	DWORD	defft;		// default file type "FCW",0\rscid
	DWORD	fltrs;		// filters table\rscid (0=none)
	DWORD	oflags;		// flags for open  =  OFN_CREATEPROMPT
	DWORD	sflags;		// flags for save  = 	OFN_PATHMUSTEXIST
	DWORD	fidx;			// selected filter index (1=first)
	DWORD	oklabel;	// text/RSCID for ok button label
}GETFN;

// 	---------------------------------------------------------------
// 	Draw Mode flags
// 	Note: only meaningful during entity handler support of
// 		EDraw, EMark, EUndraw, etc.
// 	---------------------------------------------------------------

#define DM_DRAW			0
#define DM_MARK			1
#define DM_UNDRAW		2

// 	Entity operations control flags

#define T_ON			0x01		// prevent T<0.0 or T>1.0

// 	---------------------------------------------------------------
// 	Device Manager State flags (returned in AX by DevGetState)
// 	---------------------------------------------------------------

#define DCS_PRINT			0x01		// now printing (or preview)
#define DCS_XOR				0x02		// now XOR mode
#define DCS_META			0x04		// metafile output
#define DCS_PREVIEW		0x08		// now preview (DCS_PRINT also set)

// 	---------------------------------------------------------------

typedef struct
{
	DWORD	grow;			// grow in steps of         = 512
	DWORD	bfr;			// current buffer adrs
	DWORD	bsize;		// current buffer size
}DINDEX;

// 	---------------------------------------------------------------
// 	Status window control structure
// 	---------------------------------------------------------------

typedef struct
{
	DWORD	ttxt;			// title text\RSCID
	DWORD	stxt;			// source text\RSCID
	DWORD	dtxt;			// destination text\RECID
	DWORD	btxt;			// button label text\RSCID
}StatW;

// 	---------------------------------------------------------------
// 	Drawing List control structure (CurDwgL ->this)
// 	---------------------------------------------------------------

typedef struct
{
	DWORD	badr;			// block base address (0=no cmtd)
	DWORD	csize;		// current # bytes of data (0=empty)
	DWORD	msize;		// max size before COMMIT req
	DWORD	rsize;		// reserved size (upper limit)
}DwgList;

// 	---------------------------------------------------------------
// 	Smart Symbol placement structure
// 	---------------------------------------------------------------

typedef struct
{
	GPOINT3 At;
	float scalex;
	float scaley;
	float scalez;
	float rotxy;
	float rotyz;
	float rotzx;
	DWORD flags;
	SYMTMAT  TM;          //martix embodying setup
}PLACE;

typedef struct
{
	DWORD flags;
	DWORD pCtrlPE;
	DWORD Tracking;
	DWORD pRay3;
	DWORD pInsSR;
	DWORD rsvd;
}PLSPEC;

#endif