#include "sequence.h"
#include <iostream>
#include <vector>
using namespace std;

vector< int > v;
void bob_init(int n){
	v.resize(n, compare_numbers(0, 1, 2));
}

int query_from_alice(int a){
	return v[a];
}
