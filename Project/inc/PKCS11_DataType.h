/**
* @file:   PKCS11_DataType.h
* @brief   PKCS#11�������Ͷ���
* @author  Li YaoLong
* @date    2015/10/13
* @version 1.0
* <pre><b>CopyRight: (c) 2015, Li YaoLong</b></pre>
* <pre><b>Email: </b>SecMaster@Outlook.com</pre>
* <pre><b>Company: </b>http://www.sectalk.com.cn</pre>
* <pre><b>All rights reserved.</b></pre>
*/
#ifndef PKCS11_DATATYPE_H
#define PKCS11_DATATYPE_H

/*----------------------------------------------------------------------*
                         <<< PKCS11�Զ������� >>>
*----------------------------------------------------------------------*/

typedef unsigned char        CK_BYTE;

typedef CK_BYTE              CK_CHAR;

typedef CK_BYTE              CK_UTF8CHAR;

typedef CK_BYTE              CK_BBOOL;

typedef unsigned long int    CK_ULONG;

typedef long int             CK_LONG;

typedef CK_ULONG             CK_FLAGS;

typedef CK_BYTE CK_PTR       CK_BYTE_PTR; 

typedef CK_CHAR CK_PTR       CK_CHAR_PTR;     

typedef CK_UTF8CHAR CK_PTR   CK_UTF8CHAR_PTR;  

typedef CK_ULONG  CK_PTR     CK_ULONG_PTR; 

typedef void  CK_PTR         CK_VOID_PTR;    

typedef CK_VOID_PTR CK_PTR   CK_VOID_PTR_PTR;

/**
* ֪ͨ����
*/
typedef CK_ULONG             CK_NOTIFICATION;

/**
* �����ķ���ֵ����
*/
typedef CK_ULONG             CK_RV;

/**
* ���Ʋ۱�ʶ����
*/
typedef CK_ULONG             CK_SLOT_ID;
/**
* ���Ʋ۱�ʶָ������
*/
typedef CK_ULONG CK_PTR      CK_SLOT_ID_PTR;
/**
* �Ự������ͣ��ǻỰ��Ψһ��ʶ
*/
typedef CK_ULONG             CK_SESSION_HANDLE;
/**
 * �Ự���ָ������
 */
typedef CK_SESSION_HANDLE CK_PTR CK_SESSION_HANDLE_PTR; //�Ự���ָ��

/**
 * �û�����
 */
typedef CK_ULONG             CK_USER_TYPE;

/**
 * �Ự״̬
 */
typedef CK_ULONG             CK_STATE;

/**
 * ������
 */
typedef CK_ULONG             CK_OBJECT_HANDLE;
/*
 *
 */
typedef CK_OBJECT_HANDLE CK_PTR CK_OBJECT_HANDLE_PTR; //������ָ��

/*
 * ��������
 */
typedef CK_ULONG             CK_OBJECT_CLASS;
/*
 *
 */
typedef CK_OBJECT_CLASS CK_PTR CK_OBJECT_CLASS_PTR; //��������ָ��

/*Ӳ����������*/
/*
 *
 */
typedef CK_ULONG             CK_HW_FEATURE_TYPE;

/*��Կ����*/
/*
 *
 */
typedef CK_ULONG             CK_KEY_TYPE;

/**
 * ֤������
 */
typedef CK_ULONG             CK_CERTIFICATE_TYPE;


/**
 * ��������
 */
typedef CK_ULONG             CK_ATTRIBUTE_TYPE;

/**
 * �����㷨���ͣ����ڸ��ݹ�����������������Կ����Ҫ����EC������ϵ��
 */
typedef CK_ULONG             CK_EC_KDF_TYPE; 

/**
 * ����������ͣ�Ҳ����֧�ֵ������㷨������
 */
typedef CK_ULONG             CK_MECHANISM_TYPE;
/**
 * 
 */
typedef CK_MECHANISM_TYPE CK_PTR CK_MECHANISM_TYPE_PTR;

/**
 *
 */
typedef struct CK_FUNCTION_LIST         CK_FUNCTION_LIST;
/**
 *
 */
typedef CK_FUNCTION_LIST CK_PTR         CK_FUNCTION_LIST_PTR;
/**
 *
 */
typedef CK_FUNCTION_LIST_PTR CK_PTR     CK_FUNCTION_LIST_PTR_PTR;

/*----------------------------------------------------------------------*
                          <<<�ص������ӿ�>>>
*----------------------------------------------------------------------*/
/**
 *
 */
typedef CK_CALLBACK_FUNCTION(CK_RV, CK_NOTIFY)(CK_SESSION_HANDLE hSession,        //ִ�лص��ĻỰ�ľ��
	                                           CK_NOTIFICATION   event,           //֪ͨ�ص�������
                                               CK_VOID_PTR       pApplication);
/**
 *
 */
typedef CK_CALLBACK_FUNCTION(CK_RV, CK_CREATEMUTEX)(CK_VOID_PTR_PTR ppMutex);
/**
 *
 */
typedef CK_CALLBACK_FUNCTION(CK_RV, CK_DESTROYMUTEX)(CK_VOID_PTR pMutex);
/**
 *
 */
typedef CK_CALLBACK_FUNCTION(CK_RV, CK_LOCKMUTEX)(CK_VOID_PTR pMutex);
/**
 *
 */
typedef CK_CALLBACK_FUNCTION(CK_RV, CK_UNLOCKMUTEX)(CK_VOID_PTR pMutex);

/*----------------------------------------------------------------------*
                     <<< PKCS11�ж���ͨ���������� >>>
*----------------------------------------------------------------------*/

/*PKCS�İ汾�ţ���ǰ�汾��2.40,OASIS Standard 14/4/2015*/
/*
 *
 */
typedef struct CK_VERSION 
{
	CK_BYTE major; //major��ʾ���汾��
	CK_BYTE minor; //minor��ʾ�ΰ汾��
} CK_VERSION, *CK_VERSION_PTR;  

/**
 * Cryptoki��ͨ����Ϣ
 */
typedef struct CK_INFO
{
	CK_VERSION  cryptokiVersion;         // Cryptoki �ӿڰ汾�ţ���ýӿڵ�δ���汾�����
	CK_UTF8CHAR manufacturerID[32];     //Cryptoki �������ID���������հ��ַ�('')����Ӧ��0��ֹ��
	CK_FLAGS    flags;                     //Ϊδ���汾������λ��־��������汾��˵������Ϊ0
	CK_UTF8CHAR libraryDescription[32]; //����ַ����������������հ��ַ�('')����Ӧ��0��ֹ;
	CK_VERSION  libraryVersion;          //Cryptoki ��汾��
} CK_INFO,*CK_INFO_PTR;

//Cryptoki ���ڷ�������һ���ڴ���ִ�еĺ�����ӵ�е�ִ��Ȩ������Ӧ�ó������ִ��������������ִ�����κ������Ĳ���֮��Ӧ�ó���ӦָʾCryptoki �Ǽ���ִ�иú�������ȡ���ú���
#define CKN_SURRENDER 0
 
/**
 * ����һ���۵���Ϣ
 */
