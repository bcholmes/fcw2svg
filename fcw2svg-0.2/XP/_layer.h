//////// _LAYERS.H - Layers InfoBlock Structure /////////////////////
//
//	(C)1998 Evolution Computing
//	All rights reserved
//
/////////////////////////////////////////////////////////////////////

#ifndef _LAYER_H_
#define _LAYER_H_

#define CurLyrIBVer	1	// current version #

// 	Each layer has the following information:

typedef struct
{
	int RLen;		// = sizeof(LAYER)
	short ID;		// layer ID word
	short Flags;		// layer status flags
	short LSID;		// ID style for BYLAYER
	char LName[6];		// ANSIZ layer name (var length)
}LAYER;

typedef struct
{
	int RLen;		// = sizeof(LAYER0)
	short ID;		// layer ID word
	short flags;		// layer status flags
	short LSID;		// ID style for BYLAYER
	char LName[6];		// ANSIZ layer name ="MERGE",0
}LAYER0;


// 	The Layer Infoblock is:

// 		The LYRIB structure
// 		followed by 1 or more LAYER records
// 		followed by a dword NULL end of list marker

typedef struct
{
	int   ERLen;		// std info block header =SIZEOF(LYRIB)
	char  EType;	  	// EType = Info Block  	= ET_IB
	char  IType;		// IB type = Layers = IB_LAYER
	short Creator;		// XPID (0=core)
	int   AllocLen;	 	// allocation length (0=ERLen)
	short IBVer;		// LyrIB version id  = CurLyrIBVer
	short NextID;		// next ID to use  = 2
	LAYER Layers[1];
}LYRIB;

// 	the values for LAYER.flags are:

#define LF_Hide		 1	// hide layer flag
#define LF_Freeze	 2	// freeze layer flag
#define LF_Used		0x80	// layer is in use

// ===================================================================
// LayerFunctions
// ===================================================================

#define AskLayerHidden _AskLayerHidden
char _stdcall AskLayerHidden(int Layer);
#define AskLayerFrozen _AskLayerFrozen
char _stdcall AskLayerFrozen(int Layer);
#define GetLayerName _GetLayerName
char * _stdcall GetLayerName(int Layer);
#define GetLayerNr _GetLayerNr
int  _stdcall GetLayerNr(char *LayerName);
#define ChangeCurLayer _ChangeCurLayer
void _stdcall ChangeCurLayer(int LayerNr);
#define AddLayer _AddLayer
int _stdcall AddLayer(char *LayerName);

#endif
