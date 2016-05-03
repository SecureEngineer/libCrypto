/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: StorageObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\StorageObject.h"

CStorageObject::CStorageObject()
{
	//全部初始化为缺省值
	bToken = CK_FALSE; 
	bPrivate = CK_FALSE;
	bModifiable = CK_TRUE;
	pUTF8Label = NULL_PTR;
}