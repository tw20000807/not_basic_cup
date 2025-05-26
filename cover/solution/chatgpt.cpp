#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int n, m;
vector<vector<int>> board;
vector<vector<int>> id;
vector<vector<int>> result;

int match_count = 0;
int label = 1;

struct Pos {
    int x, y;
};

vector<vector<Pos>> g;
vector<int> match_to;
vector<bool> visited;

int node(int x, int y) {
    return x * m + y;
}

bool dfs(int u) {
    for (auto& v : g[u]) {
        int vid = node(v.x, v.y);
        if (visited[vid]) continue;
        visited[vid] = true;
        if (match_to[vid] == -1 || dfs(match_to[vid])) {
            match_to[vid] = u;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    board.assign(n, vector<int>(m));
    id.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> board[i][j];

    g.resize(n * m);
    result.assign(n, vector<int>(m, -1));

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 0 && (i + j) % 2 == 0) {
                for (int d = 0; d < 4; ++d) {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m && board[ni][nj] == 0) {
                        g[node(i, j)].push_back({ni, nj});
                    }
                }
            }
        }

    match_to.assign(n * m, -1);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if ((i + j) % 2 == 0 && board[i][j] == 0) {
                visited.assign(n * m, false);
                if (dfs(node(i, j))) {
                    match_count++;
                }
            }

    // assign labels to matched pairs
    int color = 1;
    vector<vector<bool>> used(n, vector<bool>(m, false));
    for (int v = 0; v < n * m; ++v) {
        if (match_to[v] != -1) {
            int ux = match_to[v] / m, uy = match_to[v] % m;
            int vx = v / m, vy = v % m;
            if (!used[ux][uy] && !used[vx][vy]) {
                result[ux][uy] = result[vx][vy] = color++;
                used[ux][uy] = used[vx][vy] = true;
            }
        }
    }

    cout << match_count << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == -1)
                cout << -1;
            else if (result[i][j] > 0)
                cout << result[i][j];
            else
                cout << 0;
            if (j + 1 < m) cout << " ";
        }
        cout << "\n";
    }

    return 0;
}
