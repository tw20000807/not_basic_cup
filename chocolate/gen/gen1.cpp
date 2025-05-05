#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int maxn = atoi(argv[1]);
	int c = atoi(argv[2]);
	int T = 500;
	cout << c << endl;
	cout << T << endl;
	for(int i = 1; i <= T; ++i){
		int n = rnd.next(1, maxn);
		int b = rnd.next(1, n);
		cout << n << " " << b << endl;
	}
}
