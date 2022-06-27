#include <malloc.h>
#include "ptHeader.h"
#include <stdio.h>
#include "ptld_c.h"
#include <string.h>
static unsigned const char GUARDFILL = 0XFD;
struct ptMemoryBlockHeader *pHead;
int ptIsValidBlock(struct ptMemoryBlockHeader *pCurrentBlock) {
	for (struct ptMemoryBlockHeader *p = pHead; p != NULL; p = p->m_pNext) {
		if (pCurrentBlock == p)
			return 1;
	}
	return 0;
}
void ptDumpBlock(struct ptMemoryBlockHeader *p) {
	printf("\nBytes leaked<%zu>\n", p->m_Size);
	printf("Address <0x%p>\n", p + 1);
	printf("Line # <%d>\n", p->m_LineNumber);
	printf("Function <%s>\n", p->m_pFunction);
	printf("File <%s>\n", p->m_pFile);
}
void *ptmalloc(size_t size, const char *pFunction, const char  *pFile, int lineNo) {
	void *allocated_mem = malloc(sizeof(struct ptMemoryBlockHeader) + size + GUARDSIZE);
	if (!allocated_mem) {
		return NULL;
	}
	struct ptMemoryBlockHeader *pCurrentBlock = (struct ptMemoryBlockHeader*)allocated_mem;
	pCurrentBlock->m_Size = size;
	pCurrentBlock->m_pFunction = pFunction;
	pCurrentBlock->m_pFile = pFile;
	pCurrentBlock->m_LineNumber = lineNo;
	pCurrentBlock->m_pNext = pCurrentBlock->m_pPrev = NULL;
	memset(pCurrentBlock->m_Guard, GUARDFILL, GUARDSIZE);
	unsigned char *pEnd = (unsigned char*)pCurrentBlock;
	pEnd += (sizeof(struct ptMemoryBlockHeader) + size);
	memset(pEnd, GUARDFILL, GUARDSIZE);
	if (pHead == NULL) {
		pHead = pCurrentBlock;
	} else {
		pCurrentBlock->m_pNext = pHead;
		pHead->m_pPrev = pCurrentBlock;
		pHead = pCurrentBlock;
	}
	return pCurrentBlock + 1;

}
void ptfree(void *p) {
	if (p == NULL)
		return;
	struct ptMemoryBlockHeader *pCurrentBlock = (struct ptMemoryBlockHeader *)p;
	pCurrentBlock -= 1;
	if (ptIsValidBlock(pCurrentBlock)) {
		if (pCurrentBlock->m_pPrev != NULL) {
			pCurrentBlock->m_pPrev->m_pNext = pCurrentBlock->m_pNext;
		} else {
			pHead = pCurrentBlock->m_pNext;
		}
		if (pCurrentBlock->m_pNext != NULL) {
			pCurrentBlock->m_pNext->m_pPrev = pCurrentBlock->m_pPrev;
		}
		free(pCurrentBlock);
	}

}
void *ptGetBegGuard(struct ptMemoryBlockHeader *ptr) {
	return &ptr->m_Guard;
}
void *ptGetEndGuard(struct ptMemoryBlockHeader *ptr) {
	unsigned char *user_mem = ptr + 1 ;
	return user_mem + ptr->m_Size ;
}
void ptDumpHeapCorruptionInfo(struct ptMemoryBlockHeader *ptr) {
	unsigned char guard[GUARDSIZE] = { 0 };
	memset(guard, GUARDFILL, 4);
	if (memcmp(ptGetBegGuard(ptr), guard, GUARDSIZE) != 0) {
		printf("\nHeap corruption before memory block\n");
		printf("Address <0x%p>\n", ptr + 1);
		printf("Line # <%d>\n", ptr->m_LineNumber);
		printf("Function <%s>\n", ptr->m_pFunction);
		printf("File <%s>\n", ptr->m_pFile);
	}
	if(memcmp(ptGetEndGuard(ptr), guard, GUARDSIZE) != 0) {
		printf("\nHeap corruption after memory block\n");
		printf("Address <0x%p>\n", ptr + 1);
		printf("Line # <%d>\n", ptr->m_LineNumber);
		printf("Function <%s>\n", ptr->m_pFunction);
		printf("File <%s>\n", ptr->m_pFile);
	}
}
void PtDumpLeaks() {
	if (pHead == NULL) {
		printf("No leaks detected");
		return;
	}
	printf("\n---------------\n");
	printf("LEAKS DETECTED\n");
	printf("\n---------------\n");
	for (struct ptMemoryBlockHeader *ptr = pHead; ptr != NULL; ptr = ptr->m_pNext) {
		ptDumpBlock(ptr);
	}
}
void PtCheckMemory() {
	for (struct ptMemoryBlockHeader *ptr = pHead; ptr != NULL; ptr = ptr->m_pNext) {
		ptDumpHeapCorruptionInfo(ptr);
	}
}