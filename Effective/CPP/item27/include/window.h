#include <iostream>

using namespace std;

class Window {
public:
	Window(int size=100) : size(size) {}
	virtual void onResize(int resize) {
		size=resize;
		cout << "Window's onResize(): " << size << endl; 
	}
	int get_size() { return size; }
private:
	int size;
};

class SpecialWindow: public Window {
public:
	virtual void onResize(int resize) { 
		// calling base class onResize
		//static_cast<Window>(*this).onResize(resize);	// it won't work: update a copy of base obj
        Window::onResize(200);
		cout << "Special's onResize(): " << get_size() << endl;
		// get_size() output is 100 (not changed) with static_case
	}

	void blink() {
		cout << "Special's blink()" << endl;
	}
};
