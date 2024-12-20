#pragma once
#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
template<typename T>
class threadsafe_queue
{
private:
    struct node {
        std::shared_ptr<T> data;
        std::unique_ptr<node> next;

        node() {}
		node(T _data) : data(std::move(_data)) {}
    };

    //std::atomic<node*> head;
    //std::atomic<node*> tail;


    std::mutex head_mutex;
    std::unique_ptr<node> head;
    std::mutex tail_mutex;
    node* tail;
    std::condition_variable data_cond;

    node* get_tail() {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        return tail;
    }

    std::unique_ptr<node> pop_head() {
        // std::unique_ptr<node> const old_head=std::move(head);
        // NOTE! 'const' cast issue here, remvoe const (copy ellision won't work on const)
		// std::unique_ptr<node> const old_head = std::move(head);
        std::unique_ptr<node> old_head = std::move(head);
        head=std::move(old_head->next);
        return old_head;  // NOTE!: be carefull, non const variable needed to allow copy ellision
    }

    std::unique_lock<std::mutex> wait_for_data() {
        std::unique_lock<std::mutex> head_lock(head_mutex);
        //? Need to wait for the condion variable
		//* (maybe someone pushing to the queue at the moment)
		//? and also check if there is something in the queue
		//* (head.get() == get_tail()) - when head and tail points to the dummy node
		//! do we stick in the loop until one element will appear in the queue?
		//! do we need this?
        data_cond.wait(head_lock, [&] {return head.get() != get_tail();});
        return std::move(head_lock);
    }

    std::unique_ptr<node> wait_pop_head() {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        return pop_head();
    }

    std::unique_ptr<node> wait_pop_head(T& value) {
        std::unique_lock<std::mutex> head_lock(wait_for_data());
        value=std::move(*head->data);
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head() {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail()) {
            return std::unique_ptr<node>();
        }
        return pop_head();
    }

    std::unique_ptr<node> try_pop_head(T& value) {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        if(head.get()==get_tail()) {
            return std::unique_ptr<node>();
        }
        value=std::move(*head->data);
        return pop_head();
    }

public:
    threadsafe_queue(): head(new node), tail(head.get()) {}

    std::shared_ptr<T> wait_and_pop() {
        std::unique_ptr<node> const old_head=wait_pop_head();
        return old_head->data;
    }

    void wait_and_pop(T& value) {
        std::unique_ptr<node> const old_head=wait_pop_head(value);
    }

    std::shared_ptr<T> try_pop() {
        std::unique_ptr<node> const old_head=try_pop_head();
        return old_head?old_head->data:std::shared_ptr<T>();
    }

    bool try_pop(T& value) {
        std::unique_ptr<node> const old_head=try_pop_head(value);
        return old_head;
    }

    bool empty() {
        std::lock_guard<std::mutex> head_lock(head_mutex);
        return (head==get_tail());
    }

    void push(T new_value);
    void printData();
};

template<typename T>
void threadsafe_queue<T>::push(T new_value)
{
    std::shared_ptr<T> new_data(std::make_shared<T>(std::move(new_value)));
    std::unique_ptr<node> p(new node);
    {
        std::lock_guard<std::mutex> tail_lock(tail_mutex);
        tail->data = new_data;
        node* const new_tail = p.get();
        tail->next = std::move(p);
        tail = new_tail;
    }
    data_cond.notify_one();
}

template <typename T>
inline void threadsafe_queue<T>::printData()
{
	if (head.get() == get_tail())
	{
		std::cout << "Queue is empty...\n";
		return;
	}

	std::lock_guard<std::mutex> hlg(head_mutex);

	node* current = head.get();
	std::cout << "Queue from top to bottom...\n";
	int index{};
	while (current->data != nullptr)
	{
		std::cout << "current: " << current << ", value [" << index++ << "]: " << *(current->data) << std::endl;
		current = (current->next).get();
	}
	std::cout << "End of the queue...\n";
}