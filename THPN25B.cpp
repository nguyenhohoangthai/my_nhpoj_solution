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
const int maxN = 200005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, a[maxN], cost[maxN], q, num, ans;
int tree[4*maxN], range[4*maxN], lazy[4*maxN];
map<int, int> color;
set<int> values;
void push(int node, int l, int r) {
    if (!lazy[node]) return;
    range[node] += (r - l + 1) * lazy[node];
    if (l != r) {
        lazy[node << 1] += lazy[node];
        lazy[node << 1 | 1] += lazy[node];
    }
    lazy[node] = 0;
}
void update_range(int node, int l, int r, int u, int v, int x) {
    push(node, l, r);
    if (u > r || v < l) return;
    if (u <= l && r <= v) {
        lazy[node] += x;
        push(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update_range(node << 1, l, mid, u, v, x);
    update_range(node << 1 | 1, mid + 1, r, u, v, x);
    range[node] = range[node << 1] + range[node << 1 | 1];
}
int query_range(int node, int l, int r, int u, int v) {
    push(node, l, r);
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return range[node];
    int mid = (l + r) >> 1;
    return query_range(node << 1, l, mid, u, v) + query_range(node << 1 | 1, mid + 1, r, u, v);
}
void update(int node, int l, int r, int u, int v) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(node << 1, l, mid, u, v);
    update(node << 1 | 1, mid + 1, r, u, v);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return query(node << 1, l, mid, u, v) + query(node << 1 | 1, mid + 1, r, u, v);
}

int get(int x, int val) {
    if (x < a[x]) {
        update_range(1, 1, n, x, a[x] - 1, val);
        return query(1, 1, n, x, a[x] - 1);
    }
    update_range(1, 1, n, a[x], x - 1, val);
    return query(1, 1, n, a[x], x - 1);
}

void prepare() {
    fto(i, 1, n) values.insert(a[i]);
    for (auto x : values) color[x] = ++num;
    fto(i, 1, n) a[i] = color[a[i]];

    fto(i, 1, n-1) update(1, 1, n, i, cost[i]);
    fto(i, 1, n) {
        if (a[i] == i) continue;
        ans += get(i, 1);
    }
}

signed main() {
    fastio;
    #define test "THPN25B"
if (fopen(test".inp", "r")) {
        freopen(test".inp", "r", stdin);
        freopen(test".out", "w", stdout);
    }
    cin >> n;
    fto(i, 1, n) cin >> a[i];
    fto(i, 1, n-1) cin >> cost[i];

    prepare();

    cout << ans << "\n";

    cin >> q;

    while (q--) {
        int type, x, y; cin >> type >> x >> y;
        if (type == 1) {
            ans -= get(x, -1);
            ans -= get(y, -1);
            swap(a[x], a[y]);
            ans += get(x, 1);
            ans += get(y, 1);
        }
        else {
            int cnt = query_range(1, 1, n, x, x);
            ans += cnt * (y - query(1, 1, n, x, x));
            update(1, 1, n, x, y);
        }
        cout << ans << "\n";
    }
    return 0;
}