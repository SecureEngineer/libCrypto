/**
 * @file:   Mechanism.h
 * @brief   算法机制类声明
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


/***********************************包含头文件 ************************************/
#include <vector>
#include <string>
#include "Global.h"
#include "Mutex.h"
using namespace std;

/** 
 * @class CMechanism
 * @brief 令牌槽的类声明
 *
 * 该类主要用于单个令牌槽的操作
 */
class CMechanism
{
public:
	/**
	 * @brief 默认构造函数
	 */
	CMechanism(CK_ULONG ulType,CK_VOID_PTR parameter,CK_ULONG ulParaLen,CK_ULONG ulMinKeySize,CK_ULONG ulMaxKeySize,CK_ULONG ulFlags);
	/**
	 * @brief 拷贝构造函数
	 */
	CMechanism(const CMechanism& mechanism);
	/**
	 * @brief 析构函数
	 */
	~CMechanism();
protected:
	/**
	 * @brief 机制类型
	 * @see CK_MECHANISM
	 */
	CK_ULONG m_ulType;
	/**
	 * @brief 参数指针
	 * @see CK_MECHANISM
	 */
	CK_VOID_PTR m_pParameter;
	/**
	 * @brief 指针指向参数的长度
	 * @see CK_MECHANISM
	 */
	CK_ULONG m_ulParameterLen;
	
	/**
	 * @brief 最大密钥长度
	 * @see CK_MECHANISM_INFO
	 */
	CK_ULONG m_ulMaxKeySize;
	/**
	 * @brief 最小密钥长度
	 * @see CK_MECHANISM_INFO
	 */
	CK_ULONG m_ulMinKeySize;
	/**
	 * @brief 机制标志位
	 * @see CK_MECHANISM_INFO
	 */
	CK_FLAGS m_ulFlags;
public:
	/**
	 * @brief 获取机制类型
	 */
	CK_ULONG GetType();
	/**
	 * @brief 获取机制参数
	 */
	CK_ULONG GetParameter(CK_VOID_PTR parameter);
	/**
	 * @brief 获取机制信息中的最大密钥长度
	 */
	CK_ULONG GetMaxKeySize();
	/**
	 * @brief 获取机制信息中的最小密钥长度
	 */
	CK_ULONG GetMinKeySize();
	/**
	 * @brief 获取机制信息中的标志位
	 */
	CK_ULONG GetFlags();
};

/** 
 * @class CMechanismList
 * @brief 机制链表类声明
 *
 * 该类主要使用数组实现一维链表
 */
class CMechanismList
{
public:
	/**  
	 * @brief      构造函数
	 */
	CMechanismList();
	/**  
	 * @brief      析构函数
	 */
	~CMechanismList();
public:
	/**  
	 * @brief      获取链表中元素的数量
	 * @return     当前链表中元素的数量
	 */
	int GetCount();
	/**
	 * @brief      获取特定令牌槽(Slot)对象
	 * @param[in]  列表中令牌槽索引号，从0开始计数

	 * @return     特定令牌槽(Slot)对象引用
	 */
	CMechanism& GetMechanism(int nIndex);
	
private:
	/**
	 * 机制链表
	 */
	vector<CMechanism> m_vecMechanism;
};
#endif