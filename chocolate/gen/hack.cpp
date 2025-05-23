#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int maxn = atoi(argv[1]);
	int c = atoi(argv[2]);
	vector< pair<int, int> > al;
    for(int i = 1; i < maxn; ++i){
		for(int j = 1; j <= i; ++j){
			al.push_back({i, j});
		}
	}
	cout << c << endl;
	cout << al.size() << endl;
	for(int i = 0; i < al.size(); ++i){
		cout << al[i].first << " " << al[i].second << endl;
	}
}
