#include "rearrange.h"
#include <cassert>
#include <iostream>
// BEGIN SECRET
#include <string>
// END SECRET
using namespace std;
int main() {
	// BEGIN SECRET
	const std::string input_secret = "SX4sl1lxDFZr39zzEnirMRn9hy1cLOWa";
	const std::string output_secret = "gCf9Urk7brY9n0BAGoLGC2RnqQx0ZL06";
	string secret;
	assert(cin >> secret);
	if(secret != input_secret) {
		cout << output_secret << "\n";
		cout << "PV\n";
		cout << "Possible tampering with the input\n";
		return 0;
	}
	// END SECRET
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

	// BEGIN SECRET
	cout << output_secret << "\n";
	cout << "OK\n";
	// END SECRET

	for(int i = 0; i < n; ++i){
		cout << res[i] << " \n"[i == n - 1];
	}
	return 0;
}
