#include <new>

// RAII������� new handler�� �����ϴ� Ŭ����
class NewHandlerRAII {
public:
	explicit NewHandlerRAII(std::new_handler nh) noexcept {
		old = std::set_new_handler(nh);
	}
	~NewHandlerRAII() noexcept {
		std::set_new_handler(old);
	}
	NewHandlerRAII(const NewHandlerRAII&) = delete;
	NewHandlerRAII& operator=(const NewHandlerRAII&) = delete;
private:
	std::new_handler old;
};

// class���� new handler�� ������ �� �ִ� ��ɰ� �������̽��� ��� �ִ� Ŭ���� ���ø�.
template <class T>
class NewHandlerFeature {
public:
	static std::new_handler set_new_handler(std::new_handler nh) noexcept {
		auto old = currentHandler;
		currentHandler = nh;
		return old;
	}
	static void* operator new(std::size_t size) throw(std::bad_alloc) {
		NewHandlerRAII nhr(currentHandler);
		return ::operator new(size);
	}
	static void* operator new(std::size_t size, void *pMem) noexcept {
		// NewHandlerRAII nhr(currentHandler);
		return ::operator new(size, pMem);
	}
	static void* operator new(std::size_t size, const std::nothrow_t& nt) noexcept {
		NewHandlerRAII nhr(currentHandler);
		return ::operator new(size, nt);
	}
	// operator new[]�� ����..
private:
	static std::new_handler currentHandler;
};
template <class T>
std::new_handler NewHandlerFeature<T>::currentHandler = nullptr;

// �ű��ϰ� �ݺ��Ǵ� ���ø� ���� (CRTP : Curiously Recurring Template Pattern)
// also called to "������ ��(Do It For Me)" by Scott Meyers.
// CRTP������ ��������ν� �⺻ Ŭ������ ���������� �Ļ� Ŭ�������� ���� ������ �� �ְԵȴ�.
class Example : public NewHandlerFeature<Example> {
public:
	Example() {}
	~Example() {}
private:
	char dummy[8];
};

void func() {}

int main() {
	Example::set_new_handler(func);
	auto ptr1 = new Example();
	char buf[sizeof(Example)];
	auto ptr2 = new (buf) Example();
	auto ptr3 = new (std::nothrow) Example();
}