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
	vector<ll> v(n);
	ll x, a, b, c; cin >> x >> a >> b >> c;
	v[0] = x;
	for (int i = 1; i < n; ++i)
	{
		v[i] = (v[i - 1] * a + b) % c;
	}
	vector<ll> ans;
	deque<ll> q;
	for (int i = 0; i < n; ++i)
	{
		while (!q.empty() && v[q.back()] > v[i])q.pop_back();
		q.push_back(i);
		if (q.front() <= i - k)q.pop_front();
		if (i >= k - 1)ans.push_back(v[q.front()]);
	}
	ll res = 0;
	for (auto &i : ans) res ^= i;
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