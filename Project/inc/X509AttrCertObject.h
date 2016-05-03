/************************************************************************/
/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: X5O9AttrCertObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef X509ATTRCERTOBJECT_H
#define X509ATTRCERTOBJECT_H

#include "CertificateObject.h"

class CX509AttrCertObject:public CCertificateObject
{
public:
	CX509AttrCertObject();
	~CX509AttrCertObject(){};
protected:
	//����֤���������Ƶ�DER-����
	CK_BYTE_PTR pbOwner;
	//�������෢�����ֶε�DER-����
	CK_BYTE_PTR pbACIssuer;
	//֤�����кŵ�DER����
	CK_BYTE_PTR pbSerialNumber;
	//��Ӧ��֤�������������������͵�һ�������ʶ��ֵ��BER-����
	CK_BYTE_PTR pbAttrTypes;
	//֤���BER-����
	CK_BYTE_PTR pbValue;
	//��������ģ��
	CK_ATTRIBUTE ckAttrTemplate[12];
};
#endif