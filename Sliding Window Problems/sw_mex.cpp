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
	ll n, k; cin >> n >> k;
	vector<ll> a(n);
	fr(i, n)cin >> a[i];
	map<ll, int> mp; 		// freq of seen data points
	set<ll> s;
	for (int i = 0; i <= k; ++i)
	{
		s.insert(i);
	}
	int l = 0;
	vector<ll> ans;
	for (int r = 0; r < n; ++r)
	{
		if (mp[a[r]] <= k) {
			mp[a[r]]++;
			if (s.count(a[r]))s.erase(a[r]);	// it is seen
		}

		if (r - l + 1 > k) {
			// shrink the required window.
			if (a[l] <= k) {
				mp[a[l]]--;
				if (mp[a[l]] == 0) {
					mp.erase(a[l]);
					s.insert(a[l]);
				}
			}
			l++;
		}
		if (r - l + 1 == k) ans.push_back(*s.begin());
	}
	for (auto i : ans)cout << i << " ";
	cout << endl;
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
