#include <bits/stdc++.h>
using namespace std;
string Ame(int n, int b){
    if(n == b) {return "";}
    int B = b, W = n-b;
    bool nigga = false;
    if(__builtin_popcount(b) > B || (__lg(b)+1 - __builtin_popcount(b)) > W || __lg(b)+1 > ceil(log2(n))) {
        nigga = true;
        b = n-b;
    }
    string re;
    while(b) {
        re += (b&1 ? 'B' : 'W');
        b>>=1;
    }
    if(nigga) re += 'W';
    return re;
}
int Bla(int n, string s){
    if(n == 1) return 1;
    if(s.empty()) return n;
    int re = 0;
    if(s.back() == 'W') {
        for(int i = 0; i < s.size()-1; i++)
            re += (s[i] == 'B')<<i;
        re = n-re;
    } else {
        for(int i = 0; i < s.size(); i++)
            re += (s[i] == 'B')<<i;
    }
    return re;
}