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
public:
    Date(int y, int m, int d) : y(y), m(m), d(d) {}
    int day() const { return d; }
    int month() const { return m; }
    int year() const { return y; }
private:
    int y, m, d;
};

bool ex10_leapyear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

//Класс может быть полезен для точных вычислений, где важно избежать ошибок округления, характерных для чисел с плавающей точкой.
class Rational 
{
public:
    Rational(int numerator, int denominator);
    Rational operator+(const Rational& rhs);
    Rational operator-(const Rational& rhs);
    Rational operator*(const Rational& rhs);
    Rational operator/(const Rational& rhs);
    bool operator==(const Rational& rhs);
    operator double();

private:
    int numerator;
    int denominator;
};

class Money 
{
public:
    Money(long cents); // Конструктор принимает сумму в центах
    Money operator+(const Money& rhs);
    Money operator-(const Money& rhs);
    Money operator*(double multiplier);
    friend ostream& operator<<(std::ostream& os, const Money& money);

private:
    long round(double amount);
};

void ex2_3();
void ex4();