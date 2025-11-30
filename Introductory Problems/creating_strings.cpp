#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
set<string> a;
void solve(int i, string s) {
	if (i == s.size()) {
		if (a.find(s) == a.end())a.insert(s);
		return;
	}
	for (int j = i; j < s.size(); ++j)
	{
		swap(s[i], s[j]);
		solve(i + 1, s);
		swap(s[i], s[j]);
	}
}
 
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
 
	string s; cin >> s;
	solve(0, s);
	cout << a.size() << endl;
	for (auto i : a)cout << i << endl;
	return 0;
}