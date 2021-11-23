#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

using namespace std;
int gsd(unsigned long long a, unsigned long long b)
{
	while (a > 0 && b > 0)

		if (a > b)
			a %= b;

		else
			b %= a;

	return a + b;
}
bool square(unsigned long long a) {
	if (sqrt(a) == int(sqrt(a)))
		return true;
	else return false;

}
unsigned long long Step1(const unsigned long long n) {
	int b;
	b = n;
	for (int a = 2; a<=int(cbrt(n)); a++) {
		if (n % a == 0) {
			return a;
		}
		else continue;
	}
	return b;
}
unsigned long long Step2(const unsigned long long n)
{
	int b = n;
	for (int k = 1; k <= int(pow(n, 1 / 3.)); k++)
		for (int d = 0; (d <= (int(pow(n, 1 / 6.) / (4 * sqrt(k))) + 1)); d++) {
			if (square(pow((floor(sqrt(4 * k * n)) + d), 2) - 4 * k * n)) {
				if ((1 < gsd(int(sqrt(4 * k * n)) + d + sqrt(pow(int(sqrt(4 * k * n)) + d, 2) - 4 * k * n), n)) && (gsd(int(sqrt(4 * k * n)) + d + sqrt(pow(int(sqrt(4 * k * n)) + d, 2) - 4 * k * n), n) < n))
				{
					b = gsd(int(sqrt(4 * k * n)) + d + sqrt(pow(int(sqrt(4 * k * n)) + d, 2) - 4 * k * n), n);
					return b;

				}
			}
		}
	return b;
}
vector <int> pethod_Leman(int data) {
	vector<int> res;

	if (Step1(data) != data) {
		res.push_back(Step1(data));
		res.push_back(data / Step1(data));
	}
	else if (Step2(data) != data) {
		res.push_back(Step2(data));
		res.push_back(data / Step2(data));
	}
	return res;
}

