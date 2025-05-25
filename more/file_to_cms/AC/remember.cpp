#include "more.h"
#include <bits/stdc++.h>
using namespace std;

long long remember(const std::vector<int> v){
	long long ret = 0;
	int n = v.size();
	for(int i = 0; i < n; ++i){
		mt19937_64 rng(v[i]);
		long long tmp = rng();
		ret -= tmp;
	}
	return ret;
}
