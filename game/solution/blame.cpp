#include "game.h"
#include <bits/stdc++.h>
using namespace std;
int n;
vector<bool> dp, dp2;
vector<int> SS;
int game_start(int x, int y, vector<int> S){
    dp.resize(y+1);
    dp2.resize(x+1);
    SS = S;
    dp[1] = false;
    for(int i = 2; i <= y; i++) {
        bool ok = true;
        for(auto &d : S) if(i-d >= 1) {
            ok &= dp[i-d];
        }
        dp[i] = !ok;
    }
    dp2[1] = false;
    for(int i = 2; i <= x; i++) {
        bool ok = true;
        for(auto &d : S) if(i-d >= 1) {
            ok &= dp2[i-d];
        }
        dp2[i] = !ok;
    }
    // for(int i = 1; i <= y; i++) cout << dp[i] << " \n"[i==y];
    return (dp[y] + dp2[x]) != 1;
}
int play(int x, int y){
    for(auto &d : SS) if(y-d >= 1 && !dp[y-d]) {
        return d;
    }
    for(auto &d : SS) if(x-d >= 1 && !dp2[x-d]) {
        return -d;
    }
    for(auto &d : SS) if(y-d >= 1) return d;
    for(auto &d : SS) if(x-d >= 1) return -d;
}