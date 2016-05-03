/************************************************************************/
/************************************************************************/
/* 
* Copyright (c) 2009-2010, ��ҫ��
* All rights reserved.
* File Name: KeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef KEYOBJECT_H
#define KEYOBJECT_H

#include "StorageObject.h"

/** 
* @class CKeyObject
* @brief PKCS#11��׼����Կ������
*
* ����������CStorageObject��,��������Կ������ĸ���
* @see CStorageObject
*/
class CKeyObject:public CStorageObject
{
public:
	CKeyObject(){};
	~CKeyObject(){};
protected:
	//��Կ����
	CK_KEY_TYPE ulKeyType;
	//��Կ�ı�ʶ��
	CK_BYTE_PTR pbID;
	//��Կ����������
	CK_DATE     StartDate;
	//��Կ����ֹ����
	CK_DATE     EndDate;
	//�����Կ֧����������ΪTRUE������ΪFALSE
	CK_BBOOL    bDerive;
	//������Կ���������֮һʱ��ΪTRUE:
	//��1��ʹ��C_GenerateKey����C_GenerateKeyPair���ñ������ɣ����ڴ������ϣ���
	//��2��ʹ��C_CopyObject������Ϊһ����Կ�ĸ�������������Կ��CKA_LOCAL�����趨ΪTRUE
	CK_BBOOL    bLocal;
};
#endif