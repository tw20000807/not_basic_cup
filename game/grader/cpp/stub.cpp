#include "game.h"
#include <cassert>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream fout(argv[2]);
	ifstream fin(argv[1]);
	int n, x, y;
	if(!(fin >> n >> x >> y)){
		cerr << "can not read n, x, y" << endl;
		exit(0);
	}
	vector< int > S(n);
	for(int i = 0; i < n; ++i){
		if(!(fin >> S[i])){
			cerr << "can not read S" << endl;
			exit(0);
		}
	}
	int f = game_start(x, y, S);
	fout << f << endl;
	while(true){
		if(!(fin >> x >> y)){
			exit(0);
		}
		int k = play(x, y);
		fout << k << endl;
	}
}
