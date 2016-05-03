/************************************************************************/
/* 
* Copyright (c) 2015, 李耀龙
* All rights reserved.
* File Name: CertificateObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef CERTIFICATEOBJECT_H
#define CERTIFICATEOBJECT_H

#include "StorageObject.h"

class CCertificateObject:public CStorageObject
{
public:
	CCertificateObject()
	{
		//初始化为保留字段；
		certType = CKC_VENDOR_DEFINED;
		//证书为不可信的；
		bTrusted = CK_FALSE;
		//对象类型
		ObjectClass = CKO_CERTIFICATE;
	};
	~CCertificateObject(){};
protected:
	//证书类型
	CK_CERTIFICATE_TYPE certType;
	//证书是否可信
	CK_BBOOL bTrusted;
};
#endif