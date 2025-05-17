#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerChecker("cover", argc, argv);
	int n = inf.readInt(), m = inf.readInt();
	int cnt = ouf.readInt(0, n * m);
	int opt = ans.readInt();
	vector< vector< int > > grid(n, vector< int >(m));
	cerr << "k : " << cnt << " T : " << opt << "\n";
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		grid[i][j] = ouf.readInt(-1, cnt);
		int x = inf.readInt();
		if(x == -1 && grid[i][j] != -1){
			quitf(_wa, "in input, (%d, %d) is -1, but you isn't\n", i, j);
		}
	}
	vector< int > vis(cnt + 1);
	for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
		if(grid[i][j] > 0){
			if(vis[grid[i][j]]){
				quitf(_wa, "index %d appear more than once, %d, %d\n", grid[i][j], i, j);
			}
			vis[grid[i][j]] = 1;
			if(i + 1 < n && grid[i + 1][j] == grid[i][j]){
				grid[i + 1][j] = grid[i][j] = 0;
			}
			else if(j + 1 < m && grid[i][j + 1] == grid[i][j]){
				grid[i][j + 1] = grid[i][j] = 0;
			}
			if(grid[i][j] > 0){
				quitf(_wa, "Invalid put format\n");
			}
		}
	}
	for(int i = 1; i <= cnt; ++i) if(!vis[i]){
		quitf(_wa, "grid didn't have %d\n");
	}
	if(opt - cnt <= 4) quitp(0.5 + 1.0 / (2.0 + 2.0 * (opt - cnt)));
	else if(opt <= cnt * 2) quitp((0.6 * cnt) / opt);
	else quit(_wa);
}
