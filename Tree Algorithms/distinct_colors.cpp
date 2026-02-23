/**
    author:  UG_BEAST
**/

void solve() {
    ll n; cin >> n;
    vector<int> a(n + 1);
    set<int> s[n + 1];
    for (int i = 1; i <= n; ++i)
    {
        int x; cin >> x;
        s[i].insert(x);
    }
    vector<vector<int>> adj(n + 1);
    vector<int> subtree(n + 1);
    for (int i = 1; i < n; ++i)
    {
        int x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    function<void(int, int)> dfs = [&](int c, int p) {
        // s[c].insert(a[c]);
        for (auto &i : adj[c]) {
            if (i != p) {
                dfs(i, c);
                if (s[i].size() > s[c].size()) swap(s[i], s[c]); // if not doing it will make the complexity as N^2logn
                // adter this the TC -> Nlog^2logn
                for (auto &j : s[i]) s[c].insert(j);
                // as we are aways inserting smaller set into bigger set the insertion will take logN
                // as inserting size = 1 and size >= 1 make the net size >= 2, then size >= 4, size >= 8 and so on
                // thus covering the n size in logn time.
            }
        }
        subtree[c] = s[c].size();
    };

    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << subtree[i] << " ";
}
