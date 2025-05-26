#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

int n, q, query_times = 0;
vector< int > v;
int compare_numbers(int i, int j, int k){
	query_times++;
	if(!(0 <= i && i < n)){
        cerr << "i out of range" << endl;
        cout << 0 << endl;
        exit(0);
    }
    if(!(0 <= j && j < n)){
        cerr << "j out of range" << endl;
        cout << 0 << endl;
        exit(0);
    }
    if(!(0 <= k && k < n)){
        cerr << "k out of range" << endl;
        cout << 0 << endl;
        exit(0);
    }
    if(i == j || i == k || j == k){
        cerr << "i, j, k must be different" << endl;
        cout << 0 << endl;
        exit(0);
    }
	if(v[i] > v[j]) swap(i, j);
	if(v[i] > v[k]) swap(i, k);
	if(v[j] > v[k]) swap(j, k);
	return v[j];
}

int main(int argc, char *argv[]){
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
	assert(cin >> n >> q);
	v = vector< int > (n);
	for(int i = 0; i < n; ++i){
		assert(cin >> v[i]);
	}
	vector< int > ask(q);
	for(int i = 0; i < q; ++i){
		assert(cin >> ask[i]);
	}
    fout << n << " " << q << endl;

    while(true){
        string s;
        if(!(fin >> s)){
            cerr << "can not read s" << endl;
            cout << 0 << endl;
            exit(0);
        }
        if(s == "start_query") break;
        if(s != "q"){
            cerr << "unknow query" << endl;
            cout << 0 << endl;
            exit(0);
        }
        int i, j, k;
        if(!(fin >> i >> j >> k)){
            cerr << "can not read i, j, k" << endl;
            cout << 0 << endl;
            exit(0);
        }
        int ret = compare_numbers(i, j, k);
        fout << ret << endl;
        if(query_times > 500 * n){
            cout << 0 << endl;
            cerr << "query times exceed" << endl;
            exit(0);
        }
    }
	int mx = *max_element(v.begin(), v.end());
	int mn = *min_element(v.begin(), v.end());
	for(int i = 0; i < q; ++i){
		int a = ask[i];
		fout << a << endl;
        int ret; 
        if(!(fin >> ret)){
            cerr << "can not read ret" << endl;
            cout << 0 << endl;
            exit(0);
        }
		if(v[a] == mx || v[a] == mn) continue;
		if(ret != v[a]){
			cerr << "wrong answer" << endl;
			cout << 0 << endl;
            exit(0);
		}
	}
    int Q = (query_times + n - 1) / n;
    cerr << "query times : " << query_times << endl;
    if(Q > 500){
        cerr << "query times exceed" << endl;
        cout << 0 << endl;
        exit(0);
    }
    else if(Q >= 9){
        cerr << "Q : " << Q << endl;
        cout << 2.46 * sqrt(Q) << endl;
    }
    else if(Q >= 3){
        cerr << "Q : " << Q << endl;
        cout << (109.0 - 3.0 * Q) / 100.0 << endl;
    }
    else{
        cerr << "Q : " << Q << endl;
        cout << 1.0 << endl;
    }
	return 0;
}
