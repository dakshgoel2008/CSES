/**
    author:  UG_BEAST
**/
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll mod = 1e9 + 7;
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
 
void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> prices(n), pages(n);
    fr(i, n)cin >> prices[i];
    fr(i, n)cin >> pages[i];
 
    // state -> dp[i][b] = max pages that can be read from book ith to n - th book
    // provided we have a budget of b.
    vector<ll> curr(x + 1), next(x + 1, 0);
    for (int i = n - 1; i >= 0; --i) {
        for (int b = 0; b <= x; ++b) {
            int pick = 0, skip = 0;
            skip = next[b];
            if (b >= prices[i])pick = pages[i] + next[b - prices[i]];
            curr[b] = max(pick, skip);
        }
        next = curr;
    }
    cout << curr[x] << endl;
}
 
int main() {
    fastio();
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}