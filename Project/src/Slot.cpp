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
#include "..\inc\Slot.h"

//定义并初始化单例
CSlotList*  CSlotList::m_pInstance = 0;

CSlot::CSlot()
{
	//空方法
};
CSlot::~CSlot()
{
	//空方法
};
CK_SLOT_ID CSlot::GetID()
{
	return m_ulSlotID;
};
CK_BBOOL CSlot::CheckTokenPresent()
{
	return m_bTokenPresent;
};
CK_SLOT_INFO CSlot::GetInfo()
{
	return m_stSlotInfo;
};
CK_TOKEN_INFO CSlot::GetTokenInfo()
{
	return m_stTokenInfo;
};
CSlotList::CSlotList()
{
	m_vecSlot.clear();
};
CSlotList* CSlotList::GetInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CSlotList();
	}

	return m_pInstance;
};
int CSlotList::GetCount()
{
	return m_vecSlot.size();
}
CSlot& CSlotList::GetSlot(int nIndex)
{
	return m_vecSlot[nIndex];
};