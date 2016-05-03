/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
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
	//当前对象的属性集合
	CK_ATTRIBUTE ckAttrTemplate[7];
	//对象的应用名称；
	CK_UTF8CHAR_PTR pUTF8App;
	//对象ID，字节数组，为DER编码
	CK_BYTE_PTR pObjID;
	//对象的实际数值
	CK_BYTE_PTR pObjValue;
};
#endif