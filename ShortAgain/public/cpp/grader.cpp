#include "ShortAgain.h"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	assert(cin >> n >> k);
	vector<int> result = construct(n, k);
	assert((int)result.size() == n);
	vector< int > vis(n + 1);
	for (int i = 0; i < n; ++i) {
		assert(result[i] >= 1 && result[i] <= n);
		assert(vis[result[i]] == 0);
		vis[result[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) 
		assert(vis[i] == 1);
	int cnt = 0;
	for(int i = 0; i < n; ++i) 
		for (int j = i + 1; j < n; ++j) 
			cnt += (result[i] > result[j])
	if(cnt == k)
		cout << "OK" << endl;
	else
		cout << "WA" << endl;
}