/************************************************************************/
/* 
 * Copyright (c) 2015, 李耀龙
 * All rights reserved.
 * File Name: Slot.cpp
 * Version  : 1.0
 * Author   : Li Yao Long
 * Date     : 2015/10/13
 */
/************************************************************************/
/**************************** 头文件 ****************************/
#include "..\inc\Mechanism.h"

CMechanism::CMechanism(
	CK_ULONG    ulType,
	CK_VOID_PTR parameter,
	CK_ULONG    ulParaLen,
	CK_ULONG    ulMinKeySize,
	CK_ULONG    ulMaxKeySize,
	CK_ULONG    ulFlags)
{
	//
	m_ulType = ulType;
	if (parameter && ulParaLen != 0)
	{
		m_ulParameterLen = ulParaLen;
		m_pParameter = new unsigned char[m_ulParameterLen];
		memset(m_pParameter,0,m_ulParameterLen);
		memcpy(m_pParameter,parameter,m_ulParameterLen);
	}
	else
	{
		m_ulParameterLen = 0;
		m_pParameter = NULL;
	}
	m_ulMinKeySize = ulMinKeySize;
	m_ulMaxKeySize = ulMaxKeySize;
	m_ulFlags = ulFlags;
};
CMechanism::CMechanism(const CMechanism& mechanism)
{
	this->m_ulType = mechanism.m_ulType;
	if (mechanism.m_pParameter && mechanism.m_ulParameterLen != 0)
	{
		this->m_ulParameterLen = mechanism.m_ulParameterLen;
		this->m_pParameter = new unsigned char[m_ulParameterLen];
		memset(m_pParameter,0,m_ulParameterLen);
		memcpy(m_pParameter,mechanism.m_pParameter,m_ulParameterLen);
	}
	else
	{
		this->m_ulParameterLen = 0;
		this->m_pParameter = NULL;
	}
	this->m_ulMinKeySize = mechanism.m_ulMinKeySize;
	this->m_ulMaxKeySize = mechanism.m_ulMaxKeySize;
	this->m_ulFlags = mechanism.m_ulFlags;
}
CMechanism::~CMechanism()
{
	//空方法
};

CK_MECHANISM_TYPE CMechanism::GetType()
{
	return m_ulType;
};

CK_ULONG CMechanism::GetParameter(CK_VOID_PTR parameter)
{
	parameter = m_pParameter;
	return m_ulParameterLen;
};

CK_ULONG CMechanism::GetMaxKeySize()
{
	return m_ulMaxKeySize;
};

CK_ULONG CMechanism::GetMinKeySize()
{
	return m_ulMinKeySize;
};

CK_ULONG CMechanism::GetFlags()
{
	return m_ulFlags;
};

CMechanismList::CMechanismList()
{
	m_vecMechanism.clear();
	//初始化所支持的密码机制列表
	//(1)EC_KEY_PAIR_GEN
	m_vecMechanism[0] = CMechanism(CKM_EC_KEY_PAIR_GEN,NULL,0,256,384,CKF_EC_F_2M|CKF_EC_UNCOMPRESS);
	//(2)ECDSA
	m_vecMechanism[1] = CMechanism(CKM_ECDSA,NULL,0,256,384,CKF_EC_F_2M|CKF_EC_UNCOMPRESS);
	//(3)ECDH
	CK_ECDH1_DERIVE_PARAMS ecdhParams;
	m_vecMechanism[1] = CMechanism(CKM_ECDH1_DERIVE,&ecdhParams,0,256,384,CKF_EC_F_2M|CKF_EC_UNCOMPRESS);
	//(3)AES-CBC
	m_vecMechanism[3] = CMechanism(CKM_AES_CBC,NULL,0,128,256,0);
	//(4)AES-ECB
	m_vecMechanism[4] = CMechanism(CKM_AES_ECB,NULL,0,128,256,0);
	//(5)SHA-256
	m_vecMechanism[5] = CMechanism(CKM_SHA256,NULL,0,0,0,0);
	//(5)SHA-384
	m_vecMechanism[6] = CMechanism(CKM_SHA384,NULL,0,0,0,0);
};

int CMechanismList::GetCount()
{
	return m_vecMechanism.size();
}

CMechanism& CMechanismList::GetMechanism(int nIndex)
{
	return m_vecMechanism[nIndex];
};