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
	ll sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		sum += i;
	}
	if (sum & 1) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	vector<int> a, b;
 
	sum /= 2;
	for (int i = n; i >= 1; --i)
	{
		if (i <= sum) {
			a.pb(i);
			sum -= i;
		} else {
			b.pb(i);
		}
	}
	cout << a.size() << endl;
	for (auto i : a) {
		cout << i << " ";
	} cout << endl;
 
	cout << b.size() << endl;
	for (auto i : b) {
		cout << i << " ";
	} cout << endl;
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