/**
* @file:   SymmEngine.h
* @brief   �ṹ�嶨��
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_SYMM_ENGINE_H
#define PKCS11_SYMM_ENGINE_H


/***********************************����ͷ�ļ� ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** �������� **********************************/

/**
* @class CSymmEngine
* @brief �Գ��㷨��������
*
* ������Ҫ���ڵ����Ự����
*/
class CSymmEngine
{
public:
	/**
	* @brief Ĭ�Ϲ��캯��
	*/
	CSymmEngine();
	/**
	* @brief ��������
	*/
	~CSymmEngine();
public:
	/**
	 * @brief ���ü�����Կ�������Կ
	 */
	virtual int SetKey() = 0;
	
	/**
	 * @brief ���ܳ�ʼ��
	 */
	virtual CK_LONG  EncryptInit() = 0;
	
	/**
	 * @brief �������ܻ�ѭ������
	 */
	virtual CK_LONG  EncryptUpdate() = 0;
	
	/**
	 * @brief ���ܽ���
	 */
	virtual CK_LONG  EncryptFinal() = 0;
	
	/**
	 * @brief ���ܳ�ʼ��
	 */
	virtual CK_LONG  DecryptInit() = 0;
	
	/**
	 * @brief �������ܻ�ѭ������
	 */
	virtual CK_LONG  DecryptUpdate() = 0;
	
	/**
	 * @brief ���ܽ���
	 */
	virtual CK_LONG  DecryptFinal() = 0;
};
#endif