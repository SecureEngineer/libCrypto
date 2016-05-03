#ifndef _DLLEXPORT_H_
#define _DLLEXPORT_H_

#define DLL
#ifdef DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT
#endif

#endif