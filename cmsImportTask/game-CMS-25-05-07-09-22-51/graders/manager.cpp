#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;
int mex(vector< int > &v){
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for(int i = 0; i < (int)v.size(); ++i){
        if(v[i] != i) return i;
    }
    return v.size();
}
int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, x, y;
    assert(cin >> n >> x >> y);
    vector< int > S(n);
    for(int i = 0; i < n; ++i){
        assert(cin >> S[i]);
    }

    fout << n << " " << x << " " << y << endl;
    for(int i = 0; i < n; ++i){
        fout << S[i] << endl;
    }
    --x, --y;
    vector< int > sg(max(x, y) + 1);
    {
        vector< int > tmp;
        for(int i = 0; i <= max(x, y); ++i){
            tmp.clear();
            for(int k : S){
                if(i - k < 0) break;
                tmp.push_back(sg[i - k]);
            }
            sg[i] = mex(tmp);
        }
    }
    while(fin >> x >> y){
        if(x == 1 && y == 1){
            cout << 1 << endl;
            cerr << "You Win" << endl;
            fout << 0 << endl;
            exit(0);
        }
        --x, --y;
        if(sg[x] == sg[y]){
            if(x > y) fout << -1 << endl;
            else fout << 1 << endl;
            continue;
        }
        int neg = 1;
        if(sg[x] > sg[y]) swap(x, y), neg = -1;
        for(int i : S){
            if(y - i >= 0 && sg[y - i] == sg[x]){
                if(x == 0 && y - i == 0){
                    cout << 0 << endl;
                    cerr << "You Lose\n";
                    exit(0);
                }
                fout << neg * i << endl;
                break;
            }
        }
    }
    return -1;
}
