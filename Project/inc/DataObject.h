/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: DataObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef DATAOBJECT_H  
#define DATAOBJECT_H

#include "StorageObject.h"

class CDataObject:public CStorageObject
{
public:
	CDataObject();
	~CDataObject(){};
protected:
	//��ǰ��������Լ���
	CK_ATTRIBUTE ckAttrTemplate[7];
	//�����Ӧ�����ƣ�
	CK_UTF8CHAR_PTR pUTF8App;
	//����ID���ֽ����飬ΪDER����
	CK_BYTE_PTR pObjID;
	//�����ʵ����ֵ
	CK_BYTE_PTR pObjValue;
};
#endif