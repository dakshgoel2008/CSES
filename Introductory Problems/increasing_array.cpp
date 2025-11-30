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
	int n; cin >> n;
	vector<ll> a(n);
	fr(i, n)cin >> a[i];
	ll ans = 0;
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < a[i - 1]) {
			ans += abs(a[i] - a[i - 1]);
			a[i] = a[i - 1];
		}
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