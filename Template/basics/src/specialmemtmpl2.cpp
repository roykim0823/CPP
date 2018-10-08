#include <utility>
#include <string>
#include <iostream>
#include "specialmemtmpl2.hpp"

int main()
{
  std::string s = "sname";
  Person p1(s);              // init with string object => calls copying string-CONSTR
  Person p2("tmp");          // init with string literal => calls moving string-CONSTR
  //Person p3(p1);             // Compilation ERROR
  Person p4(std::move(p1));  

  // However, copying a "constant Person works fine:
  Person const p2c("ctmp");
  Person p3c(p2c);
}
