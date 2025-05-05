#include "grader.h"
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;
int main() {
	int T;
	assert(cin >> T);
	for(int t = 1; t <= T; ++t){
		int n, b;
		assert(cin >> n >> b);
		string tmp = Ame(n, b);
		int B_cnt = count(tmp.begin(), tmp.end(), 'B');
		int W_cnt = count(tmp.begin(), tmp.end(), 'W');
		assert(B_cnt <= b);
		assert(W_cnt <= n - b);
		assert(B_cnt + W_cnt == tmp.size());
		int ret = Bla(n, tmp);
		cout << "test case #" << t << " : " << (ret == b ? "OK" : "WA") << "\n";
		cout << "Ame : " << tmp << "\n";
		cout << "Bla : " << ret << "\n";
	}
}
