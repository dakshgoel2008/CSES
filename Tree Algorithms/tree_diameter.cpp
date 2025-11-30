/**
    author:  UG_BEAST
**/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll mod = 1e9 + 7;
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
 
void solve() {
	ll n; cin >> n;
	vector<vector<ll>> adj(n + 1);
	for (int i = 1; i < n; ++i)
	{
		ll u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	vector<int> dis1(n + 1, -1);
	vector<int> dis2(n + 1, -1);
	// just need to calculate the dis of each node from the current src node:
	function<void(vector<int>&, int, int)> dfs = [&](vector<int> &a, int c, int p) {
		if (p == -1) {
			a[c] = 0;		// we have to count the max number of edges.
		} else {
			a[c] = a[p] + 1;
		}
		for (auto &i : adj[c]) {
			if (i != p) {
				dfs(a, i, c);
			}
		}
	};
	dfs(dis1, 1, -1);
	ll id = distance(dis1.begin(), max_element(all(dis1)));
	dfs(dis2, id, -1);
	cout << *max_element(all(dis2));
}
 
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
 
	int t = 1;
	while (t--) {
		solve();
	}
 
	return 0;
}