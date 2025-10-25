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
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text 3\Packages\User
int n, m, k, t, vs[105];
vector<vector<int>>g(100005);

void dfs(int a) {
    cout << a << " ";
    vs[a] = 1;
    for (auto x : g[a]) {
        if (vs[x] == 0) dfs(x);
    }
    return;
}

void bfs(int a) {
    queue<int> q;
    vs[a] = 1;
    q.push(a);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (auto x : g[v]) {
            if (vs[x] == 0) {
                q.push(x);
                vs[x] = 1;
            }
        }
    }
}
int main(){
    fastio;
    cin >> n >> m >> k;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    fto(i, 1, n) sort(g[i].begin(), g[i].end());
    while (k--) {
        int u; cin >> t >> u;
        fto(i, 1, n) vs[i] = 0;
        if (t == 1) dfs(u);
        else bfs(u);
        cout << "\n";
    }
}