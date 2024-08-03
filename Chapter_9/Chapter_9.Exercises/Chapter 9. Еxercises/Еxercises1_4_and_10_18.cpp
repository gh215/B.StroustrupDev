#include "Header_ex1_4_and_10_18.h"

void Name_pairs::read_names()
{
    string input;
    cout << "Введите имена (для завершения введите 'end'): " << endl;
    while (true)
    {
        cin >> input;
        if (input == "end") break;
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
    Вытолкнуть хлеб
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
        int m;
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

/*
struct X - определение структуры X
void f(int x) - метод f структуры X, принимающий целочисленный аргумент
struct Y - вложенная структура Y внутри метода f
int f() - метод f структуры Y, возвращающий 1
int m - член m структуры Y
m = x - присваивание значения x члену m структуры X
Y m2 - создание объекта m2 структуры Y
return f(m2.f()) - рекурсивный вызов метода f структуры X с аргументом, полученным от вызова f() объекта m2
void g(int m) - метод g структуры X с условным оператором
X() - конструктор структуры X
void m3() - пустой метод m3 структуры X
*/