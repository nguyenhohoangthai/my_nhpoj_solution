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
#define int long long
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

const int oo = 1e18;
const int maxN = 300005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, dp[maxN];
pii a[maxN];
vector<pii> container;
struct line {
int a, b;
    line() : a(0), b(oo) {}
    line(int a, int b) : a(a), b(b) {}
    int get(int x) {
        return a*x + b;
    }
};
struct lichao {
vector<line> tree;
    int len;
    lichao() {}
    lichao(int _len) {
        len = _len;
        tree.resize(4*len);
    }
    void update(int node, int l, int r, line f) {
        if (l == r) {
            if (tree[node].get(l) > f.get(l)) tree[node] = f;
            return;
        }
        int mid = (l + r) >> 1;
        if (tree[node].get(mid) > f.get(mid)) swap(tree[node], f);
        if (f.a > tree[node].a) update(node << 1, l, mid, f);
        if (f.a < tree[node].a) update(node << 1 | 1, mid + 1, r, f);
    }
    int query(int node, int l, int r, int x) {
        int res = tree[node].get(x);
        if (l == r) return res;
        int mid = (l + r) >> 1;
        if (x <= mid) return min(res, query(node << 1, l, mid, x));
        return min(res, query(node << 1 | 1, mid + 1, r, x));
    }
};
signed main() {
    fastio;
    #define test "dphl-04"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i].ff >> a[i].ss;

    sort(a+1, a+n+1, [] (const pii x, const pii y) {
        if (x.ff == y.ff) return x.ss < y.ss;
        return x.ff < y.ff;
    });

    fdto(i, n, 1) {
        if (container.empty() || a[i].ss > container.back().ss) container.pb(a[i]);
    }
    container.pb(make_pair(0, 0));
    reverse(container);

    int x_max = (int) 1e6;

    n = sz(container) - 1;

    lichao tree(x_max);

    dp[0] = 0;
    tree.update(1, 1, x_max, line(container[1].ss, dp[0]));

    fto(i, 1, n) {
        dp[i] = tree.query(1, 1, x_max, container[i].ff);
        if (i < n) tree.update(1, 1, x_max, line(container[i+1].ss, dp[i]));
    }

    cout << dp[n] << "\n";
    return 0;
}