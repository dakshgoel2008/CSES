const int N = 2e5 + 1, M = 20;
vector<int> adj[N];
int dep[N], par[N][M];
int val[N];

void dfs(int curr, int p) {
	dep[curr] = dep[p] + 1;
	par[curr][0] = p;

	for (int i = 1; i < M; ++i)
		par[curr][i] = par[par[curr][i - 1]][i - 1];

	for (auto x : adj[curr])
		if (x != p)
			dfs(x, curr);
}

int LCA(int u, int v) {
	if (u == v) return u;

	if (dep[u] < dep[v])
		swap(u, v);   // ensure u is deeper

	int diff = dep[u] - dep[v];

	for (int i = M - 1; i >= 0; --i)
		if ((1 << i) & diff)
			u = par[u][i];

	if (u == v) return u;

	for (int i = M - 1; i >= 0; --i) {
		if (par[u][i] != par[v][i]) {
			u = par[u][i];
			v = par[v][i];
		}
	}

	return par[u][0];
}

void solve() {
	int n, m; cin >> n >> m;
	for (int i = 1; i < n; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1, 0);
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b;
		val[a] += 1;
		val[b] += 1;
		val[LCA(a, b)] -= 1;
		val[par[LCA(a, b)][0]] -= 1;
	}

	function<void(int, int)> dfs2 = [&](int c, int p) {
		for (auto& i : adj[c]) {
			if (i != p) {
				dfs2(i, c);
				val[c] += val[i];
			}
		}
	};

	dfs2(1, 0);
	for (int i = 1; i <= n; ++i)
	{
		cout << val[i] << " ";
	} cout << "\n";
}