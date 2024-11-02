#include "include/thread_safe_queue.h"

#include <iostream>
#include <thread>

void producer(threadsafe_queue<int>& ts_q) {
    ts_q.push(1);
    ts_q.push(2);
    ts_q.push(3);
    ts_q.push(4);
    ts_q.push(5);
}

void consumer(threadsafe_queue<int>& ts_q) {
    std::vector<int> answer;
    answer.push_back(*ts_q.wait_and_pop());
    answer.push_back(*ts_q.wait_and_pop());
    int k;
    ts_q.wait_and_pop(k);
    answer.push_back(k);
    answer.push_back(*ts_q.wait_and_pop());
    answer.push_back(*ts_q.wait_and_pop());
}

int main() {
    threadsafe_queue<int> ts_queue;
    std::thread t1(producer, std::ref(ts_queue));
    std::thread t2(consumer, std::ref(ts_queue));
    t1.join();
    t2.join();
    return 0;
}
