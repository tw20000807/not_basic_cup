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
int die(string res){
    cout << 0 << endl;
    cerr << res << endl;
    exit(0);
}
vector< int > S, sg;
int judge_play(int x, int y){
    if(x == 1 && y == 1){
        cout << 1 << endl;
        cerr << "You Win" << endl;
        exit(0);
    }
    --x, --y;
    if(sg[x] == sg[y]){
        if(x > y) return -1;
        else return 1;
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
            return neg * i;
        }
    }
    cout << 0 << endl;
    cerr << "Unknown error\n";
    exit(0);
}
void Move(int &x, int &y, int k){
    if(k < 0) x -= -k;
    else y -= k;
    if(!(x > 0 && y > 0)){
        cout << 0 << endl;
        cerr << "Invalid Move, out of board\n";
        exit(0);
    }
}
int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, x, y;
    if(!(cin >> n >> x >> y)){
        die("can not read n, x, y");
    }
    S.resize(n);
    sg.resize(max(x, y) + 1);
    for(int i = 0; i < n; ++i){
        if(!(cin >> S[i])){
            die("can not read S");
        }
    }
    fout << n << " " << x << " " << y << endl;
    for(int i = 0; i < n; ++i){
        fout << S[i] << endl;
    }
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
    int fir;
    if(!(fin >> fir)){
        die("can not read fir");
    }
    if(fir == 0){
        int k = judge_play(x, y);
        Move(x, y, k);
    }
    while(true){
        fout << x << " " << y << endl;
        int k;
        if(!(fin >> k)){
            die("can not read k");
        }
        if(!count(S.begin(), S.end(), abs(k))){
            die("Invalid Move, |k| not in S");
        }
        Move(x, y, k);
        k = judge_play(x, y);
        Move(x, y, k);
    }
}
