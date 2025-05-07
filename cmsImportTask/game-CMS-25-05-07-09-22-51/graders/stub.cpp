#include "game.h"
#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

namespace{
	ifstream fin;
	ofstream fout;

	int judge_play(int x, int y){
		fout << x << " " << y << endl;
		int k;
		assert(fin >> k);
		return k;
	}
	int move(int &x, int &y, int k){
		if(k < 0) x -= -k;
		else y -= k;
		return x > 0 && y > 0;
	}

}

int main(int argc, char *argv[]) {
	fout.open(argv[2]);
	fin.open(argv[1]);
	int n, x, y;
	assert(fin >> n >> x >> y);
	vector< int > S(n);
	for(int i = 0; i < n; ++i){
		assert(fin >> S[i]);
	}
	int f = game_start(x, y, S);
	if(!f){
		int k = judge_play(x, y);
		assert(move(x, y, k));
	}
	while(x != 1 || y != 1){
		cerr << x << " " << y << "\n";
		int k = play(x, y);
		assert(count(S.begin(), S.end(), abs(k)));
		assert(move(x, y, k));
		k = judge_play(x, y);
		assert(move(x, y, k));
	}
}
