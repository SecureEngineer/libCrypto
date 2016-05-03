/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
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
	//对象类型为私钥
	ObjectClass = CKO_PRIVATE_KEY;
	//密钥类型为RSA类型密钥
	ulKeyType = CKK_RSA;

	//RSA私钥对象的类别属性
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//RSA私钥对象的会话属性
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//RSA私钥对象的私有属性
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//RSA私钥对象的可修改属性
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//RSA私钥对象的标签属性
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = 0; //需要考虑指针指向内存的空间大小

	//RSA私钥对象的密钥类型属性
	ckAttrTemplate[5].type = CKA_KEY_TYPE;
	ckAttrTemplate[5].pValue = &ulKeyType;
	ckAttrTemplate[5].ulValueLen = sizeof(ulKeyType);

	//RSA私钥对象的密钥标识符属性
	pbID = NULL_PTR;
	ckAttrTemplate[6].type = CKA_ID;
	ckAttrTemplate[6].pValue = pbID;
	ckAttrTemplate[6].ulValueLen = 0;

	//RSA私钥对象启用日期属性
	memset(StartDate.year,0,sizeof(StartDate.year));
	memset(StartDate.month,0,sizeof(StartDate.month));
	memset(StartDate.day,0,sizeof(StartDate.day));

	ckAttrTemplate[7].type = CKA_START_DATE;
	ckAttrTemplate[7].pValue = &StartDate;
	ckAttrTemplate[7].ulValueLen = sizeof(StartDate);

	//RSA私钥对象的终止日期属性
	memset(EndDate.year,0,sizeof(EndDate.year));
	memset(EndDate.month,0,sizeof(EndDate.month));
	memset(EndDate.day,0,sizeof(EndDate.day));
	ckAttrTemplate[8].type = CKA_END_DATE;
	ckAttrTemplate[8].pValue = &EndDate;
	ckAttrTemplate[8].ulValueLen = sizeof(EndDate);

	//RSA私钥对象的派生属性
	ckAttrTemplate[9].type = CKA_DERIVE;
	ckAttrTemplate[9].pValue = &bDerive;
	ckAttrTemplate[9].ulValueLen = sizeof(bDerive);

	//RSA私钥对象的本地属性
	ckAttrTemplate[10].type = CKA_LOCAL;
	ckAttrTemplate[10].pValue = &bLocal;
	ckAttrTemplate[10].ulValueLen = sizeof(bLocal);

	//主体名称属性
	ckAttrTemplate[11].type = CKA_SUBJECT;
	ckAttrTemplate[11].pValue = pbSubject;
	ckAttrTemplate[11].ulValueLen = 0;

	//敏感属性
	ckAttrTemplate[12].type = CKA_SENSITIVE;
	ckAttrTemplate[12].pValue = &bSensitive;
	ckAttrTemplate[12].ulValueLen = sizeof(bSensitive);

	//二次鉴别属性
	ckAttrTemplate[13].type = CKA_SECONDARY_AUTH;
	ckAttrTemplate[13].pValue = &bSecondaryAuth;
	ckAttrTemplate[13].ulValueLen = sizeof(bSecondaryAuth);

	//二次鉴别的状态
	ckAttrTemplate[14].type = CKA_AUTH_PIN_FLAGS;
	ckAttrTemplate[14].pValue = &AuthPINFlags;
	ckAttrTemplate[14].ulValueLen = sizeof(AuthPINFlags);

	//支持解密属性
	ckAttrTemplate[15].type = CKA_DECRYPT;
	ckAttrTemplate[15].pValue = &bDecrypt;
	ckAttrTemplate[15].ulValueLen = sizeof(bDecrypt);

	//支持签名属性
	ckAttrTemplate[16].type = CKA_SIGN;
	ckAttrTemplate[16].pValue = &bSign;
	ckAttrTemplate[16].ulValueLen = sizeof(bSign);

	//支持签名恢复属性
	ckAttrTemplate[17].type = CKA_SIGN_RECOVER;
	ckAttrTemplate[17].pValue = &bSignRec;
	ckAttrTemplate[17].ulValueLen = sizeof(bSignRec);

	//支持解密其他密钥属性
	ckAttrTemplate[18].type = CKA_UNWRAP;
	ckAttrTemplate[18].pValue = &bUnWrap;
	ckAttrTemplate[18].ulValueLen = sizeof(bUnWrap);

	//萃取属性
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