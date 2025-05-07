#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerChecker("difference", argc, argv);
	int n = inf.readInt();
	int k = ouf.readInt();
	vector< vector< int > > v(k, vector< int >(n));
	vector< vector< int > > p(k, vector< int >(n, -1));
	int T = k - (__lg(n - 1) + 1);
	for(int i = 0; i < k; ++i){

		int t = ouf.readInt(1, n / 2);
		for(int j = 0; j < t; ++j){
			int x = ouf.readInt(0, n - 1);
			v[i][j] = x;
			if(p[i][x] != -1) quitf(_wa, "same value");
			p[i][x] = 0;
		}

		for(int j = 0; j < t; ++j){
			int x = ouf.readInt(0, n - 1);
			v[i][j] = x;
			if(p[i][x] != -1) quit(_wa, "same value");
			p[i][x] = 1;
		}
	}

	for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j){
		int ok = 0;
		for(int t = 0; t < k; ++t) if(p[t][i] != -1 && p[t][j] != -1) {
			if(p[t][i] ^ p[t][j]){
				ok = 1;
				break;
			}
		}
		if(!ok) quitf(_wa, "%d, %d have not apart\n", i, j);
	}
	if(T == 0) quit(_ok);
	if(T == 1) quitp(0.5);
	if(T == 2) quitp(0.3);
	if(T == 3) quitp(0.1);
	quitf(_wa, "T=%d", T);
}
