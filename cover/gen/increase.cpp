#include <iostream>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]), m = atoi(argv[2]);
	int t = atoi(argv[3]);
	cout << n << " " << m << "\n";
    vector< int > v(n);
    v[0] = 1;
    for(int i = 1; i < n; ++i){
        v[i] = v[i - 1] + rnd.next(0, 2);
    }
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		cout << (j < v[i] ? 0 : -1) << " \n"[j == m - 1];
	}
}
