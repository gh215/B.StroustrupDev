#include "head.h"

void print_ex2(const string& comment, const vector<int>& v) 
{
    cout << comment << ": ";
    for (int num : v) 
    {
        cout << num << " ";
    }
}

vector<int> fibonacci_ex3(int x, int y, vector<int> v, int n) 
{
    v.push_back(x);
    v.push_back(y);
    if (n > 1)
    {
        for (int i = 2; i < n; ++i)
        {
            v.push_back(v[i - 1] + v[i - 2]);
        }
    }
    return v;
}

vector<int> reverseVectorCopy_ex5(const vector<int>& vec) 
{
    return vector<int>(vec.rbegin(), vec.rend());
}

void reverseVectorInPlace_ex5(vector<int>& vec)
{
    reverse(vec.begin(), vec.end());
}

vector<string> reverseVectorCopy_ex6(const vector<string>& vec)
{
    return vector<string>(vec.rbegin(), vec.rend());
}

void reverseVectorInPlace_ex6(vector<string>& vec)
{
    reverse(vec.begin(), vec.end());
}

void PeopleCount_ex7() 
{
    vector<string> name;
    vector<double> age;

    cout << "Введите 5 имен:\n";
    for (int i = 0; i < 5; ++i) 
    {
        string temp;
        cin >> temp;
        name.push_back(temp);
    }

    cout << "Введите возраст для каждого имени:\n";
    for (const auto& n : name) 
    {
        cout << "Возраст для " << n << ": ";
        double temp;
        cin >> temp;
        age.push_back(temp);
    }

    cout << "Исходные пары (имя, возраст):\n";
    for (size_t i = 0; i < name.size(); ++i) 
    {
        cout << name[i] << ": " << age[i] << endl;
    }

    vector<pair<string, double>> name_age_pairs;
    for (size_t i = 0; i < name.size(); ++i) 
    {
        name_age_pairs.push_back(make_pair(name[i], age[i]));
    }

    sort(name_age_pairs.begin(), name_age_pairs.end());

    cout << "\nОтсортированные пары (имя, возраст):\n";
    for (const auto& pair : name_age_pairs) 
    {
        cout << pair.first << ": " << pair.second << endl;
    }
}


double sumOfProducts_ex8(const vector<double>& price, const vector<double>& weight) 
{
    if (price.size() != weight.size()) 
    {
        throw invalid_argument("Векторы должны иметь одинаковый размер");
    }

    double sum = 0;
    for (size_t i = 0; i < price.size(); ++i) 
    {
        sum += price[i] * weight[i];
    }

    return sum;
}

int maxv_ex9(const vector<int>& vec) 
{
    if (vec.empty()) 
    {
        throw runtime_error("Vector is empty");
    }
    return *max_element(vec.begin(), vec.end());
}

void ex3_print()
{
    vector<int> fib_numbers = fibonacci_ex3(1, 2, {}, 10);
    print_ex2("Числа Фибоначчи", fib_numbers);
}

void ex5_print()
{
    vector<int> reversed = reverseVectorCopy_ex5({ 2,5,7,9,12,32 });
    vector<int> vec = { 2,5,7,9,12,32 };
    reverseVectorInPlace_ex5(vec);
}

void ex6_print()
{
    vector<string> reversed = reverseVectorCopy_ex6({"Hehe, here we go"});
    vector<string> vec = { "Hehe, here we go" };
    reverseVectorInPlace_ex6(vec);
}

void ex7_print()
{
    PeopleCount_ex7();
}

void ex8_print()
{
   cout << sumOfProducts_ex8({ 12, 16, 18, 20, 22 }, { 6, 9, 1, 8, 20 });
}

void ex9_print()
{
    cout << maxv_ex9({1, 4, 5, 7, 10, 23});
}