typedef struct CK_SLOT_INFO
{
	CK_UTF8CHAR slotDescription[64];   //�۵��ַ����������������հ��ַ�(''),��Ӧ��0��ֹ��
	CK_UTF8CHAR manufacturerID[32];    //�������ߵ�ID���������հ��ַ�('')�� ��Ӧ��0��ֹ��.
	CK_FLAGS    flags;
	CK_VERSION  hardwareVersion;        //�۵�Ӳ���İ汾��;
	CK_VERSION  firmwareVersion;        //�۵Ĺ̼��İ汾��;
} CK_SLOT_INFO, *CK_SLOT_INFO_PTR;

/**
 * ������Ϣ 
 */
typedef struct CK_TOKEN_INFO
{
	CK_UTF8CHAR label[32];               //Ӧ�ó�����ı�ǣ��������Ƴ�ʼ���ڼ�ָ���ġ��������հ��ַ�('')����Ӧ��0��ֹ
	CK_UTF8CHAR manufacturerID[32];      //�������ߵ�ID���������հ��ַ�('')�� ��Ӧ��0��ֹ
	CK_UTF8CHAR model[16];               //�豸�ͺš��������հ��ַ�('')�� ��Ӧ��0��ֹ
	CK_CHAR     serialNumber[16];        //�豸���ַ���˳��š��������հ��ַ�('')�� ��Ӧ��0��ֹ��
	CK_FLAGS    flags;                   //ָʾ�豸��������״̬��λ��־
	CK_ULONG    ulMaxSessionCount;       //ͨ������Ӧ�ó�����������һ��ͬʱ�򿪵����Ự����;
	CK_ULONG    ulSessionCount;          //��ǰ�����ƴ򿪵ĻỰ������;
	CK_ULONG    ulMaxRwSessionCount;     //ͨ������Ӧ�ó�����������һ��ͬʱ�򿪶�/д�Ự���������
	CK_ULONG    ulRwSessionCount;        //�����ƴ򿪵�ǰ��/д�Ự������
	CK_ULONG    ulMaxPinLen;             //PIN����󳤶ȣ��ֽ�����
	CK_ULONG    ulMinPinLen;             //PIN����С���ȣ��ֽ�����
	CK_ULONG    ulTotalPublicMemory;     //�����Ͽ��Դ�Ź���������ܴ洢�������ֽ�����
	CK_ULONG    ulFreePublicMemory;      //���ڴ�Ź�������Ŀ��У�δ�ã��洢�������ֽ�����
	CK_ULONG    ulTotalPrivateMemory;    //�����������˽�ж�����ܴ洢�������ֽ�����
	CK_ULONG    ulFreePrivateMemory;     //���ڴ��˽�ж���Ŀ��У�δ�ã��洢����
	CK_VERSION  hardwareVersion;         //Ӳ���İ汾��
	CK_VERSION  firmwareVersion;         //�̼��İ汾��
	CK_CHAR     utcTime[16];             //����һ������Ϊ16���ַ��������ĵ�ǰʱ�䣬��YYYYMMDDhhmmssxx��ʽ��ʾ����������4���ַ���ʾ���¡��ա�Сʱ���ֺ������2���ַ���ʾ����������������0���ַ�������������Ϣ��־��ָʾ������������ֶε�ֵ����װ����һ��ʱ�ӵ�����������
} CK_TOKEN_INFO,*CK_TOKEN_INFO_PTR;

/*�Ự��Ϣ*/
/*
 *
 */
typedef struct CK_SESSION_INFO
{
	CK_SLOT_ID slotID;          //�����ƽӿڵ��Ǹ��۵�ID
	CK_STATE   state;           //�Ự��״̬
	CK_FLAGS   flags;           //����Ự�����͵�λ��־
	CK_ULONG   ulDeviceError;   //�������豸����Ĵ�����롣����Cryptoki���ܸ��ǵĴ���
} CK_SESSION_INFO, *CK_SESSION_INFO_PTR;

/*����*/
/*
 *
 */
typedef struct CK_ATTRIBUTE 
{
	CK_ATTRIBUTE_TYPE type;           //��������
	CK_VOID_PTR       pValue;         //����ֵ
	CK_ULONG          ulValueLen;     //���Գ���
} CK_ATTRIBUTE,*CK_ATTRIBUTE_PTR;


/*ȷ�����ڵĽṹ�����ֶα��������ַ������������ֽ�ֵ*/
/*
 *
 */
typedef struct CK_DATE
{
	CK_CHAR year[4];   //�� (��1900�� - ��9999��)
	CK_CHAR month[2];  //�� (��01�� - ��12��)
	CK_CHAR day[2];    //�� (��01�� - ��31��)
} CK_DATE;


/**
 * ȷ���ض����Ƽ�����������Ľṹ
 */
typedef struct CK_MECHANISM 
{
	CK_MECHANISM_TYPE mechanism;        //���Ƶ�����
	CK_VOID_PTR       pParameter;       //ָ�������ָ�룬���������Ҫ�Ļ�
	CK_ULONG          ulParameterLen;   //�����ĳ��ȣ��ֽ�����
} CK_MECHANISM, *CK_MECHANISM_PTR;


/**
 * �ṩ�й�һ���ض�������Ϣ�Ľṹ
 */
typedef struct CK_MECHANISM_INFO
{
	CK_ULONG ulMinKeySize; //������Կ����С��С����������λ���в����������ֽڽ��в��������Ƕ������ƣ�
	CK_ULONG ulMaxKeySize; //������Կ������С����������λ���в����������ֽڽ��в��������Ƕ������ƣ�
	CK_FLAGS flags;        //ָ������������λ��־
} CK_MECHANISM_INFO,*CK_MECHANISM_INFO_PTR;

typedef struct CK_ECDH1_DERIVE_PARAMS 
{
	CK_EC_KDF_TYPE kdf;  
	CK_ULONG ulSharedDataLen;  
	CK_BYTE_PTR pSharedData;  
	CK_ULONG ulPublicDataLen;  
	CK_BYTE_PTR pPublicData; 
} CK_ECDH1_DERIVE_PARAMS; 

/*CK_C_INITIALIZE_ARGS �ǰ���C_Initialize������ѡ��Ԫ�Ľṹ������Cryptoki������汾����Щ��ѡ�ı�Ԫ�漰���ÿ⴦���̵߳ķ�ʽ*/
/*
 *
 */
typedef struct CK_C_INITIALIZE_ARGS
{
 	CK_CREATEMUTEX  CreateMutex;     //���������˹���Ԥ����ĺ�����ָ��
 	CK_DESTROYMUTEX DestroyMutex;    //���������˹���Ԥ����ĺ�����ָ��
 	CK_LOCKMUTEX    LockMutex;       //������ס�˹���Ԥ����ĺ�����ָ��
 	CK_UNLOCKMUTEX  UnlockMutex;     //���������˹���Ԥ����ĺ�����ָ��
	CK_FLAGS        flags;           //ΪC_Initializeȷ��ѡ���λ��־����Щ��־���Ժ���
	CK_VOID_PTR     pReserved;       //Ϊδ��ʹ�ñ�����Cryptoki������汾ӦΪNULL_PTR 
} CK_C_INITIALIZE_ARGS,*CK_C_INITIALIZE_ARGS_PTR ;

/*----------------------------------------------------------------------*
                  <<< ����Ϣ��־λ�ı����뼰�京�� >>>
*----------------------------------------------------------------------*/

