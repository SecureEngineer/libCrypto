/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
* @brief EC�㷨˽Կ������
*
* ������Ҫ����EC�㷨˽Կ����������뷽����������CPrivateKeyObject�ࡣ
* @see CPrivateKeyObject
*/
class CECPriKeyObject:public CPrivateKeyObject
{
public:
	CECPriKeyObject();
	~CECPriKeyObject(){};
protected:
	//����ģ��
	CK_ATTRIBUTE ckAttrTemplate[30];
};
#endif