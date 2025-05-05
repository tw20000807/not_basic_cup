#include <iostream>
#include <set>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int T = 1;
	int n = atoi(argv[1]), k = atoi(argv[2]);
	set<int> vis;
	vector<int> v2;
	while((int)v2.size() < n){
		int x = rnd.next(0, INT_MAX);
		if(!vis.count(x)){
			vis.insert(x);
			v2.push_back(x);
		}
	}
	vector<int> v1(v2.begin() + k, v2.end());
	shuffle(v1.begin(), v1.end());
	println(T);
	println(n - k, k);
	println(v1);
	println(v2);
	return 0;
}
