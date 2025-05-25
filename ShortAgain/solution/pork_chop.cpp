#include <bits/stdc++.h> 
using namespace std; 
   
#define ll long long 
#define endl '\n' 
#define pb push_back 
#define mp make_pair 
  
vector<int> construct(vector<int> V){ 
    ll n=(ll)V.size(); 
    vector<int> r=V; 
    r.pb(V[n-1]); 
    for(int i=0;i<n-1;i++) r.pb(V[i]); 
    return r; 
}   