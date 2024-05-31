#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <sstream>

using namespace std;

void ex1_5()
{
	double a = 0.0, b = 0.0;
	string input;
	double difference = 1.0 / 100;

	while (true)
	{
		cout << "\nВведите два числа. Для выхода введите символ '|'\n";
		cout << "Первое число: ";
		cin >> input;
		if (input == "|") break;
		a = stod(input);

		cout << "Второе число: ";
		cin >> input;
		if (input == "|") break;
		b = stod(input);

		cout << fixed;
		cout.precision(2);
		cout << "Вот они, числа: " << a << " и " << b << endl;

		if (a == b)
		{
			cout << "Числа равны!" << endl;
		}
		else if (abs(a - b) <= difference)
		{
			cout << "Числа почти равны" << endl;
		}
		else if (a > b)
		{
			cout << "Наименьшее значение равно: " << b << endl;
			cout << "Наибольшее значение равно: " << a << endl;
		}
		else
		{
			cout << "Наименьшее значение равно: " << a << endl;
			cout << "Наибольшее значение равно: " << b << endl;
		}
	}
}


void ex6()
{
	double a, minVal = numeric_limits<double>::infinity(), maxVal = -numeric_limits<double>::infinity();
	string input;
	while (true)
	{
		cout << "\nВведите число. Для выхода введите символ '|'\n";
		cin >> input;
		if (input == "|") break;
		a = stod(input);
		if (a < minVal)
		{
			minVal = a;
			cout << "Текущее мин. значение: " << minVal << endl;
		}
		if (a > maxVal)
		{
			maxVal = a;
			cout << "Текущее макс. значение: " << maxVal << endl;
		}
	}
}

double convertToMeters(string unit, double value)
{
	if (unit == "cm") return (value / 100.0);
	if (unit == "m") return value;
	if (unit == "in") return value * (2.54 / 100.0);
	if (unit == "ft") return value * (12 * 2.54 / 100.0);
	cout << "Неверная единица измерения!" << endl;
	return -1;
}

void ex7_11()
{
	vector<double> values;
	double a, minVal = numeric_limits<double>::infinity(), maxVal = -numeric_limits<double>::infinity();
	string input;
	double result;
	double sum = 0;
	int count = 0;
	while (true)
	{
		cout << "\nВведите число. Введите единицу измерения (cm, m, in или ft). Для выхода введите символ '|'\n";
		getline(cin, input);
		if (input == "|") break;

		stringstream ss(input);
		string unit;
		ss >> a >> unit;
		
		result = convertToMeters(unit, a);

		if (result == -1) continue; // Пропускаем неверные значения
		if (result < minVal)
		{
			minVal = result;
		}
		if (result > maxVal)
		{
			maxVal = result;
		}
		cout << "Текущее значение: " << result << endl;
		cout << "Текущее мин. значение: " << minVal << endl;
		cout << "Текущее макс. значение: " << maxVal << endl;

		values.push_back(result);
		sum += result;
		count++;
	}

	sort(values.begin(), values.end());

	cout << "Наибольшее введённое значение: " << maxVal << endl;
	cout << "Наименьшее введённое значение: " << minVal << endl;
	cout << "Сумма введенных значений: " << sum << " м" << endl;
	cout << "Количество введенных значений: " << count << endl;

	for (double value : values)
	{
		cout << value << " м" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ex7_11();
}