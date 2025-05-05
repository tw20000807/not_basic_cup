#include "testlib.h"
using namespace std;

const string output_secret = "dSyoZytgdLGDi6jYVNTcHHaJXSEt9pU2";

int main(int argc, char* argv[]) {
	registerChecker("sort", argc, argv);
	readBothSecrets(output_secret);
	readBothGraderResults();
	compareRemainingLines(3);
}