/**
 * ������д���һ�����ƣ����磬��һ���豸���Ķ����У�Ϊ��
 */
#define CKF_TOKEN_PRESENT		            0x00000001
/**
 * ����Ķ���֧�ֿɲ�ж�豸��Ϊ�档
 */
#define CKF_REMOVABLE_DEVICE                0x00000002
/**
 * �������һ��Ӳ�ۣ�Ϊ�档����������ƣ�Ϊ��
 */
#define CKF_HW_SLOT		                    0x00000004

/*----------------------------------------------------------------------*
                   <<< ������Ϣ�б�־λ�ı����뼰�京�� >>>
*----------------------------------------------------------------------*/
/**
 * ����������Լ����������������Ϊ��
 */
#define CKF_RNG		                        0x00000001
/**
 * ���������д�����ģ�Ϊ��
 */
#define CKF_WRITE_PROTECTED		            0x00000002
/**
 * ����û�����ע�����ִ�����뺯����Ϊ��
 */
#define CKF_LOGIN_REQUIRED		            0x00000004
/**
 * �����ͨ�û���PIN�Ѿ�����ʼ����Ϊ��
 */
#define CKF_USER_PIN_INITIALIZED		    0x00000008
/**
 * ����ɹ�����һ���Ự���������״̬���ǰ����ָ��ûỰ��״̬����Ҫ��������Կ����Ϊ��
 */
#define CKF_RESTORE_KEY_NOT_NEEDED		    0x00000020
/**
 * ����������Լ���Ӳ��ʱ�ӣ���Ϊ��
 */
#define CKF_CLOCK_ON_TOKEN		            0x00000040
/**
 * ���������һ���ܱ����ļ���·�����û���˲��ð�PIN����Cryptoki ����ܹ�ע�ᵽ�����У�Ϊ��
 */
#define CKF_PROTECTED_AUTHENTICATION_PATH	0x00000100
/**
 * ��������Ƶĵ�һ�Ự�ܹ�ִ�ж�ż���������Ϊ�棨�μ��½� 11.13��
 */
#define CKF_DUAL_CRYPTO_OPERATIONS		    0x00000200
/**
 * ���ʹ��C_InitializeToken �򱾱�׼��Χ��ĵ�Ч�����Ѿ���ʼ�������ƣ���Ϊ�档���ñ�־�����ò�ʹ���Ʊ����³�ʼ���������C_InitializeToken ��
 */
#define CKF_TOKEN_INITIALIZED		        0x00000400
/**
 * �������֧��˽Կ������μ�����Ϊ�档�����ԣ��µ�ִ�г���Ҫ�������������Ϊ�棩
 */
#define CKF_SECONDARY_AUTHENTICATION		0x00000800
/**
 * ���������һ�γɹ��ļ���һ��������û�ע���PIN��������һ�Σ���Ϊ��
 */
#define CKF_USER_PIN_COUNT_LOW		        0x00010000
/**
 * ����ṩһ��������û���PIN����ס����Ϊ�档
 */
#define CKF_USER_PIN_FINAL_TRY	      	    0x00020000
/**
 * ����û���PIN����ס����Ϊ�档�û�ע��������ǲ����ܵġ�
 */
#define CKF_USER_PIN_LOCKED		            0x00040000
/**
 * ����û���PINֵͨ�����Ƴ�ʼ����ӹ������óɴ���ֵ����PIN�ɿ���ֹ��
 */
#define CKF_USER_PIN_TO_BE_CHANGED		    0x00080000
/**
 * �����һ�γɹ�����֤��SO��¼��PIN���ٽ���һ�Σ���Ϊ��
 */
#define CKF_SO_PIN_COUNT_LOW		        0x00100000
/**
 * ����ṩ�Ĵ����SO PIN������ס����Ϊ��
 */
#define CKF_SO_PIN_FINAL_TRY		        0x00200000
/**
 * ���SO PIN����ס����Ϊ�档�û���¼�����ǲ����ܵ�
 */
#define CKF_SO_PIN_LOCKED		            0x00400000
/**
 *���SO PINֵͨ�����Ƴ�ʼ����ӹ������óɴ����ֵ����PIN�ɿ���ֹ����Ϊ��
 */
#define CKF_SO_PIN_TO_BE_CHANGED		    0x00800000
/**
 *
 */
#define CK_UNAVAILABLE_INFORMATION          (~0UL)
/**
 *
 */
#define CK_EFFECTIVELY_INFINITE             0
/**
 * ��Ч�ľ��,��ֵ���ܱ�ʾ�Ự�����������
 */
#define CK_INVALID_HANDLE                   0 


/*----------------------------------------------------------------------*
                           <<< �û�����ֵ�� >>>
*----------------------------------------------------------------------*/
/**
 * ��ȫ��Ա
 */
#define CKU_SO                              0 
/**
 * ��ͨ�û�
 */
#define CKU_USER                            1


/*----------------------------------------------------------------------*
                            <<< �Ự״ֵ̬ >>>
*----------------------------------------------------------------------*/
/**
 * ֻ�������Ự״̬
 */
#define CKS_RO_PUBLIC_SESSION               0 //
/**
 *
 */
#define CKS_RO_USER_FUNCTIONS               1 //ֻ���û����ܻỰ״̬
/**
 *
 */
#define CKS_RW_PUBLIC_SESSION               2 //��д�����Ự״̬
/**
 *
 */
#define CKS_RW_USER_FUNCTIONS               3 //��д�û����ܻỰ״̬
/**
 *
 */
#define CKS_RW_SO_FUNCTIONS                 4 //��д��ȫ��Ա���ܻỰ״̬

/*----------------------------------------------------------------------*
                       <<< �Ự���ͱ����뼰�京�� >>>
*----------------------------------------------------------------------*/
/**
 *
 */
#define CKF_RW_SESSION	                    0x00000002	//����ỰΪ��/д����Ϊ�棻����Ự��ֻ������Ϊ��
/**
 *
 */
#define CKF_SERIAL_SESSION	                0x00000004	//�ñ�־�ṩ�����ݣ���ʼ������Ϊ��

/**
 * ��������ֵ
 */
#define CKO_DATA                            0x00000000 //���ݶ���
/**
 *
 */
#define CKO_CERTIFICATE                     0x00000001 //֤�����
/**
 *
 */
#define CKO_PUBLIC_KEY                      0x00000002 //��Կ����
/**
 *
 */
#define CKO_PRIVATE_KEY                     0x00000003 //˽Կ����
/**
 *
 */
#define CKO_SECRET_KEY                      0x00000004 //�Գ���Կ���󣬻��Ϊ������Կ����
/**
 *
 */
#define CKO_HW_FEATURE                      0x00000005 //Ӳ����������
/**
 *
 */
#define CKO_DOMAIN_PARAMETERS               0x00000006 //
/**
 *
 */
#define CKO_MECHANISM                       0x00000007
/**
 *
 */
#define CKO_OTP_KEY                         0x00000008
/**
 *
 */
#define CKO_VENDOR_DEFINED                  0x80000000


/*----------------------------------------------------------------------*
                         <<< Ӳ����������ֵ >>>
*----------------------------------------------------------------------*/
/**
 *
 */
#define CKH_MONOTONIC_COUNTER               0x00000001
/**
 *
 */
