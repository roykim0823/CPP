#include "logger.h"
using namespace std;

double add(double a, double b)
{
  cout << a << "+" << b << "=" << (a + b) << endl;
  return a + b;
}

int main()
{
  Logger([]() {cout << "Hello" << endl; }, "HelloFunction")();
  Logger2<function<void()>>([]() {cout << "Hello2" << endl; }, "HelloFunction")();
  
  // cannot do this
  //make_logger2([]() {cout << "Hello" << endl; }, "HelloFunction")();
  auto call = make_logger2([]() {cout << "Hello!" << endl; }, "HelloFunction");
  call();

  auto logged_add = make_logger3(add, "Add");
  auto result = logged_add(2, 3);
  
  return 0;
}
