#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), m = atoi(argv[2]);
	int t = atoi(argv[3]);
	cout << n << " " << m << "\n";
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		int x = ((i + j) & 1) ? -1 : 0;
		cout << x << " \n"[j == m - 1];
	}
}
