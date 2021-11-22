#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> FermatFactor(int data)
{
    vector<int>factors, ffact;

    int a = sqrt(data) + 1;
    int b2 = a * a - data;


    int tmp = sqrt(b2);
    while (tmp * tmp != b2)
    {
        a = a + 1;
        b2 = a * a - data;

        tmp = sqrt(b2);
    }
    factors.push_back(a + tmp);
    factors.push_back(a - tmp);

    return factors;
}
