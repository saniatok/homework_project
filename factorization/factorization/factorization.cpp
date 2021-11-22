#include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include <fstream>
#include "Algorithms.h"
using namespace std;

#define RUN(x) {                \
    Run(#x, x, data);           \
}

template <typename T>
void Run(string method_name, Algorithms<T> a, int data )
{
    auto start = chrono::system_clock::now();
    vector<int> result=a(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << endl << method_name << "\t"
         << to_string(time) + "\tmcs" << endl
        << "Простые множители числа: ";
    for (vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
            cout << *i << " " ;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int data;
    cout << "Введите число для факторизации: ";
    cin >> data;
    RUN(p_method_Pollard);
    RUN(FermatFactor);
    return 0;
}