#include "sequence.h"
#include <bits/stdc++.h>
using namespace std;

vector< int > v;
mt19937 rng(time(0) + 666666);

void bob_init(int n){
	v.resize(n);
	iota(v.begin(), v.end(), 0);
	random_shuffle(v.begin(), v.end());
	{
		vector< int > tmp(n);
		map<int, int> vis;
		vector< int > same;
		for(int i = 2; i < n; ++i){
			tmp[i] = compare_numbers(v[0], v[1], v[i]);
			if(vis.count(tmp[i])) same.push_back(tmp[i]);
			vis[tmp[i]] = i;
		}
		sort(same.begin(), same.end());
		same.resize(unique(same.begin(), same.end()) - same.begin());

	}

}
int query_from_alice(int a){
	return v[a];
}
