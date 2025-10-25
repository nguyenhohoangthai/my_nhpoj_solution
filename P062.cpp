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
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, u, v, w, ans;
vector<pair<int, int>> adj[50005];
vector<int> vis;
int dfs(int u) {
    int res = 0;
    vis[u] = 1;
    for (auto x : adj[u]) {
        int s = 0;
        if (!vis[x.ff]) s = dfs(x.ff) + x.ss;
        if (s > 0) res += s;
    }
    ans = max(ans, res);
    return res;
}
int main() {
    fastio;
    cin >> n;
    ans = -oo;
    vis.resize(n+5, 0);
    fto(i, 1, n) {
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    dfs(1);
    cout << ans << "\n";
    return 0;
}