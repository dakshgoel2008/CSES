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
	ll n, w; cin >> n >> w;
	vector<ll> v(n);
	fr(i, n) {
		cin >> v[i];
	}
	sort(all(v));
	ll ans = 0;
	int l = 0, r = n - 1;
	while (l <= r) {
		ll sum = v[l] + v[r];
		if (sum <= w) {
			l++;
		}
		r--;
		ans++;
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