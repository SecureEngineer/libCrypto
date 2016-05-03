/**
* @file:   Session.h
* @brief   结构体定义
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


/***********************************包含头文件 ************************************/
#include "..\inc\cryptoki.h"
#include <list>
using namespace std;
/********************************** 数据类型 **********************************/

/** 
* @class CSession
* @brief 会话类声明
*
* 该类主要用于单个会话操作
*/
class CSession
{
public:
	/**
	* @brief 默认构造函数
	*/
	CSession();
	/**
	* @brief 析构函数
	*/
	~CSession();
protected:
	/**
	* 会话句柄
	*/
	CK_SESSION_HANDLE m_hSession;
	/**
	* 会话信息
	*/
	CK_SESSION_INFO   m_stSessionInfo;
	/**
	* 查找对象句柄
	*/
	CK_OBJECT_HANDLE  m_hFindObject;
public:
	/**
	* @brief 获取槽标识
	*/
	CK_SESSION_HANDLE GetHandle();
	/**
	* @brief 获取槽信息
	*/
	CK_SESSION_INFO GetInfo();
	
};
/** 
* @class CSessionList
* @brief 会话列表类声明
*
* 该类主要用于多个会话类的管理
*/
class CSessionList
{
private:
	CSessionList();
public:
	/**  
	* @brief      获取令牌接口类的单例句柄 
	* @return     CCrypto* 实例化句柄指针
	* @retval     NULL 空指针，无效数据
	* @retval     !NULL 非空指针，有效数据
	*/
	static CSessionList* GetInstance();
private:
	static CSessionList* m_pInstance;
	static list<CSession> m_listSlot;
	/** 
	* @class CCarbo
	* @brief 垃圾回收类声明
	*
	* 该类主要用于多个令牌槽的管理
	*/
	class CGarbo//唯一的工作就是在销毁时删除CCrypto的实例
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

	static CGarbo Garbo;//定义静态成员
};
#endif