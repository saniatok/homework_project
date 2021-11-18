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
void Run(string method_name, Algorithms<T> p, vector <T> data)
{
    auto start = chrono::system_clock::now();
    vector<T> res = p(data);
    auto stop = chrono::system_clock::now();
    auto time = chrono::duration_cast<chrono::microseconds>(stop - start).count();
    cout << method_name << "\t"
        << (is_sorted(res.begin(), res.end()) ? to_string(time) + "\tmcs" : "failed") << endl;
}

void ReadData(vector <int> data)
{
    string str;
    int num;
    ifstream file;
    file.open("data.txt");
    while (!file.eof()) {
        getline(file, str);
        for (int i : str)
        {
            num = stoi(str);
            data.push_back(i);
        }
    }
    file.close();
}

int main()
{
    vector <int> data;
    ReadData(data);
}