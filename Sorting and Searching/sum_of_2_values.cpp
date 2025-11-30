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
	int n, x; cin >> n >> x;
	vector<pair<int, int>> a(n);
	fr(i, n) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(all(a));
	ll l = 0, r = n - 1;
	ll sum = 0;
	while (l < r) {
		sum = a[l].first + a[r].first;
		if (sum == x) {
			break;
		} else if (sum > x) {
			r--;
		} else l++;
	}
	if (l >= r) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << a[l].second + 1 << " " << a[r].second + 1 << endl;
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