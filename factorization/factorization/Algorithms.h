#pragma once
#include <vector>

using namespace std;

template <typename T>
using Algorithms = vector<int>(*)(T data);

vector<int> p_method_Pollard(int data);
vector<int>FermatFactor(int data);
vector<int> pethod_Leman(int data);