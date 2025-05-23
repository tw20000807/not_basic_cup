#include "testlib.h"
using namespace std;

const string output_secret = "du3W59OSqKqC9FuBgxi0VkGO13qNOHq6";

int main(int argc, char* argv[]) {
	registerChecker("more", argc, argv);
	readBothSecrets(output_secret);
	inf.readLine(); // input secret
	int T = inf.readInt();
	for(int t = 1; t <= T; ++t) {
		int n = inf.readInt();
		int k = inf.readInt();
		vector<int> v1(n), v2(n + k);
		for(int i = 0; i < n; ++i) {
			v1[i] = inf.readInt();
		}
		for(int i = 0; i < n + k; ++i) {
			v2[i] = inf.readInt();
		}
		multiset<int> ans(v2.begin(), v2.end());
		for(int i = 0; i < n; ++i) {
			ans.erase(ans.find(v1[i]));
		}
		if((int)ans.size() != k) quit(_fail);
		vector< int > out(k);
		for(int i = 0; i < k; ++i){
			out[i] = ouf.readInt();
			if(!ans.count(out[i])){
				quit(_wa);
			}
			ans.erase(ans.find(out[i]));
		}
	}
	quit(_ok);
}
