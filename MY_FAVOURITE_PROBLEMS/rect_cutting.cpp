/**
    author:  UG_BEAST
**/
 
void solve() {
    int a, b; cin >> a >> b;
    // state -> dp[i][j] = minimum no of cuts for a*b grid.
    // i -> heigth and j -> width:
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
 
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (i == j) {
                dp[i][j] = 0;       // stop dude if got square.
                continue;
            }
            for (int h = 1; h <= i / 2; ++h)
            {
                dp[i][j] = min(dp[i][j], dp[h][j] + dp[i - h][j] + 1);
            }
            for (int w = 1; w <= j / 2; ++w)
            {
                dp[i][j] = min(dp[i][j], dp[i][w] + dp[i][j - w] + 1);
            }
        }
    }
 
    cout << dp[a][b] << endl;
}


// RECURSIVE + MEMOIZATION 
void solve() {
	ll a, b; cin >> a >> b;
	vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));

	function<int(int, int)> f = [&](int i, int j) {
		if (i == j) return 0;	// got 1 square no need to cut further.
		// vertical cuts:
		if (dp[i][j] != -1) return dp[i][j];

		int ans = INF;
		// horizontal cuts.
		for (int c = 1; c <= i/2; ++c) ans = min(ans, f(c, j) + f(i - c, j) + 1);
		for (int c = 1; c <= j/2; ++c) ans = min(ans, f(i, c) + f(i, j - c) + 1);

		return dp[i][j] = ans;
	};

	cout << f(a, b) << endl;
}