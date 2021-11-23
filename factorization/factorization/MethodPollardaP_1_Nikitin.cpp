#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

__int64 powmod(__int64 a, __int64 k, __int64 n) // (a*k) % n
{
    return (__int64(pow(a, k)) % n);
}

bool prostoe(__int64 n)// проверяем простое число или нет
{
    for (unsigned int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0)
            return false;
    return true;
}

__int64 NOD(__int64 a, __int64 b) { //НОД по алгоритму Евклида
    return(a == 0) ? b : NOD(b % a, a);
}

__int64 metodpollardap1(__int64 n) {//реализация метода Полларда p-1
    vector <__int64> prostch;
    __int64 B;
    B = 20;
    for (unsigned int i = 2; i <= B; i++) {
        if (prostoe(i)) {
            prostch.push_back(i);
        }
    }
    __int64 l;
    __int64 a = 2;
    __int64 p;
    p = NOD(a, n);
    if (p == 1) {
        for (unsigned int i = 0; i <= prostch.size() - 1; i++) {
            if (NOD(a - 1, n) == 1) {
                l = __int64(floor(log(B) / log(prostch[i])));
                a = powmod(a, powmod(prostch[i], l, n), n);
                if (a > 1)
                    p = NOD(a - 1, n);
            }
        }
    }
    return p;
}

vector <__int64> Pollardans(__int64 n) {//создаем вектор простых множителей числа
    vector <__int64> mn;
    __int64 p = 2;
    while (n > 1 && p > 1) {
        if (!prostoe(n)) {
            p = metodpollardap1(n);
            n = n / p;
            mn.push_back(p);
        }
        else {
            mn.push_back(n);
            n = 1;
        }
    }
    return mn;
}