/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: ECPriKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/12/13
*/
/************************************************************************/
#ifndef ECPRIKEYOBJECT_H
#define ECPRIKEYOBJECT_H

#include "PrivateKeyObject.h"
/** 
* @class CECPriKeyObject
* @brief EC算法私钥对象类
*
* 该类主要包含EC算法私钥对象的属性与方法，派生于CPrivateKeyObject类。
* @see CPrivateKeyObject
*/
class CECPriKeyObject:public CPrivateKeyObject
{
public:
	CECPriKeyObject();
	~CECPriKeyObject(){};
protected:
	//属性模板
	CK_ATTRIBUTE ckAttrTemplate[30];
};
#endif