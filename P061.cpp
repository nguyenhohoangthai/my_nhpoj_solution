/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, m, visited[100005], cnt;
vector<int> adj[100005], tplt[100005], mx;
void dfs(int i) {
    visited[i] = 1;
    tplt[cnt].pb(i);
    for (auto u : adj[i]) {
        if (!visited[u]) dfs(u);
    }
}
int main() {
    fastio;
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }
    fto(i, 1, n) {
        if (!visited[i]) {
            ++cnt;
            dfs(i);
            mx.pb(tplt[cnt].size());
        }
    }
    sort(mx.begin(), mx.end());
    cout << mx[sz(mx) - 1] + mx[sz(mx) - 2] << "\n";
    return 0;
}