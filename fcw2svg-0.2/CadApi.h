#ifndef __CADAPI_H
#define __CADAPI_H



#ifdef _WIN32
#include "_estruc.h"
#include "_HEADER.H"
#include "_ibmgr.h"
#include "_fstyles.h"

#ifndef IBHDR
#define IBHDR HDR
#endif

#else
#include <stdint.h>
#define WORD int16_t
#define DWORD int32_t
#define BYTE char
#include "estruct.h"
#pragma pack(1)
#include "ibmgr.h"
#include "XP/_HEADER.H"
#include "XP/_fstyles.h"
#endif
#pragma pack()



#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#endif