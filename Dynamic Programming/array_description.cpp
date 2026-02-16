void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	fr(i, n)cin >> a[i];
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
 
	// dp[i][k] = no. of ways to build prefix of size i st last el of prefix is k.
 
	// base case:
	for (int i = 1; i <= m; ++i)
	{
		if (a[0] == i || a[0] == 0)dp[1][i] = 1;
	}
 
	for (int i = 2; i <= n; ++i)
	{
		for (int k = 1; k <= m; ++k) {
			if (a[i - 1] != 0 && a[i - 1] != k) {
				dp[i][k] = 0;
				continue;
			}
 
			for (int prev = k - 1; prev <= k + 1 ; ++prev)
			{
				if (!(prev >= 1 and prev <= m))continue;
				dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= m ; ++i)
	{
		ans = (ans + dp[n][i]) % mod;
	}
	cout << ans << endl;
}
 

// DP WITH MEMOIZATION
void solve() {
	ll n, m; cin >> n >> m;
	vector<ll> a(n);
	fr(i, n)cin >> a[i];

	// f(i, j) = total number arr possible with len i and last element as j.
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, -1));

	function<ll(ll, ll)> f = [&](ll i, ll k) {
		if (a[i - 1] != 0LL && a[i - 1] != k) return 0LL;

		if (i == 1LL) return 1LL;

		if (dp[i][k] != -1) return dp[i][k];
		ll ans = 0;
		if (k > 1) ans = (ans + f(i - 1, k - 1)) % mod;
		ans = (ans + f(i - 1, k)) % mod;
		if (k < m)ans = (ans + f(i - 1, k + 1)) % mod;

		return dp[i][k] = ans;
	};

	ll sum = 0;
	for (int i = 1; i <= m; ++i)
	{
		sum = (sum + f(n, i)) % mod;
	}
	cout << sum << endl;
}