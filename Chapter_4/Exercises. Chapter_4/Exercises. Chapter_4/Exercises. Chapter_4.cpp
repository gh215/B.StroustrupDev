#include <iostream>
#include <utility>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <limits>

using namespace std;

void ex2()
{

}

void ex3()
{
	vector<double> distances;
	double distance;

	cout << "Введите расстояния между городами (0 для завершения):" << endl;
	while (cin >> distance && distance != 0)
	{
		distances.push_back(distance);
	}

	double totalDistance = 0;
	double minDistance = numeric_limits<double>::max();
	double maxDistance = numeric_limits<double>::min();
	double averageDistance = 0;

	for (double d : distances)
	{
		totalDistance += d;
		minDistance = min(minDistance, d);
		maxDistance = max(maxDistance, d);
	}

	if (!distances.empty())
	{
		averageDistance = totalDistance / distances.size();
	}

	cout << "Общее расстояние: " << totalDistance << endl;
	cout << "Наименьшее расстояние: " << minDistance << endl;
	cout << "Наибольшее расстояние: " << maxDistance << endl;
	cout << "Среднее расстояние: " << averageDistance << endl;
}

void guessNumber_ex4()
{
	int min = 1;
	int max = 100;
	cout << "Задумайте число от 1 до 100" << endl;

	for (int i = 0; i < 7; ++i)
	{
		int guess = min + (max - min) / 2;
		cout << "Может быть, ваше число " << guess << "? (min, max, correct)" << endl;
		string response;
		cin >> response;

		if (response == "max")
		{
			max = guess - 1;
		}
		else if (response == "min")
		{
			min = guess + 1;
		}
		else if (response == "correct")
		{
			cout << "Поздравляем, я угадал!" << endl;
			return;
		}
		else
		{
			cout << "Некорректный ответ. Попробуйте снова." << endl;
		}
	}
	cout << "Я не смог угадать ваше число." << endl;
}

void calculator_ex5()
{
	double a, b;
	char oper;
	double result = 0;

	cout << "Введите два числа и оператор (например, +, -, *, /): " << endl;

	cout << "Введите первое число: ";
	cin >> a;

	cout << "Введите второе число: ";
	cin >> b;

	cout << "Введите оператор: ";
	cin >> oper;

	switch (oper)
	{
	case '+':
		result = a + b;
		cout << "Сумма " << a << " и " << b << " равна " << result << endl;
		break;

	case '-':
		result = a - b;
		cout << "Разность " << a << " и " << b << " равна " << result << endl;
		break;

	case '*':
		result = a * b;
		cout << "Произведение " << a << " и " << b << " равно " << result << endl;
		break;

	case '/':
		if (b != 0)
		{
			result = a / b;
			cout << "Частное " << a << " и " << b << " равно " << result << endl;
		}
		else
		{
			cout << "Деление на ноль невозможно" << endl;
		}
		break;
	default:
		cout << "Неизвестный оператор" << endl;
		break;
	}
}

void ex6()
{
	vector<string> numberNames = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	while (true)
	{
		cout << "Введите число (от 0 до 9) или строку (от 'zero' до 'nine'): ";
		string input;
		cin >> input;

		bool isNumber = true;
		for (char c : input)
		{
			if (!isdigit(c))
			{
				isNumber = false;
				break;
			}
		}

		if (isNumber)
		{
			int num = stoi(input);
			if (num >= 0 && num <= 9)
			{
				cout << numberNames[num] << endl;
			}
			else
			{
				cout << "Число должно быть от 0 до 9." << endl;
			}
		}
		else
		{
			bool found = false;
			for (int i = 0; i < numberNames.size(); ++i)
			{
				if (numberNames[i] == input)
				{
					cout << i << endl;
					found = true;
					break;
				}
			}
			if (!found)
			{
				cout << "Неверно вводимое число" << endl;
			}
		}
	}
}

void calculator_ex7()
{
	string a, b;
	char oper;
	double result = 0;

	cout << "Введите два числа и оператор (например, +, -, *, /): " << endl;

	cout << "Введите первое число: ";
	cin >> a;

	cout << "Введите второе число: ";
	cin >> b;

	cout << "Введите оператор: ";
	cin >> oper;

	double numA = stod(a);
	double numB = stod(b);

	switch (oper)
	{
	case '+':
		result = numA + numB;
		cout << "Сумма " << a << " и " << b << " равна " << result << endl;
		break;

	case '-':
		result = numA - numB;
		cout << "Разность " << a << " и " << b << " равна " << result << endl;
		break;

	case '*':
		result = numA * numB;
		cout << "Произведение " << a << " и " << b << " равна " << result << endl;
		break;

	case '/':
		if (numB != 0) {
			result = numA / numB;
			std::cout << "Частное " << numA << " и " << numB << " равна " << result << std::endl;
		}
		else {
			std::cout << "Деление на ноль невозможно" << std::endl;
		}
		break;
	default:
		cout << "Неизвестный оператор" << endl;
		break;
	}
}

