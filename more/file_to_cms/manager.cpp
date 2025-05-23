#include "more.h"
#include <cassert>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
// BEGIN SECRET
#include <string>
const std::string input_secret = "xBKhCirDv7dWDvJlxKTtuZimwF4Zi9x1";
const std::string output_secret = "du3W59OSqKqC9FuBgxi0VkGO13qNOHq6";
// END SECRET
using namespace std;
void pass1(char* pipe_path){
	ofstream fout(pipe_path);
	string secret;
	assert(cin >> secret);
	int T, n, k;
	assert(cin >> T);
	fout << secret << "\n";
	fout << T << "\n";
	for(int t = 1; t <= T; ++t){
		assert(cin >> n >> k);
		vector<int> v1(n), v2(n + k);
		for(int i = 0; i < n; ++i){
			assert(cin >> v1[i]);
		}
		for(int i = 0; i < n + k; ++i){
			assert(cin >> v2[i]);
		}
		long long ret = remember(v1);
		fout << ret << "\n";
		fout << n << "\n";
		fout << k << "\n";
		for(int i = 0; i < n + k; ++i){
			fout << v2[i] << " \n"[i == n + k - 1];
		}
	}
}

void pass2(char *pipe_path){
	ifstream fin(pipe_path);
	// BEGIN SECRET
	string secret;
	assert(fin >> secret);
	if (secret != input_secret) {
		cout << output_secret << "\n";
		cout << "PV\n";
		cout << "Possible tampering with the input\n";
		return ;
	}
	// END SECRET
	long long ret;
	int T, n, k;
	cout << output_secret << "\n";
	assert(fin >> T);
	for(int t = 1; t <= T; ++t){
		assert(fin >> ret);
		assert(fin >> n);
		assert(fin >> k);
		vector<int> v(n + k);
		for(int i = 0; i < n + k; ++i){
			assert(fin >> v[i]);
		}
		vector<int> ans = find(k, ret, v);
		assert((int)ans.size() == k);
		sort(ans.begin(), ans.end());
		for(int i = 0; i < k; ++i){
			cout << ans[i] << " \n"[i == k - 1];
		}
	}
}
int main(int argc, char* argv[]) {
	if (argc < 3) {
		cout << "invalid arguments" << endl;
		return 1;
	}
	int type = atoi(argv[1]);
	if(type == 0){
		pass1(argv[2]);
	}
	else{
		pass2(argv[2]);
	}
	return 0;
}
