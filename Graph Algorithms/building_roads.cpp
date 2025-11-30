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
 
void dfs(int c, vector<vector<int>> &adj, vector<int> &vis) {
	vis[c] = 1;
	for (auto &i : adj[c]) {
		if (!vis[i]) {
			dfs(i, adj, vis);
		}
	}
}
 
void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	fr(i, m) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	// we just need to count the total number of distinct components -> thats our answer.
	// pull out the first node always for connection.
	vector<int> vis(n + 1, 0);
	vector<int> ans;
	for (int i = 1; i <= n; ++i)
	{
		if (!vis[i]) {
			ans.pb(i);  // src node of this depth
			dfs(i, adj, vis);
		}
	}
	cout << (int)ans.size() - 1 << endl;
	// now have to find the way to make the roads
	for (int i = 1; i < (int)ans.size(); ++i)
	{
		cout << ans[i - 1] << " " << ans[i] << endl;
	}
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