#include <bits/stdc++.h>
using namespace std;
std::string Ame(int n, int b){
	int hi = __lg(b) + 1;
	string ret(hi, 'W');
	for(int i = 0; i < hi; ++i){
		if(b >> i & 1) ret[i] = 'B';
	}
	reverse(ret.begin(), ret.end());
	int need_w = count(ret.begin(), ret.end(), 'W');
	if(need_w > n - b){
		return string(n - b, 'W');
	}
	return ret;
}
int Bla(int n, std::string s){
	if(!count(s.begin(), s.end(), 'B')){
		return n - (int)s.size();
	}
	for(auto &k : s) k = '0' + (k == 'B');
	return stoll(s, 0, 2);
}