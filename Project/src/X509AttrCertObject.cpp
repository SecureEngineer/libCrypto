/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: X509AttrCertObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\X509AttrCertObject.h"

CX509AttrCertObject::CX509AttrCertObject()
{
	//����ö���ΪX509��Կ֤��
	certType = CKC_X_509_ATTR_CERT;

	//��Կ֤�������������
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//��Կ֤�����ĻỰ����
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//��Կ֤������˽������
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//��Կ֤�����Ŀ��޸�����
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//��Կ֤�����ı�ǩ����
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = 0; //��Ҫ����ָ��ָ���ڴ�Ŀռ��С

	//��Կ֤������֤����������
	ckAttrTemplate[5].type = CKA_CERTIFICATE_TYPE;
	ckAttrTemplate[5].pValue = &certType;
	ckAttrTemplate[5].ulValueLen = sizeof(certType);

	//��Կ֤�����Ŀ���������
	ckAttrTemplate[6].type = CKA_TRUSTED;
	ckAttrTemplate[6].pValue = &bTrusted;
	ckAttrTemplate[6].ulValueLen = sizeof(bTrusted);

	//����֤�����������ֶ���������
	ckAttrTemplate[7].type = CKA_OWNER;
	ckAttrTemplate[7].pValue = pbOwner;
	ckAttrTemplate[7].ulValueLen = 0; //��Ҫ����ָ��ָ���ڴ�ĳ���

	//����֤�鷢��������
	pbACIssuer = NULL_PTR; //ȱʡΪ��
	ckAttrTemplate[8].type = CKA_AC_ISSUER;
	ckAttrTemplate[8].pValue = pbACIssuer;
	ckAttrTemplate[8].ulValueLen = 0;//��Ҫ����ָ��ָ���ڴ�ĳ���

	//����֤���������к�����
	pbSerialNumber = NULL_PTR;
	ckAttrTemplate[9].type = CKA_SERIAL_NUMBER;
	ckAttrTemplate[9].pValue = pbSerialNumber;
	ckAttrTemplate[9].ulValueLen = 0;

	//����֤���������к�����
	pbAttrTypes = NULL_PTR;
	ckAttrTemplate[10].type = CKA_ATTR_TYPES;
	ckAttrTemplate[10].pValue = pbAttrTypes;
	ckAttrTemplate[10].ulValueLen = 0;

	//��Կ֤���������кű���
	pbValue = NULL_PTR;
	ckAttrTemplate[11].type = CKA_VALUE;
	ckAttrTemplate[11].pValue = pbValue;
	ckAttrTemplate[11].ulValueLen = 0;
}