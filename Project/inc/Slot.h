/**
 * @file:   Slot.h
 * @brief   �ṹ�嶨��
 * @author  Li YaoLong
 * @date    2015/10/13
 * @version 1.0
 * <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
 * <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
 * <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
 * <pre><b>All rights reserved.</b></pre> 
 */
#ifndef SLOT_H
#define SLOT_H


/***********************************����ͷ�ļ� ************************************/
#include <vector>
#include <string>
#include "Global.h"
#include "Mutex.h"
using namespace std;

/** 
 * @class CSlot
 * @brief ���Ʋ۵�������
 *
 * ������Ҫ���ڵ������Ʋ۵Ĳ���
 */
class CSlot
{
public:
	/**
	 * @brief Ĭ�Ϲ��캯��
	 */
	CSlot();
	/**
	 * @brief ��������
	 */
	~CSlot();
protected:
	/**
	 * �۱�ʶ
	 */
	CK_SLOT_ID m_ulSlotID;
	/**
	 * ����Ϣ
	 */
	CK_SLOT_INFO m_stSlotInfo;
	/**
	 * @brief �Ƿ�������
	 */
	CK_BBOOL m_bTokenPresent;
	/**
	 * @brief ������Ϣ
	 */
	CK_TOKEN_INFO m_stTokenInfo;
public:
	/**
	 * @brief ��ȡ�۱�ʶ
	 */
	CK_SLOT_ID GetID();
	/**
	 * @brief ��ȡ����Ϣ
	 */
	CK_SLOT_INFO GetInfo();
	/**
	 * @brief ����Ƿ��������
	 */
	CK_BBOOL CheckTokenPresent();
	/**
	 * @brief ��ȡ������Ϣ
	 */
	CK_TOKEN_INFO GetTokenInfo();
};

/** 
 * @class CSlotList
 * @brief ���Ʋ�����������
 *
 * ������Ҫ���ڶ�����Ʋ۵Ĺ���
 */
class CSlotList
{
private:
	CSlotList();
public:
	/**  
	 * @brief      ��ȡ���ƽӿ���ĵ������ 
	 * @return     CCrypto* ʵ�������ָ��
	 * @retval     NULL ��ָ�룬��Ч����
	 * @retval     !NULL �ǿ�ָ�룬��Ч����
	 */
	static CSlotList* GetInstance();
	/**  
	 * @brief      ��ȡ���Ʋ�(Slot)������ 
	 * @return     ��ǰ�豸�в�(Slot)������
	 */
	int GetCount();
	/**  
	 * @brief      ��ȡ�ض����Ʋ�(Slot)����
	 * @param[in]  �б������Ʋ������ţ���0��ʼ����
	 * @return     �ض����Ʋ�(Slot)��������
	 */
	CSlot& GetSlot(int nIndex);
	
private:
	/**
	 * ʵ�������
	 */
	static CSlotList* m_pInstance;
	/**
	 * Slot����
	 */
	vector<CSlot> m_vecSlot;
	/** 
	 * @class CCarbo
	 * @brief ��������������
	 *
	 * Ψһ�Ĺ�������������ʱɾ��CCrypto��ʵ��
	 */
	class CGarbo//
	{
	public:
		~CGarbo()
		{
			if (CSlotList::m_pInstance)
			{
				delete CSlotList::m_pInstance;
			}
		}
	};
    /**
	 * ���徲̬��Ա
	 */
	static CGarbo Garbo;
};
#endif