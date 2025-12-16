/**
    author:  UG_BEAST
**/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const ll mod = 1e9 + 7;

#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back

void solve() {
	ll n; cin >> n;
	vector<ll> a(n);
	fr(i, n)cin >> a[i];
	vector<int> dp;
	for (int i = 0; i < n; ++i)
	{
		if (dp.empty()) {
			dp.pb(a[i]);
			continue;
		}
		auto it = lower_bound(dp.begin(), dp.end(), a[i]);
		if (it == dp.end()) dp.pb(a[i]);
		else *it = a[i];
	}
	cout << dp.size() << endl;
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
