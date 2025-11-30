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
	ll n, k; cin >> n >> k;
	vector<ll>a(n);
	fr(i, n)cin >> a[i];
	ll l = *max_element(all(a)), r = accumulate(all(a), 0LL);
	ll ans = 0;
	while (l <= r) {
		ll m = l + (r - l) / 2;
		// FFFFTTTT -> first true.
		ll sum = 0, blocks = 1;
		for (int i = 0; i < n; ++i)
		{
			sum += a[i];
			if (sum > m) {
				sum = a[i];
				blocks++;
			}
		}
		if (blocks <= k) {
			r = m - 1;
			ans = m;
		} else l = m + 1;
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
	while (t--) {
		solve();
	}
 
	return 0;
}