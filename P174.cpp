/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define int long long
#define mem(x, a) memset(x, (long long) a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const long long oo = 2000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, m, d[maxN], s, t;
vector<pair<int, int>> adj[maxN];
void dijkstra() {
    memset(d, oo, sizeof d);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.push({0, s});
    d[s] = 0;
    while (!Q.empty()) {
        int u = Q.top().ss;
        int w = Q.top().ff;
        Q.pop();
        if (w != d[u]) continue;
        for (auto x : adj[u]) {
            int tmp = max(d[u], x.ss);
            if (d[x.ff] > tmp) {
                d[x.ff] = tmp;
                Q.push({tmp, x.ff});
            }
        }
    }
    cout << d[t] << "\n";
}
signed main() {
    fastio;
    cin >> n >> m >> s >> t;
    fto(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w}); adj[v].pb({u, w});
    }
    dijkstra();
    return 0;
}