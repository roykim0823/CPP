#include "ptmain.h"
#include <cstring>
#include <climits>
#include "ptHeader.h"
#include <iostream>

int main() {
	//ptMemoryBlockHeader p ;
	//std::cout << sizeof(p) << std::endl;
	//memset(&p, 1, sizeof(p)) ;
	//p.m_LineNumber = 5 ;
	//p.m_Size = 8 ;
	//memset(p.m_Guard, 'A', 4) ;
	int *p1 = new int{5} ;
	p1[-1] = 3 ;
	char *p = (char*)malloc(5) ;
	p[-1] = 'a' ;
	strcpy(p,"Hello") ;
	PtCheckMemory();
	free(p) ;
	delete p1 ;
	PtDumpLeaks() ;
}
  