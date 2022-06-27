#ifndef _PTLD_C_H
#define _PTLD_C_H
#include <stddef.h>
#ifdef __cplusplus
extern "C" {
#endif

void * ptmalloc(size_t size, const char *pFunction, const char  *pFile, int lineNo) ;
void ptfree(void *p) ;

#ifdef __cplusplus
}
#endif

#endif /*_PTLD_C_H*/