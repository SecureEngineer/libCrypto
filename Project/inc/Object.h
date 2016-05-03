/************************************************************************/
/* 
* Copyright (c) 2009-2010, ��ҫ��
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
	* @brief      ��������Ĵ��麯�� 
	* @return     
	* @retval     
	*/
    virtual CK_RV C_CreateObject(CK_SESSION_HANDLE hSession,CK_ATTRIBUTE_PTR pTemplate,CK_ULONG ulCount,CK_OBJECT_HANDLE_PTR phObject)=0; 
	/**  
	* @brief      �޸Ķ���Ĵ��麯�� 
	* @return     
	* @retval     
	*/
	virtual CK_RV C_SetAttributeValue(CK_SESSION_HANDLE hSession,CK_OBJECT_HANDLE hObject,CK_ATTRIBUTE_PTR pTemplate,CK_ULONG ulCount)=0;
	/**  
	* @brief      ���ƶ���Ĵ��麯�� 
	* @return     
	* @retval     
	*/
	virtual CK_RV C_CopyObject(CK_SESSION_HANDLE hSession,CK_OBJECT_HANDLE hObject,CK_ATTRIBUTE_PTR pTemplate,CK_ULONG ulCount,CK_OBJECT_HANDLE_PTR phNewObject)=0;
protected:
	//��ʶ����������ͣ���һ��ֵ�������ж���Ĺ�������
	CK_OBJECT_CLASS ObjectClass;
private:
	//���Ե�ģ�弯��
	CK_ATTRIBUTE ckAttrTemplate[1];
};
#endif