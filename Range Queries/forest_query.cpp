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
 
	int n, q ; cin >> n >> q;
	vector<vector<int>> a(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			char ch; cin >> ch;
			if (ch == '.')a[i][j] = 0;		// not present
			else a[i][j] = 1;		// present
		}
	}
 
	vector<vector<int>> pre(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			pre[i][j] = a[i][j];
			if (i > 0) {
				pre[i][j] += pre[i - 1][j];
			}
			if (j > 0) {
				pre[i][j] += pre[i][j - 1];
			}
			if (i > 0 and j > 0) {
				pre[i][j] -= pre[i - 1][j - 1];
			}
		}
	}
 
	while (q--) {
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		int ans = pre[x2 - 1][y2 - 1];
		if (x1 - 1 > 0) {
			ans -= pre[x1 - 2][y2 - 1];
		}
		if (y1 - 1 > 0) {
			ans -= pre[x2 - 1][y1 - 1 - 1];
		}
		if (x1 - 1 > 0 && y1 - 1 > 0) {
			ans += pre[x1 - 2][y1 - 2];
		}
		cout << ans << endl;
	}
 
	return 0;
}