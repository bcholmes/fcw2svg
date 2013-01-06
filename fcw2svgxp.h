#pragma pack(1)

#include <windows.h>

#pragma warning(disable: 4200)

extern "C" 
{  
	#include <xp.h>
}

#define XPID 0xF000
extern XP MyXP;


// SaveSVG.cpp
int SaveSVG(char *FileName);
