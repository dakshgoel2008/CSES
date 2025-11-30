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
	vector <pair<ll, ll>> a(n);
	fr(i, n) {
		cin >> a[i].first >> a[i].second;
	}
	sort(all(a));
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		while (!pq.empty() and pq.top() <= a[i].first)pq.pop();
		pq.push(a[i].second);
		ans = max(ans, (int)pq.size());
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
 
	int t = 1;
	while (t--) {
		solve();
	}
 
	return 0;
}