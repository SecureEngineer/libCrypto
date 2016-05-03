/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: ECPubKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/

#ifndef ECPUBKEYOBJECT_H
#define ECPUBKEYOBJECT_H

#include "PublicKeyObject.h"
/** 
* @class CECPubKeyObject
* @brief EC算法公钥对象类
*
* 该类主要包含EC算法公钥对象的属性与方法，派生于CPublicKeyObject类。
* @see CPublicKeyObject
*/
class CECPubKeyObject:public CPublicKeyObject
{
public:
	CECPubKeyObject();
	~CECPubKeyObject(){};
protected:
	// 属性
	CK_ATTRIBUTE ckAttrTemplate[20];
};
#endif