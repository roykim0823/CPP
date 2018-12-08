#include <iostream>
#include <new>

// function to call if operator new can't allocate enough memory
void outOfMem() {
	std::cerr << "Unable to stisfy request for memory\n";
	std::abort();
}

// new handler with RAII
class NewHandlerHolder {
public:
	explicit NewHandlerHolder(std::new_handler nh) noexcept	// accquire current new-handler 
	: handler(nh) {}
	~NewHandlerHolder() noexcept                             	// release it
	{ std::set_new_handler(handler); }

	// prevent copyting
	NewHandlerHolder(const NewHandlerHolder&) = delete;
	NewHandlerHolder& operator=(const NewHandlerHolder&) = delete;
private:
	std::new_handler handler;
};

// "mixin-style" base class for class-specfic set_new_handler support
// CRTP : Curiously Recurring Template Pattern
// The template never uses its type parameter T. It doesn't need to
// The template parameter T just distinguishes one inheriting class from another
template <class T>
class NewHandlerSupport {
public:
	static std::new_handler set_new_handler(std::new_handler nh) noexcept {
		auto oldHandler = currentHandler;
		currentHandler = nh;
		return oldHandler;
	}
	static void* operator new(std::size_t size) throw(std::bad_alloc) {
		NewHandlerHolder nhr(currentHandler);
		return ::operator new(size);
	}
	static void* operator new(std::size_t size, void *pMem) noexcept {
		// NewHandlerRAII nhr(currentHandler);
		return ::operator new(size, pMem);
	}
	static void* operator new(std::size_t size, const std::nothrow_t& nt) noexcept {
		NewHandlerHolder nhr(currentHandler);
		return ::operator new(size, nt);
	}
	// operator new[]
private:
	static std::new_handler currentHandler;
};

template< class T>
std::new_handler NewHandlerSupport<T>::currentHandler=nullptr;
