/************************************************************************/
/* 
* Copyright (c) 2010-2011, 李耀龙
* All rights reserved.
* 文件名称：PrivateKeyObject.h
* 文件标识：无
* 摘    要：定义私钥对象的基类
* 当前版本：1.0
* 作    者：李耀龙
* 完成日期：2011/02/16
*/
/************************************************************************/

#ifndef PRIVATEKEYOBJECT_H
#define PRIVATEKEYOBJECT_H

#include "KeyObject.h"

class CPrivateKeyObject:public CKeyObject
{
public:
	CPrivateKeyObject()
	{
		ObjectClass = CKO_PRIVATE_KEY;
		pbSubject = NULL_PTR;
		bSensitive = CK_FALSE;
		bSecondaryAuth = CK_FALSE;
		AuthPINFlags = 0;
		bDecrypt = CK_FALSE;
		bSign = CK_FALSE;
		bSignRec = CK_FALSE;
		bUnWrap = CK_FALSE;
		bExtractable = CK_FALSE;
		bAlwaysSensitive = CK_FALSE;
		bNeverExtractable = CK_FALSE;
	};
	~CPrivateKeyObject(){};
protected:
	//证书主体名称的DER编码，默认为空
	CK_BYTE_PTR  pbSubject;
	//如果密钥是敏感的，则为真，否则为假
	CK_BBOOL     bSensitive;
	//如果在密钥允许使用前使用二次鉴别发生，则为真（默认为空）
	//反之，引用程序必须设置始终为假，省略模板
	CK_BBOOL     bSecondaryAuth;
	//表征码指示现有二次鉴别PIN状态。如果CKA_SENCONDARY_AUTH错误，则这个属性为0；
	CK_FLAGS     AuthPINFlags;
	//如果密钥支持解密，则为真
	CK_BBOOL     bDecrypt;
	//如果密钥支持签名（在这里该签名是该数据的附录），则为真；
	CK_BBOOL     bSign;
	//如果密钥支持签名（在这里该数据能从签名中恢复），则为真；
	CK_BBOOL     bSignRec;
	//如果密钥支持解密，则为真（即能被作用解密其他密钥）
	CK_BBOOL     bUnWrap;
	//如果密钥能萃取，则为真；
	CK_BBOOL     bExtractable;
	//如果密钥始终把CKA_SENSITIVE属性这是为真，则为真；
	CK_BBOOL     bAlwaysSensitive;
	//如果密钥不能把CKA_EXTRACTABLE属性设置为真，则为真；
	CK_BBOOL     bNeverExtractable;
};
#endif