/**
* @file:   Crypto.h
* @brief   CCrypto������ͷ�ļ�
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
* <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
* <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
* <pre><b>All rights reserved.</b></pre> 
*/
#ifndef CRYPTO_H
#define CRYPTO_H

#include <vector>
#include <string>
#include "Global.h"
#include "Mutex.h"
using namespace std;

/** 
* @class CCrypto
* @brief PKCS#11��׼���������ƽӿ���
*
* ������Ҫ���ڳ�ʼ��ȫ����ر�����
*/
class CCrypto
{
private:
	static CCrypto* m_pInstance; 
public:
	/**  
	* @brief      ��ȡ���ƽӿ���ĵ������ 
	* @return     CCrypto* ʵ�������ָ��
	* @retval     NULL ��ָ�룬��Ч����
	* @retval     !NULL �ǿ�ָ�룬��Ч����
	*/
	static CCrypto* GetInstance();
	/**  
	* @brief      ��ʼ���ӿ�
	* @return     CCrypto* ʵ�������ָ��
	* @retval     NULL ��ָ�룬��Ч����
	* @retval     !NULL �ǿ�ָ�룬��Ч����
	*/
	CK_RV Initialize(CK_VOID_PTR pInitArgs);

	/**  
	* @brief      ��ȡ��ʼ����ʶ
	* @return     ����ӿڿ��Ƿ��ѳ�ʼ��
	* @retval     TRUE  �ѳ�ʼ��
	* @retval     FALSE δ��ʼ��
	*/
	CK_BBOOL GetInitFlag();

	/**  
	* @brief      �رսӿ�
	* @return     CCrypto* ʵ�������ָ��
	* @retval     NULL ��ָ�룬��Ч����
	* @retval     !NULL �ǿ�ָ�룬��Ч����
	*/
	CK_RV Finalize(CK_VOID_PTR pReserved);
	
	/**  
	* @brief      ��ȡ�ӿ���Ϣ
	* @param[out] 
	* @return     CCrypto* ʵ�������ָ��
	* @retval     NULL ��ָ�룬��Ч����
	* @retval     !NULL �ǿ�ָ�룬��Ч����
	*/
	CK_RV GetInfo(CK_INFO_PTR pInfo);

private:
	CCrypto();
	/**
	* ��ǰʹ�ù̶���ID
	*/
	CK_UTF8CHAR m_utf8ManuFacturerID[32];
	/**
	* Cryptoki������
	*/
	CK_UTF8CHAR m_utf8LibraryDesc[32] ;
	/**
	* PKCS#11�ӿڿ�ʵ�ֵ�ȫ�ֱ���
	*/
	CK_BBOOL    m_bInitialized;
	/**
	* cryptoki�ⲻ���Լ������߳�
	*/
	CK_FLAGS    m_fCryptokiFlag;
	/**
	* �洢����ĳ�ʼ��cryptoki����
	*/
	CK_C_INITIALIZE_ARGS_PTR    m_pInitArgs;

	//////////////////////////////////////////////////////////////////////////
	class CGarbo//Ψһ�Ĺ�������������ʱɾ��CCrypto��ʵ��
	{
	public:
		~CGarbo()
		{
			if (CCrypto::m_pInstance)
			{
				delete CCrypto::m_pInstance;
			}
		}
	};

	static CGarbo Garbo;//���徲̬��Ա
};

#endif