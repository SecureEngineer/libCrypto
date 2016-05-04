/**
* @file:   HashEngine.h
* @brief   结构体定义
* @author  Li YaoLong
* @date    2016/05/4
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_HASH_ENGINE_H
#define PKCS11_HASH_ENGINE_H


/***********************************包含头文件 ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** 数据类型 **********************************/

/**
* @class CHashEngine
* @brief 杂凑密码算法引擎
*
* 该类主要用于杂凑密码引擎声明
*/
class CHashEngine
{
public:
	/**
	* @brief 默认构造函数
	*/
	CHashEngine();
	/**
	* @brief 析构函数
	*/
	~CHashEngine();
public:
	virtual CK_LONG  HashInit(CK_BYTE_PTR pbData, CK_ULONG ulDataLen) = 0;
	virtual CK_LONG  HashUpdate(CK_BYTE_PTR pbData, CK_ULONG ulDataLen) = 0;
	virtual CK_LONG  HashFinal(CK_BYTE_PTR pbData, CK_ULONG_PTR pulDataLen) = 0;
};
#endif