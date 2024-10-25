#include "thread_safe_stack.h"

int main() {
    threadsafe_stack<int> si;
    si.push(5);
    si.pop();
    if(!si.empty()) {
        int x;
        si.pop(x);
    }

}
