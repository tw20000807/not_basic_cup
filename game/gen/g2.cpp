#include "testlib.h"
#include <cassert>
#include <numeric>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int subtask = atoi(argv[1]);
	int W = atoi(argv[2]);
	int n, x, y;
	int MAXN = 100000;
	vector< int > S;
	if(subtask == 1){
		x = 1;
		y = rnd.wnext(1, MAXN, 10);
		n = rnd.wnext(1,min(100, max(x, y)), W);
		S.resize(max(x, y));
		iota(S.begin(), S.end(), 1);
		shuffle(S.begin() + 1, S.end());
		S.resize(n);
	}
	else if(subtask == 2){
		MAXN = 100;
		x = rnd.wnext(1, MAXN, 10);
		y = rnd.wnext(1, MAXN, 10);
		n = max(x, y);
		S.resize(max(x, y));
		iota(S.begin(), S.end(), 1);
	}
	else if(subtask == 3){
		x = rnd.wnext(1, 100, 10);
		y = rnd.wnext(1, 100, 10);
		n = rnd.wnext(1, min(100, max(x, y)), W);
		S.resize(max(x, y));
		iota(S.begin(), S.end(), 1);
		shuffle(S.begin() + 1, S.end());
		S.resize(n);
	}
	else if(subtask == 4){
		x = rnd.wnext(1, MAXN, 10);
		y = rnd.wnext(1, MAXN, 10);
		n = min(max(x, y), 4);
		S.resize(min(max(x, y), 10));
		iota(S.begin(), S.end(), 1);
		shuffle(S.begin() + 1, S.end());
		S.resize(n);
	}
	else{
		assert(0);
	}
	println(n, x, y);
	println(S);
	return 0;
}
