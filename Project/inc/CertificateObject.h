/************************************************************************/
/* 
* Copyright (c) 2015, ��ҫ��
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
		//��ʼ��Ϊ�����ֶΣ�
		certType = CKC_VENDOR_DEFINED;
		//֤��Ϊ�����ŵģ�
		bTrusted = CK_FALSE;
		//��������
		ObjectClass = CKO_CERTIFICATE;
	};
	~CCertificateObject(){};
protected:
	//֤������
	CK_CERTIFICATE_TYPE certType;
	//֤���Ƿ����
	CK_BBOOL bTrusted;
};
#endif