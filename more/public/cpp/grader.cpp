#include "grader.h"
#include <vector>
#include <algorithm>

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		int n, k;
		cin >> n >> k;
		vector< int > V(n), U(n + k);
		for(int i = 0; i < n; ++i) cin >> V[i];
		for(int i = 0; i < n + k; ++i) cin >> U[i];
		int rem = remember(V);
		vector< int > W = find(k, rem, U);
		copy(W.begin(), W.end(), back_inserter(V));
		sort(V.begin(), V.end());
		sort(U.begin(), U.end());
		if(V == U){
			cout << "testcase #" << i << " : OK\n";
		}
		else{
			cout << "testcase #" << i << " : Wrong Answer\n";
		}
		cout << rem << "\n";
		for(int i = 0; i < k; ++i) cout << W[i] << " \n"[i == k - 1];
	}
}
