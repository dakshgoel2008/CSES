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
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 2; i <= n; ++i)
	{
		int u; cin >> u;
		adj[u].pb(i);
		adj[i].pb(u);
	}
	vector<int> sub(n + 1);
	function < void(int, int)> dfs = [&](int c, int p) {
		sub[c] = 1;
		for (auto &i : adj[c]) {
			if (i != p) {
				dfs(i, c);
				sub[c] += sub[i];
			}
		}
	};
	dfs(1, -1);
	for (int i = 1; i <= n; ++i)
	{
		cout << sub[i] - 1 << " ";
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