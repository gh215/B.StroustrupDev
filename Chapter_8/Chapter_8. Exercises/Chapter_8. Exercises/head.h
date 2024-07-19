#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct VectorStats
{
	int min;
	int max;
	double average;
	double median;
};

vector<int> fibonacci_ex3(int x, int y, vector<int> v, int n);
vector<int> fibonacci_overflow_ex4(int x, int y, vector<int> v, int n);
vector<int> reverseVectorCopy_ex5(const vector<int>& vec);
vector<string> reverseVectorCopy_ex6(const vector<string>& vec);
void reverseVectorInPlace_ex5(vector<int>& vec);
void reverseVectorInPlace_ex6(vector<string>& vec);
void PeopleCount_ex7();
double sumOfProducts_ex8(const vector<double>& price, const vector<double>& weight);
int maxv_ex9(const vector<int>& vec);
VectorStats analyseVector_ex10(const vector<int>& vec);
bool print_until_s_ex11(const vector<string>& v, const string& quit);
bool print_until_ss_ex11(const vector<string>& v, const string& quit);
vector<int> getStringLengths_ex12(const vector<string>& v);
void print_ex2(const string& comment, const vector<int>& v); 
void print_ex2(const string& comment, const vector<string>& v);
void swap_r(int& a, int& b);
void ex3_print();
void ex4_print();
void ex5_print();
void ex6_print();
void ex7_print();
void ex8_print();
void ex9_print();
void ex10_print();
void ex11_tests();
void ex12_print();
void ex13();
