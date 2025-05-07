#include "testlib.h"
using namespace std;

const string output_secret = "du3W59OSqKqC9FuBgxi0VkGO13qNOHq6";

int main(int argc, char* argv[]) {
	registerChecker("more", argc, argv);
	readBothSecrets(output_secret);
	compareRemainingLines(3);
}
