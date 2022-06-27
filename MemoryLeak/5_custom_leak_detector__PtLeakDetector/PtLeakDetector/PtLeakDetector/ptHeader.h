#ifndef _PT_HEADER_H
#define _PT_HEADER_H
#include <stddef.h>
#define GUARDSIZE 4
struct ptMemoryBlockHeader {
	const char *m_pFunction ;
	const char *m_pFile ;
	size_t m_Size ;
	struct ptMemoryBlockHeader *m_pPrev ;
	struct ptMemoryBlockHeader *m_pNext ;
	int m_LineNumber ;
	unsigned char m_Guard[GUARDSIZE] ;
};

#endif /*_PT_HEADER_H*/
