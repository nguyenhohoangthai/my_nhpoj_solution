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
int n, m, k, src, dst, f[101][101][101];
vector<pair<int, int>> adj[101];
int dp(int i, int prv, int cnt) {
    if (cnt > k+2) return oo;
    if (i == dst && src != dst) return 0;
    if (i == dst && src == dst && prv != i && cnt > 0) return 0;
    if (f[i][prv][cnt] != -1) return f[i][prv][cnt];
    int res = oo;
    for (auto x : adj[i]) {
        if (x.ff != prv || x.ff == dst) res = min(res, dp(x.ff, i, cnt+1) + x.ss);
    }
    return f[i][prv][cnt] = res;
}
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> n >> m >> k;
    fto(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    cin >> src >> dst;
    mem(f, -1);
    int ans = dp(src, 0, 0);
    cout << (ans == oo ? -1 : ans) << "\n";
    return 0;
}