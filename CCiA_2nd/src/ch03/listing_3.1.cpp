#include <list>
#include <mutex>
#include <algorithm>
#include <thread>

std::list<int> some_list;
std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    some_list.push_back(new_value);
}
bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(some_mutex);
    return std::find(some_list.begin(),some_list.end(),value_to_find)
        != some_list.end();
}

#include <iostream>

int main()
{
    std::thread t_1(add_to_list, 42);
    std::thread t_2(add_to_list, 72);
    t_1.join();
    t_2.join();

    std::cout<<"contains(1)="<<list_contains(1)<<", contains(42)="<<list_contains(42)<<std::endl;
}
