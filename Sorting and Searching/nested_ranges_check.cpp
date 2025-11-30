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
	ll n; cin >> n;
	vector<tuple<ll, ll, int>> v;
	for (int i = 0; i < n; ++i)
	{
		ll x, y; cin >> x >> y;
		v.pb({x, y, i});
	}
 
	auto cmp = [&](auto & a, auto & b) {
		if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
		return get<0>(a) < get<0>(b);
	};
 
	sort(all(v), cmp);
 
	vector<ll> contains(n, 0), contained(n, 0);
 
	// case is_contained ->
	ll max_y = 0;
	for (auto &[x, y, i] : v) {
		if (y <= max_y) {
			contained[i] = 1;
		}
		max_y = max(max_y, y);
	}
 
	// case contains:  minimum l and maximum r
	ll min_y = 1e9 + 1;
	for (int i = n - 1; i >= 0; --i)
	{
		auto &[x, y, indx] = v[i];
		if (y >= min_y) contains[indx] = 1;
		min_y = min(min_y, y);
	}
 
	for (auto i : contains)cout << i << " "; cout << endl;
	for (auto i : contained)cout << i << " "; cout << endl;
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