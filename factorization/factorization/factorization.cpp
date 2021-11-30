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
        << "Множители числа: ";
    for (vector<int>::const_iterator i = result.begin(); i != result.end(); ++i)
            cout << *i << " " ;
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    while (1)
    {
        int data;
        cout <<endl << "Введите число для факторизации или 0 для выхода: ";
        cin >> data;
        if (data != 0)
        {
            RUN(p_method_Pollard);
            RUN(metodpollardap1);
            RUN(FermatFactor);
            RUN(pethod_Leman);
            RUN(fraction_method);
        }
        else
            return 0;
    }
    return 0;
}
