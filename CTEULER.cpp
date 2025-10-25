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
const int maxN = 105;
//link snippet: C:/Users/nguye/AppData/Roaming/Sublime Text/Packages/User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, m;
set<int> adj[maxN];
stack<int> st;
vector<int> ans;
int main() {
    fastio;
    if (fopen("thptltt_170.inp", "r")) {
        freopen("thptltt_170.inp", "r", stdin);
        freopen("thptltt_170.out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v; cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    fto(i, 1, n) {
        if (sz(adj[i]) & 1) {
            cout << -1 << "\n";
            return 0;
        }
    }
    st.push(1);
    while (sz(st)) {
        int u = st.top();
        if (sz(adj[u])) {
            int v = *adj[u].begin();
            st.push(v);
            adj[u].erase(v);
            adj[v].erase(u);
        }
        else {
            st.pop();
            ans.pb(u);
        }
    }
    if (ans.back() != 1 || ans[0] != 1) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto x : ans) cout << x << " ";
    return 0;
}