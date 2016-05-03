/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: Mutex.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\global.h"

const char pstrMutexName[] = {"FL-PKCS#11"};

/*******************************************************************************
* 函数名称 : pkcs11_CreateMutex
* 功能描述 : 创建互斥对象
* 参　　数 : CK_VOID_PTR_PTR ppMutex
* 返 回 值 : CK_RV
* 设计日期 : 2010年6月23日
* 修改日期 : 2010年6月23日
*******************************************************************************/
CK_RV PKCS11_CreateMutex(CK_VOID_PTR_PTR ppMutex)
{
	CK_RV ckRetVal = CKR_OK;
/*
	//局部变量
	HANDLE hMutex = NULL;

	if (ppMutex)
	{
		hMutex = OpenMutex(MUTEX_ALL_ACCESS,FALSE,pstrMutexName);

		if (hMutex)
		{//成功打开已经存在的互斥对象
			ckRetVal = CKR_OK;
		}
		else
		{//打开失败，则创建一个新的互斥对象
			hMutex = CreateMutex(NULL,FALSE,pstrMutexName);

			if (hMutex)
			{//创建互斥对象成功
				ckRetVal = CKR_OK;
			}
			else
			{//创建互斥对象失败
				ckRetVal = CKR_GENERAL_ERROR;
			}
		}

		*ppMutex = hMutex;
	}
	else
	{//传入参数非法
		ckRetVal = CKR_MUTEX_BAD;
	}
*/
	return ckRetVal;
}
/*******************************************************************************
* 函数名称 : pkcs11_DestroyMutex
* 功能描述 : 销毁互斥对象，注意：函数执行成功后需要将互斥对象置为NULL
* 参　　数 : CK_VOID_PTR pMutex
* 返 回 值 : CK_RV
* 设计日期 : 2010年6月23日
* 修改日期 : 2010年6月23日
*******************************************************************************/
CK_RV PKCS11_DestroyMutex(CK_VOID_PTR pMutex)
{
	CK_RV ckRetVal = CKR_OK;
/*
	if (pMutex)
	{
		if (CloseHandle(pMutex))
		{//关闭句柄成功
			ckRetVal = CKR_OK;
		}
		else
		{//关闭失败
			ckRetVal = CKR_GENERAL_ERROR;
		}
	}
	else
	{//传入的Mutex参数无效
		ckRetVal = CKR_MUTEX_BAD;
	}
*/
	return ckRetVal;
}
/*******************************************************************************
* 函数名称 : pkcs11_LockMutex
* 功能描述 : 锁定互斥对象
* 参　　数 : CK_VOID_PTR pMutex
* 返 回 值 : CK_RV
* 设计日期 : 2010年6月23日
* 修改日期 : 2010年6月23日
*******************************************************************************/
CK_RV PKCS11_LockMutex(CK_VOID_PTR pMutex)
{
	CK_RV ckRetVal = CKR_OK;
	CK_ULONG ulWaitResult = 0;
/*
	if (pMutex)
	{
		ulWaitResult = WaitForSingleObject(pMutex,INFINITE);

		if (ulWaitResult !=  WAIT_FAILED)
		{//
			if (ulWaitResult == WAIT_OBJECT_0)
			{//等待成功
				ckRetVal = CKR_OK;
			}
			else
			{
				ckRetVal = CKR_GENERAL_ERROR;
			}
		}
		else
		{//wait函数失败
			ckRetVal = CKR_GENERAL_ERROR;
		}
	}
	else
	{
		ckRetVal = CKR_MUTEX_BAD;
	}
*/
	return ckRetVal;
}
/*******************************************************************************
* 函数名称 : pkcs11_UnLockMutex
* 功能描述 : 释放互斥对象
* 参　　数 : CK_VOID_PTR pMutex
* 返 回 值 : CK_RV
* 设计日期 : 2010年6月23日
* 修改日期 : 2010年6月23日
*******************************************************************************/
CK_RV PKCS11_UnLockMutex(CK_VOID_PTR pMutex)
{
	CK_RV ckRetVal = CKR_OK;
/*
	if (pMutex)
	{
		if (ReleaseMutex(pMutex))
		{
			ckRetVal = CKR_OK;
		}
		else
		{
			ckRetVal = CKR_GENERAL_ERROR;
		}
	}
	else
	{
		ckRetVal = CKR_MUTEX_BAD;
	}
*/
	return ckRetVal;
}