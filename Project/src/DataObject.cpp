/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
	//����Ϊ���ݶ���
	ObjectClass = CKO_DATA;

	//������������
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//����ĻỰ�������
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue =&bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//�����˽������
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//����Ŀ��޸�����
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//����ı�ǩ����
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = strlen((const char*)pUTF8Label);

	//�����Ӧ������
	ckAttrTemplate[5].type = CKA_APPLICATION;
	ckAttrTemplate[5].pValue = pUTF8App;
	ckAttrTemplate[5].ulValueLen = strlen((const char*)pUTF8App);

	//�����ID����
	pObjID = NULL_PTR;
	ckAttrTemplate[6].type = CKA_OBJECT_ID;
    ckAttrTemplate[6].pValue = pObjID;
	ckAttrTemplate[6].ulValueLen = 0; //��Ҫ���Ǽ���ָ��ָ���ڴ�ĳ���

	//�����ֵ����
	pObjValue = NULL_PTR;
	ckAttrTemplate[7].type = CKA_VALUE;
	ckAttrTemplate[7].pValue = pObjValue;
	ckAttrTemplate[7].ulValueLen = 0;//��Ҫ���Ǽ���ָ��ָ���ڴ�ĳ���
}