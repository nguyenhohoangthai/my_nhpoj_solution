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
int n, x, par[maxN], child[maxN], a[maxN];
vector<int> adj[maxN];

void trace(int u) {
    if (child[u] == 0) return;
    cout << child[u] << " ";
    trace(child[u]);
}

int main() {
    fastio;
    #define test "P293"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> x;

    fto(i, 0, n-1) child[i] = i+1;
    fto(i, 1, n) par[i] = i-1;

    fto(_, 1, x) {
        int u, v; cin >> u >> v;
        child[par[u]] = child[u];
        par[child[u]] = par[u];

        child[par[v]] = u;
        child[u] = v;
        par[u] = par[v];
        par[v] = u;
    }

    trace(0);
    return 0;
}