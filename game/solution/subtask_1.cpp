#include "game.h"
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
vector< int > dp;
vector< int > s;
int game_start(int x, int y, const std::vector<int> S){
	--x, --y;
    assert(x == 0);
	s = S;
    dp = vector< int > (max(x, y) + 1);

	for(int i = 0; i <= max(x, y); ++i){
		for(int t : S){
			if(i - t >= 0){
				dp[i] |= !dp[i - t];
			}
		}
	}
	return dp[y];
}
int play(int x, int y){
    --x, --y;
    cerr << x << " " << y << endl;
	for(int i : s){
		if(y - i >= 0 && dp[y - i] == 0){
			return i;
		}
	}
	assert(0);
}