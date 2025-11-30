// Problem: Multiplication Table
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/2422
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
	// just have to find minimum of mid st f(mid)>= n*n+1/2
	// here f(x) means no of elements <= x.
	ll n;
	cin >> n;
	ll l = 1, r = n * n;
	ll ans = 0;
	while (l <= r) {
		ll mid = l + (r - l) / 2;
		ll cnt = 0;
		for (int i = 1; i <= n; ++i) cnt += min(n, mid / i);
		if (cnt >= (n * n + 1) / 2) {
			r = mid - 1;
			ans = mid;
		} else
			l = mid + 1;
	}
	cout << ans << endl;
}
 
int main() {
	fastio();
	int t = 1;
 
	while (t--) {
		solve();
	}
 
	return 0;
}