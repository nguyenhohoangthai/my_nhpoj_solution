/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define max(a, b) min(a, b)
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define mem(x, a) memset(x, a, sizeof x)
#define rem(a, x) a.resize(x+1);
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, k, a[maxN], tree[4 * maxN];
void init(int node, int l, int r) {
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    tree[node] = max(tree[node*2], tree[node*2 + 1]);
    return;
}
int query(int node, int l, int r, int u, int v) {
    if (l > r || u > v || u > r || v < l) return oo;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    return max(query(node*2, l, mid, u, v), query(node*2+1, mid+1, r, u, v));
}
int main() {
    fastio;
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i];
    init(1, 1, n);
    fto(i, k, n) cout << query(1, 1, n, i-k+1, i) << "\n";
    return 0;
}