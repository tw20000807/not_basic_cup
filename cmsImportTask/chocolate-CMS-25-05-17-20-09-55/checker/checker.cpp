#include "testlib.h"
using namespace std;

const string output_secret = "UUHvViSbOcm1f20T0qa9HbSlGWAR2d3H";

int main(int argc, char* argv[]) {
	registerChecker("fortune", argc, argv);
	readBothSecrets(output_secret);
	inf.readLine(); // secret
	int c = inf.readInt();
	int T = ouf.readInt();
	int mx = 0;
	for(int i = 1; i <= T; ++i){
		string result = ouf.readToken();
		if(result != "OK"){
			quit(_wa);
		}
		int len = ouf.readInt();
		mx = max(mx, len);
	}
	if(c == 1){
		if(mx <= 5) quit(_ok);
		else if(mx <= 15) quitp(0.5);
		else quit(_wa);
	}
	else if(c == 2){
		if(mx <= 9) quit(_ok);
		else if(mx <= 19) quitp(0.5);
		else quit(_wa);
	}
	else if(c == 3){
		if(mx <= 10) quit(_ok);
		else if(mx <= 20) quitp(0.5);
		else quit(_wa);
	}
	else quitf(_fail, "grader wrong");
}
