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
 
vector<ll> djikstra(vector<vector<pair<ll, ll>>> adj, ll src, ll n) {
    priority_queue < pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;  // dist[node], node.
    vector<ll> dis(n + 1, LLONG_MAX), parent(n + 1, -1);    // initially distance = LLONG_MAX
    parent[src] = src;
    dis[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [cd, u] = pq.top(); pq.pop();
        if (cd > dis[u]) continue;
 
        for (auto &[v, w] : adj[u]) {
            // edge weight + dis of parent
            if (w + dis[u] < dis[v]) {
                dis[v] = w + dis[u];
                parent[v] = u;
                pq.push({dis[v], v});
            }
        }
    }
    return dis;
}
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pair<ll, ll>>> adj(n + 1), rev(n + 1);
    for (int i = 0; i < m; ++i)
    {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
        rev[v].pb({u, w});
    }
 
    vector<ll> distFromSrc = djikstra(adj, 1, n);
    vector<ll> distToDest = djikstra(rev, n, n);
 
    ll ans = distFromSrc[n];
    for (ll u = 1; u <= n; u++) {
        for (auto [v, w] : adj[u]) {
            w /= 2;
            if (distFromSrc[u] == LLONG_MAX || distToDest[v] == LLONG_MAX) continue;
            ll dis = distFromSrc[u] + w + distToDest[v];
            ans = min(dis, ans);
        }
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