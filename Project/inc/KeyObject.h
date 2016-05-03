/************************************************************************/
/************************************************************************/
/* 
* Copyright (c) 2009-2010, 李耀龙
* All rights reserved.
* File Name: KeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef KEYOBJECT_H
#define KEYOBJECT_H

#include "StorageObject.h"

/** 
* @class CKeyObject
* @brief PKCS#11标准中密钥对象类
*
* 该类派生于CStorageObject类,是所有密钥对象类的父类
* @see CStorageObject
*/
class CKeyObject:public CStorageObject
{
public:
	CKeyObject(){};
	~CKeyObject(){};
protected:
	//密钥类型
	CK_KEY_TYPE ulKeyType;
	//密钥的标识符
	CK_BYTE_PTR pbID;
	//密钥的启用日期
	CK_DATE     StartDate;
	//密钥的终止日期
	CK_DATE     EndDate;
	//如果密钥支持派生，则为TRUE，否则为FALSE
	CK_BBOOL    bDerive;
	//仅当密钥是下列情况之一时，为TRUE:
	//（1）使用C_GenerateKey或者C_GenerateKeyPair调用本地生成（即在此令牌上）；
	//（2）使用C_CopyObject调用作为一个密钥的副本创建，该密钥的CKA_LOCAL属性设定为TRUE
	CK_BBOOL    bLocal;
};
#endif