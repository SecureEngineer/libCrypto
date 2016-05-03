/************************************************************************/
/* 
* Copyright (c) 2009-2010, ÀîÒ«Áú
* All rights reserved.
* File Name: Object.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\Object.h"

CObject::CObject()
{
	ObjectClass = CKO_VENDOR_DEFINED;

	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);
}