#define CKH_CLOCK                           0x00000002
/**
 *
 */
#define CKH_VENDOR_DEFINED                  0x80000000

/*----------------------------------------------------------------------*
                            <<< ��Կ����ֵ >>>
*----------------------------------------------------------------------*/

#define CKK_RSA                             0x00000000
/**
 *
 */
#define CKK_DSA                             0x00000001
/**
 *
 */
#define CKK_DH                              0x00000002
#define CKK_ECDSA                           0x00000003 /* CKK_ECDSA is deprecated in v2.11 */
#define CKK_EC                              0x00000003
#define CKK_X9_42_DH                        0x00000004
#define CKK_KEA                             0x00000005
#define CKK_GENERIC_SECRET                  0x00000010
#define CKK_RC2                             0x00000011
#define CKK_RC4                             0x00000012
#define CKK_DES                             0x00000013
#define CKK_DES2                            0x00000014
#define CKK_DES3                            0x00000015
#define CKK_CAST                            0x00000016
#define CKK_CAST3                           0x00000017
#define CKK_CAST5                           0x00000018 /* CKK_CAST5 is deprecated in v2.11 */
#define CKK_CAST128                         0x00000018
#define CKK_RC5                             0x00000019
#define CKK_IDEA                            0x0000001A
#define CKK_SKIPJACK                        0x0000001B
#define CKK_BATON                           0x0000001C
#define CKK_JUNIPER                         0x0000001D
#define CKK_CDMF                            0x0000001E
#define CKK_AES                             0x0000001F
#define CKK_VENDOR_DEFINED                  0x80000000


/*----------------------------------------------------------------------*
                           <<< ֤������ֵ >>>
*----------------------------------------------------------------------*/
#define CKC_X_509                           0x00000000
#define CKC_X_509_ATTR_CERT                 0x00000001
#define CKC_VENDOR_DEFINED                  0x80000000

/**/
/*----------------------------------------------------------------------*
                          <<< ��������ֵ >>>
*----------------------------------------------------------------------*/
#define CKA_CLASS                           0x00000000
#define CKA_TOKEN                           0x00000001
#define CKA_PRIVATE                         0x00000002
#define CKA_LABEL                           0x00000003
#define CKA_APPLICATION                     0x00000010
#define CKA_VALUE                           0x00000011
#define CKA_OBJECT_ID                       0x00000012
#define CKA_CERTIFICATE_TYPE                0x00000080
#define CKA_ISSUER                          0x00000081
#define CKA_SERIAL_NUMBER                   0x00000082
#define CKA_AC_ISSUER                       0x00000083
#define CKA_OWNER                           0x00000084
#define CKA_ATTR_TYPES                      0x00000085
#define CKA_TRUSTED                         0x00000086
#define CKA_KEY_TYPE                        0x00000100
#define CKA_SUBJECT                         0x00000101
#define CKA_ID                              0x00000102
#define CKA_SENSITIVE                       0x00000103
#define CKA_ENCRYPT                         0x00000104
#define CKA_DECRYPT                         0x00000105
#define CKA_WRAP                            0x00000106
#define CKA_UNWRAP                          0x00000107
#define CKA_SIGN                            0x00000108
#define CKA_SIGN_RECOVER                    0x00000109
#define CKA_VERIFY                          0x0000010A
#define CKA_VERIFY_RECOVER                  0x0000010B
#define CKA_DERIVE                          0x0000010C
#define CKA_START_DATE                      0x00000110
#define CKA_END_DATE                        0x00000111
#define CKA_MODULUS                         0x00000120
#define CKA_MODULUS_BITS                    0x00000121
#define CKA_PUBLIC_EXPONENT                 0x00000122
#define CKA_PRIVATE_EXPONENT                0x00000123
#define CKA_PRIME_1                         0x00000124
#define CKA_PRIME_2                         0x00000125
#define CKA_EXPONENT_1                      0x00000126
#define CKA_EXPONENT_2                      0x00000127
#define CKA_COEFFICIENT                     0x00000128
#define CKA_PRIME                           0x00000130
#define CKA_SUBPRIME                        0x00000131
#define CKA_BASE                            0x00000132
#define CKA_PRIME_BITS                      0x00000133
#define CKA_SUB_PRIME_BITS                  0x00000134
#define CKA_VALUE_BITS                      0x00000160
#define CKA_VALUE_LEN                       0x00000161
#define CKA_EXTRACTABLE                     0x00000162
#define CKA_LOCAL                           0x00000163
#define CKA_NEVER_EXTRACTABLE               0x00000164
#define CKA_ALWAYS_SENSITIVE                0x00000165
#define CKA_KEY_GEN_MECHANISM               0x00000166
#define CKA_MODIFIABLE                      0x00000170
#define CKA_ECDSA_PARAMS                    0x00000180/* CKA_ECDSA_PARAMS is deprecated in v2.11 */
#define CKA_EC_PARAMS                       0x00000180
#define CKA_EC_POINT                        0x00000181
#define CKA_SECONDARY_AUTH                  0x00000200
#define CKA_AUTH_PIN_FLAGS                  0x00000201
#define CKA_HW_FEATURE_TYPE                 0x00000300
#define CKA_RESET_ON_INIT                   0x00000301
#define CKA_HAS_RESET                       0x00000302
#define CKA_VENDOR_DEFINED                  0x80000000


/*----------------------------------------------------------------------*
                   <<< �����������ֵ PKCS#11 V2.40>>>
*----------------------------------------------------------------------*/

