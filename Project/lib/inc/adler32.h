#ifndef _ADLER32_H_
#define _ADLER32_H_
#include <assert.h>
#include <dllexport.h>

typedef unsigned char byte;

class DLLEXPORT Adler32
{
public:
	Adler32() {Reset();}
	void Update(const byte *input, unsigned int length);
	void TruncatedFinal(byte *hash, unsigned int size);

private:
	void Reset() {m_s1 = 1; m_s2 = 0;}
	unsigned int m_s1, m_s2;
};

#endif