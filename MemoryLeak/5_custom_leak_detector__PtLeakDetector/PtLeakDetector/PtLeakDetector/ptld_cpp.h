#ifndef _PTLD_CPP_H
#define _PTLD_CPP_H
#include <stddef.h>
void *operator new(size_t size, const char *pFunction, const char  *pFile, int lineNo );
void *operator new[](size_t size, const char *pFunction, const char  *pFile, int lineNo );
#ifdef _DEBUG
void operator delete(void *p);
void operator delete[](void *p);
#endif /*_DEBUG*/
#endif /*_PTLD_CPP_H*/