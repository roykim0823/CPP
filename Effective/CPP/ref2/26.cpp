
class Example {
public:
	explicit Example(int n) {}
};

typedef int Data;

int main() {
	Example ex(1);

	Example(3);

	(Example) 3;

	// ��� 1
	// ������ 1�� + �Ҹ��� 1�� + ���� n��
	for (Data data, int i = 0; i < n; ++i) {
		data = func(i);
	}
	// ��� 2
	// ������ n�� + �Ҹ��� n��
	for (int i = 0; i < n; ++i) {
		Data data = func(i);
	}
	// ��� 1 if cost(����) > cost(������ + �Ҹ���),
	// ��� 2 otherwise.
}