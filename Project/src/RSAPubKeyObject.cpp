/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
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

	//公钥对象的类别属性
	ckAttrTemplate[0].type = CKA_CLASS;
	ckAttrTemplate[0].pValue = &ObjectClass;
	ckAttrTemplate[0].ulValueLen = sizeof(ObjectClass);

	//公钥对象的会话属性
	ckAttrTemplate[1].type = CKA_TOKEN;
	ckAttrTemplate[1].pValue = &bToken;
	ckAttrTemplate[1].ulValueLen = sizeof(bToken);

	//公钥对象的私有属性
	ckAttrTemplate[2].type = CKA_PRIVATE;
	ckAttrTemplate[2].pValue = &bPrivate;
	ckAttrTemplate[2].ulValueLen = sizeof(bPrivate);

	//公钥对象的可修改属性
	ckAttrTemplate[3].type = CKA_MODIFIABLE;
	ckAttrTemplate[3].pValue = &bModifiable;
	ckAttrTemplate[3].ulValueLen = sizeof(bModifiable);

	//公钥对象的标签属性
	ckAttrTemplate[4].type = CKA_LABEL;
	ckAttrTemplate[4].pValue = pUTF8Label;
	ckAttrTemplate[4].ulValueLen = 0; //需要考虑指针指向内存的空间大小

	//公钥对象的密钥类型属性
	ckAttrTemplate[5].type = CKA_KEY_TYPE;
	ckAttrTemplate[5].pValue = &ulKeyType;
	ckAttrTemplate[5].ulValueLen = sizeof(ulKeyType);

	//公钥对象的密钥标识符属性
	pbID = NULL_PTR;
	ckAttrTemplate[6].type = CKA_ID;
	ckAttrTemplate[6].pValue = pbID;
	ckAttrTemplate[6].ulValueLen = 0;

	//公钥对象启用日期属性
	memset(StartDate.year,0,sizeof(StartDate.year));
	memset(StartDate.month,0,sizeof(StartDate.month));
	memset(StartDate.day,0,sizeof(StartDate.day));

	ckAttrTemplate[7].type = CKA_START_DATE;
	ckAttrTemplate[7].pValue = &StartDate;
	ckAttrTemplate[7].ulValueLen = sizeof(StartDate);

	//公钥对象的终止日期属性
	memset(EndDate.year,0,sizeof(EndDate.year));
	memset(EndDate.month,0,sizeof(EndDate.month));
	memset(EndDate.day,0,sizeof(EndDate.day));
	ckAttrTemplate[8].type = CKA_END_DATE;
	ckAttrTemplate[8].pValue = &EndDate;
	ckAttrTemplate[8].ulValueLen = sizeof(EndDate);

	//公钥对象的派生属性
	ckAttrTemplate[9].type = CKA_DERIVE;
	ckAttrTemplate[9].pValue = &bDerive;
	ckAttrTemplate[9].ulValueLen = sizeof(bDerive);

	//公钥对象的本地属性
	ckAttrTemplate[10].type = CKA_LOCAL;
	ckAttrTemplate[10].pValue = &bLocal;
	ckAttrTemplate[10].ulValueLen = sizeof(bLocal);

	//公钥对象的密钥主体名称属性
	ckAttrTemplate[11].type = CKA_SUBJECT;
	ckAttrTemplate[11].pValue = pbSubject;
	ckAttrTemplate[11].ulValueLen = 0;

	//密钥对象的加密属性
	ckAttrTemplate[12].type = CKA_ENCRYPT;
	ckAttrTemplate[12].pValue = &bEncrypt;
	ckAttrTemplate[12].ulValueLen = sizeof(bEncrypt);

	//公钥对象的验证属性
	ckAttrTemplate[13].type = CKA_VERIFY;
	ckAttrTemplate[13].pValue = &bVerify;
	ckAttrTemplate[13].ulValueLen = sizeof(bVerify);

	//公钥对象的验证属性
	ckAttrTemplate[14].type = CKA_VERIFY_RECOVER;
	ckAttrTemplate[14].pValue = &bVerifyRec;
	ckAttrTemplate[14].ulValueLen = sizeof(bVerifyRec);

	//公钥对象的打包属性
	ckAttrTemplate[15].type = CKA_WRAP;
	ckAttrTemplate[15].pValue = &bWrap;
	ckAttrTemplate[15].ulValueLen = sizeof(bWrap);

	//公钥对象的可信属性
	ckAttrTemplate[16].type = CKA_TRUSTED;
	ckAttrTemplate[16].pValue = &bTrusted;
	ckAttrTemplate[16].ulValueLen = sizeof(bTrusted);

	//RSA公钥的模数N的长度
	ulModulusBits = 0;
	ckAttrTemplate[17].type = CKA_MODULUS_BITS;
	ckAttrTemplate[17].pValue = &ulModulusBits;
	ckAttrTemplate[17].ulValueLen = sizeof(ulModulusBits);

	//RSA公钥的模数
	memset(pbModulus,0,sizeof(pbModulus));
	ckAttrTemplate[18].type = CKA_MODULUS;
	ckAttrTemplate[18].pValue = pbModulus;
	ckAttrTemplate[18].ulValueLen = ulModulusBits/8;

	//RSA公钥的公开指数
	memset(pbPubExponent,0,sizeof(pbPubExponent));
	ckAttrTemplate[19].type = CKA_PUBLIC_EXPONENT;
	ckAttrTemplate[19].pValue = pbPubExponent;
	ckAttrTemplate[19].ulValueLen = 0;
}