/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
	//ģ��N,ͬʱ֧��1024λ��2048λ
	CK_BYTE  pbModulus[260];
	//ģ��N�ĳ��ȣ����ձ���λ�����㣬
	CK_ULONG ulModulusBits;
	//����ָ��E
	CK_BYTE  pbPubExponent[260];
	//
	CK_ATTRIBUTE ckAttrTemplate[20];
};
#endif