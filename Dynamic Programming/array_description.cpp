#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll mod = 1e9 + 7;
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
 
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
 
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
 
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}