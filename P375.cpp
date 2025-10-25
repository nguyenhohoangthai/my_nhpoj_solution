/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define int long long
#define fto(i, a, b) for (int i = (int) a; i <= (int) b; ++i)
#define fdto(i, a, b) for (int i = (int) a; i >= (int) b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define bit_count(x) __builtin_popcount(x)
#define bit_countll(x) __builtin_popcountll(x)
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 100000000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
pii st_11[1005], st_12[1005];
int f[1005][1005][3];
int n, m;
int bp(int x) {
    return x*x;
}
int dist(pii a, pii b) {
    return bp(a.ff - b.ff) + bp(a.ss - b.ss);
}

int dp(int i, int j, int vis) {
    if (i == m && j < n) return oo;
    if (i == m && j == n) return 0;
    if (f[i][j][vis] != -1) return f[i][j][vis];
    int res = oo;
    if (vis == 1) {
        if (i < m) minimize(res, dp(i+1, j, 1) + dist(st_11[i], st_11[i+1]));
        if (j < n) minimize(res, dp(i, j+1, 2) + dist(st_11[i], st_12[j+1]));
    }
    if (vis == 2) {
        if (i < m) minimize(res, dp(i+1, j, 1) + dist(st_11[i+1], st_12[j]));
        if (j < n) minimize(res, dp(i, j+1, 2) + dist(st_12[j], st_12[j+1]));
    }
    return f[i][j][vis] = res;
}

void solve() {
    mem(f, -1);
    cout << dp(1, 0, 1) << "\n";
}

void input() {
    cin >> m >> n;
    fto(i, 1, m) cin >> st_11[i].ff >> st_11[i].ss;
    fto(i, 1, n) cin >> st_12[i].ff >> st_12[i].ss;
}

signed main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    input();
    solve();
    return 0;
}