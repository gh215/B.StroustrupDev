#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

const int MIN_MONTH_DAY = 1;
const int MAX_MONTH = 12;
const int MAX_DAY = 31;

struct Date_9_4_1 
{
    int y, m, d;
};

bool correct_date(int& m, int& d);
void init_day(Date_9_4_1& dd, int y, int m, int d);

struct Date_9_4_2 
{
    int y, m, d;
    Date_9_4_2(int y, int m, int d);
};

void add_day_9_4_1(Date_9_4_1& dd, int n);
void add_day_9_4_2(Date_9_4_2& dd, int n);

class Date_9_4_3 
{
public:
    Date_9_4_3(int y, int m, int d);
    int day() const { return d; }
    int month() const { return m; }
    int year() const { return y; }
    void add_day(int n);
private:
    int y, m, d;
};

class Date_9_7_1 
{
public:
    Date_9_7_1(int y, int m, int d);
    int day() const { return d; }
    int month() const { return m; }
    int year() const { return y; }
    void add_day(int n);
private:
    int y, m, d;
};

class Date_9_7_4 
{
public:
    class Invalid {};
    Date_9_7_4(int y, int m, int d);
    int day() const { return d; }
    int month() const { return m; }
    int year() const { return y; }
    void add_day(int n);
private:
    int y, m, d;
};

ostream& operator<<(ostream& os, const Date_9_4_1& dd);
ostream& operator<<(ostream& os, const Date_9_4_2& dd);
ostream& operator<<(ostream& os, const Date_9_4_3& dd);
ostream& operator<<(ostream& os, const Date_9_7_1& dd);
ostream& operator<<(ostream& os, const Date_9_7_4& dd);