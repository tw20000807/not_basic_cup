#include "game.h"
#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

namespace{
	int judge_play(int x, int y){
		if(x == 1 && y == 1){
			cout << "OK, your program win!" << endl;
			exit(0);
		}
		cout << "(" << x << " " << y << ")" << endl;
		int k;
		assert(cin >> k);
		return k;
	}
	void move(int &x, int &y, int k){
		if(k < 0) x -= -k;
		else y -= k;
		assert(x > 0 && y > 0);
	}

}

int main() {
	int n, x, y;
	assert(cin >> n >> x >> y);
	vector< int > S(n);
	for(int i = 0; i < n; ++i){
		assert(cin >> S[i]);
	}
	int f = game_start(x, y, S);
	if(!f){
		int k = judge_play(x, y);
		move(x, y, k);
	}
	while(x != 1 || y != 1){
		int k = play(x, y);
		assert(count(S.begin(), S.end(), abs(k)));
		move(x, y, k);
		k = judge_play(x, y);
		assert(count(S.begin(), S.end(), abs(k)));
		move(x, y, k);
		if(x == 1 && y == 1){
			cout << "Wrong, your program lose!" << endl;
			exit(0);
		}
	}
}
