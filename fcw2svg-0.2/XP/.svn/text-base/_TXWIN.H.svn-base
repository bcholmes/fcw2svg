// 	===============================================================
// 	TXWIN.CPY - Text Window equates, structures, and macros
// 	===============================================================
// 	Copyright 1996 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 2-2-96
// 	---------------------------------------------------------------

#ifndef _TXWIN_H_
#define _TXWIN_H_

typedef struct
{
	DWORD	len;				// record length											- dword	SIZEOF(TXWIN)
	DWORD	txadr;			// address of text image
	DWORD	TWTitle;		// adrs/rscid of text window title
	DWORD	flags;			// option flags
	DWORD	eproc;			// proc to enum text data on demand
	float twnormxl;		// location in main win, normalized		- REAL4	0.2	
	float twnormyl;		//																			REAL4	0.2
	float twnormxh;	  //																			REAL4	0.8
	float twnormyh;		//																			REAL4	0.8
	DWORD	hDWin;			// child window is accessed thru its handle
	DWORD	self;				// adrs of source pkt copied here
	DWORD	lcount;			// current image line count						-	dword	1
	DWORD	ccount;			// current character count
	DWORD	cmax;				// current image max bfr size
	DWORD	sptr;				// store ptr for TWRcv
	DWORD	clnum;			// current display top line number 1..lcount	- dword	1
	DWORD	twcr[4];		// full text window client rect       -	dword	0,0,0,0
	DWORD	mwloc[4];		// main window current location				- dword	0,0,0,0
}TXWIN;

// 	TXWIN.flags values

#define TWF_Release		1	// release TXWIN.txadr on window close
#define TWF_Single		2	// single window - use already open win
#define TWF_UpdPosn		4	// position changes copy back to spec
#define TWF_Max				8	// window is maximized
#define TWF_Min			 16	// window is minimized

// 	Text Window WM_SYSCOMMAND id's

#define TWF_PRINT		999	// print the window text
#define TWF_SAVE		998	// save the window text
#define TWF_SETUP		997	// do page setup for text window

#endif