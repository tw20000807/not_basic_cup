#include "grader.h"
#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
int main() {
	int T;
	std::cin >> T;
	for(int t = 1; t <= T; ++t){
		int n, k;
		std::cin >> n >> k;
		std::vector< int > V(n), U(n + k);
		for(int i = 0; i < n; ++i) std::cin >> V[i];
		for(int i = 0; i < n + k; ++i) std::cin >> U[i];
		long long r = remember(V);
		std::vector< int > W = find(k, r, U);
		assert((int)W.size() == k);
		std::copy(W.begin(), W.end(), std::back_inserter(V));
		std::sort(V.begin(), V.end());
		std::sort(U.begin(), U.end());
		if(V == U){
			std::cout << "testcase #" << t << " : OK\n";
		}
		else{
			std::cout << "testcase #" << t << " : Wrong Answer\n";
		}
		std::cout << r << "\n";
		for(int i = 0; i < k; ++i) std::cout << W[i] << " \n"[i == k - 1];
	}
}
