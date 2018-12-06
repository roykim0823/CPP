/*
 * Key Idea:
 *
 *   Using nullptr improves code clarity especially when auto variables are
 *   involved.
 */

#include <iostream>
using namespace std;

int* findRecord() {
  return nullptr;
}

int main()
{

  {
    auto result = findRecord( /* arguments */ );
    
    if (result == 0) {
		cout << "result == 0" << endl;
    }
  }


  {
    auto result = findRecord( /* arguments */ );

    if (result == nullptr) {
		cout << "result == nullptr" << endl;
    }
  }

}
