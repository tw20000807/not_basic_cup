#include "rearrange.h"
#include <vector>
#include <algorithm>
int n;
std::vector<int> construct(const std::vector<int> v) {
	n = v.size();
	std::vector<int> r = v;
	std::random_shuffle(r.begin(), r.end());
	return r;
}