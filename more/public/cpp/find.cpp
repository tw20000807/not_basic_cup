#include<vector>
using namespace std;
std::vector<int> find(int k, long long r, std::vector<int> U){
    int n = U.size();
    return vector< int >(U.begin(), U.begin() + k);
}