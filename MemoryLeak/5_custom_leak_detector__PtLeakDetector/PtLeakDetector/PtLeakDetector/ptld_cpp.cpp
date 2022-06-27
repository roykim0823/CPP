
#include "ptld_c.h"
#include "ptld_cpp.h"

void *operator new(size_t size, const char *pFunction, const char  *pFile, int lineNo ){
	return ptmalloc(size, pFunction, pFile, lineNo) ;
}
void *operator new[](size_t size, const char *pFunction, const char  *pFile, int lineNo ){
	return ptmalloc(size, pFunction, pFile, lineNo) ;
}
#ifdef _DEBUG

void operator delete(void *p){
	ptfree(p) ;
}
void operator delete[](void *p){
	ptfree(p) ;
}
#endif /*_DEBUG*/  
