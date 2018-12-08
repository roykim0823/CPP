// https://gist.github.com/taeguk/f80fddabaa48877e80a0600722d566a0
#include <iostream>

// Ư�������� ���� tag��.
struct walk_ability_tag {};
struct jump_ability_tag {};
struct fly_ability_tag {};
struct run_ability_tag :public walk_ability_tag {};
struct ground_ability_tag :public run_ability_tag, public jump_ability_tag {};
struct all_ability_tag :public ground_ability_tag, public fly_ability_tag {};

// Ư������ Ŭ���� ���ø�.
// Ư������ Ŭ������ ���ʿ� ���� �׻� ����ü�� �����Ѵ�.
template <class T>
struct ability_traits {
	typedef typename T::ability_category ability_category;
};

// Ư�������� ���� ȣ��� �Լ��� ������ Ÿ�ӿ� �����ȴ�.
template <class T>
void move(T& obj) {
	move(obj, typename ability_traits<T>::ability_category());
}

// Ư�������� ���� �Լ����� �����ε�.
template <class T>
void move(T&, walk_ability_tag) { std::cout << "move by walking." << std::endl; }
template <class T>
void move(T&, jump_ability_tag) { std::cout << "move by jumping." << std::endl; }
template <class T>
void move(T&, fly_ability_tag) { std::cout << "move by flying." << std::endl; }
template <class T>
void move(T&, run_ability_tag) { std::cout << "move by running." << std::endl; }
template <class T>
void move(T&, ground_ability_tag) { std::cout << "move through ground." << std::endl; }
template <class T>
void move(T&, all_ability_tag) { std::cout << "move by all methods." << std::endl; }

// Ư�������� �����ϴ� Ŭ������.
class Walker {
public:
	typedef walk_ability_tag ability_category;
};
class Jumper {
public:
	typedef jump_ability_tag ability_category;
};
class Flyer {
public:
	typedef fly_ability_tag ability_category;
};
class Runner {
public:
	typedef run_ability_tag ability_category;
};
class GroundMan {
public:
	typedef ground_ability_tag ability_category;
};
class Master {
public:
	typedef all_ability_tag ability_category;
};

int main() {
	Walker walker;
	Jumper jumper;
	Flyer flyer;
	Runner runner;
	GroundMan groundMan;
	Master master;

	move(walker);
	move(jumper);
	move(flyer);
	move(runner);
	move(groundMan);
	move(master);

	/* ������
	move by walking.
	move by jumping.
	move by flying.
	move by running.
	move through ground.
	move by all methods.
	*/

	return 0;
}