#pragma once
#include <exception>
#include <stack>
#include <mutex>
#include <memory>

template<typename T>
class trivial_threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    trivial_threadsafe_stack(){}
    trivial_threadsafe_stack(const trivial_threadsafe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }

    trivial_threadsafe_stack& operator=(const trivial_threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

     void pop() {
        std::lock_guard<std::mutex> lock(m);
        data.pop();
    }

    T& top() {
        std::lock_guard<std::mutex> lock(m);
        return data.top();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

// Still there is a race condition in this trivial_thread_safe_stack.
// The probl,em is that the results of empty() or size() can't be relied on.
// The race condition inherits from the interface
// user code
// if (!ts_stack.empty()) {
//    int value = ts_stack.top();
//    std::cout << "value --" << value << std::end;
//    ts_stack.pop();
// }


struct empty_stack: std::exception {
    const char* what() const throw() {
        return "empty stack";
    }
};

template<typename T>
class threadsafe_stack {
private:
    std::stack<T> data;
    mutable std::mutex m;

public:
    threadsafe_stack(){}
    threadsafe_stack(const threadsafe_stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }

    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));  // use std::move
    }

    // Use std::shared_ptr to avoid the bad_alloc exception
    std::shared_ptr<T> pop() {  // combine top() & pop()
        // remove the race condition, it pop check the empty()
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    // Pass reference to store value to avoid the bad_alloc exception
    void pop(T& value) {  // combine top() and pop()
        // remove the race condition, it pop check the empty()
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        value=data.top();
        data.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};