#include "short.h"
#include <cassert>
#include <iostream>
using namespace std;
int main() {
	int n;
	assert(cin >> n);
	std::vector< int > v(n);
	for(int i = 0; i < n; ++i){
		assert(cin >> v[i]);
	}
	std::vector< int > res = construct(v);
	assert((int)res.size() == n);
	std::vector< bool > vis(n + 1);
	for(int i = 0; i < n; ++i){
		assert(res[i] > 0);
		assert(res[i] <= n);
		assert(!vis[res[i]]);
		vis[res[i]] = 1;
	}


	for(int i = 0; i < n; ++i){
		cout << res[i] << " \n"[i == n - 1];
	}
	return 0;
}
