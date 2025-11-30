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
	vector<int> a(n);
	fr(i, n)cin >> a[i];
	multiset<int> s;
	// we are just focussing on top of the towers
	for (int i = 0; i < n; ++i)
	{
		auto id = s.upper_bound(a[i]);
		if (id != s.end()) s.erase(id);
		s.insert(a[i]);
	}
	// currently set will be having all the top elements of the towers created.
	cout << s.size() << endl;
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