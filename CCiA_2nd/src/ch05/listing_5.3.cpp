#include <iostream>

void foo(int a,int b) {
    // if (a==2) {
    //     std::cout << "reversed." << std::endl;
    // }
    std::cout<<a<<","<<b<<std::endl;
}

int get_num() {
    static int i=0;
    return ++i;
}

int main() {

    for (int i=0; i<100; ++i) {
        // "foo(1, 2)" or "foo(2, 1)"
        foo(get_num(), get_num());  // Calls to get_num() are unordered.
    }
}
