/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
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
	//证书主体名称的DER-编码
	CK_BYTE_PTR pbSubject;
	//公钥/私钥对的密钥标识符
	CK_BYTE_PTR pbID;
	//证书发布者名称的DER编码
	CK_BYTE_PTR pbIssuer;
	//证书序列号的DER编码
	CK_BYTE_PTR pbSerialNumber;
	//证书序列号的BER编码
	CK_BYTE_PTR pbValue;
	//对象属性模板
	CK_ATTRIBUTE ckAttrTemplate[12];
};
#endif