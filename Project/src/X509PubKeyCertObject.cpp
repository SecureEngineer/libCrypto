/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: X509PubKeyCertObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/

#include "..\inc\X509PubKeyCertObject.h"

CX509PubKeyCertObject::CX509PubKeyCertObject()
{
	//定义该对象为X509公钥证书
	certType = CKC_X_509;

	//公钥证书对象的类别属性
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);
	
	//公钥证书对象的会话属性
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//公钥证书对象的私有属性
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//公钥证书对象的可修改属性
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//公钥证书对象的标签属性
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = 0; //需要考虑指针指向内存的空间大小

	//公钥证书对象的证书类型属性
	ckAttrTemplate[5].type = CKA_CERTIFICATE_TYPE;
	ckAttrTemplate[5].pValue = &certType;
	ckAttrTemplate[5].ulValueLen = sizeof(certType);

	//公钥证书对象的可信任属性
	ckAttrTemplate[6].type = CKA_TRUSTED;
	ckAttrTemplate[6].pValue = &bTrusted;
	ckAttrTemplate[6].ulValueLen = sizeof(bTrusted);

	//公钥证书对象的证书主体名称属性
	ckAttrTemplate[7].type = CKA_SUBJECT;
	ckAttrTemplate[7].pValue = pbSubject;
	ckAttrTemplate[7].ulValueLen = 0; //需要计算指针指向内存的长度

	//公钥证书对象的密钥标识符属性
	pbID = NULL_PTR; //缺省为空
	ckAttrTemplate[8].type = CKA_ID;
	ckAttrTemplate[8].pValue = pbID;
	ckAttrTemplate[8].ulValueLen = 0;//需要计算指针指向内存的长度

	//公钥证书对象的证书发布者名称属性
	pbIssuer = NULL_PTR;
	ckAttrTemplate[9].type = CKA_ISSUER;
	ckAttrTemplate[9].pValue = pbIssuer;
	ckAttrTemplate[9].ulValueLen = 0;//需要计算指针指向内存的长度

	//公钥证书对象的序列号属性
	pbSerialNumber = NULL_PTR;
	ckAttrTemplate[10].type = CKA_SERIAL_NUMBER;
	ckAttrTemplate[10].pValue = pbSerialNumber;
	ckAttrTemplate[10].ulValueLen = 0;

	//公钥证书对象的序列号编码
	pbValue = NULL_PTR;
	ckAttrTemplate[11].type = CKA_VALUE;
	ckAttrTemplate[11].pValue = pbValue;
	ckAttrTemplate[11].ulValueLen = 0;
};