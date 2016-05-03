/**
* @file:   Session.h
* @brief   �ṹ�嶨��
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
* <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
* <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
* <pre><b>All rights reserved.</b></pre> 
*/
#ifndef Session_H
#define Session_H


/***********************************����ͷ�ļ� ************************************/
#include "..\inc\cryptoki.h"
#include <list>
using namespace std;
/********************************** �������� **********************************/

/** 
* @class CSession
* @brief �Ự������
*
* ������Ҫ���ڵ����Ự����
*/
class CSession
{
public:
	/**
	* @brief Ĭ�Ϲ��캯��
	*/
	CSession();
	/**
	* @brief ��������
	*/
	~CSession();
protected:
	/**
	* �Ự���
	*/
	CK_SESSION_HANDLE m_hSession;
	/**
	* �Ự��Ϣ
	*/
	CK_SESSION_INFO   m_stSessionInfo;
	/**
	* ���Ҷ�����
	*/
	CK_OBJECT_HANDLE  m_hFindObject;
public:
	/**
	* @brief ��ȡ�۱�ʶ
	*/
	CK_SESSION_HANDLE GetHandle();
	/**
	* @brief ��ȡ����Ϣ
	*/
	CK_SESSION_INFO GetInfo();
	
};
/** 
* @class CSessionList
* @brief �Ự�б�������
*
* ������Ҫ���ڶ���Ự��Ĺ���
*/
class CSessionList
{
private:
	CSessionList();
public:
	/**  
	* @brief      ��ȡ���ƽӿ���ĵ������ 
	* @return     CCrypto* ʵ�������ָ��
	* @retval     NULL ��ָ�룬��Ч����
	* @retval     !NULL �ǿ�ָ�룬��Ч����
	*/
	static CSessionList* GetInstance();
private:
	static CSessionList* m_pInstance;
	static list<CSession> m_listSlot;
	/** 
	* @class CCarbo
	* @brief ��������������
	*
	* ������Ҫ���ڶ�����Ʋ۵Ĺ���
	*/
	class CGarbo//Ψһ�Ĺ�������������ʱɾ��CCrypto��ʵ��
	{
	public:
		~CGarbo()
		{
			if (CSessionList::m_pInstance)
			{
				delete CSessionList::m_pInstance;
			}
		}
	};

	static CGarbo Garbo;//���徲̬��Ա
};
#endif