void ex8()
{
	int grains = 1;
	int totalGrains = 0;
	int cell = 0;

	while (totalGrains < 1000)
	{
		totalGrains += grains;
		grains *= 2;
		cell++;
	}
	cout << "Для не менее 1000 зерен: " << cell << endl;

	while (totalGrains < 1000000)
	{
		totalGrains += grains;
		grains *= 2;
		cell++;
	}
	cout << "Для не менее 1 000 000 зерен: " << cell << endl;

	while (totalGrains < 1000000000)
	{
		totalGrains += grains;
		grains *= 2;
		cell++;
	}
	cout << "Для не менее 1 000 000 000 зерен: " << cell << endl;
}

void ex9()
{
	int grains = 1;
	long double ldgrains = 1.0;
	int totalGrains = 0;
	int cell = 0;
	long double totalGrainsDouble = 0.0;

	while (totalGrains < INT_MAX)
	{
		totalGrains += grains;
		grains *= 2;
		cell++;
	}
	cout << "Максимальное количество клеток для int: " << cell << endl;

	while (totalGrainsDouble < LDBL_MAX)
	{
		totalGrainsDouble += ldgrains;
		ldgrains *= 2;
		cell++;
	}
	cout << "Максимальное количество клеток для double: " << cell << endl;
}

void ex10()
{
	srand(static_cast<unsigned int>(time(0)));
	int userChoice, computerChoice;

	cout << "Введите ваш выбор (1 - камень, 2 - бумага, 3 - ножницы): ";
	cin >> userChoice;

	computerChoice = rand() % 3 + 1;

	cout << "Вы выбрали: ";
	switch (userChoice)
	{
	case 1: cout << "камень"; break;
	case 2: cout << "бумагу"; break;
	case 3: cout << "ножницы"; break;
	}

	cout << "\nКомпьютер выбрал: ";
	switch (computerChoice)
	{
	case 1: cout << "камень"; break;
	case 2: cout << "бумагу"; break;
	case 3: cout << "ножницы"; break;
	}

	// Определение победителя
	if (userChoice == computerChoice)
	{
		cout << "\nНичья!";
	}
	else if ((userChoice == 1 && computerChoice == 3) || (userChoice == 2 && computerChoice == 1) || (userChoice == 3 && computerChoice == 2))
	{
		cout << "\nВы победили!";
	}
	else
	{
		cout << "\nВы проиграли!";
	}
}

bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n % 2 == 0 && n > 2) return false;

	double sqr = sqrt(n);

	for (int i = 3; i <= sqr; i += 2)
	{
		if (n % i == 0) return false;
	}
	return true;
}

void findPrimesUpTo10_ex11()
{
	vector<int> foundPrimes;

	for (int i = 1; i <= 100; ++i)
	{
		if (isPrime(i))
		{
			foundPrimes.push_back(i);
		}
	}

	cout << "Простые число до 100: ";
	for (int pr : foundPrimes)
	{
		cout << pr << " ";
	}
}

void findPrimesUpToMax_ex12(int max)
{
	vector<int> foundPrimes;

	for (int i = 1; i <= max; ++i)
	{
		if (isPrime(i))
		{
			foundPrimes.push_back(i);
		}
	}

	cout << "Простые число до " << max << ": ";
	for (int pr : foundPrimes)
	{
		cout << pr << " ";
	}
}

/*
 "Решето Эратосфена" работает следующим образом:
	Создается список всех чисел от 2 до max.
	Начинаем с первого простого числа(2) и помечаем все его кратные числа как составные.
	Переходим к следующему непомеченному числу и повторяем процесс, пока не достигнем max.

	Заполнить массив из N элементов целыми числами подряд от 2 до N.
	Присвоить переменной p значение 2 (первого простого числа).
	Удалить из массива числа от p2 до N с шагом p. Это будут числа кратные p:

	  p^2, p^2+p, p^2+2p и т. д.

	Найти первое оставшееся в массиве число, большее p, и присвоить значению переменной p это число.
	Повторять два предыдущих шага пока это возможно.
*/


