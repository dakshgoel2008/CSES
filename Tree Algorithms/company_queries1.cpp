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

const int N = 2e5 + 1, M = 20;	// m = log2(n)
vector<int> adj[N];
int dep[N], par[N][M];

void dfs(int curr, int p) {
	dep[curr] = dep[p] + 1;
	par[curr][0] = p;			// first parent
	for (int j = 1; j < M; ++j) par[curr][j] = par[par[curr][j - 1]][j - 1];
	for (auto x : adj[curr]) if (x != p) dfs(x, curr);
}

int kthPar(int u, int k) {
	for (int i = M - 1; i >= 0; --i)
	{
		if ((1 << i)&k) u = par[u][i];
	}
	return u;
}

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 2; i <= n; ++i) {
		int x; cin >> x;
		adj[x].push_back(i);
	}
	dfs(1, 0);
	while (q--)
	{
		int x, k; cin >> x >> k;
		int ans = kthPar(x, k);
		cout << (ans == 0 ? -1 : ans) << endl;
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
