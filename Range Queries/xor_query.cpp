#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll mod = 1e9 + 7;
 
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1) res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;} // only for prime m
ll lcm(ll a, ll b) {return (a * b) / __gcd(a, b);}
 
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
void solve() {
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    fr(i, n)cin >> a[i];
    vector<ll> pre(n);
    pre[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        pre[i] = pre[i - 1] ^ a[i];
    }
    for (int i = 0; i < q; ++i)
    {
        ll a, b; cin >> a >> b;
        a -= 1, b -= 1;
        cout << ((a - 1 >= 0) ? (pre[b] ^ pre[a - 1]) : pre[b]) << endl;
    }
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