void sieveOfEratosthenes_ex13_14(int max)
{
	vector<bool> sieve(max + 1, true); // Инициализация вектора, где true означает, что число простое
	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i * i <= max; ++i)  //Перебираем числа от 2 до квадратного корня из max
	{
		if (sieve[i])  // Если число i простое
		{
			for (int j = i * i; j <= max; j += i) // Помечаем все кратные числа как составные
			{
				sieve[j] = false;
			}
		}
	}

	cout << "Простые число до " << max << ": ";
	for (int i = 2; i <= max; ++i)
	{
		if (sieve[i])
		{
			cout << i << " ";
		}
	}
}

vector<int> ex15(int n)
{
	vector<int>primes;

	if (n < 1) return primes;

	for (int i = 2; primes.size() != n; i++)
	{
		if (isPrime(i))
		{
			primes.push_back(i);
		}
	}

	return primes;
}

template <typename T> void print_vector(vector<T> v)
{
	for (auto vec : v)
	{
		cout << vec << endl;
	}
}

int ex16(vector<int> v)
{
	int max_times = 0;
	int mode = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int times = 0;
		int number = v[i];
		for (int j = 0; j < v.size(); j++)
		{
			if (number == v[j])
			{
				times++;
			}
		}
		if (times > max_times)
		{
			max_times = times;
			mode = number;
		}
	}
	return mode;
}

bool ex17(const vector<string>& v, string& mode, string& max, string& min)
{
	if (v.empty()) return false;
	int max_times = 0;
	max = *max_element(v.begin(), v.end());
	min = *min_element(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		string stroka = v[i];
		for (string str : v)
		{
			int times = count(v.begin(), v.end(), str);
			if (times > max_times)
			{
				max_times = times;
				mode = stroka;
			}
		}
	}
	return true;
}

void ex18(double a = 0, double b = 0, double c = 0)
{
	double x1, x2;
	double D = pow(b, 2) - 4 * a * c;

	if (D > 0)
	{
		x1 = (-b + sqrt(D)) / (2 * a);
		x2 = (-b - sqrt(D)) / (2 * a);

		cout << x1 << " " << x2 << endl;
	}

	if (D == 0)
	{
		x1 = -b / (2 * a);

		cout << x1 << endl;
	}

	if (D < 0)
	{
		cout << "Уравнение не имеет действительных решений" << endl;
	}
}

void find_name_ex20(vector<string>& n, vector<int>& s)
{
	string input_name;
	cout << "Введите имя: ";
	getline(cin, input_name);
	bool found = false;
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == input_name)
		{
			cout << "Имя найдено: " << input_name << ", баллы: " << s[i] << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Имя не найдено" << endl;
	}
}

void find_score_ex21(vector<string>& n, vector<int>& s)
{
	string input;
	int target_score;
	cout << "Введите количество баллов: ";
	getline(cin, input);
	istringstream os(input);
	os >> target_score;

	bool found = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == target_score)
		{
			cout << "Имя: " << n[i] << ", баллы: " << s[i] << endl;
			found = true;
			break;
		}
	}
	if (!found)
	{
		cout << "Баллы не найдены" << endl;
	}
}

void sort_names_scores(vector<string>& n, vector<int>& s)
{
	for (int i = 0; i < n.size() && i < s.size(); i++)
	{
		cout << n[i] << " " << s[i] << " " << endl;
	}
}

void ex19()
{
	pair<string, int> p;
	vector<string> names;
	vector<int> scores;
	string input;

	while (true)
	{
		cout << "Если хотите посмотреть баллы, то введите 'scores', если имя, то 'names'. Если хотите выйти из программы, то наберите NoName 0" << endl;
		cout << "Введите имя и число: ";

		getline(cin, input);

		stringstream ss(input);
		ss >> p.first >> p.second;

		if (p.first == "NoName" && p.second == 0) break;

		if (p.first == "names")
		{
			find_name_ex20(names, scores);
		}
		else if (p.first == "score")
		{
			find_score_ex21(names, scores);
		}
		else
		{
			if (find(names.begin(), names.end(), p.first) == names.end())
			{
				names.push_back(p.first);
				scores.push_back(p.second);
			}
			else
			{
				cout << "Ошибка: имя '" << p.first << "' уже было введено." << endl;
				continue;
			}
		}
	}
	sort_names_scores(names, scores);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ex19();
}