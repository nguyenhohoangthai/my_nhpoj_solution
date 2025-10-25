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
int n, in[maxN], used[maxN], cnt;
vector<int> adj[maxN];
pq q;
int main() {
    fastio;
    if (fopen("P466.inp", "r")) {
        freopen("P466.inp", "r", stdin);
        freopen("P466.out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n-1) {
        int u, v; cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        ++in[u]; ++in[v];
    }
    fto(u, 1, n) {
        if (in[u] == 1) q.push({1, u});
    }
    while (!q.empty()) {
        if (cnt >= n-2) {
            fto(i, 1, n) {
                if (!used[i]) cout << i << " ";
            }
            cout << "\n";
            break;
        }
        set<int> proc;
        while (!q.empty()) {
            int u = q.top().ss; q.pop();
            if (used[u]) continue;;
            ++cnt;
            for (int v : adj[u]) {
                --in[v];
                if (in[v] == 1) proc.insert(v);
            }
            used[u] = 1;
        }
        for (auto x : proc) q.push({in[x], x});
    }
    return 0;
}