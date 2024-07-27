#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include "..\Include\std_lib_facilities.h"

using namespace std;

void miles_to_km()
{
	const double km_per_mile = 1.609;
	double miles = 0;
	double kilometrs = 0;
	cout << "Введите количество километров, которые вы хотите перевести в метры: ";
	cin >> miles;
	kilometrs = miles * km_per_mile;
	cout << "Итого миль: " << miles << endl;
}

void calc()
{
	int val1, val2;
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
	else if (val1 == val2)
	{
		cout << "Числа равны!" << endl;
	}
	else
	{
		cout << "Наибольше число : " << val2 << endl;
		cout << "Наименьшее число : " << val1 << endl;
	}

	addition = val1 + val2;
	difference = val1 - val2;
	multiplication = val1 * val2;
	if (val2 == 0)
	{
		cout << "Ошибка, нельзя делить на 0" << endl;
		return;
	}
	else
	{
		division = val1 / val2;
	}

	cout << "\nСложение: " << addition << "\nВычитание: " << difference <<
		"\nУмножение: " << multiplication << "\nДеление: " << division;
}

void calc_d()
{
	double val1, val2;
	double addition;
	double difference;
	double multiplication;
	double division;
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
	else if (val1 == val2)
	{
		cout << "Числа равны!" << endl;
	}
	else
	{
		cout << "Наибольше число : " << val2 << endl;
		cout << "Наименьшее число : " << val1 << endl;
	}

	addition = val1 + val2;
	difference = val1 - val2;
	multiplication = val1 * val2;
	if (val2 == 0)
	{
		cout << "Ошибка, нельзя делить на 0" << endl;
		return;
	}
	else
	{
		division = val1 / val2;
	}

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
	string sep;
	for (int i = 0; i < 3; ++i) 
	{
		cout << sep << numbers[i];
		sep = ", ";
	}
	
	cout << endl;
}

void in_order_names()
{
	string names[3];
	string sep;
	cout << "Введите три имени: ";
	for (int i = 0; i < 3; ++i)
	{
		cin >> names[i];
	}

	sort(names, names + 3);
	cout << "Числа в порядке возрастания: ";
	for (int i = 0; i < 3; ++i)
	{
		cout << sep << names[i];
		sep = ", ";
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
	else
	{
		cout << "Число " << number << " является нечетным." << endl;
	}

}

void wordToNumber()
{
	string word;
	map<string, int> dic
	{
		{"zero", 0},
		{"one", 1},
		{"two", 2},
		{"three", 3},
		{"four", 4},
		{"five", 5},
		{"six", 6},
		{"seven", 7},
		{"eight", 8},
		{"nine", 9}
	};

	cout << "Введите число в виде слова: ";
	cin >> word;
	if (dic.count(word) != 1)
	{
		cout << "Я не знаю такого числа" << endl;
	}
	else
	{
		cout << dic[word] << endl;
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

int how_much_money(string kind)
{
	int coins;
	cout << "Сколько у вас " << kind <<  " монет ? ";
	cin >> coins;
	return coins;
}

void cents()
{
	int oneCent = 0, fiveCents = 0, tenCents = 0, twentyFiveCents = 0, fiftyCents = 0, dollarCents = 0;
	int totalCents = 0;

	oneCent = how_much_money("одноцентовых");
	totalCents += oneCent;

	fiveCents = how_much_money("пятицентовых");
	totalCents += fiveCents * 5;

	tenCents = how_much_money("десятицентовых");
	totalCents += tenCents * 10;

	twentyFiveCents = how_much_money("двадцатипятицентовых");
	totalCents += twentyFiveCents * 25;

	fiftyCents = how_much_money("пятидесятицентовых");
	totalCents += fiftyCents * 50;

	dollarCents = how_much_money("долларовых");
	totalCents += dollarCents * 100;

	if (oneCent == 1)
	{
		cout << "У вас " << oneCent << " одноцентовая монета." << endl;
	}
	else
	{
		cout << "У вас " << oneCent << " одноцентовых монет." << endl;
	}
	if (fiveCents == 1)
	{
		cout << "У вас " << fiveCents << " пятицентовая монета." << endl;
	}
	else
	{
		cout << "У вас " << fiveCents << " пятицентовых монет." << endl;
	}
	if (tenCents == 1)
	{
		cout << "У вас " << tenCents << " десятицентовая монета." << endl;
	}
	else
	{
		cout << "У вас " << tenCents << " десятицентовых монет." << endl;
	}
	if (twentyFiveCents == 1)
	{
		cout << "У вас " << twentyFiveCents << " двадцатипятицентовая монета." << endl;
	}
	else
	{
		cout << "У вас " << twentyFiveCents << " двадцатипятицентовых монет." << endl;
	}
	if (fiftyCents == 1)
	{
		cout << "У вас " << fiftyCents << " пятидесятицентовая монета." << endl;
	}
	else
	{
		cout << "У вас " << fiftyCents << " пятидесятицентовых монет." << endl;
	}
	if (dollarCents == 1)
	{
		cout << "У вас " << dollarCents << " долларовая монета." << endl;
	}
	else
	{
		cout << "У вас " << dollarCents << " долларовых монет." << endl;
	}

	int dollars = totalCents / 100;
	int cents = totalCents % 100;

	cout << "Общая стоимость ваших монет равна " << dollars << " долларов " << cents << " цента." << endl;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	//Проверка сохранения русского языка
	cents();
}
