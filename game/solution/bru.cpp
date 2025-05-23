#include "game.h"
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
vector< vector< int > > dp;
vector< int > s;
int game_start(int x, int y, const std::vector<int> S){
	--x, --y;
	s = S;
    dp = vector< vector< int > > (x + 1,vector< int >(y + 1));

	for(int i = 0; i <= x; ++i) for(int j = 0; j <= y; ++j){
		for(int t : S){
			if(i - t >= 0){
				dp[i][j] |= !dp[i - t][j];
			}
            if(j - t >= 0){
                dp[i][j] |= !dp[i][j - t];
            }
            if(dp[i][j]) break;
		}
	}
	return dp[x][y];
}
int play(int x, int y){
    --x, --y;
    cerr << x << " " << y << endl;
	for(int i : s){
		if(y - i >= 0 && dp[x][y - i] == 0){
			return i;
		}
        if(x - i >= 0 && dp[x - i][y] == 0){
            return -i;
        }
	}
	assert(0);
}