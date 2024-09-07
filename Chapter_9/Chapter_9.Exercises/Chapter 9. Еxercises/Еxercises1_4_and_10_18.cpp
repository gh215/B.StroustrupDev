#include "Header_ex1_4_and_10_18.h"

void Name_pairs::read_names()
{
    string input;
    cout << "Введите имена (для завершения введите '|'): " << endl;
    while (true)
    {
        cin >> input;
        if (input == "|") break;
        name.push_back(input);
    }
}
void Name_pairs::read_ages()
{
    for (int i = 0; i < name.size(); ++i)
    {
        double a;
        cout << "Введите возраст для " << name[i] << ": ";
        cin >> a;
        age.push_back(a);
    }
}

ostream& operator<<(ostream& os, const Name_pairs& np)
{
    for (size_t i = 0; i < np.name.size(); ++i)
    {
        os << np.name[i] << " " << np.age[i] << endl;
    }
    return os;
}

bool Name_pairs::operator==(const Name_pairs& other) const
{
    return (name == other.name && age == other.age);
}

bool Name_pairs::operator!=(const Name_pairs& other) const
{
    return !(*this == other);
}


void Name_pairs::sort()
{
    for (size_t i = 0; i < name.size() - 1; ++i)
    {
        for (size_t j = 0; j < name.size() - i - 1; ++j)
        {
            if (name[j] > name[j + 1])
            {
                string temp_name = name[j];
                double temp_age = age[j];
                name[j] = name[j + 1];
                age[j] = age[j + 1];
                name[j + 1] = temp_name;
                age[j + 1] = temp_age;
            }
        }
    }
}


void ex1()
{
    /*
    Включить
    Выключить
    Установить уровень прожарки хлеба
    Вставить хлеб
    Извлечь хлеб
    Начать прожаривание
    Остановить прожаривание
    Проверить готовность
    */
}

void ex2_3() 
{
    Name_pairs np;
    np.read_names();
    np.read_ages();
    cout << "Исходный список:\n";
    cout << np;
    np.sort();
    cout << "Отсортированный список:\n";
    cout << np;;
}

void ex4()
{
    struct X
    {
        void f(int x)
        {
            struct Y
            {
                int f() { return 1; }
                int m;
            };
            int m;
            m = x;
            Y m2;
            return f(m2.f());
        }
        int m = 0;
        void g(int m)
        {
            if (m)
            {
                f(m + 2);
            }
            else
            {
                g(m + 2);
            }
        }
        X() { }
        void m3() { }

        void main()
        {
            X a;
            a.f(2);
        }
    };
}

bool ex10_leapyear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Date::days_in_month(int y, int m) 
{
    const vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && ex10_leapyear(y)) 
    {
        return 29;
    }
    return days[m - 1];
}

// Вспомогательная функция для определения дня недели, используя Алгоритм Зеллера
// Алгоритм Зеллера позволяет вычислить день недели для любой даты. Вот как он работает:
// 1. Если месяц меньше марта, год уменьшается на 1.
// 2. Преобразование месяца по правилам : январь = 13, февраль = 14.

//d — день,
//m — месяц,
//y — год,
//J — столетие(y / 100)
//K — год в столетии(y % 100)
//Остаток от деления (𝑓 + 5) % 7 дает день недели : 0 - суббота, 1 - воскресенье, ..., 6 - пятница.
int Date::day_of_week(int y, int m, int d) 
{
    if (m < 3) 
    {
        m += 12;
        y -= 1;
    }
    int K = y % 100;
    int J = y / 100;
    int f = d + 13 * (m + 1) / 5 + K + K / 4 + J / 4 + 5 * J;
    int dayOfWeek = f % 7;
    return (dayOfWeek + 5) % 7;
}

void Date::add_day(int n) 
{
    d += n;
    while (d > days_in_month(y, m)) 
    {
        d -= days_in_month(y, m);
        if (++m > 12) 
        {
            m = 1;
            ++y;
        }
    }
}

// Функция для получения следующего рабочего дня
//Добавляем один день к текущей дате и проверяем, является ли новый день рабочим (не суббота и не воскресенье). 
//Если это выходной, продолжаем добавлять дни до тех пор, пока не получим рабочий день.
Date Date::next_workday()
{
    Date next_d = *this;
    next_d.add_day(1);
    while (next_d.day_of_week(next_d.year(), next_d.month(), next_d.day()) == 0 ||  // Воскресенье
        next_d.day_of_week(next_d.year(), next_d.month(), next_d.day()) == 6) // Суббота
    {  
        next_d.add_day(1);
    }
    return next_d;
}

