#include "game.h"
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
namespace{
	int n;
	vector< int > copy_S;
}
int game_start(int x, int y, std::vector<int> S){
	n = S.size();
	copy_S = S;
	assert(count(S.begin(), S.end(), 1) == 1);
	if(x == y) return 1;
	return 0;
}
int play(int x, int y){
	if(x > y) return -1;
	return 1;
}