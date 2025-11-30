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
    int a, b; cin >> a >> b;
    // state -> dp[i][j] = minimum no of cuts for a*b grid.
    // i -> heigth and j -> width:
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 1e9));
 
    for (int i = 1; i <= a; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            if (i == j) {
                dp[i][j] = 0;       // stop dude if got square.
                continue;
            }
            for (int h = 1; h <= i / 2; ++h)
            {
                dp[i][j] = min(dp[i][j], dp[h][j] + dp[i - h][j] + 1);
            }
            for (int w = 1; w <= j / 2; ++w)
            {
                dp[i][j] = min(dp[i][j], dp[i][w] + dp[i][j - w] + 1);
            }
        }
    }
 
    cout << dp[a][b] << endl;
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