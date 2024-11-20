#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))

const int N = 1e5 + 10;

ll c[N];
vector<pair<int, ll> > con[N];
int sz = 0;
int vis[N];
ll ans = 0;
ll ans2 = 0;
// Equivalent problem : Find the spanning tree with minimum
// bitwise OR of edges.
// Check if we can get a connected graph using edges 
// which don't require ith token

void dfs(int s, ll i){
	sz++;
	vis[s] = 1;
	for(auto it : con[s]){
		int v = it.first;
		ll cost = it.second;
		if((cost & i) != cost) continue;
		if(!vis[v]) dfs(v, i);
	}
}

void dfs2(int s){
	vis[s] = 1; sz++;
	for(auto v : con[s]){
		if(!vis[v.first]) dfs2(v.first);
	}
}
int main(){

	int n, m, k, u, v, l, ind;
	sd(n); sd(m); sd(k);

	for(int i = 0; i < k; i++){
		cin >> c[i];
		if(i) assert(c[i] >= 2 * c[i - 1]);
	}
	for(int i = 1; i <= m; i++){
		sd(u); sd(v); sd(l); ll cost = 0;
		for(int j = 1; j <= l; j++){
			sd(ind);
			cost |= (1LL << (ind - 1));
		}
		con[u].push_back({v, cost});
		con[v].push_back({u, cost});
	}
	dfs2(1);
	if(sz != n){
		cout << -1;
		return 0;
	}
	ll ans = 0, X = ((1LL << k) - 1), ret = 0;
	for(int i = k - 1; i >= 0; i--){
		sz = 0; memset(vis, 0, sizeof vis);
		dfs(1, X ^ (1LL << i));
		if(sz != n){
			ans |= (1LL << i);
			ret += c[i];
		}
		else X ^= (1LL << i);
	}

	printf("%lld\n", ret);

}