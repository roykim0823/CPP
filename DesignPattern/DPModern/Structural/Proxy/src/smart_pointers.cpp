#include "smart_pointer.h"

int main()
{
  BankAccount* ba = new CurrentAccount(123);
  ba->deposit(321);
  delete ba;

  // << will not work if you make this a shared_ptr<BankAccount>
  //auto b = make_shared<CurrentAccount>(123);
  auto ba2 = make_shared<CurrentAccount>(100);

  BankAccount* actual = ba2.get(); 	// pointer's own operations on a .
  ba2->deposit(321); 				// underlying object's operations are on ->
                   
  // note this expression is identical to what's above
  cout << *ba2 << endl;
  // no delete, see shared_ptr in file structure window

  return 0;
}
