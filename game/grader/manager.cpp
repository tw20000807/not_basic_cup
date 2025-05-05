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
    auto play = [&]() -> int {
        if(sg[x] > sg[y]){
            for(int t : S){
                if(sg[x - t] == sg[y]){
                    x -= t;
                    return -t;
                }
            }
            assert(0);
        }
        else if(sg[x] < sg[y]){
            for(int t : S){
                if(sg[y - t] == sg[x]){
                    y -= t;
                    return t;
                }
            }
            assert(0);
        }
        else{
            if(x > y){
                x -= 1;
                return -1;
            }else{
                y -= 1;
                return 1;
            }
        }
    };
    int fir = 1;
    while(x != 0 || y != 0){
        int k;
        assert(fin >> k);
        if(k < 0)
            x -= -k;
        else if(k > 0){
            y -= k;
        }
        else{
            if(fir == 0){
                fout << "0" << endl;
                cout << "0" << endl;
                cerr << "k = 0 but is not first turn\n";
                exit(0);
            }
        }
        if(x == 0 && y == 0){
            fout << "0" << endl;
            cout << "1" << endl;
            cerr << "You Win\n";
            exit(0);
        }
        int ret = play();
        if(x == 0 && y == 0){
            fout << "0" << endl;
            cout << "0" << endl;
            cerr << "You Lose\n";
            exit(0);
        }
        else{
            fout << ret << endl;
        }
        fir = 0;
    }
    return -1;
}
