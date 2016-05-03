/**
 * @file:   Mechanism.h
 * @brief   �㷨����������
 * @author  Li YaoLong
 * @date    2015/10/13
 * @version 1.0
 * <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
 * <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
 * <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
 * <pre><b>All rights reserved.</b></pre> 
 */
#ifndef MECHANISM_H
#define MECHANISM_H


/***********************************����ͷ�ļ� ************************************/
#include <vector>
#include <string>
#include "Global.h"
#include "Mutex.h"
using namespace std;

/** 
 * @class CMechanism
 * @brief ���Ʋ۵�������
 *
 * ������Ҫ���ڵ������Ʋ۵Ĳ���
 */
class CMechanism
{
public:
	/**
	 * @brief Ĭ�Ϲ��캯��
	 */
	CMechanism(CK_ULONG ulType,CK_VOID_PTR parameter,CK_ULONG ulParaLen,CK_ULONG ulMinKeySize,CK_ULONG ulMaxKeySize,CK_ULONG ulFlags);
	/**
	 * @brief �������캯��
	 */
	CMechanism(const CMechanism& mechanism);
	/**
	 * @brief ��������
	 */
	~CMechanism();
protected:
	/**
	 * @brief ��������
	 * @see CK_MECHANISM
	 */
	CK_ULONG m_ulType;
	/**
	 * @brief ����ָ��
	 * @see CK_MECHANISM
	 */
	CK_VOID_PTR m_pParameter;
	/**
	 * @brief ָ��ָ������ĳ���
	 * @see CK_MECHANISM
	 */
	CK_ULONG m_ulParameterLen;
	
	/**
	 * @brief �����Կ����
	 * @see CK_MECHANISM_INFO
	 */
	CK_ULONG m_ulMaxKeySize;
	/**
	 * @brief ��С��Կ����
	 * @see CK_MECHANISM_INFO
	 */
	CK_ULONG m_ulMinKeySize;
	/**
	 * @brief ���Ʊ�־λ
	 * @see CK_MECHANISM_INFO
	 */
	CK_FLAGS m_ulFlags;
public:
	/**
	 * @brief ��ȡ��������
	 */
	CK_ULONG GetType();
	/**
	 * @brief ��ȡ���Ʋ���
	 */
	CK_ULONG GetParameter(CK_VOID_PTR parameter);
	/**
	 * @brief ��ȡ������Ϣ�е������Կ����
	 */
	CK_ULONG GetMaxKeySize();
	/**
	 * @brief ��ȡ������Ϣ�е���С��Կ����
	 */
	CK_ULONG GetMinKeySize();
	/**
	 * @brief ��ȡ������Ϣ�еı�־λ
	 */
	CK_ULONG GetFlags();
};

/** 
 * @class CMechanismList
 * @brief ��������������
 *
 * ������Ҫʹ������ʵ��һά����
 */
class CMechanismList
{
public:
	/**  
	 * @brief      ���캯��
	 */
	CMechanismList();
	/**  
	 * @brief      ��������
	 */
	~CMechanismList();
public:
	/**  
	 * @brief      ��ȡ������Ԫ�ص�����
	 * @return     ��ǰ������Ԫ�ص�����
	 */
	int GetCount();
	/**
	 * @brief      ��ȡ�ض����Ʋ�(Slot)����
	 * @param[in]  �б������Ʋ������ţ���0��ʼ����

	 * @return     �ض����Ʋ�(Slot)��������
	 */
	CMechanism& GetMechanism(int nIndex);
	
private:
	/**
	 * ��������
	 */
	vector<CMechanism> m_vecMechanism;
};
#endif