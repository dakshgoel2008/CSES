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
    ll n; cin >> n;
    vector<ll> a(n);
    fr(i, n)cin >> a[i];
    ll sum = accumulate(all(a), 0LL);
    ll ans = sum;
    for (int mask = 0; mask < (1LL << n); ++mask)
    {
        ll s = 0;
        for (int i = 0; i < n; ++i)
        {
            if (mask & (1LL << i))s += a[i];
        }
        ans = min(ans, abs(sum - 2 * s));
    }
    cout << ans << endl;
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
