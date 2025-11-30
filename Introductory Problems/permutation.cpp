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
	if (n == 1) {
		cout << 1 << endl;
		return;
	}
	if (n == 4) {
		cout << "2 4 1 3" << endl;
		return;
	}
	if (n <= 4) {
		cout << "NO SOLUTION" << endl;
		return;
	}
	for (int i = 1; i <= n; i += 2) cout << i << " ";
	for (int i = 2; i <= n; i += 2) cout << i << " ";
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