// Функция для получения номера недели в году
int Date::week_of_year()  
{
    Date first_d_of_y(y, 1, 1);
    int first_d_week = first_d_of_y.day_of_week(first_d_of_y.year(), first_d_of_y.month(), first_d_of_y.day());
    int d_of_y = 0;
    for (int i = 1; i < m; ++i) 
    {
        d_of_y += days_in_month(y, i);
    }
    d_of_y += d;
    return (d_of_y + first_d_week) / 7 + 1;
}

int Date_ex12::days_in_month(int y, int m)
{
    const vector<int> days = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && ex10_leapyear(y))
    {
        return 29;
    }
    return days[m - 1];
}

// Преобразование даты в количество дней с 1 января 1970
long Date_ex12::date_to_days(int year, int month, int day)
{
    long days = 0;

    // Добавляем дни за полные прошедшие годы
    for (int y = 1970; y < year; ++y) 
    {
        days += ex10_leapyear(y) ? days_per_leap_year : days_per_year;
    }

    // Добавляем дни за полные прошедшие месяцы
    for (int m = 1; m < month; ++m) 
    {
        days += days_in_month(year, m);
    }

    // Добавляем дни в текущем месяце
    days += day - 1;

    return days;
}

// Преобразование количества дней в дату
void Date_ex12::days_to_date(long days, int& year, int& month, int& day)
{
    year = 1970;
    while (true) 
    {
        int d_in_y = ex10_leapyear(year) ? days_per_leap_year : days_per_year;
        if (days < d_in_y) break;
        days -= d_in_y;
        ++year;
    }

    month = 1;
    while (true) 
    {
        int days_in_month = this->days_in_month(year, month);
        if (days < days_in_month) break;
        days -= days_in_month;
        ++month;
    }

    day = days + 1;
}

void ex11() 
{
    Date today(2023, 8, 6);
    Date next_work = today.next_workday();
    cout << "Следующий рабочий день: " << next_work.year() << "-" << next_work.month() << "-" << next_work.day() << endl;
    cout << "Неделя года: " << today.week_of_year() << endl;
}

void ex12() 
{
    Date today(2023, 8, 6);
    today.add_day(5); 
    cout << "Новая дата: " << today.year() << "-" << today.month() << "-" << today.day() << endl;
}

void ex13() 
{
    Rational r1(5, 6);
    Rational r2(3, 4);

    Rational sum = r1 + r2;
    Rational diff = r1 - r2;
    Rational prod = r1 * r2;
    Rational quot = r1 / r2;

    cout << "Сумма: " << sum << endl;
    cout << "Разность: " << diff << endl;
    cout << "Произведение: " << prod << endl;
    cout << "Частное: " << quot << endl;
    cout << "Сравнение: " << (r1 == r2) << endl;
    cout << "Двойное представление r1: " << static_cast<double>(r1) << endl;
}

void ex14_15() 
{
    try 
    {
        Money m1(123.45, "USD");
        Money m2(54.32, "USD");
        Money m3(100.00, "DKK");

        Money sum = m1 + m2;  // Корректная операция
        cout << "Сумма: " << sum << endl;

        Money invalid_sum = m1 + m3;  // Некорректная операция

    }
    catch (const exception& e) 
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
}

void ex16() 
{
    Money m1(0.0, "USD");

    cout << "Введите сумму и валюту (например, USD1.23): ";
    cin >> m1;

    cout << "Вы ввели: " << m1 << endl;
}

void ex17() 
{
    Rational r1(1, 3);  // 1/3 доллара
    Rational r2(2, 3);  // 2/3 доллара
    Rational result = r1 + r2;  // Результат точно 1 доллар

    Money m1(0.33, "USD");  // 33 цента
    Money m2(0.67, "USD");  // 67 цента
    // В случае с Money точность может пострадать из-за округления в меньшую сторону

    cout << "Рациональный результат: " << result << " (1 доллар)" << endl;
    cout << "Денежный результат: " << m1 + m2 << " (может не быть ровно 1 доллар из-за округления)" << endl;
}

void ex18() 
{
    Rational r1(1, 7);  // 1/7
    Rational r2(2, 7);  // 2/7
    Rational result = r1 + r2;  // Результат точно 3/7

    double d1 = 1.0 / 7;
    double d2 = 2.0 / 7;
    double d_result = d1 + d2;  // Результат будет с потерей точности

    cout << "Рациональный результат: " << result << " (точно 3/7)" << endl;
    cout << "Денежный результат: " << d_result << " (может быть приблизительно 0.428571...)" << endl;
}