// Problem: Playlist
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1141/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
//
// Powered by CP Editor (https://cpeditor.org)
 
// by -> Daksh Goel
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio()                    \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);                    \
  cout.tie(NULL)
 
const ll mod = 1e9 + 7;
const ll INF = 1e18;
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	fr(i, n) cin >> a[i];
	map<ll, ll> mp;
	ll l = 0, ans = 0;
	fr(r, n) {
		mp[a[r]]++;  // inc freq of current el,
		while (mp[a[r]] > 1) {
			mp[a[l++]]--;
		}
		ans = max(ans, r - l + 1);
	}
	cout << ans << endl;
}
 
int main() {
	fastio();
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}
 
	return 0;
}