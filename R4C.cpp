/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, k, ans, point_to[maxN], tree[maxN * 4];
pair<int, int> nxt[maxN];
vector<int> adj[maxN];
void update(int node, int l, int r, int u, int v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, u, v);
    update(node << 1 | 1, mid + 1, r ,u, v);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, u, v) + query(node << 1 | 1, mid + 1, r, u, v);
}
void dfs(int u, int p) {
    ans += query(1, 1, n, nxt[u].ff, nxt[u].ss);
    update(1, 1, n, u, 1);
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    update(1, 1, n, u, 0);
    return;
}
int main() {
    fastio;
    if (fopen("R4C.inp", "r")) {
        freopen("R4C.inp", "r", stdin);
        freopen("R4C.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        point_to[v] += 1;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    fto(i, 1, n) {
        nxt[i].ff = max(0, i - k);
        nxt[i].ss = min(n, i + k);
    }
    fto(i, 1, n) {
        if (point_to[i] == 0) {
            dfs(i, 0);
            break;
        }
    }
    cout << ans << "\n";
    return 0;
}