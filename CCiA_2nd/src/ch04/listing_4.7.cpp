#include <string>
#include <future>

struct X {
    void foo(int,std::string const&) {};
    std::string bar(std::string const& str) {return str;};
};

struct Y {
    double operator()(double);
};

class move_only
{
public:
    move_only();
    move_only(move_only&&);
    move_only(move_only const&) = delete;
    move_only& operator=(move_only&&);
    move_only& operator=(move_only const&) = delete;
    void operator()();
};


int main() {
    X x;
    auto f1=std::async(&X::foo, &x, 42, "hello");
    auto f2=std::async(&X::bar, x, "goodbye");

    Y y;
    // auto f3=std::async(Y(), 3.141);  // compilation error
    // auto f4=std::async(std::ref(y), 2.718);  // compilation error
    X baz(X&);
    // auto f6=std::async(baz, std::ref(x));  // compilation error

    // auto f5=std::async(move_only());  // compilation error
    return 0;
}
