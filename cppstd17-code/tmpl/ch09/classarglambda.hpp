#include <utility>  // for std::forward

template <typename CB>
class CountCalls
{
    private:
        CB callback;
        long calls = 0;
    public:
        CountCalls(CB cb) : callback(cb) {}
        template <typename... Args>
        auto operator()(Args&&... args) {
            ++calls;
            return callback(std::forward<Args>(args)...);
        }
        long count() const {
            return calls;
        }
};