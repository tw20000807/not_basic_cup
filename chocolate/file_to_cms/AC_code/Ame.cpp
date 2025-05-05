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
