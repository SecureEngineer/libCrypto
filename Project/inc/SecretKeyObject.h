/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
	//��������
	CK_BBOOL  bSensitive;
	//֧�ּ�������
	CK_BBOOL  bEncrypt;
	//֧�ֽ�������
	CK_BBOOL  bDecrypt;
	//֧��ǩ�����ԣ�������ǩ�������ݵĸ�¼��
	CK_BBOOL  bSign;
	//֧����֤����
	CK_BBOOL  bVerify;
	//֧�ּ���������Կ����
	CK_BBOOL  bWrap;
	//֧�ֽ���������Կ����
	CK_BBOOL  bUnWrap;
	//��ȡ����
	CK_BBOOL  bExtractable;
	//
	CK_BBOOL  bAlwaysSensitive;
	//
	CK_BBOOL  bNeverExtractable;
	//��Կ���ݣ�������CKA_VALUEһ��ʹ��
	CK_BYTE_PTR  pbKey;
	//��Կ���ݳ��ȣ�������CKA_VALUE_LENһ��ʹ�ã�
	CK_ULONG  ulKeyLen;
	//��Կ����̳���
	CK_ULONG ulKeyMinLen;
	//��Կ����󳤶�
	CK_ULONG ulKeyMaxLen;
	//��Կģ��
	CK_ATTRIBUTE ckAttrTemplate[22];
};
#endif