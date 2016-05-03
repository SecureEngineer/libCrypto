/************************************************************************/
/* 
* Copyright (c) 2009-2010, ��ҫ��
* All rights reserved.
* File Name: Mutex.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef MUTEX_H
#define MUTEX_H

/***********************************����ͷ�ļ� ************************************/
#include "Global.h"
/*********************************** �������� **********************************/

CK_RV PKCS11_CreateMutex(CK_VOID_PTR_PTR ppMutex);

CK_RV PKCS11_DestroyMutex(CK_VOID_PTR pMutex);

CK_RV PKCS11_LockMutex(CK_VOID_PTR pMutex);

CK_RV PKCS11_UnLockMutex(CK_VOID_PTR pMutex);

#endif