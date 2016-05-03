/**
 * @file:   Slot.h
 * @brief   结构体定义
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


/***********************************包含头文件 ************************************/
#include <vector>
#include <string>
#include "Global.h"
#include "Mutex.h"
using namespace std;

/** 
 * @class CSlot
 * @brief 令牌槽的类声明
 *
 * 该类主要用于单个令牌槽的操作
 */
class CSlot
{
public:
	/**
	 * @brief 默认构造函数
	 */
	CSlot();
	/**
	 * @brief 析构函数
	 */
	~CSlot();
protected:
	/**
	 * 槽标识
	 */
	CK_SLOT_ID m_ulSlotID;
	/**
	 * 槽信息
	 */
	CK_SLOT_INFO m_stSlotInfo;
	/**
	 * @brief 是否含有令牌
	 */
	CK_BBOOL m_bTokenPresent;
	/**
	 * @brief 令牌信息
	 */
	CK_TOKEN_INFO m_stTokenInfo;
public:
	/**
	 * @brief 获取槽标识
	 */
	CK_SLOT_ID GetID();
	/**
	 * @brief 获取槽信息
	 */
	CK_SLOT_INFO GetInfo();
	/**
	 * @brief 检查是否存在令牌
	 */
	CK_BBOOL CheckTokenPresent();
	/**
	 * @brief 获取令牌信息
	 */
	CK_TOKEN_INFO GetTokenInfo();
};

/** 
 * @class CSlotList
 * @brief 令牌槽链表类声明
 *
 * 该类主要用于多个令牌槽的管理
 */
class CSlotList
{
private:
	CSlotList();
public:
	/**  
	 * @brief      获取令牌接口类的单例句柄 
	 * @return     CCrypto* 实例化句柄指针
	 * @retval     NULL 空指针，无效数据
	 * @retval     !NULL 非空指针，有效数据
	 */
	static CSlotList* GetInstance();
	/**  
	 * @brief      获取令牌槽(Slot)的数量 
	 * @return     当前设备中槽(Slot)的数量
	 */
	int GetCount();
	/**  
	 * @brief      获取特定令牌槽(Slot)对象
	 * @param[in]  列表中令牌槽索引号，从0开始计数
	 * @return     特定令牌槽(Slot)对象引用
	 */
	CSlot& GetSlot(int nIndex);
	
private:
	/**
	 * 实例化句柄
	 */
	static CSlotList* m_pInstance;
	/**
	 * Slot链表
	 */
	vector<CSlot> m_vecSlot;
	/** 
	 * @class CCarbo
	 * @brief 垃圾回收类声明
	 *
	 * 唯一的工作就是在销毁时删除CCrypto的实例
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
	 * 定义静态成员
	 */
	static CGarbo Garbo;
};
#endif