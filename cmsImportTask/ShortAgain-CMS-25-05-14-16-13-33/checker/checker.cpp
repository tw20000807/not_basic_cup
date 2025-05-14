#include "testlib.h"
using namespace std;

int main(int argc, char* argv[]) {
	registerChecker("inverse", argc, argv);
	string secret = ouf.readLine();
	if(secret != "blame"){
		quit(_fail);
	}
	string s = ouf.readLine();
	if(s == "OK"){
		quit(_ok);
	}
	else{
		quit(_wa);
	}
}
