#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &it : a)cin >> it;
 
	vector<ll> pre(n);
	pre[0] = a[0];
	for (ll i = 1; i < n; ++i) {
		pre[i] = pre[i - 1] + a[i];
	}
	while (q--) {
		ll l, r; cin >> l >> r;
		cout << pre[r - 1] - ((l - 1 <= 0) ? 0 : pre[l - 1 - 1]) << endl;
	}
 
 
	return 0;
}