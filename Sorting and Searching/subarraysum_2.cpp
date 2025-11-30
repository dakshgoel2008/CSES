#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
 
	ll n; cin >> n;
	ll x; cin >> x;
	vector<ll> a(n);
	for (auto &it : a)cin >> it;
 
	map<ll, ll> map;
	ll cnt = 0;
	ll sum = 0;
	// prefix sum, frequency:
	for (ll i = 0; i < n; ++i)
	{
		sum += a[i];		// storing the prefix sums
		if (sum == x)cnt++;
		cnt += map[sum - x];
		map[sum]++;
	}
 
	cout << cnt << endl;
 
	return 0;
}