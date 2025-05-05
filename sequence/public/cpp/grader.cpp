#include "sort.h"
#include <cassert>
#include <cstdio>

int main() {
	int n;
	assert(1 == scanf("%d", &n));
	fclose(stdin);

	int res = min_val(n);

	printf("%d\n", res);
	fclose(stdout);
	return 0;
}
