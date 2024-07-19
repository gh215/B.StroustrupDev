#include "head.h"

void print_ex2(const string& comment, const vector<int>& v)
{
	cout << comment << ": ";
	for (int num : v)
	{
		cout << num << '\n';
	}
}

void print_ex2(const string& comment, const vector<string>& v)
{
	cout << comment << ": ";
	for (string num : v)
	{
		cout << num << '\n';
	}
}

vector<int> fibonacci_ex3(int x, int y, vector<int> v, int n)
{
	v.push_back(x);
	v.push_back(y);
	for (int i = 2; i < n; ++i)
	{
		v.push_back(v[i - 1] + v[i - 2]);
	}

	return v;
}

vector<int> fibonacci_overflow_ex4(int x, int y, vector<int> v, int n)
{
	v.push_back(x);
	v.push_back(y);
	for (int i = 2; i < n; ++i)
	{
		if (v[i - 1] > numeric_limits<int>::max() - v[i - 2]) throw out_of_range("Произошло переполнение");
			// Если следующее число Фибоначчи превысит максимальное значение int, прерываем цикл
		v.push_back(v[i - 1] + v[i - 2]);
	}
	return v;
}

vector<int> reverseVectorCopy_ex5(const vector<int>& vec)
{
	return vector<int>(vec.rbegin(), vec.rend());
}

