/**
 * @file:   PKCS11_Function.cpp
 * @brief   PKCS#11 接口定义源文件
 * @author  Li YaoLong
 * @date    2015/10/13
 * @version 1.0
 * <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
 * <pre><b>Email: </b>SecMaster@outlook.com</pre> 
 * <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
 * <pre><b>All rights reserved.</b></pre> 
 */
#include "..\inc\Crypto.h"
#include "..\inc\Slot.h"

/**
 * Cryptoki接口库版本
 */
CK_VERSION cryptokiVersion = {0x02,0x0b};

/**
 * cryptoki库版本
 */
CK_VERSION libraryVersion = {0x00,0x01};

CK_FUNCTION_LIST gFunctionList = 
{
	cryptokiVersion,
	C_Initialize,
	C_Finalize,
	C_GetInfo,
	C_GetFunctionList,
	C_GetSlotList,
 	C_GetSlotInfo,
 	C_GetTokenInfo,
 	C_GetMechanismList,
 	C_GetMechanismInfo,
 	C_InitToken,
 	C_InitPIN,
 	C_SetPIN,
 	C_OpenSession,
 	C_CloseSession,
 	C_CloseAllSessions,
 	C_GetSessionInfo,
 	C_GetOperationState,
 	C_SetOperationState,
 	C_Login,
 	C_Logout,
 	C_CreateObject,
 	C_CopyObject,
 	C_DestroyObject,
 	C_GetObjectSize,
 	C_GetAttributeValue,
 	C_SetAttributeValue,
 	C_FindObjectsInit,
 	C_FindObjects,
 	C_FindObjectsFinal,
 	C_EncryptInit,
 	C_Encrypt,
 	C_EncryptUpdate,
 	C_EncryptFinal,
 	C_DecryptInit,
 	C_Decrypt,
 	C_DecryptUpdate,
 	C_DecryptFinal,
 	C_DigestInit,
 	C_Digest,
 	C_DigestUpdate,
 	C_DigestKey,
 	C_DigestFinal,
 	C_SignInit,
 	C_Sign,
 	C_SignUpdate,
 	C_SignFinal,
 	C_SignRecoverInit,
 	C_SignRecover,
 	C_VerifyInit,
 	C_Verify,
 	C_VerifyUpdate,
 	C_VerifyFinal,
 	C_VerifyRecoverInit,
 	C_VerifyRecover,
 	C_DigestEncryptUpdate,
 	C_DecryptDigestUpdate,
 	C_SignEncryptUpdate,
 	C_DecryptVerifyUpdate,
 	C_GenerateKey,
 	C_GenerateKeyPair,
 	C_WrapKey,
 	C_UnwrapKey,
 	C_DeriveKey,
 	C_SeedRandom,
 	C_GenerateRandom,
 	C_GetFunctionStatus,
 	C_CancelFunction,
 	C_WaitForSlotEvent,
};

CK_DEFINE_FUNCTION(CK_RV,C_Initialize)(
	CK_VOID_PTR pInitArgs)
{
	CCrypto *pCrypto = CCrypto::GetInstance();

	return pCrypto->Initialize(pInitArgs);
}


CK_DEFINE_FUNCTION(CK_RV,C_Finalize)(
	CK_VOID_PTR pReserved)
{
	CCrypto *pCrypto = CCrypto::GetInstance();

	return pCrypto->Finalize(pReserved);
}

CK_DEFINE_FUNCTION(CK_RV,C_GetInfo)(
	CK_INFO_PTR pInfo)
{
	CCrypto *pCrypto = CCrypto::GetInstance();

	return pCrypto->GetInfo(pInfo);
}

CK_DEFINE_FUNCTION(CK_RV,C_GetFunctionList)(
	CK_FUNCTION_LIST_PTR_PTR ppFunctionList)
{
	CK_RV  ckRetVal = CKR_OK;

	if (!ppFunctionList)
	{
		ckRetVal = CKR_ARGUMENTS_BAD;
	}
	else
	{
		*ppFunctionList = &gFunctionList;
	}
	return ckRetVal;
}

