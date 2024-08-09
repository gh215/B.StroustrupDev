#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Name_pairs
{
private:
	vector<string> name;
	vector<double> age;
public:
	void read_names();
	void read_ages();
	void sort();

	friend ostream& operator<<(ostream& os, const Name_pairs& np);
	bool operator==(const Name_pairs& other) const;
	bool operator!=(const Name_pairs& other) const;
};

class Date
{
private:
	int y, m, d;
public:
	Date(int y, int m, int d) : y(y), m(m), d(d) {}
	int day() const { return d; }
	int month() const { return m; }
	int year() const { return y; }

	int days_in_month(int year, int month);
	int day_of_week(int year, int month, int day);
	void add_day(int n);
	Date next_workday();
	int week_of_year();
};

class Date_ex12 
{
private:
	long days_since_epoch;	
	static const int days_per_year = 365;
	static const int days_per_leap_year = 366;

public:
	Date_ex12() : days_since_epoch(0) {}

	Date_ex12(int y, int m, int d) 
	{
		days_since_epoch = date_to_days(y, m, d);
	}

	// Преобразование даты в количество дней с 1 января 1970
	long date_to_days(int year, int month, int day);

	// Преобразование количества дней в дату
	void days_to_date(long days, int& year, int& month, int& day);

	// Получение текущего дня, месяца и года
	int days_in_month(int y, int m);

	int day() 
	{
		int year, month, day;
		days_to_date(days_since_epoch, year, month, day);
		return day;
	}

	int month() 
	{
		int year, month, day;
		days_to_date(days_since_epoch, year, month, day);
		return month;
	}

	int year() 
	{
		int year, month, day;
		days_to_date(days_since_epoch, year, month, day);
		return year;
	}
	// Добавление дней к дате
	void add_day(int n) { days_since_epoch += n; }
};

class Rational
{
private:
	int numerator;
	int denominator;
public:
	Rational(int n, int d) : numerator(n), denominator(d) {}

	Rational operator+(const Rational& other)
	{
		if (denominator == other.denominator)
		{
			return Rational(numerator + other.numerator, denominator);
		}
		else 
		{
			return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
		}
	}

	Rational operator-(const Rational& other)
	{
		if (denominator == other.denominator)
		{
			return Rational(numerator - other.numerator, denominator);
		}
		else
		{
			return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
		}
	}

	Rational operator*(const Rational& other)
	{
		return Rational(numerator * other.numerator, denominator * other.denominator);
	}

	Rational operator/(const Rational& other)
	{
		return Rational(numerator * other.denominator, denominator * other.numerator);
	}

	bool operator==(const Rational& other)
	{
		// сравниваем числители и знаменатели
		return numerator == other.numerator && denominator == other.denominator;
	}

	operator double()
	{
		return static_cast<double>(numerator) / denominator;
	}

	friend ostream& operator<<(ostream& os, const Rational& r)
	{
		os << r.numerator << "/" << r.denominator;
		return os;
	}
};

class Money
{
private:
	long cents;
	string currency;
	bool is_representable(double amount)
	{
		return round(amount * 100) == amount * 100;
	}
public:
	Money(double amount, const string& curr) : currency(curr)
	{
		if (!is_representable(amount))
		{
			throw invalid_argument("Сумма не может быть точно представлена с помощью long int центов");
		}
		cents = round(amount * 100);
	}

	Money(long c, const string& curr) : cents(c), currency(curr) {}

	double to_dollars() const { return cents / 100.0; }

	Money operator+(const Money& other)
	{
		if (currency != other.currency)
		{
			throw invalid_argument("Невозможно прибавить деньги в разных валютах без таблицы конвертации");
		}
		return Money(cents + other.cents, currency);
	}

	Money operator-(const Money& other)
	{
		if (currency != other.currency)
		{
			throw invalid_argument("Невозможно вычесть деньги в разных валютах без таблицы конвертации");
		}
		return Money(cents - other.cents, currency);
	}

	bool operator==(const Money& other)
	{
		return cents == other.cents && currency == other.currency;
	}

	friend istream& operator>>(istream& is, Money& m)
	{
		string input;
		is >> input;

		string curr = input.substr(0, 3);  // первые три символа - валюта
		double amount = stod(input.substr(3));  // остальное - сумма

		m = Money(amount, curr);
		return is;
	}

	friend ostream& operator<<(ostream& os, const Money& m)
	{
		os << m.currency << m.to_dollars();
		return os;
	}
};

void ex2_3();
void ex4();
bool ex10_leapyear(int y);
void ex11();
void ex12();
void ex13();
void ex14_15();
void ex16();
void ex17();
void ex18();


