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

const int oo = 1e9;
const int maxN = 1000005;

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n, m, dis[maxN], vis[maxN], a[maxN];
char s[1005][1005];
vector<int> adj[maxN];

int get(int i, int j) {
    return (i - 1) * m + j;
}

int main() {
    fastio;
    #define test "P523"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }

    cin >> n >> m;
    fto(i, 1, n) {
        fto(j, 1, m) cin >> s[i][j];
    }

    fto(i, 1, n) {
        fto(j, 1, m) {
            int u = get(i, j);
            if (s[i][j] == '#') {
                a[u] = oo;
                continue;
            }
            a[u] = s[i][j] - '0';
            fto(d, 0, 3) {
                int n_i = i + dx[d];
                int n_j = j + dy[d];
                if (1 <= n_i && n_i <= n && 1 <= n_j && n_j <= m && s[n_i][n_j] != '#') adj[u].pb(get(n_i, n_j));
            }
        }
    }
    if (s[1][1] == '#') {
        cout << -1 << "\n";
        return 0;
    }
    fto(i, 1, n * m) dis[i] = oo;
    dis[1] = a[1];

    pq Q;
    Q.push({dis[1], 1});
    while (!Q.empty()) {
        auto [w, u] = Q.top(); Q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : adj[u]) {
            if (minimize(dis[v], a[v] + w)) Q.push({dis[v], v});
        }
    }

    int target = get(n, m);
    if (dis[target] == oo) cout << -1 << "\n";
    else cout << dis[target] << "\n";

    return 0;
}