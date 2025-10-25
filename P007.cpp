/*Code by Hoang Thai*/
#include <bits/stdc++.h>
#define pb push_back
#define ff first
#define ss second
#define sz(a) a.size()
#define cell(a, i, j) a.cell[i][j]
#define ll long long
#define fto(i, a, b) for (int i = a; i <= b; ++i)
#define fdto(i, a, b) for (int i = a; i >= b; --i)
#define mem(x, a) memset(x, a, sizeof x)
#define open(a) freopen(a".INP", "r", stdin); freopen(a".OUT", "w", stdout);
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const int oo = 1000000007;
const int maxN = 100005;
//link snippet: C:\Users\nguye\AppData\Roaming\Sublime Text\Packages\User
int n, a[maxN], pos[maxN], cnt, mn, mx, lazy[4*maxN], dis[4 * maxN];
void push(int node) {
    lazy[2*node] += lazy[node];
    lazy[2*node+1] += lazy[node];
    dis[2*node] += lazy[node];
    dis[2*node+1] += lazy[node];
    lazy[node] = 0;
    return;
}
int query(int node, int l, int r, int u, int v) {
    if (l > r || u > v || u > r || v < l) return -oo;
    if (u <= l && r <= v) return dis[node];
    push(node);
    int mid = (l + r) >> 1;
    return max(query(node*2, l, mid, u, v), query(node*2+1, mid+1, r, u, v));
}
void update(int node, int l, int r, int u, int v, int w) {
    if (l > r || u > v || u > r || v < l) return;
    if (u <= l && r <= v) {
        dis[node] += w;
        lazy[node] += w;
        return;
    }
    push(node);
    int mid = (l + r) >> 1;
    update(node*2, l, mid, u, v, w);
    update(node*2+1, mid+1, r, u, v, w);
    dis[node] = max(dis[node*2], dis[node*2+1]);
    return;
}
int case_left(int x) {
    update(1, 1, n, 1, pos[x] - 1, 1);
    return query(1, 1, n, pos[x], pos[x]);
}
int case_right(int x) {
    update(1, 1, n, pos[x] + 1, n, -1);
    return query(1, 1, n, pos[x], pos[x]);
}
int solve(int x) {
    if (x <= n/2) return abs(x - case_left(x));
    return abs(x - case_right(x));
}
void init(int node, int l, int r) {
    if (l == r) {
        dis[node] = pos[a[l]];
        return;
    }
    int mid = (l + r) >> 1;
    init(node*2, l, mid);
    init(node*2+1, mid+1, r);
    dis[node] = max(dis[node*2], dis[node*2+1]);
}
int main() {
    fastio;
    cin >> n;
    fto(i, 1, n) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    init(1, 1, n);
    mn = 1; mx = n;
    while (cnt < n) {
        cout << solve((++cnt & 1) ? mn++ : mx--) << "\n";
    }
    return 0;
}