#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
int main() {
	int n, m;
	cin >> n >> m;
	vector< vector< int > > id(n, vector< int >(m));
	vector< vector< int > > grid(n, vector< int >(m));
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		cin >> grid[i][j];
		id[i][j] = i * m + j;
	}
	auto in_map = [&](int x, int y) -> bool {
		return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != -1;
	};
	vector< vector< int > > g(n * m);
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) if(grid[i][j] != -1) {
		for(int t = 0; t < 4; ++t){
			int nx = i + dx[t];
			int ny = j + dy[t];
			if(in_map(nx, ny)){
				g[id[i][j]].push_back(id[nx][ny]);
			}
		}
	}
	vector< int > vis(n * m), nxt(n * m, -1);
	auto dfs = [&](auto dfs, int cur) -> bool {
		vis[cur] = 1;
		for(auto &k : g[cur]){
			if(nxt[k] == -1 || (!vis[nxt[k]] && dfs(dfs, nxt[k]))){
				nxt[k] = cur;
				return 1;
			}
		}
		return 0;
	};
	
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		if((i ^ j) & 1){
			fill(vis.begin(), vis.end(), 0);
			dfs(dfs, id[i][j]);
		}
	}

	int tag = 0;
	for(int i = 0; i < n * m; ++i){
		if(nxt[i] != -1){
			int x = i / m, y = i % m;
			int nx = nxt[i] / m, ny = nxt[i] % m;
			grid[x][y] = grid[nx][ny] = ++tag;
		}
	}
	
	cout << tag << "\n";
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		cout << grid[i][j] << " \n"[j == m - 1];
	}
}
