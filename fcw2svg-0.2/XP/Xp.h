//////////////////// XP.H - Master FastCAD-32 XP include file ////////////
//
//	Written by Mike Riddle 5-24-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _XP_H_
#define _XP_H_

#pragma pack(1)	// no packing for alignment

#define XPCALL _stdcall
#define XPSVC _declspec (dllexport)

typedef void (_stdcall *PCMDPROC)(void);

typedef struct 
{
	DWORD	selfid;					// location of copy of self stored here
	char	*CmdList;				// adrs of CList list of strings
	PCMDPROC *ProcList;		// adrs of PList list of functions
	char **RscTbl;				// address of our resource index table
	PCMDPROC MsgProc;			// address of our XP message procedure
	PCMDPROC ESVCProc;		// address of our XP ent SVC procedure
	DWORD	XPIDNr;					// our modules' XP ID #
	HINSTANCE ModHdl;			// our modules' LoadResource handle
	DWORD	ReqVersion;			// minimum required FCW version to run (ie, 500)
	DWORD	ReqFlags;				// Requirement flags
	DWORD	RunningVer;			// Now running on FCW Version (500t)
	DWORD	XPVersion;			// XP Version #
	HWND  hMainWin;				// main prog window handle
	DWORD MainPrgRscMod;	// main prog resource module hdl
	HINSTANCE hMainInst;	// main program instance handle
	DWORD hDWMain;        // DW container window handle
	char  SubVer[2];			// Added subersion two-character string ("7g" for 6.037g)
	char  Reserved1[2];		// Reserved for future use
	DWORD	Reserved2[4];		// Reserved for future use
}XP;

#include <_FORMST.H>
#include <_RDATA.H>
#include <_GEOMTRY.H>
#include <_ESTRUC.H>
#include <_DLMGR.H>
#include <_ENTOPS.H>
#include <_MATH.H>
#include <_MATDEF.H>
#include <_DIALOG.H>
#include <_LAYER.H>
#include <_XPMSG.H>
#include <_HEADER.H>
#include <_IBMGR.H>
#include <_SVIB.H>
#include <_FONTS.H>
#include <_LSTYLES.H>
#include <_FSTYLES.H>
#include <_PACKETS.H>
#include <_RSCID.H>
#include <_MISC.H>
#include <_INTS.H>
#include <_GRIDS.H>
#include <_TXWIN.H>
#include <_DSTYLES.H>
#include <_PRINT.H>
#include <_TOOL.H>
#include <_RECLIST.H>
#include <_COLORS.H>
#include <_MESSAGE.H>
#include <_OPFLAGS.H>
#include <_NVIEW.H>
#include <_LWCMAP.H>

/////////////////////// function prototypes ////////////////////////////////

#define XPRegCmd _XPRegCmd
#define XPUnregCmd _XPUnregCmd
#define XPRegImport _XPRegImport
#define XPRegExport _XPRegExport
#define CmdEnd _CmdEnd

void _stdcall XPRegCmd(void *xpdef);
void _stdcall XPUnregCmd(void *xpdef);
void _stdcall XPRegImport(void (_stdcall *xproc)(),char *xdesc, char *xtype);
void _stdcall XPRegExport(void *xproc,char *xdesc, char *xtype);

void _stdcall CmdEnd();

void XPCALL SetBmpToolsAdr(void *p, int n);
void XPCALL ShowChanges(void);
void XPCALL DevBkShowCur(void);
HBITMAP XPCALL MakeXPBitmap(UINT sizex,UINT sizey,
			double xlow,double ylow,double xhi,double yhi,PCMDPROC pDraw);
HBITMAP XPCALL MakeXPBitmap2(UINT sizex,UINT sizey,
			double xlow,double ylow,double xhi,double yhi,PCMDPROC pDraw);

void XPCALL RBmpFill(BMPSTY* pBS,GLINE2* pext);//void XPCALL RBmpFill(BMPSTY* pBS,EXT2* pext);

void XPCALL RFitBmp(HBITMAP hbmp, DWIN *hdwin, GLINE2 *pExt);

DWIN* XPCALL GetPkDWinAdr(void);

#endif