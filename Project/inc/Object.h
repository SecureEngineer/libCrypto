/************************************************************************/
/* 
* Copyright (c) 2009-2010, 李耀龙
* All rights reserved.
* File Name: Object.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef OBJECT_H
#define OBJECT_H

#include "global.h"

class CObject
{
public:
	CObject();
	~CObject(){};
public:
	/**  
	* @brief      创建对象的纯虚函数 
	* @return     
	* @retval     
	*/
    virtual CK_RV C_CreateObject(CK_SESSION_HANDLE hSession,CK_ATTRIBUTE_PTR pTemplate,CK_ULONG ulCount,CK_OBJECT_HANDLE_PTR phObject)=0; 
	/**  
	* @brief      修改对象的纯虚函数 
	* @return     
	* @retval     
	*/
	virtual CK_RV C_SetAttributeValue(CK_SESSION_HANDLE hSession,CK_OBJECT_HANDLE hObject,CK_ATTRIBUTE_PTR pTemplate,CK_ULONG ulCount)=0;
	/**  
	* @brief      复制对象的纯虚函数 
	* @return     
	* @retval     
	*/
	virtual CK_RV C_CopyObject(CK_SESSION_HANDLE hSession,CK_OBJECT_HANDLE hObject,CK_ATTRIBUTE_PTR pTemplate,CK_ULONG ulCount,CK_OBJECT_HANDLE_PTR phNewObject)=0;
protected:
	//标识对象类别（类型）的一个值，是所有对象的公共属性
	CK_OBJECT_CLASS ObjectClass;
private:
	//属性的模板集合
	CK_ATTRIBUTE ckAttrTemplate[1];
};
#endif