//********************************************************
// The following code example is taken from the book
//  C++17 - The Complete Guide
//  by Nicolai M. Josuttis (www.josuttis.com)
//  http://www.cppstd17.com
//
// The code is licensed under a
//  Creative Commons Attribution 4.0 International License
//  http://creativecommons.org/licenses/by/4.0/
//********************************************************


#include <chrono>
#include <iostream>

std::ostream& operator<< (std::ostream& strm,
                          const std::chrono::duration<double,std::milli>& dur)
{
  return strm << dur.count() << "ms";
}

template<typename T>
void roundAndAbs(T dur)
{
  using namespace std::chrono;

  std::cout << dur << '\n';
  std::cout << " abs():   " << abs(dur) << '\n';
  std::cout << " cast:    " << duration_cast<std::chrono::seconds>(dur) << '\n';
  std::cout << " floor(): " << floor<std::chrono::seconds>(dur) << '\n';
  std::cout << " ceil():  " << ceil<std::chrono::seconds>(dur) << '\n';
  std::cout << " round(): " << round<std::chrono::seconds>(dur) << '\n';
}

int main()
{
  using namespace std::literals;
  roundAndAbs(3.33s);
  roundAndAbs(3.77s);
  roundAndAbs(-3.77s);
}

