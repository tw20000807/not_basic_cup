#include "sort.h"

#include <bits/stdc++.h>
using namespace std;

vector< int > v;
mt19937 rng(time(0) + 666666);

void bob_init(int n){
	v.resize(n);
	iota(v.begin(), v.end(), 0);
	random_shuffle(v.begin(), v.end());
	
	auto f = [&](auto f, int l, int r, vector< int > &v, int mn = -1, int mx = -1){

	};

}
int query_from_alice(int a){
	return p[a];
}
