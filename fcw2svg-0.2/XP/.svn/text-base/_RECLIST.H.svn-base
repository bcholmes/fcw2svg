// 	===============================================================
// 	RECLIST.CPY - Record List Control Structure
// 	===============================================================
// 	Copyright 1994 Evolution Computing
// 	All rights reserved
// 	Written by Mike Riddle 8-14-94
// 	Revised for WIN32 5-10-95 MR
// 	---------------------------------------------------------------

#ifndef _RECLIST_H_
#define _RECLIST_H_

//  A Record is:

//     ÚÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÂÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄ¿
//     ³ record length ³                data bytes               ³
//     ÀÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÙ
//     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ record length ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ

// 	A variable # of bytes that starts with a DWORD record length.
// 	The length DWORD is included in the length. The smallest
// 	valid record is 4 bytes long.

// 	---------------------------------------------------------------

//  A Record LIST is:

//     ÚÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿
//     ³ rec 1 ³    rec 2   ³  rec 3  ³ tos rec 4 ³   unused memory   ³
//     ÀÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ
//      À Start                        À TOS                       Max Ù
// 
// 	The data structure specified by RECLIST contains pointers
// 	to a block of global memory that contains none or more records
// 	stored one after the other, with the newest record stored at
// 	the highest offset, followed by available memory for a total
// 	memory block size of RECLIST.Max bytes.

// 	A record list is easily scanned from oldest to newest record.
// 
// 	---------------------------------------------------------------

//  A Record STACK is:

//     ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄ¿
//     ³  unused memory   ³ tos rec 4 ³  rec 3  ³   rec 2   ³  rec 1  ³
//     ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÙ
//      À Start            À TOS                                   Max Ù
// 
// 	The data structure specified by RECSTACK contains pointers
// 	to a block of global memory that contains none or more records
// 	stored one below the other, with the newest record stored at
// 	the lowest offset, preceeded by available memory for a total
// 	memory block size of RECLIST.Max bytes.

// 	A record stack is easily scanned from newest to oldest record.
// 
// 	===============================================================

typedef struct
{
	DWORD Max;			// max offset of list +1
	DWORD Start;		// offset of start of data
	DWORD TOS;			// current TOS (top of stack) offset of top valid record
	DWORD EOL;			// offset of 1st free byte after TOS record
	DWORD flags;		// 0=RECLIST
}RECLIST;

typedef struct
{
	DWORD Max;			// max offset of stack +1
	DWORD Start;		// offset of start of data 0=not yet allocated
	DWORD TOS;			// current TOS (top of stack) offset of top valid record
	DWORD EOL;			// offset of 1st free byte after TOS record
	DWORD flags;		// 1=RECSTACK
}RECSTACK;

#endif