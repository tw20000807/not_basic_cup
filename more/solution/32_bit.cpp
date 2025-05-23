#include "more.h"
#include <bits/stdc++.h>
using namespace std;

long long remember(const std::vector<int> v){
	int ret = 0;
	int n = v.size();
	for(int i = 0; i < n; ++i){
		mt19937 rng(v[i]);
		int tmp = rng();
		ret -= tmp;
	}
	return ret;
}
std::vector<int> find(const int k, const long long ret, const std::vector<int> v){
	int n = v.size();
	int sum = ret;
	vector< pair<int, int> > tmp(n);
	for(int i = 0; i < n; ++i){
		mt19937 rng(v[i]);
		tmp[i] = {rng(), v[i]};
		sum += tmp[i].first;
	}
	sort(tmp.begin(), tmp.end());
	if(k == 1){
		return {lower_bound(tmp.begin(), tmp.end(), pair<int,int>{sum, 0})->second};
	}
	if(k == 2){
		for(int i = 0; i < n; ++i){
			int a = tmp[i].first; int b = tmp[i].second;
			auto it = lower_bound(tmp.begin(), tmp.end(), pair<int,int>{sum-a, 0});
			if(it->first == (sum - a)){
				return {b, it->second};
			}
		}
	}
	if(k == 3){
		for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j){
			int a = tmp[i].first; int b = tmp[i].second;
			int p = tmp[j].first; int q = tmp[j].second;
			auto it = lower_bound(tmp.begin(), tmp.end(), pair<int,int>{sum-a-p, 0});
			if(it->first == (sum-a-p)){
				return {b, q, it->second};
			}
		}
	}
	return {};
}