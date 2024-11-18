#include <memory>
#include <mutex>

template<typename T>
class queue
{
private:
    struct node
    {
        T data;
        std::unique_ptr<node> next;

        node(T data_):
            data(std::move(data_))
        {}
    };
    
    std::unique_ptr<node> head;
    node* tail;
    // add mutex to illustrate the serialization problem
    std::mutex head_mutex;
    std::mutex tail_mutex;
    
public:
    queue():
        tail(nullptr)
    {}

    queue(const queue& other)=delete;
    queue& operator=(const queue& other)=delete;

    std::shared_ptr<T> try_pop()
    {
        std::lock_guard<std::mutex> hlg(head_mutex);  // added mutex
        if(!head)
        {
            return std::shared_ptr<T>();
        }
        std::shared_ptr<T> const res(
            std::make_shared<T>(std::move(head->data)));
        std::unique_ptr<node> const old_head=std::move(head);
        head=std::move(old_head->next);
        if(!head)
            tail=nullptr;  // tail points to null when it is empty. this can cause an exception in push()
                           // or you can put a lock on tail. -> only one thread can execute either try_pop() or push()
        return res;
    }
    
    void push(T new_value)
    {
        std::unique_ptr<node> p(new node(std::move(new_value)));
        node* const new_tail=p.get();

        std::lock_guard<std::mutex> tlg(tail_mutex);  // added mutex
        if(tail)
        {
            tail->next=std::move(p);  // it can point to null when the other thread is executing try_pop()
                                      // and there is only one element in the queue.
        }
        else
        {
            std::lock_guard<std::mutex> hlg(head_mutex);  // added mutex
            head=std::move(p);
        }
        tail=new_tail;
    }
};

