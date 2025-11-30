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
	vector<ll> a(n);
	fr(i, n)cin >> a[i];
	stack<ll> s;
	vector<ll> ans(n);
	for (int i = 0; i < n; ++i)
	{
		while (!s.empty() && a[s.top()] >= a[i])s.pop();
		if (s.empty())ans[i] = 0;
		else ans[i] = s.top() + 1;
		s.push(i);
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