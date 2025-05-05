#include "sort.h"
#include <cassert>
#include <cstdio>
// BEGIN SECRET
#include <string>
// END SECRET

int main() {
	// BEGIN SECRET
	const std::string input_secret = "dtTwijelmkpC0UfnzAo20C6OsDtFMMdN";
	const std::string output_secret = "dSyoZytgdLGDi6jYVNTcHHaJXSEt9pU2";
	char secret[1000];
	assert(1 == scanf("%999s", secret));
	if (std::string(secret) != input_secret) {
		printf("%s\n", output_secret.c_str());
		printf("PV\n");
		printf("Possible tampering with the input\n");
		fclose(stdout);
		return 0;
	}
	// END SECRET
	int n;
	assert(1 == scanf("%d", &n));
	fclose(stdin);

	int res = min_val(n);

	// BEGIN SECRET
	printf("%s\n", output_secret.c_str());
	printf("OK\n");
	// END SECRET
	printf("%d\n", res);
	fclose(stdout);
	return 0;
}
