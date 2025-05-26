#include "game.h"
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

set<int> moves;
unordered_map<long long, int> memo; // key = (x << 17) | y
int start_x, start_y;

int grundy(int x, int y) {
    if (x == 1 && y == 1) return 0;
    long long key = ((long long)x << 17) | y;
    if (memo.count(key)) return memo[key];

    set<int> s;
    for (int d : moves) {
        if (x - d >= 1) s.insert(grundy(x - d, y));
        if (y - d >= 1) s.insert(grundy(x, y - d));
    }

    int g = 0;
    while (s.count(g)) ++g;
    return memo[key] = g;
}

int game_start(int x, int y, vector<int> S) {
    start_x = x;
    start_y = y;
    moves = set<int>(S.begin(), S.end());

    int g = grundy(x, y);
    return (g == 0 ? 0 : 1); // 0 means後手有必勝法，我就後手
}

int play(int x, int y) {
    for (int d : moves) {
        if (x - d >= 1 && grundy(x - d, y) == 0) return -d; // 往左
        if (y - d >= 1 && grundy(x, y - d) == 0) return d;   // 往下
    }
    return -(*moves.begin()); // 隨便走一個合法的，反正已經輸了
}
