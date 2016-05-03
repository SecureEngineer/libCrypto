/**
 * @file:   PKCS11_Function.h
 * @brief   PKCS#11 函数接口声明头文件
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
                         <<<声明函数类型>>>
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
                           <<< 函数定义 >>>
*----------------------------------------------------------------------*/
/**
 * @brief      初始化接口库，该函数在一个进程中只能被调用一次；
 * @param[in]  pInitArgs
 * @return     CK_RV
 * @retval     CKR_ARGUMENTS_BAD -传入的pInitArgs值为非空值，CK_C_INITIALIZE_ARGS中的pReserved不是NULL_PTR时返回该值
 * @retval     CKR_CANT_LOCK     -当前库不会返回该值
 * @retval     CKR_CRYPTOKI_ALREADY_INITIALIZED  -接口库已经初始化完毕
 * @retval     CKR_FUNCTION_FAILED               -函数运行错误
 * @retval     CKR_GENERAL_ERROR                 -通用错误
 * @retval     CKR_HOST_MEMORY                   -主机内存不足，申请内存失败
 * @retval     CKR_NEED_TO_CREATE_THREADS        -当前库不会返回该值
 * @retval     CKR_OK
 */
CK_DECLARE_FUNCTION(CK_RV, C_Initialize)(
	CK_VOID_PTR pInitArgs);

/**
 * @brief      释放动态链接库，调用该函数之后，该进程的其他所有线程都不会成功调用Cryptoki函数。
 * @param[in]  pReserved
 * @return     CK_RV
 * @retval     CKR_ARGUMENTS_BAD -输入参数错误
 * @retval     CKR_CRYPTOKI_NOT_INITIALIZED -没有初始化便进行了释放操作
 * @retval     CKR_OK -函数执行正确
 */
CK_DECLARE_FUNCTION(CK_RV, C_Finalize)(
	CK_VOID_PTR pReserved);

