#include <vector>
#include <algorithm>
int n;
std::vector<int> construct(const std::vector<int> v) {
	n = v.size();
	std::vector<int> r = v;
	std::rotate(r.rbegin(), r.rbegin() + 1, r.rend());
	return r;
}