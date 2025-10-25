/*Hoang Thai*/
#include <bits/stdc++.h>
#pragma GCC optimize("O3", "unroll-loops")
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
#define pq priority_queue<pii, vector<pii>, greater<pii> >
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

const int oo = 1000000007;
const int maxN = 100005;

bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);}
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);}

int n, d, ans, a[maxN], num, tree[4*maxN];
vector<int> all;
map<int, int> color;

void compress() {
    fto(i, 1, n) all.pb(a[i]);
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (auto x : all) color[x] = ++num;
}

void update(int node, int l, int r, int u, int v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) maximize(tree[node], v);
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, u, v);
    update(node << 1 | 1, mid + 1, r, u, v);
    tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}

int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return max(query(node << 1, l, mid, u, v), query(node << 1 | 1, mid + 1, r, u, v));
}

signed main() {
    fastio;
    #define test "P521"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n >> d;
    fto(i, 1, n) cin >> a[i];

    compress();
    fto(i, 1, n) {
        int low = 0;
        int high = sz(all) - 1;
        int res = -1;
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (all[mid] <= a[i] - d) {
                res = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        if (res == -1) update(1, 1, num, color[a[i]], 1);
        else update(1, 1, num, color[a[i]], query(1, 1, num, 1, color[all[res]]) + 1);
    }
    cout << tree[1] << "\n";
    return 0;
}