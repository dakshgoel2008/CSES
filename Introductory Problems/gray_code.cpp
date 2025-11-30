#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
 
void solve() {
	int n; cin >> n;
	vector<string> v = {"0", "1"}; 		// base case when n = 1
	for (int i = 2; i <= n; ++i)
	{
		int end = v.size() - 1;
		while (end >= 0) {
			v.push_back(v[end]);
			end--;
		}
 
		int cnt = (1 << i);
		for (int j = 0; j < cnt; ++j)
		{
			if (j < cnt / 2)v[j] += '0';
			else v[j] += '1';
		}
	}
	for (auto i : v)cout << i << endl;
}
 
int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
 
	int t = 1;;
	while (t--) {
		solve();
	}
 
	return 0;
}