/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: X5O9PubKeyCertObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef X509PUBKEYCERTOBJECT_H
#define X509PUBKEYCERTOBJECT_H

#include "CertificateObject.h"

class CX509PubKeyCertObject:public CCertificateObject
{
public:
	CX509PubKeyCertObject();
	~CX509PubKeyCertObject(){};
protected:
	//֤���������Ƶ�DER-����
	CK_BYTE_PTR pbSubject;
	//��Կ/˽Կ�Ե���Կ��ʶ��
	CK_BYTE_PTR pbID;
	//֤�鷢�������Ƶ�DER����
	CK_BYTE_PTR pbIssuer;
	//֤�����кŵ�DER����
	CK_BYTE_PTR pbSerialNumber;
	//֤�����кŵ�BER����
	CK_BYTE_PTR pbValue;
	//��������ģ��
	CK_ATTRIBUTE ckAttrTemplate[12];
};
#endif