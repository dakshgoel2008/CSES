// Problem: Subarray Sums I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1660
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
 
ll expo(ll a, ll b, ll mod) {
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % mod;
		a = (a * a) % mod;
		b = b >> 1;
	}
	return res;
}
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_mul(ll a, ll b, ll m) {
	a = a % m;
	b = b % m;
	return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m) {
	a = a % m;
	b = b % m;
	return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m) {
	a = a % m;
	b = b % m;
	return (mod_mul(a, mminvprime(b, m), m) + m) % m;
}  // only for prime m
ll lcm(ll a, ll b) { return (a * b) / __gcd(a, b); }
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
void solve() {
	ll n, x;
	cin >> n >> x;
	vector<ll> a(n);
	fr(i, n) cin >> a[i];
	ll l = 0, sum = 0, cnt = 0;
	fr(r, n) {
		sum += a[r];
		while (sum > x) sum -= a[l++];
		if (sum == x) cnt++;
	}
	cout << cnt << endl;
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