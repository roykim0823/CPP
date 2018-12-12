#include <xutility>
std::input_iterator_tag a;
// ���ø� ���� �߷� ���������� �Ͻ��� Ÿ�� ��ȯ�� ������� �ʽ��ϴ�.
// �Ͻ��� Ÿ�� ��ȯ�� ����Ϸ��� Ÿ���� ��Ȯ�� �˾ƾ��ϴµ� �߷��۾��������� �翬�� �Ұ����� ���Դϴ� ����
namespace issue {
	template <class T>
	class Example {
	public:
		Example(int num)
		{}
	};

	template <class T>
	const Example<T> operator*(const Example<T> &lhs, const Example<T> &rhs) {
		return Example<T>();
	}

	void situation() {
		Example<int> a(2);
		a * 2;  // compile error.
	}
}

// �ذ�å�� ���� �Լ��� Ŭ���� ���ø��ȿ� ��� ���Դϴ�.
// �׷��� Ŭ���� ���ø��� �ν��Ͻ�ȭ�� �� ���� �Լ��� ���� ���ǵǹǷ� ������ �����ϴ�.
// ���� �Լ��� Ŭ���� ���ø� �ȿ� ������� friend ������ ����մϴ�.
namespace solution {
	template <class T>
	class Example {
	public:
		Example(int num)
		{}

		friend const Example<T> operator*(const Example<T> &lhs, const Example<T> &rhs) {
			return Example<T>(2);
		}
	};

	void situation() {
		Example<int> a(2);
		a * 2;  // compile ok!
	}
}

int main() {
	
}