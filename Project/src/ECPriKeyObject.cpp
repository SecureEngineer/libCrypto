/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: ECPriKeyObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/12/13
*/
/************************************************************************/
#include "..\inc\ECPriKeyObject.h"

CECPriKeyObject::CECPriKeyObject()
{
	//��������Ϊ˽Կ
	ObjectClass = CKO_PRIVATE_KEY;
	//��Կ����ΪRSA������Կ
	ulKeyType = CKK_RSA;

	//RSA˽Կ������������
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//RSA˽Կ����ĻỰ����
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//RSA˽Կ�����˽������
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//RSA˽Կ����Ŀ��޸�����
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//RSA˽Կ����ı�ǩ����
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = 0; //��Ҫ����ָ��ָ���ڴ�Ŀռ��С

	//RSA˽Կ�������Կ��������
	ckAttrTemplate[5].type = CKA_KEY_TYPE;
	ckAttrTemplate[5].pValue = &ulKeyType;
	ckAttrTemplate[5].ulValueLen = sizeof(ulKeyType);

	//RSA˽Կ�������Կ��ʶ������
	pbID = NULL_PTR;
	ckAttrTemplate[6].type = CKA_ID;
	ckAttrTemplate[6].pValue = pbID;
	ckAttrTemplate[6].ulValueLen = 0;

	//RSA˽Կ����������������
	memset(StartDate.year,0,sizeof(StartDate.year));
	memset(StartDate.month,0,sizeof(StartDate.month));
	memset(StartDate.day,0,sizeof(StartDate.day));

	ckAttrTemplate[7].type = CKA_START_DATE;
	ckAttrTemplate[7].pValue = &StartDate;
	ckAttrTemplate[7].ulValueLen = sizeof(StartDate);

	//RSA˽Կ�������ֹ��������
	memset(EndDate.year,0,sizeof(EndDate.year));
	memset(EndDate.month,0,sizeof(EndDate.month));
	memset(EndDate.day,0,sizeof(EndDate.day));
	ckAttrTemplate[8].type = CKA_END_DATE;
	ckAttrTemplate[8].pValue = &EndDate;
	ckAttrTemplate[8].ulValueLen = sizeof(EndDate);

	//RSA˽Կ�������������
	ckAttrTemplate[9].type = CKA_DERIVE;
	ckAttrTemplate[9].pValue = &bDerive;
	ckAttrTemplate[9].ulValueLen = sizeof(bDerive);

	//RSA˽Կ����ı�������
	ckAttrTemplate[10].type = CKA_LOCAL;
	ckAttrTemplate[10].pValue = &bLocal;
	ckAttrTemplate[10].ulValueLen = sizeof(bLocal);

	//������������
	ckAttrTemplate[11].type = CKA_SUBJECT;
	ckAttrTemplate[11].pValue = pbSubject;
	ckAttrTemplate[11].ulValueLen = 0;

	//��������
	ckAttrTemplate[12].type = CKA_SENSITIVE;
	ckAttrTemplate[12].pValue = &bSensitive;
	ckAttrTemplate[12].ulValueLen = sizeof(bSensitive);

	//���μ�������
	ckAttrTemplate[13].type = CKA_SECONDARY_AUTH;
	ckAttrTemplate[13].pValue = &bSecondaryAuth;
	ckAttrTemplate[13].ulValueLen = sizeof(bSecondaryAuth);

	//���μ����״̬
	ckAttrTemplate[14].type = CKA_AUTH_PIN_FLAGS;
	ckAttrTemplate[14].pValue = &AuthPINFlags;
	ckAttrTemplate[14].ulValueLen = sizeof(AuthPINFlags);

	//֧�ֽ�������
	ckAttrTemplate[15].type = CKA_DECRYPT;
	ckAttrTemplate[15].pValue = &bDecrypt;
	ckAttrTemplate[15].ulValueLen = sizeof(bDecrypt);

	//֧��ǩ������
	ckAttrTemplate[16].type = CKA_SIGN;
	ckAttrTemplate[16].pValue = &bSign;
	ckAttrTemplate[16].ulValueLen = sizeof(bSign);

	//֧��ǩ���ָ�����
	ckAttrTemplate[17].type = CKA_SIGN_RECOVER;
	ckAttrTemplate[17].pValue = &bSignRec;
	ckAttrTemplate[17].ulValueLen = sizeof(bSignRec);

	//֧�ֽ���������Կ����
	ckAttrTemplate[18].type = CKA_UNWRAP;
	ckAttrTemplate[18].pValue = &bUnWrap;
	ckAttrTemplate[18].ulValueLen = sizeof(bUnWrap);

	//��ȡ����
	ckAttrTemplate[19].type = CKA_EXTRACTABLE;
	ckAttrTemplate[19].pValue = &bExtractable;
	ckAttrTemplate[19].ulValueLen = sizeof(bExtractable);

	//
	ckAttrTemplate[20].type = CKA_ALWAYS_SENSITIVE;
	ckAttrTemplate[20].pValue = &bAlwaysSensitive;
	ckAttrTemplate[20].ulValueLen = sizeof(bAlwaysSensitive);

	//
	ckAttrTemplate[21].type = CKA_NEVER_EXTRACTABLE;
	ckAttrTemplate[21].pValue = &bNeverExtractable;
	ckAttrTemplate[21].ulValueLen = sizeof(bNeverExtractable);
};