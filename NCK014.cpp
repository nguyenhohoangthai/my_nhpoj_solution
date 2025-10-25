/*Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define reverse(x) reverse(x.begin(), x.end())
#define ff first
#define ss second
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define pii pair<int, int>
#define pq priority_queue<pii, vector<pii>, greater<pii>>
#define ll long long
#define int long long
#define db double
#define sz(a) (int) a.size()
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define yes "YES"
#define no "NO"
#define PI acos(-1)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 200005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

vector<vector<int>> pascal={{0},
                            {1, 1},
                            {1, 2, 1},
                            {1, 3, 3, 1},
                            {1, 4, 6, 4, 1},
                            {1, 5, 10, 10, 5, 1},
                            {1, 6, 15, 20, 15, 6, 1},
                            {1, 7, 21, 35, 35, 21, 7, 1},
                            {1, 8, 28, 56, 70, 56, 28, 8, 1},
                            {1, 9, 36, 84, 126, 126, 84, 36, 9, 1},
                            {1, 10, 45, 120, 210, 252, 210, 120, 45, 10, 1}
};

int n, k, sz[maxN];
ll res, dp[11][maxN], ans[maxN];
vector<pii> adj[maxN];

ll nhan(ll a, ll b) {
    return (a * b) % oo;
}

void dfs(int u, int p) {
    sz[u] = 1;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
    dp[0][u] = sz[u] - 1;
    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        int w_r = w;
        fto(i, 1, k) {
            dp[i][u] = (dp[i][u] + w_r) % oo;
            w_r = nhan(w_r, w);
            int r_p = 1;
            fto(j, 0, sz(pascal[i]) - 1) {
                dp[i][u] = (dp[i][u] + nhan(nhan(pascal[i][j], r_p), dp[i - j][v])) % oo;
                r_p = nhan(r_p, w);
            }
        }
    }
}

void reroot(int u, int p, int w) {
    int tmp_sz_u = sz[u];
    int tmp_sz_p = sz[p];
    vector<int> tmp_dp_u, tmp_dp_p;
    fto(i, 0, k) {
        tmp_dp_u.pb(dp[i][u]);
        tmp_dp_p.pb(dp[i][p]);
    }

    sz[p] -= sz[u];
    dp[0][p] = sz[p] - 1;
    int w_r = w;
    fto(i, 1, k) {
        dp[i][p] = (dp[i][p] - w_r + oo) % oo;
        w_r = nhan(w_r, w);
        int r_p = 1;
        fto(j, 0, sz(pascal[i]) - 1) {
            dp[i][p] = (dp[i][p] - nhan(nhan(pascal[i][j], r_p), dp[i - j][u]) + oo) % oo;
            r_p = nhan(r_p, w);
        }
    }

    sz[u] += sz[p];
    dp[0][u] = sz[u] - 1;
    w_r = w;
    fto(i, 1, k) {
        dp[i][u] = (dp[i][u] + w_r) % oo;
        w_r = nhan(w_r, w);
        int r_p = 1;
        fto(j, 0, sz(pascal[i]) - 1) {
            dp[i][u] = (dp[i][u] + nhan(nhan(pascal[i][j], r_p), dp[i - j][p])) % oo;
            r_p = nhan(r_p, w);
        }
    }

    ans[u] = dp[k][u];

    for (auto [v, w] : adj[u]) {
        if (v == p) continue;
        reroot(v, u, w);
    }

    sz[u] = tmp_sz_u;
    sz[p] = tmp_sz_p;
    fto(i, 0, k) {
        dp[i][u] = tmp_dp_u[i];
        dp[i][p] = tmp_dp_p[i];
    }
}

signed main() {
    fastio;
    #define test "NCK014"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n-1) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].pb(make_pair(v, w));
        adj[v].pb(make_pair(u, w));
    }

    dfs(1, 0);
    ans[1] = dp[k][1];

    for (auto [v, w] : adj[1]) reroot(v, 1, w);

    fto(i, 1, n) res = (res + ans[i]) % oo;
    cout << res << "\n";
    return 0;
}