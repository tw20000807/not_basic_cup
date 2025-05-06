#include "testlib.h"
#include <iostream>
#include <numeric>
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int n = atoi(argv[1]);
	int q = n;
	int maxn = 1e9;
	set< int > vis;
	vector< int > v, ask(n);
	while((int)v.size() < n){
		int x = rnd.next(-maxn, maxn);
		if(!vis.count(x)){
			vis.insert(x);
			v.push_back(x);
		}
	}
	iota(ask.begin(), ask.end(), 0);
	println(n, q);
	println(v);
	println(ask);
}
