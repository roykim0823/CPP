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

#include <iostream>
#include <string>
#include <thread>

class Data {
  private:
    std::string name;
  public:
    Data(const std::string& s) : name(s) {
    }
    auto startThreadWithCopyOfThis() const {
        // start and return new thread using this after 3 seconds:
        using namespace std::literals;
        std::thread t([*this] {
                               std::this_thread::sleep_for(3s);
                               std::cout << name << '\n';
                           });
        return t;
    }
};

int main()
{
    std::thread t;
    {
      Data d{"c1"};
      t = d.startThreadWithCopyOfThis();
    } // d is no longer valid
    t.join();
}
