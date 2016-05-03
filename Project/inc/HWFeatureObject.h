/************************************************************************/
/* 
* Copyright (c) 2009-2010, 李耀龙
* All rights reserved.
* File Name: HWFeatureObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/

#ifndef HWFEATUREOBJECT_H
#define HWFEATUREOBJECT_H

#include "Object.h"

class CHWFeatureObject:public CObject
{
public:
	CHWFeatureObject();
	~CHWFeatureObject(){};
protected:
	CK_HW_FEATURE_TYPE hwFeatureType;
private:
	CK_ATTRIBUTE ckAttrTemplate[2];
public:
	//创建对象
	CK_RV C_CreateObject(CK_SESSION_HANDLE hSession, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phObject);
	//修改对象的值
	CK_RV C_SetAttributeValue(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount);
	//复制对象
	CK_RV C_CopyObject(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phNewObject);
};

#endif