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
		cout << "\n������� ��� �����. ��� ������ ������� ������ '|'\n";
		cout << "������ �����: ";
		cin >> input;
		if (input == "|") break;
		a = stod(input);

		cout << "������ �����: ";
		cin >> input;
		if (input == "|") break;
		b = stod(input);

		cout << fixed;
		cout.precision(2);
		cout << "��� ���, �����: " << a << " � " << b << endl;

		if (a == b)
		{
			cout << "����� �����!" << endl;
		}
		else if (abs(a - b) <= difference)
		{
			cout << "����� ����� �����" << endl;
		}
		else if (a > b)
		{
			cout << "���������� �������� �����: " << b << endl;
			cout << "���������� �������� �����: " << a << endl;
		}
		else
		{
			cout << "���������� �������� �����: " << a << endl;
			cout << "���������� �������� �����: " << b << endl;
		}
	}
}


void ex6()
{
	double a, minVal = numeric_limits<double>::infinity(), maxVal = -numeric_limits<double>::infinity();
	string input;
	while (true)
	{
		cout << "\n������� �����. ��� ������ ������� ������ '|'\n";
		cin >> input;
		if (input == "|") break;
		a = stod(input);
		if (a < minVal)
		{
			minVal = a;
			cout << "������� ���. ��������: " << minVal << endl;
		}
		if (a > maxVal)
		{
			maxVal = a;
			cout << "������� ����. ��������: " << maxVal << endl;
		}
	}
}

double convertToMeters(string unit, double value)
{
	if (unit == "cm") return (value / 100.0);
	if (unit == "m") return value;
	if (unit == "in") return value * (2.54 / 100.0);
	if (unit == "ft") return value * (12 * 2.54 / 100.0);
	cout << "�������� ������� ���������!" << endl;
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
		cout << "\n������� �����. ������� ������� ��������� (cm, m, in ��� ft). ��� ������ ������� ������ '|'\n";
		getline(cin, input);
		if (input == "|") break;

		stringstream ss(input);
		string unit;
		ss >> a >> unit;
		
		result = convertToMeters(unit, a);

		if (result == -1) continue; // ���������� �������� ��������
		if (result < minVal)
		{
			minVal = result;
		}
		if (result > maxVal)
		{
			maxVal = result;
		}
		cout << "������� ��������: " << result << endl;
		cout << "������� ���. ��������: " << minVal << endl;
		cout << "������� ����. ��������: " << maxVal << endl;

		values.push_back(result);
		sum += result;
		count++;
	}

	sort(values.begin(), values.end());

	cout << "���������� �������� ��������: " << maxVal << endl;
	cout << "���������� �������� ��������: " << minVal << endl;
	cout << "����� ��������� ��������: " << sum << " �" << endl;
	cout << "���������� ��������� ��������: " << count << endl;

	for (double value : values)
	{
		cout << value << " �" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ex7_11();
}