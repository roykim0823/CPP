#include <iostream>
#include <new>
#include "newHandler.h"

// new_hanlder for a specific class
class Widget {
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc);
private:
	static std::new_handler currentHandler;
};

// static class member must be difined outside the class definition
// unless they're const and integral [Item 2]
std::new_handler Widget::currentHandler = nullptr;	// init to null in the class impl. file

std::new_handler Widget::set_new_handler(std::new_handler p) throw() 
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

void* Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder h(std::new_handler(currentHandler));
	return ::operator new(size);
}


// CRTP : Curiously Recurring Template Pattern
class Widget_CRTP : public NewHandlerSupport<Widget_CRTP> {
public:
	Widget_CRTP() {}
	~Widget_CRTP() {}
private:
	char dummy[8];
};

int main() {
	// first exmaple
	std::set_new_handler(outOfMem);
	int *pBigDataArray = new int[1000000000];

	// newHandler Classes
	Widget_CRTP::set_new_handler(outOfMem);

	auto ptr1 = new Widget_CRTP();
	char buf[sizeof(Widget_CRTP)];
	auto ptr2 = new (buf) Widget_CRTP();
	auto ptr3 = new (std::nothrow) Widget_CRTP();
}
