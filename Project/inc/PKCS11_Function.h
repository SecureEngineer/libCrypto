/**
 * @file:   PKCS11_Function.h
 * @brief   PKCS#11 �����ӿ�����ͷ�ļ�
 * @author  Li YaoLong
 * @date    2015/10/13
 * @version 1.0
 * <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
 * <pre><b>Email: </b>SecMaster@outlook.com</pre> 
 * <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
 * <pre><b>All rights reserved.</b></pre> 
 */

#ifndef PKCS11_FUNCTION_H
#define PKCS11_FUNCTION_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "PKCS11_DataType.h"

/*----------------------------------------------------------------------*
                         <<<������������>>>
*----------------------------------------------------------------------*/

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Initialize)(
	CK_VOID_PTR pInitArgs);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Finalize)(
	CK_VOID_PTR pReserved);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetInfo)(
	CK_INFO_PTR pInfo);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetFunctionList)(
	CK_FUNCTION_LIST_PTR_PTR ppFunctionList);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetSlotList)(
	CK_BBOOL tokenPresent, 
	CK_SLOT_ID_PTR pSlotList,
	CK_ULONG_PTR pulCount);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetSlotInfo)(
	CK_SLOT_ID slotID, 
	CK_SLOT_INFO_PTR pInfo);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetTokenInfo)(
	CK_SLOT_ID slotID,
	CK_TOKEN_INFO_PTR pInfo);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_WaitForSlotEvent)(
	CK_FLAGS flags,
	CK_SLOT_ID_PTR pSlot,
	CK_VOID_PTR pReserved);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetMechanismList)(
	CK_SLOT_ID slotID,
	CK_MECHANISM_TYPE_PTR pMechanismList,
	CK_ULONG_PTR pulCount);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetMechanismInfo)(
	CK_SLOT_ID slotID,
	CK_MECHANISM_TYPE type,
	CK_MECHANISM_INFO_PTR pInfo);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_InitToken)(
	CK_SLOT_ID slotID,
	CK_CHAR_PTR pszPin,
	CK_ULONG ulPinLen,
	CK_UTF8CHAR_PTR pLabel);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_InitPIN)(
	CK_SESSION_HANDLE hSession, 
	CK_CHAR_PTR pszPin, 
	CK_ULONG ulPinLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SetPIN)(
	CK_SESSION_HANDLE hSession,
	CK_CHAR_PTR pszOldPin,
	CK_ULONG ulOldLen,
	CK_CHAR_PTR pszNewPin,
	CK_ULONG ulNewLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_OpenSession)(
	CK_SLOT_ID slotID,
	CK_FLAGS flags,
	CK_VOID_PTR pApplication,
	CK_NOTIFY Notify,
	CK_SESSION_HANDLE_PTR phSession);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_CloseSession)(
	CK_SESSION_HANDLE hSession);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_CloseAllSessions)(
	CK_SLOT_ID slotID);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetSessionInfo)(
	CK_SESSION_HANDLE hSession,
	CK_SESSION_INFO_PTR pInfo);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetOperationState)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pbOperationState,
	CK_ULONG_PTR      pulOperationStateLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SetOperationState)(
	CK_SESSION_HANDLE   hSession, 
	CK_BYTE_PTR         pbOperationState,
	CK_ULONG            ulOperationStateLen,
	CK_OBJECT_HANDLE    hEncryptionKey,
	CK_OBJECT_HANDLE    hAuthenticationKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Login)(
	CK_SESSION_HANDLE hSession,
	CK_USER_TYPE      userType,
	CK_CHAR_PTR       pszPin,
	CK_ULONG          ulPinLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Logout)(
	CK_SESSION_HANDLE hSession);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_CreateObject)(
	CK_SESSION_HANDLE   hSession,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phObject);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_CopyObject)(
	CK_SESSION_HANDLE    hSession,
	CK_OBJECT_HANDLE     hObject,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phNewObject);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DestroyObject)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetObjectSize)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ULONG_PTR      pulSize);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetAttributeValue)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SetAttributeValue)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_FindObjectsInit)(
	CK_SESSION_HANDLE hSession,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_FindObjects)(
	CK_SESSION_HANDLE     hSession,
	CK_OBJECT_HANDLE_PTR  phObject,
	CK_ULONG              ulMaxObjectCount,
	CK_ULONG_PTR          pulObjectCount);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_FindObjectsFinal)(
	CK_SESSION_HANDLE hSession);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_EncryptInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Encrypt)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pbData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pbEncryptedData,
	CK_ULONG_PTR      pulEncryptedDataLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_EncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pbPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pbEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_EncryptFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pLastEncryptedPart,
	CK_ULONG_PTR      pulLastEncryptedPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DecryptInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Decrypt)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedData,
	CK_ULONG          ulEncryptedDataLen,
	CK_BYTE_PTR       pData,
	CK_ULONG_PTR      pulDataLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DecryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DecryptFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pLastPart,
	CK_ULONG_PTR      pulLastPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DigestInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Digest)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pDigest,
	CK_ULONG_PTR      pulDigestLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DigestUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DigestKey)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DigestFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pDigest,
	CK_ULONG_PTR      pulDigestLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SignInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Sign)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SignUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SignFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SignRecoverInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SignRecover)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_VerifyInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_Verify)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_VerifyUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_VerifyFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_VerifyRecoverInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_VerifyRecover)(
	CK_SESSION_HANDLE  hSession,
	CK_BYTE_PTR        pSignature,
	CK_ULONG           ulSignatureLen,
	CK_BYTE_PTR        pData,
	CK_ULONG_PTR       pulDataLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DigestEncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DecryptDigestUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SignEncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DecryptVerifyUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GenerateKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GenerateKeyPair)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_ATTRIBUTE_PTR     pPublicKeyTemplate,
	CK_ULONG             ulPublicKeyAttributeCount,
	CK_ATTRIBUTE_PTR     pPrivateKeyTemplate,
	CK_ULONG             ulPrivateKeyAttributeCount,
	CK_OBJECT_HANDLE_PTR phPublicKey,
	CK_OBJECT_HANDLE_PTR phPrivateKey);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_WrapKey)(
	CK_SESSION_HANDLE   hSession,
	CK_MECHANISM_PTR    pMechanism,
	CK_OBJECT_HANDLE    hWrappingKey,
	CK_OBJECT_HANDLE    hKey,
	CK_BYTE_PTR         pWrappedKey,
	CK_ULONG_PTR        pulWrappedKeyLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_UnwrapKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_OBJECT_HANDLE     hUnwrappingKey,
	CK_BYTE_PTR          pWrappedKey,
	CK_ULONG             ulWrappedKeyLen,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_DeriveKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_OBJECT_HANDLE     hBaseKey,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey);

typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_SeedRandom)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSeed,
	CK_ULONG          ulSeedLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GenerateRandom)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pRandomData,
	CK_ULONG          ulRandomLen);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_GetFunctionStatus)(
	CK_SESSION_HANDLE hSession);


typedef CK_DECLARE_FUNCTION_POINTER(CK_RV,CK_C_CancelFunction)(
	CK_SESSION_HANDLE hSession);

/*----------------------------------------------------------------------*
                           <<< �������� >>>
*----------------------------------------------------------------------*/
/**
 * @brief      ��ʼ���ӿڿ⣬�ú�����һ��������ֻ�ܱ�����һ�Σ�
 * @param[in]  pInitArgs
 * @return     CK_RV
 * @retval     CKR_ARGUMENTS_BAD -�����pInitArgsֵΪ�ǿ�ֵ��CK_C_INITIALIZE_ARGS�е�pReserved����NULL_PTRʱ���ظ�ֵ
 * @retval     CKR_CANT_LOCK     -��ǰ�ⲻ�᷵�ظ�ֵ
 * @retval     CKR_CRYPTOKI_ALREADY_INITIALIZED  -�ӿڿ��Ѿ���ʼ�����
 * @retval     CKR_FUNCTION_FAILED               -�������д���
 * @retval     CKR_GENERAL_ERROR                 -ͨ�ô���
 * @retval     CKR_HOST_MEMORY                   -�����ڴ治�㣬�����ڴ�ʧ��
 * @retval     CKR_NEED_TO_CREATE_THREADS        -��ǰ�ⲻ�᷵�ظ�ֵ
 * @retval     CKR_OK
 */
CK_DECLARE_FUNCTION(CK_RV, C_Initialize)(
	CK_VOID_PTR pInitArgs);

/**
 * @brief      �ͷŶ�̬���ӿ⣬���øú���֮�󣬸ý��̵����������̶߳�����ɹ�����Cryptoki������
 * @param[in]  pReserved
 * @return     CK_RV
 * @retval     CKR_ARGUMENTS_BAD -�����������
 * @retval     CKR_CRYPTOKI_NOT_INITIALIZED -û�г�ʼ����������ͷŲ���
 * @retval     CKR_OK -����ִ����ȷ
 */
