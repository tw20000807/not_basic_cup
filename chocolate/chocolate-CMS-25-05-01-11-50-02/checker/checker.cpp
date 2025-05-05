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
	if(c == 1) quitp(max(0.0, 30 - 6 * pow(mx - 5, 1.82)) / 30);
	else if(c == 2) quitp(max(0.0, 30 - 7 * pow(2 * mx - 18, 1.62)) / 30);
	else if(c == 3) quitp(max(0.0, (40 - pow(3 * mx - 30, 2.14))) / 40);
	else quitf(_fail, "grader wrong");
}
