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
	string s; cin >> s;
	map<char, int> mp;
	for (auto i : s)
	{
		mp[i] ++;
	}
	int odd = 0;
	char oc;
	for (auto &[a, b] : mp) {
		if (b & 1) {
			odd++;
			oc = a;
		}
 
	}
	if (odd > 1) {
		cout << "NO SOLUTION";
		return;
	}
	string s1;
	for (auto &[a, b] : mp) {
		if ((b & 1) == 0) {
			s1 += string(b / 2, a);
		}
	}
 
	string s2 = s1;
	reverse(all(s1));
	string middle = "";
	if (odd == 1) {
		middle = string(mp[oc], oc);  // Just one instance of the odd character
	}
	cout << s2 + middle +  s1 << endl;
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