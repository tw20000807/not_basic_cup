#include "sequence.h"
#include <bits/stdc++.h>
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
		for(int i = 2; i < n; ++i){
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
		map<int, int> p;
		random_shuffle(ord.begin(), ord.end());
		int now = ord.back(); ord.pop_back();
		for(auto i : ord){
			v[i] = compare_numbers(now, i, vis[mx][0]);
			if(p.count(v[i])){
				v[now] = v[i];
				swap(p[v[i]], now);
				v[i] = compare_numbers(now, i, vis[mx][0]);
			}
			p[v[i]] = i;
		}
		v[now] = p.begin()->first;
	}// mn
	{
		vector< int > ord = vis[mx];
		map<int, int> p;
		random_shuffle(ord.begin(), ord.end());
		int now = ord.back(); ord.pop_back();
		for(auto i : ord){
			v[i] = compare_numbers(vis[mn][0], now, i);
			if(p.count(v[i])){
				v[now] = v[i];
				swap(p[v[i]], now);
				v[i] = compare_numbers(vis[mn][0], now, i);
			}
			p[v[i]] = i;
		}
		v[now] = prev(p.end())->first;
	}// mx
}
/*

*/
int query_from_alice(int a){
	return v[a];
}
