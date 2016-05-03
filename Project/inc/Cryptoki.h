/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: Cryptoki.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef CRYPTOKI_H
#define CRYPTOKI_H
/***********************************包含头文件 ************************************/

/********************************** 常量及宏定义 **********************************/

#define CRYPTOKI_EXPORTS //编译Cryptoki时需要定义，其他不需要定义

#ifdef WIN16  //定义Windows 16平台下的编译选项
    
	#pragma pack(1)
	
	#define CK_PTR far *
	
	#define CK_DEFINE_FUNCTION(returnType, name) \
      returnType __export _far _pascal name
	
	#define CK_DECLARE_FUNCTION(returnType, name) \
      returnType __export _far _pascal name
	  
	#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
      returnType __export _far _pascal (* name)
	  
	#define CK_CALLBACK_FUNCTION(returnType, name) \
      returnType _far _pascal (* name)

#include "PKCS11.h"

#elif defined(WIN32)  //定义Windows 32位平台下的编译选项
    
	#pragma pack(push, cryptoki, 1)

	#define CK_IMPORT_SPEC __declspec(dllimport)

    #ifdef CRYPTOKI_EXPORTS
        #define CK_EXPORT_SPEC __declspec(dllexport) 
    #else
        #define CK_EXPORT_SPEC CK_IMPORT_SPEC 
    #endif

     /* Ensures the calling convention for Win32 builds */
    #define CK_CALL_SPEC __cdecl

    #define CK_PTR *

	#define CK_DEFINE_FUNCTION(returnType, name) \
	  returnType CK_EXPORT_SPEC CK_CALL_SPEC name
	  
	#define CK_DECLARE_FUNCTION(returnType, name) \
	  returnType CK_EXPORT_SPEC CK_CALL_SPEC name
	  
	#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
	  returnType CK_IMPORT_SPEC (CK_CALL_SPEC CK_PTR name)
	  
	#define CK_CALLBACK_FUNCTION(returnType, name) \
	  returnType (CK_CALL_SPEC CK_PTR name)

    #ifndef NULL_PTR
        #define NULL_PTR 0
    #endif

    #ifndef CK_FALSE
        #define CK_FALSE 0
    #endif

    #ifndef CK_TRUE
        #define CK_TRUE (!CK_FALSE)
    #endif
    
    #include "PKCS11.h"

    #pragma pack(pop, cryptoki)

#else  //定义类UNIX平台下的编译选项
    
	#define CK_PTR *

	#define CK_DEFINE_FUNCTION(returnType, name) \
	  returnType name
	  
	#define CK_DECLARE_FUNCTION(returnType, name) \
	  returnType name

	#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
	  returnType (* name)
	
	#define CK_CALLBACK_FUNCTION(returnType, name) \
	  returnType (* name)
	  
	#ifndef NULL_PTR
	    #define NULL_PTR 0
	#endif

#include "PKCS11.h"

#endif

#endif