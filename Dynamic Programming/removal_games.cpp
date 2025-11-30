#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i) cin >> a[i];
 
	vector<vector<ll>> dp(n, vector<ll>(n, 0));
 
	// Base cases
	for (ll i = 0; i < n; ++i)
		dp[i][i] = a[i];  // Only one element
 
	for (ll i = 0; i < n - 1; ++i)
		dp[i][i + 1] = max(a[i], a[i + 1]);  // Two elements
 
	// Fill DP table for lengths >= 3
	for (ll len = 3; len <= n; ++len) {
		for (ll i = 0; i + len - 1 < n; ++i) {
			ll j = i + len - 1;		// this will give the indx of the segment end item ie. e pointer.
 
			// Choice 1: pick a[i]
			ll pick_i = a[i] + min(
			                dp[i + 2][j]	// if second player picks a[i+1]
			                , dp[i + 1][j - 1]	// if second player picks a[j];
			            );
 
			// Choice 2: pick a[j]
			ll pick_j = a[j] + min(
			                dp[i + 1][j - 1]		// if second player picks a[i]
			                , dp[i][j - 2]	// if second player picks a[j-1]
			            );
 
			dp[i][j] = max(pick_i, pick_j);
		}
	}
 
	cout << dp[0][n - 1] << endl;
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