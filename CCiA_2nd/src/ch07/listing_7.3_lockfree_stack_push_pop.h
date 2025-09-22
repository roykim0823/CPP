#include <atomic>
#include <memory>

template<typename T>
class lock_free_stack
{
private:
    struct node
    {
        std::shared_ptr<T> data;
        node* next;
        node(T const& data_):
            data(std::make_shared<T>(data_))
        {}
    };
    std::atomic<node*> head;
public:
    void push(T const& data)
    {
        // Not thread safe implementation
        // node* const new_node = new node(data);
        // new_node->next= head;
        // head = new_node;
        
        node* const new_node = new node(data);
        new_node->next = head.load();
        while(!head.compare_exchange_weak(new_node->next, new_node));
    }

    std::shared_ptr<T> pop()  // There are memory leaks...
    {
        // Not thread safe implementation
        // node *old_head = head;
        // head = old_head->next;
        // result = old_head->data;
        // delete old_head;
        
        node* old_head=head.load();
        while(old_head &&  // check the empty stack
              !head.compare_exchange_weak(old_head, old_head->next));
        return old_head ? old_head->data : std::shared_ptr<T>();
    }
};
