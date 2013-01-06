//////// _XPMSG.H - XPMessage ID #s - FastCAD-32 XP include file /////////
//
//	(C)1998 Evolution Computing
//	All rights reserved
//
//////////////////////////////////////////////////////////////////////////

#ifndef _XPMSG_H_
#define _XPMSG_H_

#define XPM_AllLoaded				1	// all XPs have been loaded
#define XPM_BeforeSave			2	// about to save drawing
#define XPM_AfterLoad				3	// after drawing load/new
#define XPM_ImportECW				4	// ECW imported
#define XPM_ImportFCD				5	// FCD imported
#define XPM_Import					6	// after import of drawing by
															//  any import filter. The specific
															//  type message has already been
															//  sent by the filter function.
#define XPM_Undo						7	// undo command starting
															// selected ents will toggle erase
#define XPM_Parts						8	// one or more parts have been inserted
#define XPM_DwgUpdate				9	// an old format dwg will be updated
															// esi = old DBVERSION #
															// edi = target DBVERSION #
#define XPM_BeforeCmd			 10	// a new command is about to be executed
															// esi -> new command
#define XPM_BkgndChg			 11	// background color changed
#define XPM_AfterCmd			 12	// a command has finished
#define XPM_CurColorChg		 13	// current color changed
#define XPM_AddMenu				 14	// SVC AddMenu May be called
#define XPM_SetMarkers		 16	// set menu marker commands now
#define XPM_InterCom			 17	// InterCom message pass-thru
#define XPM_Quiting				 18	// program is quitting
#define XPM_Guide					 19	// start guide file name at ESI
#define XPM_DLDESTROY			 20	// ESI = hDL about to be destroyed


#define XPID_Guide			0x0021	// XPID of GUIDE
#define XPID_SymCat			0x0022	// XPID of SYMCAT
#define XPID_ASave		  0x0023	// XPID of ASAVE

// Custom entity support

#define XPEDraw		   0  // Draw
#define	XPEPick	 	   1  // Pick test
#define	XPEXCheck	   2  // Extent-check
#define	XPETran		   3  // Transform
#define	XPENUTran	   4  // N. U. Transform
#define	XPEMirror	   5  // Mirror
#define	XPEStretch	 6  // Stretch
#define	XPEClass	   7  // Class
#define	XPEInfo		   8  // Info
#define	XPEList		   9  // List
#define	XPEEdit		  10  // Edit
#define	XPEDynEd	  11  // Dyn Edit
#define	XPETrim		  12  // Trim
#define	XPECut		  13  // Cut
#define	XPEExplode  14  // Explode
#define	XPEActuate  15  // Actuate
#define	XPEAttach   16  // Attach
#define	XPEPt2nearT	17  // point to nearest T
#define	XPET2Pt		  18  // T to point
#define	XPES2T		  19  // S to T
#define	XPET2S		  20  // T to S
#define	XPETangent	21  // Tangent
#define	XPERay		  22  // Ray intersection
#define	XPECurv		  23  // Curvature
#define	XPEOffset		24  // Offset
#define	XPEL2Edge		25  // Specify Multipoly Edges
#define	XPEPlace		26  // Place

#define	XPERender		27  // OpenGL Render Entity
#define	XPEPt3nearT	28  // point to nearest T (3d)
#define	XPET3Pt		  29  // T to point (3d)
#define	XPEL2Edge3	30  // 3d edge gen

void _stdcall ENoSupp(void);

#endif