#define CKM_RSA_PKCS_KEY_PAIR_GEN           0x00000000
#define CKM_RSA_PKCS                        0x00000001
#define CKM_RSA_9796                        0x00000002
#define CKM_RSA_X_509                       0x00000003
#define CKM_MD2_RSA_PKCS                    0x00000004
#define CKM_MD5_RSA_PKCS                    0x00000005
#define CKM_SHA1_RSA_PKCS                   0x00000006
#define CKM_RIPEMD128_RSA_PKCS              0x00000007
#define CKM_RIPEMD160_RSA_PKCS              0x00000008
#define CKM_RSA_PKCS_OAEP                   0x00000009
#define CKM_RSA_X9_31_KEY_PAIR_GEN          0x0000000A
#define CKM_RSA_X9_31                       0x0000000B
#define CKM_SHA1_RSA_X9_31                  0x0000000C
#define CKM_RSA_PKCS_PSS                    0x0000000D
#define CKM_SHA1_RSA_PKCS_PSS               0x0000000E
#define CKM_DSA_KEY_PAIR_GEN                0x00000010
#define CKM_DSA                             0x00000011
#define CKM_DSA_SHA1                        0x00000012
#define CKM_DSA_FIPS_G_GEN                  0x00000013
#define CKM_DSA_SHA224                      0x00000014
#define CKM_DSA_SHA256                      0x00000015
#define CKM_DSA_SHA384                      0x00000016
#define CKM_DSA_SHA512                      0x00000017
#define CKM_DH_PKCS_KEY_PAIR_GEN            0x00000020
#define CKM_DH_PKCS_DERIVE                  0x00000021
#define CKM_X9_42_DH_KEY_PAIR_GEN           0x00000030
#define CKM_X9_42_DH_DERIVE                 0x00000031
#define CKM_X9_42_DH_HYBRID_DERIVE          0x00000032
#define CKM_X9_42_MQV_DERIVE                0x00000033
#define CKM_SHA256_RSA_PKCS                 0x00000040
#define CKM_SHA384_RSA_PKCS                 0x00000041
#define CKM_SHA512_RSA_PKCS                 0x00000042
#define CKM_SHA256_RSA_PKCS_PSS             0x00000043
#define CKM_SHA384_RSA_PKCS_PSS             0x00000044
#define CKM_SHA512_RSA_PKCS_PSS             0x00000045
#define CKM_SHA224_RSA_PKCS                 0x00000046
#define CKM_SHA224_RSA_PKCS_PSS             0x00000047
#define CKM_SHA512_224                      0x00000048
#define CKM_SHA512_224_HMAC                 0x00000049
#define CKM_SHA512_224_HMAC_GENERAL         0x0000004A
#define CKM_SHA512_224_KEY_DERIVATION       0x0000004B
#define CKM_SHA512_256                      0x0000004C
#define CKM_SHA512_256_HMAC                 0x0000004D
#define CKM_SHA512_256_HMAC_GENERAL         0x0000004E
#define CKM_SHA512_256_KEY_DERIVATION       0x0000004F
#define CKM_SHA512_T                        0x00000050
#define CKM_SHA512_T_HMAC                   0x00000051
#define CKM_SHA512_T_HMAC_GENERAL           0x00000052
#define CKM_SHA512_T_KEY_DERIVATION         0x00000053
#define CKM_RC2_KEY_GEN                     0x00000100
#define CKM_RC2_ECB                         0x00000101
#define CKM_RC2_CBC                         0x00000102
#define CKM_RC2_MAC                         0x00000103
#define CKM_RC2_MAC_GENERAL                 0x00000104
#define CKM_RC2_CBC_PAD                     0x00000105
#define CKM_RC4_KEY_GEN                     0x00000110
#define CKM_RC4                             0x00000111
#define CKM_DES_KEY_GEN                     0x00000120
#define CKM_DES_ECB                         0x00000121
#define CKM_DES_CBC                         0x00000122
#define CKM_DES_MAC                         0x00000123
#define CKM_DES_MAC_GENERAL                 0x00000124
#define CKM_DES_CBC_PAD                     0x00000125
#define CKM_DES2_KEY_GEN                    0x00000130
#define CKM_DES3_KEY_GEN                    0x00000131
#define CKM_DES3_ECB                        0x00000132
#define CKM_DES3_CBC                        0x00000133
#define CKM_DES3_MAC                        0x00000134
#define CKM_DES3_MAC_GENERAL                0x00000135
#define CKM_DES3_CBC_PAD                    0x00000136
#define CKM_CDMF_KEY_GEN                    0x00000140
#define CKM_CDMF_ECB                        0x00000141
#define CKM_CDMF_CBC                        0x00000142
#define CKM_CDMF_MAC                        0x00000143
#define CKM_CDMF_MAC_GENERAL                0x00000144
#define CKM_CDMF_CBC_PAD                    0x00000145
#define CKM_DES_OFB64                       0x00000150
#define CKM_DES_OFB8                        0x00000151
#define CKM_DES_CFB64                       0x00000152
#define CKM_DES_CFB8                        0x00000153
#define CKM_MD2                             0x00000200
#define CKM_MD2_HMAC                        0x00000201
#define CKM_MD2_HMAC_GENERAL                0x00000202
#define CKM_MD5                             0x00000210
#define CKM_MD5_HMAC                        0x00000211
#define CKM_MD5_HMAC_GENERAL                0x00000212
#define CKM_SHA_1                           0x00000220
#define CKM_SHA_1_HMAC                      0x00000221
#define CKM_SHA_1_HMAC_GENERAL              0x00000222
#define CKM_RIPEMD128                       0x00000230
#define CKM_RIPEMD128_HMAC                  0x00000231
#define CKM_RIPEMD128_HMAC_GENERAL          0x00000232
#define CKM_RIPEMD160                       0x00000240
#define CKM_RIPEMD160_HMAC                  0x00000241
#define CKM_RIPEMD160_HMAC_GENERAL          0x00000242
#define CKM_SHA256                          0x00000250
#define CKM_SHA256_HMAC                     0x00000251
#define CKM_SHA256_HMAC_GENERAL             0x00000252
#define CKM_SHA224                          0x00000255
#define CKM_SHA224_HMAC                     0x00000256
#define CKM_SHA224_HMAC_GENERAL             0x00000257
#define CKM_SHA384                          0x00000260
#define CKM_SHA384_HMAC                     0x00000261
#define CKM_SHA384_HMAC_GENERAL             0x00000262
#define CKM_SHA512                          0x00000270
#define CKM_SHA512_HMAC                     0x00000271
#define CKM_SHA512_HMAC_GENERAL             0x00000272
#define CKM_SECURID_KEY_GEN                 0x00000280
#define CKM_SECURID                         0x00000282
#define CKM_HOTP_KEY_GEN                    0x00000290
#define CKM_HOTP                            0x00000291
#define CKM_ACTI                            0x000002A0
#define CKM_ACTI_KEY_GEN                    0x000002A1
#define CKM_CAST_KEY_GEN                    0x00000300
#define CKM_CAST_ECB                        0x00000301
#define CKM_CAST_CBC                        0x00000302
#define CKM_CAST_MAC                        0x00000303
#define CKM_CAST_MAC_GENERAL                0x00000304
#define CKM_CAST_CBC_PAD                    0x00000305
#define CKM_CAST3_KEY_GEN                   0x00000310
#define CKM_CAST3_ECB                       0x00000311
#define CKM_CAST3_CBC                       0x00000312
#define CKM_CAST3_MAC                       0x00000313
#define CKM_CAST3_MAC_GENERAL               0x00000314
#define CKM_CAST3_CBC_PAD                   0x00000315
#define CKM_CAST5_KEY_GEN                   0x00000320
#define CKM_CAST128_KEY_GEN                 0x00000320
#define CKM_CAST5_ECB                       0x00000321
#define CKM_CAST128_ECB                     0x00000321
#define CKM_CAST5_CBC                       0x00000322
#define CKM_CAST128_CBC                     0x00000322
#define CKM_CAST5_MAC                       0x00000323
#define CKM_CAST128_MAC                     0x00000323
#define CKM_CAST5_MAC_GENERAL               0x00000324
#define CKM_CAST128_MAC_GENERAL             0x00000324
#define CKM_CAST5_CBC_PAD                   0x00000325
#define CKM_CAST128_CBC_PAD                 0x00000325
#define CKM_RC5_KEY_GEN                     0x00000330
#define CKM_RC5_ECB                         0x00000331
#define CKM_RC5_CBC                         0x00000332
#define CKM_RC5_MAC                         0x00000333
#define CKM_RC5_MAC_GENERAL                 0x00000334
#define CKM_RC5_CBC_PAD                     0x00000335
#define CKM_IDEA_KEY_GEN                    0x00000340
#define CKM_IDEA_ECB                        0x00000341
#define CKM_IDEA_CBC                        0x00000342
#define CKM_IDEA_MAC                        0x00000343
#define CKM_IDEA_MAC_GENERAL                0x00000344
#define CKM_IDEA_CBC_PAD                    0x00000345
#define CKM_GENERIC_SECRET_KEY_GEN          0x00000350
#define CKM_CONCATENATE_BASE_AND_KEY        0x00000360
#define CKM_CONCATENATE_BASE_AND_DATA       0x00000362
#define CKM_CONCATENATE_DATA_AND_BASE       0x00000363
#define CKM_XOR_BASE_AND_DATA               0x00000364
#define CKM_EXTRACT_KEY_FROM_KEY            0x00000365
#define CKM_SSL3_PRE_MASTER_KEY_GEN         0x00000370
#define CKM_SSL3_MASTER_KEY_DERIVE          0x00000371
#define CKM_SSL3_KEY_AND_MAC_DERIVE         0x00000372
#define CKM_SSL3_MASTER_KEY_DERIVE_DH       0x00000373
#define CKM_TLS_PRE_MASTER_KEY_GEN          0x00000374
#define CKM_TLS_MASTER_KEY_DERIVE           0x00000375
#define CKM_TLS_KEY_AND_MAC_DERIVE          0x00000376
#define CKM_TLS_MASTER_KEY_DERIVE_DH        0x00000377
#define CKM_TLS_PRF                         0x00000378
#define CKM_SSL3_MD5_MAC                    0x00000380
#define CKM_SSL3_SHA1_MAC                   0x00000381
#define CKM_MD5_KEY_DERIVATION              0x00000390
#define CKM_MD2_KEY_DERIVATION              0x00000391
#define CKM_SHA1_KEY_DERIVATION             0x00000392
#define CKM_SHA256_KEY_DERIVATION           0x00000393
#define CKM_SHA384_KEY_DERIVATION           0x00000394
#define CKM_SHA512_KEY_DERIVATION           0x00000395
#define CKM_SHA224_KEY_DERIVATION           0x00000396
#define CKM_PBE_MD2_DES_CBC                 0x000003A0
#define CKM_PBE_MD5_DES_CBC                 0x000003A1
#define CKM_PBE_MD5_CAST_CBC                0x000003A2
#define CKM_PBE_MD5_CAST3_CBC               0x000003A3
#define CKM_PBE_MD5_CAST5_CBC               0x000003A4
#define CKM_PBE_MD5_CAST128_CBC             0x000003A4
#define CKM_PBE_SHA1_CAST5_CBC              0x000003A5
#define CKM_PBE_SHA1_CAST128_CBC            0x000003A5
#define CKM_PBE_SHA1_RC4_128                0x000003A6
#define CKM_PBE_SHA1_RC4_40                 0x000003A7
#define CKM_PBE_SHA1_DES3_EDE_CBC           0x000003A8
#define CKM_PBE_SHA1_DES2_EDE_CBC           0x000003A9
#define CKM_PBE_SHA1_RC2_128_CBC            0x000003AA
#define CKM_PBE_SHA1_RC2_40_CBC             0x000003AB
#define CKM_PKCS5_PBKD2                     0x000003B0
#define CKM_PBA_SHA1_WITH_SHA1_HMAC         0x000003C0
#define CKM_WTLS_PRE_MASTER_KEY_GEN         0x000003D0
#define CKM_WTLS_MASTER_KEY_DERIVE          0x000003D1
#define CKM_WTLS_MASTER_KEY_DERIVE_DH_ECC   0x000003D2
#define CKM_WTLS_PRF                        0x000003D3
#define CKM_WTLS_SERVER_KEY_AND_MAC_DERIVE  0x000003D4
#define CKM_WTLS_CLIENT_KEY_AND_MAC_DERIVE  0x000003D5
#define CKM_TLS10_MAC_SERVER                0x000003D6
#define CKM_TLS10_MAC_CLIENT                0x000003D7
#define CKM_TLS12_MAC                       0x000003D8
#define CKM_TLS12_MASTER_KEY_DERIVE         0x000003E0
#define CKM_TLS12_KEY_AND_MAC_DERIVE        0x000003E1
#define CKM_TLS12_MASTER_KEY_DERIVE_DH      0x000003E2
#define CKM_TLS12_KEY_SAFE_DERIVE           0x000003E3
#define CKM_TLS_MAC                         0x000003E4
#define CKM_TLS_KDF                         0x000003E5
#define CKM_KEY_WRAP_LYNKS                  0x00000400
#define CKM_KEY_WRAP_SET_OAEP               0x00000401
#define CKM_CMS_SIG                         0x00000500
#define CKM_KIP_DERIVE                      0x00000510
#define CKM_KIP_WRAP                        0x00000511
#define CKM_KIP_MAC                         0x00000512
#define CKM_CAMELLIA_KEY_GEN                0x00000550
#define CKM_CAMELLIA_ECB                    0x00000551
#define CKM_CAMELLIA_CBC                    0x00000552
#define CKM_CAMELLIA_MAC                    0x00000553
#define CKM_CAMELLIA_MAC_GENERAL            0x00000554
#define CKM_CAMELLIA_CBC_PAD                0x00000555
#define CKM_CAMELLIA_ECB_ENCRYPT_DATA       0x00000556
#define CKM_CAMELLIA_CBC_ENCRYPT_DATA       0x00000557
#define CKM_CAMELLIA_CTR                    0x00000558
#define CKM_ARIA_KEY_GEN                    0x00000560
#define CKM_ARIA_ECB                        0x00000561
#define CKM_ARIA_CBC                        0x00000562
#define CKM_ARIA_MAC                        0x00000563
#define CKM_ARIA_MAC_GENERAL                0x00000564
#define CKM_ARIA_CBC_PAD                    0x00000565
#define CKM_ARIA_ECB_ENCRYPT_DATA           0x00000566
#define CKM_ARIA_CBC_ENCRYPT_DATA           0x00000567
#define CKM_SKIPJACK_KEY_GEN                0x00001000
#define CKM_SKIPJACK_ECB64                  0x00001001
#define CKM_SKIPJACK_CBC64                  0x00001002
#define CKM_SKIPJACK_OFB64                  0x00001003
#define CKM_SKIPJACK_CFB64                  0x00001004
#define CKM_SKIPJACK_CFB32                  0x00001005
#define CKM_SKIPJACK_CFB16                  0x00001006
#define CKM_SKIPJACK_CFB8                   0x00001007
#define CKM_SKIPJACK_WRAP                   0x00001008
#define CKM_SKIPJACK_PRIVATE_WRAP           0x00001009
#define CKM_SKIPJACK_RELAYX                 0x0000100a
#define CKM_KEA_KEY_PAIR_GEN                0x00001010
#define CKM_KEA_KEY_DERIVE                  0x00001011
#define CKM_FORTEZZA_TIMESTAMP              0x00001020
#define CKM_BATON_KEY_GEN                   0x00001030
#define CKM_BATON_ECB128                    0x00001031
#define CKM_BATON_ECB96                     0x00001032
#define CKM_BATON_CBC128                    0x00001033
#define CKM_BATON_COUNTER                   0x00001034
#define CKM_BATON_SHUFFLE                   0x00001035
#define CKM_BATON_WRAP                      0x00001036
#define CKM_ECDSA_KEY_PAIR_GEN              0x00001040
#define CKM_EC_KEY_PAIR_GEN                 0x00001040
#define CKM_ECDSA                           0x00001041
#define CKM_ECDSA_SHA1                      0x00001042
#define CKM_ECDH1_DERIVE                    0x00001050
#define CKM_ECDH1_COFACTOR_DERIVE           0x00001051
#define CKM_ECMQV_DERIVE                    0x00001052
#define CKM_ECDH_AES_KEY_WRAP               0x00001053
#define CKM_RSA_AES_KEY_WRAP                0x00001054
#define CKM_JUNIPER_KEY_GEN                 0x00001060
#define CKM_JUNIPER_ECB128                  0x00001061
#define CKM_JUNIPER_CBC128                  0x00001062
#define CKM_JUNIPER_COUNTER                 0x00001063
#define CKM_JUNIPER_SHUFFLE                 0x00001064
#define CKM_JUNIPER_WRAP                    0x00001065
#define CKM_FASTHASH                        0x00001070
#define CKM_AES_KEY_GEN                     0x00001080
#define CKM_AES_ECB                         0x00001081
#define CKM_AES_CBC                         0x00001082
#define CKM_AES_MAC                         0x00001083
#define CKM_AES_MAC_GENERAL                 0x00001084
#define CKM_AES_CBC_PAD                     0x00001085
#define CKM_AES_CTR                         0x00001086
#define CKM_AES_GCM                         0x00001087
#define CKM_AES_CCM                         0x00001088
#define CKM_AES_CMAC_GENERAL                0x00001089
#define CKM_AES_CMAC                        0x0000108A
#define CKM_AES_CTS                         0x0000108B
#define CKM_AES_XCBC_MAC                    0x0000108C
#define CKM_AES_XCBC_MAC_96                 0x0000108D
#define CKM_BLOWFISH_KEY_GEN                0x00001090
#define CKM_BLOWFISH_CBC                    0x00001091
#define CKM_TWOFISH_KEY_GEN                 0x00001092
#define CKM_TWOFISH_CBC                     0x00001093
#define CKM_BLOWFISH_CBC_PAD                0x00001094
#define CKM_TWOFISH_CBC_PAD                 0x00001095
#define CKM_DES_ECB_ENCRYPT_DATA            0x00001100
#define CKM_DES_CBC_ENCRYPT_DATA            0x00001101
#define CKM_DES3_ECB_ENCRYPT_DATA           0x00001102
#define CKM_DES3_CBC_ENCRYPT_DATA           0x00001103
#define CKM_AES_ECB_ENCRYPT_DATA            0x00001104
#define CKM_AES_CBC_ENCRYPT_DATA            0x00001105
#define CKM_GOSTR3410_KEY_PAIR_GEN          0x00001200
#define CKM_GOSTR3410                       0x00001201
#define CKM_GOSTR3410_WITH_GOSTR3411        0x00001202
#define CKM_GOSTR3410_KEY_WRAP              0x00001203
#define CKM_GOSTR3410_DERIVE                0x00001204
#define CKM_GOSTR3411                       0x00001210
#define CKM_GOSTR3411_HMAC                  0x00001211
#define CKM_GOST28147_KEY_GEN               0x00001220
#define CKM_GOST28147_ECB                   0x00001221
#define CKM_GOST28147                       0x00001222
#define CKM_GOST28147_MAC                   0x00001223
#define CKM_GOST28147_KEY_WRAP              0x00001224
#define CKM_DSA_PARAMETER_GEN               0x00002000
#define CKM_DH_PKCS_PARAMETER_GEN           0x00002001
#define CKM_X9_42_DH_PKCS_PARAMETER_GEN     0x00002002
#define CKM_DSA_PROBABLISTIC_PARAMETER_GEN  0x00002003
#define CKM_DSA_SHAWE_TAYLOR_PARAMETER_GEN  0x00002004
#define CKM_AES_OFB                         0x00002104
#define CKM_AES_CFB64                       0x00002105
#define CKM_AES_CFB8                        0x00002106
#define CKM_AES_CFB128                      0x00002107
#define CKM_AES_CFB1                        0x00002108
#define CKM_AES_KEY_WRAP                    0x00002109
#define CKM_AES_KEY_WRAP_PAD                0x0000210A
#define CKM_RSA_PKCS_TPM_1_1                0x00004001
#define CKM_RSA_PKCS_OAEP_TPM_1_1           0x00004002
#define CKM_VENDOR_DEFINED                  0x80000000

