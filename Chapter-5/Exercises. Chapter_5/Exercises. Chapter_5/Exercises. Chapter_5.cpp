#include <iostream>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include "..\std_lib_facilities.h"
#include <map>

using namespace std;

const double ABS_ZERO_CELS = -273.15;
const double ABS_ZERO_KELV = 0;
const double ABS_ZERO_FAHREN = -459.76;

double ex4_ctok(double c)
{
	double FROM_CELS_TO_KELV = c - ABS_ZERO_CELS;
	if (FROM_CELS_TO_KELV < ABS_ZERO_KELV)
	{
		cout << "Ошибка! Температура не можеть быть меньше " << ABS_ZERO_KELV << " Кельвина!" << endl;
	}
	else
	{
		cout << "Результат перевода из Цельсия в Кельвина: " << FROM_CELS_TO_KELV << endl;

	}
	return FROM_CELS_TO_KELV;
}

double ex5_ktoc(double k)
{
	double FROM_KELV_TO_CELS = k + ABS_ZERO_CELS;
	if (FROM_KELV_TO_CELS < ABS_ZERO_CELS)
	{
		cout << "Ошибка! Температура не можеть быть меньше " << ABS_ZERO_CELS << " Цельсия!" << endl;
	}
	else
	{
		cout << "Результат перевода из Кельвина в Цельсия: " << FROM_KELV_TO_CELS << endl;

	}
	return FROM_KELV_TO_CELS;
}

double ex6_ctof(double c)
{
	double FROM_CELS_TO_FAHREN = (9 / 5) * c + 32;
	if (FROM_CELS_TO_FAHREN < ABS_ZERO_FAHREN)
	{
		cout << "Ошибка! Температура не можеть быть меньше " << ABS_ZERO_FAHREN << " Кельвина!" << endl;
	}
	else
	{
		cout << "Результат перевода из Цельсия в Фаренгейта: " << FROM_CELS_TO_FAHREN << endl;
	}
	return FROM_CELS_TO_FAHREN;
}

double ex6_ftoc(double f)
{
	double FROM_FAHREN_TO_CELS = (f - 32) * 5 / 9;
	if (FROM_FAHREN_TO_CELS < ABS_ZERO_CELS)
	{
		cout << "Ошибка! Температура не можеть быть меньше " << ABS_ZERO_CELS << " Цельсия!" << endl;
	}
	else
	{
		cout << "Результат перевода из Фаренгейта в Цельсия: " << FROM_FAHREN_TO_CELS << endl;

	}
	return FROM_FAHREN_TO_CELS;
}

int ex7_func(int a, int b, int c)
{
	double x1, x2;
	double D = pow(b, 2) - (4 * a * c);

	if (D > 0)
	{
		x1 = (-b - sqrt(D)) / 2 * a;
		x2 = (-b + sqrt(D)) / 2 * a;
		cout << "x1: " << x1 << endl << "x2: " << x2 << endl;
		return x1, x2;
	}
	if (D == 0)
	{
		x1 = -b / (2 * a);
		return x1;
	}
	else
	{
		cout << "Нет корней!" << endl;
		return 0;
	}
}

vector<int> ex8_readNumbers()
{
	vector<int> numbers;
	string input;
	int number;

	cout << "Введите несколько целых чисел (| для окончания ввода): ";
	while (true)
	{
		cin >> input;
		if (input == "|")
		{
			break;
		}

		if (input.find('.') != string::npos)
		{
			cout << "Нельзя вводить значения типа double. Введите другое число." << endl;
			continue;
		}

		stringstream iss(input);
		iss >> number;
		numbers.push_back(number);
	}

	return numbers;
}

int ex8_sumFirstNumbers(const vector<int>& num, int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += num[i];
	}
	return sum;
}

vector<double> ex10_readNumbers()
{
	vector<double> numbers;
	string input;
	double number;

	cout << "Введите несколько целых чисел (| для окончания ввода): ";
	while (true)
	{
		cin >> input;
		if (input == "|")
		{
			break;
		}

		stringstream iss(input);
		while (iss >> number)
		{
			numbers.push_back(number);
		}
	}

	return numbers;
}

