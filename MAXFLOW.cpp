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
int n, m, c[105][105], f[105][105], r[105][105], trace[105];
ll ans;

void init() {
    mem(r, 0);
    fto(i, 1, n) {
        fto(j, 1, n) {
            if (f[i][j] < c[i][j]) r[i][j] = c[i][j] - f[i][j];
            if (f[i][j]) r[j][i] = f[i][j];
        }
    }
}

int find() {
    init();
    queue<int> q;
    q.push(1);

    mem(trace, 0);

    trace[1] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();

        fto(v, 1, n) {
            if (!trace[v] && r[u][v]) {
                trace[v] = u;
                q.push(v);
            }
        }
    }

    return (trace[n] > 0);
}

void incr() {
    int d = oo;
    int v = n;

    while (trace[v] != v) {
        int u = trace[v];
        minimize(d, r[u][v]);
        v = u;
    }

    v = n;
    while (trace[v] != v) {
        int u = trace[v];

        if (f[u][v] < c[u][v]) f[u][v] += d;
        else f[v][u] -= d;

        v = u;
    }
}

int main() {
    fastio;
    #define test "MAXFLOW"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        c[u][v] = w;
    }
    while (1) {
        if (!find()) break;
        incr();
    }

    fto(i, 1, n) ans += f[1][i];

    cout << ans << "\n";
    return 0;
}