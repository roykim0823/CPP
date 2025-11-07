/*
Type decay in C++ refers to the set of implicit type conversions that occur in
certain contexts, most notably when types are passed by value to functions, or
when arrays or functions are used in most expressions.
The process is called "decay" because it often involves the loss of some type
information, such as array size or cv-qualifiers (like const or volatile)
*/

#include <iostream>
#include <type_traits>
#include <vector>
#include "type_name.hpp"

void func(int arr[]) {
    // Here, 'arr' decays to 'int*'
    std::cout << "Inside func, type of arr: "
              << (std::is_same<decltype(arr), int*>::value ? "int*" : "other")
              << '\n';
    std::cout << "Size of arr inside func: " << sizeof(arr) << " bytes\n";
}

template <typename T>
void print_decayed_type() {
    // std::decay_t<T> gives the type after decay is applied.
    using DecayedType = std::decay_t<T>;

    std::cout << "Original Type (T): "
              // << typeid(T).name() << std::endl;
              << type_name<T>() << std::endl;
    std::cout << "Decayed Type: "
              //<< typeid(DecayedType).name() << "\n\n";
              << type_name<DecayedType>() << std::endl;

    // Note: typeid().name() output is implementation-defined (often mangled),
    // but its *difference* is what matters here.
}

int main() {
    /* 1. Array to Pointer Decay
        What happens: An array, when used in most expressions
                (including being passed as a function argument by value),
                decays into a pointer to its first element.

        Information Lost: The size/dimension of the array is lost.
    */
    {
        int myArray[5] = {1, 2, 3, 4, 5};

        std::cout << "Before decay, type of myArray: "
                  << (std::is_array<decltype(myArray)>::value ? "array" : "other")
                  << '\n';
        std::cout << "Size of myArray before decay: " << sizeof(myArray) << " bytes\n";

        func(myArray); // Array decays to pointer when passed to function
    }
    std::cout << "--------------------------\n";

    /* 2. Function-to-Pointer Decay
        What happens: A function name, when used in most expressions,
                decays into a pointer to the function.

        Information Lost: The function type information is lost.
    */
    {
        void (*funcPtr)(int) = [](int x) {
            std::cout << "Lambda called with " << x << '\n';
        };

        std::cout << "Type of funcPtr: "
                  << (std::is_pointer<decltype(funcPtr)>::value ? "function pointer" : "other")
                  << '\n';

        funcPtr(42); // Calling the function pointer
    }
    /* 3. Removal of Qualifiers and References (During Pass-by-Value)
        What happens: When an argument is passed by value
                    (i.e., the function parameter is T), any references (& or &&)
                    and top-level const or volatile qualifiers are discarded
                    to get the simple, underlying type.

        Information Lost: The reference status and const/volatile qualifiers
                         of the original argument are ignored, as the function
                        receives a copy of the value.
    */
    {
        auto printType = [](auto value) {
            using T = decltype(value);
            std::cout << "Type inside lambda: "
                      << (std::is_const<std::remove_reference_t<T>>::value ? "const " : "")
                      << (std::is_volatile<std::remove_reference_t<T>>::value ? "volatile " : "")
                      << (std::is_lvalue_reference<T>::value ? "lvalue reference" :
                          std::is_rvalue_reference<T>::value ? "rvalue reference" : "non-reference")
                      << '\n' << std::endl;
        };

        const int x = 10;
        volatile int y = 20;

        std::cout << "Type outside lambda: "
                      << (std::is_const<std::remove_reference_t<decltype(x)>>::value ? "const " : "")
                      << (std::is_volatile<std::remove_reference_t<decltype(x)>>::value ? "volatile " : "")
                      << (std::is_lvalue_reference<decltype(x)>::value ? "lvalue reference" :
                          std::is_rvalue_reference<decltype(x)>::value ? "rvalue reference" : "non-reference")
                      << '\n';
        printType(x); // Passed by value, const is preserved in type deduction
        std::cout << "Type inside lambda: "
                      << (std::is_const<std::remove_reference_t<decltype(y)>>::value ? "const " : "")
                      << (std::is_volatile<std::remove_reference_t<decltype(y)>>::value ? "volatile " : "")
                      << (std::is_lvalue_reference<decltype(y)>::value ? "lvalue reference" :
                          std::is_rvalue_reference<decltype(y)>::value ? "rvalue reference" : "non-reference")
                      << '\n';
        printType(y); // Passed by value, volatile is preserved in type deduction

        const int &x_lref = x;
        std::cout << "Type inside lambda: "
                      << (std::is_const<std::remove_reference_t<decltype(x_lref)>>::value ? "const " : "")
                      << (std::is_volatile<std::remove_reference_t<decltype(x_lref)>>::value ? "volatile " : "")
                      << (std::is_lvalue_reference<decltype(x_lref)>::value ? "lvalue reference" :
                          std::is_rvalue_reference<decltype(x_lref)>::value ? "rvalue reference" : "non-reference")
                      << '\n';
        printType(x_lref); // Passed by value, reference is removed
        int temp = 30;
        int &&y_rref = std::move(temp);
        std::cout << "Type inside lambda: "
                      << (std::is_const<std::remove_reference_t<decltype(y_rref)>>::value ? "const " : "")
                      << (std::is_volatile<std::remove_reference_t<decltype(y_rref)>>::value ? "volatile " : "")
                      << (std::is_lvalue_reference<decltype(y_rref)>::value ? "lvalue reference" :
                          std::is_rvalue_reference<decltype(y_rref)>::value ? "rvalue reference" : "non-reference")
                      << '\n';
        printType(y_rref); // Passed by value, reference is removed
    }
    std::cout << "--------------------------\n";

    /* std::decay for Metaprogramming
        The C++ standard library provides the type trait std::decay<T>
        (and its alias std::decay_t<T>) in the <type_traits> header.
        This utility allows you to explicitly determine the resulting type after
        applying all decay rules, which is highly useful in template metaprogramming
        when you need to store or work with the "plain" value type of a complex
        template argument.
    */
    {
        // 1. Array-to-Pointer Decay
    std::cout << "--- Array Decay ---" << std::endl;
    print_decayed_type<int[5]>(); // T is 'int[5]' -> Decays to 'int*' (pointer to int)

    // 2. Reference and Const Decay
    std::cout << "--- Const/Reference Decay ---" << std::endl;
    print_decayed_type<const std::string&>(); // T is 'const std::string&'
                                            // -> Decays to 'std::string' (plain value)

    // 3. Simple Value (No Decay)
    std::cout << "--- Simple Type ---" << std::endl;
    print_decayed_type<double>(); // T is 'double' -> Decays to 'double' (no change)
    }

    return 0;
}

/*
Why This is Important

In the example above, if you were writing a generic function to store a copy of
the passed argument, you would use std::decay_t<T> to define the type of the storage member
*/

template <typename T>
class Storage {
public:
    // This is the key: The stored type is the decayed type of T.
    using StoredType = std::decay_t<T>;

    // An array argument (e.g., int[5]) would be stored as a pointer (int*).
    // A const reference (e.g., const int&) would be stored as a plain int.
    StoredType value;

    Storage(T&& arg) : value(std::forward<T>(arg)) {}
};

/* By using std::decay_t<T>, you ensure that your generic component is always working
   with the fundamental value type, correctly handling the complexities of
   array-to-pointer conversion and stripping unnecessary qualifiers and references.
   It makes generic code behave consistently, as if the argument were passed by value.
*/