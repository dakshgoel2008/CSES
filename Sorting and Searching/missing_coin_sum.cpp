#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
 
	sort(a.begin(), a.end());
 
	ll maxRange = 0; // This represents the largest number we can form
	for (int i = 0; i < n; ++i) {
		if (a[i] > maxRange + 1) {
			// If the current number creates a gap, we cannot form maxRange + 1
			break;
		}
		maxRange += a[i]; // Extend the range
	}
 
	// The first missing number is maxRange + 1
	cout << maxRange + 1 << endl;
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
}c