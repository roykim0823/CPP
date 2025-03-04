#include <mutex>
#include <condition_variable>
#include <iostream>
#include <thread>
#include <queue>

bool more_data = true;
bool more_data_to_prepare()
{
    return more_data;
}

struct data_chunk
{};

data_chunk prepare_data()
{
    return data_chunk();
}

void process(data_chunk&)
{
    std::cout << "process data..." << std::endl;
}

bool is_last_chunk(data_chunk&)
{
    return true;
}

std::mutex mut;
std::queue<data_chunk> data_queue;
std::condition_variable data_cond;

void data_preparation_thread() {
    while(more_data_to_prepare()) {
        data_chunk const data=prepare_data();
        {
            std::lock_guard<std::mutex> lk(mut);
            data_queue.push(data);
        }
        data_cond.notify_one();  // notify the condition variable after unlocking the mutex
        std::cout << "notify_one()" << std::endl;  // should be used under lock()
        more_data=false;  // to exit the while loop
    }
}

void data_processing_thread() {
    while(true) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk,[]{return !data_queue.empty();});
        data_chunk data=data_queue.front();
        data_queue.pop();
        lk.unlock();
        process(data);
        if(is_last_chunk(data))
            break;
    }
}

int main() {
    std::thread t1(data_preparation_thread);
    std::thread t2(data_processing_thread);

    t1.join();
    t2.join();
}
