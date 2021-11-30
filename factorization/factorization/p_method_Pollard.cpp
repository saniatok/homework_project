#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;

unsigned int GCD(unsigned int a, unsigned int b) //функция нахождения НОД
{   
	unsigned int с;  
	while( b != 0 )   
	{       
		с = a % b;      
		a = b;       
		b = с;   
	}   
	return a;
}

int Pollard(int n)
{
	int a = 2;
	int i = 2;
	int d;
	while (true)
	{
		a = (a ^ i) % n;
		d = GCD((a - 1), n);
		if (d > 1)
		{
			return d;
			break;
		}
		else
		{
			i += 1;
		}
	}
}

unsigned int StepMod(unsigned int A, unsigned int B, unsigned int N) //функция нахождения   числа А в степени B по модулю N 
{
	unsigned __int64 y = A;
	int t = 31;
	while ((B & (1 << t)) == 0)
		t--;
	t--;
	for (;t >= 0; t--)
	{
		y = (y * y) % N;
		if ((B & (1 << t)) != 0)
			y = (y * A) % N;
	}
	return y;
}



bool Test(unsigned int m) //функция проверки числа на простоту
{   
	int s=0,t=m-1,a;     
	unsigned long x; 
	while(t%2==0)   
	{
		s++;      
		t=t/2;
	} 

	int r=0; 
	while (r < 50)
	{
		r++;
		a = (rand() % (m - 4)) + 2;
		x = StepMod(a, t, m);
		if (!((x == 1) || (x == (m - 1))))
		{
			for (int j = 0; j < (s - 1); j++)
			{
				x = StepMod(x, 2, m);
				if (x == 1)
				{
					return 0;
				}
				if (x == (m - 1))
				{
					break;
				}
			}
		}
	} 
	return 1; 
}


vector<int> p_method_Pollard(int data)
{
	int n = data;
	vector <int> res;
	int d;
	int r;
	int num=n;
	while (true)
	{
		d = Pollard(num);
		res.push_back(d);
		r = int(num / d);
		if (Test(r))
		{
			res.push_back(r);
			break;
		}
		else
		{
			num = r;
		}
	}
	return res;
}
