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

const ll INF = 1e9;
const ll mod = 1e9 + 7;

#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back

// rerooting: dp[c] = dp[p] - subTree[c] + (total nodes - subTree[c]);
// when we reroot -> all nodes of subtree of c decreased by 1 ie. substract the size of the subTree[c]
// and all the other nodes increases the depth ie. add (total node - subTree[c]);

void solve() {
	int n; cin >> n;
	vector<vector<int>> adj(n + 1);
	vector<ll> st(n + 1, 1), res(n + 1, 0);

	for (int i = 1; i < n; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	function<ll(int, int, int)> dfs = [&](int c, int p, int d) { // d -> depth
		ll ans = d;
		for (auto& i : adj[c]) {
			if (i != p) {
				ans += dfs(i, c, d + 1);
				st[c] += st[i];
			}
		}
		return ans;
	};

	function<void(int, int, ll)> reRoot = [&](int c, int p, ll ans) {
		res[c] = ans;
		for (auto& i : adj[c]) {
			if (i != p) reRoot(i, c, ans - st[i] + n - st[i]);	// ans -> ans of node c which is parent for i.
		}
	};

	reRoot(1, -1, dfs(1, -1, 0));
	for (int i = 1; i <= n; ++i) cout << res[i] << " ";
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
