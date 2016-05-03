/**
* @file:   Crypto.cpp
* @brief   CCrypto类定义源文件
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
* <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
* <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
* <pre><b>All rights reserved.</b></pre> 
*/
#include "..\inc\Crypto.h"

//对当前PKCS11库的描述
string strLibDesc="PKCS#11动态链接库(Beta1)";
//密码设备的生产ID，应该根据实际的设备ID来进行动态标识；
string strManuFacturerID = "00000000000000000000000000000001";
//定义并初始化单例
CCrypto*  CCrypto::m_pInstance = 0;

CCrypto::CCrypto()
{
	memcpy(m_utf8ManuFacturerID,strManuFacturerID.c_str(),strManuFacturerID.length());
	memcpy(m_utf8LibraryDesc,strLibDesc.c_str(),strLibDesc.length());
	m_bInitialized = CK_FALSE;
	m_fCryptokiFlag = CKF_LIBRARY_CANT_CREATE_OS_THREADS;
	m_pInitArgs = NULL_PTR;
}
CCrypto* CCrypto::GetInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new CCrypto();
	}

	return m_pInstance;
}
CK_RV CCrypto::Initialize(CK_VOID_PTR pInitArgs)
{
	CK_RV ckRetVal = CKR_OK;

	CK_C_INITIALIZE_ARGS_PTR pArgs = NULL_PTR;
	
	
	if (m_bInitialized)
	{
		//已经初始化cryptoki
		ckRetVal = CKR_CRYPTOKI_ALREADY_INITIALIZED;
		goto Ret;
	}
	else
	{
		if (pInitArgs)
		{//传入的参数非空

			pArgs = (CK_C_INITIALIZE_ARGS_PTR)pInitArgs;

			if (NULL_PTR != pArgs->pReserved)
			{
				//传入的参数非法，该版本中该值必须为空，否则返回错误码
				ckRetVal = CKR_ARGUMENTS_BAD;
				m_bInitialized = CK_FALSE;
				goto Ret;
			}
			else
			{
				//分配内存并初始化
				if (!m_pInitArgs)
				{
					m_pInitArgs = new CK_C_INITIALIZE_ARGS;
					
					if (!m_pInitArgs)
					{
						//申请内存失败
						ckRetVal = CKR_HOST_MEMORY;
						goto Ret;
					}
					else
					{
						memset(m_pInitArgs,0,sizeof(CK_C_INITIALIZE_ARGS));
					}
				}

				if(pArgs->flags & CKF_OS_LOCKING_OK)
				{//参数的标志字段含有CKF_OS_LOCKING_OK的标志

					if (pArgs->CreateMutex && pArgs->DestroyMutex && pArgs->LockMutex && pArgs->UnlockMutex)
					{//函数指针非空，说明应用程序将执行多线程调用，

						m_pInitArgs->CreateMutex  = pArgs->CreateMutex;
						m_pInitArgs->DestroyMutex = pArgs->DestroyMutex;
						m_pInitArgs->LockMutex    = pArgs->LockMutex;
						m_pInitArgs->UnlockMutex  = pArgs->UnlockMutex;
					}
					else
					{//传入的函数指针为空值，接口库将自己产生用于互斥的多线程控制
						m_pInitArgs->CreateMutex  = PKCS11_CreateMutex;
						m_pInitArgs->DestroyMutex = PKCS11_DestroyMutex;
						m_pInitArgs->LockMutex    = PKCS11_LockMutex;
						m_pInitArgs->UnlockMutex  = PKCS11_UnLockMutex;
					}
				}
				else
				{//没有CKF_OS_LOCKING_OK标志

					if (pArgs->CreateMutex && pArgs->DestroyMutex && pArgs->LockMutex && pArgs->UnlockMutex)
					{//函数指针非空，说明应用程序将执行多线程调用，

						m_pInitArgs->CreateMutex  = pArgs->CreateMutex;
						m_pInitArgs->DestroyMutex = pArgs->DestroyMutex;
						m_pInitArgs->LockMutex    = pArgs->LockMutex;
						m_pInitArgs->UnlockMutex  = pArgs->UnlockMutex;
					}
					else
					{
						/*函数指针为空，说明应用程序不会执行多线程调用，\
						如果应用程序执行了多线程调用，可能会产生错误！*/
						//不执行任何操作
					}
				}
			}
		}
		else
		{
			//传入的参数为空值，不做任何处理

		}
		//修改初始化标志
		m_bInitialized = CK_TRUE;
	}
Ret:
	return ckRetVal;
}
CK_BBOOL CCrypto::GetInitFlag()
{
	return m_bInitialized;
}
CK_RV CCrypto::Finalize(CK_VOID_PTR pReserved)
{
	CK_RV ckRetVal = CKR_OK;

	//判断输入的参数是否合法

	if (!pReserved)
	{
		ckRetVal = CKR_ARGUMENTS_BAD;
	}
	else
	{
		//判断是否进行了初始化操作
		if(!m_bInitialized)
		{
			ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
		}
		else
		{
			//回收内存
			if (m_pInitArgs)
			{
				delete m_pInitArgs;
				m_pInitArgs = NULL_PTR;
			}
			m_bInitialized = CK_FALSE;
		}
	}
	return ckRetVal;
}
CK_RV CCrypto::GetInfo(CK_INFO_PTR pInfo)
{
	return 0;
}