/*----------------------------------------------------------------------*
             <<< �ض�������ƽṹ���б�־λ�ı���λֵ���京�� >>>
*----------------------------------------------------------------------*/
/**
 * ������������豸ִ�еģ���Ϊ�棻��������������ִ�еģ���Ϊ�١�
 */
#define CKF_HW	                            0x00000001
/**
 * ������ƿ�����C_EncryptInitһ��ʹ����Ϊ�档
 */
#define CKF_ENCRYPT                     	0x00000100
/**
 * ������ƿ�����C_DecryptInitһ��ʹ�ã���Ϊ��
 */
#define CKF_DECRYPT                     	0x00000200
/**
 * ������ƿ����� C_DigestInitһ��ʹ�ã���Ϊ��
 */
#define CKF_DIGEST                      	0x00000400
/**
 * ������ƿ�����C_SignInitһ��ʹ�ã���Ϊ��
 */
#define CKF_SIGN                         	0x00000800
/**
 * ������ƿ�����C_SignRecoverInitһ��ʹ�ã���Ϊ��
 */
#define CKF_SIGN_RECOVER                	0x00001000
/**
 * ������ƿ�����C_VerifyInitһ��ʹ�ã���Ϊ��
 */
#define CKF_VERIFY                         	0x00002000
/*
 * ������ƿ����� C_VerifyRecoverInitһ��ʹ�ã���Ϊ��
 */
