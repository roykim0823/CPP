#include <atomic>
#include <thread>
#include <vector>
#include <iostream>
std::vector<int> queue_data;
std::atomic<int> count;

void wait_for_more_items() {
    std::this_thread::sleep_for(std::chrono::microseconds(100));
}

void process(int data){
    std::cout << data << std::endl;
}

void populate_queue()  // write
{
    unsigned const number_of_items=20;
    queue_data.clear();
    for(unsigned i=0; i<number_of_items; ++i)
    {
        queue_data.push_back(i);
    }

    count.store(number_of_items,std::memory_order_release);  // initial store
}

void consume_queue_items()  // read
{
    while(true)
    {
        int item_index;
        if((item_index = count.fetch_sub(1,std::memory_order_acquire))<=0)
        {
            wait_for_more_items();
            //continue;
            break;  // to end the execution when the count becomes 0
        }
        process(queue_data[item_index-1]);  // reading queue is safe
    }
}

int main()
{
    std::thread a(populate_queue);
    std::thread b(consume_queue_items);
    std::thread c(consume_queue_items);
    a.join();
    b.join();
    c.join();
}
