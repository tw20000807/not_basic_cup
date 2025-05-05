#include<bits/stdc++.h>
int Bla(int n, std::string s){
	if(!count(s.begin(), s.end(), 'B')){
		return n - (int)s.size();
	}
	for(auto &k : s) k = '0' + (k == 'B');
	return stoll(s, 0, 2);
}