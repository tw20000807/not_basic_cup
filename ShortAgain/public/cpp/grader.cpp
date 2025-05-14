#include "ShortAgain.h"
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

struct BIT{
	vector< int > tree;
	int n;
	BIT(int N){
		n = N;
		tree.resize(N + 2);
	}
	void modify(int id, int val){for(; id <= n; id += id&-id) tree[id] += val;}
	int query(int id){
		int re = 0;
		for(; id; id-=id&-id) re += tree[id];
		return re;
	}
};
int main() {
	int n, k;
	assert(cin >> n >> k);
	vector<int> result = construct(n, k);
	assert(result.size() == n);
	vector< int > vis(n + 1);
	for (int i = 0; i < n; ++i) {
		assert(result[i] >= 1 && result[i] <= n);
		assert(vis[result[i]] == 0);
		vis[result[i]] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		assert(vis[i] == 1);
	}
	int cnt = 0;
	BIT bit(n);
	for(int i = n - 1; i >= 0; --i) {
		cnt += bit.query(result[i]);
		bit.modify(result[i], 1);
	}
	if(cnt == k){
		cout << "OK" << endl;
	}
	else{
		cout << "WA" << endl;
	}
}