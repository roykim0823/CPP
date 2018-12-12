
// ��ø ���� �̸��� �⺻������ Ÿ���� �ƴ϶�� �����ȴ�.
// ��ø ���� �̸��� Ÿ������ �˷��ֱ� ���ؼ��� typename Ű���带 ����ؾ��Ѵ�.
template <class T>
void example(void) {
	int a;  // ������ �̸�(non-dependent name)
	T b;  // ���� �̸�(dependent name)
	auto c = T::variable;  // ��ø ���� �̸�(nested dependent name)
	typename T::type d;  // ��ø ���� Ÿ�� �̸�(nested dependent type name)
}

// typename�� ��ø ���� �̸��� �ĺ��ϴ� ������ ����� �� �ִ�.
template <class T>
void func(const T& obj);  // typename ���� �� ��.

// ��ø ���� �̸��� '���ƻ�' Ÿ���� �� �ۿ� ���� ��쿡�� typename�� ���� �ȵȴ�.
template <class T>
class Derived :public Base<T>::musttype {
	Derived(int val)
		: Base<T>::musttype(val)
	{}
};