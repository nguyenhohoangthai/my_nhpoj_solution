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

int n, q, a[maxN];

struct smt {
int tree[4*maxN];
    int t;
    smt() {
        mem(tree, 0);
        t = 0;
    }

    void build(int _t) {
        t = _t;
    }

    int mex(int a, int b) {
        if (t == 0) return min(a, b);
        return max(a, b);
    }

    void init(int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        init(node << 1, l, mid);
        init(node << 1 | 1, mid + 1, r);
        tree[node] = mex(tree[node << 1], tree[node << 1 | 1]);
    }

    int query(int node, int l, int r, int u, int v) {
        if (u > r || v < l) return (t == 0 ? oo : 0);
        if (u <= l && r <= v) return tree[node];
        int mid = (l + r) >> 1;
        return mex(query(node << 1, l, mid, u, v), query(node << 1 | 1, mid + 1, r, u, v));
    }
};

smt it_mn, it_mx;

int main() {
    fastio;
    #define test "sinh"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }

    cin >> n >> q;
    fto(i, 1, n) cin >> a[i];

    it_mn.build(0);
    it_mx.build(1);

    it_mn.init(1, 1, n);
    it_mx.init(1, 1, n);

    while (q--) {
        int u, v; cin >> u >> v;
        cout << (it_mx.query(1, 1, n, u, v) - it_mn.query(1, 1, n, u, v)) << "\n";
    }
    return 0;
}