#include <iostream>
#include <vector>
#include "Algorithms.h"

using namespace std;

int main()
{
    __int64 ch;
    setlocale(LC_ALL, "Russian");
    cout << "Введите число: ";
    cin >> ch;
    if (Pollardans(ch)[0] != 1) {
        cout << "Простые множители числа: ";
        for (__int64 i = 0; i < Pollardans(ch).size(); i++) {
            cout << Pollardans(ch)[i] << " ";
        }
    }
    else
        cout << "Разложить число на простые множители по методу Полларда p-1 не удалось";
}
