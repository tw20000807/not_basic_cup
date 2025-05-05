#include "manager.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <fstream>

// BEGIN SECRET
#include <string>
const std::string input_secret = "dmv7A5gYlPmjptJm7mx15JsQPSMiOxJQ";
const std::string output_secret = "UUHvViSbOcm1f20T0qa9HbSlGWAR2d3H";
// END SECRET
using namespace std;

void pass1(char* pipe_path){
	ofstream fout(pipe_path);

	// BEGIN SECRET
	string secret;
	assert(cin >> secret);
	if (secret != input_secret) {
		cout << output_secret << "\n";
		cout << "PV\n";
		cout << "Possible tampering with the input\n";
		return;
	}
	// END SECRET
	int c, T;
	assert(cin >> c >> T);
	fout << input_secret << "\n";
	fout << T << "\n";
	for(int t = 0; t < T; ++t){
		int n, b;
		assert(cin >> n >> b);
		string s = Ame(n, b);
		int s_b = count(s.begin(), s.end(), 'B');
		int s_w = count(s.begin(), s.end(), 'W');
		assert(s_b <= b);
		assert(s_w <= n - b);
		assert(s_b + s_w == (int)s.size());
		fout << n << " " << b << "\n";
		fout << s.size() << "\n";
		fout << s << "\n";
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
		return;
	}
	// END SECRET
	int T;
	assert(fin >> T);
	cout << output_secret << "\n";
	cout << T << "\n";
	for(int t = 0; t < T; ++t){
		int n, o;
		string s = "";
		assert(fin >> n >> o);
		int sz;
		assert(fin >> sz);
		if(sz) assert(fin >> s);
		int ans = Bla(n, s);
		if(ans != o){
			cout << "WA\n";
		}
		else{
			cout << "OK\n";
			cout << s.size() << "\n";
		}
	}
}

int main(int argc, char *argv[]) {
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
