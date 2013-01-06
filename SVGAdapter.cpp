#include "fcw2svgxp.h"

#include "fcw2svg-0.2/Fcw.h"

using bcholmes::fcw2svg::Fcw;

static DWORD XPCALL SaveSVGScan(hDLIST hDList, pENTREC pEntRec, void *node_handle, PARM parm2)
{
	Fcw* fcw = (Fcw*) node_handle;
	fcw->addEntity(pEntRec);

	switch(pEntRec->CStuff.EType)
	{
		case ET_MPOLY2:
		case ET_SYMDEF:
		case ET_SYMREF:
		case ET_PART:
		case ET_SHEET:
			{
				fcw->startSubList();
				hDLIST hSubList = DLGetSubList(pEntRec);
				if (hSubList != NULL) {
					DLScan(hSubList, SaveSVGScan, DLS_UNLK | DLS_NOWDC, node_handle, 0);
				}
				fcw->endSubList();
				
				break;
			}
		default:
			;

	}
	return 0;
}

int SaveSVG(char *FileName)
{
	Fcw fcw("", FileName);
	HDR* hdr = GetHeaderAdr();
	fcw.addInfoBlock(hdr);
	DLScan(NULL, SaveSVGScan, DLS_SHEET , (void *)&fcw, 0);

	DLScan(NULL, SaveSVGScan, DLS_RO, (void *)&fcw, 0);
	fcw.toSvg();
	return true;
}