CK_DEFINE_FUNCTION(CK_RV,C_GetSlotList)(
	CK_BBOOL       tokenPresent,
	CK_SLOT_ID_PTR pSlotList,
	CK_ULONG_PTR   pulCount)
{
	int        i = 0;
	int        nCount = 0;
	CK_RV      ckRetVal = CKR_OK;
	CCrypto*   pCrypto = CCrypto::GetInstance();
	CSlotList* pList = CSlotList::GetInstance();
	

	if (!pCrypto->GetInitFlag())
	{
		//密码库未初始化
		ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
	}
	else 
	{
		if(pSlotList)
		{
			if (pulCount)
			{
				nCount = pList->GetCount();

				if ((int)(*pulCount) >= nCount)
				{
					for(i = 0;i < nCount;i++)
					{
						pSlotList[i] = pList->GetSlot(i).GetID();
					}
				}
				else
				{
					ckRetVal = CKR_BUFFER_TOO_SMALL;
				}
			}
			else
			{
				//参数错误
				ckRetVal = CKR_ARGUMENTS_BAD;
			}
		}
		else
		{
			if(pulCount)
			{
				*pulCount = pList->GetCount();
			}
			else
			{
				//参数错误
				ckRetVal = CKR_ARGUMENTS_BAD;
			}
		}
	}
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetSlotInfo)(
	CK_SLOT_ID       slotID,
	CK_SLOT_INFO_PTR pInfo)
{
	bool       bFind = false;
	int        i = 0;
	CK_RV      ckRetVal = CKR_OK;	
	CCrypto*   pCrypto = CCrypto::GetInstance();
	CSlotList* pSlotList = CSlotList::GetInstance();
	
	if (!pCrypto->GetInitFlag())
	{
		//密码库未初始化
		ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
	}
	else
	{
		if(pInfo)
		{
			for(i = 0;i < pSlotList->GetCount();i++)
			{
				if(slotID == pSlotList->GetSlot(i).GetID())
				{
					*pInfo = pSlotList->GetSlot(slotID).GetInfo();
					bFind = true;
				}
			}
			if(!bFind)
			{
				ckRetVal = CKR_SLOT_ID_INVALID;
			}
		}
		else
		{
			ckRetVal = CKR_ARGUMENTS_BAD;
		}
	}
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetTokenInfo)(
	CK_SLOT_ID        slotID,
	CK_TOKEN_INFO_PTR pInfo)
{
	bool       bFind = false;
	int        i = 0;
	CK_RV      ckRetVal = CKR_OK;
	CCrypto*   pCrypto = CCrypto::GetInstance();
	CSlotList* pSlotList = CSlotList::GetInstance();
	if (!pCrypto->GetInitFlag())
	{
		//密码库未初始化
		ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
	}
	else
	{
		if(pInfo)
		{
			for(i = 0;i < pSlotList->GetCount();i++)
			{
				if(slotID == pSlotList->GetSlot(i).GetID())
				{
					*pInfo = pSlotList->GetSlot(slotID).GetTokenInfo();
					bFind = true;
				}
			}
			if(!bFind)
			{
				ckRetVal = CKR_SLOT_ID_INVALID;
			}
		}
		else
		{
			ckRetVal = CKR_ARGUMENTS_BAD;
		}
	}
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_WaitForSlotEvent)(
	CK_FLAGS       flags,
	CK_SLOT_ID_PTR pSlot,
	CK_VOID_PTR    pReserved)
{
	bool       bFind = false;
	int        i = 0;
	CK_RV      ckRetVal = CKR_OK;
	CCrypto*   pCrypto = CCrypto::GetInstance();
	CSlotList* pSlotList = CSlotList::GetInstance();
	if (!pCrypto->GetInitFlag())
	{
		//密码库未初始化
		ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
	}
	else
	{
		//空代码
	}
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetMechanismList)(
	CK_SLOT_ID            slotID,
	CK_MECHANISM_TYPE_PTR pMechanismList,
	CK_ULONG_PTR          pulCount)
{
	bool       bFind = false;
	int        i = 0;
	CK_RV      ckRetVal = CKR_OK;
	CCrypto*   pCrypto = CCrypto::GetInstance();
	CSlotList* pSlotList = CSlotList::GetInstance();
	if (!pCrypto->GetInitFlag())
	{
		//密码库未初始化
		ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
	}
	else
	{
		for(i = 0;i < pSlotList->GetCount();i++)
		{
			if(slotID == pSlotList->GetSlot(i).GetID())
			{
				bFind = true;
			}
		}
		if(!bFind)
		{
			ckRetVal = CKR_SLOT_ID_INVALID;
		}
		else
		{
			if(!pMechanismList)
			{
				if(pulCount)
				{
					*pulCount = 0;
				}
				else
				{
					ckRetVal = CKR_ARGUMENTS_BAD;
				}	
			}
			else
			{
				if(pulCount)
				{
					if(*pulCount >= 0)
					{

					}
					else
					{
						ckRetVal = CKR_BUFFER_TOO_SMALL;
					}
				}
				else
				{
					ckRetVal = CKR_ARGUMENTS_BAD;
				}	
			}
			
		}
		
	}
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetMechanismInfo)(
	CK_SLOT_ID            slotID,
	CK_MECHANISM_TYPE     type,
	CK_MECHANISM_INFO_PTR pInfo)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_InitToken)(
	CK_SLOT_ID      slotID,
	CK_CHAR_PTR     pPin,
	CK_ULONG        ulPinLen,
	CK_UTF8CHAR_PTR pLabel)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_InitPIN)(
	CK_SESSION_HANDLE hSession,
	CK_CHAR_PTR       pPin,
	CK_ULONG          ulPinLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SetPIN)(
	CK_SESSION_HANDLE hSession,
	CK_CHAR_PTR       pOldPin,
	CK_ULONG          ulOldLen,
	CK_CHAR_PTR       pNewPin,
	CK_ULONG          ulNewLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_OpenSession)(
	CK_SLOT_ID            slotID,
	CK_FLAGS              flags,
	CK_VOID_PTR           pApplication,
	CK_NOTIFY             Notify,
	CK_SESSION_HANDLE_PTR phSession)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_CloseSession)(
	CK_SESSION_HANDLE hSession)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_CloseAllSessions)(
	CK_SLOT_ID slotID)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetSessionInfo)(
	CK_SESSION_HANDLE   hSession,
	CK_SESSION_INFO_PTR pInfo)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetOperationState)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pOperationState,
	CK_ULONG_PTR      pulOperationStateLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SetOperationState)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pOperationState,
	CK_ULONG          ulOperationStateLen,
	CK_OBJECT_HANDLE  hEncryptionKey,
	CK_OBJECT_HANDLE  hAuthenticationKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_Login)(
	CK_SESSION_HANDLE hSession,
	CK_USER_TYPE      userType,
	CK_CHAR_PTR       pPin,
	CK_ULONG          ulPinLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_Logout)(
	CK_SESSION_HANDLE hSession)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_CreateObject)(
	CK_SESSION_HANDLE    hSession,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phObject)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_CopyObject)(
	CK_SESSION_HANDLE    hSession,
	CK_OBJECT_HANDLE     hObject,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phNewObject)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DestroyObject)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetObjectSize)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ULONG_PTR      pulSize)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetAttributeValue)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SetAttributeValue)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_FindObjectsInit)(
	CK_SESSION_HANDLE hSession,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_FindObjects)(
	CK_SESSION_HANDLE    hSession,
	CK_OBJECT_HANDLE_PTR phObject,
	CK_ULONG             ulMaxObjectCount,
	CK_ULONG_PTR         pulObjectCount)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_FindObjectsFinal)(
	CK_SESSION_HANDLE hSession)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_EncryptInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_Encrypt)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pEncryptedData,
	CK_ULONG_PTR      pulEncryptedDataLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_EncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_EncryptFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pLastEncryptedPart,
	CK_ULONG_PTR      pulLastEncryptedPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DecryptInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_Decrypt)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedData,
	CK_ULONG          ulEncryptedDataLen,
	CK_BYTE_PTR       pData,
	CK_ULONG_PTR      pulDataLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DecryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DecryptFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pLastPart,
	CK_ULONG_PTR      pulLastPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DigestInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_Digest)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pDigest,
	CK_ULONG_PTR      pulDigestLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DigestUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DigestKey)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DigestFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pDigest,
	CK_ULONG_PTR      pulDigestLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SignInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}

