#include <exception>
#include <memory>

struct empty_stack: std::exception
{
    const char* what() const throw();
};

template<typename T>
class threadsafe_stack
{
public:
    threadsafe_stack();
    threadsafe_stack(const threadsafe_stack&);
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value);
    std::shared_ptr<T> pop();  // option 3: return a pointer to the popped item
    void pop(T& value);  // option 1: pass in a reference
    bool empty() const;
};

int main()
{}
