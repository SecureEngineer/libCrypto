/**
* @file:   Crypto.h
* @brief   CCrypto类声明头文件
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
* @brief PKCS#11标准中密码令牌接口类
*
* 该类主要用于初始化全局相关变量。
*/
class CCrypto
{
private:
	static CCrypto* m_pInstance; 
public:
	/**  
	* @brief      获取令牌接口类的单例句柄 
	* @return     CCrypto* 实例化句柄指针
	* @retval     NULL 空指针，无效数据
	* @retval     !NULL 非空指针，有效数据
	*/
	static CCrypto* GetInstance();
	/**  
	* @brief      初始化接口
	* @return     CCrypto* 实例化句柄指针
	* @retval     NULL 空指针，无效数据
	* @retval     !NULL 非空指针，有效数据
	*/
	CK_RV Initialize(CK_VOID_PTR pInitArgs);

	/**  
	* @brief      获取初始化标识
	* @return     密码接口库是否已初始化
	* @retval     TRUE  已初始化
	* @retval     FALSE 未初始化
	*/
	CK_BBOOL GetInitFlag();

	/**  
	* @brief      关闭接口
	* @return     CCrypto* 实例化句柄指针
	* @retval     NULL 空指针，无效数据
	* @retval     !NULL 非空指针，有效数据
	*/
	CK_RV Finalize(CK_VOID_PTR pReserved);
	
	/**  
	* @brief      获取接口信息
	* @param[out] 
	* @return     CCrypto* 实例化句柄指针
	* @retval     NULL 空指针，无效数据
	* @retval     !NULL 非空指针，有效数据
	*/
	CK_RV GetInfo(CK_INFO_PTR pInfo);

private:
	CCrypto();
	/**
	* 当前使用固定的ID
	*/
	CK_UTF8CHAR m_utf8ManuFacturerID[32];
	/**
	* Cryptoki库描述
	*/
	CK_UTF8CHAR m_utf8LibraryDesc[32] ;
	/**
	* PKCS#11接口库实现的全局变量
	*/
	CK_BBOOL    m_bInitialized;
	/**
	* cryptoki库不会自己创建线程
	*/
	CK_FLAGS    m_fCryptokiFlag;
	/**
	* 存储传入的初始化cryptoki参数
	*/
	CK_C_INITIALIZE_ARGS_PTR    m_pInitArgs;

	//////////////////////////////////////////////////////////////////////////
	class CGarbo//唯一的工作就是在销毁时删除CCrypto的实例
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

	static CGarbo Garbo;//定义静态成员
};

#endif