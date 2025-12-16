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
	map<ll, ll> f;		// frwquency count for each element.
	map<ll, set<ll>> fc;		// elements for each frequency

	int l = 0;
	vector<ll> ans;
	for (int r = 0; r < n; ++r)
	{

		int old = f[a[r]];
		if (old > 0) {
			fc[old].erase(a[r]);
			if (fc[old].empty()) fc.erase(old);
		}
		f[a[r]]++;
		fc[f[a[r]]].insert(a[r]);
		if (r - l + 1 > k) {
			// shrink the window
			int freq = f[a[l]];
			// find this element in the fc and remove it from there and insert again.
			fc[freq].erase(a[l]);
			if (fc[freq].empty()) fc.erase(freq);

			f[a[l]]--;
			if (f[a[l]] == 0) {
				f.erase(a[l]);
			}
			else {
				fc[f[a[l]]].insert(a[l]);
			}

			l++;
		}
		if (r - l + 1 == k) {
			auto it = fc.rbegin();
			// auto set = it->second;
			ans.push_back(*it->second.begin());
		}
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
