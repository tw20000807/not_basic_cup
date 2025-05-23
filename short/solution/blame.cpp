#include "short.h"
#include <bits/stdc++.h>
std::vector<int> construct(const std::vector<int> v) {
    const int n = v.size();
    auto re = v;
    std::reverse(re.begin(), re.end());
    if(n&1) {
        std::swap(re[n/2], re[n/2+1]);
    }
    return re;
}