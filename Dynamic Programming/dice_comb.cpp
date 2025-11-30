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
	ll n; cin >> n;
	vector<ll> dp(n + 1);
	// state -> dp[i] = no. of ways to get sum = i from 0;
	dp[0] = 1;	// 0 to 0 no. of ways is 1 -> don't roll the dice.
	// transition -> dp[x] = summation from 1 to 6 for dp[x-i];
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= 6; ++j)
		{
			if (i >= j) dp[i] = (dp[i] + dp[i - j]) % mod;
		}
	}
	cout << dp[n] << endl;
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