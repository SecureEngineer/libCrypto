/************************************************************************/
/* 
* Copyright (c) 2010-2011, ��ҫ��
* All rights reserved.
* �ļ����ƣ�PrivateKeyObject.h
* �ļ���ʶ����
* ժ    Ҫ������˽Կ����Ļ���
* ��ǰ�汾��1.0
* ��    �ߣ���ҫ��
* ������ڣ�2011/02/16
*/
/************************************************************************/

#ifndef PRIVATEKEYOBJECT_H
#define PRIVATEKEYOBJECT_H

#include "KeyObject.h"

class CPrivateKeyObject:public CKeyObject
{
public:
	CPrivateKeyObject()
	{
		ObjectClass = CKO_PRIVATE_KEY;
		pbSubject = NULL_PTR;
		bSensitive = CK_FALSE;
		bSecondaryAuth = CK_FALSE;
		AuthPINFlags = 0;
		bDecrypt = CK_FALSE;
		bSign = CK_FALSE;
		bSignRec = CK_FALSE;
		bUnWrap = CK_FALSE;
		bExtractable = CK_FALSE;
		bAlwaysSensitive = CK_FALSE;
		bNeverExtractable = CK_FALSE;
	};
	~CPrivateKeyObject(){};
protected:
	//֤���������Ƶ�DER���룬Ĭ��Ϊ��
	CK_BYTE_PTR  pbSubject;
	//�����Կ�����еģ���Ϊ�棬����Ϊ��
	CK_BBOOL     bSensitive;
	//�������Կ����ʹ��ǰʹ�ö��μ���������Ϊ�棨Ĭ��Ϊ�գ�
	//��֮�����ó����������ʼ��Ϊ�٣�ʡ��ģ��
	CK_BBOOL     bSecondaryAuth;
	//������ָʾ���ж��μ���PIN״̬�����CKA_SENCONDARY_AUTH�������������Ϊ0��
	CK_FLAGS     AuthPINFlags;
	//�����Կ֧�ֽ��ܣ���Ϊ��
	CK_BBOOL     bDecrypt;
	//�����Կ֧��ǩ�����������ǩ���Ǹ����ݵĸ�¼������Ϊ�棻
	CK_BBOOL     bSign;
	//�����Կ֧��ǩ����������������ܴ�ǩ���лָ�������Ϊ�棻
	CK_BBOOL     bSignRec;
	//�����Կ֧�ֽ��ܣ���Ϊ�棨���ܱ����ý���������Կ��
	CK_BBOOL     bUnWrap;
	//�����Կ����ȡ����Ϊ�棻
	CK_BBOOL     bExtractable;
	//�����Կʼ�հ�CKA_SENSITIVE��������Ϊ�棬��Ϊ�棻
	CK_BBOOL     bAlwaysSensitive;
	//�����Կ���ܰ�CKA_EXTRACTABLE��������Ϊ�棬��Ϊ�棻
	CK_BBOOL     bNeverExtractable;
};
#endif