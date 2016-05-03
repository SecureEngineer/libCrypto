/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
* All rights reserved.
* File Name: RSAPubKeyObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\RSAPubKeyObject.h"

CRSAPubKeyObject::CRSAPubKeyObject()
{
	ulKeyType = CKK_RSA;

	//��Կ������������
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//��Կ����ĻỰ����
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//��Կ�����˽������
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//��Կ����Ŀ��޸�����
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//��Կ����ı�ǩ����
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = 0; //��Ҫ����ָ��ָ���ڴ�Ŀռ��С

	//��Կ�������Կ��������
	ckAttrTemplate[5].type = CKA_KEY_TYPE;
	ckAttrTemplate[5].pValue = &ulKeyType;
	ckAttrTemplate[5].ulValueLen = sizeof(ulKeyType);

	//��Կ�������Կ��ʶ������
	pbID = NULL_PTR;
	ckAttrTemplate[6].type = CKA_ID;
	ckAttrTemplate[6].pValue = pbID;
	ckAttrTemplate[6].ulValueLen = 0;

	//��Կ����������������
	memset(StartDate.year,0,sizeof(StartDate.year));
	memset(StartDate.month,0,sizeof(StartDate.month));
	memset(StartDate.day,0,sizeof(StartDate.day));

	ckAttrTemplate[7].type = CKA_START_DATE;
	ckAttrTemplate[7].pValue = &StartDate;
	ckAttrTemplate[7].ulValueLen = sizeof(StartDate);

	//��Կ�������ֹ��������
	memset(EndDate.year,0,sizeof(EndDate.year));
	memset(EndDate.month,0,sizeof(EndDate.month));
	memset(EndDate.day,0,sizeof(EndDate.day));
	ckAttrTemplate[8].type = CKA_END_DATE;
	ckAttrTemplate[8].pValue = &EndDate;
	ckAttrTemplate[8].ulValueLen = sizeof(EndDate);

	//��Կ�������������
	ckAttrTemplate[9].type = CKA_DERIVE;
	ckAttrTemplate[9].pValue = &bDerive;
	ckAttrTemplate[9].ulValueLen = sizeof(bDerive);

	//��Կ����ı�������
	ckAttrTemplate[10].type = CKA_LOCAL;
	ckAttrTemplate[10].pValue = &bLocal;
	ckAttrTemplate[10].ulValueLen = sizeof(bLocal);

	//��Կ�������Կ������������
	ckAttrTemplate[11].type = CKA_SUBJECT;
	ckAttrTemplate[11].pValue = pbSubject;
	ckAttrTemplate[11].ulValueLen = 0;

	//��Կ����ļ�������
	ckAttrTemplate[12].type = CKA_ENCRYPT;
	ckAttrTemplate[12].pValue = &bEncrypt;
	ckAttrTemplate[12].ulValueLen = sizeof(bEncrypt);

	//��Կ�������֤����
	ckAttrTemplate[13].type = CKA_VERIFY;
	ckAttrTemplate[13].pValue = &bVerify;
	ckAttrTemplate[13].ulValueLen = sizeof(bVerify);

	//��Կ�������֤����
	ckAttrTemplate[14].type = CKA_VERIFY_RECOVER;
	ckAttrTemplate[14].pValue = &bVerifyRec;
	ckAttrTemplate[14].ulValueLen = sizeof(bVerifyRec);

	//��Կ����Ĵ������
	ckAttrTemplate[15].type = CKA_WRAP;
	ckAttrTemplate[15].pValue = &bWrap;
	ckAttrTemplate[15].ulValueLen = sizeof(bWrap);

	//��Կ����Ŀ�������
	ckAttrTemplate[16].type = CKA_TRUSTED;
	ckAttrTemplate[16].pValue = &bTrusted;
	ckAttrTemplate[16].ulValueLen = sizeof(bTrusted);

	//RSA��Կ��ģ��N�ĳ���
	ulModulusBits = 0;
	ckAttrTemplate[17].type = CKA_MODULUS_BITS;
	ckAttrTemplate[17].pValue = &ulModulusBits;
	ckAttrTemplate[17].ulValueLen = sizeof(ulModulusBits);

	//RSA��Կ��ģ��
	memset(pbModulus,0,sizeof(pbModulus));
	ckAttrTemplate[18].type = CKA_MODULUS;
	ckAttrTemplate[18].pValue = pbModulus;
	ckAttrTemplate[18].ulValueLen = ulModulusBits/8;

	//RSA��Կ�Ĺ���ָ��
	memset(pbPubExponent,0,sizeof(pbPubExponent));
	ckAttrTemplate[19].type = CKA_PUBLIC_EXPONENT;
	ckAttrTemplate[19].pValue = pbPubExponent;
	ckAttrTemplate[19].ulValueLen = 0;
}