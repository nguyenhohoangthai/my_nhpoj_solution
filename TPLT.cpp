#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fllto(i, a, b) for (long long i = a; i <= b; ++i)
#define flldto(i, a, b) for (long long i = a; i >= b; --i)
#define fvt(i, g) for (int i : g)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define open(a) freopen(a".inp", "r", stdin); freopen(a".out", "w", stdout);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text 3\Packages\User
int n, m, visited[30005];
vector<int> adj[30005];
void dfs(int u) {
    visited[u] = 1;
    for (auto v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

int main(){
    fastio;
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    int ans = 0;
    fto(u, 1, n) {
        if (!visited[u]) {
            ++ans;
            dfs(u);
        }
    }
    cout << ans;
    return 0;
}