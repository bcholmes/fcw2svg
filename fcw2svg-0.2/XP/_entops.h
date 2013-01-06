////// _ENTOPS.H - Entity Operations - FastCAD-32 XP include file ////////
//
//	Written by Mike Riddle 5-24-98
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _ENTOPS_H_
#define _ENTOPS_H_

#define GetCStuff _GetCStuff
void _stdcall GetCStuff(void* pEntRec);
#define UseCStuff _UseCStuff
void _stdcall UseCStuff(void* pEntRec);

#define NowDrawingEnt _NowDrawingEnt
pENTREC _stdcall NowDrawingEnt(void);

#define EDraw _EDraw
void _stdcall EDraw(pENTREC pEntRec);
#define EMark _EMark
void _stdcall EMark(pENTREC pEntRec);
#define EUndraw _EUndraw
void _stdcall EUndraw(pENTREC pEntRec);
#define EDrawM _EDrawM
void _stdcall EDrawM(pENTREC pEntRec);

#define EXCheck _EXCheck
void _stdcall EXCheck(pENTREC pEntRec);
#define BgnPExtents _BgnPExtents
void _stdcall BgnPExtents(void);
#define EndPExtents _EndPExtents
void _stdcall EndPExtents(GLINE3* pExt);

#define EPick _EPick
BOOL _stdcall EPick(pENTREC pEntRec);
#define SetEachPickView _SetEachPickView
void _stdcall SetEachPickView(float PickX,float PickY);
#define PartEntity _PartEntity
BOOL _stdcall PartEntity(pENTREC pGroup, pENTREC pInside);
#define SRefEntity _SRefEntity
BOOL _stdcall SRefEntity(pENTREC pSRef, pENTREC pTformed,pENTREC pSource);

#define ETran _ETran
void _stdcall ETran(pENTREC pEntRec);
#define ENUTran _ENUTran
pENTREC _stdcall ENUTran(pENTREC pEntRec);
#define EMir _EMir
pENTREC _stdcall EMir(pENTREC pEntRec);

#define EStretch _EStretch
void _stdcall EStretch(pENTREC pEntRec);
#define SetStretchView _SetStretchView
void _stdcall SetStretchView(float XL,float YL, float XH, float YH);

#define EClass _EClass
int _stdcall EClass(pENTREC pEntRec);

#define	C_NONE	0x00000	// no point data in entity
#define	C_PNT	0x00000	// point data
#define	C_LIN	0x00001	// entity is linear (2D/3D line, arc, spline)
#define	C_SRF	0x00002	// entity has surface (open cyl, filled poly)
#define	C_VOL	0x00003	// entity encloses volume (sphere, solid)
	
#define	C_FILL	0x00004	// bit 2 set=interior is solid or filled
#define	C_3D	0x00008	// bit 3 set=3D, clear=2D
#define	C_2D	0x00000	// bit 3 set=3D, clear=2D
	
#define	C_CLS	0x00080	// bit 7 set=closed (circle or poly)
#define	C_ANN	0x00100	// bit 8 set=annotation only, clear=model
#define	C_COMP	0x00200	// bit 9 set=composite entity
#define	C_EDGE	0x00400	// bit 10 set = entity supports EEdge svc

#define EClassH _EClassH
int _stdcall EClassH(pENTREC pEntRec);

#define	H_TRIM	0x00001	// supports trim
#define	H_BND	0x00002	// supports bend
#define	H_CUT	0x00004	// supports cut
#define	H_DYNED	0x00008	// supports graphic edit
#define	H_MATH	0x00010	// supports near, tan, t, etc.
#define	H_NONE	0x00000	// supports nothing

#define EInfoName _EInfoName
LPSTR _stdcall EInfoName(pENTREC pEntRec);
#define EInfoLength _EInfoLength
float _stdcall EInfoLength(pENTREC pEntRec);
#define EInfoArea _EInfoArea
float _stdcall EInfoArea(pENTREC pEntRec);

#define EList _EList
void _stdcall EList(pENTREC pEntRec);
#define ECut2 _ECut2
pENTREC _stdcall ECut2(pENTREC pEntRec,float X,float Y);
#define ETrim _ETrim
BOOL _stdcall ETrim(pENTREC pEntRec,float TTrim, float TPick);

typedef DWORD (_stdcall *EXPPROC)(pENTREC pEntRec);
#define EExplode _EExplode
BOOL _stdcall EExplode(pENTREC pEntRec,EXPPROC pExpProc);

#define EAttach _EAttach
BOOL _stdcall EAttach(pENTREC pEntRec,int AtCode,GPOINT2* pPick,GPOINT2* pResult);
#define AT_CEN	0	// Center of entity
#define AT_MID	1	// Midpoint
#define	AT_EPT	2	// Nearest Endpoint
#define AT_PCT	3	// % along (PickX = 0..100)
#define	AT_DIST	4	// distance along (PickX = distance)
#define	AT_ON	5	// nearest point on entity
#define	AT_DEG	6	// degrees along entity

#define ENearT2 _ENearT2
BOOL _stdcall ENearT2(pENTREC pEntRec,float X,float Y, int flag,float* pResult);
#define	ENEARF_ANY	0	// point can be off the entity
#define	ENEARF_ON	1	// point must be on the entity

#define ECalPt2 _ECalPt2
BOOL _stdcall ECalPt2(pENTREC pEntRec,float T,GPOINT2* pResult);
#define ECalTan2 _ECalTan2
BOOL _stdcall ECalTan2(pENTREC pEntRec,float T,GPOINT2* pResult);

typedef void (_stdcall *EDGEPROC)(pENTREC pEntRec);
#define EEdge _EEdge
BOOL _stdcall EEdge(pENTREC pEntRec,EDGEPROC EdgeProc);
#define EOffset _EOffset
pENTREC _stdcall EOffset(pENTREC pEntRec,float Distance);

#define NewTag _NewTag
void _stdcall NewTag(CSTUFF *CStuff);
#define MarkChanged _MarkChanged
DWORD _stdcall MarkChanged(void);

#define GetTextSpecs _GetTextSpecs
void _stdcall GetTextSpecs(void *Text);
#define GetTextSpecsAlt _GetTextSpecsAlt
char _stdcall GetTextSpecsAlt(void *Text);

#define EPlace _EPlace
void *_stdcall EPlace(pENTREC pEntRec,CTRLP *pCtrlP);
#endif
