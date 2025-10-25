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
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, m, cnt;
vector<int> adj[maxN], bridge[maxN];
vector<int> num, low;
pair<int, int> query[maxN], unsort[maxN];
void dfs(int u, int p) {
    num[u] = low[u] = cnt++;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!num[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] == num[v]) {
                bridge[u].pb(v);
                bridge[v].pb(u);
            }
        }
        else low[u] = min(low[u], num[v]);
    }
}
int main() {
    fastio;
    cin >> n;
    num.resize(n+5);
    low.resize(n+5);
    fto(i, 1, n) {
        int u, v; cin >> u >> v;
        query[i] = {u, v};
        unsort[i] = {u, v};
        adj[u].pb(v); adj[v].pb(u);
    }
    sort(unsort+1, unsort+n+1);
    fto(i, 2, n) {
        if (unsort[i].ff == unsort[i-1].ff && unsort[i].ss == unsort[i-1].ss) {
            cout << unsort[i].ff << " " << unsort[i].ss << "\n";
            return 0;
        }
    }
    cnt = 1;
    fto(i, 1, n) {
        if (!num[i]) dfs(i, i);
    }
    fdto(i, n, 1) {
        bool found = false;
        for (auto x : bridge[query[i].ff]) {
            if (x == query[i].ss) {
                found = true;
                break;
            }
        }
        if (found == false) {
            cout << query[i].ff << " " << query[i].ss << "\n";
            break;
        }
    }
    return 0;
}