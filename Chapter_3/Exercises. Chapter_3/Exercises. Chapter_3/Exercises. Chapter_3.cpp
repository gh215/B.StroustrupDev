#include <iostream>
#include <algorithm>
#include <string>
#include "..\Include\std_lib_facilities.h"

using namespace std;

void miles_to_km()
{
	double miles_to_kilometrs = 0;
	cout << "Введите количество километров, которые вы хотите перевести в метры: ";
	cin >> miles_to_kilometrs;
	miles_to_kilometrs *= 1.609;
	cout << "Итого миль: " << miles_to_kilometrs << endl;
}

void calc()
{
	int val1, val2;
	int min = 0;
	int max = 0;
	int addition;
	int difference;
	int multiplication;
	int division;
	cout << "\tВведите два числа";
	cout << "\nВведите первое число: ";
	cin >> val1;
	cout << "\nВведите второе число: ";
	cin >> val2;

	if (val1 > val2)
	{
		cout << "Наибольше число : " << val1 << endl;
		cout << "Наименьшее число : " << val2 << endl;
	}
	else
	{
		cout << "Наибольше число : " << val2 << endl;
		cout << "Наименьшее число : " << val1 << endl;
	}

	addition = val1 + val2;
	difference = val1 - val2;
	multiplication = val1 * val2;
	division = val1 / val2;

	cout << "\nСложение: " << addition << "\nВычитание: " << difference <<
		"\nУмножение: " << multiplication << "\nДеление: " << division;
}

void in_order_numbers()
{
	int numbers[3];
	cout << "Введите три целых числа: ";
	for (int i = 0; i < 3; ++i) 
	{
		cin >> numbers[i];
	}

	sort(numbers, numbers + 3);
	cout << "Числа в порядке возрастания: ";
	for (int i = 0; i < 3; ++i) 
	{
		cout << numbers[i] << ", ";
	}
	cout << endl;
}

void in_order_names()
{
	string names[3];
	cout << "Введите три имени: ";
	for (int i = 0; i < 3; ++i)
	{
		cin >> names[i];
	}

	sort(names, names + 3);
	cout << "Числа в порядке возрастания: ";
	for (int i = 0; i < 3; ++i)
	{
		cout << names[i] << ", ";
	}
	cout << endl;
}

void parity_of_numbers()
{
	int number;
	cout << "Введите целое число: ";
	cin >> number;

	if (number % 2 == 0)
	{
		cout << "Число " << number << " является четным." << endl;
	}
	cout << "Число " << number << " является нечетным." << endl;
}

void wordToNumber()
{
	string word;
	cout << "Введите число в виде слова: ";
	cin >> word;

	if (word == "zero")
	{
		cout << "Ваше число равно 0" << endl;
	}
	else if (word == "one")
	{
		cout << "Ваше число равно 1" << endl;
	}
	else if (word == "two")
	{
		cout << "Ваше число равно 2" << endl;
	}
	else if (word == "three")
	{
		cout << "Ваше число равно 3" << endl;
	}
	else if (word == "four")
	{
		cout << "Ваше число равно 4" << endl;
	}
	else
	{
		cout << "Я глупый компьютер Я не знаю такого числа!" << endl;
	}
}

void perf_arithm_oper()
{
	string operation;
	double operand1, operand2;

	cout << "Введите операцию (+, -, *, /,): ";
	cin >> operation;

	cout << "Введите первый операнд: ";
	cin >> operand1;

	cout << "Введите второй операнд: ";
	cin >> operand2;

	if (operation == "+") 
	{
		cout << "Результат: " << operand1 + operand2 << endl;
	}
	else if (operation == "-") 
	{
		cout << "Результат: " << operand1 - operand2 << endl;
	}
	else if (operation == "*") 
	{
		cout << "Результат: " << operand1 * operand2 << endl;
	}
	else if (operation == "/") 
	{
		if (operand2 != 0) 
		{
			cout << "Результат: " << operand1 / operand2 << endl;
		}
		cout << "Ошибка: деление на ноль" << endl;

	}
	else
	{
		cout << "Неизвестная операция" << endl;
	}
}

void cents()
{
	int oneCent = 0, fiveCents = 0, tenCents = 0, twentyFiveCents = 0, fiftyCents = 0;
	int totalCents = 0;

	cout << "Сколько у вас одноцентовых монет? ";
	cin >> oneCent;
	totalCents += oneCent;

	cout << "Сколько у вас пятицентовых монет? ";
	cin >> fiveCents;
	totalCents += fiveCents * 5;

	cout << "Сколько у вас десятицентовых монет? ";
	cin >> tenCents;
	totalCents += tenCents * 10;

	cout << "Сколько у вас двадцатипятицентовых монет? ";
	cin >> twentyFiveCents;
	totalCents += twentyFiveCents * 25;

	cout << "Сколько у вас пятидесятицентовых монет? ";
	cin >> fiftyCents;
	totalCents += fiftyCents * 50;

	cout << "У вас " << oneCent << " одноцентовых монет." << std::endl;
	cout << "У вас " << fiveCents << " пятицентовых монет." << std::endl;
	cout << "У вас " << tenCents << " десятицентовых монет." << std::endl;
	cout << "У вас " << twentyFiveCents << " двадцатипятицентовых монет." << std::endl;
	cout << "У вас " << fiftyCents << " пятидесятицентовых монет." << std::endl;

	int dollars = totalCents / 100;
	int cents = totalCents % 100;

	cout << "Общая стоимость ваших монет равна " << dollars << " долларов " << cents << " цента." << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
}
