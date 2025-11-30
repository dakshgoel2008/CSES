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
 
void solve() {
	ll n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	vector<vector<int>> dp(n, vector<int>(n, 0));
	if (a[0][0] != '*')dp[0][0] = 1;
	for (int i = 1; i < n; ++i)
	{
		if (a[i][0] != '*')dp[i][0] = dp[i - 1][0];
		if (a[0][i] != '*')dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (a[i][j] != '*')dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
		}
	}
	cout << dp[n - 1][n - 1] << endl;
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