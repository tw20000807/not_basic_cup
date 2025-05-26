// remember.cpp
#include <vector>
using namespace std;

long long remember(vector<int> V) {
    long long sum = 0;
    long long xorval = 0;
    for (int v : V) {
        sum += v;
        xorval ^= v;
    }
    // Pack sum and xorval into a single 64-bit number
    return (sum << 32) | xorval;
}

// find.cpp
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> find(int k, long long r, vector<int> U) {
    long long sumV = r >> 32;
    long long xorV = r & ((1LL << 32) - 1);
    long long sumU = 0, xorU = 0;
    for (int u : U) {
        sumU += u;
        xorU ^= u;
    }
    long long sumDiff = sumU - sumV;
    long long xorDiff = xorU ^ xorV;

    int n = U.size();
    vector<int> res;

    // Try all combinations of k elements from U
    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            if (U[i] == sumDiff && U[i] == xorDiff) {
                return {U[i]};
            }
        }
    } else if (k == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((long long)U[i] + U[j] == sumDiff && (U[i] ^ U[j]) == xorDiff) {
                    return {U[i], U[j]};
                }
            }
        }
    } else if (k == 3) {
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int l = j + 1; l < n; ++l) {
                    if ((long long)U[i] + U[j] + U[l] == sumDiff &&
                        (U[i] ^ U[j] ^ U[l]) == xorDiff) {
                        return {U[i], U[j], U[l]};
                    }
                }
    }
    return {}; // should never happen for valid test cases
}
