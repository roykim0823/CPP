#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class WidgetImpl {
};

template <typename T>
class Widget {
public:
	void swap(Widget &ex) {
		using std::swap;
		swap(pImpl, ex.pImpl);
	}
private:
	WidgetImpl<T> *pImpl;
};

template <typename T>
void swap(Widget<T> a, Widget<T> b) {
	cout << "Widget::swap is called" << endl;
	a.swap(b);
}

template <typename T>
void func(T& a, T& b) {
	using std::swap;
	swap(a, b);
}

int main() {
	Widget<int> a, b;
	func(a, b);
}
