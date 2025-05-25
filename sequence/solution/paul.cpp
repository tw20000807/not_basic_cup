#include<bits/stdc++.h> 
using namespace std; 
int ans[1005]; 
int maxn, minn; 
int maxp, minp; 
const int bign=1e9; 
int compare_numbers(int i, int j, int k); 
vector<int> v1, v2; 
int findmin(vector<int> v) 
{ 
    minn=bign; 
    v1.clear(); 
    for(int i=2;i<v.size();i++) 
    { 
        int x=compare_numbers(0, 1, i); 
        if(x<minn) 
        { 
            v1.clear(); 
            v1.push_back(i); 
            minn=x; 
        } 
        else if(x==minn) 
        { 
            v1.push_back(i); 
        } 
    } 
    if(v1.size()==v.size()-2) 
    { 
        minn=bign; 
        v1.clear(); 
        for(int i=0;i<v.size();i++) 
        { 
            if(i==0||i==2) continue; 
            int x=compare_numbers(0, 2, i); 
            if(x<minn) 
            { 
                v1.clear(); 
                v1.push_back(i); 
                minn=x; 
            } 
            else if(x==minn) 
            { 
                v1.push_back(i); 
            } 
        } 
        if(v1.size()==1) return v1[0]; 
        else
        { 
            v1.push_back(0); 
            v1.push_back(2); 
            return findmin(v1); 
        } 
    } 
    else
    { 
        if(v1.size()==1) return v1[0]; 
        else
        { 
            v1.push_back(0); 
            v1.push_back(1); 
            return findmin(v1); 
        } 
    } 
} 
  
int findmax(vector<int> v) 
{ 
    maxn=-1; 
    v1.clear(); 
    for(int i=2;i<v.size();i++) 
    { 
        int x=compare_numbers(0, 1, i); 
        if(x>maxn) 
        { 
            v1.clear(); 
            v1.push_back(i); 
            maxn=x; 
        } 
        else if(x==maxn) 
        { 
            v1.push_back(i); 
        } 
    } 
    if(v1.size()==v.size()-2) 
    { 
        maxn=-1; 
        v1.clear(); 
        for(int i=0;i<v.size();i++) 
        { 
            if(i==0||i==2) continue; 
            int x=compare_numbers(0, 2, i); 
            if(x>maxn) 
            { 
                v1.clear(); 
                v1.push_back(i); 
                maxn=x; 
            } 
            else if(x==maxn) 
            { 
                v1.push_back(i); 
            } 
        } 
        if(v1.size()==1) return v1[0]; 
        else
        { 
            v1.push_back(0); 
            v1.push_back(2); 
            return findmax(v1); 
        } 
    } 
    else
    { 
        if(v1.size()==1) return v1[0]; 
        else
        { 
            v1.push_back(0); 
            v1.push_back(1); 
            return findmax(v1); 
        } 
    } 
} 
  
void bob_init(int n) 
{ 
    v1.clear(); 
    v2.clear(); 
    maxn=-1; 
    minn=n; 
    for(int i=2;i<n;i++) 
    { 
        int x=compare_numbers(0, 1, i); 
        if(x>maxn) 
        { 
            v1.clear(); 
            v1.push_back(i); 
            maxn=x; 
        } 
        else if(x==maxn) 
        { 
            v1.push_back(i); 
        } 
        if(x<minn) 
        { 
            v2.clear(); 
            v2.push_back(i); 
            minn=x; 
        } 
        else if(x==minn) 
        { 
            v2.push_back(i); 
        } 
    } 
    if(v1.size()==n-2&&v2.size()==n-2) 
    { 
        maxn=-1; 
        minn=n; 
        v1.clear(); 
        v2.clear(); 
        for(int i=0;i<n;i++) 
        { 
            if(i==0||i==2) continue; 
            int x=compare_numbers(0, 2, i); 
            if(x>maxn) 
            { 
                v1.clear(); 
                v1.push_back(i); 
                maxn=x; 
            } 
            else if(x==maxn) 
            { 
                v1.push_back(i); 
            } 
            if(x<minn) 
            { 
                v2.clear(); 
                v2.push_back(i); 
                minn=x; 
            } 
            else if(x==minn) 
            { 
                v2.push_back(i); 
            } 
        } 
  
        if(v1.size()==1) maxp=v1[0]; 
        else
        { 
            v1.push_back(0); 
            v1.push_back(2); 
            maxp=findmax(v1); 
        } 
  
        if(v2.size()==1) minp=v2[0]; 
        else
        { 
            v2.push_back(0); 
            v2.push_back(2); 
            minp=findmin(v2); 
        } 
    } 
    else
    { 
        if(v1.size()==1) maxp=v1[0]; 
        else
        { 
            v1.push_back(0); 
            v1.push_back(1); 
            maxp=findmax(v1); 
        } 
  
        if(v2.size()==1) minp=v2[0]; 
        else
        { 
            v2.push_back(0); 
            v2.push_back(1); 
            minp=findmin(v2); 
        } 
    } 
    maxn=-1; 
    minn=n; 
    for(int i=0;i<n;i++) 
    { 
        if(i==maxp||i==minp) continue; 
        int x=compare_numbers(maxp, minp, i); 
        if(x>maxn) maxn=x; 
        if(x<minn) minn=x; 
        ans[i]=x; 
    } 
    ans[maxp]=maxn; 
    ans[minp]=minn; 
} 
int query_from_alice(int a) 
{ 
    return ans[a]; 
}