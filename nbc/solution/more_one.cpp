#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	int k = __lg(n - 1) + 1;
	vector< vector< int > > v(k, vector< int >(n, -1));
	auto dfs = [&](auto dfs, int dep, int l, int r, int x = 0) -> void {
		// cerr << dep << " " << l << " " << r << " " << t << "\n";
		if(l == r){
			return;
		}
		int mid = (l + r) >> 1;
		for(int i = l; i <= mid; ++i){
			v[dep][i] = x;
		}
		for(int i = mid + 1; i <= r; ++i){
			v[dep][i] = x ^ 1;
		}
		dfs(dfs, dep + 1, l, mid, x);
		dfs(dfs, dep + 1, mid + 1, r, x ^ 1);
	};
	dfs(dfs, 0, 0, n - 1);

	cout << k + 1 << "\n";
	for(int t = 0; t < k; ++t){
		vector< int > l, r;
		for(int j = 0; j < n; ++j){
			if(v[t][j] == 0) l.push_back(j);
			if(v[t][j] == 1) r.push_back(j);
		}
		assert(l.size() == r.size());
		cout << l.size() << "\n";
		for(int i = 0; i < (int)l.size(); ++i) cout << l[i] << " \n"[i + 1 == (int)l.size()];
		for(int i = 0; i < (int)r.size(); ++i) cout << r[i] << " \n"[i + 1 == (int)r.size()];
	}
    for(int t = 0; t < 1; ++t){
		vector< int > l, r;
		for(int j = 0; j < n; ++j){
			if(v[t][j] == 0) l.push_back(j);
			if(v[t][j] == 1) r.push_back(j);
		}
		assert(l.size() == r.size());
		cout << l.size() << "\n";
		for(int i = 0; i < (int)l.size(); ++i) cout << l[i] << " \n"[i + 1 == (int)l.size()];
		for(int i = 0; i < (int)r.size(); ++i) cout << r[i] << " \n"[i + 1 == (int)r.size()];
	}
}
/*
0 49
*/