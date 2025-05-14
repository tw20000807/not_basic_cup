#include <vector>
std::vector<int> construct(int n, int k) {
	std::vector< int > ret(n);
    int now = 1;
    for(int i = n - 1; i >= 0; --i){
        if(k - i >= 0){
            ret[i] = now++;
            k -= i;
        }
    }
    for(int i = 0; i < n; ++i){
        if(ret[i] == 0){
            ret[i] = now++;
        }
    }
    return ret;
}
