#include "sequence.h"
#include <cassert>
#include <vector>
#include <iostream>
using namespace std;

namespace{
	const std::string input_secret = "dtTwijelmkpC0UfnzAo20C6OsDtFMMdN";
	const std::string output_secret = "dSyoZytgdLGDi6jYVNTcHHaJXSEt9pU2";
	int n, q, query_times = 0;
	vector< int > v;
}
int compare_numbers(int i, int j, int k){
	query_times++;
	assert(0 <= i && i < n);
	assert(0 <= j && j < n);
	assert(0 <= k && k < n);
	assert(i != j);
	assert(i != k);
	assert(j != k);
	if(v[i] > v[j]) swap(i, j);
	if(v[i] > v[k]) swap(i, k);
	if(v[j] > v[k]) swap(j, k);
	return v[j];
}
int main() {
	// BEGIN SECRET
	string secret;
	assert(cin >> secret);
	if (secret != input_secret) {
		cout << output_secret << "\n";
		cout << "PV\n";
		return 0;
	}
	// END SECRET

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
	for(int i = 0; i < q; ++i){
		int a = ask[i];
		int pa = query_from_alice(a);
		if(pa != v[a]) ver = 0;
	}
	cout << output_secret << "\n";
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
