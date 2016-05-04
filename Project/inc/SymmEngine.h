/**
* @file:   SymmEngine.h
* @brief   结构体定义
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sinosecsoft.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_SYMM_ENGINE_H
#define PKCS11_SYMM_ENGINE_H


/***********************************包含头文件 ************************************/
#include "..\inc\cryptoki.h"
using namespace std;
/********************************** 数据类型 **********************************/

/**
* @class CSymmEngine
* @brief 对称算法引擎声明
*
* 该类主要用于单个会话操作
*/
class CSymmEngine
{
public:
	/**
	* @brief 默认构造函数
	*/
	CSymmEngine();
	/**
	* @brief 析构函数
	*/
	~CSymmEngine();
public:
	/**
	 * @brief 设置加密密钥或解密密钥
	 */
	virtual int SetKey() = 0;
	
	/**
	 * @brief 加密初始化
	 */
	virtual CK_LONG  EncryptInit() = 0;
	
	/**
	 * @brief 持续加密或循环加密
	 */
	virtual CK_LONG  EncryptUpdate() = 0;
	
	/**
	 * @brief 加密结束
	 */
	virtual CK_LONG  EncryptFinal() = 0;
	
	/**
	 * @brief 解密初始化
	 */
	virtual CK_LONG  DecryptInit() = 0;
	
	/**
	 * @brief 持续解密或循环解密
	 */
	virtual CK_LONG  DecryptUpdate() = 0;
	
	/**
	 * @brief 解密结束
	 */
	virtual CK_LONG  DecryptFinal() = 0;
};
#endif