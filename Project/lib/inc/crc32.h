#ifndef _CRC32_H_
#define _CRC32_H_
#include <dllexport.h>
const unsigned int CRC32_NEGL = 0xffffffffL;

#ifdef IS_LITTLE_ENDIAN
#define CRC32_INDEX(c) (c & 0xff)
#define CRC32_SHIFTED(c) (c >> 8)
#else
#define CRC32_INDEX(c) (c >> 24)
#define CRC32_SHIFTED(c) (c << 8)
#endif


class DLLEXPORT CRC32
{
public:
	CRC32();
	void Update(const unsigned char *input, unsigned int length);
	void TruncatedFinal(unsigned char *hash, unsigned int size);


private:
	unsigned char GetCrcByte(size_t i) const {return ((unsigned char *)&(m_crc))[i];}
	void Reset() {m_crc = CRC32_NEGL;}

	static const unsigned int m_tab[256];
	unsigned int m_crc;
};

#endif