#include <exception>
#include <stack>
#include <mutex>
#include <memory>
#include <iostream>

// default type of inheritance to class is "private"
// default type of inheritance to struct is "public"
struct empty_stack: std::exception	//	public inheritance
{
    const char* what() const throw()
    {
        return "empty stack";
    }
    
};

template<typename T>
class threadsafe_stack
{
private:
    std::stack<T> data;
    mutable std::mutex m;	// mutable for bool empty() const
public:
    threadsafe_stack(){}
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);	// lock the source object mutex
        data=other.data;
    }
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }
    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top();
        data.pop();
    }
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    threadsafe_stack<int> si;
	for(int i=0; i<10; i++) 
		si.push(i);
    while(!si.empty())
    {
        int x;
        si.pop(x);			// void pop(T& value)
		std::cout << x << std::endl;
        auto y = si.pop();  // std::shared_ptr<T> pop()
		std::cout << *y << std::endl;
    }
    
}
