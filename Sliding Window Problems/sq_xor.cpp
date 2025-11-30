/**
    author:  UG_BEAST
**/
 
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
	ll x, a, b, c; cin >> x >> a >> b >> c;
	ll sum = 0, res = 0;
	vector<ll> w;
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)x = x;
		else x = (a * x + b) % c;
		w.pb(x);
		sum ^= x;
		if (w.size() > k) {
			sum ^= w[w.size() - 1 - k];	// remove it from the current sum.
		}
		if (i >= k - 1)res ^= sum;
	}
	cout << res << endl;
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