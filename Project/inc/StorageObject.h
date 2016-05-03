/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: StorageObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef STORAGEOBJECT_H
#define STORAGEOBJECT_H

#include "Object.h"
#include <string>

class CStorageObject:public CObject
{
public:
	CStorageObject();
	~CStorageObject(){};
protected:
	//���������һ�����ƶ�����ΪTRUE�����������һ���Ự������ΪFALSE��ȱʡΪFALSE��
	CK_BBOOL bToken;
	//���������һ��˽�ж�����ΪTRUE�����������һ������������ΪFALSE��
	//ȱʡֵ�������Ʋ�ͬ���仯�ģ������п���ȡ���ڸö����������Ե�ֵ��
	CK_BBOOL bPrivate;
	//���������Ա��޸ģ���ΪTRUE������ΪFALSE��ȱʡΪTRUE��
	CK_BBOOL bModifiable;
	//�����˵����ȱʡΪ�գ�
	CK_UTF8CHAR_PTR pUTF8Label;
};

#endif