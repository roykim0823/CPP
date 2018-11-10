#include <new>

// �׸�33ó�� �̸� ������ ������ �߻��� �� �ִ�.
// �⺻Ŭ���� ������ �̸��� �������� �� using���� �ذ��� �� ������, ���� �̸��� �������� �ذ��� �� ����.
// ���� ���� operator new/delete�� wrapper interface�� �������μ� �ذ��Ѵ�.
// �� �� ���ϰ� �Ϸ��� wrapper interface���� ������ Ŭ������ �ϳ� ����� �̰� ��������μ� �ذ��Ѵ�.
namespace name_hiding {
	namespace problem {
		class Example {
		public:
			using ::operator new;  // compile error. it is impossible :(
			static void* operator new(std::size_t size, void *pMem) noexcept {
				...
			}
		};
		void situation() {
			new Example();  // compile error.
		}
	}
	namespace solution {
		class GlobalNewDeleteFeature { ... };  // it has wrapper interfaces to global operator new/delete
		class Example : public GlobalNewDeleteFeature {
		public:
			using GlobalNewDeleteFeature::operator new;
			using GlobalNewDeleteFeature::operator delete;
			static void* operator new(std::size_t size, void *pMem) noexcept {
				...
			}
		};
		void situation() {
			new Example();  // compile ok.
		}
	}
}

// new Ű����� ��ü�� ������ ��, �����ڿ��� ���ܰ� �߻��� ���, operator delete�� ȣ��Ǿ�߸� �Ѵ�.
// �޸��Ҵ�� ���� operator new�� "�߰� �Ű�����" ����/Ÿ���� �Ȱ��� operator delete�� ã�Ƽ� ȣ���Ѵ�.
// ����, �׷��� operator delete�� �������� �ʴ´ٸ� �ƹ��͵� ȣ������ʰ�, memory leak�� �߻��ϰ� �ȴ�.
// �ذ�å�� �׻� operator new�� operator delete�� ¦�� �°� �����ϴ� ���̴�.
// �߰������� newŰ����� deleteŰ���� ���� �׻� ¦�� �°� ������־���Ѵ�. �׷��� ������� ������ ���� �� �ִ�.
namespace memory_leak {
	class Example {
	public:
		Example() {
			throw 1;
		}
		static void* operator new(std::size_t size, void *pMem) noexcept {
			return ::operator new(size, pMem);
		}
	};
	void situation() {
		char buf[sizeof(Example)];
		auto ptr = new (buf) Example(); // operator delete is not called.
		delete ptr;  // call basic operator delete(="void ::operator delete(void*)").
	}
}

int main() {
}