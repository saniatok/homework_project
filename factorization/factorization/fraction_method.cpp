#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <limits>


using namespace std;

bool is_equal(double x, double y) {
    return fabs(x - y) < numeric_limits<double>::epsilon();
}

long gcd(long a, long b) {//ищем НОД

    while (a != b) {
        if (a > b) {
            long tmp = a;
            a = b;
            b = tmp;
        }
        b = b - a;
    }
    return a;
}

vector<int> fractionmethod(int& n) {
    double e = sqrt(n) - (int)sqrt(n);
    vector<int> b;
    vector<int> A;
    vector<int> B;
    vector<int> lefts;
    vector<int> rigts;
    vector<int> ans;
    b.push_back((int)sqrt(n));
    int i = 0;
    while (1) {
        double temp = 1 / (e);
        b.push_back(int(temp));
        for (int j = 1; j < (int)sqrt(n); ++j) {
            for (int k = 1; k < 2 * (int)sqrt(n); ++k) {
                double f = (j + sqrt(n)) / k;
                if (is_equal(f, temp)) {
                    A.push_back(j);
                    B.push_back(k);
                }
            }
        }
        e = temp - (int)temp;
        if (i >= 1) {
            for (int i = 2; i < (int)sqrt(n); ++i) {
                if (n % i == 0) {
                    ans.push_back(i);
                    ans.push_back(n / i);
                    return ans;
                }
            }
            lefts.push_back(B[i] * B[i - 1] * (-1));
            rigts.push_back(A[i] * A[i]);
            if (lefts.size() > 2) {
                for (int t = 1; t < lefts.size() - 1; ++t) {
                    for (int l = 0; l < t; ++l) {
                        if (sqrt(lefts[t] * lefts[l]) == static_cast<int>(sqrt(lefts[t] * lefts[l])))
                        {
                            ans.push_back(gcd(abs((int)sqrt(lefts[t] * lefts[l]) - (int)sqrt(rigts[i])), n));
                            ans.push_back(n / gcd(abs((int)sqrt(lefts[t] * lefts[l]) - (int)sqrt(rigts[i])), n));
                            return ans;
                        }
                    }
                }
            }
        }
        cout << (int)temp << endl;
        i++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> v = fractionmethod(n);
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }
    return 0;
}
