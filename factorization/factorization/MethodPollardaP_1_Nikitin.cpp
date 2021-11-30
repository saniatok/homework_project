#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int powmod(int a, int k, int n) // (a*k) % n
{
    return (int(pow(a, k)) % n);
}

bool prostoe(int n)// проверяем простое число или нет
{
    for (unsigned int i = 2; i <= sqrt(n); i++) 
        if (n % i == 0)
            return false;
    return true;
}

int NOD(int a, int b) { //НОД по алгоритму Евклида
    return(a == 0) ? b : NOD(b % a, a);
}

int metodpollardap1(int n) {//реализация метода Полларда p-1
    vector <int> prostch;
    int B;
    B = 10;
    for (unsigned int i = 2; i <= B; i++) {
        if (prostoe(i)) {
            prostch.push_back(i);
        }
    }
    int l;
    int a = 2;
    int p;
    p = NOD(a, n);
    if (p == 1) {
        for (unsigned int i = 0; i <= prostch.size() - 1; i++) {
            if (NOD(a - 1, n) == 1) {
                l = int(floor(log(B) / log(prostch[i])));
                a = powmod(a, powmod(prostch[i], l, n), n);
                if (a > 1)
                    p = NOD(a - 1, n);
            }
        }
    }
    return p;
}

vector <int> Pollardans(int n) {//создаем вектор простых множителей числа
    vector <int> mn;
    int p = 2;
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
    if (p == 1) {
        mn[0] = -1;
    }
    return mn;
}
