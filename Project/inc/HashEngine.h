/**
* @file:   HashEngine.h
* @brief   �ṹ�嶨��
* @author  Li YaoLong
* @date    2016/05/4
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_HASH_ENGINE_H
#define PKCS11_HASH_ENGINE_H


/***********************************����ͷ�ļ� ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** �������� **********************************/

/**
* @class CHashEngine
* @brief �Ӵ������㷨����
*
* ������Ҫ�����Ӵ�������������
*/
class CHashEngine
{
public:
	/**
	* @brief Ĭ�Ϲ��캯��
	*/
	CHashEngine();
	/**
	* @brief ��������
	*/
	~CHashEngine();
public:
	virtual CK_LONG  HashInit(CK_BYTE_PTR pbData, CK_ULONG ulDataLen) = 0;
	virtual CK_LONG  HashUpdate(CK_BYTE_PTR pbData, CK_ULONG ulDataLen) = 0;
	virtual CK_LONG  HashFinal(CK_BYTE_PTR pbData, CK_ULONG_PTR pulDataLen) = 0;
};
#endif