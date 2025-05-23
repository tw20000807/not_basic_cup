#include<bits/stdc++.h>
#define int long long
#define all(v) v.begin(), v.end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
#define X first
#define Y second

using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;//    998244353;
const int llmx = 1e18;

int n, m;
void build(int now, int nxt, int id, int cnt, int put, vector< array<int, 3> > &v){
    if(id == n){
        v.push_back({nxt, cnt, put});
        return;
    }
    if(!(now >> id & 1) && !(nxt >> id & 1))
        build(now | (1 << id), nxt | (1 << id), id + 1, cnt + 1, put | (1 << id), v);
    if(id + 1 < n && !(now >> id & 1) && !(now >> (id + 1) & 1))
        build(now | (1 << id) | (1 << (id + 1)), nxt, id + 2, cnt + 1, put | (1 << (id + n)), v);
    if(id == 0 || (now >> (id - 1) & 1) || (now >> id & 1))
        build(now, nxt, id + 1, cnt, put, v);
}
void sol(){
    cin >> n >> m;
    vector< vector< int > > v(n, vector< int >(m + 2, -1));
    for(int i = 0; i < n; ++i) for(int j = 1; j <= m; ++j) cin >> v[i][j];
    vector< vector< array<int, 3> > > dp(m + 2, vector< array<int, 3> >(1 << n, array<int, 3>{-llmx, -1, -1}));
    dp[0][(1 << n) - 1] = {0, -1, -1};
    for(int i = 0; i <= m; ++i){
        int nxt = 0;
        for(int k = 0; k < n; ++k) if(v[k][i + 1] == -1) nxt |= (1 << k);
        for(int j = 0; j < (1 << n); ++j) if(dp[i][j][0] >= 0) {
            vector< array<int, 3> > tmp;
            build(j, nxt, 0, 0, 0, tmp);
            for(auto [mask, cnt, put] : tmp){
                assert(__builtin_popcount(put) == cnt);
                dp[i + 1][mask] = max(dp[i + 1][mask], array<int, 3>{dp[i][j][0] + cnt, put, j});
            }
        }
    }
    int dfn = 0;
    int now = (1 << n) - 1;
    for(int i = m; i > 0; --i){
        int put = dp[i + 1][now][1];
        if(now == -1) break;
        for(int j = 0; j < n; ++j) if(put >> j & 1){
            v[j][i] = v[j][i + 1] = ++dfn;
        }
        for(int j = 0; j < n - 1; ++j) if(put >> (j + n) & 1){
            v[j][i] = v[j + 1][i] = ++dfn;
        }
        now = dp[i + 1][now][2];
    }
    cout << dfn << "\n";
    for(int i = 0; i < n; ++i) for(int j = 1; j <= m; ++j) cout << v[i][j] << " \n"[j == m];
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}