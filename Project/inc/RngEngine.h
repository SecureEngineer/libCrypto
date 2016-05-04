/**
* @file:   RngEngine.h
* @brief   结构体定义
* @author  Li YaoLong
* @date    2016/05/4
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_RNG_ENGINE_H
#define PKCS11_RNG_ENGINE_H


/***********************************包含头文件 ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** 数据类型 **********************************/

/**
* @class CRngEngine
* @brief 随机数发生器引擎
*
* 该类主要用于产生真随机数及伪随机数
*/
class CRngEngine
{
public:
	/**
	* @brief 默认构造函数
	*/
	CRngEngine();
	/**
	* @brief 析构函数
	*/
	~CRngEngine();
public:
	virtual CK_LONG  GenRandom(CK_BYTE_PTR pbRandom,CK_LONG lRandomLen) = 0;
};
#endif