void swap_r(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_r(string& a, string& b)
{
	string temp = a;
	a = b;
	b = temp;
}

void reverseVectorInPlace_ex5(vector<int>& vec)
{
	int last_ind = vec.size() - 1;
	for (size_t i = 0; i < vec.size() / 2; i++)
	{
		swap_r(vec[i], vec[last_ind - i]);
	}
}

vector<string> reverseVectorCopy_ex6(const vector<string>& vec)
{
	return vector<string>(vec.rbegin(), vec.rend());
}

void reverseVectorInPlace_ex6(vector<string>& vec)
{
	int last_ind = vec.size() - 1;
	for (size_t i = 0; i < vec.size() / 2; i++)
	{
		swap_r(vec[i], vec[last_ind - i]);
	}
}

bool comparePairs(const pair<string, double>& a, const pair<string, double>& b) 
{
	if (a.second != b.second) 
	{
		return a.second < b.second;
	}
	return a.first < b.first;
}

void PeopleCount_ex7()
{
	vector<string> names;
	vector<double> ages;
	string name;
	double age;

	cout << "Введите имена и возраст (для завершения введите '-1'):\n";
	while (name != "-1")
	{
		cout << "Имя: ";
		cin >> name;
		names.push_back(name);

		cout << "Возраст: ";
		cin >> age;
		ages.push_back(age);
	}

	cout << "Исходные пары (имя, возраст):\n";
	for (size_t i = 0; i < names.size(); ++i) 
	{
		cout << names[i] << ": " << ages[i] << endl;
	}

	// Создаем вектор пар (возраст, имя) для сортировки
	vector<pair<double, string>> age_name_pairs;
	for (size_t i = 0; i < names.size(); ++i) 
	{
		age_name_pairs.push_back(make_pair(ages[i], names[i]));
	}

	sort(age_name_pairs.begin(), age_name_pairs.end());

	cout << "\nОтсортированные пары (имя, возраст):\n";
	for (const auto& pair : age_name_pairs) 
	{
		cout << pair.second << ": " << pair.first << endl;
	}
}


double sumOfProducts_ex8(const vector<double>& price, const vector<double>& weight)
{
	if (price.size() != weight.size())
	{
		throw invalid_argument("Векторы должны иметь одинаковый размер");
	}

	double sum = 0;
	for (size_t i = 0; i < price.size(); ++i)
	{
		sum += price[i] * weight[i];
	}

	return sum;
}

int maxv_ex9(const vector<int>& vec)
{
	if (vec.empty())
	{
		throw runtime_error("Vector is empty");
	}

	int max_value = vec[0];  

	for (size_t i = 1; i < vec.size(); ++i)
	{
		if (vec[i] > max_value)
		{
			max_value = vec[i];
		}
	}

	return max_value;
}

/*
void analyseVector_ex10(const vector<int>& vec, int& min, int& max, double& average, double& median) 
*/

VectorStats analyseVector_ex10(const vector<int>& vec) 
{
	VectorStats result;

	if (vec.empty()) 
	{
		throw exception("Пустой вектор");
	}


	result.min = *min_element(vec.begin(), vec.end());
	result.max = *max_element(vec.begin(), vec.end());

	double sum = 0;
	for (int num : vec) 
	{
		sum += num;
	}
	result.average = sum / vec.size();

	vector<int> sorted_vec = vec;
	sort(sorted_vec.begin(), sorted_vec.end());

	if (sorted_vec.size() % 2 == 0) 
	{
		result.median = (sorted_vec[sorted_vec.size() / 2 - 1] + sorted_vec[sorted_vec.size() / 2]);
	}
	else 
	{
		result.median = sorted_vec[sorted_vec.size() / 2];
	}

	return result;
}

bool print_until_s_ex11(const vector<string>& v, const string& quit) 
{
	for (const auto& s : v) 
	{
		if (s == quit) return true;
		cout << s << '\n';
	}

	return false;
}

bool print_until_ss_ex11(const vector<string>& v, const string& quit)
{
	int count = 0;
	const int stop_word_max_count = 2;
	for (const auto& s : v) 
	{
		if (s == quit) 
		{
			count++;
			if (count == stop_word_max_count) return true;
		}
		cout << s << '\n';
	}

	return false;
}

/*
Я решил эту задачу в одной функции, так как все операции можно выполнить за один проход по вектору. 
Это эффективнее, чем использовать отдельные функции для каждой задачи.
*/
vector<int> getStringLengths_ex12(const vector<string>& v) 
{
	vector<int> lengths;
	string shortest = v[0];
	string longest = v[0];
	string first = v[0];
	string last = v[0];

	for (const auto& s : v) 
	{
		lengths.push_back(s.size());
		if (s.size() < shortest.size())
		{
			shortest = s;
		}
		if (s.size() > longest.size())
		{
			longest = s;
		}
		if (s < first)
		{
			first = s;
		}
		if (s > last)
		{
			last = s;
		}
	}

	cout << "Самая короткая: " << shortest << endl;
	cout << "Самый длинная: " << longest << endl;
	cout << "Первый лексикографический: " << first << endl;
	cout << "Последний лексикографический: " << last << endl;

	return lengths;
}

/*
Да, можно объявить константный аргумент функции, который передается не по ссылке. 
Однако это редко используется, потому что:
При передаче по значению создается копия, поэтому изменение аргумента внутри функции все равно не повлияет на оригинальное значение.
Для примитивных типов (int, double и т.д.) копирование не является дорогостоящей операцией.
Если мы не собираемся изменять аргумент, нет особой необходимости объявлять его константным, если он передается по значению.
[Это может ввести в заблуждение других программистов, так как обычно const используется с передачей по ссылке].
*/
void f_ex13(const int x) 
{
	cout << x << "\n";
	// x нельзя изменить внутри функции
	// int y = x + 1; - допустимо
	// x = 5; - вызовет ошибку компиляции
}

void ex3_print()
{
	vector<int> fib_numbers = fibonacci_ex3(1, 2, {}, 50);
	print_ex2("Числа Фибоначчи", fib_numbers);
}

void ex4_print()
{
	vector<int> fib_numbers = fibonacci_overflow_ex4(1, 2, {}, 100);
	print_ex2("Числа Фибоначчи/переполнение", fib_numbers);
}

void ex5_print()
{
	vector<int> original = { 2,5,7,9,12,32 };
	vector<int> reversed = reverseVectorCopy_ex5(original);
	vector<int> vec = original;
	reverseVectorInPlace_ex5(vec);

	print_ex2("Исходный вектор", original);
	cout << endl;
	print_ex2("Обратный вектор (копия)", reversed);
	cout << endl;

	reverseVectorInPlace_ex5(vec);
	print_ex2("Обратный вектор (на месте)", vec);
}

void ex6_print()
{
	vector<string> original = { "Hehe, here we go" };
	vector<string> reversed = reverseVectorCopy_ex6(original);
	vector<string> vec = original;
	reverseVectorInPlace_ex6(vec);

	cout << "Исходный вектор: ";
	for (const auto& str : original) cout << str << " ";
	cout << endl;

	cout << "Обратный вектор (копия): ";
	for (const auto& str : reversed) cout << str << " ";
	cout << endl;

	reverseVectorInPlace_ex6(vec);
	cout << "Обратный вектор (на месте): ";
	for (const auto& str : vec) cout << str << " ";
	cout << endl;
}

void ex7_print()
{
	PeopleCount_ex7();
}

void ex8_print()
{
	cout << sumOfProducts_ex8({ 12, 16, 18, 20, 22 }, { 6, 9, 1, 8, 20 });
}

void ex9_print()
{
	cout << maxv_ex9({ 1, 4, 5, 7, 10, 23 });
}

void ex10_print()
{
	vector<int> vec = { 10, 24, 15, 11, 15 };
	VectorStats result = analyseVector_ex10(vec); 

	cout << "Минимум: " << result.min << endl;
	cout << "Максимум: " << result.max << endl;
	cout << "Среднее: " << result.average << endl;
	cout << "Медиана: " << result.median << endl;
}


void ex11_tests()
{
	string quit = "quit";

	cout << "Тест 0:\n";
	vector<string> test0 = {"a", "b", "s"};
	print_until_s_ex11(test0, quit);
	cout << "\n";

	cout << "Тест 1: Пустой вектор\n";
	vector<string> test1 = {};
	print_until_s_ex11(test1, quit);
	cout << "\n";

	cout << "Тест 2: Вектор, где строка quit отсутствует\n";
	vector<string> test2 = { "apple", "banana", "cherry", "date" };
	print_until_s_ex11(test2, quit);
	cout << "\n";

	cout << "Тест 3: Вектор, где строка quit находится в начале\n";
	vector<string> test3 = { "stop", "apple", "banana", "cherry", "date" };
	print_until_s_ex11(test3, quit);
	cout << "\n";

	cout << "Тест 4: Вектор, где строка quit находится в конце\n";
	vector<string> test4 = { "apple", "banana", "cherry", "date", "stop" };
	print_until_s_ex11(test4, quit);
	cout << "\n";

	cout << "Тест 5: Вектор, где строка quit встречается несколько раз\n";
	vector<string> test5 = { "apple", "stop", "banana", "stop", "cherry", "date" };
	print_until_s_ex11(test5, quit);
}

void ex12_print()
{
	vector<string> inputStrings = { "Never be alone here", "Another string", "Short" };
	vector<int> lengths = getStringLengths_ex12(inputStrings);

	for (size_t i = 0; i < inputStrings.size(); ++i)
	{
		cout << "Строка: " << inputStrings[i] << ", Длина: " << lengths[i] << endl;
	}
}

void ex13()
{
	int a = 5;
	f_ex13(a);
}
