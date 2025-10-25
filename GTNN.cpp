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
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

const int oo = 1000000007;
const int maxN = 100001;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
struct Line {
int a, b;
    Line(int _a, int _b) {
        a = _a;
        b = _b;
    }
    Line() {
        a = 0;
        b = maxN;
    }
    long long get(long long x) {
        return a * x + b;
    }
};
Line tree[4*maxN];
void update(int node, int l, int r, Line x) {
    int mid = (l + r) >> 1;
    bool _left_better = x.get(l) < tree[node].get(l);
    bool _mid_better = x.get(mid) < tree[node].get(mid);
    if (_mid_better) swap(tree[node], x);
    if (l == r) return;
    if (_left_better != _mid_better) update(node << 1, l, mid, x);
    else update(node << 1 | 1, mid + 1, r, x);
}
long long query(int node, int l, int r, long long x) {
    if (l == r) return tree[node].get(x);
    int mid = (l + r) >> 1;
    if (x <= mid) return min(tree[node].get(x), query(node << 1, l, mid, x));
    return min(tree[node].get(x), query(node << 1 | 1, mid + 1, r, x));
}
int n, q;
int main() {
    fastio;
    if (fopen("LICHAO.inp", "r")) {
        freopen("LICHAO.inp", "r", stdin);
        freopen("LICHAO.out", "w", stdout);
    }
    cin >> n >> q;
    fto(i, 1, n) {
        int u, v; cin >> u >> v;
        update(1, 0, maxN, Line(u, v));
    }
    while (q--) {
        int x; cin >> x;
        cout << query(1, 0, maxN, x) << "\n";
    }
    return 0;
}