#include "sequence.h"
#include <random>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <ctime>
#include <utility>
using namespace std;

vector< int > v;
mt19937 rng(time(0) + 666666);

void bob_init(int n){
	v.resize(n);
	map<int, vector<int> > vis;
	int mx, mn;
	{	
		vector< int > ord(n);
		iota(ord.begin(), ord.end(), 0);
		random_shuffle(ord.begin(), ord.end());
		for(int i = 2; i < (int)ord.size(); ++i){
			v[ord[i]] = compare_numbers(ord[0], ord[1], ord[i]);
			vis[v[ord[i]]].push_back(ord[i]);
		}
		if(n == 3){
			v[ord[0]] = v[ord[1]] = v[ord[2]];
			return;
		}
		else{
			mn = vis.begin()->first;
			mx = prev(vis.end())->first;
			v[ord[0]] = compare_numbers(vis[mn][0], ord[0], vis[mx][0]);
			v[ord[1]] = compare_numbers(vis[mn][0], ord[1], vis[mx][0]);
			vis[v[ord[0]]].push_back(ord[0]);
			vis[v[ord[1]]].push_back(ord[1]);
		}
	} // first
	{
		vector< int > ord = vis[mn];
		while((int) ord.size() > 2){
            random_shuffle(ord.begin(), ord.end());
            map<int, vector< int > > mp;
            for(int i = 1; i < (int)ord.size(); ++i){
                v[ord[i]] = compare_numbers(ord[0], ord[i], vis[mx][0]);
                mp[v[ord[i]]].push_back(ord[i]);
            }
            v[ord[0]] = mp.begin()->first;
            mp.begin()->second.push_back(ord[0]);
            ord = mp.begin()->second;
        }
	}// mn
	{
		vector< int > ord = vis[mx];
		while((int) ord.size() > 2){
            random_shuffle(ord.begin(), ord.end());
            map<int, vector< int > > mp;
            for(int i = 1; i < (int)ord.size(); ++i){
                v[ord[i]] = compare_numbers(ord[0], ord[i], vis[mn][0]);
                mp[v[ord[i]]].push_back(ord[i]);
            }
            v[ord[0]] = prev(mp.end())->first;
            prev(mp.end())->second.push_back(ord[0]);
            ord = prev(mp.end())->second;
        }
	}// mx
}
/*

*/
int query_from_alice(int a){
	return v[a];
}
