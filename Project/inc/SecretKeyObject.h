/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: SecretKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef SECRETKEYOBJECT_H
#define SECRETKEYOBJECT_H

#include "KeyObject.h"

class CSecretKeyObject:public CKeyObject
{
public:
	CSecretKeyObject()
	{
		bSensitive = CK_FALSE;
		bEncrypt = CK_FALSE;
		bDecrypt = CK_FALSE;
		bSign = CK_FALSE;
		bVerify = CK_FALSE;
		bWrap = CK_FALSE;
		bUnWrap = CK_FALSE;
		bExtractable = CK_FALSE;
		bAlwaysSensitive = CK_FALSE;
		bNeverExtractable = CK_FALSE;
		pbKey = NULL_PTR;
		ulKeyLen = 0;
		ulKeyMinLen = 0;
		ulKeyMaxLen = 0;
	};
	~CSecretKeyObject(){};
protected:
	//敏感属性
	CK_BBOOL  bSensitive;
	//支持加密属性
	CK_BBOOL  bEncrypt;
	//支持解密属性
	CK_BBOOL  bDecrypt;
	//支持签名属性，在这里签名是数据的附录；
	CK_BBOOL  bSign;
	//支持验证属性
	CK_BBOOL  bVerify;
	//支持加密其他密钥属性
	CK_BBOOL  bWrap;
	//支持解密其他密钥属性
	CK_BBOOL  bUnWrap;
	//萃取属性
	CK_BBOOL  bExtractable;
	//
	CK_BBOOL  bAlwaysSensitive;
	//
	CK_BBOOL  bNeverExtractable;
	//密钥数据，与属性CKA_VALUE一起使用
	CK_BYTE_PTR  pbKey;
	//密钥数据长度，与属性CKA_VALUE_LEN一起使用；
	CK_ULONG  ulKeyLen;
	//密钥的最短长度
	CK_ULONG ulKeyMinLen;
	//密钥的最大长度
	CK_ULONG ulKeyMaxLen;
	//密钥模板
	CK_ATTRIBUTE ckAttrTemplate[22];
};
#endif