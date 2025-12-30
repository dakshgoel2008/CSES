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

const int N = 2e5 + 1, M = 20;
vector<int> adj[N];
int dep[N], par[N][M];

void dfs(int curr, int p) {
	dep[curr] = dep[p] + 1;
	par[curr][0] = p;
	for (int i = 1; i < M; ++i) par[curr][i] = par[par[curr][i - 1]][i - 1];
	for (auto x : adj[curr]) if (x != p) dfs(x, curr);
}

int LCA(int u, int v) {
	if (u == v)return u;
	if (dep[u] < dep[v]) swap(u, v);

	int diff = dep[u] - dep[v];
	for (int i = M - 1; i >= 0; --i)
	{
		if ((1 << i) & diff) u = par[u][i];
	}

	for (int i = M - 1; i >= 0; --i)
	{
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}
	return u != v ? par[u][0] : u;
}

void solve() {
	int n, q; cin >> n >> q;
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0);
	while (q--) {
		int a, b; cin >> a >> b;
		int x = LCA(a, b);
		cout << dep[a] + dep[b] - (dep[x] << 1) << endl;
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