vector<double> ex10_calculateDifferences(const vector<double>& numbers)
{
	vector<double> differences;
	for (int i = 1; i < numbers.size(); ++i)
	{
		//тут вычисляется разность между текущем элементом numbers[i] и предыдущим numbers[i - 1];
		differences.push_back(numbers[i] - numbers[i - 1]);
	}
	return differences;
}


double ex10_sumFirstNumbers(const vector<double>& num, int n)
{
	double sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += num[i];
	}
	return sum;
}

void countBullsAndCows(const vector<int>& secret, const vector<int>& guess, int& bulls, int& cows)
{
	bulls = 0;
	cows = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (secret[i] == guess[i])
		{
			++bulls;
		}
		else
		{
			for (int j = 0; j < 4; ++j)
			{
				if (secret[i] == guess[j])
				{
					++cows;
					break;
				}
			}
		}
	}
}

void playGame_ex12(const vector<int> secret, int attempts)
{
	while (true)
	{
		cout << "Введите ваше предположение (четырехзначное число): ";
		vector<int> guess(4);
		for (int i = 0; i < 4; ++i)
		{
			cin >> guess[i];
		}

		int bulls = 0, cows = 0;
		countBullsAndCows(secret, guess, bulls, cows);

		cout << "Быки: " << bulls << ", Коровы: " << cows << endl;
		++attempts;

		if (bulls == 4)
		{
			cout << "Поздравляем Вы угадали число за " << attempts << " попыток." << endl;
			break;
		}
	}
}

void playGame_ex13(int num1, int num2, int num3, int num4)
{
	char playAgain = 'y';
	while (playAgain == 'y')
	{
		vector<int> secret({ num1, num2, num3, num4 });
		int attempts = 0;

		cout << "Введите ваше предположение (четырехзначное число): ";
		vector<int> guess(4);
		for (int i = 0; i < 4; ++i)
		{
			cin >> guess[i];
		}

		int bulls = 0, cows = 0;
		countBullsAndCows(secret, guess, bulls, cows);

		cout << "Быки: " << bulls << ", Коровы: " << cows << endl;
		++attempts;

		if (bulls == 4)
		{
			cout << "Поздравляем Вы угадали число за " << attempts << " попыток." << endl;
			cout << "Хотите сыграть еще раз? (y/n): ";
			cin >> playAgain;

			while (playAgain != 'y' && playAgain != 'n')
			{
				cout << "Неверно введённое значение. Попробуйте ещё раз!" << endl;
				continue;
			}
			
		}
	}
}

vector<int> generateNumber()
{
	vector<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	random_shuffle(digits.begin(), digits.end());
	return vector<int>(digits.begin(), digits.begin() + 4);
}

void ex2()
{
	double c = 0;
	cout << "Введите градусы Цельсия: ";
	cin >> c;
	double k = ex4_ctok(c);
}

void ex3()
{
	double c = 0;
	cout << "Введите градусы Цельсия: ";
	cin >> c;
	double k = ex4_ctok(c);
}

void ex5()
{
	double k = 0;
	cout << "Введите градусы Кельвина: ";
	cin >> k;
	double c = ex5_ktoc(k);
}

void ex6()
{
	char choice;
	cout << "Выберите, что вы хотитите изменить. Из C в F - введите c, если F в C - f: ";
	cin >> choice;
	choice = tolower(choice);
	if (choice == 'c')
	{
		double c = 0;
		cout << "Введите градусы Цельсия: ";
		cin >> c;
		double f = ex6_ctof(c);
	}
	else if (choice == 'f')
	{
		double f = 0;
		cout << "Введите градусы Цельсия: ";
		cin >> f;
		double c = ex6_ftoc(f);
	}
	else
	{
		cout << "Неправильно вводимое значение" << endl;
	}
}

void ex7()
{
	int a = 0;
	int b = 0;
	int c = 0;

	cout << "Для решения квадратного уравнения введите:" << endl;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите c: ";
	cin >> c;
	double func = ex7_func(a, b, c);
}

