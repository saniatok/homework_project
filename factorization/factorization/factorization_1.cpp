#include <iostream>
#include <vector>
#include "Algorithms.h"

using namespace std;

int main()
{
    int ch;
    setlocale(LC_ALL, "Russian");
    cout << "������� �����: ";
    cin >> ch;
    cout << "������� ��������� �����: ";
    for (unsigned int i = 0; i < Pollardans(ch).size(); i++) {
        cout << Pollardans(ch)[i] << " ";
    }
}
