#include "game.h"
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
int mex(vector< int > v){
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for(int i = 0; i < (int)v.size(); ++i){
		if(v[i] != i) return i;
	}
	return v.size();
}
vector< int > sg, s;
int game_start(int x, int y, const std::vector<int> S){
	--x, --y;
	s = S;
	sg = vector< int > (max(x, y) + 1);
	for(int i = 0; i <= max(x, y); ++i){
		vector< int > tmp;
		for(int t : S){
			if(i - t >= 0){
				tmp.push_back(sg[i - t]);
			}
		}
		sg[i] = mex(tmp);
	}
	return (sg[x] != sg[y]);
}
int play(int x, int y){
	--x, --y;
	assert(sg[x] != sg[y]);
	int neg = 1;
	if(sg[x] > sg[y]) swap(x, y), neg = -1;
	for(int i : s){
		if(y - i >= 0 && sg[y - i] == sg[x]){
			return neg * i;
		}
	}
	assert(0);
}