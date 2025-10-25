/*Code by Hoang Thai*/
#pragma GCC optimize("O3", "unroll-loops")
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define pii pair<int, int>
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
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
const int oo = 1000000007;
const int maxN = 10005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
bool maximize(int &a, int b) {return (a < b ? (a = b) : 0);};
bool minimize(int &a, int b) {return (a > b ? (a = b) : 0);};
int n, k, a[maxN], tree[4*maxN], f[maxN];
int mex(int a, int b) {
    return max(a, b);
}
int query(int node, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return tree[node];
    int mid = (l + r) >> 1;
    int q_1 = query(node*2, l, mid, u, v);
    int q_2 = query(node*2 + 1, mid + 1, r, u, v);
    return mex(q_1, q_2);
}
void update(int node, int l, int r, int u, int x) {
    if (u > r || u < l) return;
    if (l == r) {
        if (u == l) tree[node] = x;
        return;
    }
    int mid = (l + r) >> 1;
    update(2 * node, l, mid, u, x);
    update(2 * node + 1, mid + 1, r, u, x);
    tree[node] = mex(tree[node * 2], tree[node * 2 + 1]);
    return;
}

// int dp(int i) {
//     if (i > n) return 0;
//     if (f[i] != -1) return f[i];
//     int res = -oo;
//     fto(j, i, min(n, i+k-1)) {
//         maximize(res, dp(j+1) + query(1, 1, n, i, j) * (j - i + 1));
//     }
//     return f[i] = res;
// }
int main() {
    fastio;
    if (fopen("sinh.inp", "r")) {
        freopen("sinh.inp", "r", stdin);
        freopen("sinh.out", "w", stdout);
    }
    cin >> n >> k;
    fto(i, 1, n) cin >> a[i], update(1, 1, n, i, a[i]);
    fto(i, 1, n) {
        fto(j, max(0, i-k), i) {
            f[i] = max(f[i], f[j] + query(1, 1, n, j+1, i) * (i - j));
        }
    }
    cout << f[n] << "\n";
    return 0;
}