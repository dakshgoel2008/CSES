#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	ll median = 0;
	if (n & 1) {
		median = a[n / 2];
	}
	else {
		median = (a[n / 2 - 1] + a[n / 2]) / 2;
	}
 
	ll ans = 0;
	for (int i = 0; i < n; ++i)
	{
		ans += (abs(median - a[i]));
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
 
	solve();
 
	return 0;
}