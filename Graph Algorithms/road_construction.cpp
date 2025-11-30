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
 
class UnionFind {
public:
    vector<ll> p, rank, size;
    UnionFind(ll n) {
        p.assign(n, 0), rank.assign(n, 0);  size.assign(n, 1);
        iota(all(p), 0);
    }
    ll findSet(ll i) {return p[i] == i ? i : p[i] = findSet(p[i]);}
    bool isSameSet(ll i, ll j) {return findSet(i) == findSet(j);}
 
    void unionSet(ll i, ll j) {
        if (!isSameSet(i, j)) {
            ll x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) swap(x, y);
            // we are taking y as parent always.
            p[x] = y;
            if (rank[x] == rank[y]) rank[y]++;
            size[y] += size[x];
        }
    }
};
 
void solve() {
    ll n, m; cin >> n >> m;
    UnionFind dsu(n);
    ll cmp = n;
    ll maxi = 0;
    for (int i = 0; i < m; ++i)
    {
        ll u, v; cin >> u >> v;
        u--; v--;
        if (!dsu.isSameSet(u, v))cmp--;
        dsu.unionSet(u, v);
        ll p1 = dsu.findSet(u);
        maxi = max({maxi, dsu.size[p1]});
        cout << cmp << " " << maxi << endl;
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