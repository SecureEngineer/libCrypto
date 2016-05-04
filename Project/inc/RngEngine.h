/**
* @file:   RngEngine.h
* @brief   �ṹ�嶨��
* @author  Li YaoLong
* @date    2016/05/4
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_RNG_ENGINE_H
#define PKCS11_RNG_ENGINE_H


/***********************************����ͷ�ļ� ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** �������� **********************************/

/**
* @class CRngEngine
* @brief ���������������
*
* ������Ҫ���ڲ������������α�����
*/
class CRngEngine
{
public:
	/**
	* @brief Ĭ�Ϲ��캯��
	*/
	CRngEngine();
	/**
	* @brief ��������
	*/
	~CRngEngine();
public:
	virtual CK_LONG  GenRandom(CK_BYTE_PTR pbRandom,CK_LONG lRandomLen) = 0;
};
#endif