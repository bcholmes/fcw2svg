/////////////////////////////////FCW2SVGXP/////////////////////////////
//  Writen By: BC Holmes
///////////////////////////////////////////////////////////////////////	
#include <windows.h>
#include "fcw2svgxp.h"

extern "C" void _stdcall FullFileName(void);

#define XPID 0xF000

void XPCALL About(void);
void XPCALL ExportAsSVG(void);

char CList[]="\0";
PCMDPROC PList[]={About, };

XP MyXP = {0, CList, PList, 0, 0, 0, XPID, 0, 500, 0, 0, 500};

/////////////  DllMain - XP initialization & Unload code //////////////
BOOL WINAPI DllMain (HINSTANCE hDLL, DWORD dwReason, LPVOID lpReserved)
{ 
	switch (dwReason)
	{ 
		case DLL_PROCESS_ATTACH:
			MyXP.ModHdl=hDLL;
			XPRegCmd(&MyXP);
			XPRegExport(ExportAsSVG, "SVG File", "SVG");
			break;
		case DLL_PROCESS_DETACH:
			XPUnregCmd(&MyXP);
			break;
	}
	return TRUE;
}
///////////////////////////////////////////////////////////////////////


/////////////////////////// About information /////////////////////////
FORMST(MyAPkt,"CC2 XP\n\n\tSAVEAS - Save a drawing as SVG\n")

void XPCALL About (void)
{
	FormSt(&MyAPkt,RSC(FD_MsgBox));
}
///////////////////////////////////////////////////////////////////////


//////////////////////////////// The command //////////////////////////
void XPCALL ExportAsSVG(void)
{
	char FileName[260];

	//
	/// Convert current filename to full path (no # or $)
	//

	// This call does not protect ebx, esi & edi which is needed for _stdcall calling convention. Save them on the stack manually.

	__asm push ebx; 
	__asm push esi; 
	__asm push edi; 

	__asm mov esi, RSC_CurSaveName;
	__asm lea edi, FileName;
	FullFileName();

	__asm pop edi; 
	__asm pop esi; 
	__asm pop ebx; 


	SaveSVG(FileName);
	CmdEnd();
}
///////////////////////////////////////////////////////////////////////