#define CKF_VERIFY_RECOVER                 	0x00004000
/**
 * ������ƿ�����C_GenerateKeyһ��ʹ�ã���Ϊ��
 */
#define CKF_GENERATE	                    0x00008000
/**
 * ������ƿ�����C_GenerateKeyPairһ��ʹ�ã���Ϊ��
 */
#define CKF_GENERATE_KEY_PAIR              	0x00010000
/**
 * ������ƿ�����C_WrapKeyһ��ʹ�ã���Ϊ��
 */
#define CKF_WRAP	                        0x00020000
/**
 * ������ƿ�����C_UnwrapKeyһ��ʹ�ã���Ϊ��
 */
#define CKF_UNWRAP                         	0x00040000
/**
 * ������ƿ�����C_DeriveKeyһ��ʹ�ã���Ϊ��
 */
#define CKF_DERIVE                      	0x00080000
/**
 * ����û�����Fp��ʹ��EC�����, ��Ϊ��
 */
#define CKF_EC_F_P                        	0x00100000
/**
 * ����û�����F2m��ʹ��EC�����, ��Ϊ��
 */
#define CKF_EC_F_2M	                        0x00200000
/**
 * ����û�����F2m��ʹ��EC��ecParameters�Ĳ���, ��Ϊ��
 */
#define CKF_EC_ECPARAMETERS                	0x00400000
/**
 * ����û�����F2m��ʹ��EC��namedCurve�Ĳ���, ��Ϊ��
 */
#define CKF_EC_NAMEDCURVE                  	0x00800000
/**
 * TRUE if the mechanism can be used with elliptic curve point uncompressed
 */
