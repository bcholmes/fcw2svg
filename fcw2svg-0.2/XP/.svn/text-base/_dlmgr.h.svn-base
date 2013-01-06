////// DLMGR.H - FormSt Packets - Master FastCAD-32 XP include file //////
//
//	Written by Mike Riddle 5-24-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////
#ifndef _DLGMGR_H_
#define _DLGMGR_H_


#define hDLIST void*
#define pIB void*
#define PARM DWORD

void _stdcall MarkUndo();
void _stdcall MarkUndoAdd();
void _stdcall CancelUndo();

hDLIST _stdcall DLCreate(LPSTR pFName,int DLFlags);
void _stdcall DLDestroy(hDLIST hDList);
void _stdcall DLDestroyOV(void);
void _stdcall DLDestroyXR(void);

//	for the following calls, hDList = NULL means the
//	current working DList (the one that gets new entities).

void _stdcall DLLocateIB(hDLIST hDList);
pIB _stdcall DLGetIBAdr(hDLIST hDList,int IBId);
void _stdcall DLSetIBAdr(hDLIST hDList,int IBId, void *pNewIB);

hDLIST _stdcall DLRename(hDLIST hDList,LPSTR pLFName);
void _stdcall DLEmpty(hDLIST hDList);

void _stdcall DLTransfer(hDLIST hDLTemp, pENTREC pRecd, DWORD BorA);
#define DLT_BEFORE 0
#define DLT_AFTER  1

void _stdcall DLPack(hDLIST hDList);

pENTREC _stdcall DLGetFirst(hDLIST hDList);
pENTREC _stdcall DLGetBack(hDLIST hDList);
pENTREC _stdcall DLGetLast(hDLIST hDList);

pENTREC _stdcall DLCopy(hDLIST hDList,pENTREC pEntRec);
pENTREC _stdcall DLApnd(hDLIST hDList,pENTREC pEntRec);
pENTREC _stdcall DLApndM(hDLIST hDList,pENTREC pEntRec);
pENTREC _stdcall DLApndE(hDLIST hDList,int EntType, int EntSize);
pENTREC _stdcall DLCopyM(hDLIST hDList,pENTREC pEntRec);

pENTREC _stdcall DLDup(pENTREC pEntRec);
pENTREC _stdcall DLClone(pENTREC pEntRec);

pENTREC _stdcall DLResize(pENTREC pEntRec,int NewSize);
pENTREC _stdcall DLReplace(pENTREC pEntRec,pENTREC pNewRec);
pENTREC _stdcall DLDelete(pENTREC pEntRec);

void _stdcall DLErase(pENTREC pEntRec);
void _stdcall DLUnErase(pENTREC pEntRec);
BOOL _stdcall DLAskErased(pENTREC pEntRec);
void _stdcall DLSelect(pENTREC pEntRec);
void _stdcall DLUnSelect(pENTREC pEntRec);
BOOL _stdcall DLAskSelected(pENTREC pEntRec);

void _stdcall DLMove(pENTREC pMoveRec,pENTREC pAfter);
void _stdcall DLMoveB(pENTREC pMoveRec,pENTREC pBefore);

typedef DWORD (_stdcall *SCANPROC)(hDLIST hDList,pENTREC pEntRec,
		PARM parm1, PARM parm2);

//	for the following call, hDList = NULL means scan
//	All DL_OVL DLists as a single operation.
//	DLScan performs two DLScan1 calls, with first
//	DLS_ONLYSHT then DLS_NOSHEET, to force common sheet
//	after all named sheets.

DWORD _stdcall DLScan(void* hDlist,void* EntProc,int DSFlags, void* parm1, void* parm2);
DWORD _stdcall DLScan1(void* hDlist,void* EntProc,int DSFlags, void* parm1, void* parm2);

// 	---------------------------------------------------------------
// 	Values that can be specified for DLFlags:
// 	---------------------------------------------------------------

#define DL_OVL			1	// list shares common coordinate space
						 					// (all DLists with DL_OVL set will
							 				//  be drawn in all common-view windows
							 				//  in an overlaid coordinate space.)

#define DL_STD		DL_OVL	// default standard drawing list

#define DL_RO				2	// list is read-only - no changes can
						 					// be made - it is visible for reference
						 					// only. (RD_PickRef will pick, but
						 					//  RD_Pick & RD_Pick1 will not).

#define DL_Sep			4	// separate DList - not an overlay

#define DL_Private	8	// private - not vis in DWGCTL dialog
							 				// SAVEALL will not save this

#define DL_HasWin		0x10	// has a separate DWIN active

#define DL_Head			0x80	// all DLists have this flag set
									 				// to enable finding the DList
									 				// from the record pointer. No
									 				// ECTL.Flags word ever has it set.
#define DL_SubL			0x40	// this DList is a sublist of an entity

#define DL_XREF			0x20	// List is an XREF

//	---------------------------------------------------------------
//	Values that can be specified for DSFlags:
//	---------------------------------------------------------------

#define	DLS_Std						0				// standard all non-erased ents
#define	DLS_Sel			0x10000				// only selected entities
#define	DLS_NotSel	0x20000				// only unselected entities
#define	DLS_RO			0x40000				// allow read-only entities
#define	DLS_All			0x80000				// all entities, even erased
#define	DLS_SL			0x01000				// also ents in sublists
																	// after owner entity
																	// take precedince over unlock
#define	DLS_UNLK		0x02000				// force unlock for this scan
																	// no group hdr, just its ents	
#define	DLS_NOUNLK   0x04000      // ignore unlock for this scan
#define	DLS_Fence    0x08000      // test fence to end scan
#define	DLS_OVL      0x00100      // force overlay scan for NULL
																	// hDList even if current work is
																	// a separate file window.
#define	DLS_NOWDC    0x00200      // no work dwg change during scan
#define DLS_SHEET    0x00400      // see sheets instead of scan their SL
#define DLS_HSHTOK	 0x00800		  // hidden sheets ok - proc them
#define DLS_ONLYSHT	 0x00010		  // show only entities on a sheet
#define DLS_NOSHEET	 0x00020		  // ignore entities on a sheet


#define	DLS_Edit	DLS_Std+DLS_Sel	// entities to edit
#define	DLS_Info	DLS_Edit+DLS_RO	// entities to list
#define	DLS_Std      0						// standard all non-erased ents
#define	DLS_StdN  DLS_Std+DLS_NOWDC

pENTREC _stdcall DLMakeSubList(pENTREC pEntRec);
hDLIST _stdcall DLGetSubList(pENTREC pEntRec);
BOOL _stdcall DLAskEmptySL(pENTREC pEntRec);
hDLIST _stdcall DLGetDList(pENTREC pEntRec);
DWORD _stdcall DLSetWorkDL(hDLIST hDList);
hDLIST _stdcall DLGetWorkDL(void);

hDLIST _stdcall DLLoad(LPSTR pFName,int DLFlags);
BOOL _stdcall DLSave(hDLIST hDList,LPSTR pFName);



void _stdcall DLSetFence(hDLIST hDList);
void _stdcall DLClearFence(hDLIST hDList);
void _stdcall DLDelThis(void);
void _stdcall DLAskNest(void);


void _stdcall ClearSel(void);

#endif
