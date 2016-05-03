/************************************************************************/
/* 
* Copyright (c) 2010-2011, 李耀龙
* All rights reserved.
* 文件名称：
* 文件标识：无
* 摘    要：定义存储对象的类
* 当前版本：1.0
* 作    者：李耀龙
* 完成日期：2011/02/14
*/
/************************************************************************/
/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: PublicKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef PUBLICKEYOBJECT_H
#define PUBLICKEYOBJECT_H

#include "KeyObject.h"

class CPublicKeyObject:public CKeyObject
{
public:
	CPublicKeyObject();
	~CPublicKeyObject(){};
protected:
	//密钥主体名称的DER-编码
	CK_BYTE_PTR pbSubject;
	//如果密钥支持加密，则为TRUE
	CK_BBOOL bEncrypt;
	//如果密钥支持验证，其中签名是数据的一个附录，则为TRUE
	CK_BBOOL bVerify;
	//如果密钥支持验证，其中数据是从签名回复的，则为TRUE;
	CK_BBOOL bVerifyRec;
	//如果密钥支持打包，即可以用来打包其它密钥，则为TRUE；
	CK_BBOOL bWrap;
	//如果对其创建的应用来说，这个密钥是可信的；
	CK_BBOOL bTrusted;
	//对象属性模板
	CK_ATTRIBUTE ckAttrTemplate[17];
};
#endif