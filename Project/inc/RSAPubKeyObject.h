/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: RSAPubKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/

#ifndef RSAPUBKEYOBJECT_H
#define RSAPUBKEYOBJECT_H

#include "PublicKeyObject.h"

class CRSAPubKeyObject:public CPublicKeyObject
{
public:
	CRSAPubKeyObject();
	~CRSAPubKeyObject(){};
protected:
	//模数N,同时支持1024位与2048位
	CK_BYTE  pbModulus[260];
	//模数N的长度，按照比特位来计算，
	CK_ULONG ulModulusBits;
	//公用指数E
	CK_BYTE  pbPubExponent[260];
	//
	CK_ATTRIBUTE ckAttrTemplate[20];
};
#endif