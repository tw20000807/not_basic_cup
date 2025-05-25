#include "sequence.h"
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

namespace{
	int n, q, query_times = 0;
	vector< int > v;
}
int compare_numbers(int i, int j, int k){
	query_times++;
	if(!(0 <= i && i < n)){
        cerr << "i out of range" << endl;
        exit(0);
    }
    if(!(0 <= j && j < n)){
        cerr << "j out of range" << endl;
        exit(0);
    }
    if(!(0 <= k && k < n)){
        cerr << "k out of range" << endl;
        exit(0);
    }
    if(i == j || i == k || j == k){
        cerr << "i, j, k must be different" << endl;
        exit(0);
    }
	if(v[i] > v[j]) swap(i, j);
	if(v[i] > v[k]) swap(i, k);
	if(v[j] > v[k]) swap(j, k);
	return v[j];
}
int main() {
	assert(cin >> n >> q);
	v = vector< int > (n);
	for(int i = 0; i < n; ++i){
		assert(cin >> v[i]);
	}
	vector< int > ask(q);
	for(int i = 0; i < q; ++i){
		assert(cin >> ask[i]);
	}
	fclose(stdin);
	bob_init(n);
	int ver = 1;
	int mx = *max_element(v.begin(), v.end());
	int mn = *min_element(v.begin(), v.end());
	for(int i = 0; i < q; ++i){
		int a = ask[i];
		int pa = query_from_alice(a);
		if(v[a] == mx || v[a] == mn) continue;
		if(pa != v[a]){
			cerr <<"p[" << a << "] = " << v[a] << " " << "you answer " << pa << "\n";
			ver = 0;
		}
	}
	if(ver){
		cout << "OK\n";
		cout << query_times << "\n";
	}
	else{
		cout << "WA\n";
		cout << query_times << "\n";
	}
	return 0;
}
