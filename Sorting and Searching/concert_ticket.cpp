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
	int n, k; cin >> n >> k;
	multiset<ll> s;
	fr(i, n) {
		int x; cin >> x; s.insert(x);
	}
	fr(i, k) {
		int x; cin >> x;
		auto id = s.upper_bound(x);
		if (id == s.begin()) cout << -1 << endl;
		else {
			--id;
			// now whatever the element will be it will be <= x.
			cout << *id << endl;
			s.erase(id);
		}
	}
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