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
char moveChar[] = {'D', 'U', 'R', 'L'};
 
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
 
const ll mod = 1e9 + 7;
 
#define fr(i, n) for (ll i = 0; i < n; ++i)
#define all(v) v.begin(), v.end()
#define pb push_back
 
void solve() {
    int n, m; cin >> n >> m;
    vector<string> adj(n);
    fr(i, n)cin >> adj[i];
    pair<int, int> src, des;
    fr(i, n) {
        fr(j, m) {
            if (adj[i][j] == 'A')src = {i, j};
            if (adj[i][j] == 'B')des = {i, j};
        }
    }
    // BFS:
    queue<pair<int, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dir(n, vector<int>(m));
    q.push(src);
    int hai = 0;
    vis[src.first][src.second] = 1;
    while (!q.empty()) {
        auto &[x, y] = q.front();    q.pop();
        // child traversal:
        for (int i = 0; i < 4; ++i)
        {
            int ni = x + dx[i];
            int nj = y + dy[i];
            if (ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && adj[ni][nj] != '#') {
                vis[ni][nj] = 1;
                q.push({ni, nj});
                dir[ni][nj] = i;
                if (make_pair(ni, nj) == des) {
                    hai = 1;
                    break;
                }
            }
        }
        if (hai)break;
    }
    cout << (hai ? "YES" : "NO") << endl;
    // now we need to contruct the path also:
    // using backtracking solution to solve this!
    if (hai) {
        // Construct the path using backtracking
        string ans;
        int dxx = des.first, dyy = des.second;
        int sx = src.first, sy = src.second;
        while (!(dxx == sx && dyy == sy)) {
            int p = dir[dxx][dyy];
            ans += moveChar[p];
            dxx -= dx[p];
            dyy -= dy[p];
        }
        reverse(all(ans));
        cout << ans.size() << endl;
        cout << ans << endl;
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