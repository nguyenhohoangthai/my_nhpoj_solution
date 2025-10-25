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
int T, n, dp[maxN], ans[maxN];
vector<int> adj[maxN];
void dfs(int u, int p) {
    if (sz(adj[u]) == 1 && u != 1) {
        if ((u + 1) & 1) dp[u] = 1;
        return;
    }

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (dp[v]) ++dp[u];
    }
}
void reroot(int u, int p) {
    int t_dp_u = dp[u];
    int t_dp_p = dp[p];

    if (dp[u]) --dp[p];

    if (sz(adj[u]) == 1) dp[u] = 0;

    dp[u] += (dp[p] > 0);

    ans[u] = dp[u];

    for (int v : adj[u]) {
        if (v == p) continue;
        reroot(v, u);
    }

    dp[u] = t_dp_u;
    dp[p] = t_dp_p;
}
int main() {
    fastio;
    #define test "P179"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> T;
    while (T--) {
        cin >> n;
        fto(i, 1, n) adj[i].clear();

        fto(i, 1, n) {
            dp[i] = 0;
            ans[i] = 0;
        }

        fto(i, 1, n-1) {
            int u, v; cin >> u >> v;
            ++u; ++v;
            adj[u].pb(v);
            adj[v].pb(u);
        }

        dfs(1, 0);

        ans[1] = dp[1];

        for (int v : adj[1]) reroot(v, 1);

        fto(i, 1, n) cout << ans[i] << " ";
        cout << "\n";
    }
    return 0;
}