/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: RSAPriKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef RSAPRIKEYOBJECT_H
#define RSAPRIKEYOBJECT_H

#include "PrivateKeyObject.h"

class CRSAPriKeyObject:public CPrivateKeyObject
{
public:
	CRSAPriKeyObject();
	~CRSAPriKeyObject(){};
protected:
	//模数N
	CK_BYTE    pbModulus[260];
	//公共指数E
	CK_BYTE    pbPubExponent[260];
	//私有指数D
	CK_BYTE    pbPriExponent[260];
	//质数1
	CK_BYTE    pbPrime1[260];
	//质数2
	CK_BYTE    pbPrime2[260];
	//私有指数D模P-1
	CK_BYTE    pbExponent1[260];
	//私有指数D模Q-1
	CK_BYTE    pbExponent2[260];
	//CRT系数
	CK_BYTE    pbCoefficient[260];
	//属性模板
	CK_ATTRIBUTE ckAttrTemplate[30];
};
#endif