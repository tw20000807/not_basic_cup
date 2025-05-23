#include "game.h"
#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;
int game_start(int x, int y, const std::vector<int> S){
	return x != y;
}
int play(int x, int y){
    --x, --y;
    cerr << x << " " << y << endl;
	return y - x;
}