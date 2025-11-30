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
	vector<ll> a(n);
	for (auto &i : a)cin >> i;
 
	map<ll, ll> mp;
	ll cnt = 0;
	ll sum = 0;
	for (auto i : a) {
		sum += i;
		if ((sum % n + n) % n == 0)cnt++;
		cnt += mp[(sum % n + n) % n];		// here it will be basically giving 0;
		mp[(sum % n + n) % n]++;
	}
	cout << cnt << endl;
 
	return 0;
}