CK_DECLARE_FUNCTION(CK_RV, C_Finalize)(
	CK_VOID_PTR pReserved);

/**
 * @brief      �����й�Cryptoki��ͨ����Ϣ��pInfoָ�������Ϣ��Ԫ
 * @param[out] pInfo
 * @retval     CK_RV
 * @retval     CKR_ARGUMENTS_BAD --�����������
 * @retval     CKR_CRYPTOKI_NOT_INITIALIZED --û�г�ʼ����������ͷŲ���
 * @retval     CKR_FUNCTION_FAILED --����ִ��ʧ��
 * @retval     CKR_GENERAL_ERROR --����ͨ�ô���
 * @retval     CKR_HOST_MEMORY   --�����ڴ����
 * @retval     CKR_OK -����ִ����ȷ
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetInfo)(
	CK_INFO_PTR pInfo);

/**
 * @brief      �����й�Cryptoki�ĺ����б�ָ��
 * @param[out] CK_INFO_PTR pInfo
 * @return     CK_RV
 * @retval     CKR_ARGUMENTS_BAD --�����������
 * @retval     CKR_FUNCTION_FAILED --����ִ��ʧ��
 * @retval     CKR_GENERAL_ERROR --����ͨ�ô���
 * @retval     CKR_HOST_MEMORY   --�����ڴ����
 * @retval     CKR_OK -����ִ����ȷ
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetFunctionList)(
	CK_FUNCTION_LIST_PTR_PTR ppFunctionList);

/**
 * @brief      ���ڻ��ϵͳ�е�һ�����б�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetSlotList)(
	CK_BBOOL       tokenPresent,
	CK_SLOT_ID_PTR pSlotList,
	CK_ULONG_PTR   pulCount);

/**
 * @brief      ���ϵͳ���й�һ���ض��۵���Ϣ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetSlotInfo)(
	CK_SLOT_ID       slotID,
	CK_SLOT_INFO_PTR pInfo);

/**
 * @brief      ���ϵͳ���й�һ���ض��۵���Ϣ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetTokenInfo)(
	CK_SLOT_ID        slotID,
	CK_TOKEN_INFO_PTR pInfo);

/**
 * @brief      �ȴ�һ�����¼��ķ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_WaitForSlotEvent)(
	CK_FLAGS       flags,
	CK_SLOT_ID_PTR pSlot,
	CK_VOID_PTR    pReserved);
/**
 * @brief      ���ڻ�ȡ��һ��������֧�ֵĻ��������б�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetMechanismList)(
	CK_SLOT_ID            slotID,
	CK_MECHANISM_TYPE_PTR pMechanismList,
	CK_ULONG_PTR          pulCount);

/**
 * @brief      ��ȡ������һ������֧�ֵ�һ���ض����Ƶ���Ϣ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetMechanismInfo)(
	CK_SLOT_ID            slotID,
	CK_MECHANISM_TYPE     type,
	CK_MECHANISM_INFO_PTR pInfo);

/**
 * @brief      ��ʼ��һ������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_InitToken)(
	CK_SLOT_ID      slotID,
	CK_CHAR_PTR     pPin,
	CK_ULONG        ulPinLen,
	CK_UTF8CHAR_PTR pLabel);

/**
 * @brief      ��ʼ����ͨ�û���PIN.
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_InitPIN)(
	CK_SESSION_HANDLE hSession,
	CK_CHAR_PTR       pPin,
	CK_ULONG          ulPinLen);
/**
 * @brief      �޸�Ŀǰע����û���PIN
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SetPIN)(
	CK_SESSION_HANDLE hSession,
	CK_CHAR_PTR       pOldPin,
	CK_ULONG          ulOldLen,
	CK_CHAR_PTR       pNewPin,
	CK_ULONG          ulNewLen);
/**
 * @brief      ��ĳһ�ض�����Ӧ�ú����Ƽ�ĶԻ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_OpenSession)(
	CK_SLOT_ID            slotID,
	CK_FLAGS              flags,
	CK_VOID_PTR           pApplication,
	CK_NOTIFY             Notify,
	CK_SESSION_HANDLE_PTR phSession);
/**
 * @brief      �ر�Ӧ�ú����Ƽ��ĶԻ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CloseSession)(
	CK_SESSION_HANDLE hSession);

/**
 * @brief      �ر�һ��Ӧ�����еĴ����ƵĶԻ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CloseAllSessions)(
	CK_SLOT_ID slotID);
/**
 * @brief      ����й�һ���Ի�����Ϣ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetSessionInfo)(
	CK_SESSION_HANDLE   hSession,
	CK_SESSION_INFO_PTR pInfo);

/**
 * @brief      ��öԻ��������״̬�ĸ����������һ���ֽ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetOperationState)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pOperationState,
	CK_ULONG_PTR      pulOperationStateLen);

/**
 * @brief      ����C_GetOperationState ��õ�һ���ֽ��лָ�һ���Ի����������״̬
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SetOperationState)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pOperationState,
	CK_ULONG          ulOperationStateLen,
	CK_OBJECT_HANDLE  hEncryptionKey,
	CK_OBJECT_HANDLE  hAuthenticationKey);

/**
 * @brief      ��ÿ���û�ע��һ������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Login)(
	CK_SESSION_HANDLE hSession,
	CK_USER_TYPE      userType,
	CK_CHAR_PTR       pPin,
	CK_ULONG          ulPinLen);

/**
 * @brief      ���û���������ע��
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Logout)(CK_SESSION_HANDLE hSession);

/**
 * @brief      ������һ���µĶ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CreateObject)(
	CK_SESSION_HANDLE    hSession,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phObject);

/**
 * @brief      ����һ������Ϊ��������һ���µĶ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CopyObject)(
	CK_SESSION_HANDLE    hSession,
	CK_OBJECT_HANDLE     hObject,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phNewObject);

/**
 * @brief      ����һ������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DestroyObject)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject);

/**
 * @brief      ��ö����ֽڵĴ�С
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetObjectSize)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ULONG_PTR      pulSize);

/**
 * @brief      ��ö����һ����������ֵ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetAttributeValue)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount);

/**
 * @brief      �޸Ķ���һ���������Ե�ֵ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SetAttributeValue)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount);

/**
 * @brief      ������ƥ��ģ������ƺͶԻ��������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjectsInit)(
	CK_SESSION_HANDLE hSession,
	CK_ATTRIBUTE_PTR  pTemplate,
	CK_ULONG          ulCount);

/**
 * @brief      ������Ѱƥ��ģ������ƺͶԻ����󣬻�ø��ӵĶ�����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjects)(
	CK_SESSION_HANDLE    hSession,
	CK_OBJECT_HANDLE_PTR phObject,
	CK_ULONG             ulMaxObjectCount,
	CK_ULONG_PTR         pulObjectCount);
/**
 * @brief      ������Ѱ���ƺͶԻ�����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjectsFinal)(
	CK_SESSION_HANDLE hSession);

/**
 * @brief      ��ʼ��һ�����ܲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_EncryptInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      ���ܵ���������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Encrypt)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pEncryptedData,
	CK_ULONG_PTR      pulEncryptedDataLen);

/**
 * @brief      �����ಿ�ּ��ܲ�����������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_EncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen);

/**
 * @brief      ����һ�ζಿ�ּ��ܲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_EncryptFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pLastEncryptedPart,
	CK_ULONG_PTR      pulLastEncryptedPartLen);

/**
 * @brief      ����һ����ܲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      ���ܵ������еļ�������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Decrypt)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedData,
	CK_ULONG          ulEncryptedDataLen,
	CK_BYTE_PTR       pData,
	CK_ULONG_PTR      pulDataLen);

/**
 * @brief      ����һ��ಿ�ֵĽ��ܲ�����������һ���������ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen);

/**
 * @brief      �����ಿ�ֽ��ܲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pLastPart,
	CK_ULONG_PTR      pulLastPartLen);

/**
 * @brief      Ԥ����ϢժҪ����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism);

/**
 * @brief      ժҪ�������е�����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Digest)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pDigest,
	CK_ULONG_PTR      pulDigestLen);

/**
 * @brief      �����ಿ����ϢժҪ������������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen);

/**
 * @brief      ժҪ������Կֵ�������ಿ����ϢժҪ�Ĳ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestKey)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      �����ಿ����ϢժҪ������������ϢժҪ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pDigest,
	CK_ULONG_PTR      pulDigestLen);
/**
 * @brief      Ԥ��ǩ������������ǩ�������ݵĸ�¼
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SignInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);
/**
 * @brief      ���������е�����ǩ��������ǩ�������ݵĸ�¼
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Sign)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen);

/**
 * @brief      �����ಿ��ǩ��������������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SignUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen);

/**
 * @brief      �����ಿ��ǩ������������ǩ��
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SignFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen );

/**
 * @brief      Ԥ��ǩ�����������������ܴ�ǩ���лָ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SignRecoverInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      ����һ�����е�����ǩ�����������ݿ���ǩ���лָ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SignRecover)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG_PTR      pulSignatureLen);

/**
 * @brief      Ԥ��У�����������ǩ�������ݵĸ�¼
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      У�鵥���ֲ����е�ǩ��������ǩ�������ݵĸ�¼
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Verify)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pData,
	CK_ULONG          ulDataLen,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen);

/**
 * @brief      ����һ���ಿ�ֵ�У�������������һ���ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen);

/**
 * @brief      ����һ�ζಿ��У��������˲�ǩ�� 
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyFinal)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen);

/**
 * @brief      Ԥ��ǩ��У��������������ݴ�ǩ�ָֻ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyRecoverInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      У�鵥���ֲ����е�ǩ�֣��������ݴ�ǩ���лָ�
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_VerifyRecover)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSignature,
	CK_ULONG          ulSignatureLen,
	CK_BYTE_PTR       pData,
	CK_ULONG_PTR      pulDataLen);

/**
 * @brief      �������жಿ�ֵ�ժҪ�ͼ��ܲ�����������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestEncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen);

/**
 * @brief      �����ಿ�ֺϲ��Ľ��ܺ�ժҪ������������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptDigestUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen);

/**
 * @brief      ����һ���ಿ�ֽ�ϵ�ǩ���ͼ��ܲ�����������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SignEncryptUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pPart,
	CK_ULONG          ulPartLen,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG_PTR      pulEncryptedPartLen);

/**
 * @brief      ����һ���ಿ�ֽ�ϵĽ��ܺ�У�������������һ�����ݲ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DecryptVerifyUpdate)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pEncryptedPart,
	CK_ULONG          ulEncryptedPartLen,
	CK_BYTE_PTR       pPart,
	CK_ULONG_PTR      pulPartLen);

/**
 * @brief      ����һ��������Կ������һ���µ���Կ����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GenerateKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulCount,
	CK_OBJECT_HANDLE_PTR phKey);

/**
 * @brief      ����һ������/˽Կ�ԣ������µ���Կ����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GenerateKeyPair)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,			  
	CK_ATTRIBUTE_PTR     pPublicKeyTemplate,
	CK_ULONG             ulPublicKeyAttributeCount,
	CK_ATTRIBUTE_PTR     pPrivateKeyTemplate,
	CK_ULONG             ulPrivateKeyAttributeCount,
	CK_OBJECT_HANDLE_PTR phPublicKey,
	CK_OBJECT_HANDLE_PTR phPrivateKey);

/**
 * @brief      ��� (��., ����) һ��˽�л�����Կ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_WrapKey)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism,
	CK_OBJECT_HANDLE  hWrappingKey,
	CK_OBJECT_HANDLE  hKey,
	CK_BYTE_PTR       pWrappedKey,
	CK_ULONG_PTR      pulWrappedKeyLen);

/**
 * @brief      ������������ܣ�һ�������Կ������һ���µ�˽Կ��������Կ����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_UnwrapKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_OBJECT_HANDLE     hUnwrappingKey,
	CK_BYTE_PTR          pWrappedKey,
	CK_ULONG             ulWrappedKeyLen,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey);

/**
 * @brief      �ӻ�����Կ��������һ����Կ������һ���µ���Կ����
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DeriveKey)(
	CK_SESSION_HANDLE    hSession,
	CK_MECHANISM_PTR     pMechanism,
	CK_OBJECT_HANDLE     hBaseKey,
	CK_ATTRIBUTE_PTR     pTemplate,
	CK_ULONG             ulAttributeCount,
	CK_OBJECT_HANDLE_PTR phKey);

/**
 * @brief      �����ӵ����Ӳ��ϻ������Ƶ������������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_SeedRandom)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pSeed,
	CK_ULONG          ulSeedLen);

/**
 * @brief      ���������α���������
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GenerateRandom)(
	CK_SESSION_HANDLE hSession,
	CK_BYTE_PTR       pRandomData,
	CK_ULONG          ulRandomLen);

/**
 * @brief      ��һ����ͳ������ֻ�ܷ��� CKR_FUNCTION_NOT_PARALLELֵ
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetFunctionStatus)(
	CK_SESSION_HANDLE hSession);

/**
 * @brief      ȡ����Ӧ�ò������еĺ���
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CancelFunction)(
	CK_SESSION_HANDLE hSession);


#ifdef __cplusplus
}
#endif

#endif