#include <vector>
std::vector<int> construct(int n, int k) {
	std::vector< int > ret(n);
    for(int i = 0; i < n; ++i) ret[i] = i + 1;
    return ret;
}
