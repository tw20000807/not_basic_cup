#include <vector>
#include <algorithm>
int n;
std::vector<int> construct(const std::vector<int> v) {
	n = v.size();
	std::vector<int> r = v;
	std::rotate(r.begin(), r.begin() + 1, r.end());
	return r;
}