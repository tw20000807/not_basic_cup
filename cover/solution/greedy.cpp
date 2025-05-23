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

void sol(){
    int n, m;
    cin >> n >> m;
    vector< vector< int > > v(n, vector< int >(m));
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) cin >> v[i][j];
    int id = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
        if(j + 1 < m && v[i][j] == 0 && v[i][j + 1] == 0) v[i][j] = v[i][j + 1] = ++id;
        if(i + 1 < n && v[i][j] == 0 && v[i + 1][j] == 0) v[i][j] = v[i + 1][j] = ++id;
    }
    cout << id << "\n";
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j){
        cout << v[i][j] << " \n"[j == m - 1];
    }
}
/*


*/
signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cerr.tie(0);
    int t = 1; //cin >> t;
    while(t--) sol();
}