void ex8_9()
{
	vector<int> total_numbers = ex8_readNumbers();
	int sum_numbers;

	cout << "Введите количество суммируемых значений: ";
	do
	{
		cin >> sum_numbers;
		if (sum_numbers > total_numbers.size())
		{
			cout << "Количество запрашиваемых чисел для суммы больше, чем вы задали.";
			cout << "Попробуйте ещё раз : " << endl;
		}
	} while (sum_numbers > total_numbers.size());

	int sum = ex8_sumFirstNumbers(total_numbers, sum_numbers);

	cout << "Сумма первых " << sum_numbers << " чисел (";

	for (unsigned int i = 0; i < sum_numbers; ++i)
	{
		cout << total_numbers[i] << " ";
	}
	cout << ") равна " << sum << "." << endl;

}

void ex10()
{
	vector<double> total_numbers = ex10_readNumbers();
	int sum_numbers;

	cout << "Введите количество суммируемых значений: ";
	do
	{
		cin >> sum_numbers;
		if (sum_numbers > total_numbers.size())
		{
			cout << "Количество запрашиваемых чисел для суммы больше, чем вы задали.";
			cout << "Попробуйте ещё раз : " << endl;
		}
	} while (sum_numbers > total_numbers.size());

	double sum = ex10_sumFirstNumbers(total_numbers, sum_numbers);

	cout << "Сумма первых " << sum_numbers << " чисел (";

	for (int i = 0; i < sum_numbers; ++i)
	{
		cout << total_numbers[i] << " ";
	}
	cout << ") равна " << sum << "." << endl;

	vector<double> differences = ex10_calculateDifferences(total_numbers);
	cout << "Разности между соседними числами: ";
	for (double diff : differences)
	{
		cout << diff << " ";
	}
}


void ex11()
{
	long long a = 0;
	long long b = 1;
	long long next_number = 0;

	cout << numeric_limits<long long>::max() << endl;

	while (true)
	{
		//исправить условие
		if (next_number > numeric_limits<long long>::max() - b)
		{
			break;
		}
		next_number = a + b;
		a = b;
		b = next_number;
	}
	cout << "Макс. возможное значение числа: " << next_number << endl;
}

void ex12()
{
	srand(static_cast<unsigned int>(time(0)));
	vector<int> secret = generateNumber();
	int attempts = 0;

	playGame_ex12(secret, attempts);
}


void ex13()
{
	cout << "Введите начальное значение для генерации случайных чисел: ";
	int seed;
	cin >> seed;
	seed_randint(time(0));

	int num1 = randint(10);
	int num2 = randint(10);
	int num3 = randint(10);
	int num4 = randint(10);

	playGame_ex13(num1, num2, num3, num4);
}


bool equal(string e, string c)
{
	// Преобраджение строк к нижнему регистру
	transform(e.begin(), e.end(), e.begin(), ::tolower);
	transform(c.begin(), c.end(), c.begin(), ::tolower);

	// Сначала проверяем полное совпадение строк
	if (e == c) return true;

	// Смотрим, соответсвует ли строка одному из сокращений из 3х символов
	if (e.substr(0, 3) == c) return true;

	return false;
}

void enterValue_ex14(const vector<string>& daysOfWeek, int& rejectedCount, vector<int>& weekSums)
{
	string inputDay;
	int inputValue;

	while (cin >> inputDay >> inputValue)
	{
		bool validDay = false;

		if (inputDay == "e")
		{
			break;
		}

		for (int i = 0; i < daysOfWeek.size(); ++i)
		{
			if (equal(daysOfWeek[i], inputDay))
			{
				weekSums[i] += inputValue;
				validDay = true;
				break;
			}
		}
		if (!validDay)
		{
			rejectedCount++;
		}
	}

	cout << "Сумма значений для каждого дня недели:" << endl;
	for (int i = 0; i < daysOfWeek.size(); ++i)
	{
		cout << daysOfWeek[i] << ": " << weekSums[i] << endl;
	}

	cout << "Количество отвергнутых чисел: " << rejectedCount << endl;
}

void ex14()
{
	vector<string> daysOfWeek = { "monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday" };
	// Вектор для хранения сумм значений для каждого дня недели
	vector<int> weekSums(7, 0);
	int rejectedCount = 0;

	cout << "Введите пары (день недели, значение) или 'e', чтобы закончить ввод:" << endl;

	enterValue_ex14(daysOfWeek, rejectedCount, weekSums);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ex14();
}

