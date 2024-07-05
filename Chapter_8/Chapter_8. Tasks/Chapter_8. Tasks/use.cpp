#include "my.h"

namespace X
{
	int var;
	void print()
	{
		std::cout << "X's var: " << var << std::endl;
	}
}

namespace Y
{
	int var;
	void print()
	{
		std::cout << "Y's var: " << var << std::endl;
	}
}

namespace Z
{
	int var;
	void print()
	{
		std::cout << "Z's var: " << var << std::endl;
	}
}

void task_ex1()
{
	foo = 7;
	print_foo();
	print(99);

	char cc;
	std::cin >> cc;
}

void task_ex2()
{
	int x = 7;
	int y = 9;

	swap_v(x, y);  // Компилируется, но не меняет x и y
	std::cout << "x: " << x << ", y: " << y << std::endl;

	swap_r(x, y);  // Компилируется и меняет x и y
	std::cout << "x: " << x << ", y: " << y << std::endl;

	// swap_v(7, 9);  // Компилируется, но бесполезно
	// swap_r(7, 9);  // Не компилируется, нельзя взять ссылку на литерал

	const int cx = 7;
	const int cy = 9;
	// swap_r(cx, cy);  // Не компилируется, нельзя взять неконстантную ссылку на константу

	// swap_v(7.7, 9.9);  // Компилируется, но бесполезно и теряется точность
	// swap_r(7.7, 9.9);  // Не компилируется, нельзя взять ссылку на литерал

	double dx = 7.7;
	double dy = 9.9;
	// swap_v(dx, dy);  // Компилируется, но не меняет dx и dy и теряется точность
	// swap_r(dx, dy);  // Не компилируется, несоответствие типов
}

void task_ex3()
{
	X::var = 7;
	X::print();

	using namespace Y;
	var = 9;
	print();

	{
		using Z::var;
		using Z::print;
		var = 11;
		print();
	}

	print();
	X::print();
}

int main()
{
	task_ex1();
	return 0;
}
