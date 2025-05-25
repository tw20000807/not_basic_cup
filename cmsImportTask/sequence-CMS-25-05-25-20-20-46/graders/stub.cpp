#include "sequence.h"
#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int n, q;
ofstream fout;
ifstream fin;
int compare_numbers(int i, int j, int k){
	fout << "q " << i << " " << j << " " << k << endl;
	int t;
	if(!(fin >> t)){
		cerr << "can not read compare_numbers" << endl;
		exit(0);
	}
	return t;
}
int main(int argc, char *argv[]) {
	fout.open(argv[2]);
	fin.open(argv[1]);
	if(!(fin >> n >> q)){
		cerr << "can not read n, q" << endl;
		exit(0);
	}
	bob_init(n);
	fout << "start_query" << endl;
	for(int i = 0; i < q; ++i){
		int p;
		if(!(fin >> p)){
			cerr << "can not read p" << endl;
			exit(0);
		}
		int t = query_from_alice(p);
		fout << t << endl;
	}
	return 0;
}
