#include "testlib.h"
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
    int inv = atoi(argv[2]);
	std::vector< int > v(n);
	std::iota(v.begin(), v.end(), 1);
	if(inv) std::reverse(v.begin(), v.end());
	println(n);
	println(v);
	return 0;
}
