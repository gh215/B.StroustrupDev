#include <iostream>
#include "..\Include\std_lib_facilities.h"

using namespace std;

int main()
try {
    cout << "Success!\n";
    cout << "Success!\n";
    cout << "Success" << "!\n";
    string success = "Success!";
    cout << success << endl;

    int res = 7; 
    vector<int> v(10); 
    v[5] = res; 
    cout << "Success!\n";

    vector<int> v2(10); 
    v2[5] = 7; 
    if (v2[5] == 7) cout << "Success!\n";

    bool cond = true; 
    if (cond) cout << "Success!\n";
    else cout << "Fail!\n";

    bool c = true; 
    if (c) cout << "Success!\n"; 
    else cout << "xFail!\n";

    string s1 = "ape"; 
    bool c2 = "fool" < s1; 
    if (c2) cout << "Success!\n";

    string s2 = "ape"; 
    if (s2 != "fool") cout << "Success!\n";

    string s3 = "ape"; 
    if (s3 != "fool") cout << "Success!\n";

    string s4 = "ape"; 
    if (s4 != "fool") cout << "Success!\n";

    vector<char> v3(5); 
    
    for (int i = 0; i < v3.size(); ++i); 
    cout << "Success!\n";

    vector<char> v4(5); 
    for (int i = 0; i < v4.size(); ++i); 
    cout << "Success!\n";

    string s5 = "Success!\n"; 
    for (int i = 0; i < s5.size(); ++i) 
        cout << s5[i];

    if (true) cout << "Success!\n";         
    else cout << "Fail!\n";

    int x1 = 2000; 
    char c3 = x1; 
    if (c3 == 0) cout << "Success!\n";

    string s6 = "Success!\n"; 
    for (int i = 0; i < s6.size(); ++i) cout << s6[i];

    vector<int> v5(5); 
    for (int i = 0; i < v5.size(); ++i); cout << "Success!\n";

    int i1 = 0; 
    int j1 = 9; 
    while (i1 < 10) ++i1; if (j1 > i1) cout << "Success!\n";

    int x2 = 2; 
    double d = 5.0 / (x2 - 2); 
    if (d != 2 * x2 + 0.5) cout << "Success!\n";

    string s7 = "Success!\n"; 
    for (int i = 0; i < s7.size(); ++i) cout << s7[i];

    int i2 = 0, j2 = 0; 
    while (i2 < 10) ++i2; 
    if (j2 < i2) cout << "Success!\n";

    int x3 = 4; 
    double d2 = 5.0 / (x3 - 2); 
    if (d2 == 2 * x3 + 0.5) cout << "Success!\n";

    cout << "Success!\n";

    keep_window_open();
    return 0;
}
catch (exception& e) {
    cerr << "error: " << e.what() << "\n";
    keep_window_open();
    return 1;
}
catch (...) {
    cerr << "Неизвестное исключение!\n";
    keep_window_open();
    return 2;
}