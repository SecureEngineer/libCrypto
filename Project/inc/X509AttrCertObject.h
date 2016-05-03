/************************************************************************/
/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
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
	//属性证书主体名称的DER-编码
	CK_BYTE_PTR pbOwner;
	//属性整肃发布者字段的DER-编码
	CK_BYTE_PTR pbACIssuer;
	//证书序列号的DER编码
	CK_BYTE_PTR pbSerialNumber;
	//对应于证书中所包含的属性类型的一串对象标识符值的BER-编码
	CK_BYTE_PTR pbAttrTypes;
	//证书的BER-编码
	CK_BYTE_PTR pbValue;
	//对象属性模板
	CK_ATTRIBUTE ckAttrTemplate[12];
};
#endif