/**
* @file:   Crypto.cpp
* @brief   CCrypto�ඨ��Դ�ļ�
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre> 
* <pre><b>Email: </b>SecMaster@Outlook.com</pre> 
* <pre><b>Company: </b>http://www.sectalk.com.cn</pre> 
* <pre><b>All rights reserved.</b></pre> 
*/
#include "..\inc\Crypto.h"

//�Ե�ǰPKCS11�������
string strLibDesc="PKCS#11��̬���ӿ�(Beta1)";
//�����豸������ID��Ӧ�ø���ʵ�ʵ��豸ID�����ж�̬��ʶ��
string strManuFacturerID = "00000000000000000000000000000001";
//���岢��ʼ������
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
		//�Ѿ���ʼ��cryptoki
		ckRetVal = CKR_CRYPTOKI_ALREADY_INITIALIZED;
		goto Ret;
	}
	else
	{
		if (pInitArgs)
		{//����Ĳ����ǿ�

			pArgs = (CK_C_INITIALIZE_ARGS_PTR)pInitArgs;

			if (NULL_PTR != pArgs->pReserved)
			{
				//����Ĳ����Ƿ����ð汾�и�ֵ����Ϊ�գ����򷵻ش�����
				ckRetVal = CKR_ARGUMENTS_BAD;
				m_bInitialized = CK_FALSE;
				goto Ret;
			}
			else
			{
				//�����ڴ沢��ʼ��
				if (!m_pInitArgs)
				{
					m_pInitArgs = new CK_C_INITIALIZE_ARGS;
					
					if (!m_pInitArgs)
					{
						//�����ڴ�ʧ��
						ckRetVal = CKR_HOST_MEMORY;
						goto Ret;
					}
					else
					{
						memset(m_pInitArgs,0,sizeof(CK_C_INITIALIZE_ARGS));
					}
				}

				if(pArgs->flags & CKF_OS_LOCKING_OK)
				{//�����ı�־�ֶκ���CKF_OS_LOCKING_OK�ı�־

					if (pArgs->CreateMutex && pArgs->DestroyMutex && pArgs->LockMutex && pArgs->UnlockMutex)
					{//����ָ��ǿգ�˵��Ӧ�ó���ִ�ж��̵߳��ã�

						m_pInitArgs->CreateMutex  = pArgs->CreateMutex;
						m_pInitArgs->DestroyMutex = pArgs->DestroyMutex;
						m_pInitArgs->LockMutex    = pArgs->LockMutex;
						m_pInitArgs->UnlockMutex  = pArgs->UnlockMutex;
					}
					else
					{//����ĺ���ָ��Ϊ��ֵ���ӿڿ⽫�Լ��������ڻ���Ķ��߳̿���
						m_pInitArgs->CreateMutex  = PKCS11_CreateMutex;
						m_pInitArgs->DestroyMutex = PKCS11_DestroyMutex;
						m_pInitArgs->LockMutex    = PKCS11_LockMutex;
						m_pInitArgs->UnlockMutex  = PKCS11_UnLockMutex;
					}
				}
				else
				{//û��CKF_OS_LOCKING_OK��־

					if (pArgs->CreateMutex && pArgs->DestroyMutex && pArgs->LockMutex && pArgs->UnlockMutex)
					{//����ָ��ǿգ�˵��Ӧ�ó���ִ�ж��̵߳��ã�

						m_pInitArgs->CreateMutex  = pArgs->CreateMutex;
						m_pInitArgs->DestroyMutex = pArgs->DestroyMutex;
						m_pInitArgs->LockMutex    = pArgs->LockMutex;
						m_pInitArgs->UnlockMutex  = pArgs->UnlockMutex;
					}
					else
					{
						/*����ָ��Ϊ�գ�˵��Ӧ�ó��򲻻�ִ�ж��̵߳��ã�\
						���Ӧ�ó���ִ���˶��̵߳��ã����ܻ��������*/
						//��ִ���κβ���
					}
				}
			}
		}
		else
		{
			//����Ĳ���Ϊ��ֵ�������κδ���

		}
		//�޸ĳ�ʼ����־
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

	//�ж�����Ĳ����Ƿ�Ϸ�

	if (!pReserved)
	{
		ckRetVal = CKR_ARGUMENTS_BAD;
	}
	else
	{
		//�ж��Ƿ�����˳�ʼ������
		if(!m_bInitialized)
		{
			ckRetVal = CKR_CRYPTOKI_NOT_INITIALIZED;
		}
		else
		{
			//�����ڴ�
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