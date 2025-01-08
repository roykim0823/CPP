#include <vector>
#include <atomic>
#include <iostream>
#include <chrono>
#include <thread>

std::vector<int> data;
std::atomic_bool data_ready(false);

// Important Relations with atomic
// 1. Happen-before within the thread
// 2. Inter-thread-happen-before
// 3. Synchronized-with

void reader_thread()
{
    // synchronized with data_ready
    while(!data_ready.load())  
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }// happen_before from the access data[0]
    
    // inter-thread happen-before (push_back happens before the access)
    std::cout<<"The answer = "<< data[0] << "\n";
}

void writer_thread()
{
    data.push_back(42);  // happen-before the atomic op (data_read = true) 
    data_ready=true;
}

void run_code() {
    std::thread reader(reader_thread);
    std::thread writer(writer_thread);

    reader.join();
    writer.join();
}

int main() {
    run_code();
}