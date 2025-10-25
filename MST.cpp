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
struct node {
int u, v, w;
};
vector<node> a;
int n, m, parent[105], ans;
int cmp(node a, node b) {
    return a.w < b.w;
}
void make_set() {
    fto(i, 1, n) parent[i] = i;
}
int find(int a) {
    if (a == parent[a]) return a;
    return parent[a] = find(parent[a]);
}
int union_set(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return 0;
    parent[b] = a;
    return 1;
}
int main() {
    fastio;
    cin >> n >> m;
    fto(i, 1, m) {
        int u, v, w; cin >> u >> v >> w;
        node x = {u, v, w};
        a.pb(x);
    }
    sort(a.begin(), a.end(), cmp);
    make_set();
    for (auto e : a) {
        if (!union_set(e.u, e.v)) continue;
        ans += e.w;
    }
    cout << ans << "\n";
    return 0;
}