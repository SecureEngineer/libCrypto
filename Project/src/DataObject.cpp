/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: DataObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\DataObject.h"

CDataObject::CDataObject()
{
	//对象为数据对象
	ObjectClass = CKO_DATA;

	//对象的类别属性
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//对象的会话类别属性
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue =&bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//对象的私有属性
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//对象的可修改属性
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//对象的标签属性
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = strlen((const char*)pUTF8Label);

	//对象的应用属性
	ckAttrTemplate[5].type = CKA_APPLICATION;
	ckAttrTemplate[5].pValue = pUTF8App;
	ckAttrTemplate[5].ulValueLen = strlen((const char*)pUTF8App);

	//对象的ID属性
	pObjID = NULL_PTR;
	ckAttrTemplate[6].type = CKA_OBJECT_ID;
    ckAttrTemplate[6].pValue = pObjID;
	ckAttrTemplate[6].ulValueLen = 0; //需要考虑计算指针指向内存的长度

	//对象的值属性
	pObjValue = NULL_PTR;
	ckAttrTemplate[7].type = CKA_VALUE;
	ckAttrTemplate[7].pValue = pObjValue;
	ckAttrTemplate[7].ulValueLen = 0;//需要考虑计算指针指向内存的长度
}