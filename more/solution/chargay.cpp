#include<bits/stdc++.h>
using namespace std;
#define ll long long 
 
vector<int> find(int k, long long r, vector<int> U)
{
    ll total = 0;
    for (auto t : U) total = total ^ t;
    vector<int> aans;
    if(k==1){
        for(auto t:U){
            if((total^t)==r){
                aans.push_back(t);  
                return aans;
            }
        }
    }
    else if(k==2){
        for(int i=0;i<U.size();i++){
            for(int j=i+1;j<U.size();j++){
                ll ab=U[i]^U[j];
                if((total^ab)==r){
                    aans.push_back(U[i]);
                    aans.push_back(U[j]);
                    return aans;
                }
            }
        }
    }
    else if(k==3){
        vector<int> vis;
        for(auto t:U){
            vis.push_back(t);
        }
        sort(vis.begin(),vis.end());
        for(int i=0;i<U.size();i++){
            for(int j=i+1;j<U.size();j++){
                ll need=(1LL*total)^(1LL*U[i])^(1LL*U[j])^r;
                auto id=lower_bound(vis.begin(),vis.end(),need);
                if(*id==need and *id!=U[i] and *id!=U[j]){
                    aans.push_back(U[i]);
                    aans.push_back(U[j]);
                    aans.push_back(need);
                    return aans;
                }
            }
        }
    }
}
long long remember(vector<int> V)
{
    long long int ans = 0;
    for (auto t : V) ans = ans ^ t;
    //cout<<ans<<'\n';
    return ans;
}