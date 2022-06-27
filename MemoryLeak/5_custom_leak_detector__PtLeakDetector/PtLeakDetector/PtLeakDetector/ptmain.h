#ifndef _PTMAIN_H
#define _PTMAIN_H
#include <stddef.h>
#include <malloc.h>
#include "ptld_c.h"
#ifdef __cplusplus
#include "ptld_cpp.h"
extern "C" {
#endif
	void PtDumpLeaks();
	void PtCheckMemory() ;

#ifdef _WIN32
#define PT_FUNCTION_NAME __FUNCSIG__
#elif defined __GNUC__
#define PT_FUNCTION_NAME __PRETTY_FUNCTION__
#else
#define PT_FUNCTION_NAME "Unknown function"
#endif

#ifdef _DEBUG
#define malloc(size) ptmalloc(size, PT_FUNCTION_NAME, __FILE__, __LINE__)
#define free ptfree

#define new new(PT_FUNCTION_NAME, __FILE__, __LINE__)
#endif


#ifdef __cplusplus
}
#endif

#endif /*_PTMAIN_H */