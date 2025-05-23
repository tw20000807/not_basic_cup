#include "testlib.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int maxn = (1 << 30);
	int T = atoi(argv[1]), n = atoi(argv[2]), k = atoi(argv[3]);
	println(T);
    for(int tt = 0; tt < T; ++tt) {
        vector<int> v2(n);
        for(int i = 0; i < n; ++i) v2[i] = rnd.next(1, maxn);
        vector<int> v1(v2.begin(), v2.end() - k);
        println(n - k, k);
        println(v1);
        println(v2);
    }
	return 0;
}
