/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
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
	//如果对象是一个令牌对象，则为TRUE；如果对象是一个会话对象则为FALSE；缺省为FALSE；
	CK_BBOOL bToken;
	//如果对象是一个私有对象，则为TRUE；如果对象是一个公开对象，则为FALSE；
	//缺省值是随令牌不同而变化的，并且有可能取决于该对象其它属性的值；
	CK_BBOOL bPrivate;
	//如果对象可以被修改，则为TRUE；否则为FALSE；缺省为TRUE；
	CK_BBOOL bModifiable;
	//对象的说明，缺省为空；
	CK_UTF8CHAR_PTR pUTF8Label;
};

#endif