/**
 * @brief      返回有关Cryptoki的通用消息。pInfo指向接收信息单元
 * @param[out] pInfo
 * @retval     CK_RV
 * @retval     CKR_ARGUMENTS_BAD --输入参数错误
 * @retval     CKR_CRYPTOKI_NOT_INITIALIZED --没有初始化便进行了释放操作
 * @retval     CKR_FUNCTION_FAILED --函数执行失败
 * @retval     CKR_GENERAL_ERROR --函数通用错误
 * @retval     CKR_HOST_MEMORY   --主机内存错误
 * @retval     CKR_OK -函数执行正确
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetInfo)(
	CK_INFO_PTR pInfo);

/**
 * @brief      返回有关Cryptoki的函数列表指针
 * @param[out] CK_INFO_PTR pInfo
 * @return     CK_RV
 * @retval     CKR_ARGUMENTS_BAD --输入参数错误
 * @retval     CKR_FUNCTION_FAILED --函数执行失败
 * @retval     CKR_GENERAL_ERROR --函数通用错误
 * @retval     CKR_HOST_MEMORY   --主机内存错误
 * @retval     CKR_OK -函数执行正确
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetFunctionList)(
	CK_FUNCTION_LIST_PTR_PTR ppFunctionList);

/**
 * @brief      用于获得系统中的一个槽列表
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
 * @brief      获得系统中有关一个特定槽的信息
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetSlotInfo)(
	CK_SLOT_ID       slotID,
	CK_SLOT_INFO_PTR pInfo);

/**
 * @brief      获得系统中有关一个特定槽的信息
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetTokenInfo)(
	CK_SLOT_ID        slotID,
	CK_TOKEN_INFO_PTR pInfo);

/**
 * @brief      等待一个槽事件的发生
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
 * @brief      用于获取由一个令牌所支持的机制类型列表
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
 * @brief      获取可能由一个令牌支持的一个特定机制的信息
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
 * @brief      初始化一个令牌
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
 * @brief      初始化普通用户的PIN.
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
 * @brief      修改目前注册的用户的PIN
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
 * @brief      打开某一特定槽中应用和令牌间的对话
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
 * @brief      关闭应用和令牌见的对话
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CloseSession)(
	CK_SESSION_HANDLE hSession);

/**
 * @brief      关闭一个应用所有的带令牌的对话
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_CloseAllSessions)(
	CK_SLOT_ID slotID);
/**
 * @brief      获得有关一个对话的信息
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetSessionInfo)(
	CK_SESSION_HANDLE   hSession,
	CK_SESSION_INFO_PTR pInfo);

/**
 * @brief      获得对话密码操作状态的副本，编码成一串字节
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
 * @brief      从用C_GetOperationState 获得的一串字节中恢复一个对话的密码操作状态
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
 * @brief      将每个用户注册一个令牌
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
 * @brief      将用户从令牌中注销
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_Logout)(CK_SESSION_HANDLE hSession);

/**
 * @brief      创建了一个新的对象
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
 * @brief      拷贝一个对象，为拷贝创建一个新的对象
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
 * @brief      销毁一个对象
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DestroyObject)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hObject);

/**
 * @brief      获得对象字节的大小
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
 * @brief      获得对象的一个或多个属性值
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
 * @brief      修改对象一个或多个属性的值
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
 * @brief      启动对匹配模板的令牌和对话对象的搜
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
 * @brief      继续搜寻匹配模板的令牌和对话对象，获得附加的对象句柄
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
 * @brief      结束搜寻令牌和对话对象
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_FindObjectsFinal)(
	CK_SESSION_HANDLE hSession);

/**
 * @brief      初始化一个加密操作
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
 * @brief      加密单部分数据
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
 * @brief      继续多部分加密操作，处理另一个数据部分
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
 * @brief      结束一次多部分加密操作
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
 * @brief      启动一项解密操作
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
 * @brief      解密单部分中的加密数据
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
 * @brief      继续一项多部分的解密操作，处理另一个加密数据部分
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
 * @brief      结束多部分解密操作
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
 * @brief      预置消息摘要操作
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestInit)(
	CK_SESSION_HANDLE hSession,
	CK_MECHANISM_PTR  pMechanism);

/**
 * @brief      摘要单部分中的数据
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
 * @brief      继续多部分消息摘要操作，处理另一个数据部分
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
 * @brief      摘要保密密钥值，继续多部分消息摘要的操作
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_DigestKey)(
	CK_SESSION_HANDLE hSession,
	CK_OBJECT_HANDLE  hKey);

/**
 * @brief      结束多部分消息摘要操作，返回消息摘要
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
 * @brief      预置签名操作，其中签名是数据的附录
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
 * @brief      给单部分中的数据签名，其中签名是数据的附录
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
 * @brief      继续多部分签名操作，处理另一个数据部分
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
 * @brief      结束多部分签名操作，返回签名
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
 * @brief      预置签名操作，其中数据能从签名中恢复
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
 * @brief      给单一操作中的数据签名，其中数据可以签名中恢复
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
 * @brief      预置校验操作，其中签名是数据的附录
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
 * @brief      校验单部分操作中的签名，其中签名是数据的附录
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
 * @brief      继续一个多部分的校验操作，处理另一数据部分
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
 * @brief      结束一次多部分校验操作，核查签名 
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
 * @brief      预置签字校验操作，其中数据从签字恢复
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
 * @brief      校验单部分操作中的签字，其中数据从签字中恢复
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
 * @brief      继续进行多部分的摘要和加密操作，处理另一个数据部分
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
 * @brief      继续多部分合并的解密和摘要操作，处理另一个数据部分
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
 * @brief      继续一个多部分结合的签名和加密操作，处理另一个数据部分
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
 * @brief      继续一个多部分结合的解密和校验操作，处理另一个数据部分
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
 * @brief      产生一个保密密钥，创建一个新的密钥对象
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
 * @brief      生成一个公共/私钥对，创建新的密钥对象
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
 * @brief      打包 (即., 加密) 一个私有或保密密钥
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
 * @brief      解包（即，解密）一个打包密钥，创建一个新的私钥或秘密密钥对象
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
 * @brief      从基础密钥中衍生出一个密钥，创建一个新的密钥对象
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
 * @brief      将附加的种子材料混入令牌的随机数产生器
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
 * @brief      产生随机或伪随机的数据
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
 * @brief      是一个传统函数，只能返回 CKR_FUNCTION_NOT_PARALLEL值
 * @param[in]  
 * @param[out] 
 * @return     CK_RV
 * @retval     
 */
CK_DECLARE_FUNCTION(CK_RV, C_GetFunctionStatus)(
	CK_SESSION_HANDLE hSession);

/**
 * @brief      取消与应用并行运行的函数
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