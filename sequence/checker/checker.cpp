#include "testlib.h"
using namespace std;

const string output_secret = "dSyoZytgdLGDi6jYVNTcHHaJXSEt9pU2";

int main(int argc, char* argv[]) {
	registerChecker("sort", argc, argv);
	readBothSecrets(output_secret);
	string ret;
	ret = ouf.readLine();
	inf.readLine(); //secret
	int n = inf.readInt();
	if(ret == "OK"){
		int x = ouf.readInt();
		int Q = (x - 1) / n + 1
		if(Q <= 9) quitp((100.0 - max(0, 3 * Q - 9)) / 100);
		else if(Q <= 500) quitp(2.46 / sqrt(Q));
		else quit(_wa);
	}
	else if(ret == "WA"){
		quitf(_wa, "wrong answer");
	}
	else{
		quitf(_fail, "unknow result");
	}
}
