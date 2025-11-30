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
	vector<pair<pair<ll, ll>, ll>> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].second = i;
	}
	sort(a.begin(), a.end());		// sorting on basis of arrival time.
	vector<ll> ans(n, 0);
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	// for departure time, room alloted.
	int room = 0;
	for (int i = 0; i < n; ++i)
	{
		if (pq.empty()) {
			ans[a[i].second] = ++room;
			pq.push({a[i].first.second, room});
		}
		else {
			// if arrival time is less than least departure time.
			if (a[i].first.first <= pq.top().first) {
				ans[a[i].second] = ++room;
				pq.push({a[i].first.second, room});
			}
			// arrival time is greater than least departure time.
			else {
				ans[a[i].second] = pq.top().second;
				pq.pop();
				pq.push({a[i].first.second, ans[a[i].second]});		// alloted room is previously used room.
			}
		}
	}
	cout << room << endl;
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