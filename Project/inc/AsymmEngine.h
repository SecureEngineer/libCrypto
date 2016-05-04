/**
* @file:   AsymmEngine.h
* @brief   �ṹ�嶨��
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
* <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre> 
* <pre><b>All rights reserved.</b></pre> 
*/
#ifndef PKCS11_ASYMM_ENGINE_H
#define PKCS11_ASYMM_ENGINE_H


/***********************************����ͷ�ļ� ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** �������� **********************************/

/** 
* @class CAsymmEngine
* @brief �ǶԳ��㷨����
*
* ������Ҫ���ڷǶԳ�����
*/
class CAsymmEngine
{
public:
	/**
	* @brief Ĭ�Ϲ��캯��
	*/
	CAsymmEngine();
	/**
	* @brief ��������
	*/
	~CAsymmEngine();
public:
	virtual CK_LONG SetKey(CK_BYTE_PTR pbKey, CK_ULONG ulKeyLen) = 0;
	virtual CK_LONG Encrypt(CK_BYTE_PTR pbPlainKey, CK_ULONG ulPlainKeyLen, CK_BYTE_PTR pbCipherKey, CK_ULONG_PTR pulCipherKeyLen) = 0;
	virtual CK_LONG Signature(CK_BYTE_PTR pbHashData, CK_ULONG ulHashDataLen, CK_BYTE_PTR pbSignData, CK_ULONG_PTR pulSignDataLen) = 0;
	virtual CK_LONG Verify(CK_BYTE_PTR pbSignData, CK_ULONG ulSignDataLen) = 0;
};
#endif