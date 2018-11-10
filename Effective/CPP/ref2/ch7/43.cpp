
template <class T>
class Base {
public:
	void func_of_base() {}
};

// C++�� '�̸� ����(early diagnose)'�� ��ȣ�Ѵ�.
// ��ȿ�� üũ�� 'Ŭ���� ���ø� ������ ���� �м�' �ÿ� �����Ѵ�. (�ν���ȭ�� ���� �ƴ϶�)
// �׷��� Ŭ���� ���ø��� ���� ���� ��ӵǴ� �� ��ü������ �𸥴�.
// ���� func_of_base�� ����ִ����� �� �� ����. �װ��� ������.
// �����Ϸ��� ���� ǥ���� ����, �̸� ������ִ� ��쵵 �ִ�. (visual studio 2013�� �׷��׿��)
template <class T>
class Problem :public Base<T> {
public:
	void foo() {
		func_of_base();  // compile error!
	}
};

// this pointer�� �̿��� �ذ�å.
template <class T>
class SolutionOne :public Base<T> {
public:
	void foo() {
		this->func_of_base();  // �Լ��� ��ӵǴ� ������ �����ȴ�.
	}
};

// using ������ �̿��� �ذ�å.
template <class T>
class SolutionTwo :public Base<T> {
public:
	using Base<T>::func_of_base;  // Base<T>�� �Լ��� �ִ� ������ �����ȴ�.
	void foo() {
		func_of_base();
	}
};

// �����ȣ���� ���� �ذ�å.
// ��, ���� �Լ� ���ε��� ���õǹǷ� �Ⱦ��°� ����.
template <class T>
class SolutionThree :public Base<T> {
public:
	void foo() {
		Base<T>::func_of_base();  // ��������� �Լ��� �����Ѵ�.
	}
};

// �������� �������δ� �ذ�å1(this pointer�� �̿��� �ذ�å) �� ���� ���ƺ��δ�.


int main() {
}