#define CKF_EC_UNCOMPRESS                  	0x01000000
/**
 * TRUE if the mechanism can be used with elliptic curve point compressed
 */
#define CKF_EC_COMPRESS                    	0x02000000
/**
 * ����Ǳ�־���ӳ����֣���Ϊ�棻������Ǳ�־���ӳ����֣���Ϊ�١����ڸð汾����Ϊ�١�
 */
#define CKF_EXTENSION	                    0x80000000

/*----------------------------------------------------------------------*
                   <<< PKCS11�ж��庯���ķ���ֵ>>>
*----------------------------------------------------------------------*/
#define CKR_OK                              0x00000000
#define CKR_CANCEL                          0x00000001
#define CKR_HOST_MEMORY                     0x00000002
#define CKR_SLOT_ID_INVALID                 0x00000003
#define CKR_GENERAL_ERROR                   0x00000005
#define CKR_FUNCTION_FAILED                 0x00000006
#define CKR_ARGUMENTS_BAD                   0x00000007
#define CKR_NO_EVENT                        0x00000008
#define CKR_NEED_TO_CREATE_THREADS          0x00000009
#define CKR_CANT_LOCK                       0x0000000A
#define CKR_ATTRIBUTE_READ_ONLY             0x00000010
#define CKR_ATTRIBUTE_SENSITIVE             0x00000011
#define CKR_ATTRIBUTE_TYPE_INVALID          0x00000012
#define CKR_ATTRIBUTE_VALUE_INVALID         0x00000013
#define CKR_DATA_INVALID                    0x00000020
#define CKR_DATA_LEN_RANGE                  0x00000021
#define CKR_DEVICE_ERROR                    0x00000030
#define CKR_DEVICE_MEMORY                   0x00000031
#define CKR_DEVICE_REMOVED                  0x00000032
#define CKR_ENCRYPTED_DATA_INVALID          0x00000040
#define CKR_ENCRYPTED_DATA_LEN_RANGE        0x00000041
#define CKR_FUNCTION_CANCELED               0x00000050
#define CKR_FUNCTION_NOT_PARALLEL           0x00000051
#define CKR_FUNCTION_NOT_SUPPORTED          0x00000054
#define CKR_KEY_HANDLE_INVALID              0x00000060
#define CKR_KEY_SIZE_RANGE                  0x00000062
#define CKR_KEY_TYPE_INCONSISTENT           0x00000063
#define CKR_KEY_NOT_NEEDED                  0x00000064
#define CKR_KEY_CHANGED                     0x00000065
#define CKR_KEY_NEEDED                      0x00000066
#define CKR_KEY_INDIGESTIBLE                0x00000067
#define CKR_KEY_FUNCTION_NOT_PERMITTED      0x00000068
#define CKR_KEY_NOT_WRAPPABLE               0x00000069
#define CKR_KEY_UNEXTRACTABLE               0x0000006A
#define CKR_MECHANISM_INVALID               0x00000070
#define CKR_MECHANISM_PARAM_INVALID         0x00000071
#define CKR_OBJECT_HANDLE_INVALID           0x00000082
#define CKR_OPERATION_ACTIVE                0x00000090
#define CKR_OPERATION_NOT_INITIALIZED       0x00000091
#define CKR_PIN_INCORRECT                   0x000000A0
#define CKR_PIN_INVALID                     0x000000A1
#define CKR_PIN_LEN_RANGE                   0x000000A2
#define CKR_PIN_EXPIRED                     0x000000A3
#define CKR_PIN_LOCKED                      0x000000A4
#define CKR_SESSION_CLOSED                  0x000000B0
#define CKR_SESSION_COUNT                   0x000000B1
#define CKR_SESSION_HANDLE_INVALID          0x000000B3
#define CKR_SESSION_PARALLEL_NOT_SUPPORTED  0x000000B4
#define CKR_SESSION_READ_ONLY               0x000000B5
#define CKR_SESSION_EXISTS                  0x000000B6
#define CKR_SESSION_READ_ONLY_EXISTS        0x000000B7
#define CKR_SESSION_READ_WRITE_SO_EXISTS    0x000000B8
#define CKR_SIGNATURE_INVALID               0x000000C0
#define CKR_SIGNATURE_LEN_RANGE             0x000000C1
#define CKR_TEMPLATE_INCOMPLETE             0x000000D0
#define CKR_TEMPLATE_INCONSISTENT           0x000000D1
#define CKR_TOKEN_NOT_PRESENT               0x000000E0
#define CKR_TOKEN_NOT_RECOGNIZED            0x000000E1
#define CKR_TOKEN_WRITE_PROTECTED           0x000000E2
#define CKR_UNWRAPPING_KEY_HANDLE_INVALID   0x000000F0
#define CKR_UNWRAPPING_KEY_SIZE_RANGE       0x000000F1
#define CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT  0x000000F2
#define CKR_USER_ALREADY_LOGGED_IN          0x00000100
#define CKR_USER_NOT_LOGGED_IN              0x00000101
#define CKR_USER_PIN_NOT_INITIALIZED        0x00000102
#define CKR_USER_TYPE_INVALID               0x00000103
#define CKR_USER_ANOTHER_ALREADY_LOGGED_IN  0x00000104
#define CKR_USER_TOO_MANY_TYPES             0x00000105
#define CKR_WRAPPED_KEY_INVALID             0x00000110
#define CKR_WRAPPED_KEY_LEN_RANGE           0x00000112
#define CKR_WRAPPING_KEY_HANDLE_INVALID     0x00000113
#define CKR_WRAPPING_KEY_SIZE_RANGE         0x00000114
#define CKR_WRAPPING_KEY_TYPE_INCONSISTENT  0x00000115
#define CKR_RANDOM_SEED_NOT_SUPPORTED       0x00000120
#define CKR_RANDOM_NO_RNG                   0x00000121
#define CKR_DOMAIN_PARAMS_INVALID           0x00000130
#define CKR_BUFFER_TOO_SMALL                0x00000150
#define CKR_SAVED_STATE_INVALID             0x00000160
#define CKR_INFORMATION_SENSITIVE           0x00000170
#define CKR_STATE_UNSAVEABLE                0x00000180
#define CKR_CRYPTOKI_NOT_INITIALIZED        0x00000190
#define CKR_CRYPTOKI_ALREADY_INITIALIZED    0x00000191
#define CKR_MUTEX_BAD                       0x000001A0
#define CKR_MUTEX_NOT_LOCKED                0x000001A1
#define CKR_VENDOR_DEFINED                  0x80000000


/*----------------------------------------------------------------------*
                   <<< C_Initialize������־ >>>
*----------------------------------------------------------------------*/
/**
 * ���ִ�п�ĵ��õ�Ӧ�ó����̲߳�����ʹ�ñ���Ĳ���ϵͳ�������̵߳ĵ��ã���Ϊ�棻������ԣ���Ϊ�١�
 */
#define CKF_LIBRARY_CANT_CREATE_OS_THREADS	0x00000001
/**
 * �������ʹ�ñ���Ĳ���ϵͳ����ģ����ס����Ϊ�档��֮Ϊ�١�
 */
#define CKF_OS_LOCKING_OK	                0x00000002


#endif