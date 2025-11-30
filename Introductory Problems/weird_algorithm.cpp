#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
void helper(ll n) {
    if (n == 1) {
        cout << 1 << " ";
        return;
    }
    cout << n << " ";
 
    if (n & 1) n = 3 * n + 1;
    else {
        n /= 2;
    }
    helper(n);
}
void solve() {
    ll n; cin >> n;
    helper(n);
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