CK_DEFINE_FUNCTION(CK_RV,C_Sign)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SignUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SignFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen )
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SignRecoverInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SignRecover)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_VerifyInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_Verify)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_VerifyUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_VerifyFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_VerifyRecoverInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_VerifyRecover)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen,
	CK_BYTE_PTR       pData,
	CK_ULONG_PTR      pulDataLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DigestEncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DecryptDigestUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SignEncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}



CK_DEFINE_FUNCTION(CK_RV,C_DecryptVerifyUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GenerateKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GenerateKeyPair)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_ATTRIBUTE_PTR     pPublicKeyTemplate,
	CK_ULONG             ulPublicKeyAttributeCount,
	CK_ATTRIBUTE_PTR     pPrivateKeyTemplate,
	CK_ULONG             ulPrivateKeyAttributeCount,
	CK_OBJECT_HANDLE_PTR phPublicKey,
	CK_OBJECT_HANDLE_PTR phPrivateKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_WrapKey)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hWrappingKey,
	CK_OBJECT_HANDLE  hKey,
	CK_BYTE_PTR       pWrappedKey,
	CK_ULONG_PTR      pulWrappedKeyLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_UnwrapKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_OBJECT_HANDLE     hUnwrappingKey,
	CK_BYTE_PTR          pWrappedKey,
	CK_ULONG             ulWrappedKeyLen,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_DeriveKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_OBJECT_HANDLE     hBaseKey,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_SeedRandom)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSeed,
	CK_ULONG          ulSeedLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GenerateRandom)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pRandomData,
	CK_ULONG          ulRandomLen)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_GetFunctionStatus)(
	CK_SESSION_HANDLE hSession)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}


CK_DEFINE_FUNCTION(CK_RV,C_CancelFunction)(
	CK_SESSION_HANDLE hSession)
{
	CK_RV ckRetVal = CKR_OK;
	return ckRetVal;
}