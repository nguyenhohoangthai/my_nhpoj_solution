/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define ull unsigned long long
#define ii pair <int, int>
#define mtsii multiset <int>
#define mtsll multiset <long long>
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define fat(i, a) for (auto i : a)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, m, tree[4 * maxN], a[maxN], type, lazy[4 * maxN];
void pushdown(int node, int l, int r) {
    if (lazy[node] != -1) {
        tree[node] = (r - l + 1) * lazy[node];
        if (l != r) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = -1;
    }
}
void init(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}
int query(int node, int l, int r, int u, int v) {
    if (l > v || u > r || l > r || u > v) return 0;
    pushdown(node, l, r);
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    int q_1 = query(node*2, l, mid, u, v);
    int q_2 = query(node*2 + 1, mid + 1, r, u, v);
    return q_1 + q_2;
}
void update(int node, int l, int r, int u, int v, int x) {
    pushdown(node, l, r);
    if (l > v || u > r || l > r || u > v) return;
    if (u <= l && r <= v) {
        lazy[node] = x;
        pushdown(node, l, r);
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, u, v, x);
    update(2 * node + 1, mid + 1, r, u, v, x);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return;
}
int main() {
    fastio;
    cin >> n >> m;
    fto(i, 1, n) cin >> a[i];
    init(1, 1, n);
    memset(lazy, -1, sizeof lazy);
    while (m--) {
        cin >> type;
        if (type == 2) {
            int i, j; cin >> i >> j;
            cout << query(1, 1, n, i, j) << "\n";
        }
        else {
            int i, j, x; cin >> i >> j >> x;
            update(1, 1, n, i, j, x);
        }
    }
    return 0;
}