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

vector<int> topo(vector<vector<int>> &adj) {
	int n = adj.size();
	vector<int> in(n, 0);
	for (int u = 0; u < n; ++u)
	{
		for (auto v : adj[u]) in[v]++;
	}
	queue<int> q;
	for (int u = 0; u < n; ++u)
	{
		if (in[u] == 0) q.push(u);
	}
	vector<int> ans;
	while (!q.empty()) {
		int f = q.front();	q.pop();
		ans.pb(f);
		for (auto v : adj[f]) {
			in[v]--;
			if (in[v] == 0) q.push(v);
		}
	}
	return ans;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n + 1);
	fr(i, m) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
	}

	vector<int> vis(n + 1, 0);
	function<bool(int)> dfs = [&](int node) {
		vis[node] = 1;
		for (auto n : adj[node]) {
			if (vis[n] == 0) {
				if (dfs(n)) return true;
			} else if (vis[n] == 1) {
				return true;
			}
		}
		vis[node] = 2;
		return false;
	};

	for (int i = 1; i <= n; ++i) {
		if (dfs(i)) {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}

	vector<int> ans = topo(adj);
	for (int i = 1; i <= n; ++i)cout << ans[i] << " ";
	cout << endl;
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
