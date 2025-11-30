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
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size(), m = s2.size();
	vector<vector<ll>> dp(n + 1, vector<ll>(m + 1));
	// state-> dp[i][j] = edit distance for i characters of s1 and j characters of s2.
	// base case:
	// if any string is empty the answer will be the size of the second string
	for (int i = 0; i <= n; ++i)
	{
		dp[i][0] = i;		// if s1 is of length i and s2 of 0 -> answer will be i.
	}
	for (int i = 0; i <= m; ++i)
	{
		dp[0][i] = i;
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = min({
				dp[i][j - 1] + 1,	// adding to s1 or removing from s2
				dp[i - 1][j] + 1,	// removing from s1 or adding to s2
				dp[i - 1][j - 1] + 1,	// adding to both s1 and s2
			}) % mod;
		}
	}
	cout << dp[n][m] << endl;
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