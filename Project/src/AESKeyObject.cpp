/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: AESKeyObject.cpp
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#include "..\inc\AESKeyObject.h"

CAESKeyObject::CAESKeyObject()
{
	//长度从16-32字节，有最大长度和最小长度
	ulKeyMinLen = 16;
	ulKeyMaxLen = 32;
	ulKeyLen = 0; 

	//分配内存，按照密钥的最长长度分配；
	pbKey = new CK_BYTE[ulKeyMaxLen];
	memset(pbKey,0,ulKeyMaxLen); 

	ObjectClass = CKO_SECRET_KEY;
	ulKeyType = CKK_AES;
	ulKeyLen = 0;
	pbKey = NULL_PTR;

	//密钥模板；
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bModifiable;
	ckAttrTemplate[2].ulValueLen = sizeof(bModifiable);

	ckAttrTemplate[3].type = CKA_LABEL;
	ckAttrTemplate[3].pValue = pUTF8Label;
	ckAttrTemplate[3].ulValueLen = 0;

	ckAttrTemplate[4].type = CKA_KEY_TYPE;
	ckAttrTemplate[4].pValue = &ulKeyType;
	ckAttrTemplate[4].ulValueLen = sizeof(ulKeyType);

	ckAttrTemplate[5].type = CKA_ID;
	ckAttrTemplate[5].pValue = pbID;
	ckAttrTemplate[5].ulValueLen = 0;

	ckAttrTemplate[6].type = CKA_START_DATE;
	ckAttrTemplate[6].pValue = &StartDate;
	ckAttrTemplate[6].ulValueLen = sizeof(StartDate);

	ckAttrTemplate[7].type = CKA_END_DATE;
	ckAttrTemplate[7].pValue = &EndDate;
	ckAttrTemplate[7].ulValueLen = sizeof(EndDate);

	ckAttrTemplate[8].type = CKA_DERIVE;
	ckAttrTemplate[8].pValue = &bDerive;
	ckAttrTemplate[8].ulValueLen = sizeof(bDerive);

	ckAttrTemplate[9].type = CKA_LOCAL;
	ckAttrTemplate[9].pValue = &bLocal;
	ckAttrTemplate[9].ulValueLen = sizeof(bLocal);

	ckAttrTemplate[10].type = CKA_SENSITIVE;
	ckAttrTemplate[10].pValue = &bSensitive;
	ckAttrTemplate[10].ulValueLen = sizeof(bSensitive);

	ckAttrTemplate[11].type = CKA_ENCRYPT;
	ckAttrTemplate[11].pValue = &bEncrypt;
	ckAttrTemplate[11].ulValueLen = sizeof(bEncrypt);

	ckAttrTemplate[12].type = CKA_DECRYPT;
	ckAttrTemplate[12].pValue = &bDecrypt;
	ckAttrTemplate[12].ulValueLen = sizeof(bDecrypt);

	ckAttrTemplate[13].type = CKA_SIGN;
	ckAttrTemplate[13].pValue = &bSign;
	ckAttrTemplate[13].ulValueLen = sizeof(bSign);

	ckAttrTemplate[14].type = CKA_VERIFY;
	ckAttrTemplate[14].pValue = &bVerify;
	ckAttrTemplate[14].ulValueLen = sizeof(bVerify);

	ckAttrTemplate[15].type = CKA_WRAP;
	ckAttrTemplate[15].pValue = &bWrap;
	ckAttrTemplate[15].ulValueLen = sizeof(bWrap);

	ckAttrTemplate[16].type = CKA_UNWRAP;
	ckAttrTemplate[16].pValue = &bUnWrap;
	ckAttrTemplate[16].ulValueLen = sizeof(bUnWrap);

	ckAttrTemplate[17].type = CKA_EXTRACTABLE;
	ckAttrTemplate[17].pValue = &bExtractable;
	ckAttrTemplate[17].ulValueLen = sizeof(bExtractable);

	ckAttrTemplate[18].type = CKA_ALWAYS_SENSITIVE;
	ckAttrTemplate[18].pValue = &bAlwaysSensitive;
	ckAttrTemplate[18].ulValueLen = sizeof(bAlwaysSensitive);

	ckAttrTemplate[19].type = CKA_NEVER_EXTRACTABLE;
	ckAttrTemplate[19].pValue = &bNeverExtractable;
	ckAttrTemplate[19].ulValueLen = sizeof(bNeverExtractable);

	ckAttrTemplate[20].type = CKA_VALUE;
	ckAttrTemplate[20].pValue = pbKey;
	ckAttrTemplate[20].ulValueLen = 0;
};
CAESKeyObject::~CAESKeyObject()
{
	if (pbKey)
	{
		delete pbKey;
		pbKey = NULL;
		ulKeyLen = 0;
	}
};