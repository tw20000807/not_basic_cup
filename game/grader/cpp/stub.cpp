#include "game.h"
#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin;
ofstream fout;
int play(int k){
	fout << k << endl;
	assert(fin >> k);
	if(k == 0) exit(0);
	return k;
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
	game(x, y, S);
	return 0;
}
