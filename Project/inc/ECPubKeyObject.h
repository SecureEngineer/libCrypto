/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
* @brief EC�㷨��Կ������
*
* ������Ҫ����EC�㷨��Կ����������뷽����������CPublicKeyObject�ࡣ
* @see CPublicKeyObject
*/
class CECPubKeyObject:public CPublicKeyObject
{
public:
	CECPubKeyObject();
	~CECPubKeyObject(){};
protected:
	// ����
	CK_ATTRIBUTE ckAttrTemplate[20];
};
#endif