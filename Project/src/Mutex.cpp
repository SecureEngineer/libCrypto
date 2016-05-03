/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
* �������� : pkcs11_CreateMutex
* �������� : �����������
* �Ρ����� : CK_VOID_PTR_PTR ppMutex
* �� �� ֵ : CK_RV
* ������� : 2010��6��23��
* �޸����� : 2010��6��23��
*******************************************************************************/
CK_RV PKCS11_CreateMutex(CK_VOID_PTR_PTR ppMutex)
{
	CK_RV ckRetVal = CKR_OK;
/*
	//�ֲ�����
	HANDLE hMutex = NULL;

	if (ppMutex)
	{
		hMutex = OpenMutex(MUTEX_ALL_ACCESS,FALSE,pstrMutexName);

		if (hMutex)
		{//�ɹ����Ѿ����ڵĻ������
			ckRetVal = CKR_OK;
		}
		else
		{//��ʧ�ܣ��򴴽�һ���µĻ������
			hMutex = CreateMutex(NULL,FALSE,pstrMutexName);

			if (hMutex)
			{//�����������ɹ�
				ckRetVal = CKR_OK;
			}
			else
			{//�����������ʧ��
				ckRetVal = CKR_GENERAL_ERROR;
			}
		}

		*ppMutex = hMutex;
	}
	else
	{//��������Ƿ�
		ckRetVal = CKR_MUTEX_BAD;
	}
*/
	return ckRetVal;
}
/*******************************************************************************
* �������� : pkcs11_DestroyMutex
* �������� : ���ٻ������ע�⣺����ִ�гɹ�����Ҫ�����������ΪNULL
* �Ρ����� : CK_VOID_PTR pMutex
* �� �� ֵ : CK_RV
* ������� : 2010��6��23��
* �޸����� : 2010��6��23��
*******************************************************************************/
CK_RV PKCS11_DestroyMutex(CK_VOID_PTR pMutex)
{
	CK_RV ckRetVal = CKR_OK;
/*
	if (pMutex)
	{
		if (CloseHandle(pMutex))
		{//�رվ���ɹ�
			ckRetVal = CKR_OK;
		}
		else
		{//�ر�ʧ��
			ckRetVal = CKR_GENERAL_ERROR;
		}
	}
	else
	{//�����Mutex������Ч
		ckRetVal = CKR_MUTEX_BAD;
	}
*/
	return ckRetVal;
}
/*******************************************************************************
* �������� : pkcs11_LockMutex
* �������� : �����������
* �Ρ����� : CK_VOID_PTR pMutex
* �� �� ֵ : CK_RV
* ������� : 2010��6��23��
* �޸����� : 2010��6��23��
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
			{//�ȴ��ɹ�
				ckRetVal = CKR_OK;
			}
			else
			{
				ckRetVal = CKR_GENERAL_ERROR;
			}
		}
		else
		{//wait����ʧ��
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
* �������� : pkcs11_UnLockMutex
* �������� : �ͷŻ������
* �Ρ����� : CK_VOID_PTR pMutex
* �� �� ֵ : CK_RV
* ������� : 2010��6��23��
* �޸����� : 2010��6��23��
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