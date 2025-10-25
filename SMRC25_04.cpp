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
#pragma GCC optimize("O3", "unroll-loops")
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

const int oo = 1e9 + 7;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, k, q, p[20], c[1005][1005], dis[1005][1005], f[MASK(17)][20], cost[20][20];

int main() {
    #define test "SMRC25_04"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    fastio;

    cin >> n >> k >> q;

    fto(i, 0, k-1) cin >> p[i];
    fto(i, 1, n) {
        fto(j, 1, n) cin >> c[i][j];
    }
    fto(i, 1, n) mem(dis[i], 0x3f);
    fto(i, 0, k-1) {
        pq Q;
        dis[p[i]][p[i]] = 0;
        Q.push({0, p[i]});
        while (!Q.empty()) {
            auto [w, u] = Q.top(); Q.pop();
            if (w > dis[p[i]][u]) continue;
            fto(v, 1, n) {
                if (dis[p[i]][v] > dis[p[i]][u] + c[u][v]) {
                    dis[p[i]][v] = dis[p[i]][u] + c[u][v];
                    Q.push({dis[p[i]][v], v});
                }
            }
        }
    }
    fto(i, 0, k-1) {
        pq Q;
        dis[p[i]][p[i]] = 0;
        Q.push({0, p[i]});
        while (!Q.empty()) {
            auto [w, u] = Q.top(); Q.pop();
            if (w > dis[u][p[i]]) continue;
            fto(v, 1, n) {
                if (dis[v][p[i]] > dis[u][p[i]] + c[v][u]) {
                    dis[v][p[i]] = dis[u][p[i]] + c[v][u];
                    Q.push({dis[v][p[i]], v});
                }
            }
        }
    }

    fto(start, 0, k-1) {

        memset(f, 0x3f, sizeof f);

        f[MASK(start)][start] = 0;
        cost[start][start] = oo;
        fto(mask, 1, MASK(k) - 1) {
            if (!BIT(mask, start)) continue;
            for (int sub = mask; sub > 0; sub &= (sub - 1)) {
                int u = __builtin_ctz(sub);
                for (int nxt_sub = (~mask) & (MASK(k) - 1); nxt_sub > 0; nxt_sub &= (nxt_sub - 1)) {
                    int v = __builtin_ctz(nxt_sub);
                    minimize(f[mask | MASK(v)][v], f[mask][u] + dis[p[u]][p[v]]);
                }
            }
        }
        int base = MASK(k) - 1;
        fto(e, 0, k-1) cost[start][e] = f[base][e];
    }

    fto(_, 1, q) {
        int u, v; cin >> u >> v;
        int ans = oo;
        fto(start, 0, k-1) {
            fto(e, 0, k-1) minimize(ans, dis[u][p[start]] + cost[start][e] + dis[p[e]][v]);
        }
        cout << ans << "\n";
    }
    return 0;
}