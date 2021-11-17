#include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <iostream>
#include "Algorithms.h"
using namespace std;

template <typename T>
void Run(string method_name, Algorithms<T> p, vector<T> data)
{
    auto start = chrono::system_clock::now();
    vector<T> res = p(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << method_name << "\t"
        << data.size() << "\t"
        << (is_sorted(res.begin(), res.end()) ? to_string(time) + "\tmcs" : "failed") << endl;
}

int main()
{
   
    
}