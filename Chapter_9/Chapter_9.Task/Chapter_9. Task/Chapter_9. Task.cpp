#include "Header.h"

void init_day(Date_9_4_1& dd, int y, int m, int d)
{
    if (!correct_date(m, d))
    {
        cerr << "Некорректная дата\n";
        return;
    }
    dd.y = y;
    dd.m = m;
    dd.d = d;
}

void add_day_9_4_1(Date_9_4_1& dd, int n)
{
    dd.d += n;
    while (dd.d > MAX_DAY)
    {
        dd.d -= MAX_DAY;
        dd.m++;
        if (dd.m > MAX_MONTH)
        {
            dd.m = MIN_MONTH_DAY;
            dd.y++;
        }
    }
}

void add_day_9_4_2(Date_9_4_2& dd, int n)
{
    dd.d += n;
    while (dd.d > MAX_DAY)
    {
        dd.d -= MAX_DAY;
        dd.m++;
        if (dd.m > MAX_MONTH)
        {
            dd.m = MIN_MONTH_DAY;
            dd.y++;
        }
    }
}

void Date_9_4_3::add_day(int n) 
{
    d += n;
    while (d > MAX_DAY)
    {
        d -= MAX_DAY;
        m++;
        if (m > MAX_MONTH)
        {
            m = MIN_MONTH_DAY;
            y++;
        }
    }
}

void Date_9_7_1::add_day(int n)
{
    d += n;
    while (d > MAX_DAY)
    {
        d -= MAX_DAY;
        m++;
        if (m > MAX_MONTH)
        {
            m = MIN_MONTH_DAY;
            y++;
        }
    }
}

void Date_9_7_4::add_day(int n)
{
    d += n;
    while (d > MAX_DAY)
    {
        d -= MAX_DAY;
        m++;
        if (m > MAX_MONTH)
        {
            m = MIN_MONTH_DAY;
            y++;
        }
    }
}

bool correct_date(int& m, int& d)
{
    if (m < MIN_MONTH_DAY || m > MAX_MONTH || d < MIN_MONTH_DAY || d > MAX_DAY)
    {
        return false;
    }
    return true;
}

Date_9_4_2::Date_9_4_2(int y, int m, int d) : y(y), m(m), d(d) 
{
    if (!correct_date(m, d)) throw invalid_argument("Некорректная дата");
}

Date_9_4_3::Date_9_4_3(int y, int m, int d) : y(y), m(m), d(d)
{
    if (!correct_date(m, d)) throw invalid_argument("Некорректная дата"); 
}

Date_9_7_1::Date_9_7_1(int y, int m, int d) : y(y), m(m), d(d)
{
    if (!correct_date(m, d)) throw invalid_argument("Некорректная дата");
}

Date_9_7_4::Date_9_7_4(int y, int m, int d) : y(y), m(m), d(d)
{
    if (!correct_date(m, d))  throw Invalid{};
}

ostream& operator<<(ostream& os, const Date_9_4_1& dd) 
{
    return os << dd.d << '.' << dd.m << '.' << dd.y;
}

ostream& operator<<(ostream& os, const Date_9_4_2& dd) 
{
    return os << dd.d << '.' << dd.m << '.' << dd.y;
}

ostream& operator<<(ostream& os, const Date_9_4_3& dd) 
{
    return os << dd.day() << '.' << dd.month() << '.' << dd.year();
}

ostream& operator<<(ostream& os, const Date_9_7_1& dd) 
{
    return os << dd.day() << '.' << dd.month() << '.' << dd.year();
}

ostream& operator<<(ostream& os, const Date_9_7_4& dd) 
{
    return os << dd.day() << '.' << dd.month() << '.' << dd.year();
}

void test_9_4_1()
{
    cout << "\nТестирование версии Date из раздела 9.4.1:\n";

    Date_9_4_1 today;
    init_day(today, 1963, 5, 19);

    Date_9_4_1 tomorrow = today;
    add_day_9_4_1(tomorrow, 1);

    cout << "Сегодня: " << today << endl;
    cout << "Завтра: " << tomorrow << endl;

    cout << "\nПроверка некорректной даты:\n";
    Date_9_4_1 invalid_date;
    init_day(invalid_date, 2009, 13, -5);
}

void test_9_4_2()
{
    cout << "\nТестирование версии Date из раздела 9.4.2:\n";

    Date_9_4_2 today(1963, 5, 19);

    Date_9_4_2 tomorrow = today;
    add_day_9_4_2(tomorrow, 1);

    cout << "Сегодня: " << today << endl;
    cout << "Завтра: " << tomorrow << endl;

    cout << "\nПроверка некорректной даты:\n";
    try 
    {
        Date_9_4_2 invalid_date(2009, 13, -5);
    }
    catch (invalid_argument& e) 
    {
        cout << e.what() << endl;
    }
}

void test_9_4_3()
{
    cout << "\nТестирование версии Date из раздела 9.4.3:\n";

    Date_9_4_3 today(1963, 5, 19);
    Date_9_4_3 tomorrow = today;
    tomorrow.add_day(1);

    cout << "Сегодня: " << today << endl;
    cout << "Завтра: " << tomorrow << endl;

    cout << "\nПроверка некорректной даты:\n";
    try
    {
        Date_9_4_3 invalid_date(2009, 13, -5);
    }
    catch (invalid_argument& e)
    {
        cout << e.what() << endl;
    }


}

void test_9_7_1()
{
    cout << "\nТестирование версии Date из раздела 9.7.1:\n";

    Date_9_7_1 today(1963, 5, 19);
    Date_9_7_1 tomorrow = today;
    tomorrow.add_day(1);

    cout << "Сегодня: " << today << endl;
    cout << "Завтра: " << tomorrow << endl;

    cout << "\nПроверка некорректной даты:\n";
    try
    {   
        Date_9_7_1 invalid_date(2009, 13, -5);
    }
    catch (invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}

void test_9_7_4()
{
    cout << "\nТестирование версии Date из раздела 9.7.4:\n";

    Date_9_7_4 today(1963, 5, 19);
    Date_9_7_4 tomorrow = today;
    tomorrow.add_day(1);

    cout << "Сегодня: " << today << endl;
    cout << "Завтра: " << tomorrow << endl;

    try 
    {
        cout << "\nПроверка некорректной даты:\n";
        Date_9_7_4 invalid_date(2009, 13, -5);
    }
    catch (Date_9_7_4::Invalid) 
    {
        cout << "Некорректная дата\n";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    test_9_7_4();
}

