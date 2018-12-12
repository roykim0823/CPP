
// �Ļ��� Ŭ�������� �����Լ��� ���������� ���� ���,
// �ǵ����� ���� ������ �߻��� ������ �ִ�.
namespace issue {
	class Base {
	public:
		virtual void func() { /* default working */ }
	};
	class Derived : public Base {
		// no declaration of func.
	};
	void situation() {
		Derived obj;
		obj.func();  // no error.
	}
}
// �ذ�å 1
// ���������Լ��� ������ �ϰ�, default�Լ��� �񰡻��Լ��� �����ϴ� ���.
namespace solution_1 {
	class Base {
	public:
		virtual void func() = 0;
	protected:
		void defaultFunc() { /* default working */ }
	};
	class Derived : public Base {
	public:
		// must declare func.
		virtual void func() { defaultFunc(); }
	};
	void situation() {
		Derived obj;
		obj.func();
	}
}
// �ذ�å 2
// ���������Լ��� ������ �ϰ� ���Ǹ� �����ع�����(?). ������
// default �Լ��� �� �����ؾ��ϴ� ���� �Ž��� ��� �̿��� �� �ִ� ���.
namespace solution_2 {
	class Base {
	public:
		virtual void func() = 0;
	};
	class Derived : public Base {
	public:
		// must declare func.
		virtual void func() { Base::func(); }
	};
	void situation() {
		Derived obj;
		obj.func();
	}
	void Base::func() { /* default working */ }
}
