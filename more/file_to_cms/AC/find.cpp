#include "more.h"
#include <bits/stdc++.h>
using namespace std;

std::vector<int> find(const int k, const long long ret, const std::vector<int> v){
	int n = v.size();
	long long sum = ret;
	vector< pair<long long, int> > tmp(n);
	for(int i = 0; i < n; ++i){
		mt19937_64 rng(v[i]);
		tmp[i] = {rng(), v[i]};
		sum += tmp[i].first;
	}
	sort(tmp.begin(), tmp.end());
	if(k == 1){
		return {lower_bound(tmp.begin(), tmp.end(), pair<long long,int>{sum, 0})->second};
	}
	if(k == 2){
		for(int i = 0; i < n; ++i){
			long long a = tmp[i].first; int b = tmp[i].second;
			auto it = lower_bound(tmp.begin(), tmp.end(), pair<long long,int>{sum-a, 0});
			if(it->first == (sum - a)){
				return {b, it->second};
			}
		}
	}
	if(k == 3){
		for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j){
			long long a = tmp[i].first; int b = tmp[i].second;
			long long p = tmp[j].first; int q = tmp[j].second;
			auto it = lower_bound(tmp.begin(), tmp.end(), pair<long long,int>{sum-a-p, 0});
			if(it->first == (sum-a-p)){
				return {b, q, it->second};
			}
		}
	}
	return {};
}