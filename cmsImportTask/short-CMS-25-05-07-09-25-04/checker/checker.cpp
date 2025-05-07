#include "testlib.h"
using namespace std;

const string output_secret = "gCf9Urk7brY9n0BAGoLGC2RnqQx0ZL06";

int main(int argc, char* argv[]) {
	registerChecker("rearrange", argc, argv);
	readBothSecrets(output_secret);
	readBothGraderResults();

	inf.readLine(); //secret
	int n = inf.readInt();
	for(int i = 0; i < n; ++i){
		int a = ouf.readInt();
		int b = inf.readInt();
		if(a == b){
			quit(_wa, "v[i] == r[i]");
		}
	}
	quit(_ok);
}
