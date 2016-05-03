
/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: HWFeatureObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\HWFeatureObject.h"

CHWFeatureObject::CHWFeatureObject()
{
	//��ʶΪӲ����������
	ObjectClass = CKO_HW_FEATURE;

	//�����������
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);
	
	//ʹ�ñ������ֶΣ�˵����ǰû�м�������ʵʱʱ�ӣ�
	hwFeatureType = CKH_VENDOR_DEFINED; 

    //Ӳ���������ԣ���Ҫָ���Ƿ���ʵʱʱ�����������
	ckAttrTemplate[1].type = CKA_HW_FEATURE_TYPE;
	ckAttrTemplate[1].pValue = &hwFeatureType;
	ckAttrTemplate[1].ulValueLen = sizeof(hwFeatureType);

};

CK_RV CHWFeatureObject::C_CreateObject(CK_SESSION_HANDLE hSession, 
	                               CK_ATTRIBUTE_PTR pTemplate, 
	                               CK_ULONG ulCount, 
	                               CK_OBJECT_HANDLE_PTR phObject)
{
	CK_RV ckRetVal = CKR_ATTRIBUTE_TYPE_INVALID;
	return ckRetVal;
}

CK_RV CHWFeatureObject::C_SetAttributeValue(CK_SESSION_HANDLE hSession, 
	                                   CK_OBJECT_HANDLE hObject,
									   CK_ATTRIBUTE_PTR pTemplate,
									   CK_ULONG ulCount)
{
	CK_RV ckRetVal = CKR_ATTRIBUTE_TYPE_INVALID;
	return ckRetVal;
}
CK_RV CHWFeatureObject::C_CopyObject(CK_SESSION_HANDLE hSession, 
	                             CK_OBJECT_HANDLE hObject, 
							     CK_ATTRIBUTE_PTR pTemplate, 
								 CK_ULONG ulCount, 
								 CK_OBJECT_HANDLE_PTR phNewObject)
{
	CK_RV ckRetVal = CKR_ATTRIBUTE_TYPE_INVALID;
	return ckRetVal;
}