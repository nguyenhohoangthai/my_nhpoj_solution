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
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m, sz[1001];
ll dp[1001][1001][2], store[1001][2], best[1001], a[1001];
vector<int> adj[1001];
vector<int> lead;

void dfs(int u, int p) {
    fto(i, 0, n) dp[u][i][0] = dp[u][i][1] = 1e15;
    sz[u] = 1;

    dp[u][0][0] = 0;

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);

        fto(i, 0, sz[u] + sz[v]) store[i][0] = store[i][1] = 1e15;

        fto(i, 0, sz[u]) {
            fto(j, 0, sz[v]) {
                store[i+j][0] = min(store[i+j][0], dp[u][i][0] + min(dp[v][j][0], dp[v][j][1]));
                store[i+j][1] = min(store[i+j][1], dp[u][i][1] + min(dp[v][j][0], dp[v][j][1]));

                if (i) store[i+j][1] = min(store[i+j][1], dp[u][i-1][0] + a[u] + dp[v][j][1]);
                if (j) store[i+j][1] = min(store[i+j][1], dp[u][i][1] + a[v] + dp[v][j-1][0]);
                if (i && j) store[i+j][1] = min(store[i+j][1], dp[u][i-1][0] + dp[v][j-1][0] + a[u] + a[v]);
            }
        }

        fto(i, 0, sz[u] + sz[v]) {
            dp[u][i][0] = min(dp[u][i][0], store[i][0]);
            dp[u][i][1] = min(dp[u][i][1], store[i][1]);
        }

        sz[u] += sz[v];
    }
}

void init() {
    fto(i, 2, n) best[i] = 1e15;
    fto(i, 2, n) {
        for (int x : lead) best[i] = min(best[i], min(dp[x][i][0], dp[x][i][1]));
    }

    for (int v : lead) {
        if (v == 1) continue;

        fto(i, 0, sz[1]) {
            fto(j, 0, sz[v]) {
                best[i+j] = min(best[i+j], min(dp[1][i][0], dp[1][i][1]) + min(dp[v][j][0], dp[v][j][1]));
            }
        }
        fto(i, 0, sz[1] + sz[v]) store[i][0] = store[i][1] = 1e15;

        fto(i, 0, sz[1]) {
            fto(j, 0, sz[v]) {
                store[i+j][0] = min(store[i+j][0], dp[1][i][0] + min(dp[v][j][0], dp[v][j][1]));
                if (i) store[i+j][1] = min(store[i+j][1], dp[1][i][1] + min(dp[v][j][0], dp[v][j][1]));
            }
        }

        fto(i, 0, sz[1] + sz[v]) {
            dp[1][i][0] = min(dp[1][i][0], store[i][0]);
            dp[1][i][1] = min(dp[1][i][1], store[i][1]);
        }
        sz[1] += sz[v];
    }
}

int check(int num, int mx) {
    return (best[num] <= mx);
}

int main() {
    fastio;
    #define test "BIMAT"
if (fopen(test".INP", "r")) {
        freopen(test".INP", "r", stdin);
        freopen(test".OUT", "w", stdout);
    }

    cin >> n >> m;
    fto(i, 1, n) cin >> a[i];

    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    fto(i, 1, n) {
        if (!sz[i]) {
            lead.pb(i);
            dfs(i, -1);
        }
    }

    init();

    int q; cin >> q;
    while (q--) {
        int s; cin >> s;
        int low = 2;
        int high = n;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (check(mid, s)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        cout << ans << "\n";
    }
    return 0;
}