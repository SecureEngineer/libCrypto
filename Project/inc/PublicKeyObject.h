/************************************************************************/
/* 
* Copyright (c) 2010-2011, ��ҫ��
* All rights reserved.
* �ļ����ƣ�
* �ļ���ʶ����
* ժ    Ҫ������洢�������
* ��ǰ�汾��1.0
* ��    �ߣ���ҫ��
* ������ڣ�2011/02/14
*/
/************************************************************************/
/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: PublicKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef PUBLICKEYOBJECT_H
#define PUBLICKEYOBJECT_H

#include "KeyObject.h"

class CPublicKeyObject:public CKeyObject
{
public:
	CPublicKeyObject();
	~CPublicKeyObject(){};
protected:
	//��Կ�������Ƶ�DER-����
	CK_BYTE_PTR pbSubject;
	//�����Կ֧�ּ��ܣ���ΪTRUE
	CK_BBOOL bEncrypt;
	//�����Կ֧����֤������ǩ�������ݵ�һ����¼����ΪTRUE
	CK_BBOOL bVerify;
	//�����Կ֧����֤�����������Ǵ�ǩ���ظ��ģ���ΪTRUE;
	CK_BBOOL bVerifyRec;
	//�����Կ֧�ִ�����������������������Կ����ΪTRUE��
	CK_BBOOL bWrap;
	//������䴴����Ӧ����˵�������Կ�ǿ��ŵģ�
	CK_BBOOL bTrusted;
	//��������ģ��
	CK_ATTRIBUTE ckAttrTemplate[17];
};
#endif