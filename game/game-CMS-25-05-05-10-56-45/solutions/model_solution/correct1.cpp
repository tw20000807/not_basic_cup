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
void game(int x, int y, const std::vector<int> S){
	--x, --y;
	vector< int > sg(max(x, y) + 1);
	for(int i = 0; i <= max(x, y); ++i){
		vector< int > tmp;
		for(int t : S){
			if(i - t >= 0){
				tmp.push_back(sg[i - t]);
			}
		}
		sg[i] = mex(tmp);
	}
	if(sg[x] == sg[y]){
		int t = play(0);
		if(t < 0) x -= -t;
		else if(t > 0) y -= t;
		else exit(0);
	}
	while(true){
		int ok = 0;
		int ret = 0;
		if(sg[x] > sg[y]){
			for(int t : S){
				if(x - t >= 0 && sg[x - t] == sg[y]){
					ret = play(-t);
					x -= t;
					ok = 1;
					break;
				}
			}
		}
		else if(sg[y] > sg[x]){
			for(int t : S){
				if(y - t >= 0 && sg[y - t] == sg[x]){
					ret = play(t);
					y -= t;
					ok = 1;
					break;
				}
			}
		}
		assert(ok);
		if(ret < 0) x -= -ret;
		else if(ret > 0) y -= ret;
		else exit(0);
	}
	
}
