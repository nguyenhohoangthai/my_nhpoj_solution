/*Code by Hoang Thai*/
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

const int oo = 1000000007;
const int maxN = 1000005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

int n, m, a[maxN], par[maxN], ans, on[maxN], prv, depth[maxN];
vector<int> adj[maxN], value[maxN], diff;
int deptrai[1001][1001];

int getId(int i, int j) {
    return (i-1) * m + j;
}

int find_set(int u) {
    return (u == par[u] ? u : par[u] = find_set(par[u]));
}

int union_set(int u, int v) {
    u = find_set(u);
    v = find_set(v);

    if (u == v) return 0;
    if (depth[u] < depth[v]) swap(u, v);
    depth[u] += depth[v];

    prv -= (on[u] + on[v]);
    par[v] = u;

    on[u] = on[u] | on[v];
    on[v] = 0;

    prv += on[u];
    return 1;
}

bool check(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m);
}


int main() {
    fastio;
    #define test "P156"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> m;

    fto(i, 1, n) {
        fto(j, 1, m) {
            cin >> deptrai[i][j];
        }
    }

    fto(i, 1, n) {
        fto(j, 1, m) {
            int cur = getId(i, j);
            int x = deptrai[i][j];
            fto(d, 0, 3) {
                int n_i = i + dx[d];
                int n_j = j + dy[d];
                if (check(n_i, n_j) && deptrai[n_i][n_j] >= deptrai[i][j]) adj[cur].pb(getId(n_i, n_j));
            }

            par[cur] = cur;
            a[cur] = x;
            value[x].pb(cur);
            diff.pb(x);
            depth[cur] = 1;
        }
    }

    sort(diff.begin(), diff.end());
    diff.erase(unique(diff.begin(), diff.end()), diff.end());

    fdto(tmp, sz(diff) - 1, 0) {
        int level = diff[tmp];
        for (auto i : value[level]) {
            bool flag = true;
            int p_i = find_set(i);
            for (int n_i : adj[i]) {
                int p_n_i = find_set(n_i);
                if (a[n_i] > a[i]) {
                    union_set(n_i, i);
                    flag = false;
                }
                else if (a[i] == a[n_i]) union_set(n_i, i);
            }
            if (flag) {
                p_i = find_set(i);
                if (!on[p_i]) ++prv;
                on[p_i] = 1;
            }
        }

        maximize(ans, prv);
    }

    cout << ans << "\n";
    return 0;
}