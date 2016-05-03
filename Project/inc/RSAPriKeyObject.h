/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
	//ģ��N
	CK_BYTE    pbModulus[260];
	//����ָ��E
	CK_BYTE    pbPubExponent[260];
	//˽��ָ��D
	CK_BYTE    pbPriExponent[260];
	//����1
	CK_BYTE    pbPrime1[260];
	//����2
	CK_BYTE    pbPrime2[260];
	//˽��ָ��DģP-1
	CK_BYTE    pbExponent1[260];
	//˽��ָ��DģQ-1
	CK_BYTE    pbExponent2[260];
	//CRTϵ��
	CK_BYTE    pbCoefficient[260];
	//����ģ��
	CK_ATTRIBUTE ckAttrTemplate[30];
};
#endif