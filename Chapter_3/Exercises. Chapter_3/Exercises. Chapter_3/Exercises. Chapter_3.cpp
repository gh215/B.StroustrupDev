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
	cout << "������� ���������� ����������, ������� �� ������ ��������� � �����: ";
	cin >> miles;
	kilometrs = miles * km_per_mile;
	cout << "����� ����: " << miles << endl;
}

void calc()
{
	int val1, val2;
	int addition;
	int difference;
	int multiplication;
	int division;
	cout << "\t������� ��� �����";
	cout << "\n������� ������ �����: ";
	cin >> val1;
	cout << "\n������� ������ �����: ";
	cin >> val2;

	if (val1 > val2)
	{
		cout << "��������� ����� : " << val1 << endl;
		cout << "���������� ����� : " << val2 << endl;
	}
	else if (val1 == val2)
	{
		cout << "����� �����!" << endl;
	}
	else
	{
		cout << "��������� ����� : " << val2 << endl;
		cout << "���������� ����� : " << val1 << endl;
	}

	addition = val1 + val2;
	difference = val1 - val2;
	multiplication = val1 * val2;
	if (val2 == 0)
	{
		cout << "������, ������ ������ �� 0" << endl;
		return;
	}
	else
	{
		division = val1 / val2;
	}

	cout << "\n��������: " << addition << "\n���������: " << difference <<
		"\n���������: " << multiplication << "\n�������: " << division;
}

void calc_d()
{
	double val1, val2;
	double addition;
	double difference;
	double multiplication;
	double division;
	cout << "\t������� ��� �����";
	cout << "\n������� ������ �����: ";
	cin >> val1;
	cout << "\n������� ������ �����: ";
	cin >> val2;

	if (val1 > val2)
	{
		cout << "��������� ����� : " << val1 << endl;
		cout << "���������� ����� : " << val2 << endl;
	}
	else if (val1 == val2)
	{
		cout << "����� �����!" << endl;
	}
	else
	{
		cout << "��������� ����� : " << val2 << endl;
		cout << "���������� ����� : " << val1 << endl;
	}

	addition = val1 + val2;
	difference = val1 - val2;
	multiplication = val1 * val2;
	if (val2 == 0)
	{
		cout << "������, ������ ������ �� 0" << endl;
		return;
	}
	else
	{
		division = val1 / val2;
	}

	cout << "\n��������: " << addition << "\n���������: " << difference <<
		"\n���������: " << multiplication << "\n�������: " << division;
}

void in_order_numbers()
{
	int numbers[3];
	cout << "������� ��� ����� �����: ";
	for (int i = 0; i < 3; ++i) 
	{
		cin >> numbers[i];
	}

	sort(numbers, numbers + 3);
	cout << "����� � ������� �����������: ";
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
	cout << "������� ��� �����: ";
	for (int i = 0; i < 3; ++i)
	{
		cin >> names[i];
	}

	sort(names, names + 3);
	cout << "����� � ������� �����������: ";
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
	cout << "������� ����� �����: ";
	cin >> number;

	if (number % 2 == 0)
	{
		cout << "����� " << number << " �������� ������." << endl;
	}
	else
	{
		cout << "����� " << number << " �������� ��������." << endl;
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

	cout << "������� ����� � ���� �����: ";
	cin >> word;
	if (dic.count(word) != 1)
	{
		cout << "� �� ���� ������ �����" << endl;
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

	cout << "������� �������� (+, -, *, /,): ";
	cin >> operation;

	cout << "������� ������ �������: ";
	cin >> operand1;

	cout << "������� ������ �������: ";
	cin >> operand2;

	if (operation == "+") 
	{
		cout << "���������: " << operand1 + operand2 << endl;
	}
	else if (operation == "-") 
	{
		cout << "���������: " << operand1 - operand2 << endl;
	}
	else if (operation == "*") 
	{
		cout << "���������: " << operand1 * operand2 << endl;
	}
	else if (operation == "/") 
	{
		if (operand2 != 0) 
		{
			cout << "���������: " << operand1 / operand2 << endl;
		}
		cout << "������: ������� �� ����" << endl;

	}
	else
	{
		cout << "����������� ��������" << endl;
	}
}

int how_much_money(string kind)
{
	int coins;
	cout << "������� � ��� " << kind <<  " ����� ? ";
	cin >> coins;
	return coins;
}

void cents()
{
	int oneCent = 0, fiveCents = 0, tenCents = 0, twentyFiveCents = 0, fiftyCents = 0, dollarCents = 0;
	int totalCents = 0;

	oneCent = how_much_money("������������");
	totalCents += oneCent;

	fiveCents = how_much_money("������������");
	totalCents += fiveCents * 5;

	tenCents = how_much_money("��������������");
	totalCents += tenCents * 10;

	twentyFiveCents = how_much_money("��������������������");
	totalCents += twentyFiveCents * 25;

	fiftyCents = how_much_money("������������������");
	totalCents += fiftyCents * 50;

	dollarCents = how_much_money("����������");
	totalCents += dollarCents * 100;

	if (oneCent == 1)
	{
		cout << "� ��� " << oneCent << " ������������ ������." << endl;
	}
	else
	{
		cout << "� ��� " << oneCent << " ������������ �����." << endl;
	}
	if (fiveCents == 1)
	{
		cout << "� ��� " << fiveCents << " ������������ ������." << endl;
	}
	else
	{
		cout << "� ��� " << fiveCents << " ������������ �����." << endl;
	}
	if (tenCents == 1)
	{
		cout << "� ��� " << tenCents << " �������������� ������." << endl;
	}
	else
	{
		cout << "� ��� " << tenCents << " �������������� �����." << endl;
	}
	if (twentyFiveCents == 1)
	{
		cout << "� ��� " << twentyFiveCents << " �������������������� ������." << endl;
	}
	else
	{
		cout << "� ��� " << twentyFiveCents << " �������������������� �����." << endl;
	}
	if (fiftyCents == 1)
	{
		cout << "� ��� " << fiftyCents << " ������������������ ������." << endl;
	}
	else
	{
		cout << "� ��� " << fiftyCents << " ������������������ �����." << endl;
	}
	if (dollarCents == 1)
	{
		cout << "� ��� " << dollarCents << " ���������� ������." << endl;
	}
	else
	{
		cout << "� ��� " << dollarCents << " ���������� �����." << endl;
	}

	int dollars = totalCents / 100;
	int cents = totalCents % 100;

	cout << "����� ��������� ����� ����� ����� " << dollars << " �������� " << cents << " �����." << endl;
}



int main()
{
	setlocale(LC_ALL, "Russian");
	//�������� ���������� �������� �����
	cents();
}
