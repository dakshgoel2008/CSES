void solve() {
	ll n; cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; ++i)
	{
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	vector<int> dis1(n + 1, 0);	// max{1st end point of diameter}
	vector<int> dis2(n + 1, 0);	// max{2nd end point of diameter} and distances from 1st end point to every node
	vector<int> dis3(n + 1, 0);// distance of each node from 2nd end point to every node
	// ans[i] = max(dis2[i], dis3[i]);


	function<void(vector<int>&, int, int)> dfs = [&](vector<int>&a, int c, int p) {
		if (p == 0) a[c] = 0;	// root node
		else a[c] = a[p] + 1;
		for (auto &i : adj[c]) {
			if (i != p) {
				dfs(a, i, c);
			}
		}
	};

	dfs(dis1, 1, 0);
	auto id = max_element(all(dis1)) - dis1.begin();
	dfs(dis2, id, 0);
	auto id2 = max_element(all(dis2)) - dis2.begin();
	dfs(dis3, id2, 0);
	for (int i = 1; i <= n; ++i)
	{
		cout << max(dis2[i], dis3[i]) << " ";
	} cout << endl;
}