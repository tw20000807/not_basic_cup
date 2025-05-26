#include "testlib.h"
#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
    int r = atoi(argv[2]);
	int q = n;
	int maxn = 1e9;
	set< int > vis;
	vector< int > v(n), ask(n);
	iota(v.begin(), v.end(), 0);
	iota(ask.begin(), ask.end(), 0);
    if(r == 1) reverse(v.begin(), v.end());
	println(n, q);
	println(v);
	println(ask);
}
