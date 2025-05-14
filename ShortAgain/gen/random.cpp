#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int k = rnd.next(0, n * (n - 1) / 2);
	println(n, k);
	return 0;
}
