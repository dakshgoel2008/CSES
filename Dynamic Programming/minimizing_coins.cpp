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
	ll n, x; cin >> n >> x;
	vector<ll> a(n);
	fr(i, n)cin >> a[i];
	vector<ll> dp(x + 1, 1e9);
	// state -> minimum number of coins required to sum == k from 0 to i;
	dp[0] = 0;
	for (int i = 1; i <= x; ++i)
	{
		for (auto j : a)
		{
			if (i >= j)dp[i] = min(dp[i], 1 + dp[i - j]);
		}
	}
	cout << (dp[x] < 1e9 ? dp[x] : -1) << endl;
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