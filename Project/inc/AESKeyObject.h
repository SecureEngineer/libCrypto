/************************************************************************/
/* 
* Copyright (c) 2015, ÀîÒ«Áú
* All rights reserved.
* File Name: AESKeyObject.h
* Version  : 1.0
* Author   : Li Yao Long
* Date     : 2015/10/13
*/
/************************************************************************/
#ifndef AESKEYOBJECT_H
#define AESKEYOBJECT_H

#include "SecretKeyObject.h"

class CAESKeyObject:public CSecretKeyObject
{
public:
	CAESKeyObject();
	~CAESKeyObject();
};
#endif